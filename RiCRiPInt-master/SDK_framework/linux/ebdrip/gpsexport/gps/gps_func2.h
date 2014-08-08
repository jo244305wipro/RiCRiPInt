/* -*- tab-width: 4; c-basic-offset: 4; -*- *** vi:ts=4:sw=4
 ***********************************************************
 *	$Id$
 *
 *	Copyright (C) 2005 Ricoh Company, Ltd.  All Rights Reserved.
 *
 *	FILE NAME	: gps_func2.h
 *	VERSION		: $Revision$
 *	AUTHOR		: Satoshi MIYAZAKI
 *----------------------------------------------------------
 *	HISTORY
 *	12 Jan 2005: Created.
 *	$Log$
 *
 ***********************************************************/
#ifndef _GPS_FUNC2_H_
#define	_GPS_FUNC2_H_


/**********************************************************
 * Function
 * ���ϐ��ɃZ�b�g����r�b�g�� 31 �܂ő������玟�̊���
 * ����p�ӂ��鎖
 * �g�p�ϐ�: gps_function_support_info2
 **********************************************************/

/**********************************************************
 * id	: 2536
 * ����	: gpsColor_getID2()
 * date	: 2005/01/12
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_COLOR_GET_ID2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define	GPS_COLOR_GET_ID2	(1<<0)

/* prt */
#define	NONE_PRINTMODE		0	/* �w��Ȃ� */
#define	HIGH_PRINTMODE		1	/* ���� */
#define	NORMAL_PRINTMODE	2	/* �W�� */
#define	QUALITY_PRINTMODE	3	/* ���掿 */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsColor_getID2(gwmsg_client_t *client, int hdpi, int vdpi, int bit, int draw, unsigned char prt, unsigned char paper, int *modeID);

/**********************************************************
 * id	: 2537
 * ����	: gpsColor_getGoff2()
 * date	: 
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_COLOR_GET_ID2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 * GPS_COLOR_GET_ID2 ���g�p
 */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
#ifdef	__INC_GPS_NEW_COLOR_DEF__
extern int	gpsColor_getGoff2( gwmsg_client_t* client, int modeID, gps_nclr_gmfile_t *gmfile );
#endif

/**********************************************************
 * id	: 2538
 * ����	: gpsColor_get_drawparam2()
 * date	: 
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_COLOR_GET_ID2 ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 * GPS_COLOR_GET_ID2 ���g�p
 */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
#ifdef	__INC_GPS_NEW_COLOR_DEF__
extern int	gpsColor_get_drawparam2( gwmsg_client_t* client, int modeID, gps_nclr_drawparam_t *param );
#endif

/**********************************************************
 * id	: 2539
 * ����	: gpsInterpPauseAns()
 * date	: 
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define	GPS_INTERP_PAUSE_ANS	(1<<1)

/* result */
#define GPS_INTERP_PAUSE_OK		(0)
#define GPS_INTERP_PAUSE_NG		(-1)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpPauseAns( gwmsg_client_t* client, int ujobid, int result, ulong param );

/**********************************************************
 * id	: 2540
 * ����	: gpsInterpResumeAns()
 * date	: 
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 * GPS_INTERP_PAUSE_ANS ���g�p
 */

/* result */
#define GPS_INTERP_RESUME_OK	(0)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpResumeAns( gwmsg_client_t* client, int ujobid, int result, ulong param );

/*********************************************************************
 * id		: 2541
 * ����		: gpsDispSetFreeMsg()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/

/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
#define	GPS_FUNC_IPDS	(1<<2)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_freemsg
{
	unsigned char	charset;		/* charset */
#define GPS_MAX_FREEMSG			(80)
	unsigned char	str[GPS_MAX_FREEMSG];	/* ������ */
} gps_freemsg_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsDispSetFreeMsg( gwmsg_client_t* client, const gps_freemsg_t *freemsg );


/*********************************************************************
 * id		: 2542
 * ����		: gpsInterpFinishProcData2()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpFinishProcData2( gwmsg_client_t* client, int njobid );


/*********************************************************************
 * id		: 2543
 * ����		: gpsInterpJobResumeAns(()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)

/* result */
#define GPS_SYS_SUCCESS		(0)
#define GPS_SYS_FAILURE		(-1)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpJobResumeAns( gwmsg_client_t* client, int result );

/*********************************************************************
 * id		: 2544
 * ����		: gpsInterpJobEndAns(()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpJobEndAns( gwmsg_client_t* client, int result );

/*********************************************************************
 * id		: 2545
 * ����		: gpsInterpSessionCloseAns()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpSessionCloseAns( gwmsg_client_t* client, int njobid, int result );

/*********************************************************************
 * id		: 2546
 * ����		: gpsGetFormTrayInfo()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_formtray_info
{
	int	result;
	gps_penv_varinfo_t	varinfo;	/* Value Information */
} gps_formtray_info_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetFormTrayInfo( gwmsg_client_t* client, int formid, long penvid, gps_formtray_info_t *formtrayinfo );


/*********************************************************************
 * id		: 2547
 * ����		: gpsGetFormTrayList()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_formtray_list
{
#define GPS_FORMTRAY_MAX		(20)
	int	formid[GPS_FORMTRAY_MAX];
} gps_formtray_list_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetFormTrayList( gwmsg_client_t* client, gps_formtray_list_t *formtraylist );

/*********************************************************************
 * id		: 2548
 * ����		: gpsGetFormTrayList()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotChangeFormTray( gwmsg_client_t* client, int plotid, int formid, int *result );

/*********************************************************************
 * id		: 2549
 * ����		: gpsGetFormTrayInfoStr()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_formtray_info_str
{
	int	result;
#define GPS_MAX_FORMNAME		(20)
	char	name[GPS_MAX_FORMNAME+1]; /* FORM�� */
} gps_formtray_info_str_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetFormTrayInfoStr( gwmsg_client_t* client, int formid, gps_formtray_info_str_t *formtrayinfostr );

/*********************************************************************
 * id		: 2550
 * ����		: gpsGetFormTrayInfoAttr()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_formtray_info_attr
{
	int	result;
	unsigned long attr;	/* attr */
} gps_formtray_info_attr_t;
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetFormTrayInfoAttr( gwmsg_client_t* client, int formid, gps_formtray_info_attr_t *formtrayinfoattr );

/*********************************************************************
 * id		: 2551
 * ����		: gpsInterpFinishFontreset()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsInterpFinishFontreset( gwmsg_client_t* client );

/*********************************************************************
 * id		: 2552
 * ����		: gpsUjobCancel2()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsUjobCancel2( gwmsg_client_t* client, int njobid );

/*********************************************************************
 * id		: 2553
 * ����		: gpsGetStapleOkSize()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* Staple Position */
#define		GPS_SYS_STAPLE_NONE		(0) /* No Staple */
#define		GPS_SYS_STAPLE_TOP_POS		(1) /* Top */
#define		GPS_SYS_STAPLE_BOTTOM_POS	(2) /* Bottom */
#define		GPS_SYS_STAPLE_BOTH_POS		(3) /* Both */
#define		GPS_SYS_STAPLE_SADDLE_POS	(4) /* Saddle */

extern u_char	gpsGetStapleOkSize( gwmsg_client_t* client, u_char p_size, u_short p_width, u_short p_length, u_char position );

/*********************************************************************
 * id		: 2554
 * ����		: gpsGetPunchOkSize()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* Punch Position Bit */
#define		GPS_SYS_BIT_PUNCHHOLE_NONE	(0x00) /* Punch Disable */
#define		GPS_SYS_BIT_PUNCHHOLE2		(0x01) /* 2-Hole Punch */
#define		GPS_SYS_BIT_PUNCHHOLE3		(0x02) /* 3-Hole Punch */
#define		GPS_SYS_BIT_PUNCHHOLE4_EU	(0x04) /* 4-Hole(EU) Punch */
#define		GPS_SYS_BIT_PUNCHHOLE4_NE	(0x08) /* 4-Hole(NE) Punch */
#define		GPS_SYS_BIT_PUNCHHOLE2_NA	(0x10) /* 4-Hole(NA) Punch */

extern u_char	gpsGetPunchOkSize( gwmsg_client_t* client, u_char p_size, u_short p_width, u_short p_length );

/*********************************************************************
 * id		: 2555
 * ����		: gpsGetStapleMax()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* Punch Position */
#define		GPS_SYS_PUNCH_NONE		(0) /* None */
#define		GPS_SYS_PUNCH_2			(1) /* 2-Hole */
#define		GPS_SYS_PUNCH_3			(2) /* 3-Hole */
#define		GPS_SYS_PUNCH_4_EU		(3) /* 4-Hole (EU) */
#define		GPS_SYS_PUNCH_4_NE		(4) /* 4-Hole (NE) */
#define		GPS_SYS_PUNCH_2_NA		(5) /* 2-Hole (NA) */

#define		GPS_SYS_PUNCH_OFF		(0)
#define		GPS_SYS_PUNCH_ON		(1)

extern u_char	gpsGetStapleMax( gwmsg_client_t* client, u_char p_size, u_char p_kind, u_short p_width, u_short p_length, u_char punch, u_char position );

/*********************************************************************
 * id		: 2556
 * ����		: gpsGetStaplePos()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* Staple Position Bit Deatil */
#define		GPS_SYS_BIT_STAPLE_OFF		(0)
#define		GPS_SYS_BIT_STAPLE_LEFTTOPSLANT	(1 << 0)
#define		GPS_SYS_BIT_STAPLE_RIGHTTOPSLANT (1 << 1)
#define		GPS_SYS_BIT_STAPLE_LEFT2	(1 << 2)
#define		GPS_SYS_BIT_STAPLE_TOP2		(1 << 3)
#define		GPS_SYS_BIT_STAPLE_RIGHT2	(1 << 4)
#define		GPS_SYS_BIT_STAPLE_LEFTTOP	(1 << 5)
#define		GPS_SYS_BIT_STAPLE_RIGHTTOP	(1 << 6)
#define		GPS_SYS_BIT_STAPLE_BOOKLET	(1 << 7)

extern u_long	gpsGetStaplePos( gwmsg_client_t* client );

/*********************************************************************
 * id		: 2557
 * ����		: gpsGetPunchPos()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* Punch Position Bit Detail */
#define		GPS_SYS_BIT_PUNCH_OFF		(0)
#define		GPS_SYS_BIT_PUNCH_LEFT2		(1 << 0)
#define		GPS_SYS_BIT_PUNCH_TOP2		(1 << 1)
#define		GPS_SYS_BIT_PUNCH_RIGHT2	(1 << 2)
#define		GPS_SYS_BIT_PUNCH_LEFT3		(1 << 3)
#define		GPS_SYS_BIT_PUNCH_TOP3		(1 << 4)
#define		GPS_SYS_BIT_PUNCH_RIGHT3	(1 << 5)
#define		GPS_SYS_BIT_PUNCH_LEFT4		(1 << 6)
#define		GPS_SYS_BIT_PUNCH_TOP4		(1 << 7)
#define		GPS_SYS_BIT_PUNCH_RIGHT4	(1 << 8)

extern u_long	gpsGetPunchPos( gwmsg_client_t* client );

/*********************************************************************
 * id		: 2558
 * ����		: gpsGetPaperExitOkSize()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
/* face */
#define		GPS_SYS_FACE_UP			(0)
#define		GPS_SYS_FACE_DOWN		(1)
#define		GPS_SYS_FACE_NONE		(0xff)
/* tray */
#define		GPS_SYS_TRAY_NONE		(0xff)
/* EXit Tray Position Bit */
#define		GPS_SYS_BIT_EXIT_NONE		(0x0000) /* :Output Disable */
#define		GPS_SYS_BIT_EXIT_NORMAL		(0x0001) /* :Normal Output Tray */
#define		GPS_SYS_BIT_EXIT_SHIFT		(0x0002) /* :Shift Tray */
#define		GPS_SYS_BIT_EXIT_PROOF		(0x0004) /*: Proof Tray */
#define		GPS_SYS_BIT_EXIT_MAIL_BOX	(0x0008) /* :Mail Box */
#define		GPS_SYS_BIT_EXIT_BIN1		(0x0010) /* :1Bin Tray */
#define		GPS_SYS_BIT_EXIT_SADDLE		(0x0020) /* :Saddle Tray */
#define		GPS_SYS_BIT_EXIT_SHIFT_1	GPS_SYS_BIT_EXIT_SHIFT /* :Shift Tray1 */
#define		GPS_SYS_BIT_EXIT_FU			(0x0040) /* :Fu Exit Tray */
#define		GPS_SYS_BIT_EXIT_SHIFT_2	(0x0080) /* :Shift Tray2 */

extern u_long	gpsGetPaperExitOkSize( gwmsg_client_t* client, u_char p_size, u_short p_width, u_short p_length, u_char face, u_char trayno );

/*********************************************************************
 * id		: 2559
 * ����		: gpsGetPunchOkKind()
 * Date		: 2007/03/29
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern u_char	gpsGetPunchOkKind( gwmsg_client_t* client, u_char p_kind );

/*********************************************************************
 * id		: 2560
 * ����		: gpsGetTrayInfo2()
 * Date		: 2007/03/29
 * ---------------------------------------
 *********************************************************************/
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetTrayInfo2(gwmsg_client_t* client, int num, gps_trayinfo_t *trayinfo, long *trayinfo_size, int notify);

/**********************************************************
 * id		: 2561
 * ����		: gpsPlotPrepare()
 * date		: 2007/07/05
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_PREPARE ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_PREPARE	(1<<3)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_plotprepareparam {
	unsigned short	resolution_x;		/* X�����𑜓x (25.4mm������̃h�b�g��) */
	unsigned short	resolution_y;		/* Y�����𑜓x (25.4mm������̃h�b�g��) */
	unsigned char		depth;		/* �ʎq����(�K��) */
	unsigned char		paper_type;	/* ���� */
	unsigned char		color_count;	/* �F�� */
	unsigned char		reserved[25];
} gps_plotprepareparam_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotPrepare( gwmsg_client_t* client, int ujobid, gps_plotprepareparam_t *param );

/*********************************************************************
 * id		: 2562
 * ����		: gpsGetStapleOkKind()
 * Date		: 2007/11/02
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern u_char	gpsGetStapleOkKind( gwmsg_client_t* client, u_char p_kind , u_char position );

/*********************************************************************
 * id		: 2563
 * ����		: gpsGetPaperExitOkKind()
 * Date		: 2007/11/02
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_IPDS ���`���鎖
 *********************************************************************/
/*
 * ���ϐ� gps_function_support_info �ɃZ�b�g�����r�b�g
 */
//#define	GPS_FUNC_IPDS	(1<<2)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern u_long	gpsGetPaperExitOkKind( gwmsg_client_t* client, u_char p_kind, u_char face, u_char trayno );

/**********************************************************
 * id		: 2564
 * ����		: gpsPlotGetShmInfo()
 * date		: 2008/03/21
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_SETPARAM_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define	GPS_PLOT_SETPARAM_SHM	(1<<4)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotGetShmInfo( gwmsg_client_t* client, long *offset, long *size, int *result );

/**********************************************************
 * id		: 2565
 * ����		: gpsPlotSetPageParam_Shm()
 * date		: 2008/03/21
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_XXXX.h ����
 * GPS_SUPPORT_PLOT_SETPARAM_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
//#define	GPS_PLOT_SETPARAM_SHM	(1<<4)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsPlotSetPageParam_Shm( gwmsg_client_t* client, int plotid, int *result );

/**********************************************************
 * id		: 2566
 * ����		: gpsChkDuplexOk()
 * date		: 2008/08/06
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_CHK_DUPLEX_OK ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_CHK_DUPLEX_OK					(1<<5)

/*
 * �t���O�̒�`
 */
#define  GPS_DUPLEX_CHK_SIZE				(1 << 0)      /*�p���T�C�Y�����ʉ\���`�F�b�N*/
#define  GPS_DUPLEX_CHK_KIND				(1 << 1)      /*�p����ނ����ʉ\���`�F�b�N*/

/*
 * ���^�[���l�̒�`
 */
#define  GPS_DUPLEX_CHK_NG					0             /*���ʒʎ��s�\*/
#define  GPS_DUPLEX_CHK_OK					1             /*���ʒʎ��\*/

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_chkduplexok_tag {
	unsigned long flag;					/* �ݒ肷��p�����[�^ */
	unsigned long pwidth;				/* �t���[�T�C�Y���̗p����   (0.1mm�P��) */
	unsigned long plength;				/* �t���[�T�C�Y���̗p������ (0.1mm�P��) */
	unsigned char psize;
	unsigned char pkind;
	unsigned char reserved[18];			/* ���U�[�u (�@�\�ǉ��p) */
} gps_chkduplexok_t, *gps_chkduplexok_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsChkDuplexOk( gwmsg_client_t* client, gps_chkduplexok_t *pchkduplexok, int *result );

/**********************************************************
 * id		: 2567
 * ����		: gpsChkExtPortOk()
 * date		: 2008/11/28
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_CHK_PORT_OK ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_CHK_PORT_OK					(1<<6)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsChkExtPortOk( gwmsg_client_t* client, int *result );

/**********************************************************
 * id		: 2568
 * ����		: gpsGetPrtStatus2Shm()
 * date		: 2009/01/20
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_PRTSTATUS2SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_PRTSTATUS2SHM					(1<<7)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetPrtStatus2Shm( gwmsg_client_t* client, long *offset, int notify, int *result );

/**********************************************************
 * id		: 2569
 * ����		: gpsGetTrayInfoTrayBusyShm()
 * date		: 2009/12/20
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_TRAYINFOBUSYSHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_TRAY_INFO_BUSY_SHM					(1<<8)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_trayinfobusy_shm_header {
#define	GPS_TRAYINFO_SHM_STAT_LOCKED		(0x80000000L)
#define	GPS_TRAYINFO_SHM_STAT_COUNT_MASK	(0x0000ffffL)
	unsigned long	stat;
} gps_trayinfobusy_shm_header_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetTrayInfoBusyShm( gwmsg_client_t* client, int *ret_code, int num, long *offset, int *ret_num, int notify);

/**********************************************************
 * id		: 2570
 * ����		: gpsGetPdlPrintCondition()
 * date		: 2010/09/30
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_PDLPRINTCONDITION ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_PDL_PRINT_CONDITION			(1<<9)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
/* printcond.h�ɂĒ�` */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetPdlPrintCondition(gwmsg_client_t* client, int ujobid, int *status, gps_pdl_printcondition_t *cond, gps_pdl_media_printcondition_t *media);

/**********************************************************
 * id		: 2571
 * ����		: gpsGetPdfParam()
 * date		: 2010/09/30
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_PDFPARAM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_PDF_PARAM						(1<<10)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
/* printcond.h�ɂĒ�` */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetPdfParam(gwmsg_client_t* client, int ujobid, int *status, gps_pdf_param_t *param);

/**********************************************************
 * id		: 2572
 * ����		: gpsSetPdlPrintInfo()
 * date		: 2010/11/16
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_SET_PDL_PRINT_INFO ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_SET_PDL_PRINT_INFO					(1<<11)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
typedef struct gps_pdl_printinfo {
	/* ��������ύX�̏����l��ݒ肷��p�����[�^ */
	unsigned long	flag;					/* �ݒ肷��p�����[�^ */
		#define	GPS_PDL_PRTINFO_NUP					(1<<0)	/* �p�����[�^ nup ���L�� */
		#define	GPS_PDL_PRTINFO_UPSIDEDOWN			(1<<1)	/* �p�����[�^ upsidedown ���L�� */

	struct {
		unsigned char	layout;					/* �W�� */
			#define	GPS_NUP_LAYOUT_OFF				(0)		/* �W�񖳂� */
			#define	GPS_NUP_LAYOUT_2IN1				(1)		/* 2in1 */
			#define	GPS_NUP_LAYOUT_4IN1				(2)		/* 4in1 */
			#define	GPS_NUP_LAYOUT_6IN1				(3)		/* 6in1 */
			#define	GPS_NUP_LAYOUT_8IN1				(4)		/* 8in1 */
			#define	GPS_NUP_LAYOUT_9IN1				(5)		/* 9in1 */
			#define	GPS_NUP_LAYOUT_16IN1			(6)		/* 16in1 */

		unsigned char	option;					/* �W��p�����[�^ */
			#define	GPS_NUP_OPTION_RIGHT_THEN_DOWN	(0)		/* 2in1�ȊO:���と�E�と�������E�� 2in1:������E�� */
			#define	GPS_NUP_OPTION_LEFT_THEN_DOWN	(1)		/* 2in1�ȊO:�E�と���と�E�������� 2in1:�E���獶�� */
			#define	GPS_NUP_OPTION_DOWN_THEN_RIGHT	(2)		/* 2in1�ȊO:���と�������E�と�E�� 2in1:���g�p */
			#define	GPS_NUP_OPTION_DOWN_THEN_LEFT	(3)		/* 2in1�ȊO:�E�と�E�������と���� 2in1:���g�p */

		unsigned char	line;					/* �W��d�؂�� */
			#define	GPS_NUP_LINE_OFF				(0)		/* �W��d�؂������ */
			#define	GPS_NUP_LINE_ON					(1)		/* �W��d�؂���L�� */

		unsigned char	reserve;				/* �@�\�ǉ��p */

	} nup;

	unsigned char		upsidedown;				/* 180�x��] */
			#define	GPS_UPSIDEDOWN_OFF				(0)		/* 180�x��]���Ă��Ȃ� */
			#define	GPS_UPSIDEDOWN_ON				(1)		/* 180�x��]���Ă��� */

	unsigned char		reserve1[3];			/* �@�\�ǉ��p */

	unsigned long		reserve2[4];			/* �@�\�ǉ��p */


	/* �h���C�o�Ŏw�肳�ꂽ���������ݒ肷��p�����[�^ */
	unsigned long		driver_flag;			/* �ݒ肷��p�����[�^ */
			/* ( 1 << "driver_prtcond�̔z��ԍ�" )�Őݒ肷�����������w�肷�� */

	unsigned char		driver_prtcond[32];		/* �h���C�o�Ŏw�肳�ꂽ������� */
			#define	GPS_D_PRTCOND_OFF				(0)		/* �h���C�o�Ŏw�肵�Ă��Ȃ� */
			#define	GPS_D_PRTCOND_ON				(1)		/* �h���C�o�Ŏw�肵�Ă��� */

			/* driver_prtcond�̔z��ԍ� */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_WEEKLY			(0)		/* �T�����Ԃ� */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_OUTPUT_REVERSE	(1)		/* �t����� */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_USED_PROFILE		(2)		/* �v���t�@�C���������{������� */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_TAB				(3)		/* �^�u���i�C���f�b�N�X���j */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_PRINTER_MARKING	(4)	/* �n���� */
			#define	GPS_PDL_PRTINFO_D_PRTCOND_TWIN_COLOR		(5)	/* �Q�F�v�����g */

} gps_pdl_printinfo_t, *gps_pdl_printinfo_p;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsSetPdlPrintInfo( gwmsg_client_t* client, int plotid, gps_pdl_printinfo_t *prtinfo );

/**********************************************************
 * id		: 2573
 * ����		: gpsGetUcpParamShm()
 * date		: 2011/01/11
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_mach.h ����
 * GPS_SUPPORT_UCP ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_UCP_PARAM_SHM				(1<<12)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
/* info.h�ɂĒ�` */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetUcpParamShm( gwmsg_client_t* client, int ujobid, long *offset, int *result );

/**********************************************************
 * id		: 2574
 * ����		: gpsGetUcpData()
 * date		: 2011/01/11
 * ---------------------------------------
 * �T�|�[�g���� GPS �� config_mach.h ����
 * GPS_SUPPORT_UCP ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_UCP_DATA					(1<<13)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */

enum
{
	STRING_DOT_DENSITY1,		/* �����h�b�g�p�^�[���̒n��Z�x1�̃p�^�[���f�[�^ */
	STRING_DOT_DENSITY2,		/* �����h�b�g�p�^�[���̒n��Z�x2�̃p�^�[���f�[�^ */
	STRING_DOT_DENSITY3,		/* �����h�b�g�p�^�[���̒n��Z�x3�̃p�^�[���f�[�^ */
	STRING_DOT_DENSITY4,		/* �����h�b�g�p�^�[���̒n��Z�x4�̃p�^�[���f�[�^ */
	STRING_DOT_DENSITY5,		/* �����h�b�g�p�^�[���̒n��Z�x5�̃p�^�[���f�[�^ */
	BACKGROUND_DOT_DENSITY1,	/* �w�i�h�b�g�p�^�[���̒n��Z�x1�̃p�^�[���f�[�^ */
	BACKGROUND_DOT_DENSITY2,	/* �w�i�h�b�g�p�^�[���̒n��Z�x2�̃p�^�[���f�[�^ */
	BACKGROUND_DOT_DENSITY3,	/* �w�i�h�b�g�p�^�[���̒n��Z�x3�̃p�^�[���f�[�^ */
	BACKGROUND_DOT_DENSITY4,	/* �w�i�h�b�g�p�^�[���̒n��Z�x4�̃p�^�[���f�[�^ */
	BACKGROUND_DOT_DENSITY5,	/* �w�i�h�b�g�p�^�[���̒n��Z�x5�̃p�^�[���f�[�^ */
	MASKTYPE_AMIME,				/* �w�i�n��}�X�N�p�^�[���̖Ԗڂ̃p�^�[���f�[�^ */
	MASKTYPE_HIGAKI,			/* �w�i�n��}�X�N�p�^�[���̕O�_�̃p�^�[���f�[�^ */
	MASKTYPE_KIKKOU,			/* �w�i�n��}�X�N�p�^�[���̋T�b�̃p�^�[���f�[�^ */
	MASKTYPE_KOUSHI1,			/* �w�i�n��}�X�N�p�^�[���̊i�q1�̃p�^�[���f�[�^ */
	MASKTYPE_KOUSHI2,			/* �w�i�n��}�X�N�p�^�[���̊i�q2�̃p�^�[���f�[�^ */
	MASKTYPE_MATSUKAWABISHI,	/* �w�i�n��}�X�N�p�^�[���̏���H�̃p�^�[���f�[�^ */
	MASKTYPE_SEIGAIHA,			/* �w�i�n��}�X�N�p�^�[���̐C�g�̃p�^�[���f�[�^ */
	MASKTYPE_SHIPPOU,			/* �w�i�n��}�X�N�p�^�[���̎���̃p�^�[���f�[�^ */
	MASKTYPE_SYOKKOU,			/* �w�i�n��}�X�N�p�^�[����再]�̃p�^�[���f�[�^ */
	MASKTYPE_UROKO,				/* �w�i�n��}�X�N�p�^�[���̗؂̃p�^�[���f�[�^ */
	EFFECTCOPYGUARD_BACKGROUND,	/* �s���R�s�[�K�[�h�̔w�i�h�b�g�p�^�[���f�[�^ */
	EFFECTCOPYGUARD_STRING,		/* �s���R�s�[�K�[�h�̕�����h�b�g�p�^�[���f�[�^ */
};

#define	GPS_UCP_DATA_RES_200x200	(1)	/* �𑜓x200x200 */
#define	GPS_UCP_DATA_RES_300x300	(2)	/* �𑜓x300x300 */
#define	GPS_UCP_DATA_RES_400x400	(3)	/* �𑜓x400x400 */
#define	GPS_UCP_DATA_RES_600x600	(4)	/* �𑜓x600x600 */
#define	GPS_UCP_DATA_RES_600x1200	(5)	/* �𑜓x600x1200 */
#define	GPS_UCP_DATA_RES_1200x600	(6)	/* �𑜓x1200x600 */
#define	GPS_UCP_DATA_RES_1200x1200	(7)	/* �𑜓x1200x1200 */

#define	GPS_UCP_DATA_DEPTH_1BIT		(1)	/* 1bit */
#define	GPS_UCP_DATA_DEPTH_2BIT		(2)	/* 2bit */
#define	GPS_UCP_DATA_DEPTH_4BIT		(4)	/* 4bit */

typedef	struct {
	unsigned char	width;		/* �n��f�[�^�̕� */
	unsigned char	length;		/* �n��f�[�^�̍��� */
	long			offset;		/* ���L��������̒n��f�[�^�|�C���^�ւ̃I�t�Z�b�g */
}gps_ucp_data_t;

typedef	struct {
	unsigned char	kind;		/* �n��p�^�[���̎�� */
	unsigned char	resolution;	/* �n��p�^�[���̉𑜓x */
	unsigned char	depth;		/* �n��p�^�[����bit�̐[�� */
}gps_ucp_info_t;

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetUcpData(gwmsg_client_t *client, gps_ucp_info_t ucpinfo, gps_ucp_data_t *ucpdata, int *result)	;

/**********************************************************
 * id	: 2575
 * ����	: gpsGetCipherSeed()
 * date	: 2011/02/28
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_CIPHER_SEED				(1<<14)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetCipherSeed( gwmsg_client_t* client, int size, u_char *seed, long *seed_size ) ;

/**********************************************************
 * id		: 2576
 * ����		: gpsGetPdlPrintConditionShm()
 * date		: 2010/09/30
 * ---------------------------------------
 * �T�|�[�g���� GPS �� gps_api.h ����
 * GPS_SUPPORT_PDLPRINTCONDITION_SHM ���`���鎖
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_PDL_PRINT_CONDITION_SHM			(1<<15)

/*
 * API �ǉ��ɔ����Ēǉ������^��`
 */
/* printcond.h�ɂĒ�` */

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int	gpsGetPdlPrintConditionShm(gwmsg_client_t* client, int ujobid, int *status, unsigned long *offset);

/**********************************************************
 * id		: 2577
 * ����		: gpsGetHeadRiseMode()
 * date		: 2012/01/30
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_HEAD_RISE_MODE			(1<<16)
/*
 * �ǉ������ API �̃v���g�^�C�v
 */

typedef struct {		/* OUT */
	int	bypass;	/* �荷���g���C */
	int	tray1;		/* �g���C1 */
	int	tray2;		/* �g���C2 */
			#define GPS_HEADRISE_OFF (0) /* �w�b�h�㏸���[�hOFF */
			#define GPS_HEADRISE_ON  (1) /* �w�b�h�㏸���[�hON */
} gps_headrise_mode_t;

extern int	gpsGetHeadRiseMode(gwmsg_client_t* client, gps_headrise_mode_t *mode, int *result);

/**********************************************************
 * id	: 2579
 * ����	: GWID_GpsEv_TrayInfoBusy
 * date	: 
 **********************************************************/

/**********************************************************
 * id	: 2588
 * ����	: GWID_GpsEv_Interp_Pause_Req
 * date	: 
 **********************************************************/

/**********************************************************
 * id	: 2589
 * ����	: GWID_GpsEv_Interp_Resume_Req
 * date	: 
 **********************************************************/

/**********************************************************
 * id	: 2590
 * ����	: GWID_GpsEv_Notify_CaptureMode
 * date	: 2007/03/29
 **********************************************************/
/* mode */
#define GPS_SYS_CAPTURE_OFF				(0)
#define GPS_SYS_CAPTURE_ON				(1)

/**********************************************************
 * id	: 2591
 * ����	: GWID_GpsEv_Notify_EngineState
 * date	: 2007/03/29
 **********************************************************/
/* mode */
#define GPS_SYS_ENGINE_START				(0)
#define GPS_SYS_ENGINE_PRESTOP				(1)
#define GPS_SYS_ENGINE_STOP				(2)

/**********************************************************
 * id	: 2592
 * ����	: GWID_GpsEv_Req_JobEnd
 * date	: 2007/03/29
 **********************************************************/
/* reason */
#define GPS_REQ_JOBEND_REASON_SETTING			(0)
#define GPS_REQ_JOBEND_REASON_PDLCHANGE			(1)
#define GPS_REQ_JOBEND_REASON_POWERMODE			(2)

/**********************************************************
 * id	: 2593
 * ����	: GWID_GpsEv_Req_JobResume
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2594
 * ����	: GWID_GpsEv_Req_SessionClose
 * date	: 2007/03/29
 **********************************************************/
/* reason */
#define GPS_REQ_SESSIONCLOSE_REASON_REBOOT		(0)
#define GPS_REQ_SESSIONCLOSE_REASON_PDLCHANGE		(1)
#define GPS_REQ_SESSIONCLOSE_REASON_IPDSTESTPRINT	(2)
#define GPS_REQ_SESSIONCLOSE_REASON_IPDSFONTRESET	(3)

/**********************************************************
 * id	: 2595
 * ����	: GWID_GpsEv_Req_Proc_Data2
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2596
 * ����	: GWID_GpsEv_Notify_PurgedPages
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2597
 * ����	: GWID_GpsEv_Notify_StapleComplete
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2598
 * ����	: GWID_GpsEv_Req_Fontreset
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2599
 * ����	: GWID_GpsEv_TrayInfo2
 * date	: 2007/03/29
 **********************************************************/

/**********************************************************
 * id	: 2600
 * ����	: gpsGetPrtTotalCounterReq()
 * date	: 2012/08/21
 **********************************************************/
/*
 * ���ϐ� gps_function_support_info2 �ɃZ�b�g�����r�b�g
 */
#define  GPS_GET_PRT_TOTAL_COUNTER		(1<<17)

/*
 * �ǉ������ API �̃v���g�^�C�v
 */
extern int gpsGetPrtTotalCounterReq(gwmsg_client_t* client);

/**********************************************************
 * id	: 2601
 * ����	: GWID_GpsEv_GetPrtTotalCounter_Res
 * date	: 2012/08/21
 **********************************************************/

#endif	/* _GPS_FUNC2_H_ */
/*
 * Copyright (c) 2005 Ricoh Company, Ltd.  All Rights Reserved.
 */

