#include "di_envdef.h"
#include "di_envdef_hand.h"
#include "device.h"
#include "gpssim.h"

#define EMPCL5 1
#define EMPCLXL 1
#define SYS_CHECK_DIRECTION 1
#define STAPLE_PUNCH_CONTROLED_BY_PDL 0
#define TRAYSEARCHMODE_SWITCH 1
#define SUPPORT_INSERTER 0
#define BYPASS_FREE_FEED 0
#define TRAY_OVERWRITING 0
#define PRINT_QUALITY_MODE 1
#define PJL_JOB_START_END 1
#define PCLJOB 1
#define IPS_MEDIA_HANDLING 1

/* Variables declarations with some default values */
#define TRUE 1
#define FALSE 0
#define	VAR_ID_QUALITYMODE		617
#define CHANGE_MEDIATYPE	0x01
#define CHANGE_QUALITYMODE	0x02
#define DI_CODE_NO_SIZE 128
#define _enum_EOT 26
#define _enum_None 0
#define PAPERSRC_ALL 26
#define XRESOLUTION 600  /*PDI.xres*/
#define YRESOLUTION 600  /*PDI.yres*/
#define	NSEARCH_PATH	(sizeof(search_path)/sizeof(search_path[0])) /* do we need to modify complete search path ? */

/* Paper Sizes */
#define PAPERSIZE_LONGLTR 25
#define PAPERSIZE_A4  26
#define PAPERSIZE_LETTER 2
#define PAPERSIZE_A4R 27
#define USE_INTERNAL_CUSTOMSIZE 101 /*default custom value*/
#define PAPERSIZE_CUSTOM 101  /*default custom value*/

/* Media Types */
#define MEDIATYPE_PLAIN 0
#define MEDIATYPE_AUTO 0
#define MEDIATYPE_RECYCLED 5
#define MEDIATYPE_PLAIN2 4

/* Tray Settings */
#define TRAYINSERTED_IN 1
#define TRAYLOCKED_LOCKED 1
#define BYPASSTRAYSETTING_FREEMODE 1
#define BYPASSTRAYSETTING_CUSTOMFREEMODE 2

/* Macro declarations for OM case statements */
#define XRES 0
#define YRES 1
#define OMSYSTEM 1
#define OMPRINTER 2
#define OMBITSPERPIXEL 3
#define OMPAPERSRC 4
#define OMBYPASSTRAYSETTING 5
#define OMFRONTCOVERPRINT 6 
#define OMAUTOTRAYCHANGE2 7
#define OMTRAYSEARCHMODE  8 
#define OMBINDINGEDGE 10
#define OMDUPLEX 9
#define BIND_LONGEDGE 1
#define BIND_SHORTEDGE 0
#define LONGEDGEFEED 10
#define OMPRINTER 2

/* Macro definitions for OM attributes in Search Path array */
#define OMTRAY1_SIZE  26
#define OMTRAY1_MEDIATYPE 0 
#define OMTRAY1_INSERTED 1
#define OMTRAY1 3
#define PAPERSRC_TRAY1 3 
#define OMTRAY1SETTING 3

#define OMTRAY2_SIZE 2
#define OMTRAY2_MEDIATYPE 1
#define OMTRAY2_INSERTED 1
#define OMTRAY2 4 
#define PAPERSRC_TRAY2 4 
#define OMTRAY2SETTING 4

/*
#define OMTRAY3_SIZE 26
#define OMTRAY3_MEDIATYPE 2  
#define OMTRAY3_INSERTED 0
#define OMTRAY3 5
#define PAPERSRC_TRAY3 5

#define OMTRAY4_SIZE 2 
#define OMTRAY4_MEDIATYPE 3
#define OMTRAY4_INSERTED 0
#define OMTRAY4 6
#define PAPERSRC_TRAY4 6

#define OMTRAY5_SIZE 26
#define OMTRAY5_MEDIATYPE 4
#define OMTRAY5_INSERTED 0
#define OMTRAY5 7
#define PAPERSRC_TRAY5 7

#define OMTRAY6_SIZE 2
#define OMTRAY6_MEDIATYPE 5
#define OMTRAY6_INSERTED 0
#define OMTRAY6 8 
#define PAPERSRC_TRAY6 8

#define OMTRAY7_SIZE 2 
#define OMTRAY7_MEDIATYPE 6
#define OMTRAY7_INSERTED 0        
#define OMTRAY7 9
#define PAPERSRC_TRAY7 9

#define OMTRAY8_SIZE 26
#define OMTRAY8_MEDIATYPE 7
#define OMTRAY8_INSERTED 0
#define OMTRAY8 10
#define PAPERSRC_TRAY8 10

#define OMTRAY9_SIZE 2
#define OMTRAY9_MEDIATYPE 8
#define OMTRAY9_INSERTED 0
#define OMTRAY9 11
#define PAPERSRC_TRAY9 11

#define OMTRAYA_SIZE 26
#define OMTRAYA_MEDIATYPE 9
#define OMTRAYA_INSERTED 0
#define OMTRAYA 12
#define PAPERSRC_TRAYA 12

#define OMBYPASS_SIZE 2
#define OMBYPASS_MEDIATYPE 10 
#define OMBYPASS_INSERTED 0
#define OMBYPASS 13
#define PAPERSRC_BYPASS 13
*/
#define PAPERSRC_BYPASS 0
#define FRONTCOVERPRINTTRAY_TRAY1 3
#define FRONTCOVERPRINTTRAY_TRAY2 4
#define FRONTCOVERPRINTTRAY_TRAY3 5
#define FRONTCOVERPRINTTRAY_TRAY4 6
#define FRONTCOVERPRINTTRAY_TRAY5 7
#define FRONTCOVERPRINTTRAY_TRAY6 8
#define FRONTCOVERPRINTTRAY_TRAY7 9
#define FRONTCOVERPRINTTRAY_TRAY8 10
#define FRONTCOVERPRINTTRAY_TRAY9 11
#define FRONTCOVERPRINTTRAY_TRAYA 12
#define FRONTCOVERPRINTTRAY_BYPASS 13

typedef int OMenum;
typedef char* OMname;
typedef int OMEnum;
typedef int Uint16;
typedef int Uint8;
typedef int Uint32;
typedef int Sint8;
typedef int Sint16;
typedef int Sint32;
typedef int PAPERCODE;
typedef int Boolean;
/*typedef int bool;*/   /*Available in gpssim.h*/
typedef int ORIENTATION;

/*PAPERINFO structure variables are provided by RICOH*/
typedef struct {
   OMenum size, printable, offset, nominal, nomoffset, rotnomsize, rotnomoffset,
   HPnomoffset, HProtnomoffset, PS_PageSize, PS_printable, PS_margins,
   resolution; /*  type is struct {short x, y;}. */
   unsigned short OMcode;
   unsigned short PCLpaperID;
   unsigned char XLpaperID;
   bool envelope, noduplex;
} PAPERINFO;

static PAPERCODE LastPaperSelect,LastPaperSize;
static OMenum LastPaperSource,LastMediaType;
static Sint8   ChoosePaperDirectionDone;

OMenum OMGetCurrentInt(OMenum omvar, OMenum omsystem);
OMEnum OMGetDefaultEnum(OMenum omvar, OMenum omsystem);
bool OMGetCurrentBool(OMenum omvar, OMenum omsystem);
/*#ifndef IPS_MEDIA_HANDLING */
static struct {
		OMenum om_source; 
		OMname om_size;
		OMname om_mediatype;
		OMname om_stat;
		OMname om_lock;
		OMenum om_frontcovertray;
#ifdef TRAY_OVERWRITING
		OMenum om_traysetting;
#endif
} search_path[] = {
		{ PAPERSRC_TRAY1,  OMTRAY1_SIZE, OMTRAY1_MEDIATYPE,
		  OMTRAY1_INSERTED, OMTRAY1, FRONTCOVERPRINTTRAY_TRAY1
#ifdef TRAY_OVERWRITING
		  , OMTRAY1SETTING
#endif
		},
		{ PAPERSRC_TRAY2,  OMTRAY2_SIZE, OMTRAY2_MEDIATYPE,
		  OMTRAY2_INSERTED, OMTRAY2, FRONTCOVERPRINTTRAY_TRAY2
#ifdef TRAY_OVERWRITING
		  , OMTRAY2SETTING
#endif
		}
/*		{ PAPERSRC_LCT,    OMLCT_SIZE,   OMLCT_MEDIATYPE,
		  OMLCT_INSERTED, OMLCT, FRONTCOVERPRINTTRAY_LCT
#ifdef TRAY_OVERWRITING
		  , OMLCTSETTING
#endif
		},
		{ PAPERSRC_TRAY3,  OMTRAY3_SIZE, OMTRAY3_MEDIATYPE,
		  OMTRAY3_INSERTED, OMTRAY3, FRONTCOVERPRINTTRAY_TRAY3
#ifdef TRAY_OVERWRITING
		  , OMTRAY3SETTING
#endif
		},
		{ PAPERSRC_TRAY4,  OMTRAY4_SIZE, OMTRAY4_MEDIATYPE,
		  OMTRAY4_INSERTED, OMTRAY4, FRONTCOVERPRINTTRAY_TRAY4
#ifdef TRAY_OVERWRITING
		  , OMTRAY4SETTING
#endif
		},
		{ PAPERSRC_TRAY5,  OMTRAY5_SIZE, OMTRAY5_MEDIATYPE,
		  OMTRAY5_INSERTED, OMTRAY5, FRONTCOVERPRINTTRAY_TRAY5
#ifdef TRAY_OVERWRITING
		  , OMTRAY5SETTING
#endif
		},
		{ PAPERSRC_TRAY6,  OMTRAY6_SIZE, OMTRAY6_MEDIATYPE,
		  OMTRAY6_INSERTED, OMTRAY6, FRONTCOVERPRINTTRAY_TRAY6
#ifdef TRAY_OVERWRITING
		  , OMTRAY6SETTING
#endif
		},
		{ PAPERSRC_TRAY7,  OMTRAY7_SIZE, OMTRAY7_MEDIATYPE,
		  OMTRAY7_INSERTED, OMTRAY7, FRONTCOVERPRINTTRAY_TRAY7
#ifdef TRAY_OVERWRITING
		  , OMTRAY7SETTING
#endif
		},
		{ PAPERSRC_TRAY8,  OMTRAY8_SIZE, OMTRAY8_MEDIATYPE,
		  OMTRAY8_INSERTED, OMTRAY8, FRONTCOVERPRINTTRAY_TRAY8
#ifdef TRAY_OVERWRITING
		  , OMTRAY8SETTING
#endif
		},
		{ PAPERSRC_TRAY9,  OMTRAY9_SIZE, OMTRAY9_MEDIATYPE,
		  OMTRAY9_INSERTED, OMTRAY9, FRONTCOVERPRINTTRAY_TRAY9
#ifdef TRAY_OVERWRITING
		  , OMTRAY9SETTING
#endif
		},
		{ PAPERSRC_TRAYA,  OMTRAYA_SIZE, OMTRAYA_MEDIATYPE,
		  OMTRAYA_INSERTED, OMTRAYA, FRONTCOVERPRINTTRAY_TRAYA
#ifdef TRAY_OVERWRITING
		  , OMTRAYASETTING
#endif
		},
		{ PAPERSRC_BYPASS, OMBYPASS_SIZE, OMBYPASS_MEDIATYPE,
		  OMBYPASS_INSERTED, OMBYPASS, FRONTCOVERPRINTTRAY_BYPASS
#ifdef TRAY_OVERWRITING
		  , OMBYPASSTRAYSETTING
#endif
		}*/
	};

#define	NSEARCH_PATH	(sizeof(search_path)/sizeof(search_path[0]))
/* Below Variable initializations are taken from MnPaper.c */
/*LastPaperSource = (OMenum)-1;
LastMediaType = (OMenum)-1;
LastPaperSelect = 0xFFFF;
LastPaperSize = 0xFFFF;*/

extern void PrintSysChangeResolution (Uint16 * xres, Uint16 * yres, Uint8 * bit);
extern Uint8 PrintSysCheckQualityMode (Sint32 * om_media, OMenum * om_qmode);
extern int PrintSysGetCustomSize(OMenum source, int xres, int yres, PAPERINFO *paper);
extern void PrintSysGetMaxPaperSize(Sint32 *width, Sint32 *height);
extern void PRcustompaperinfo(int pwidth, int plength, int xres, int yres);
extern bool CheckSamePaperSize();
extern bool CheckSameCustomSize();
OMenum mnMediaSizeSelection(OMenum paper);
extern OMenum mnMediaSizeSelectionForInserter(OMenum paper);
extern bool PrintSysInserterMatchPaperSize(void);
extern int mnNonRotateDirection( ORIENTATION orient, int papersize, int xres, int yres );
extern OMenum mnSelectionByPreview(OMenum paper, int xres, int yres);
extern Sint32 searchBestPaperSource(OMenum code, OMenum mediatype, OMenum insert);
extern void choosePaperDirection(Sint32 *psize, OMenum longEdgePaper,
			 OMenum shortEdgePaper);
extern void mnGetCustomSize(OMenum tray, int xres, int yres, PAPERINFO *paper);
extern OMenum checkFinisherPrint(OMenum papersize, Sint32 longEdgeTray, Sint32 shortEdgeTray, ORIENTATION orient, int xres, int yres);
OMenum mnSelectionByChoosePaperSource(OMenum papersize, int xres, int yres);
OMenum mnSelectionByAutoPaperSource(OMenum papersize, int xres, int yres);
extern OMenum mnGetOMPaperSize(Sint32 code, int xres, int yres, int (*comp)());
extern void PRpaperPair (PAPERCODE OMsize, int xres, int yres, OMenum *LongEdge, OMenum *ShortEdge );
extern void PRcustompaperinfo(int pwidth, int plength, int xres, int yres);
extern const PAPERINFO * PRpaperfirst(Sint32 code, int xres, int yres, int (*comp)());
extern void PrintSysChoosePaperDirectionOnStaplePunch(bool *longEdgeTray,
											   bool *shortEdgeTray,
											   ORIENTATION orient);
extern int PrintSysPaperRequest( Sint32 *psize, Sint32 pwidth, Sint32 plength,
							OMenum ptype, Sint32 tray, bool direction);
extern void PrintSysSetCompulsionPaperSize( OMenum paper_size );
extern void PrintSysSetCompulsionInTray( OMenum tray );
extern unsigned char pcdOMtoGPSBinding( ORIENTATION orient, OMenum ombind );
extern PAPERINFO * PRpaperinfoOriginal (PAPERCODE size, int xres, int yres);
int PRpapertable(PAPERINFO *paper, int xres, int yres);
/*extern PAPERINFO * PRpaperinfo(PAPERCODE paper, int xres, int yres);*/
int  PRpaperinfo(PAPERCODE paper, int xres, int yres);
extern Sint32 searchChoosePaperSource(OMenum tray_code);


void SetMediaType(uint32 media);
int GetMediaType();
OMenum GetPaperSource();
Uint32 GetPageSize();
void SetPageSize();
Uint32 GetCustomPageWidth();
Uint32 GetCustomPageHeight();
Uint32 GetPageWidth();
Uint32 GetPageHeight();
Uint32 GetOrientation();
int32 GetQualityMode();
int getMhPageSize();
int getMhMediaType();
int getMhPaperSource();
void SetPaperSource(int tray);

OMenum OMGetCurrentInt(OMenum omvar, OMenum omsystem);
OMEnum OMGetDefaultEnum(OMenum omvar, OMenum omsystem);
bool OMGetCurrentBool(OMenum omvar, OMenum omtype);
OMEnum OMCurrentEnum(OMenum omvar, OMenum omsystem);

 
