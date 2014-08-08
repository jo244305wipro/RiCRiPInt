/**********************************************************************************
* GW PRINTER APPLICATION PANEL MANAGER HEADER FILE FOR PANEL-CLIENT
* Author:	Koji Dan			  Date: 2000/07/04
* Copyright:	Copyright (C) 2000, 2001 RICOH COMPANY, LTD.
* Function:	Defined the information table
* -------------------------------------------------------------------------------
* (Revision History)
*  ver0.10:(1999/10/25)  initial release
*  ver1.00:(2000/07/04)  �N���C�A���g�p�ɐ؂藣��
**********************************************************************************/
#ifndef __GPS_PM_INFORMATION_H_
#define	__GPS_PM_INFORMATION_H_
/*
 *  papman_def.h�̃o�[�W����
 */
#define   PAPMAN_DEF_H_20001026 1

/* =================================================================================== *
 *      ��ʃ}�N����`
 * =================================================================================== */
/*       */
#define   I_AM_GPS             123
/*       */
#define   GLOBAL               /**/
#define   PM_SUCCESS           0
#define   PM_FAILURE           (-1)
#define   MENU_GETITEM_FAIL    0xff

/*       */
#define   FILENAME_LEN         14
/*
 * STRING_CODE_MAX(= 160)�Ȃ̂����AGWIPC�̍ő勖�e(= 128)�̌��ˍ�������
 *     unsigned short	type;    ( �� 2 byte )
 *     unsigned short	length;  ( �� 2 byte )
 *     pid_t		pid;     ( �� 4 byte )
 *     �]�T��                    ( �� 8 byte )
 *  �ȏ������������, 128 - (2+2+4+8) = 112 byte �Ƃ���B
 */
#define   PM_STRING_LEN_MAX   112   /* GWIPC�̐���ɂ��킹��iNULL�^�[�~�l�[�g�܂ށj*/
#define   STRING_LEN          112   /* GWIPC�̐���ɂ��킹��iNULL�^�[�~�l�[�g�܂ށj*/
#define   STRING_LEN_P         17   /* CHAR�p�l���@�̍ő吔:NULL�^�[�~�l�[�g�܂� */
#define   DBG_MAX_NUM         (32)  /* �W�s�~�S�i�� */
#define   SELECT_ITEMS_NUM     16
#define   PM_ITEM_SIZE         32

/* =================================================================================== *
 *      �g���C���E�����E�L�[���E������E�k�d�c���
 * =================================================================================== */
/*
 *  �L�[�R�[�h�h�c
 */
enum {
  PM_KEY_NONE = 0xFFFD,             /* no key event */
  PM_KEY_C_0 = 0x40,                /* Number key (0) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_1,                       /* Number key (1) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_2,                       /* Number key (2) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_3,                       /* Number key (3) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_4,                       /* Number key (4) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_5,                       /* Number key (5) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_6,                       /* Number key (6) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_7,                       /* Number key (7) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_8,                       /* Number key (8) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_9,                       /* Number key (9) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_PERIOD,                  /* Number key(.�^*)�i�b���f���݂̂ɓK�p�j*/
  PM_KEY_C_SHARP,                   /* Number key (#) �i�b���f���݂̂ɓK�p�j */
  PM_KEY_C_CLEAR,                   /* Number key(clr)�i�b���f���݂̂ɓK�p�j */
  PM_KEY_P_UP = 0x80,               /* UP arrow key   �i�o���f���݂̂ɓK�p�j*/
  PM_KEY_P_DOWN,                    /* DOWN arrow key �i�o���f���݂̂ɓK�p�j*/
  PM_KEY_P_MENU,                    /* MENU key       �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_ESC,                     /* ESCAPE key     �i�o���f���݂̂ɓK�p�j*/
  PM_KEY_P_EXEC,                    /* EXECUTE key    �i�o���f���݂̂ɓK�p�j*/
  PM_KEY_P_EXIT_PAPER,              /* EXIT PAPER key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_RESET,                   /* RESET key      �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_ONLINE,                  /* ON/OFF LINE key�i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_MENU_UNLOCK,             /* Menu Lock key  �i�o���f���݂̂ɓK�p�j*/
  PM_KEY_P_MENU_SPECIAL,            /* Menu spcl  key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_MENU_SPECIAL2,           /* Menu spcl2 key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_MENU_SPECIAL3,           /* Menu spcl3 key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_MENU_SPECIAL4,           /* Menu spcl4 key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_MENU_SPECIAL5,           /* Menu spcl5 key �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_SPECIAL,                   /* Special key    �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_SPECIAL2,                  /* Special key2   �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_SPECIAL3,                  /* Special key3   �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_SPECIAL4,                  /* Special key4   �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_SPECIAL5,                  /* Special key5   �i�b���f���^�o���f���Ƃ��ɓK�p�j*/
  PM_KEY_P_STOP,                    /* STOP key       �i�o���f���ɓK�p����邩�͖���j*/
  PM_KEY_P_STOP_INVALID             /* STOP key       �i�o���f���ɓK�p����邩�͖���j�X�g�b�v�L�[��t�s�̏�Ԃł̃X�g�b�v�L�[�����ʒm */
};

/* =================================================================================== *
 *      PDL�p�L�[�_�C�A���O ��`
 * =================================================================================== */
/*       */
#define	 PM_KDLGPDL_MAX_LINE   6    /* �ő�\���s���B�����Ŏw�肷�邱�ƁB*/
#define	 PM_KDLGPDL_MAX_BTN    2    /* �ő�\���{�^����                  */

/* =================================================================================== *
 *       PDL�p�L�[�_�C�A���O �\����
 * =================================================================================== */
typedef struct {
	unsigned short		exist;		/* �{�^���\�� SET_DISP:�\��  RESET_DISP:��\�� */
	unsigned short		id;		/* �{�^���ɕ\�����镶����̕�����h�c �A���i0xFFF0�`0xFFFF�j�͎g�p�֎~*/
	unsigned int		code;		/* �{�^�����ڂ̕ԐM�R�[�h */
}Btn_Info_t;

typedef struct {
	char 			*filename;			/* ��o��������̂��镶����t�@�C�����B */
	void			(*pfunc);			/* �n���h�����O����֐��̃|�C���^ */
	unsigned short		str_id[PM_KDLGPDL_MAX_LINE];	/* �\�����镶����̕�����h�c */
	Btn_Info_t		btninfo[PM_KDLGPDL_MAX_BTN];	/* �{�^�����B�|�b�v�A�b�v��ʂɕ\�������{�^���������珇�ɐ������l - 1 ��Y���Ƃ���B*/
	unsigned char		time;				/* �_�C�A���O��\�����鎞�ԁi�b�j�B*/
}Key_Dialogue_PDL_t;


/* =================================================================================== *
 *        MENU DEFINITION
 * =================================================================================== */
/* ------------------------------------------------ *
 *    ���j���[�A�C�e���ݒ�p �}�N����`
 * ------------------------------------------------ */
#define   PM_MENU_NONE         0xFFFF
#define   PM_MSR_NONE          0xFFFE
#define   SET_MODIFY           1
#define   RESET_MODIFY         2
#define   SET_DISP             3
#define   HALF_DISP            4
#define   RESET_DISP           5
#define   SET_ACT              6
#define   RESET_ACT            7

/* ------------------------------------------------ *
 *    �ʒm���j���[�C�x���g �}�N����`
 * ------------------------------------------------ */
#define   PM_MENU_INIT0       0
#define   PM_MENU_INIT        1
#define   PM_MENU_COMPLETE0   2
#define   PM_MENU_COMPLETE1   3
#define   PM_MENU_END         4
#define   PM_MENU_EXIT0       7
#define   PM_MENU_EXIT        5
#define   PM_MENU_FIN         6
#define   PM_MENU_INIT2       7

/* ---------------------------------------------------
 *   MENU TYPE DEFINITION
 *   ����:����`�̔ԍ��͕ύX���Ȃ����ƁB
 * ------------------------------------------------- */
#define MENU_TYPE_TRAY     5                /* (05) �g���C�ݒ胁�j���[               : ��P��p��    */
#define MENU_TYPE_EMUSET   8                /* (08) �G�~�����[�V��������������j���[ : ��P�^C���p�� */
#define MENU_TYPE_PRN_NUM  9                /* (09) �G�~�����[�V��������������j���[ : ��P�^C���p�� */
#define MENU_TYPE_PCL     15                /* (15) PCL��������j���[                : ��P�^C���p�� */
//
// GPS�p XPDL���j���[�^�C�v��`
#define MENU_TYPE_XPDL1   91                /* (91) �g��PDL�ݒ胁�j���[              : ��P�^C���p�� */
#define MENU_TYPE_XPDL2   92                /* (92) �g��PDL�ݒ胁�j���[              : ��P�^C���p�� */
#define MENU_TYPE_XPDL3   93                /* (93) �g��PDL�ݒ胁�j���[              : ��P�^C���p�� */
#define MENU_TYPE_XPDL4   94                /* (94) �g��PDL�ݒ胁�j���[              : ��P�^C���p�� */
#define MENU_TYPE_XPDL5   95                /* (95) �g��PDL�ݒ胁�j���[              : ��P�^C���p�� */
//
// nGPS�p XPDL���j���[�^�C�v��`
// 1PDL�̃��j���[�^�C�v�ő勖�e�� �� �T��
// R_GROUP�pPDL        �ő勖�e�� �� �Q�O�� (interp.h�ɂ͂R�O�܂ŗ̈�m�ہj
// OTHERS �pPDL        �ő勖�e�� �� �Q�O�� (interp.h�ɂ͂R�O�܂ŗ̈�m�ہj
// 
#include "interp.h"
#ifndef GPS_PDL_RGROUP
#define GPS_PDL_RGROUP 40
#endif
#ifndef GPS_PDL_OTHERS
#define GPS_PDL_OTHERS 70
#endif
//  (51)�`(150)
#define MENU_TYPE_XPDL1_RGRP(n)   (51+((n-GPS_PDL_RGROUP)*5))      /* R_GROUP�p�g��PDL�ݒ胁�j���[ : ��P�^C���p�� */
#define MENU_TYPE_XPDL2_RGRP(n)   (52+((n-GPS_PDL_RGROUP)*5))      /* R_GROUP�p�g��PDL�ݒ胁�j���[ : ��P�^C���p�� */
#define MENU_TYPE_XPDL3_RGRP(n)   (53+((n-GPS_PDL_RGROUP)*5))      /* R_GROUP�p�g��PDL�ݒ胁�j���[ : ��P�^C���p�� */
#define MENU_TYPE_XPDL4_RGRP(n)   (54+((n-GPS_PDL_RGROUP)*5))      /* R_GROUP�p�g��PDL�ݒ胁�j���[ : ��P�^C���p�� */
#define MENU_TYPE_XPDL5_RGRP(n)   (55+((n-GPS_PDL_RGROUP)*5))      /* R_GROUP�p�g��PDL�ݒ胁�j���[ : ��P�^C���p�� */
// (151)�`(250)
#define MENU_TYPE_XPDL1_OTHR(n)   (151+((n-GPS_PDL_OTHERS)*5))     /* ��R�җp�g��PDL�ݒ胁�j���[  : ��P�^C���p�� */
#define MENU_TYPE_XPDL2_OTHR(n)   (152+((n-GPS_PDL_OTHERS)*5))     /* ��R�җp�g��PDL�ݒ胁�j���[  : ��P�^C���p�� */
#define MENU_TYPE_XPDL3_OTHR(n)   (153+((n-GPS_PDL_OTHERS)*5))     /* ��R�җp�g��PDL�ݒ胁�j���[  : ��P�^C���p�� */
#define MENU_TYPE_XPDL4_OTHR(n)   (154+((n-GPS_PDL_OTHERS)*5))     /* ��R�җp�g��PDL�ݒ胁�j���[  : ��P�^C���p�� */
#define MENU_TYPE_XPDL5_OTHR(n)   (155+((n-GPS_PDL_OTHERS)*5))     /* ��R�җp�g��PDL�ݒ胁�j���[  : ��P�^C���p�� */

/* ---------------------------------------------------
 *   ITEM TYPE DEFINITION
 *   ����:����`�̔ԍ��͕ύX���Ȃ����ƁB
 * ------------------------------------------------- */
#define   ITEM_TYPE_START        0          /* (00) ���[�g�\���̃A�C�e���^�C�v���ʎq                 */
#define   ITEM_TYPE_MENU         1          /* (01) ���j���[�^��ʗp�A�C�e���^�C�v���ʎq             */
#define   ITEM_TYPE_EXECUTING    3          /* (03) ���s�^��ʗp�A�C�e���^�C�v���ʎq                 */
#define   ITEM_TYPE_SELECT       2          /* (02) �I�����^��ʗp�A�C�e���^�C�v���ʎq               */
#define   ITEM_TYPE_INTEGER      5          /* (05) �����l�^��ʗp�A�C�e���^�C�v���ʎq               */
#define   ITEM_TYPE_FLOAT        6          /* (06) �����l�^��ʗp�A�C�e���^�C�v���ʎq               */
#define   ITEM_TYPE_PRN_NUM      8          /* (08) ���������ʗp�A�C�e���^�C�v���ʎq               */
#define   ITEM_TYPE_PTIME       14          /* (14) �p���ϔ{���^�C�v���ʎq                           */
#define   ITEM_TYPE_ANY         15          /* (15) �C�ӃA�C�e���^�C�v���ʎq                         */
#define   ITEM_TYPE_FLOAT_EXT   16          /* (16) �����l���g�������^�A�C�e���^�C�v���ʎq           */
#define   ITEM_TYPE_PTIME_FLT   20          /* (20) �����^�p���ϔ{���^�C�v���ʎq                     */


/* =================================================================================== *
 *       ���j���[�A�C�e���\����
 * =================================================================================== */
/* ---------------------------------------------------
 *   ITEM_TYPE_START : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		                      /* �A�C�e�����g�̃p�l���h�c 	*/
        unsigned short idDown;		                      /* ���K�w�̃p�l���h�c 		*/
					                      /* �g���b�v�p�֐��|�C���^ 	*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
        unsigned char  filename[FILENAME_LEN];                /* �t�@�C���l�[�� 		*/
	unsigned char  panel_lock_stat;        		      /* �p�l�����b�N��ԏ�� 		*/       
	unsigned char  ucReserved[3];                         /* ���g�p 			*/
        unsigned char  reserve_cid[4];                        /* �N���C�A���g�h�c�p�\��̈� 	*/
	unsigned char  ucItem;           		      /* �A�C�e���^�C�v 		*/
        unsigned char  ucMenu;                                /* ���j���[�^�C�v        		*/
} Menu_Type_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_MENU : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		      	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idNext;		       	/* ���K�w�̎��̃p�l���h�c 		*/
	unsigned short idPrev;		       	/* ���K�w�̑O�̃p�l���h�c 		*/
	unsigned short idDown;		       	/* ���K�w�̃p�l���h�c 			*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	unsigned short str2_id;		       	/* ���ڕ��i�Q�s�ځj�̕�����h�c 	*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  disp_flg;	       	/* �\���^���P�x�^��\���̃t���O 	*/
	unsigned char  ucReserved[5];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Menu_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_SELECT : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idNext;		       	/* ���K�w�̎��̃p�l���h�c 		*/
	unsigned short idPrev;		       	/* ���K�w�̑O�̃p�l���h�c 		*/
	unsigned short idDown;		       	/* ���K�w�̃p�l���h�c 			*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C����� */
	unsigned short str2_id;		       	/* ���ڕ��i�Q�s�ځj�̕�����h�c 	*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  up_num;         	       	/* ���s��ɑJ�ڂ����ւ̊K�w�� 	*/
	unsigned char  disp_flg;	       	/* �\���^���P�x�^��\���̃t���O 	*/
	unsigned char  fselect;		       	/* �I���^��I���̃t���O 		*/
	unsigned char  disp_fselect;		/* �I���t���O�̕\���^��\���̃t���O	*/
	unsigned char  ucReserved[2];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Select_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_INTEGER : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	short          sMax;		       	/* �ő�l 				*/
	short          sMin;		       	/* �ŏ��l 				*/
	unsigned short step;		       	/* �ω��� 				*/
	short          value;		       	/* �ݒ�l 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;		       	/* �P�ʕ�����h�c 	                */
	unsigned char  up_num;         	       	/* ���s��ɑJ�ڂ����ւ̊K�w�� 	*/
	unsigned char  fig_num;		       	/* �\������      	                */
	unsigned char  ucReserved[2];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Integer_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_FLOAT : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	short          sMax;		       	/* �ő�l 				*/
	short          sMin;		       	/* �ŏ��l 				*/
	unsigned short step;		       	/* �ω��� 				*/
	short          value;		       	/* �ݒ�l 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;		       	/* �P�ʕ�����h�c 	                */
	unsigned char  up_num;         	       	/* ���s��ɑJ�ڂ����ւ̊K�w�� 	*/
	unsigned char  fig_num;		       	/* �\������      	                */
	unsigned char  ucMulti; 	       	/* �w���l 				*/
        unsigned char  ucReserved;          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Float_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_PRN_NUM : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	short          sMax;		       	/* �ő�l				*/
	short          sMin;		       	/* �ŏ��l 				*/
	unsigned short step;		       	/* �ω��� 				*/
	short          value;		       	/* �ݒ�l 				*/
	unsigned short usReserved[2];          	/* ���g�p 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  ucReserved[6];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_PrnNum_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_PTIME : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	short          sMax;		       	/* �ő�l 				*/
	short          sMin;		       	/* �ŏ��l 				*/
	unsigned short step;		       	/* �ω��� 				*/
	short          value;		       	/* �ݒ�l 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;		       	/* �P�ʕ�����h�c 	                */
	unsigned char  up_num;         	       	/* ���s��ɑJ�ڂ����ւ̊K�w�� 	*/
	unsigned char  fig_num;		       	/* �\������      	                */
	unsigned char  ucReserved[2];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Ptime_t;

/* ---------------------------------------------------
 *   ITEM_TYPE_FLOAT_EXT : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	short          sMin;		       	/* �ŏ��l 				*/
	int            sMax;		       	/* �ő�l 				*/
	int            value;		       	/* �ݒ�l 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;		       	/* �P�ʕ�����h�c 	                */
	unsigned char  str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	unsigned char  step;		       	/* �ω��� 				*/
	unsigned char  fig_num;		       	/* �\������      	                */
	unsigned char  ucMulti; 	       	/* �w���l 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_FloatExt_t;


/* ---------------------------------------------------
 *   ITEM_TYPE_EXECUTING : (32byte) ��P�^C���p��
 * ------------------------------------------------- */
typedef  struct {
	unsigned short idPanel;		       	/* �A�C�e�����g�̃p�l���h�c 		*/
	unsigned short idBack;		       	/* �ďo���� ��ʊK�w�̃p�l���h�c	*/
	unsigned short str1_id;		       	/* �^�C�g�����i�P�s�ځj�̕�����h�c 	*/
	unsigned short str1_mod;	       	/* �^�C�g�����i�P�s�ځj�̕�����C�����	*/
	unsigned short str2_id;		       	/* ���ڕ��i�Q�s�ځj�̕�����h�c 	*/
	unsigned short usReserved[3];          	/* ���g�p 				*/
					   	/* �g���b�v�p�֐��|�C���^ 		*/
	void	       (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  up_num;         	       	/* ���s��ɑJ�ڂ����ւ̊K�w�� 	*/
        unsigned char  confirm;                 /* �m�F��ʃt���O                       */
	unsigned char  ucReserved[4];          	/* ���g�p 				*/
        unsigned char  reserve_cid[4];         	/* �N���C�A���g�h�c�ۑ��p�\��̈� 	*/
	unsigned char  ucItem;		       	/* �A�C�e���^�C�v 			*/
        unsigned char  ucMenu;                 	/* ���j���[�^�C�v        		*/
} Item_Type_Executing_t;

#endif  /* ! __GPS_PM_INFORMATION_H_ */

/*- EOF -*/
