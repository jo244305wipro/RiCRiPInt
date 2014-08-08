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

#ifndef	__INC_GPS_COLOR_DEF__	/* { */
#define	__INC_GPS_COLOR_DEF__

/*
 * �y�P�z
 * �W���^�錾
 */

#define	ulong	unsigned long
#define	ushort	unsigned short
#define	uchar	unsigned char



#include "gps_color_mtype.h"

/*
 * �y�Q�z
 * ���L�������̒�`
 */

/**** �K���}�f�[�^�\���̂̒�` ****/
typedef	struct {
	long	gam;		/* �K���}�f�[�^�ւ̃I�t�Z�b�g */
	ulong	gamsz;		/* �K���}�f�[�^�̃T�C�Y */
} gps_clr_gam_t;

/**** �f�B�U�f�[�^�\���̂̒�` ****/
typedef	struct {
	long	dit;		/* �f�B�U�f�[�^�ւ̃I�t�Z�b�g */
	ushort	ditsz;		/* �f�B�U�f�[�^�̃T�C�Y */
	ushort	xsz;		/* �f�B�U�}�g���b�N�X�̂w�T�C�Y */
	ushort	ysz;		/* �f�B�U�}�g���b�N�X�̂x�T�C�Y */
	ushort	thrshpln;	/* �f�B�U��臒l�v���[���� */
} gps_clr_dit_t;

/*** �F���f�[�^�\���̂̒�` ***/
typedef	struct {
	long	gam;		/* �K���}�\���̂ւ̃I�t�Z�b�g */
	long	dit;		/* �f�B�U�\���̂ւ̃I�t�Z�b�g */
} gps_clr_plane_t;

/** ���[�h���f�[�^�\���̂̒�` **/
typedef	struct {
	/* �e�F�f�[�^�\���̂ւ̃I�t�Z�b�g */
	gps_clr_plane_t	color[GPS_CLR_PLANE];
} gps_clr_data_t;

/* ���L�������w�b�_�̒�` */
typedef	struct {
	int				size;		/* ���̃������̑傫�� */
	ulong			stat;		/* �X�e�[�^�X */
	ushort			dmode;		/* �`�惂�[�h�� */
	ushort			numcolor;	/* �F�� (==GPS_CLR_PLANE) */
	ulong			off;		/* �f�[�^�|�C���^�ւ̃I�t�Z�b�g */
	gps_clr_data_t	data;		/* ���[�h���f�[�^�̔z�� */
/*
   data[dmode]�͈ȉ��̂悤�ȃ������C���[�W�ɂȂ�
	long	gam;		ID=0,color=0�̃K���}�\���̂ւ̃I�t�Z�b�g�y�Q�z���Q��
	long	dit;		ID=0,color=0�̃f�B�U�\���̂ւ̃I�t�Z�b�g�y�R�z���Q��
	long	gam;		ID=0,color=1�̃K���}�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=0,color=1�̃f�B�U�\���̂ւ̃I�t�Z�b�g
	�c	�c		�c
	long	gam;		ID=1,color=0�̃K���}�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=1,color=0�̃f�B�U�\���̂ւ̃I�t�Z�b�g
	�c	�c		�c
	long	gam;		ID=dmode-1,color=numcolor-1�̃K���}�\���̂ւ̃I�t�Z�b�g
	long	dit;		ID=dmode-1,color=numcolor-1�̃f�B�U�\���̂ւ̃I�t�Z�b�g
*
   ID�Ƃ�gpsColor_getID()�œ����J���[���[�hID
   color�Ƃ́AJupiter�ł�
	#define GPS_CLR_K 0
	#define GPS_CLR_C 1
	#define GPS_CLR_M 2
	#define GPS_CLR_Y 3
	#define GPS_CLR_PLANE 4   �@�ƂȂ�
*/
} gps_clr_shdm_t;

/* stat��bit��` */
#define	GAMM_UPDREQ	0		/* gamma�ύX�v�� */
#define	TLIM_UPDREQ	1		/* ���ʋK���l�ύX�v�� */


/*
 * �y�R�z
 * �����̌^��`
 */
/* �ʎq��bit��` */
#define	GPS_COLOR_QUANT_BIT1	1	/* 1bit */
#define	GPS_COLOR_QUANT_BIT2	2	/* 2bit */
#define	GPS_COLOR_QUANT_BIT4	4	/* 4bit */
#define	GPS_COLOR_QUANT_BIT8	8	/* 8bit */

/* �f�B�U�E���̕`�惂�[�h��` */
#define	PHOTO_DRAWMODE		0
#define	TEXT_DRAWMODE		1
#define	GRAP_DRAWMODE		2
#define	THIN_DRAWMODE		3
#define	PHOTO2_DRAWMODE		4

/* gps_color_file.h �Ɉړ��������A�݊����̂��߂�����ɂ����ꂽ */
#ifndef	SPCL_DRAWMODE_BIT
#define	SPCL_DRAWMODE_MSK			0xFFFF		/* mask for file id (same mode, maybe) */
#define	SPCL_DRAWMODE_BIT			16			/* flag of no gamma calc */
#define	NOREARRANGE_DRAWMODE_BIT	17			/* flag to has no rearrange data */
#define	SPCL_DRAWMODE	(1<<SPCL_DRAWMODE_BIT)	/* mask for no gammma calc */
#define	NOREARRANGE_DRAWMODE	(1<<NOREARRANGE_DRAWMODE_BIT)
												/* mask for no rearrage data */
#endif

/* ���ʋK���̃��[�h��` */
#define	TLIMIT_PHOTOMODE	0
#define	TLIMIT_TEXTMODE		1

/* �K���}�t�@�C���f�[�^���o���p�\���̂̒�` */
typedef	struct {
	uchar	fname[64];				/* �K���}�f�[�^�t�@�C����filename */
	int		off[GPS_CLR_PLANE];		/* �F��offset�l */
}	gps_clr_gmfile_t;

/* �K���}�v�Z�p�\���̂̒�` */
	/* ���[�U�[�E�T�[�r�X�K���}�f�[�^�̃T�C�Y */
#define	GPS_COLOR_UGAMSZALL	(GPS_CLR_GAMUMODE)
#define	GPS_COLOR_SGAMSZ1M	(GPS_CLR_GAMSPNTS)
typedef	struct {
	uchar	ug[GPS_COLOR_UGAMSZALL];	/* ���[�U�[�K���}�f�[�^ */
	uchar	sg[GPS_COLOR_SGAMSZ1M];		/* �T�[�r�X�K���}�f�[�^ */
}	gps_clr_calcgam_t;

/* �`�惂�[�h�p�����[�^�\���̂̒�` */
typedef	struct {
	int		whatis;					/* bit 0:SP���[�h�Ŏw�肳��Ă��� */
									/* UP���[�h�K���}�Ώ� */
	ushort	hdpi;					/* for horizontal resolution (ex. 1200) */
	ushort	vdpi;					/* for vertical resolution (ex. 600) */
	ushort	mode;					/* for id:D draw mode (ex.Photo/Text) */
	uchar	bit;					/* for N bit (ex.1,2,4) */
	uchar	id;						/* id for liblary */
} gps_color_drawparam_t;
/* whatis��bit��` */
#define	SPmode_set		0			/* On:SP���[�h�Ŏw�肳��Ă��� */
#define	effectUPgamma	1			/* On:UP���[�h�K���}�Ώ� */
/* whatis���`�F�b�N����@�i������gps_color_idsrch_t*�j*/
#define	check_spmodeDID(x)		((x)->whatis & (1<<SPmode_set))
#define	check_effectUPrDID(x)	((x)->whatis & (1<<effectUPgamma))

/*
 * �y�Q�`�z
 * �J���[�e�X�g����p���L�������̒�`
 */
/* �J���[�e�X�g����p���L�������w�b�_�̒�` */
typedef	struct {
	int				size;		/* ���̃������̑傫�� */
	int				ext;		/* �g���p */
	int				data;		/* size���̃f�[�^�̈� */
} gps_clr_shdm2_t;


/*
 * �y�R�`�z
 * �J���[�e�X�g����p�̒�`
 */
#define	GPS_COLOR_SHRDWKSZ	GPS_CLR_PIXEL_OUT


#endif	/* } __INC_GPS_COLOR_DEF__ */
