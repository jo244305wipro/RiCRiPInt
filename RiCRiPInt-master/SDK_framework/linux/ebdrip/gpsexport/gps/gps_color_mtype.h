/*
 * GPS COLOR LIBRARY TYPE DEFINITION.
 * Copyright (c) Ricoh Company, Ltd.
 * ALL Rights Reserved.
 *
 * $Id: gps_color_mtype.h,v 1.4 2000/04/05 01:42:05 MrX Exp MrX $
 * $Date: 2000/04/05 01:42:05 $
 * $Author: MrX $
 *
 * �K���}�E�f�B�U�f�[�^�̌^��`
 *
 */

#ifndef	__INC_GPS_COLOR_MTYPE__	/* { */
#define	__INC_GPS_COLOR_MTYPE__

/*
 * �F�C�r�b�g���̎w��
 */
/* �]�ʐF���̒�` */
#define	GPS_CLR_PLANE		4		/* 4 plane for Jupiter */

/* �F�ԍ��̒�` */
#define	GPS_CLR_K			0
#define	GPS_CLR_C			1
#define	GPS_CLR_M			2
#define	GPS_CLR_Y			3

/* �P�`��s�N�Z���̌^��` */
typedef	unsigned char	gps_clr_pixel_t;		/* 8bit for Jupiter */
#define	GPS_CLR_PIXEL_LVL	8					/* 8bit for Jupiter */
#define	GPS_CLR_PIXEL_OUT	(1<<GPS_CLR_PIXEL_LVL)		/* 8bit for Jupiter */

/* �`�惂�[�h���̒�` */
#define	GPS_CLR_DMODE		6		/*    3(1200x1200,1200x600,600x600)
										* 1(1bit)
								 		* 2(photo/text) = 6 for jupiter */

/* �����N�w�b�h�ő�l�̒�` */
#define	GPS_MAX_HEADRANK	9


/* ���A�����W�}�g���b�N�X�f�[�^ID�̌^��` */
typedef	unsigned short	gps_color_rid_t;	/* same type in gps_page_mode_t */

/* �K���}�����̒萔�̒�` */
#define	GPS_CLR_GAMUMODE	2			/* mode = highlight/midle */
#define	GPS_CLR_GAMSPNTS	15			/* point = 0-14 */



#endif	/* } __INC_GPS_COLOR_MTYPE__	 */
