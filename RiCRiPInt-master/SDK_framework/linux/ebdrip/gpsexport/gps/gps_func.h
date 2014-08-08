/* -*- tab-width: 4; c-basic-offset: 4; -*- *** vi:ts=4:sw=4
 ***********************************************************
 *	$Id$
 *
 *	Copyright (C) 2001 Ricoh Company, Ltd.  All Rights Reserved.
 *
 *	FILE NAME	: gps_func.h
 *	VERSION		: $Revision$
 *	AUTHOR		: Satoshi MIYAZAKI
 *----------------------------------------------------------
 *	HISTORY
 *	miyazaki - 22 Jun 2001: Created.
 *	$Log$
 *
 ***********************************************************/
#ifndef _GPS_FUNC_H_
#define	_GPS_FUNC_H_

/*
 *
 */
extern void gpsApiInit(gwmsg_client_t *client);

/*
 * Function Returns
 */
#define	GPS_FUNC_SUPPORT	(1)
#define	GPS_FUNC_NOT_SUPPORT	(0)

/**********************************************************
 * Function
 * ���ϐ��ɃZ�b�g����r�b�g�� 31 �܂ő������玟�̊���
 * ����p�ӂ��鎖
 * �g�p�ϐ�: gps_function_support_info
 **********************************************************/

/**********************************************************
 * id	: 2500
 * ����	: gpsGetHddInfo2()
 * date	: 2001/06/22
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_HDD_INFO2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_HDD_INFO2	(1<<0)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_hddinfo2 {
	char	stat;						/* status        */
	char	path[GPS_MAX_HDD_PATH_LEN];	/* path          */
	long	f_bsize;					/* block size    */
	long	f_blocks;					/* total blocks  */
	long	f_bfree;					/* free blocks   */
	long	reserve;					/* reserve       */
} gps_hddinfo2_t;

/* gps_hddinfo2: stat */
#define	GPS_HDDSTAT_UNKNOWN	0
#define	GPS_HDDSTAT_NONE	1
#define	GPS_HDDSTAT_READY	2

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetHddInfo2( gwmsg_client_t* client, int hdd, int *status, gps_hddinfo2_t *hddinfo2 );


/**********************************************************
 * id	: 2501
 * ����	: gpsPlotSetShift()
 * date	: 2001/06/22
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_SET_SHIFT ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_SET_SHIFT	(1<<1)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsPlotSetShift( gwmsg_client_t* client, int plotid, int shiftoff );


/**********************************************************
 * id	: 2502
 * ����	: gpsGetPrmInfo()
 * date	: 2001/06/30
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_PRMINFP ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_PRM_INFO		(1<<2)

/* gpsGetPrmInfo(): f_id */
/* GWID_GpsEv_GetPrmInfo_Res: f_id */
#define	GPS_PRMINFO_GET_JOBSPOOL	0
#define	GPS_PRMINFO_GET_TOTALCOUNT	1
#define GPS_PRMINFO_GET_MAXIMGSIZE	2
#define GPS_PRMINFO_GET_NUMFLASHMEM	3
#define GPS_PRMINFO_GET_MAXPAPERSIZE	4
#define GPS_PRMINFO_GET_XPDL_ELANG	5
#define GPS_PRMINFO_GET_COLOR_MODEL	6
#define GPS_PRMINFO_GET_PAGEEXIST	7
#define GPS_PRMINFO_GET_TESTPRINT_LOCK	8
#define GPS_PRMINFO_GET_MACHINE_PPM	9
#define GPS_PRMINFO_GET_FIRMPROHIBIT	10
#define GPS_PRMINFO_GET_CARTRIDGEINFO	11
#define GPS_PRMINFO_GET_CARTRIDGECOUNT	12
#define GPS_PRMINFO_GET_MICRINFO		13


/* gpsGetPrmInfo(): status */
/* GWID_GpsEv_GetPrmInfo_Res: status */
#define GPS_PRMINFO_SUCCESS			0
#define GPS_PRMINFO_FAILED			1
#define GPS_PRMINFO_QUEUE			2
#define GPS_PRMINFO_CHECKING        3

/* gpsGetPrmInfo: GPS_PRMINFO_GET_COLOR_MODEL: long data */
#define	GPS_CM_BW_MACHINE		0	/* Black and White */
#define	GPS_CM_FULL_COLOR_MACHINE	1	/* Full Color */
#define	GPS_CM_TWIN_COLOR_MACHINE	2	/* Twin Color */

/* gpsGetPrmInfo: GPS_PRMINFO_GET_MICRINFO: long data */
enum {
	GPS_SYS_MODEL_STANDARD,			/* 0:RICOH�W�����f�� */
	GPS_SYS_MODEL_MICR_SECURE_PCL,	/* 1:Secure PCL MICR���f�� */
	GPS_SYS_MODEL_MICR_IPDS			/* 2:IPDS MICR���f�� */
};

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetPrmInfo( gwmsg_client_t* client, int f_id, int* status, int size, void* data);


/**********************************************************
 * id	: 2503
 * ����	: gpsPlotSetPageParam2()
 * date	: 2001/07/26
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_SET_PAGE_PARAM2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_SET_PAGE_PARAM2	(1<<3)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_pageparam2 {
	unsigned long	flag;					/* �ݒ肷��p�����[�^ */
#define	GPS_PARAM2_SHIFT					(1<<0)	/* �p�����[�^ shift ���L�� */
#define	GPS_PARAM2_BACKCOVER				(1<<1)	/* �p�����[�^ backcover ���L�� */
#define	GPS_PARAM2_BACKCOVERPRINT			(1<<2)	/* �p�����[�^ backcoverprint ���L�� */
#define	GPS_PARAM2_BACKCOVERTRAY			(1<<3)	/* �p�����[�^ backcovertray ���L�� */
#define	GPS_PARAM2_PARTITION				(1<<4)	/* �p�����[�^ partition ���L�� */
#define	GPS_PARAM2_PARTITIONCYCLE			(1<<5)	/* �p�����[�^ partitioncycle ���L�� */
#define	GPS_PARAM2_STAMP					(1<<6)	/* �p�����[�^ stamp ���L�� */
#define	GPS_PARAM2_Z_FOLD					(1<<7)	/* �p�����[�^ z_fold ���L�� */
#define	GPS_PARAM2_DUPLEXMODE				(1<<8)	/* �p�����[�^ duplexmode ���L�� */
#define	GPS_PARAM2_W_FOLD					(1<<9)	/* �p�����[�^ w_fold ���L�� */
#define	GPS_PARAM2_W_PUNCH					(1<<10)	/* �p�����[�^ w_punch ���L�� */
#define	GPS_PARAM2_W_EDGEFOLD				(1<<11)	/* �p�����[�^ w_edgefold ���L�� */
#define	GPS_PARAM2_ZIG_WIDTH				(1<<12)	/* �p�����[�^ zig_width ���L�� */
#define GPS_PARAM2_RING_BIND				(1<<13)	/* �p�����[�^ ring_bind ���L�� */
#define GPS_PARAM2_PERF_BIND				(1<<14)	/* �p�����[�^ perf_bind ���L�� */
#define GPS_PARAM2_PERF_TRIM				(1<<15)	/* �p�����[�^ perf_trim ���L�� */
#define GPS_PARAM2_PERF_PAPERCODE			(1<<16)	/* �p�����[�^ perf_paper_code ���L�� */
#define GPS_PARAM2_PERF_PAPERWIDTH			(1<<17)	/* �p�����[�^ perf_paper_width ���L�� */
#define GPS_PARAM2_PERF_PAPERLENGTH			(1<<18)	/* �p�����[�^ perf_paper_length ���L�� */
#define GPS_PARAM2_PERF_INPUTTRAY			(1<<19)	/* �p�����[�^ perf_input_tray ���L�� */
#define GPS_PARAM2_PERF_COVERTRAY			(1<<20)	/* �p�����[�^ perf_cover_tray ���L�� */
#define GPS_PARAM2_PERF_IMAGEVERT			(1<<21)	/* �p�����[�^ perf_image_vert ���L�� */
#define GPS_PARAM2_PERF_IMAGEHORI			(1<<22)	/* �p�����[�^ perf_image_hori ���L�� */
#define GPS_PARAM2_PERF_FINALPAPERCODE		(1<<23)	/* �p�����[�^ perf_final_paper_code ���L�� */
#define GPS_PARAM2_PERF_FINALPAPERWIDTH		(1<<24)	/* �p�����[�^ perf_final_paper_width ���L�� */
#define GPS_PARAM2_PERF_FINALPAPERLENGTH	(1<<25)	/* �p�����[�^ perf_final_paper_length ���L�� */
#define GPS_PARAM2_PERF_FINALPAPPERVERT		(1<<26)	/* �p�����[�^ perf_final_paper_vert ���L�� */
#define GPS_PARAM2_PERF_CUTPAPERTOP			(1<<27)	/* �p�����[�^ perf_cut_paper_top ���L�� */
#define GPS_PARAM2_PERF_CUTPAPERBOTTOM		(1<<28)	/* �p�����[�^ perf_cut_paper_bottom ���L�� */
#define GPS_PARAM2_PERF_CUTPAPERSIDE		(1<<29)	/* �p�����[�^ perf_cut_paper_side ���L�� */
#define	GPS_PARAM2_W_MACHINESTAMP			(1<<30)	/* �p�����[�^ w_machinestamp ���L�� */

	unsigned char	shift:1;		/* ���ԂŃV�t�g������^���Ȃ��i�W���u�Ԃ� gps_pageparam_t�� shiftoff�j*/
	unsigned char	stamp:1;		/* �{�̃X�^���v���g�p���� */
#define	GPS_STAMP_OFF		(0)		/* �g�p���Ȃ� */
#define	GPS_STAMP_ON		(1)		/* �g�p���� */

	unsigned char	duplexmode:1;	/* �h���C�o�[���痼�ʎw�� */
#define	GPS_DUPLEXMODE_OFF	(0)		/* ���ʎw��Ȃ� */
#define	GPS_DUPLEXMODE_ON	(1)		/* ���ʎw�肠�� */

	unsigned char	w_punch:1;		/* �܂�@�p���` */
#define	GPS_W_PUNCH_OFF			(0)		/* �܂�@�p���`�Ȃ� */
#define	GPS_W_PUNCH_ON			(1)		/* �܂�@�p���`���� */

	unsigned char	w_edgefold:1;	/* ���܂� */
#define	GPS_W_EDGEFOLD_OFF		(0)		/* ���܂�Ȃ� */
#define	GPS_W_EDGEFOLD_ON		(1)		/* ���܂肠�� */

	unsigned char	w_machinestamp:1;	/* ���J�X�^���v */
#define	GPS_W_MACHINE_STAMP_OFF	(0)		/* �g�p���Ȃ� */	
#define	GPS_W_MACHINE_STAMP_ON	(1)		/* �g�p���� */

	unsigned char	res1:2;

	unsigned char	backcover;		/* ���\�����[�h */
#define	GPS_COVER_BACK		(0x02)	/* ���\������ */

	unsigned char	backcoverprint;	/* ���\���摜����� */
/*		GPS_COVER_BACK		(0x02)	   ���\��������� */
#define	GPS_COVER_BACK_R	(0x22)	/* ���\�����]�i�����Ɂj��� */

	unsigned char	backcovertray;	/* ���\���g���C */

	unsigned char	partition;		/* �d�؎����[�h */
#define	GPS_PARTITION_OFF	(0)		/* �d�؎��Ȃ� */
#define	GPS_PARTITION_SORT	(1)		/* ���P�� */
#define	GPS_PARTITION_JOB	(2)		/* �W���u�P�� */

	unsigned short	partitioncycle;	/* �d�؎��̕����w��i���P�ʂ̏ꍇ�̂ݗL���j */

	unsigned char	z_fold;			/* �y�܂� */
#define	GPS_Z_FOLD_OFF		(0)		/* �y�܂�Ȃ� */
#define	GPS_Z_FOLD_RIGHT	(1)		/* �E�܂� */
#define	GPS_Z_FOLD_BOTTOM	(2)		/* ���܂� */
#define	GPS_Z_FOLD_LEFT		(3)		/* ���܂� */

	unsigned char	w_fold;			/* �L���܂� */
#define	GPS_W_FOLD_OFF			GPS_Z_FOLD_OFF		/* �܂�Ȃ� */
#define	GPS_W_FOLD_ZIGZAG		(1)		/* �W���o���܂� */
#define	GPS_W_FOLD_ZIGZAGFILE	(2)		/* �W���o���t�@�C���܂� */
#define	GPS_W_FOLD_BASIC		(3)		/* ��{�܂� */
#define	GPS_W_FOLD_BAG			(4)		/* �ܐ܂� */
#define	GPS_W_FOLD_FILE			(5)		/* �t�@�C���܂� */
#define	GPS_W_FOLD_CUSTOM1		(6)		/* ����܂�P */
#define	GPS_W_FOLD_CUSTOM2		(7)		/* ����܂�Q */
#define	GPS_W_FOLD_PROGRAM1		(8)		/* �v���O�����܂�P */
#define	GPS_W_FOLD_PROGRAM2		(9)		/* �v���O�����܂�Q */
#define	GPS_W_FOLD_PROGRAM3		(10)	/* �v���O�����܂�R */
#define	GPS_W_FOLD_PROGRAM4		(11)	/* �v���O�����܂�S */
#define	GPS_W_FOLD_ZIGZAGCUSTOM1	(12)	/* ���ړ���܂�P */
#define	GPS_W_FOLD_ZIGZAGCUSTOM2	(13)	/* ���ړ���܂�Q */
	unsigned long	zigzag_width;	/* �W���o���܂�̐܂蕝 */

	unsigned char	ring_bind;			/* �����O���{(���[�h�ݒ� | �Ԃ��ʒu) */
#define	GPS_RING_BIND_OFF		(0)		/* ���Ȃ� */
#define	GPS_RING_BIND_LEFT		(1)		/* ���Ԃ� */
#define	GPS_RING_BIND_TOP		(2)		/* ��Ԃ� */
#define	GPS_RING_BIND_RIGHT		(3)		/* �E�Ԃ� */
#define	GPS_RING_MODE_OFF		(0x00)	/* ���[�hOFF */
#define	GPS_RING_MODE_PUNCH		(0x10)	/* �p���`�̂݃��[�h */
#define	GPS_RING_MODE_RING		(0x20)	/* �����O���{���[�h */
#define	GPS_RING_BIND_MASK		(0x0F)	/* �Ԃ��ʒu�w��r�b�g */
#define	GPS_RING_MODE_MASK		(0xF0)	/* ���[�h�w��r�b�g */

	unsigned char	perf_bind;			/* ����ݐ��{(�Ԃ��ʒu) */
#define GPS_PERF_BIND_OFF		(0) 	/* ���Ȃ� */
#define GPS_PERF_BIND_LEFT		(1) 	/* ���Ԃ� */
#define GPS_PERF_BIND_TOP		(2) 	/* ��Ԃ� */
#define GPS_PERF_BIND_RIGHT 	(3) 	/* �E�Ԃ� */

	unsigned char	perf_trim;			/* ����ݐ��{(�d�オ��T�C�Y�w����@ | �ْf�ݒ�) */
#define GPS_PERF_TRIM_NONE		(0)		/* �ْf�Ȃ� */
#define GPS_PERF_TRIM_SINGLE	(1)		/* �����J�b�g */
#define GPS_PERF_TRIM_TRIPLE	(2)		/* �O�ӃJ�b�g */
#define GPS_PERF_MODE_OFF		(0x00)	/* �w��Ȃ� */
#define GPS_PERF_MODE_FINALSIZE	(0x10)	/* �d�オ��T�C�Y�w�� */
#define GPS_PERF_MODE_CUTSIZE	(0x20)	/* �J�b�g�ʎw�� */
#define	GPS_PERF_TRIM_MASK		(0x0F)	/* �ْf���@�w��r�b�g */
#define	GPS_PERF_MODE_MASK		(0xF0)	/* �d�オ��T�C�Y���@�w��r�b�g */

	unsigned char	perf_paper_code;	/* ����ݐ��{ �����T�C�Y�R�[�h(paper.h �Q��) */
	unsigned long	perf_paper_width;	/* ����ݐ��{ �t���[�T�C�Y���̒�����   (0.1mm�P��) */
	unsigned long	perf_paper_length;	/* ����ݐ��{ �t���[�T�C�Y���̒������� (0.1mm�P��) */

	unsigned char	perf_input_tray;	/* ����ݐ��{ ���������g���C */

	unsigned char	perf_cover_tray;	/* ����ݐ��{ �\���g���C */

	long			perf_image_vert;	/* ����ݐ��{ �쑜�V�n�ʒu���� (0.1mm�P��) */
	long			perf_image_hori;	/* ����ݐ��{ �쑜�����ʒu���� (0.1mm�P��) */

	unsigned char	perf_final_paper_code;		/* �d�オ��T�C�Y�w�莞 ���{�T�C�Y�R�[�h(paper.h �Q��) */
	long			perf_final_paper_width; 	/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{��   (0.1mm�P��) */
	long			perf_final_paper_length;	/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{���� (0.1mm�P��) */
	long			perf_final_paper_vert;		/* �d�オ��T�C�Y�w�莞 �d�オ��T�C�Y�ʒu���� (0.1mm�P��) */

	unsigned long	perf_cut_paper_top; 		/* �J�b�g�ʎw�莞 �V����   (0.1mm�P��) */
	unsigned long	perf_cut_paper_bottom;		/* �J�b�g�ʎw�莞 �n����   (0.1mm�P��) */
	unsigned long	perf_cut_paper_side;		/* �J�b�g�ʎw�莞 �������� (0.1mm�P��) */

	/* �ǉ����ڂ̗̈�m�� */
	unsigned char	res2[4];
} gps_pageparam2_t, *gps_pageparam2_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsPlotSetPageParam2( gwmsg_client_t* client, int plotid, const gps_pageparam2_t *ppageparam2, int *result, unsigned long *flag );


/**********************************************************
 * id	: 2504
 * ����	: gpsFrameLoadEnv()
 * date	: 2001/07/26
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_LOAD_ENV ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_LOAD_ENV	(1<<4)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsFrameLoadEnv( gwmsg_client_t* client, int frameid );


/**********************************************************
 * id	: 2505
 * ����	: gpsPlotChkDirection()
 * date	: 2001/07/26
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_CHK_DIRECTION ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_CHK_DIRECTION	(1<<5)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotChkDirection( gwmsg_client_t* client, int plotid, const gps_chkdirprm_t *condition, int *direction, int *slantdirection );


/**********************************************************
 * id	: 2506
 * ����	: gpsFrameGetMultiBandShm()
 * date	: 2001/08/31
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_MULTIBAND ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_MULTIBAND	(1<<6)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_bandtable
{
	int				band_id;			/* �o���hID */
	int				plane_id;			/* �v���[��ID */
	long			band_xdot;			/* �o���h�� */
	long			band_ydot;			/* �o���h���� */
	int				band_draw;			/* �`�挋�� */
	int				band_skip;			/* �Ԉ��� */
	unsigned char	band_stat;			/* �e�[�u�����̃o���h�g�p��� */
	void			*band_addr;

} gps_bandtable_t, *gps_bandtable_p;

/* gps_bandtable: band_stat */
#define GPS_BAND_GET	(1 << 0)
#define GPS_BAND_OPEN	(1 << 1)
#define GPS_BAND_CLOSE	(1 << 2)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsFrameGetMultiBandShm( gwmsg_client_t* client, long *offset, int *num );


/**********************************************************
 * id	: 2507
 * ����	: gpsFrameGetMultiBand()
 * date	: 2001/08/31
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_MULTIBAND ���`���鎖
 **********************************************************/
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsFrameGetMultiBand( gwmsg_client_t* client, int frameid, int bandid, int *result );


/**********************************************************
 * id	: 2508
 * ����	: gpsFrameFlushMultiBand()
 * date	: 2001/08/31
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_MULTIBAND ���`���鎖
 **********************************************************/
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsFrameFlushMultiBand( gwmsg_client_t* client, int frameid, int bandid, int *result );


/**********************************************************
 * id	: 2509
 * ����	: gpsFrameChapterSet()
 * date	: 2001/07/26
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_CHAPTER_SET ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_CHAPTER_SET	(1<<7)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsFrameChapterSet( gwmsg_client_t* client, int frameid, unsigned char mode, unsigned char paper_type );


/**********************************************************
 * id	: 2510
 * ����	: gpsGetFontInfoWffn()
 * date	: 2001/12/04 (Tsusaka)
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h, gps_api ����
 * GPS_SUPPORT_FONTINFO_WFFN ���`���鎖
 * (���l)
 * ����I/F�́AGPS���C�u���������ł̂ݎg�p�����֐�����
 * �T�|�[�g�ۂ̃`�F�b�N������K�v�����邽�߁A������
 * �ǉ�����B(Tsusaka)
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FONTINFO_WFFN	(1<<8)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
#define	GPS_FONT_MEDIA_MEMORY	0	/* font media type is memory (eg. mask ROM) */
#define	GPS_FONT_MEDIA_FILE		1	/* font media type is file (eg. SD card) */
#define	GPS_MAX_FONT_PATH_LEN	92

typedef struct gps_fontinfo_wffn {
	int				media;	/* font media type */
	char			font_fname[GPS_MAX_FONT_PATH_LEN];	/* font file path */
	unsigned long	faddr;	/* offset address from start of file, or memory address */
	unsigned long	size;	/* font data size (not file size) */
	unsigned long	offset; /* offset address from offset to font contents */
} gps_fontinfo_wffn_t;	/* this structure size must not be excess 112(=(128-16)) bytes. */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* int	gpsGetFontInfoWffn( gwmsg_client_t* client, int font, gps_fontinfo_wffn_t *fontinfo_wffn ); */


/**********************************************************
 * id	: 2511
 * ����	: gpsPlotChangeBinding()
 * date	: 2001/12/12
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_CHANGE_BINDING ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_CHANGE_BINDING	(1<<9)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsPlotChangeBinding( gwmsg_client_t* client, int plotid, unsigned char binding, int *result );


/**********************************************************
 * id	: 2512
 * ����	: gpsGetFlashMemInfo()
 * date	: 2002/01/10
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_FLASH_MEM_INFO ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_FLASH_MEM_INFO	(1<<10)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
#define	GPS_MAX_FM_PATH_LEN	64

typedef struct gps_flashmem_info {
	unsigned long	attr;				/* attribute */
	unsigned long	media;				/* kind of media */
	char		path[GPS_MAX_FM_PATH_LEN];	/* directory path */
	char		reserved[16];			/* reserved */
} gps_flashmem_info_t, *gps_flashmem_info_p;

/* gps_flashmem_info: attr */
#define	GPS_FLASHMEM_ATTR_RW	(1 << 0)	/* READ/WRITE
							(READONLY if not set) */

/* gps_flashmem_info: media */
#define	GPS_FLASHMEM_MEDIA_UNKNOWN	0		/* unknown media */
#define	GPS_FLASHMEM_MEDIA_ROM		1		/* ROM DIMM */
#define	GPS_FLASHMEM_MEDIA_SDCARD	2		/* SD Card */

/* gpsGetFlashMemInfo(): status */
#define	GPS_GETFMINFO_SUCCESS		0
#define	GPS_GETFMINFO_FAILED		1

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsGetFlashMemInfo(gwmsg_client_t* client, int fm_id, int *status, gps_flashmem_info_t *info);

/**********************************************************
 * id	: 2513
 * ����	: gpsXpdlMenuEntryDone()
 * date	: 2002/01/16
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_XPDL_MENU_ENTRY ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_XPDL_MENU_ENTRY_DONE	(1<<11)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsXpdlMenuEntryDone( gwmsg_client_t* client );

/**********************************************************
 * id	: 2514
 * ����	: gpsReqEventNotify()
 * date	: 2002/01/23
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_REQ_EVENT_NOTIFY ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_REQ_EVENT_NOTIFY	(1<<12)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
/* req */
#define	GPS_REQEVENT_ON		1
#define	GPS_REQEVENT_OFF	0

/* ev */
#define	GPS_REQEVENT_PAGEEXIT			(1 << 0)
#define	GPS_REQEVENT_XPDL_TESTPRN_DONE	(1 << 1)
#define	GPS_REQEVENT_XPDL_UJOB_END	(1 << 2)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsReqEventNotify(gwmsg_client_t* client, int req, unsigned long ev, unsigned long *res);


/**********************************************************
 * id	: 2515
 * ����	: gpsFramePrintInfo()
 * date	: 2002/01/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_PRINT_INFO ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_PRINT_INFO	(1<<13)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
enum OBJECT_TYPE
{
	OBJECT_TYPE_CHAR,		/* ���� */
	OBJECT_TYPE_IMAGE,		/* �C���[�W */
	OBJECT_TYPE_GRAPHIC,	/* �O���t�B�b�N*/
	OBJECT_TYPE_LINE,		/* �� */
	OBJECT_TYPE_NUM
};

typedef struct gps_pageinfo2 {
	unsigned long		flag;				/* �ݒ肷��p�����[�^ */
#define	GPS_INFO2_BYPASS_DIR		(1<<0)	/* �p�����[�^ bypass_dir ���L�� */
#define	GPS_INFO2_PWIDTH			(1<<1)	/* �p�����[�^ paper_width ���L�� */
#define	GPS_INFO2_PLENGTH			(1<<2)	/* �p�����[�^ paper_length ���L�� */
#define	GPS_INFO2_FWIDTH			(1<<3)	/* �p�����[�^ frame_width ���L�� */
#define	GPS_INFO2_FLENGTH			(1<<4)	/* �p�����[�^ frame_length ���L�� */
#define	GPS_INFO2_BAND				(1<<5)	/* �p�����[�^ band_length ���L�� */
#define	GPS_INFO2_PRINT_MODE		(1<<6)	/* �p�����[�^ print_mode ���L�� */
#define	GPS_INFO2_PAGE_SHIFT		(1<<7)	/* �p�����[�^ page_shift ���L�� */
#define	GPS_INFO2_PRINT_FACE		(1<<8)	/* �p�����[�^ print_face ���L�� */
#define	GPS_INFO2_DUMMY_PAGE		(1<<9)	/* �p�����[�^ dummy_page ���L�� */
/* COSMOS�p�������� */
#define GPS_INFO2_DITHER_MODE		(1<<10)	/* �p�����[�^ dither_mode ���L�� */
#define GPS_INFO2_COLOR_MATCH		(1<<11)	/* �p�����[�^ color_match ���L�� */
#define GPS_INFO2_ORIENT			(1<<12)	/* �p�����[�^ orientation ���L�� */
#define GPS_INFO2_GRAY_PRINT		(1<<13)	/* �p�����[�^ gray_print ���L�� */
#define GPS_INFO2_RGB_COLOR			(1<<14)	/* �p�����[�^ rgb_color_mode ���L�� */
/* �����܂� */
#define GPS_INFO2_ECO_COLOR			(1<<15)	/* �p�����[�^ eco_color ���L�� */
#define GPS_INFO2_FUSER_CTL			(1<<16)	/* �p�����[�^ fuser_ctl ���L�� */

	unsigned char		bypass_dir:2;		/* �p������*/
#define	GPS_BYPASS_DIR_NONE			(0)
#define	GPS_BYPASS_DIR_LEF			(1)
#define	GPS_BYPASS_DIR_SEF			(2)

	unsigned char		page_shift:1;		/* �y�[�W�P�ʂ̃V�t�g���� */
#define	GPS_PAGE_SHIFT_NONE			(0)		/* �V�t�g���Ȃ� */
#define	GPS_PAGE_SHIFT_ON			(1)		/* �V�t�g���� */

	unsigned char	res1:5;

	unsigned char		print_mode;			/* ������[�h */
#define GPS_PRINT_MODE_NONE			(0)		/* �w�肵�Ȃ� */
#define GPS_PRINT_MODE_HIGH			(1)		/* ���� */
#define GPS_PRINT_MODE_NORMAL		(2)		/* �W�� */
#define GPS_PRINT_MODE_QUALITY		(3)		/* ���掿 */
	unsigned char		print_face;			/* ���ʈ���� */

	unsigned char	res2[1];

	unsigned long		paper_width;		/* �t���[�T�C�Y���̗p����   (0.1mm�P��) */
	unsigned long		paper_length;		/* �t���[�T�C�Y���̗p�����@ (0.1mm�P��) */
	unsigned long		frame_width;		/* �t���[���̕�   (�h�b�g�P��) */
	unsigned long		frame_length;		/* �t���[���̒��@ (�h�b�g�P��) */
	unsigned long		band_length;		/* �o���h�̒��@   (�h�b�g�P��) */

	unsigned char		dummy_page;		/* �_�~�[�y�[�W */

#define GPS_DUMMY_PAGE_OFF			(0)	/* not a dummy page */
#define GPS_DUMMY_PAGE_BLANK			(1)	/* dummy blank page */

/* COSMOS�p�������� */
	unsigned char		dither_mode[OBJECT_TYPE_NUM];		/* �f�B�U�f�[�^[COSMOS] */
		#define GPS_DITHER_AUTO		(0)	/* ���� */
		#define GPS_DITHER_MODE1		(1)	/* �ʐ^�p */
		#define GPS_DITHER_MODE2		(2)	/* �����p */

	unsigned char		color_match[OBJECT_TYPE_NUM];		/* �J���[�}�b�`���O�f�[�^[COSMOS] */
		#define GPS_COLOR_MATCH_OFF		(0)	/* ���Ȃ� */
		#define GPS_COLOR_MATCH_MODE1	(1)	/* �����₩�D�� */
		#define GPS_COLOR_MATCH_MODE2	(2)	/* �K���D�� */
		#define GPS_COLOR_MATCH_MODE3	(3)	/* �����D�� */

	unsigned char		orientation;					/* ���e����[COSMOS] */
		#define GPS_ORIENT_PORTRAIT		(0)	/* �|�[�g���[�g */
		#define GPS_ORIENT_LANDSCAPE	(1)	/* �����h�X�P�[�v */

	unsigned char		gray_print[OBJECT_TYPE_NUM];		/* �O���[�������[COSMOS] */
		#define GPS_GRAY_PRINT_MODE1	(0)	/* �Ȃ�(CMYK) */
		#define GPS_GRAY_PRINT_MODE2	(1)	/* ���P�F */
		#define GPS_GRAY_PRINT_MODE3	(2)	/* �O���[��f�̂ݍ��P�F */

	unsigned char		rgb_color_mode;				/* RGB�J���[���[�h[COSMOS] */
		#define GPS_RGB_MODE_COLOR		(0)	/* �J���[ */
		#define GPS_RGB_MODE_MONO		(1)	/* ���m�N�� */
/* �����܂� */

	unsigned char		eco_color;		/* Economy Color Mode */
		#define GPS_ECO_COLOR_NONE		(0)	/* �G�R�m�~�[�J���[���[�h�w��Ȃ� */
		#define GPS_ECO_COLOR_PRT		(1)	/* �G�R�m�~�[�J���[���[�h�w�肠�� */

	unsigned char		fuser_ctl;		/* �蒅���x������� */	
		#define GPS_FUSER_CTL_STD		(0)	/* ��摜����(���x�������Ȃ�) */
		#define GPS_FUSER_CTL_LEVEL1	(1)	/* �摜�������x���P */
		#define GPS_FUSER_CTL_LEVEL2	(3)	/* �摜�������x���Q */

	/* �ǉ����ڂ̗̈�m�� */
	unsigned char	res3[19];
} gps_pageinfo2_t, *gps_pageinfo2_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsFramePrintInfo( gwmsg_client_t* client, int frameid, const gps_pageinfo2_t *ppageinfo2, unsigned long *flag );


/**********************************************************
 * id	: 2516
 * ����	: gpsGetTrayInfoShm()
 * date	: 2002/02/04
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_TRAY_INFO_SHM ���`���鎖
 * ����I/F�́AGPS���C�u���������ł̂ݎg�p�����֐�
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_TRAY_INFO_SHM	(1<<14)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_trayinfo_shm_header {
#define	GPS_TRAYINFO_SHM_STAT_LOCKED		(0x80000000L)
#define	GPS_TRAYINFO_SHM_STAT_COUNT_MASK	(0x0000ffffL)
	unsigned long	stat;
} gps_trayinfo_shm_header_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetTrayInfoShm( gwmsg_client_t* client, int *ret_code, int num, long *offset, int *ret_num, int notify );

/**********************************************************
 * id	: 2517
 * ����	: gpsGetBinInfoShm()
 * date	: 2002/02/04
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_BIN_INFO_SHM ���`���鎖
 * ����I/F�́AGPS���C�u���������ł̂ݎg�p�����֐�
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_BIN_INFO_SHM	(1<<15)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_bininfo_shm_header {
#define	GPS_BININFO_SHM_STAT_LOCKED		(0x80000000L)
#define	GPS_BININFO_SHM_STAT_COUNT_MASK		(0x0000ffffL)
	unsigned long	stat;
} gps_bininfo_shm_header_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetBinInfoShm( gwmsg_client_t* client, int *ret_code, int num, long *offset, int *ret_num, int notify );

/**********************************************************
 * id	: 2518
 * ����	: gpsInterpNotifyExt()
 * date	: 2002/02/11
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_INTERP_NOTIFY_EXT ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_INTERP_NOTIFY_EXT	(1<<16)

typedef union gps_interp_notify_ext {
	struct	ext_testprint {
		int		interp_id;				/* interp id          */
		int		mode;					/* type of test print */
		char	res[24];
	} testprint;
	struct	ext_alert {
		int		interp_id;	/* interp id */
		int		pdl_id;		/* pdl id */
		int		mode;		/* GPS_INTERPEXT_ALERT_ON/OFF */
#define	GPS_INTERPEXT_ALERT_ON		0
#define	GPS_INTERPEXT_ALERT_OFF		1
		int		error;		/* error code */
		char		res[16];
	} alert;
	struct	ext_errorlog {
		int		interp_id;	/* interp id */
		int		pdl_id;		/* pdl id */
		int		error;		/* error code */
		char		res[20];
	} errorlog;
	struct	ext_resetkey {
		int		interp_id;	/* interp id */
		int		pdl_id;		/* pdl id */
		char		res[24];
	} resetkey;
	struct	ext_pdlerror {
		int		interp_id;	/* interp id */
		int		pdl_id;		/* pdl id */
		int		errid;		/* error id (1-9999) */
		char		res[20];
	} pdlerror;
} gps_interp_notify_ext_t;

/* status */
#define	GPS_INTERPEXT_NOSUPPORT		0
#define	GPS_INTERPEXT_SUPPORT		1

/* ext_id */
#define GPS_INTERPEXT_TESTPRINT		0
#define GPS_INTERPEXT_ALERT		1
#define GPS_INTERPEXT_ERRORLOG		2
#define GPS_INTERPEXT_RESETKEY		3
#define GPS_INTERPEXT_PDLERROR		4
/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsInterpNotifyExt( gwmsg_client_t* client , int ext_id, int *status, gps_interp_notify_ext_t interp_ext);

/**********************************************************
 * id	: 2519
 * ����	: gpsColor_getProfile()
 * date	: 2002/02/11
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_COLOR_GET_PROFILE ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_COLOR_GET_PROFILE	(1<<17)

#define	GPS_MAX_CPF_PATH_LEN		96
#define	GPS_MAX_CPF_ATTR_LEN		27

#define	GPS_CPF_MEDIA_RESIDENT		0	/* RESIDENT ROM */
#define	GPS_CPF_MEDIA_ROM		1	/* OPTION ROM DIMM */
#define	GPS_CPF_MEDIA_SDCARD		2	/* OPTION SD CARD */
#define	GPS_CPF_MEDIA_HDD		3	/* OPTION HDD */

typedef struct gps_color_profile_info {
	unsigned long		key;
	unsigned char		media;
	unsigned char		attr[GPS_MAX_CPF_ATTR_LEN];
	char			path[GPS_MAX_CPF_PATH_LEN];
} gps_color_profile_info_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsColor_getProfile( gwmsg_client_t* client , void **addr, long *num );

/**********************************************************
 * id	: 2520
 * ����	: gpsUjobCancel()
 * date	: 2002/04/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_UJOB_CANCEL ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_UJOB_CANCEL		(1<<18)

/* gpsUjobCancel(): status */
#define	GPS_UJOBCANCEL_SUCCESS		0
#define	GPS_UJOBCANCEL_FAILED		1

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsUjobCancel( gwmsg_client_t* client, int ujobid, int *status);

/**********************************************************
 * id	: 2521
 * ����	: gpsPenvDataAllocShm()
 * date	: 2002/04/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PENV_DATA_ALLOC_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PENV_DATA_ALLOC_SHM		(1<<19)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsPenvDataAllocShm( gwmsg_client_t* client, int penv, long *offset, long size, int *result );

/**********************************************************
 * id	: 2522
 * ����	: gpsPenvDataFreeShm()
 * date	: 2002/04/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PENV_DATA_FREE_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PENV_DATA_FREE_SHM		(1<<20)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsPenvDataFreeShm( gwmsg_client_t* client, int penv, long offset, int *result );

/**********************************************************
 * id	: 2523
 * ����	: gpsPenvSetDataShm()
 * date	: 2002/04/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PENV_SET_DATA_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PENV_SET_DATA_SHM		(1<<21)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsPenvSetDataShm( gwmsg_client_t* client, int penv, long var, long offset, long val_size, int *result );

/**********************************************************
 * id	: 2524
 * ����	: gpsPenvGetDataShm()
 * date	: 2002/04/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PENV_GET_DATA_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PENV_GET_DATA_SHM		(1<<22)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsPenvGetDataShm( gwmsg_client_t* client, int penv, long var, long *offset, long in_size, long *out_size, int *result );

/**********************************************************
 * id	: 2525
 * ����	: gpsGetPaperWidLen()
 * date	: 2002/04/21
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_GET_PAPER_WID_LEN ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_GET_PAPER_WID_LEN		(1<<23)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsGetPaperWidLen( gwmsg_client_t* client, u_char psize, u_short *pwidth, u_short *plength );

/**********************************************************
 * id	: 2526
 * ����	: gpsAuthReq()
 * date	: 2003/12/04
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_AUTH_REQ ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_AUTH_REQ		(1<<24)

/* gpsAuthReq(): status */
#define	GPS_AUTH_SUCCESS	(0)	/* ����   */
#define	GPS_AUTH_FAILED		(-1)	/* ���s   */
#define	GPS_AUTH_BUSY		(-2)	/* �r�W�[ */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsAuthReq( gwmsg_client_t* client, int ujobid, int *status );

/**********************************************************
 * id	: 2527
 * ����	: gpsColor_getPrmVal
 * date	: 2004/04/14
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_COLOR_GET_PRM_VAL ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_COLOR_GET_PRM_VAL		(1<<25)

/* PrmID */
/* GPS_COLOR_xx�FSP1-108-xx(�g���g�i�[�Z�[�u)�ݒ�l�擾�v�� */
#define GPS_COLOR_01		(1)
#define GPS_COLOR_02		(2)
#define GPS_COLOR_03		(3)
#define GPS_COLOR_04		(4)
#define GPS_COLOR_05		(5)
#define GPS_COLOR_06		(6)
#define GPS_COLOR_07		(7)
#define GPS_COLOR_08		(8)
#define GPS_COLOR_09		(9)
#define GPS_COLOR_10		(10)

/* 09A(Zeus-P1�`)����ǉ� */
/* GPS_ECOCOLOR_xx�FSP1-109-xx(�G�R�m�~�[�J���[���[�h)�ݒ�l�擾�v�� */
#define GPS_ECOCOLOR_01		(21)
#define GPS_ECOCOLOR_02		(22)
#define GPS_ECOCOLOR_03		(23)
#define GPS_ECOCOLOR_04		(24)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsColor_getPrmVal( gwmsg_client_t* client, int param, u_long *val, int *result );

/**********************************************************
 * id	: 2528
 * ����	: gpsInterpReqEventNotify
 * date	: 2004/04/14
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_INTERP_REQ_EVENT_NOTIFY ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_INTERP_REQ_EVENT_NOTIFY	(1<<26)

/* req */
#define	GPS_INTERP_REQ_EVENT_FEED2	1

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsInterpReqEventNotify( gwmsg_client_t* client, int req, int *result );

/**********************************************************
 * id	: 2529
 * ����	: gpsTrayRequest2()
 * date	: 2004/04/25
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_TRAY_REQUEST2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_TRAY_REQUEST2		(1<<27)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_trayrequestEx
{
	unsigned long		flag;		/* �ݒ肷��p�����[�^ */
#define GPS_TRAYREQFLAG_ALL			(0xFFFFFFFF)	/* ���ׂ� */
#define GPS_TRAYREQFLAG_PWIDTH		(1<<0)			/* �p���� */
#define GPS_TRAYREQFLAG_PLENGTH		(1<<1)			/* �p���� */
#define GPS_TRAYREQFLAG_MODE		(1<<2)			/* �������[�h */
	unsigned long		pwidth;		/* �t���[�T�C�Y���̗p����   (0.1mm�P��) */
	unsigned long		plength;	/* �t���[�T�C�Y���̗p������ (0.1mm�P��) */
	unsigned char		mode:1;		/* �����w�� */
#define	GPS_REQ_MODE1				(0)				/* �p�����A��������v�����ꍇ�̂� */
#define	GPS_REQ_MODE2				(1)				/* �傫���T�C�Y������ꍇ�ł�OK */
	unsigned char		res1:7;		/* ���U�[�u */
	unsigned char		res2[31];	/* ���U�[�u */

} gps_trayrequestEx_t, *gps_trayrequestEx_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsTrayRequest2( gwmsg_client_t* client, int plotid, int psize, int nodir, int ptype, int tray, const gps_trayrequestEx_t *pTrayReq, int *result );

/**********************************************************
 * id	: 2530
 * ����	: gpsFrameCreateEx()
 * date	: 2004/04/25
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FRAME_CREATE_Ex ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_CREATE_EX		(1<<28)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_pagemode2
{
	unsigned long		flag;			/* �ݒ肷��p�����[�^ */
#define GPS_PAGEMODEFLAG_FWIDTH			(1<<0)		/* �t���[���� */
#define GPS_PAGEMODEFLAG_FLENGTH		(1<<1)		/* �t���[���� */
#define GPS_PAGEMODEFLAG_BAND			(1<<2)		/* �o���h�� */
	unsigned long		frame_width;	/* �t���[���̕�   (�h�b�g�P��) */
	unsigned long		frame_length;	/* �t���[���̒��@ (�h�b�g�P��) */
	unsigned long		band_length;	/* �o���h�̍���   (�h�b�g�P��) */
	unsigned char		res[32];		/* ���U�[�u */
} gps_pagemode2_t, *gps_pagemode2_p;


/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsFrameCreateEx( gwmsg_client_t* client, int plotid, const gps_pagemode2_t *ppagemode2, const gps_pageinfo2_t *ppageinfo2, int *result );

/**********************************************************
 * id	: 2531
 * ����	: gpsReplotInfoEx()
 * date	: 2004/04/25
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_REPLOT_INFO_EX ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_REPLOT_INFO_EX		(1<<29)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsReplotInfoEx( gwmsg_client_t* client, int plotid, gps_pagemode2_t *ppagemode2, gps_pageinfo2_t *ppageinfo2, int *result );

/**********************************************************
 * id	: 2532
 * ����	: gpsPlotChkDirection2()
 * date	: 2004/04/25
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_CHK_DIR2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_CHK_DIR2	(1<<30)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_chkdirprmEx_tag
{
	unsigned long	flag;			/* �ݒ肷��p�����[�^ */
#define GPS_CHKDIR2_ALL				(0xFFFFFFFF)	/* ���ׂ� */
#define GPS_CHKDIR2_PWIDTH			(1<<0)			/* �p���� */
#define GPS_CHKDIR2_PLENGTH			(1<<1)			/* �p���� */
	unsigned long	ulwidth;		/* �p����(0.1mm�P��) */
	unsigned long	ullength;		/* �p����(0.1mm�P��) */
	unsigned char	res[32];		/* ���U�[�u */
	
} gps_chkdirprmEx_t, *gps_chkdirprmEx_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotChkDirection2( gwmsg_client_t* client, int plotid, const gps_chkdirprm_t *condition, const gps_chkdirprmEx_t *condEx, int *direction, int *slantdirection );

/**********************************************************
 * id	: 2533
 * ����	: gpsFormGetImageInfo()
 * date	: 2004/06/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FORM_OVERLAY ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FORM_OVERLAY	(1<<31)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsFormGetImageInfo(gwmsg_client_t* client, int plotid, int formno, int *result);

/**********************************************************
 * id	: 2534
 * ����	: gpsFormOpen()
 * date	: 2004/06/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FORM_OVERLAY ���`���鎖
 **********************************************************/
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsFormOpen(gwmsg_client_t* client, int plotid, int formno, int *result);

/**********************************************************
 * id	: 2535
 * ����	: gpsFormClose()
 * date	: 2004/06/01
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_FORM_OVERLAY ���`���鎖
 **********************************************************/
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsFormClose(gwmsg_client_t* client, int formno, int frameid, int *result);


/**********************************************************
 * id	: 1543
 * ����	: gpsFrameFlushBand()
 * date	: 2002/09/10
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_BAND_DRAW_CONTINUE ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FRAME_FLUSH_BAND	(1<<19)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */

extern int	gpsFrameFlushBand( gwmsg_client_t* client, int frameid, int bandid, int planeid, int drawn );

/**********************************************************
 * id	: 2580
 * ����	: GWID_GpsEv_GetPrm_Info_Res
 * date	: 2001/06/30
 **********************************************************/

/**********************************************************
 * id	: 2581
 * ����	: GWID_GpsEv_Notify_PageExit
 * date	: 2002/01/23
 **********************************************************/
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_event_pageexit {
	int		ujobid;
	int		kind;
	long		pageno;
	unsigned short	outbin;
	unsigned char	printcount;
	unsigned char	face;
	long		repeat_count;
	long		repeat_max;
	unsigned char	dummy_page;
	char		reserved[31];
} gps_event_pageexit_t, *gps_event_pageexit_p;

/**********************************************************
 * id	: 2582
 * ����	: GWID_GpsEv_Xpdl_Notify
 * date	: 2002/01/25
 **********************************************************/
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */

typedef union _xpdl_notify_data {
	struct xpdl_ujobend {			/* GPS_XPDL_NOTIFY_UJOB_END */
		int			ujobid;
		char			reserved[56];
	} ujobend;
	struct xpdl_menu_entry {			/* GPS_XPDL_NOTIFY_MENU_ENTRY */
		int				pdl_id;
		char			reserved[56];
	} menu_entry;
	unsigned char			uc[60];
	unsigned short			us[30];
	unsigned long			ul[15];
} _xpdl_notify_data_t;

typedef struct gps_event_xpdl_notify {
	int						info_id;
	_xpdl_notify_data_t		data;
} gps_event_xpdl_notify_t, *gps_event_xpdl_notify_p;

/* info_id */
#define	GPS_XPDL_NOTIFY_TESTPRN_DONE	(0)
#define	GPS_XPDL_NOTIFY_UJOB_END	(1)
#define	GPS_XPDL_NOTIFY_MENU_ENTRY		(2)
#define	GPS_XPDL_NOTIFY_SETTING_CHANGE		(3)

/**********************************************************
 * id	: 2583
 * ����	: GWID_GpsEv_Auth_Res
 * date	: 2003/12/04
 **********************************************************/
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */

/* limitrole */
#define	GPS_AUTH_LIMIT_ADMINMACHINE	(1 << 0)	/* �@��Ǘ��ҋ@�\ 	*/
#define	GPS_AUTH_LIMIT_ADMINUSER	(1 << 1)	/* ���[�U�[�Ǘ��ҋ@�\ */
#define	GPS_AUTH_LIMIT_ADMINDOCUMENT	(1 << 2)	/* �����Ǘ��ҋ@�\ 	*/
#define	GPS_AUTH_LIMIT_ADMINNETWORK	(1 << 3)	/* �l�b�g���[�N�Ǘ��ҋ@�\ */
#define	GPS_AUTH_LIMIT_CERUSER		(1 << 4)	/* �F�؃��[�U�@�\ 	*/
#define	GPS_AUTH_LIMIT_SUPERVISOR      	(1 << 5)	/* �X�[�p�[�o�C�U�[�@�\ */
#define	GPS_AUTH_LIMIT_SERVICE		(1 << 6)	/* �T�[�r�X�@�\ 	*/

/* result */
#define	GPS_AUTH_RES_OK			(0)
#define	GPS_AUTH_RES_NG			(1)
#define	GPS_AUTH_RES_BUSY		(2)
#define	GPS_AUTH_RES_CANCEL		(3)
#define	GPS_AUTH_RES_TIMEOUT		(4)


#endif

/**********************************************************
 * id	: 2584
 * ����	: GWID_GpsEv_Notify_Feed2
 * date	: 2004/04/14
 **********************************************************/


/**********************************************************
 * id	: 2585
 * ����	: GWID_GpsPage_TrayRequest2_Res
 * date	: 2004/04/25
 **********************************************************/

/**********************************************************
 * id	: 2586
 * ����	: GWID_GpsPage_FormGetImageInfo_Res
 * date	: 2004/06/01
 **********************************************************/

/**********************************************************
 * id	: 2587
 * ����	: GWID_GpsPage_FormOpen_Res
 * date	: 2004/06/01
 **********************************************************/


/*
 * Copyright (c) 2001 Ricoh Company, Ltd.  All Rights Reserved.
 */

