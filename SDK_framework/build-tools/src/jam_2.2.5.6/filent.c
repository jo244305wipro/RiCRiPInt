/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# ifdef NT

# ifdef __BORLANDC__
# include <dir.h>
# include <dos.h>
# undef FILENAME	/* cpp namespace collision */
# define _finddata_t ffblk
# endif

# include "jam.h"
# include "filesys.h"

# ifdef USE_WIN32_API
# include <winbase.h>
# endif

# include <io.h>
# include <sys/stat.h>

/*
 * filent.c - scan directories and archives on NT
 *
 * External routines:
 *
 *	file_dirscan() - scan a directory for files
 *	file_time() - get timestamp of file, if not done by file_dirscan()
 *	file_archscan() - scan an archive for files
 *
 * File_dirscan() and file_archscan() call back a caller provided function
 * for each file found.  A flag to this callback function lets file_dirscan()
 * and file_archscan() indicate that a timestamp is being provided with the
 * file.   If file_dirscan() or file_archscan() do not provide the file's
 * timestamp, interested parties may later call file_time().
 *
 * 07/10/95 (taylor)  Findfirst() returns the first file on NT.
 * 05/03/96 (seiwald) split apart into pathnt.c
 */

/*
 * file_dirscan() - scan a directory for files
 */

void
file_dirscan( dir, func )
char	*dir;
dirscan_func_t	func;
{
	FILENAME f;
	char filespec[ MAXJPATH ];
	char filename[ MAXJPATH ];
# ifdef USE_WIN32_API
	BOOL ret;
	HANDLE handle;
	WIN32_FIND_DATA finfo[1]; /* [1] sic! */
# else
	int ret;
	long handle;
	struct _finddata_t finfo[1];
# endif
	timestamp_t timestamp = TIME_ZERO;

	/* First enter directory itself */

	memset( (char *)&f, '\0', sizeof( f ) );

	f.f_dir.ptr = dir;
	f.f_dir.len = strlen(dir);

	dir = *dir ? dir : ".";

 	/* Special case \ or d:\ : enter it */
 
 	if( f.f_dir.len == 1 && f.f_dir.ptr[0] == '\\' )
 	    (*func)( dir, 0 /* not stat()'ed */, timestamp );
 	else if( f.f_dir.len == 3 && f.f_dir.ptr[1] == ':' )
 	    (*func)( dir, 0 /* not stat()'ed */, timestamp );

	/* Now enter contents of directory */

	sprintf( filespec, "%s/*", dir );

	if( DEBUG_BINDSCAN )
	    printf( "scan directory %s\n", dir );

# ifdef __BORLANDC__
	if ( ret = findfirst( filespec, finfo, FA_NORMAL | FA_DIREC ) )
	    return;

	while( !ret )
	{
	    time_t time_write = finfo->ff_fdate;

	    time_write = (time_write << 16) | finfo->ff_ftime;
	    f.f_base.ptr = finfo->ff_name;
	    f.f_base.len = strlen( finfo->ff_name );

	    file_build( &f, filename );

	    (*func)( filename, 1 /* stat()'ed */, time_write );

	    ret = findnext( finfo );
	}
# else
# ifdef USE_WIN32_API
	handle = FindFirstFile( filespec, finfo );
	ret = ( handle == INVALID_HANDLE_VALUE );
# else
	handle = _findfirst( filespec, finfo );
	ret = ( handle < 0L );
# endif

	if( ret )
	    return;

	while( !ret )
	{
# ifdef USE_WIN32_API
	    f.f_base.ptr = finfo->cFileName;
	    timestamp.LowPart = finfo->ftLastWriteTime.dwLowDateTime;
	    timestamp.HighPart = finfo->ftLastWriteTime.dwHighDateTime;
# else
	    f.f_base.ptr = finfo->name;
	    timestamp = finfo->time_write;
# endif
	    f.f_base.len = strlen( f.f_base.ptr );

	    file_build( &f, filename, 0 );
	    (*func)( filename, 1 /* stat()'ed */, timestamp );

# ifdef USE_WIN32_API
	    ret = ! FindNextFile( handle, finfo );
# else
	    ret = _findnext( handle, finfo );
# endif
	}

# ifdef USE_WIN32_API
	FindClose( handle );
# else
	_findclose( handle );
# endif
# endif

}

/*
 * file_time() - get timestamp of file, if not done by file_dirscan()
 */

int
file_time( filename, time )
char	*filename;
timestamp_t	*time;
{
	/* On NT this is called only for C:/ */

# ifdef USE_WIN32_API
	WIN32_FILE_ATTRIBUTE_DATA fileinfo;

	if( ! GetFileAttributesEx( filename, GetFileExInfoStandard, &fileinfo ) )
	    return -1;

	time->LowPart = fileinfo.ftLastWriteTime.dwLowDateTime;
	time->HighPart = fileinfo.ftLastWriteTime.dwHighDateTime;
# else
	struct stat statbuf;

	if( stat( filename, &statbuf ) < 0 )
	    return -1;

	*time = statbuf.st_mtime;
# endif

	return 0;
}

/*
 * file_archscan() - scan an archive for files
 */

/* Straight from SunOS */

#define	ARMAG	"!<arch>\n"
#define	SARMAG	8

#define	ARFMAG	"`\n"

struct ar_hdr {
	char	ar_name[16];
	char	ar_date[12];
	char	ar_uid[6];
	char	ar_gid[6];
	char	ar_mode[8];
	char	ar_size[10];
	char	ar_fmag[2];
};

# define SARFMAG 2
# define SARHDR sizeof( struct ar_hdr )

void
file_archscan( archive, func )
char *archive;
void (*func)();
{
	struct ar_hdr ar_hdr;
	char *string_table = 0;
	char buf[ MAXJPATH ];
	long offset;
	int fd;

	if( ( fd = open( archive, O_RDONLY | O_BINARY, 0 ) ) < 0 )
	    return;

	if( read( fd, buf, SARMAG ) != SARMAG ||
	    strncmp( ARMAG, buf, SARMAG ) )
	{
	    close( fd );
	    return;
	}

	offset = SARMAG;

	if( DEBUG_BINDSCAN )
	    printf( "scan archive %s\n", archive );

	while( read( fd, &ar_hdr, SARHDR ) == SARHDR &&
	       !memcmp( ar_hdr.ar_fmag, ARFMAG, SARFMAG ) )
	{
	    long    lar_date;
	    long    lar_size;
	    char    *name = 0;
 	    char    *endname;
	    char    *c;

	    sscanf( ar_hdr.ar_date, "%ld", &lar_date );
	    sscanf( ar_hdr.ar_size, "%ld", &lar_size );

	    lar_size = ( lar_size + 1 ) & ~1;

	    if (ar_hdr.ar_name[0] == '/' && ar_hdr.ar_name[1] == '/' )
	    {
		/* this is the "string table" entry of the symbol table,
		** which holds strings of filenames that are longer than
		** 15 characters (ie. don't fit into a ar_name
		*/

		string_table = malloc(lar_size);
		if (read(fd, string_table, lar_size) != lar_size)
		    printf("error reading string table\n");
		offset += SARHDR + lar_size;
		continue;
	    }
	    else if (ar_hdr.ar_name[0] == '/' && ar_hdr.ar_name[1] != ' ')
	    {
		/* Long filenames are recognized by "/nnnn" where nnnn is
		** the offset of the string in the string table represented
		** in ASCII decimals.
		*/

		name = string_table + atoi( ar_hdr.ar_name + 1 );
		endname = name + strlen( name );
	    }
	    else
	    {
		/* normal name */
		name = ar_hdr.ar_name;
		endname = name + sizeof( ar_hdr.ar_name );
	    }

	    /* strip trailing space, slashes, and backslashes */

	    while( endname-- > name )
		if( *endname != ' ' && *endname != '\\' && *endname != '/' )
		    break;
	    *++endname = 0;

	    /* strip leading directory names, an NT specialty */

	    if( c = strrchr( name, '/' ) )
		name = c + 1;
	    if( c = strrchr( name, '\\' ) )
		name = c + 1;

	    sprintf( buf, "%s(%.*s)", archive, endname - name, name );
	    (*func)( buf, 1 /* time valid */, (time_t)lar_date );

	    offset += SARHDR + lar_size;
	    lseek( fd, offset, 0 );
	}

	close( fd );
}

# endif /* NT */
