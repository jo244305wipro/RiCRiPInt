/*
 * GPS COLOR LIBRARY TYPE DEFINITION.
 * Copyright (c) Ricoh Company, Ltd.
 * ALL Rights Reserved.
 *
 * $Id: gps_color_inc.h,v 1.8 2000/12/05 13:35:00 MrX Exp MrX $
 * $Date: 2000/12/05 13:35:00 $
 * $Author: MrX $
 *
 * �K���}�E�f�B�U�f�[�^�̌^��`
 *
 */

#ifndef	__INC_GPS_NEW_COLOR_DEF__	/* { */
#define	__INC_GPS_NEW_COLOR_DEF__

/*
 * ���L�������̒�`
 */

/**** �K���}�f�[�^�\���̂̒�` ****/
typedef	struct {
	long	gam[GPS_MAX_HEADRANK];		/* ���H�K���}�f�[�^�ւ̃I�t�Z�b�g */
	long 	gam2[GPS_MAX_HEADRANK];		/* ���H�K���}�f�[�^�ւ̃I�t�Z�b�g */
} gps_nclr_gam_t;

/**** �f�B�U�f�[�^�\���̂̒�` ****/
typedef	struct {
	long	dit;			/* �f�B�U�f�[�^�ւ̃I�t�Z�b�g */
	ushort	ditsz;			/* �f�B�U�f�[�^�̃T�C�Y */
	ushort	xsz;			/* �f�B�U�}�g���b�N�X�̂w�T�C�Y */
	ushort	ysz;			/* �f�B�U�}�g���b�N�X�̂x�T�C�Y */
	ushort	thrshpln;		/* �f�B�U��臒l�v���[�����i�o�̓��x���̐��j */
	uchar	e_flag_max;		/* �蒅���x����p�t���O(���4bit) */
	uchar	e_flag_mid;		/* �蒅���x����p�t���O(����4bit) */
} gps_nclr_dit_t;

/**** �덷�g�U�f�[�^�\���̂̒�` ****/
typedef struct
{
	ulong	size;			/* �K���}�f�[�^�̃T�C�Y */
	ushort	plane;			/* �v���[���� */
	ushort	mask_x;			/* �}�X�N�e�[�u���w�T�C�Y */
	ushort	mask_y;			/* �}�X�N�e�[�u���x�T�C�Y */
	long	thrdata;		/* 臒l�f�[�^�ւ̃I�t�Z�b�g */
	long	mask;			/* �}�X�N�e�[�u���ւ̃I�t�Z�b�g*/
}
gps_nclr_ed_t;

/*** �F���f�[�^�\���̂̒�` ***/
typedef	struct {
	long	gam;			/* �K���}�f�[�^�\���̂ւ̃I�t�Z�b�g */
	long	dit;			/* �f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g */
	long	ed;				/* �덷�g�U�w�b�_�[�\���̂ւ̃I�t�Z�b�g */
	long	ed_gam;			/* �덷�g�U�K���}�f�[�^�\���̂ւ̃I�t�Z�b�g */
} gps_nclr_plane_t;

/*** �K�ʃe�[�u���f�[�^�\���̂̒�` ***/
typedef struct
{
	ulong	size;		/* �f�[�^�T�C�Y */ 
	long	lit;		/* �K�ʃe�[�u���f�[�^�ւ̃I�t�Z�b�g */
	long	inv;		/* �t�ϊ��e�[�u���f�[�^�ւ̃I�t�Z�b�g */
}
gps_nclr_drop_t;

/*** BG/UCR�f�[�^�\���̂̒�` ***/
typedef struct
{
	ulong	size;		/* �f�[�^�T�C�Y */
	long	bg;			/* BG�f�[�^�ւ̃I�t�Z�b�g */
	long	ucr;		/* UCR�f�[�^�ւ̃I�t�Z�b�g */
}
gps_nclr_bgucr_t;

/*** ���ʋK���f�[�^�\���̂̒�` ***/
typedef struct
{
	ulong	size;		/* �f�[�^�T�C�Y */
	long	limit;		/* ���ʋK���f�[�^�ւ̃I�t�Z�b�g */
}
gps_nclr_limit_t;

/*** ���ʃK���}�����f�[�^�\���̂̒�` ***/	
typedef struct
{
	ulong	size;		/* �f�[�^�T�C�Y */
	long	gam_front;	/* ���ʃK���}�����ւ̃I�t�Z�b�g�i�\�ʁj*/
	long	gam_back;	/* ���ʃK���}�����ւ̃I�t�Z�b�g�i���ʁj*/
}
gps_nclr_dupgam_t;

/* WiShGCR�t�H�[�}�b�g (07A) */
typedef struct
{
	ulong	size;		/* �{�\���̂̃T�C�Y */
	long	CB_bg_wish;	/* CB��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	CB_ucr_wish;	/* CB��UCR�e�[�u���ւ̃I�t�Z�b�g */
	long	CG_bg_wish;	/* CG��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	CG_ucr_wish;	/* CG��UCR�e�[�u���ւ̃I�t�Z�b�g */
	long	YG_bg_wish;	/* YG��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	YG_ucr_wish;	/* YG��UCR�e�[�u���ւ̃I�t�Z�b�g */
	long	MB_bg_wish;	/* MB��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	MB_ucr_wish;	/* MB��UCR�e�[�u���ւ̃I�t�Z�b�g */
	long	MR_bg_wish;	/* MB��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	MR_ucr_wish;	/* MB��UCR�e�[�u���ւ̃I�t�Z�b�g */
	long	YR_bg_wish;	/* YR��BG�e�[�u���ւ̃I�t�Z�b�g */
	long	YR_ucr_wish;	/* YR��UCR�e�[�u���ւ̃I�t�Z�b�g */
}
gps_nclr_wishgcr_t;


/** ���[�h���f�[�^�\���̂̒�` **/
typedef struct
{
	/* �e�F�f�[�^ */
	gps_nclr_plane_t	color[GPS_CLR_PLANE];
	/* �K�ʃf�[�^ */
	gps_nclr_drop_t	drop;
	/* ���ʋK���f�[�^ */
	gps_nclr_limit_t	limit;
	/* �덷�g�U�p�K�ʃf�[�^ */
	gps_nclr_drop_t	ed_drop;
	/* �덷�g�U�p���ʋK���f�[�^ */
	gps_nclr_limit_t	ed_limit;
	/* BG/UCR�f�[�^ */
	gps_nclr_bgucr_t	bgucr;
	/* ���ʃK���}�����f�[�^ */	
	gps_nclr_dupgam_t	dupgam;
	/* WishGCR�f�[�^*/
	gps_nclr_wishgcr_t	wishgcr;
} 
gps_nclr_data_t;

/* ���L�������w�b�_�̒�` */
typedef	struct {
	int				size;		/* ���̃������̑傫�� */
	ulong			stat;		/* �X�e�[�^�X */
	ushort			dmode;		/* �`�惂�[�h�� */
	ushort			numcolor;	/* �F�� (==GPS_CLR_PLANE) */
	ulong			off;		/* �f�[�^�|�C���^�ւ̃I�t�Z�b�g */
	gps_nclr_data_t	data;		/* ���[�h���f�[�^�̔z�� */
/*
   data[dmode]�͈ȉ��̂悤�ȃ������C���[�W�ɂȂ�B�A���A�f�[�^�����݂��Ȃ��ꍇ�ɂ́A�e�I�t�Z�b�g�l�͂O�Ƃ���B
	long	gam;		ID=0,color=0�̃K���}�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=0,color=0�̃f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed;			ID=0,color=0�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_gam;		ID=0,color=0�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g	
	�c	�c		�c
	long	gam;		ID=0,color=3�̃K���}�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=0,color=3�̃f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed;			ID=0,color=3�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_gam;		ID=0,color=3�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	drop;	  	ID=0�̓K�ʃe�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	limit;		ID=0�̑��ʋK���e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_drop;	ID=0�̌덷�g�U�K�ʃe�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_limit;	ID=0�̌덷�g�U���ʋK���e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	bgucr;		ID=0��BGUCR�e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dupgam;		ID=0�̗��ʃK���}�����f�[�^�\���̂ւ̃I�t�Z�b�g
	�c	�c		�c
	long	gam;		ID=1,color=0�̃K���}�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=1,color=0�̃f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed;			ID=1,color=0�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_gam;		ID=1,color=0�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	�c	�c		�c
	long	gam;		ID=1,color=3�̃K���}�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=1,color=3�̃f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed;			ID=1,color=3�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_gam;		ID=1,color=3�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	drop;	  	ID=1�̓K�ʃe�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	limit;		ID=1�̑��ʋK���e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_drop;	ID=1�̌덷�g�U�K�ʃe�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_limit;	ID=1�̌덷�g�U���ʋK���e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g	
	long	bgucr;		ID=1��BGUCR�e�[�u���f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dupgam;	ID=1�̗��ʃK���}�����f�[�^�\���̂ւ̃I�t�Z�b�g	
	�c	�c		�c
	long	gam;		ID=dmode-1,color=numcolor-1�̃K���}�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=dmode-1,color=numcolor-1�̃f�B�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed;		ID=dmode-1,color=numcolor-1�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	long	ed_gam;	ID=dmode-1,color=numcolor-1�̌덷�g�U�f�[�^�\���̂ւ̃I�t�Z�b�g
	�c	�c		�c
*
   ID�Ƃ�gpsColor_getID()�œ����J���[���[�hID
   color�Ƃ́AJupiter�ł�
	#define GPS_CLR_K 0
	#define GPS_CLR_C 1
	#define GPS_CLR_M 2
	#define GPS_CLR_Y 3
	#define GPS_CLR_PLANE 4   �@�ƂȂ�
*/
} gps_nclr_shdm_t;

/* �K���}�t�@�C���f�[�^���o���p�\���̂̒�` */
typedef	struct {
	uchar	fname[64];				/* �K���}�f�[�^�t�@�C����filename */
	int		off[GPS_CLR_PLANE];		/* �F��offset�l */
}	gps_nclr_gmfile_t;

/* �`�惂�[�h�p�����[�^�\���̂̒�` */
typedef	struct {
	int		whatis;					/* bit 0:SP���[�h�Ŏw�肳��Ă��� */
									/* UP���[�h�K���}�Ώ� */
	ushort	hdpi;					/* for horizontal resolution (ex. 1200) */
	ushort	vdpi;					/* for vertical resolution (ex. 600) */
	ushort	mode;					/* for id:D draw mode (ex.Photo/Text) */
	uchar	bit;					/* for N bit (ex.1,2,4) */
	uchar	id;						/* id for liblary */
	uchar	prt;					/* for print mode */
	uchar	paper;					/* for paper type */
} gps_nclr_drawparam_t;

#endif	/* } __INC_GPS_NEW_COLOR_DEF__ */
