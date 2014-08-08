/************************************************************************
 * �t�@�C����   : pageprint.h
 * �@�\�T�v     : GPS - ����y�[�W�Ǘ�
 * �����       : Copyright (C) RICOH CO., LTD. 1999-2001.
 * �݌v��       : T.Kitazawa
 * �ύX����     : 1999-09-27 �J�n
 *                2002-09-12 Version 1.143 std / 2.35 kipw / 4.41 jupw / 8.43 urpw / 9.20 jcfw / 11.44 kip2w / 12.13 urcw / 13.03 kai3
 *		  2000-07-24 Version 1.34 (Miyazaki)
 ************************************************************************/
/*      */
#ifndef _PAGEPRINT_H
#define _PAGEPRINT_H
#ifdef  __cplusplus
extern "C" {
#endif  /* !__cplusplus */
/*      */
/************************************************************************
 *      Parameter Value Definition
 ************************************************************************/
/*      */
#define GPS_PLOT_NORMAL         (0)     /* �ʏ����A  �t�@�C���폜 */
#define GPS_PLOT_REPLOT         (1)     /* ���v���b�g�A�t�@�C���ۑ��A���̃t�@�C���쐬�Ńt�@�C���폜 */
#define GPS_PLOT_PROOF          (2)     /* �P������A  �t�@�C���ۑ��A�c�������A�t�@�C���폜 */
#define GPS_PLOT_SECURE         (3)     /* ��������A  �t�@�C���ۑ��A�@�@�����A�t�@�C���폜 */
#define GPS_PLOT_STORED         (4)     /* ��������A  �t�@�C���ۑ��A�@�@�������t�@�C���ۑ� */
#define GPS_PLOT_PAUSE          (5)     /* �ۗ�����~�� */
#define GPS_PLOT_KEEP           (6)     /* �ۑ�����~�� */
#define GPS_PLOT_FORM           (7)     /* �t�H�[���o�^ */
/* OPTION�w�� */
#define GPS_PLOT_OPT_MICR       (0x100) /* OPTION�w��FMICR��� */
/*      */
#define GPS_REPLOT_BIT          (0x80)  /* ���v���b�g�w��r�b�g */
/*      */
#define GPS_PRINT_NORMAL        (0)
#define GPS_PRINT_FORCE         (1)
/*      */
#define GPS_COLOR_K             (0)
#define GPS_COLOR_C             (1)
#define GPS_COLOR_M             (2)
#define GPS_COLOR_Y             (3)
/*      */
#define GPS_PAGE_SUCCESS        (0)
#define GPS_PAGE_BUSY           (-1)
#define GPS_PAGE_FAILURE        (-2)
/*      */
#define GPS_BAND_SUCCESS        (1)
#define GPS_BAND_BUSY           (-1)
#define GPS_BAND_FAIL           (-2)
/*      */
#define GPS_BAND_NO_DRAW        (0)
#define GPS_BAND_DRAW           (1)
#define GPS_BAND_DRAW_CONTINUE  (3)
/*      */
#define GPS_TRAY_FOUND          (0)
#define GPS_TRAY_ERRSKIP        (1)
#define GPS_TRAY_CANCEL         (2)
#define GPS_TRAY_FORCE          (3)
#define GPS_TRAY_ANOTHER        (4)
/*      */
#define	GPS_PAGE_CHAP_OFF		(0)		/* �Ȃ� */
#define	GPS_PAGE_CHAP_BLANK		(1)		/* �͋�؂�F������Ȃ� */
#define	GPS_PAGE_CHAP_COPY		(2)		/* �͋�؂�F������� */
#define	GPS_PAGE_CHAP_DIVIDE	(3)		/* �͕��� */
#define	GPS_PAGE_CHAP_SPECIAL	(4)		/* ����p�� */

#define	GPS_PAGE_CHAP_SHEET1	(1)		/* ��؂�p���P */
#define	GPS_PAGE_CHAP_SHEET2	(2)		/* ��؂�p���Q */
#define	GPS_PAGE_CHAP_SHEET3	(3)		/* ��؂�p���R */
#define	GPS_PAGE_CHAP_SHEET4	(4)		/* ��؂�p���S */
#define	GPS_PAGE_CHAP_SHEET5	(5)		/* ��؂�p���T */
#define	GPS_PAGE_CHAP_SHEET6	(6)		/* ��؂�p���U */
#define	GPS_PAGE_CHAP_SHEET7	(7)		/* ��؂�p���V */
#define	GPS_PAGE_CHAP_SHEET8	(8)		/* ��؂�p���W */
#define	GPS_PAGE_CHAP_SHEET9	(9)		/* ��؂�p���X */
/*      */
/************************************************************************
 *      Structure Type Definition
 ************************************************************************/
/*      */
typedef struct gps_pageparam
{
    unsigned long       flag;           /* �ݒ肷��p�����[�^ */
/*#define GPS_PARAM_GET           (1 <<  0)*/
#define GPS_PARAM_QTY           (1 <<  1)
#define GPS_PARAM_LIMITLESS_EXIT (1 << 2)
#define GPS_PARAM_OUTPUT_TRAY   (1 <<  3)
#define GPS_PARAM_OUTMODE       (1 <<  4)
#define GPS_PARAM_BINDING       (1 <<  5)
#define GPS_PARAM_MARGIN1V      (1 <<  6)
#define GPS_PARAM_MARGIN1H      (1 <<  7)
#define GPS_PARAM_MARGIN2V      (1 <<  8)
#define GPS_PARAM_MARGIN2H      (1 <<  9)
#define GPS_PARAM_COVER         (1 << 10)
#define GPS_PARAM_COVERPRINT    (1 << 11)
#define GPS_PARAM_SLIP          (1 << 12)
#define GPS_PARAM_SHIFTOFF      (1 << 13)
#define GPS_PARAM_FINISH        (1 << 14)
#define GPS_PARAM_STAPLE        (1 << 15)
#define GPS_PARAM_PUNCH         (1 << 16)
#define GPS_PARAM_COVERTRAY     (1 << 17)
#define GPS_PARAM_SLIPTRAY      (1 << 18)
#define GPS_PARAM_MULTI_SIZE    (1 << 19)
#define GPS_PARAM_MULTI_WIDTH   (1 << 20)
#define GPS_PARAM_MULTI_LENGTH  (1 << 21)
#define GPS_PARAM_MULTI_TYPE    (1 << 22)
#define GPS_PARAM_TONERSAVE     (1 << 23)
#define GPS_PARAM_PRIORITY_TRAY (1 << 24)
#define GPS_PARAM_UPSIDEDOWN    (1 << 25)
#define GPS_PARAM_COLORCOUNT    (1 << 26)
#define GPS_PARAM_DOCBODYTRAY   (1 << 27)
#define GPS_PARAM_MIXEDDIRROT   (1 << 28)
#define GPS_PARAM_1STPAGEORDER  (1 << 29)
#define GPS_PARAM_JAMRECOVERY   (1 << 30)
#define GPS_PARAM_ACS           (1 << 31)
    unsigned short      qty;            /* ������� */
    unsigned char       limitless_exit; /* ���~�b�g���X�r���w�� */
#define GPS_LIMITLESS_OFF       (0x00)          /* ���~�b�g���X���Ȃ� */
#define GPS_LIMITLESS_EXIT      (0x10)          /* ���~�b�g���X�r������ */
/* �p�~�\�肱������ */
    unsigned char       input_tray;     /* �����g���C */
    unsigned char       paper_code;     /* �p���T�C�Y�E�R�[�h (paper.h �Q��) */
    unsigned short      xw;             /* �p����(0.1mm) (paper.h �Q��) */
    unsigned short      yw;             /* �p����(0.1mm) (paper.h �Q��) */
    unsigned char       paper_type;     /* ���� */
/* �p�~�\�肱���܂� */
    unsigned short      output_tray;    /* �r���g���C */
#define GPS_BIN_MAIN            (0x0000)        /* �{�̔r��(����/�}���`�r��) */
#define GPS_BIN_FINISHER        (0x0100)        /* �t�B�j�b�V�� */
#define GPS_BIN_MAILBOX         (0x0200)        /* ���[���{�b�N�X */
#define GPS_BIN_MULTI           (0x0300)        /* �}���`�r��(CF�g���C) */
#define GPS_BIN_SUB_FINISHER    (0x0400)        /* �T�u�t�B�j�b�V�� */
#define GPS_BIN_MAIN_STD        (0x0000)        /* FD/�W���r�� */
#define GPS_BIN_MAIN_BIN1       (0x0001)        /* 1�r���r�� */
#define GPS_BIN_MAIN_EXTED      (0x0002)        /* �g��(�X�g���[�g)�r�� */
#define GPS_BIN_FINI_PROOF      (0x0100)        /* �v���[�t�g���C */
#define GPS_BIN_FINI_SHIFT      (0x0101)        /* �V�t�g�g���C */
#define GPS_BIN_FINI_BOOKLET    (0x0105)        /* �u�b�N���b�g 0x102����0x105�֕ύX 2001.12.10 */
#define GPS_BIN_FOLD_STRAIGHT   (0x0106)        /* �܂�@:�X�g���[�g�r���g���C */
#define GPS_BIN_FOLD_BELLOWS    (0x0107)        /* �܂�@:�W���o���܂�r�o�g���C */
#define GPS_BIN_FOLD_BIN        (0x0108)        /* �܂�@:�P�������g���C */
#define GPS_BIN_MAILBOX1        (0x0201)        /* ���[���{�b�N�X�P */
#define GPS_BIN_MULTI_1         (0x0300)        /* �}���`�r���P */
#define GPS_BIN_MULTI_2         (0x0301)        /* �}���`�r���Q */
#define GPS_BIN_SUBFINI_RING    (0x040C)        /* �����O�o�C���_�r���g���C */
#define GPS_BIN_SUBFINI_PERF    (0x040F)        /* ����ݐ��{�@�r���g���C */
/* �p�~�\�肱������ */
#define GPS_BIN_MAIN_DPX        (0x0080)        /* ���ʃg���C */
#define GPS_BIN_FINI_SHIFT2     (0x0102)        /* �V�t�g�g���C�Q */
#define GPS_BIN_FINI_STAPLE     (0x0103)        /* �X�e�[�v���g���C */
#define GPS_BIN_FINI_STA_SAD    (0x0104)        /* �X�e�[�v���g���C (�T�h��) */
#define GPS_BIN_FINI_SADDLE     (0x0105)        /* �T�h���g���C */
/* �p�~�\�肱���܂� */
    unsigned char       outmode;        /* ������[�h */
#define GPS_OUT_IMGINFO         (0)             /* �摜�������̎w��ɏ]�� */
#define GPS_OUT_SINGLE          (1)             /* �Жʈ�� */
#define GPS_OUT_DUPLEX          (2)             /* ���ʈ�� */
    unsigned char       binding;        /* �c�Ƃ����� */
#define GPS_BIND_LEFT           (0)             /* ���Ԃ� */
#define GPS_BIND_TOP            (1)             /* ��Ԃ� */
#define GPS_BIND_RIGHT          (2)             /* �E�Ԃ� */
#define GPS_BIND_BOTTOM         (3)             /* ���Ԃ�(���g�p) */
#define GPS_BIND_LEFTRIGHT      (4)             /* ���E�Ԃ�(RTIFF) */
#define GPS_BIND_TOPBOTTOM      (5)             /* �㉺�Ԃ�(RTIFF) */
#define GPS_BIND_OFF            (0xF)           /* �w��Ȃ� �igpsPlotChkDirection() �̈����Ŏg�p�j */
/* �݊����ׂ̈Ɏc�� */
#define GPS_BIND_LR             (0)             /* ���E�Ԃ�(���ۂ͍�) */
#define GPS_BIND_TB             (1)             /* �㉺�Ԃ�(���ۂ͏�) */
    signed short        margin1v;       /* �c�Ƃ���(���ʎ��A��1�� 0.1mm) */
    signed short        margin1h;       /* ���Ƃ���(�@�@    �V �@ �@   ) */
    signed short        margin2v;       /* �c�Ƃ���(���ʑ�2�� 0.1mm) */
    signed short        margin2h;       /* ���Ƃ���(�@�@  �V �@    ) */
    unsigned char       cover;          /* �\�����[�h */
#define GPS_COVER_OFF           (0x00)          /* �\���ݒ肵�Ȃ� */
#define GPS_COVER_FRONT         (0x01)          /* �\�� */
/*#define GPS_COVER_BACK          (0x02)    */      /* ���\�� */
/*#define GPS_COVER_BOTH          (0x03)   */       /* �\���\�� */
    unsigned char       coverprint;     /* �\���摜����� */
#define GPS_COVER_FRONT_D       (0x11)          /* �\�� */
/*#define GPS_COVER_BACK_R        (0x22) */          /* ���\�� */
    unsigned char       cover_tray;     /* �\���g���C */
    unsigned char       slip;           /* �������[�h */
#define GPS_SLIP_OFF            (0x00)          /* OHP�������Ȃ� */
#define GPS_SLIP_ON             (0x01)          /* OHP�������� */
#define GPS_SLIP_PRINT          (0x11)          /* OHP�����Ɉ������ */
    unsigned char       slip_tray;      /* �����g���C */
    unsigned char       shiftoff;       /* �t�B�j�b�V���[�V�t�g�I�t */
#define GPS_SHIFT_ON            (0)             /* �V�t�g�I�� */
#define GPS_SHIFT_OFF           (1)             /* �V�t�g�I�t */
    unsigned char       finish;         /* �d�����w�� */
#define GPS_FINISH_OFF          (0)             /* �d�������Ȃ� */
#define GPS_SORT                (1)             /* �\�[�g */
#define GPS_STACK               (2)             /* �X�^�b�N */
#define GPS_ROT_SORT            (3)             /* ��]�\�[�g */
#define GPS_ROT_STACK           (4)             /* ��]�X�^�b�N */
    unsigned char       staple;         /* �X�e�[�v�� */
#define GPS_STAPLE_OFF              (0)
/*#define GPS_STAPLE_LEFT_TOP       (0) */         /* ���� */
#define GPS_STAPLE_LEFT_TOP_HORIZ   (1)         /* ���㐅�� */
#define GPS_STAPLE_LEFT_TOP_VERT    (2)         /* ���㐂�� */
#define GPS_STAPLE_LEFT_TOP_SLANT   (3)         /* ����΂� */
/*#define GPS_STAPLE_RIGHT_TOP      (4)   */      /* �E�� */
#define GPS_STAPLE_RIGHT_TOP_HORIZ  (5)         /* �E�㐅�� */
#define GPS_STAPLE_RIGHT_TOP_VERT   (6)         /* �E�㐂�� */
#define GPS_STAPLE_RIGHT_TOP_SLANT  (7)         /* �E��΂� */
/*#define GPS_STAPLE_DOUBLE         (8)   */        /* �E�� */
#define GPS_STAPLE_DOUBLE_LEFT      (9)         /* �����Q�� */
#define GPS_STAPLE_DOUBLE_TOP       (10)        /* �㑤�Q�� */
#define GPS_STAPLE_DOUBLE_RIGHT     (11)        /* �E���Q�� */
#define GPS_STAPLE_BOOKLET          (12)        /* �^���Q�� */
#define GPS_STAPLE_NONE             (15)        /* ��ł� */
#define GPS_STAPLE_LEFT_TOP         (16)        /* ���� */
#define GPS_STAPLE_RIGHT_TOP        (17)        /* �E�� */
#define GPS_STAPLE_CLEAR_BIT        (32)        /* �X�e�[�v������(GPS�����g�p) */
/* �p�~�\�肱������ */
#define GPS_STAPLE_TOP          (1)             /* ���@�@�@�@(��) */
#define GPS_STAPLE_TOP_SL       (2)             /* ���΂߁@�@(��) */
#define GPS_STAPLE_BOTTOM       (3)             /* ��O�@�@�@(��) */
#define GPS_STAPLE_BOTTOM_SL    (4)             /* ��O�΂߁@(��) */
#define GPS_STAPLE_BOTH         (5)             /* 2���@�@(����) */
#define GPS_STAPLE_SADDLE       (6)             /* �T�h�� */
/* �p�~�\�肱���܂� */
    unsigned char       punch;          /* �p���` */
#define GPS_PUNCH_OFF           (0)
#define GPS_PUNCH_LEFT          (1)             /* ���� */
#define GPS_PUNCH_TOP           (2)             /* ��� */
#define GPS_PUNCH_RIGHT         (3)             /* �E�� */
#define GPS_PUNCH_LEFT_TOP      (4)             /* ����i�P���p���`�p�j */
#define GPS_PUNCH_POS_BIT_MASK  (0x07)          /* �p���`�ʒu�w��r�b�g */
#define GPS_PUNCH_CLEAR_BIT     (0x08)          /* �p���`����(GPS�����g�p) */
#define GPS_PUNCH_TYPE_BIT_MASK (0xF0)          /* �p���`��ʎw��r�b�g */
#define GPS_PUNCH_JP2           (0x00)
#define GPS_PUNCH_US2           (0x10)
#define GPS_PUNCH_US3           (0x20)
#define GPS_PUNCH_EU4           (0x30)
#define GPS_PUNCH_NEU4          (0x40)
#define GPS_PUNCH_JP1           (0x50)
#define GPS_PUNCH_MULTI         (0x60)
/* �p�~�\�肱������ */
#define GPS_PUNCH_ON            (1)
/* �p�~�\�肱���܂� */
/* �p�~�\�肱������ */
    unsigned char       multi_size;     /* �}���`�g���C�̗p���T�C�Y�E�R�[�h (paper.h �Q��) */
    unsigned short      multi_width;    /* �}���`�g���C�̃t���[�T�C�Y���̗p����   (0.1mm�P��) */
    unsigned short      multi_length;   /* �}���`�g���C�̃t���[�T�C�Y���̗p������ (0.1mm�P��) */
    unsigned char       multi_type;     /* �}���`�g���C�̎��� */
/* �p�~�\�肱���܂� */
    unsigned char       tonersave;      /* �g�i�[�Z�[�u */
#define GPS_TONERSAVE_OFF       (0)             /* �g�i�[�Z�[�uOFF */
#define GPS_TONERSAVE_MODE1     (1)             /* �g�i�[�Z�[�u�E���[�h1 */
#define GPS_TONERSAVE_MODE2     (2)             /* �g�i�[�Z�[�u�E���[�h2 */
#define GPS_TONERSAVE_SOFT      (3)             /* �\�t�g�g�i�[�Z�[�u�����{���� */
    unsigned char       priority_tray;  /* �D�拋���g���C */
    unsigned char       upsidedown;     /* 180�x��] */
#define GPS_UPSIDE_UP           (0)             /* ��]���Ȃ� */
#define GPS_UPSIDE_DOWN         (1)             /* ��]���� */
    unsigned char       color_count;    /* �F�� */
#define GPS_COLOR_1             (1)             /* 1���F */
#define GPS_COLOR_RK            (2)             /* �ԍ� */
#define GPS_COLOR_CMYK          (4)             /* 4���F (CMYK) */
#define GPS_COLOR_XRGB          (5)             /* RGB[COSMOS] */
#define GPS_COLOR_2C            (6)             /* 2���F */
    unsigned char       docbody_tray;   /* �\�������̖{���g���C */
    unsigned char       mixeddirrot;    /* �p���������ݎ��̉�]���� */
#define GPS_MIXED_OFF           (0)
#define GPS_MIXED_LEFT          (1)
#define GPS_MIXED_RIGHT         (2)
    unsigned char       firstpageorder; /* �擪�y�[�W���� */
#define GPS_1STPAGEORDER_OFF    (0)
#define GPS_1STPAGEORDER_ON     (1)
    unsigned char       jamrecovery;    /* �W�����E���J�o�[ */
#define GPS_JAMRECOVERY_OFF     (0)
#define GPS_JAMRECOVERY_ON      (1)
    unsigned char       acs;            /* ACS */
#define GPS_ACS_OFF             (0)
#define GPS_ACS_ON              (1)

} gps_pageparam_t, *gps_pageparam_p;
/*      */
typedef struct gps_pagemode
{
    unsigned short      frame_width;    /* �t���[���̕�   (�h�b�g�P��) */
    unsigned short      frame_length;   /* �t���[���̍��� (�h�b�g�P��) */
    unsigned short      band_length;    /* �o���h�̍���   (�h�b�g�P��) */
    unsigned char       color_count;    /* �F�� */
/*#define GPS_COLOR_1             (1) */            /* 1���F */
/*#define GPS_COLOR_RK            (2)   */          /* �ԍ� */
/*#define GPS_COLOR_CMYK          (4)     */        /* 4���F (CMYK) */
    unsigned char       depth;          /* �ʎq���� (�K��) */
#define GPS_DEPTH_NONE          (0)             /* �摜�ȊO */
#define GPS_DEPTH_2             (1)             /* �Q�l */
#define GPS_DEPTH_4             (2)             /* �S�l */
#define GPS_DEPTH_MC            (3)             /* ���l (�P�����k����) */
#define GPS_DEPTH_M             (4)             /* ���l (���k�Ȃ�) */
#define GPS_DEPTH_16            (5)             /* �P�U�l */
#define GPS_DEPTH_256           (6)             /* �Q�T�U�l */
    unsigned char       skip_level;     /* �Ԉ������x�� */
#define GPS_SKIP_NONE           (0x00)          /* �Ԉ������Ȃ� */
#define GPS_SKIP_X              (0x01)          /* ���������Ԉ��� */
#define GPS_SKIP_Y              (0x02)          /* �呖�����Ԉ��� */
#define GPS_SKIP_XY             (0x03)          /* �啛�������Ԉ��� */
    unsigned char       rotate;         /* ��] */
#define GPS_ROT_0               (0)
#define GPS_ROT_90              (1)
#define GPS_ROT_180             (2)
#define GPS_ROT_270             (3)
    unsigned char       face;           /* ����� */
#define GPS_FACE_SINGLE         (0)             /* �Ж� */
#define GPS_FACE_DPX1ST         (1)             /* ���ʑ�P�� */
#define GPS_FACE_DPX2ND         (2)             /* ���ʑ�Q�� */
/* �p�~�\�肱������ */
    unsigned char       upsidedown;     /* 180�x��] */
/*#define GPS_UPSIDE_UP           (0)      */       /* ��]���Ȃ� */
/*#define GPS_UPSIDE_DOWN         (1)        */     /* ��]���� */
/* �p�~�\�肱���܂� */

                                        /* ���A�����W�}�g���N�X�p�^�[��ID */
                                        /* ID = 0 ���A�����WOFF */
    unsigned short      ra_id_k;                /* K plane */
    unsigned short      ra_id_c;                /* C plane */
    unsigned short      ra_id_m;                /* M plane */
    unsigned short      ra_id_y;                /* Y plane */
                                        /* �t���[���ƃ��A�����W�}�g���N�X�̃I�t�Z�b�g */
    unsigned char       ra_offx_k;              /* �呖������ K plane */
    unsigned char       ra_offy_k;              /* ���������� K plane */
    unsigned char       ra_offx_c;              /* �呖������ C plane */
    unsigned char       ra_offy_c;              /* ���������� C plane */
    unsigned char       ra_offx_m;              /* �呖������ M plane */
    unsigned char       ra_offy_m;              /* ���������� M plane */
    unsigned char       ra_offx_y;              /* �呖������ Y plane */
    unsigned char       ra_offy_y;              /* ���������� Y plane */

} gps_pagemode_t, *gps_pagemode_p;
/*      */
typedef struct gps_pageinfo
{
    unsigned char       paper_code;     /* �p���T�C�Y�E�R�[�h (paper.h �Q��) */
    unsigned short      paper_width;    /* �t���[�T�C�Y���̗p����   (0.1mm�P��) */
    unsigned short      paper_length;   /* �t���[�T�C�Y���̗p������ (0.1mm�P��) */
    unsigned short      frame_width;    /* �t���[���̕�   (�h�b�g�P��) */
    unsigned short      frame_length;   /* �t���[���̍��� (�h�b�g�P��) */
    unsigned short      band_length;    /* �o���h�̍���   (�h�b�g�P��) */
    unsigned long       line_size;      /* �����t���[���� (�o�C�g��) */
    unsigned long       xoffset;        /* ���������I�t�Z�b�g (�h�b�g�P��) */
    unsigned long       yoffset;        /* ���������I�t�Z�b�g (�h�b�g�P��) */
    unsigned short      resolution_x;   /* X�����𑜓x (25.4mm������̃h�b�g��) */
    unsigned short      resolution_y;   /* Y�����𑜓x (25.4mm������̃h�b�g��) */
    unsigned char       compress;       /* ���k */
#define GPS_COMP_NONE           (0)             /* ���k�Ȃ� */
#define GPS_COMP_K4             (4)
    unsigned char       color;          /* �g�p�J���[�i�v���[���j */
#define GPS_CB_K                (0x01)
#define GPS_CB_C                (0x02)
#define GPS_CB_M                (0x04)
#define GPS_CB_Y                (0x08)
    unsigned char       fci;            /* FCI */
#define GPS_FCI_OFF             (0)
#define GPS_FCI_ON              (1)
    unsigned char       input_tray;     /* �����g���C */
#define GPS_TRAY_MAN            (0)             /* �荷�������g���C */
#define GPS_TRAY_1              (1)             /* �{�̑�P�����g���C */
#define GPS_TRAY_2              (2)             /* �{�̑�Q�����g���C */
#define GPS_TRAY_3              (3)             /* �{�̑�R�����g���C */
#define GPS_TRAY_4              (4)             /* �{�̑�S�����g���C */
#define GPS_TRAY_5              (5)             /* �{�̑�T�����g���C */
#define GPS_TRAY_6              (6)             /* �{�̑�U�����g���C */
#define GPS_TRAY_7              (7)             /* �{�̑�V�����g���C */
#define GPS_TRAY_LCT            (0x0A)          /* ��ʋ����g���C */
#define GPS_TRAY_AUTO           (0x0F)          /* �����p���I�� */
#define GPS_TRAY_INSERTER       (0x10)          /* �����}�����j�b�g */
#define GPS_TRAY_INSERTER2      (0x11)          /* �����}�����j�b�g�i�Q�i�j*/
#define GPS_TRAY_PERF_INSERTER  (0x12)          /* ����݃C���T�[�^��i */
#define GPS_TRAY_PERF_INSERTER2 (0x13)          /* ����݃C���T�[�^���i */
    unsigned char       paper_type;     /* ���� */
#define GPS_PAPER_AUTO					(0x00)	/* ���ʎ��^�Đ��� */
#define GPS_PAPER_NORMAL				(0x01)	/* ���ʎ� */
#define GPS_PAPER_RECYCLE				(0x02)	/* �Đ��� */
#define GPS_PAPER_SPECIAL				(0x03)	/* ���ꎆ */
#define GPS_PAPER_TRACING				(0x04)	/* �g���[�V���O�� */
#define GPS_PAPER_OHP					(0x05)	/* OHP */
#define GPS_PAPER_LABEL					(0x06)	/* ���x���� */
#define GPS_PAPER_BOND					(0x07)	/* �{���h�� */
#define GPS_PAPER_CARDSTOCK				(0x08)	/* �J�[�h�X�g�b�N */
#define GPS_PAPER_CARDBOARD 			(0x09)	/* ���� */
#define GPS_PAPER_PREPRINT				(0x0A)	/* ����ςݎ� */
#define GPS_PAPER_LETTER_HEAD			(0x0B)	/* ���^�[�w�b�h�� */
#define GPS_PAPER_LTHEAD				(0x0B)	/* �p�~�\�� */
#define GPS_PAPER_PUNCH					(0x0C)	/* �p���`�ςݎ� */
#define GPS_PAPER_PREPUNCH				(0x0C)	/* �p�~�\�� */
#define GPS_PAPER_TAB					(0x0D)	/* �^�u�� */
#define GPS_PAPER_COLOR					(0x0E)	/* �F�� */
#define GPS_PAPER_NORMAL2ND				(0x0F)	/* ���ʎ�(����) */
#define GPS_PAPER_CARDBOARD2ND			(0x10)	/* ����(����) */
#define GPS_PAPER_THIN 					(0x11)	/* ���� */
#define GPS_PAPER_GLOSSY 				(0x12)	/* ���� */
#define GPS_PAPER_USED					(0x13)	/* �����i�g�p�ς݁j */
#define GPS_PAPER_POSTCARD				(0x14)	/* �n�K�L */
#define GPS_PAPER_POSTCARD2ND			(0x15)	/* �n�K�L(����) */
#define GPS_PAPER_CARDBOARD2			(0x16)	/* �����Q */
#define GPS_PAPER_FILM					(0x17)	/* �t�B�������i�}�ʃR�s�[�p�j */
#define GPS_PAPER_INKPOST				(0x18)	/* �C���N�W�F�b�g�p�͂��� */
#define GPS_PAPER_HG_NORMAL				(0x19)	/* HG���ʎ� */
#define GPS_PAPER_ENVELOPE				(0x1A)	/* ���� */
#define GPS_PAPER_CARDBOARD3			(0x1B)	/* �����R */
#define GPS_PAPER_SPECIAL2				(0x1C)	/* ���ꎆ�Q */
#define GPS_PAPER_SPECIAL3				(0x1D)	/* ���ꎆ�R */
#define GPS_PAPER_MIDDLETHICK			(0x1E)	/* ������ */
#define GPS_PAPER_COATED				(0x1F)	/* �R�[�g�� */
#define GPS_PAPER_CARDBOARD2REV			(0x20)	/* �����Q(����) */
#define GPS_PAPER_CARDBOARD3REV			(0x21)	/* �����R(����) */
#define GPS_PAPER_NORMAL2				(0x22)	/* ���ʎ��Q */
#define GPS_PAPER_THICKGLOSSY			(0x23)	/* ������� */
#define GPS_PAPER_SPECIAL4				(0x24)	/* ���ꎆ�S */
#define GPS_PAPER_SPECIAL5				(0x25)	/* ���ꎆ�T */
#define GPS_PAPER_SPECIAL6				(0x26)	/* ���ꎆ�U */

#define GPS_PAPER_USER_DEF1				(0x30)	/* ���[�U�w��P */
#define GPS_PAPER_USER_DEF2				(0x31)	/* ���[�U�w��Q */
#define GPS_PAPER_USER_DEF3				(0x32)	/* ���[�U�w��R */
#define GPS_PAPER_USER_DEF4				(0x33)	/* ���[�U�w��S */
#define GPS_PAPER_USER_DEF5				(0x34)	/* ���[�U�w��T */
#define GPS_PAPER_USER_DEF6				(0x35)	/* ���[�U�w��U */
#define GPS_PAPER_USER_DEF7				(0x36)	/* ���[�U�w��V */
#define GPS_PAPER_USER_DEF8				(0x37)	/* ���[�U�w��W */
#define GPS_PAPER_USER_DEF0				(0x38)	/* ���[�U�w��O(���o�^�J�X�^������) */

#define GPS_PAPER_COLOR1				(0x40)	/* �F���P	*/
#define GPS_PAPER_COLOR2				(0x41)	/* �F���Q	*/

#define GPS_PAPER_COLOR_WHITE			(0x50)	/* �g�p�s��(�W��) */
#define GPS_PAPER_COLOR_YELLOW			(0x51)	/* �� */
#define GPS_PAPER_COLOR_GREEN			(0x52)	/* �� */
#define GPS_PAPER_COLOR_BLUE			(0x53)	/* �� */
#define GPS_PAPER_COLOR_PURPLE			(0x54)	/* �� */
#define GPS_PAPER_COLOR_IVORY			(0x55)	/* �A�C�{���[ */
#define GPS_PAPER_COLOR_ORANGE			(0x56)	/* �� */
#define GPS_PAPER_COLOR_PINK			(0x57)	/* �� */
#define GPS_PAPER_COLOR_RED				(0x58)	/* �� */
#define GPS_PAPER_COLOR_GRAY			(0x59) 	/* �D */

#define GPS_PAPER_GLOSSY_COATED			(0x60)	/* �R�[�g��(�O���X) */
#define GPS_PAPER_THICK_GLOSSY_COATED	(0x61)	/* �R�[�g��(�O���X����) */
#define GPS_PAPER_MAT_COATED			(0x62)	/* �R�[�g��(�}�b�g) */
#define GPS_PAPER_THICK_MAT_COATED		(0x63)	/* �R�[�g��(�}�b�g����) */
#define GPS_PAPER_WATER_PROOF			(0x64)	/* �ϐ��� */
#define GPS_PAPER_CARDBOARD4			(0x65)	/* ����4  */
#define GPS_PAPER_CARDBOARD4REV			(0x66)	/* ����4���� */
#define GPS_PAPER_COATED_HIGH_GLOSSY	(0x67)	/* �R�[�g��(���O���X) */

#define GPS_PAPER_SEMIGLOSSY			(0x68)	/* �t�H�g���򎆁E������ */
#define GPS_PAPER_INKJETPLAIN			(0x69)	/* �C���N�W�F�b�g���ʎ� */
#define GPS_PAPER_MONO_TRACING			(0x6A)	/* �g���y(���m�N��) */
#define GPS_PAPER_COLOR_TRACING			(0x6B)	/* �g���y(�J���[) */
#define GPS_PAPER_MATFILM				(0x6C)	/* �}�b�g�t�B���� */
#define GPS_PAPER_CADCOATED				(0x6D)	/* �R�[�g��(CAD) */

#define GPS_PAPER_NONE					(0x80)	/* �g���C�ɐݒ肳��Ă��鎆��(����PDL���g���C�w�莞�̂ݎg�p��) */

#define	GPS_PAPER_USER_DEF9				(0x81)	/* ���[�U�w��X(IMSS) */
#define	GPS_PAPER_USER_DEF10			(0x82)	/* ���[�U�w��P�O(IMSS) */
#define	GPS_PAPER_USER_DEF11			(0x83)	/* ���[�U�w��P�P(IMSS) */
#define	GPS_PAPER_USER_DEF12			(0x84)	/* ���[�U�w��P�Q(IMSS) */
#define	GPS_PAPER_USER_DEF13			(0x85)	/* ���[�U�w��P�R(IMSS) */
#define	GPS_PAPER_USER_DEF14			(0x86)	/* ���[�U�w��P�S(IMSS) */
#define	GPS_PAPER_USER_DEF15			(0x87)	/* ���[�U�w��P�T(IMSS) */
#define	GPS_PAPER_USER_DEF16			(0x88)	/* ���[�U�w��P�U(IMSS) */
#define	GPS_PAPER_USER_DEF17			(0x89)	/* ���[�U�w��P�V(IMSS) */
#define	GPS_PAPER_USER_DEF18			(0x8A)	/* ���[�U�w��P�W(IMSS) */
#define	GPS_PAPER_USER_DEF19			(0x8B)	/* ���[�U�w��P�X(IMSS) */
#define	GPS_PAPER_USER_DEF20			(0x8C)	/* ���[�U�w��Q�O(IMSS) */
#define	GPS_PAPER_USER_DEF21			(0x8D)	/* ���[�U�w��Q�P(IMSS) */
#define	GPS_PAPER_USER_DEF22			(0x8E)	/* ���[�U�w��Q�Q(IMSS) */
#define	GPS_PAPER_USER_DEF23			(0x8F)	/* ���[�U�w��Q�R(IMSS) */
#define	GPS_PAPER_USER_DEF24			(0x90)	/* ���[�U�w��Q�S(IMSS) */
#define	GPS_PAPER_USER_DEF25			(0x91)	/* ���[�U�w��Q�T(IMSS) */
#define	GPS_PAPER_USER_DEF26			(0x92)	/* ���[�U�w��Q�U(IMSS) */
#define	GPS_PAPER_USER_DEF27			(0x93)	/* ���[�U�w��Q�V(IMSS) */
#define	GPS_PAPER_USER_DEF28			(0x94)	/* ���[�U�w��Q�W(IMSS) */
#define	GPS_PAPER_USER_DEF29			(0x95)	/* ���[�U�w��Q�X(IMSS) */
#define	GPS_PAPER_USER_DEF30			(0x96)	/* ���[�U�w��R�O(IMSS) */
#define	GPS_PAPER_USER_DEF31			(0x97)	/* ���[�U�w��R�P(IMSS) */
#define	GPS_PAPER_USER_DEF32			(0x98)	/* ���[�U�w��R�Q(IMSS) */
#define	GPS_PAPER_USER_DEF33			(0x99)	/* ���[�U�w��R�R(IMSS) */
#define	GPS_PAPER_USER_DEF34			(0x9A)	/* ���[�U�w��R�S(IMSS) */
#define	GPS_PAPER_USER_DEF35			(0x9B)	/* ���[�U�w��R�T(IMSS) */
#define	GPS_PAPER_USER_DEF36			(0x9C)	/* ���[�U�w��R�U(IMSS) */
#define	GPS_PAPER_USER_DEF37			(0x9D)	/* ���[�U�w��R�V(IMSS) */
#define	GPS_PAPER_USER_DEF38			(0x9E)	/* ���[�U�w��R�W(IMSS) */
#define	GPS_PAPER_USER_DEF39			(0x9F)	/* ���[�U�w��R�X(IMSS) */
#define	GPS_PAPER_USER_DEF40			(0xA0)	/* ���[�U�w��S�O(IMSS) */
#define	GPS_PAPER_USER_DEF41			(0xA1)	/* ���[�U�w��S�P(IMSS) */
#define	GPS_PAPER_USER_DEF42			(0xA2)	/* ���[�U�w��S�Q(IMSS) */
#define	GPS_PAPER_USER_DEF43			(0xA3)	/* ���[�U�w��S�R(IMSS) */
#define	GPS_PAPER_USER_DEF44			(0xA4)	/* ���[�U�w��S�S(IMSS) */
#define	GPS_PAPER_USER_DEF45			(0xA5)	/* ���[�U�w��S�T(IMSS) */
#define	GPS_PAPER_USER_DEF46			(0xA6)	/* ���[�U�w��S�U(IMSS) */
#define	GPS_PAPER_USER_DEF47			(0xA7)	/* ���[�U�w��S�V(IMSS) */
#define	GPS_PAPER_USER_DEF48			(0xA8)	/* ���[�U�w��S�W(IMSS) */
#define	GPS_PAPER_USER_DEF49			(0xA9)	/* ���[�U�w��S�X(IMSS) */
#define	GPS_PAPER_USER_DEF50			(0xAA)	/* ���[�U�w��T�O(IMSS) */
#define	GPS_PAPER_USER_DEF51			(0xAB)	/* ���[�U�w��T�P(IMSS) */
#define	GPS_PAPER_USER_DEF52			(0xAC)	/* ���[�U�w��T�Q(IMSS) */
#define	GPS_PAPER_USER_DEF53			(0xAD)	/* ���[�U�w��T�R(IMSS) */
#define	GPS_PAPER_USER_DEF54			(0xAE)	/* ���[�U�w��T�S(IMSS) */
#define	GPS_PAPER_USER_DEF55			(0xAF)	/* ���[�U�w��T�T(IMSS) */
#define	GPS_PAPER_USER_DEF56			(0xB0)	/* ���[�U�w��T�U(IMSS) */
#define	GPS_PAPER_USER_DEF57			(0xB1)	/* ���[�U�w��T�V(IMSS) */
#define	GPS_PAPER_USER_DEF58			(0xB2)	/* ���[�U�w��T�W(IMSS) */
#define	GPS_PAPER_USER_DEF59			(0xB3)	/* ���[�U�w��T�X(IMSS) */
#define	GPS_PAPER_USER_DEF60			(0xB4)	/* ���[�U�w��U�O(IMSS) */
#define	GPS_PAPER_USER_DEF61			(0xB5)	/* ���[�U�w��U�P(IMSS) */
#define	GPS_PAPER_USER_DEF62			(0xB6)	/* ���[�U�w��U�Q(IMSS) */
#define	GPS_PAPER_USER_DEF63			(0xB7)	/* ���[�U�w��U�R(IMSS) */
#define	GPS_PAPER_USER_DEF64			(0xB8)	/* ���[�U�w��U�S(IMSS) */
#define	GPS_PAPER_USER_DEF65			(0xB9)	/* ���[�U�w��U�T(IMSS) */
#define	GPS_PAPER_USER_DEF66			(0xBA)	/* ���[�U�w��U�U(IMSS) */
#define	GPS_PAPER_USER_DEF67			(0xBB)	/* ���[�U�w��U�V(IMSS) */
#define	GPS_PAPER_USER_DEF68			(0xBC)	/* ���[�U�w��U�W(IMSS) */
#define	GPS_PAPER_USER_DEF69			(0xBD)	/* ���[�U�w��U�X(IMSS) */
#define	GPS_PAPER_USER_DEF70			(0xBE)	/* ���[�U�w��V�O(IMSS) */
#define	GPS_PAPER_USER_DEF71			(0xBF)	/* ���[�U�w��V�P(IMSS) */
#define	GPS_PAPER_USER_DEF72			(0xC0)	/* ���[�U�w��V�Q(IMSS) */
#define	GPS_PAPER_USER_DEF73			(0xC1)	/* ���[�U�w��V�R(IMSS) */
#define	GPS_PAPER_USER_DEF74			(0xC2)	/* ���[�U�w��V�S(IMSS) */
#define	GPS_PAPER_USER_DEF75			(0xC3)	/* ���[�U�w��V�T(IMSS) */
#define	GPS_PAPER_USER_DEF76			(0xC4)	/* ���[�U�w��V�U(IMSS) */
#define	GPS_PAPER_USER_DEF77			(0xC5)	/* ���[�U�w��V�V(IMSS) */
#define	GPS_PAPER_USER_DEF78			(0xC6)	/* ���[�U�w��V�W(IMSS) */
#define	GPS_PAPER_USER_DEF79			(0xC7)	/* ���[�U�w��V�X(IMSS) */
#define	GPS_PAPER_USER_DEF80			(0xC8)	/* ���[�U�w��W�O(IMSS) */
#define	GPS_PAPER_USER_DEF81			(0xC9)	/* ���[�U�w��W�P(IMSS) */
#define	GPS_PAPER_USER_DEF82			(0xCA)	/* ���[�U�w��W�Q(IMSS) */
#define	GPS_PAPER_USER_DEF83			(0xCB)	/* ���[�U�w��W�R(IMSS) */
#define	GPS_PAPER_USER_DEF84			(0xCC)	/* ���[�U�w��W�S(IMSS) */
#define	GPS_PAPER_USER_DEF85			(0xCD)	/* ���[�U�w��W�T(IMSS) */
#define	GPS_PAPER_USER_DEF86			(0xCE)	/* ���[�U�w��W�U(IMSS) */
#define	GPS_PAPER_USER_DEF87			(0xCF)	/* ���[�U�w��W�V(IMSS) */
#define	GPS_PAPER_USER_DEF88			(0xD0)	/* ���[�U�w��W�W(IMSS) */
#define	GPS_PAPER_USER_DEF89			(0xD1)	/* ���[�U�w��W�X(IMSS) */
#define	GPS_PAPER_USER_DEF90			(0xD2)	/* ���[�U�w��X�O(IMSS) */
#define	GPS_PAPER_USER_DEF91			(0xD3)	/* ���[�U�w��X�P(IMSS) */
#define	GPS_PAPER_USER_DEF92			(0xD4)	/* ���[�U�w��X�Q(IMSS) */
#define	GPS_PAPER_USER_DEF93			(0xD5)	/* ���[�U�w��X�R(IMSS) */
#define	GPS_PAPER_USER_DEF94			(0xD6)	/* ���[�U�w��X�S(IMSS) */
#define	GPS_PAPER_USER_DEF95			(0xD7)	/* ���[�U�w��X�T(IMSS) */
#define	GPS_PAPER_USER_DEF96			(0xD8)	/* ���[�U�w��X�U(IMSS) */
#define	GPS_PAPER_USER_DEF97			(0xD9)	/* ���[�U�w��X�V(IMSS) */
#define	GPS_PAPER_USER_DEF98			(0xDA)	/* ���[�U�w��X�W(IMSS) */
#define	GPS_PAPER_USER_DEF99			(0xDB)	/* ���[�U�w��X�X(IMSS) */
#define	GPS_PAPER_USER_DEF100			(0xDC)	/* ���[�U�w��P�O�O(IMSS) */

/*#define GPS_PAPER_DEPEND      (0xFF)*/          /* �ݒ肳��Ă��鎆�� */
    unsigned char       limitless_feed; /* ���~�b�g���X���� */
#define GPS_LIMITLESS_OFF       (0x00)          /* ���~�b�g���X���Ȃ� */
#define GPS_LIMITLESS_FEED      (0x01)          /* ���~�b�g���X�������� */
    unsigned short      paper_count;    /* �o�͖��� */
    unsigned char       count_off;      /* �y�[�W�J�E���g */
#define GPS_COUNT_ON            (0)             /* �J�E���g���� */
#define GPS_COUNT_OFF           (1)             /* �J�E���g���Ȃ� */

} gps_pageinfo_t, *gps_pageinfo_p;
/*      */
/*
 * �����̒�`
 */
/* direction */
#define GPS_ROT_ERROR	(0)						/* �G���[ */
#define GPS_ROT_0B		(1<<GPS_ROT_0)			/* �O�x */
#define GPS_ROT_90B		(1<<GPS_ROT_90)			/* �X�O�x */
#define GPS_ROT_180B	(1<<GPS_ROT_180)		/* �P�W�O�x */
#define GPS_ROT_270B	(1<<GPS_ROT_270)		/* �Q�V�O�x */
#define GPS_ROT_ALL		(GPS_ROT_0B|GPS_ROT_90B|GPS_ROT_180B|GPS_ROT_270B)	/* ��]�����s�K�v */
#define GPS_ROT_NG		(0x80)					/* ��]�����s�� */


typedef struct gps_chkdirprm_tag
{
	unsigned long	flag;					/* �ݒ肷��p�����[�^ */
#define GPS_CHKDIR_STAPLE		(1<<0)
#define GPS_CHKDIR_PUNCH		(1<<1)
#define GPS_CHKDIR_BINDING		(1<<2)
#define GPS_CHKDIR_RESOLUTION	(1<<3)
#define GPS_CHKDIR_TRAY			(1<<4)
#define GPS_CHKDIR_DEPTH		(1<<5)
#define GPS_CHKDIR_DMY			(1<<31)

	int				psize;					/* �p���T�C�Y(�K�{) */
	unsigned short	pwidth;					/* �t���[�p����(0.1mm�P��) */
	unsigned short	plength;				/* �t���[�p����(0.1mm�P��) */

	unsigned char	orientation;			/* �I���G���e�[�V����(�K�{) */
#define GPS_ORIENTATION_PORTRAIT	(1<<0)
#define GPS_ORIENTATION_LANDSCAPE	(1<<1)

	unsigned char	staple;					/* �X�e�[�v��(flag�ɂĐݒ�) */
#ifdef notuse   /* See pageprint.h */
#define GPS_STAPLE_OFF				(0)		/* �Ȃ� */
#define GPS_STAPLE_LEFT_TOP_HORIZ	(1)		/* �g�p�͐������Ȃ� */
#define GPS_STAPLE_LEFT_TOP_VERT	(2)		/* �g�p�͐������Ȃ� */
#define GPS_STAPLE_LEFT_TOP_SLANT	(3)		/* ����΂� */
#define GPS_STAPLE_RIGHT_TOP_HORIZ	(5)		/* �g�p�͐������Ȃ� */
#define GPS_STAPLE_RIGHT_TOP_VERT	(6)		/* �g�p�͐������Ȃ� */
#define GPS_STAPLE_RIGHT_TOP_SLANT	(7)		/* �E��΂� */
#define GPS_STAPLE_DOUBLE_LEFT		(9)		/* �����Q�� */
#define GPS_STAPLE_DOUBLE_TOP		(10)	/* �㑤�Q�� */
#define GPS_STAPLE_DOUBLE_RIGHT		(11)	/* �E���Q�� */
#define GPS_STAPLE_BOOKLET			(12)	/* �^���Q�� */
#define GPS_STAPLE_LEFT_TOP			(16)	/* ���� */
#define GPS_STAPLE_RIGHT_TOP		(17)	/* �E�� */
#endif

	unsigned char	punch;					/* �p���`(flag�ɂĐݒ�) */
#ifdef notuse   /* See pageprint.h */
#define GPS_PUNCH_OFF		(0)				/* �Ȃ� */
#define GPS_PUNCH_LEFT		(1)				/* ���� */
#define GPS_PUNCH_TOP		(2)				/* ��� */
#define GPS_PUNCH_RIGHT		(3)				/* �E�� */
#define GPS_PUNCH_LEFT_TOP	(4)                             /* ����i�P���p���`�p�j */
#define GPS_PUNCH_JP2		(0x00)			/* ��ʂ̃p���`��ނ̎w��͂����Ă��Ȃ��Ă��ǂ� */
#define GPS_PUNCH_US2		(0x10)
#define GPS_PUNCH_US3		(0x20)
#define GPS_PUNCH_EU4		(0x30)
#define GPS_PUNCH_NEU4		(0x40)
#define GPS_PUNCH_JP1		(0x50)
#endif

	unsigned char	binding;				/* �Ƃ�����(flag�ɂĐݒ�) */
	/* �Жʂ̏ꍇ�ɂ� flag �𗧂ĂȂ����u�w��Ȃ��v���w�肷�邱�� */
#ifdef notuse   /* See pageprint.h */
#define GPS_BIND_LEFT			(0)			/* ���Ԃ� */
#define GPS_BIND_TOP			(1)			/* ��Ԃ� */
#define GPS_BIND_RIGHT			(2)			/* �E�Ԃ� */
#define GPS_BIND_BOTTOM			(3)			/* ���Ԃ�(���g�p) */
#define GPS_BIND_LEFTRIGHT		(4)			/* ���E�Ԃ�(RTIFF) */
#define GPS_BIND_TOPBOTTOM		(5)			/* �㉺�Ԃ�(RTIFF) */
#define GPS_BIND_OFF			(0xF)		/* �w��Ȃ�(gpsPlotChkDirection()�p) */
#endif

	unsigned char	dmy;					/* ���T�[�u */
	unsigned short	resX;					/* X �����̉𑜓x(flag�ɂĐݒ�, resY���ݒ肷�鎖) */
	unsigned short	resY;					/* Y �����̉𑜓x(1200dpi�̎���1200) */

	unsigned char	tray;					/* === ���k�Ȃ��g�p���鎖���ւ��� === �����g���C(flag�ɂĐݒ�, GPS_TRAY_MAN, GPS_TRAY_1 ... GPS_TRAY_AUTO) */

	unsigned char	depth;					/* �K��(flag�ɂĐݒ�) */
#ifdef notuse	/* See pageprint.h */
#define GPS_DEPTH_2				(1)			/* �Q�l(1bit) */
#define GPS_DEPTH_4				(2)			/* �S�l(2bit) */
#define GPS_DEPTH_16				(5)			/* �P�U�l(4bit) */
#define GPS_DEPTH_256				(6)			/* �Q�T�U�l(8bit) */
#endif

	unsigned char	rsv[6];					/* ���U�[�u */
} gps_chkdirprm_t, *gps_chkdirprm_p;

/*--------------------------------------------------------------------------------*/

/* --�Ԃ���-- */
typedef struct tgGpsMargin
{
	signed short		margin1v;		/* �c�Ƃ���(���ʎ��A��1�� 0.1mm�P��) */
	signed short		margin1h;		/* ���Ƃ���(�@�@    �V �@ �@   ) */
	signed short		margin2v;		/* �c�Ƃ���(���ʑ�2�� 0.1mm�P��) */
	signed short		margin2h;		/* ���Ƃ���(�@�@  �V �@    ) */
} gpsMargin;

/* --�\��-- */
typedef struct tgGpsCover
{
	unsigned char		mode;			/* ���[�h */
/*#define	GPS_COVER_OFF					(0x00)	*/	/* �\���n�e�e */
#define	GPS_FCOVER_ON					(0x01)		/* �����ĕ\���n�m */
#define	GPS_BCOVER_ON					(0x02)		/* ����\���n�m */

	unsigned char		front;			/* �����ĕ\�����[�h */
#define	GPS_COVER_BLANK					(0x00)		/* �\���Ɉ�����Ȃ� */
/*#define	GPS_COVER_FRONT					(0x01)*/		/* �\���ɕЖʈ������ */
/*#define	GPS_COVER_FRONT_D				(0x11)	*/	/* �\���ɗ��ʈ������ */

	unsigned char		back;			/* ����\�����[�h */
/*#define	GPS_COVER_BLANK					(0x00)	*/	/* ���\���Ɉ�����Ȃ� */
/*#define	GPS_COVER_BACK					(0x02)	*/	/* ���\���Ɉ������ */
/*#define	GPS_COVER_BACK_R				(0x22)	*/	/* ���\�����]�r�� */
													/* (�摜���Жʂ̏ꍇ�̂�) */

	unsigned char		fcover_tray;	/* �\���g���C */

	unsigned char		bcover_tray;	/* ���\���g���C */
} gpsCover;

/* --����-- */
typedef struct tgGpsSlip
{
	unsigned char		mode;			/* ���[�h */
	unsigned char		slip_tray;		/* �����g���C */
} gpsSlip;

/* --�d�؂莆-- */
typedef struct tgGpsPartition
{
	unsigned char		mode;			/* ���[�h */
/*#define	GPS_PARTITION_OFF				(0)		*/	/* �d�؎��Ȃ� */
/*#define	GPS_PARTITION_SORT				(1)		*/	/* ���P�� */
/*#define	GPS_PARTITION_JOB				(2)		*/	/* �W���u�P�� */

	unsigned short		cycle;			/* �����w��i���P�ʂ̏ꍇ�̂ݗL���j */
} gpsPartition;

/* --�p���`-- */
typedef struct tgGpsPunch
{
	unsigned char		pos;			/* �ʒu */
/*#define	GPS_PUNCH_OFF					(0)	*/	/* �Ȃ� */
/*#define	GPS_PUNCH_LEFT					(1)	*/	/* �� */
/*#define	GPS_PUNCH_TOP					(2)	*/	/* �� */
/*#define	GPS_PUNCH_RIGHT					(3)	*/	/* �E */
/*#define	GPS_PUNCH_LEFT_TOP				(4)	*/	/* ���� */

	unsigned char		unit;			/* ��� */
#define	GPS_PHOLE_JP2					(0)		/* ���{�Q�� */
#define	GPS_PHOLE_US2					(1)		/* �k�ĂQ�� */
#define	GPS_PHOLE_US3					(2)		/* �k�ĂR�� */
#define	GPS_PHOLE_EU4					(3)		/* ���B�S�� */
#define	GPS_PHOLE_NEU4					(4)		/* �k���S�� */
#define	GPS_PHOLE_JP1					(5)		/* ���{�P�� */
#define	GPS_PHOLE_MULTI					(6)		/* GBC�p���` */
} gpsPunch;

/* --�L���܂�-- */
typedef struct tgGpsW_Fold
{
	unsigned char		w_fold;			/* �܂��� */
/*#define	GPS_W_FOLD_OFF				(0)	*/	/* �܂�Ȃ� */
/*#define	GPS_W_FOLD_ZIGZAG				(1)*/		/* �W���o���܂� */
/*#define	GPS_W_FOLD_ZIGZAGFILE			(2)	*/	/* �W���o���t�@�C���܂� */
/*#define	GPS_W_FOLD_BASIC				(3)	*/	/* ��{�܂� */
/*#define	GPS_W_FOLD_BAG					(4)	*/	/* �ܐ܂� */
/*#define	GPS_W_FOLD_FILE					(5)	*/	/* �t�@�C���܂� */
/*#define	GPS_W_FOLD_CUSTOM1				(6)	*/	/* ����܂�P */
/*#define	GPS_W_FOLD_CUSTOM2				(7)	*/	/* ����܂�Q */
/*#define	GPS_W_FOLD_PROGRAM1				(8)	*/	/* �v���O�����܂�P */
/*#define	GPS_W_FOLD_PROGRAM2				(9)	*/	/* �v���O�����܂�Q */
/*#define	GPS_W_FOLD_PROGRAM3				(10)*/	/* �v���O�����܂�R */
/*#define	GPS_W_FOLD_PROGRAM4				(11)*/	/* �v���O�����܂�S */

	unsigned long		zigzag_width;	/* �W���o���܂�̐܂蕝(0.1mm�P��) */

	unsigned char		w_punch;		/* �܂�@�p���` */
/*#define	GPS_W_PUNCH_OFF					(0)	*/	/* �܂�@�p���`�Ȃ� */
/*#define	GPS_W_PUNCH_ON					(1)	*/	/* �܂�@�p���`���� */

	unsigned char		w_edgefold;		/* ���܂� */
/*#define	GPS_W_EDGEFOLD_OFF				(0)	*/	/* ���܂�Ȃ� */
/*#define	GPS_W_EDGEFOLD_ON				(1)	*/	/* ���܂肠�� */

	unsigned char		w_machinestamp;	/* ���J�X�^���v */
/*#define	GPS_W_MACHINE_STAMP_OFF	(0)	*/	/* �g�p���Ȃ� */
/*#define	GPS_W_MACHINE_STAMP_ON	(1)	*/	/* �g�p���� */

	unsigned char		reserve[64];	/* �@�\�ǉ��p */
} gpsW_Fold;

/* --�����O���{-- */
typedef struct tgGpsRingBind
{
	unsigned char		ring_bind;		/* �����O���{�ݒ� */
/*#define	GPS_RING_BIND_OFF				(0)	*/	/* �����O���{���Ȃ� */
#define	GPS_RING_BIND_ON				(1)		/* �����O���{���� */

	unsigned char		bind_pos;		/* �����O���{�Ԃ��ʒu */
/*#define	GPS_RING_BIND_LEFT				(1)	*/	/* ���Ԃ� */
/*#define	GPS_RING_BIND_TOP				(2)	*/	/* ��Ԃ� */
/*#define	GPS_RING_BIND_RIGHT				(3)	*/	/* �E�Ԃ� */

	unsigned char		bind_mode;		/* �����O���{���[�h�ݒ� */
#define	GPS_RING_BIND_MODE_PUNCH		(1)		/* �p���`�̂݃��[�h */
#define	GPS_RING_BIND_MODE_RING			(2)		/* �����O���{���[�h */

	unsigned char		reserve[5];		/* �@�\�ǉ��p */
} gpsRingBind;

/* --����ݐ��{-- */
typedef struct tgGpsPerfectBind
{
	unsigned char		perf_bind;				/* ����ݐ��{�ݒ� */
/*#define	GPS_PERF_BIND_OFF				(0)	*/		/* ����ݐ��{���Ȃ� */
#define	GPS_PERF_BIND_ON				(1)			/* ����ݐ��{���� */

	unsigned char		bind_pos;				/* ����ݐ��{�Ԃ��ʒu */
/*#define	GPS_PERF_BIND_LEFT				(1)	*/		/* ���Ԃ� */
/*#define	GPS_PERF_BIND_TOP				(2)	*/		/* ��Ԃ� */
/*#define	GPS_PERF_BIND_RIGHT				(3)	*/		/* �E�Ԃ� */

	unsigned char		perf_trim;				/* ����ݐ��{�ْf�ݒ� */
/*#define	GPS_PERF_TRIM_NONE				(0)	*/		/* �ْf�Ȃ� */
/*#define	GPS_PERF_TRIM_SINGLE			(1)	*/		/* �����J�b�g */
/*#define	GPS_PERF_TRIM_TRIPLE			(2)	*/		/* �O�ӃJ�b�g */

	unsigned char		trim_mode;				/* ����ݐ��{�ْf���[�h�ݒ� */
#define	GPS_PERF_TRIM_MODE_FINALSIZE	(1)			/* �d�オ��T�C�Y�w�� */
#define	GPS_PERF_TRIM_MODE_CUTSIZE		(2)			/* �J�b�g�͈͎w�� */

	unsigned char		perf_paper_code;		/* ����ݐ��{ �����T�C�Y�R�[�h(paper.h �Q��) */

	unsigned long		perf_paper_width;		/* ����ݐ��{ �t���[�T�C�Y���̒�����(�呖������)�@ (0.1mm�P��) */

	unsigned long		perf_paper_length;		/* ����ݐ��{ �t���[�T�C�Y���̒�������(����������) (0.1mm�P��) */

	unsigned char		perf_input_tray;		/* ����ݐ��{ ���������g���C */

	unsigned char		perf_cover_tray;		/* ����ݐ��{ �\���g���C */

	unsigned char		perf_cover_mode;		/* ����ݐ��{ �\�����[�h */
#define	GPS_PERF_COVER_BLANK			(0)	/* ����ݕ\���Ɉ�����Ȃ� */
#define	GPS_PERF_COVER_PRINT_INSIDE		(1)	/* ����ݕ\���ɕЖʓ���������� */
#define	GPS_PERF_COVER_PRINT_OUTSIDE	(2)	/* ����ݕ\���ɕЖʊO��������� */
#define	GPS_PERF_COVER_PRINT_DUPLEX		(3)	/* ����ݕ\���ɗ��ʈ������ */

	long				perf_cover_vert;		/* ����ݐ��{ �\���쑜�V�n(�呖��)�ʒu���� (0.1mm�P��) */

	long				perf_cover_hori;		/* ����ݐ��{ �\���쑜����(������)�ʒu���� (0.1mm�P��) */

	long				perf_image_vert;		/* ����ݐ��{ �쑜�V�n�ʒu���� (0.1mm�P��) */

	long				perf_image_hori;		/* ����ݐ��{ �쑜�����ʒu���� (0.1mm�P��) */

	unsigned char		perf_final_paper_code;	/* �d�オ��T�C�Y�w�莞 ���{�T�C�Y�R�[�h(paper.h �Q��) */

	unsigned long		perf_final_paper_width; 	/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{��(�呖������)�@ (0.1mm�P��) */

	unsigned long		perf_final_paper_length;	/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{����(����������) (0.1mm�P��) */

	long				perf_final_paper_vert;	/* �d�オ��T�C�Y�w�莞 �d�オ��T�C�Y�ʒu���� (0.1mm�P��) */

	unsigned long		perf_cut_paper_top;	 	/* �J�b�g�͈͎w�莞 �V�����@ (0.1mm�P��) */

	unsigned long		perf_cut_paper_bottom;	/* �J�b�g�͈͎w�莞 �n�����@ (0.1mm�P��) */

	unsigned long		perf_cut_paper_side;	/* �J�b�g�͈͎w�莞 �������� (0.1mm�P��) */

	unsigned char		reserve[32];			/* �@�\�ǉ��p */
} gpsPerfectBind;

/* --�}�[�L���O[COSMOS]-- */
typedef struct tgGpsMarking
{
	unsigned char		markingtype;				/* ���ߍ��ݎ�� */
#define	GPS_MARKING_OFF							(0)		/* ���ߍ��݂��Ȃ� */
#define	GPS_MARKING_COPYGUARD					(1)		/* �s���R�s�[�K�[�h */
#define	GPS_MARKING_SECURITY					(2)		/* �Z�L�����e�B�[�g���[�X */
#define	GPS_MARKING_FALSIFICATION				(3)		/* �����񌟒m */

	/* �s���R�s�[�K�[�h�d�w���ߍ��� */
	unsigned long		pattern_type;				/* �n���� */
#define	GPS_UCP_PATTERN_ON						(1<<0)		/* �}�~���� */
#define	GPS_COPYGUARD_ON						(1<<1)		/* �s���R�s�[�K�[�h */
#define	GPS_COPYGUARD_EX_ON						(1<<2)		/* �s���R�s�[�K�[�h�d�w */
#define	GPS_SECURUTY_TRACE_ON					(1<<3)		/* �Z�L�����e�B�g���[�X */
#define	GPS_PATTERN_AREA_FULL					(1<<4)		/* �n��̈�iON:�S�� OFF:�g�̂݁j */

	unsigned char		ucp_pattern_color;			/* �}�~�����̐F */
/*#define	GPS_COLOR_K								(0)	*/	/* �u���b�N */
/*#define	GPS_COLOR_C								(1)	*/	/* �V�A�� */
/*#define	GPS_COLOR_M								(2)	*/	/* �}�[���_ */

	unsigned char		ucp_pattern_density;			/* �}�~�����̔Z�x */

	unsigned char		ucp_fg_effect;			/* �}�~�����̌��ʁE�����F */
#define	GPS_UCP_FG_EFFECT_WHITE					(0)		/* �n�߂�������Ă��� */
#define	GPS_UCP_FG_EFFECT_VANISH				(1)		/* ������ */
#define	GPS_UCP_FG_EFFECT_REMAIN				(2)		/* �����Ȃ� */

	unsigned char		ucp_bg_effect;			/* �}�~�����̌��ʁE�w�i�F */
#define	GPS_UCP_BG_EFFECT_WHITE					(0)		/* �n�߂�������Ă��� */
#define	GPS_UCP_BG_EFFECT_VANISH				(1)		/* ������ */
#define	GPS_UCP_BG_EFFECT_REMAIN				(2)		/* �����Ȃ� */

	unsigned char		ucp_mask_type;			/* �}�~�����̖͗l */
#define	GPS_MASK_TYPE_NONE						(0)		/* �͗l�Ȃ� */
#define	GPS_MASK_TYPE_SEIGAIHA					(1)		/* �C�g */
#define	GPS_MASK_TYPE_AMIME						(2)		/* �Ԗ� */
#define	GPS_MASK_TYPE_KOUSHI1					(3)		/* �i�q�P */
#define	GPS_MASK_TYPE_KOUSHI2					(4)		/* �i�q�Q */
#define	GPS_MASK_TYPE_SHIPPOU					(5)		/* ���� */
#define	GPS_MASK_TYPE_SYOKKOU					(6)		/* 再] */
#define	GPS_MASK_TYPE_MATSUKAWABISHI			(7)		/* ����H */
#define	GPS_MASK_TYPE_UROKO						(8)		/* �� */
#define	GPS_MASK_TYPE_HIGAKI					(9)		/* �w�_ */
#define	GPS_MASK_TYPE_KIKKOU					(10)	/* �T�b */

	unsigned short	device_ctl_type;			/* �s���R�s�[�K�[�h�d�w�̋@�퐧��R�[�h */

	unsigned char		trace_info;				/* �Z�L�����e�B�[�g���[�X���`�� */
#define	GPS_CG_FORMAT_USERID					(0)		/* ���[�U�[�h�c */
#define	GPS_CG_FORMAT_PAPERID					(1)		/* ���h�c */

	/* �Z�L�����e�B�[�g���[�X���ߍ��� */
	unsigned char		embed_mode;				/* ���ߍ��݃��[�h */
#define	GPS_SE_MODE_IMAGEQUALITY				(0)		/* �掿�D�� */
#define	GPS_SE_MODE_NORMAL						(1)		/* ���� */
#define	GPS_SE_MODE_TOLERANCE					(2)		/* �ϐ��D�� */

	/* �����񌟒m���ߍ��� */
	unsigned char		pattern_density;			/* �n��Z�x */
#define	GPS_FA_DENSITY_LIGHT					(0)		/* ���� */
#define	GPS_FA_DENSITY_MIDDLE					(1)		/* ���� */
#define	GPS_FA_DENSITY_DARK						(2)		/* �Z�� */

	/* �n��t����� */
	unsigned char		pattern_status;				/* �n��t����� */
#define	GPS_FA_STATUS_NONE						(0)		/* �n��Ȃ� */
#define	GPS_FA_STATUS_ADDED						(1)		/* �n�䂠�� */

	unsigned short	errorcorrection_level;		/* ���������x�� */

	/* ���t���b�V���R�s�[ */
	unsigned char		refreshcopy;				/* ���ߍ��� */
#define	GPS_RF_MODE_OFF							(0)		/* OFF */
#define	GPS_RF_MODE_ON							(1)		/* ON */

	unsigned char		embedding_position;			/* ���ߍ��݈ʒu */
#define	GPS_RF_POS_RIGHTTOP						(0)		/* �E�� */
#define	GPS_RF_POS_LEFTTOP						(1)		/* ���� */
#define	GPS_RF_POS_RIGHTBOTTOM					(2)		/* �E�� */
#define	GPS_RF_POS_LEFTBOTTOM					(3)		/* ���� */

	unsigned long		embedding_pos_adj_vert;		/* ���ߍ��݈ʒu�����i�c�����j(0.1mm�P��) */

	unsigned long		embedding_pos_adj_horiz;	/* ���ߍ��݈ʒu�����i�������j(0.1mm�P��) */

	unsigned char		barcode_format;			/* �o�[�R�[�h�`�� */
#define	GPS_RF_FORMAT_QR						(0)		/* QR */
#define	GPS_RF_FORMAT_PDF417					(1)		/* PDF417 */
#define	GPS_RF_FORMAT_DATAMATRIX				(2)		/* DataMatrix */

	unsigned char		reserve[64];			/* �@�\�ǉ��p */
} gpsMarking;

/* --���@�\�܂�-- */
typedef struct tgGpsMultifold
{
	unsigned char		multifold_kind;				/* ���@�\�܂��� */
#define	GPS_MULTIFOLD_KIND_OFF					(0)		/* ���@�\�܂�Ȃ� */
#define	GPS_MULTIFOLD_KIND_HALF					(1)		/* �Q�܂�i���܂�j */
#define	GPS_MULTIFOLD_KIND_THIRDS_INSIDE		(2)		/* ���R�܂� */
#define	GPS_MULTIFOLD_KIND_THIRDS_OUTSIDE		(3)		/* �O�R�܂� */
#define	GPS_MULTIFOLD_KIND_QUART				(4)		/* �P���S�܂� */
#define	GPS_MULTIFOLD_KIND_GATE					(5)		/* �ω��܂� */

	unsigned char		multifold_printposition;	/* �󎚖� */
#define	GPS_MULTIFOLD_PRINTPOSITION_INSIDE		(0)		/* ������ */
#define	GPS_MULTIFOLD_PRINTPOSITION_OUTSIDE		(1)		/* �O���� */

	unsigned char		multifold_direction;		/* �J���i�܂�j���� */
#define	GPS_MULTIFOLD_DIRECTION_LEFT			(0)		/* ���J�� */
#define	GPS_MULTIFOLD_DIRECTION_BOTTOM			(1)		/* ���J�� */
#define	GPS_MULTIFOLD_DIRECTION_RIGHT			(2)		/* �E�J�� */
#define	GPS_MULTIFOLD_DIRECTION_TOP				(3)		/* ��J�� */

	unsigned char		multifold_sheets;			/* �d�ː܂� */
#define	GPS_MULTIFOLD_SHEETS_OFF				(0)		/* �d�ː܂肵�Ȃ� */
#define	GPS_MULTIFOLD_SHEETS_ON					(1)		/* �d�ː܂肷�� */

	unsigned char		reserve[16];				/* �@�\�ǉ��p */
} gpsMultifold;

/* --�g�����w��-- */
typedef struct tgGpsTrim
{
	unsigned char		trim_mode;		/* �g���}�[�ْ̍f����ݒ� */
#define	GPS_TRIM_OFF				(0)		/* �J�b�g�Ȃ� */
#define	GPS_TRIM_SINGLECUT			(1)		/* �����J�b�g */

	unsigned long		side_edge_cut;	/* �g���}�[�̃J�b�g�ʁ@���������ݒ�(0.1mm�P��) */

	unsigned char		reserve[16];	/* �@�\�ǉ��p */
} gpsTrim;

#define	GPS_MAX_PAGEPARAM_SHM	8

typedef struct gps_pageparam_shm
{
	unsigned long		support_flag[GPS_MAX_PAGEPARAM_SHM];	/* �T�|�[�g����p�����[�^ */

	unsigned long		flag[GPS_MAX_PAGEPARAM_SHM];			/* �ݒ肷��p�����[�^ */
/* byte:1 */
#define	GPS_PARAM_SHM_QTY 				(1 <<  0)
#define	GPS_PARAM_SHM_LIMITLESS_EXIT	(1 <<  1)
#define	GPS_PARAM_SHM_OUTPUT_TRAY		(1 <<  2)
#define	GPS_PARAM_SHM_OUTMODE			(1 <<  3)
#define	GPS_PARAM_SHM_BINDING			(1 <<  4)
#define	GPS_PARAM_SHM_MARGIN			(1 <<  5)
#define	GPS_PARAM_SHM_COVER				(1 <<  6)
#define	GPS_PARAM_SHM_SLIP				(1 <<  7)
#define	GPS_PARAM_SHM_PARTITION			(1 <<  8)
#define	GPS_PARAM_SHM_SHIFTOFF			(1 <<  9)
#define	GPS_PARAM_SHM_FINISH			(1 << 10)
#define	GPS_PARAM_SHM_STAPLE			(1 << 11)
#define	GPS_PARAM_SHM_PUNCH				(1 << 12)
#define	GPS_PARAM_SHM_Z_FOLD			(1 << 13)
#define	GPS_PARAM_SHM_W_FOLD			(1 << 14)
#define	GPS_PARAM_SHM_TONERSAVE			(1 << 15)
#define	GPS_PARAM_SHM_PRIORITY_TRAY		(1 << 16)
#define	GPS_PARAM_SHM_UPSIDEDOWN		(1 << 17)
#define	GPS_PARAM_SHM_COLOR				(1 << 18)
#define	GPS_PARAM_SHM_MIXEDDIRROT		(1 << 19)
#define	GPS_PARAM_SHM_JAMRECOVERY		(1 << 20)
#define	GPS_PARAM_SHM_ACS				(1 << 21)
#define	GPS_PARAM_SHM_STAMP				(1 << 22)
#define	GPS_PARAM_SHM_DUPLEXMODE		(1 << 23)
#define	GPS_PARAM_SHM_WHITESUPPRESS		(1 << 24)
#define	GPS_PARAM_SHM_COLORSEPARATE		(1 << 25)
#define	GPS_PARAM_SHM_RING				(1 << 26)
#define	GPS_PARAM_SHM_PERFECT			(1 << 27)
#define	GPS_PARAM_SHM_MARKING			(1 << 28)
#define	GPS_PARAM_SHM_MULTIFOLD			(1 << 29)
#define	GPS_PARAM_SHM_TRIM				(1 << 30)
#define	GPS_PARAM_SHM_FACEUP			(1 << 31)
/* byte:2 */
#define	GPS_PARAM_SHM_MAGAZINE			(1 <<  0)
#define	GPS_PARAM_SHM_PRTHEAD_DIRECTION	(1 <<  1)
#define	GPS_PARAM_SHM_SADDLE_FOLD		(1 <<  2)
/* byte:3 */
/* byte:4 */
/* byte:5 */
/* byte:6 */
/* byte:7 */
/* byte:8 */

	/* ----- �p�����[�^�P ----- */
	unsigned short		qty;				/* ������� */

	unsigned char		limitless_exit;		/* �V�[�P���V�����X�^�b�N */
/*#define	GPS_LIMITLESS_OFF				(0x00)	*/	/* �n�e�e */
/*#define	GPS_LIMITLESS_EXIT				(0x10)	*/	/* �n�m */

	unsigned short		output_tray;		/* �r���g���C */
/*#define	GPS_BIN_MAIN					(0x0000) */	/* �{�̔r��(����/�}���`�r��) */
/*#define	GPS_BIN_FINISHER				(0x0100) */	/* �t�B�j�b�V�� */
/*#define	GPS_BIN_MAILBOX					(0x0200)*/	/* ���[���{�b�N�X */
/*#define	GPS_BIN_MAIN_STD				(0x0000)*/	/* FD/�W���r�� */
/*#define	GPS_BIN_MAIN_BIN1				(0x0001)*/	/* 1�r���r�� */
/*#define	GPS_BIN_MAIN_EXTED				(0x0002)*/	/* �g��(�X�g���[�g)�r�� */
/*#define	GPS_BIN_FINI_PROOF				(0x0100)*/	/* �v���[�t�g���C */
/*#define	GPS_BIN_FINI_SHIFT				(0x0101)*/	/* �V�t�g�g���C */
/*#define	GPS_BIN_FINI_BOOKLET			(0x0105)*/	/* �u�b�N���b�g */
/*#define	GPS_BIN_MAILBOX1				(0x0201)*/	/* ���[���{�b�N�X�P */
/*#define	GPS_BIN_MULTI_1					(0x0300)*/	/* �}���`�r���P */
/*#define	GPS_BIN_MULTI_2					(0x0301)*/	/* �}���`�r���Q */
/*#define	GPS_BIN_SUBFINI_RING			(0x040C)*/	/* �����O�o�C���_�r���g���C */
/*#define	GPS_BIN_SUBFINI_PERF			(0x040F)*/	/* ����ݐ��{�@�r���g���C */

#define	GPS_BIN_STACKER_PROOF	(0x0400)				/* �X�^�b�J�[�v���[�t */
#define	GPS_BIN_STACKER			(0x0401)				/* �X�^�b�J�[�V�t�g�P */
#define	GPS_BIN_STACKER2		(0x0402)				/* �X�^�b�J�[�V�t�g�Q */
#define	GPS_BIN_RING_STACKER	GPS_BIN_SUBFINI_RING	/* �����O�o�C���_�r���g���C(08A�ł͂Ȃ�ׂ���������g�p���Ă�������) */
#define	GPS_BIN_LOADINGTRAY		GPS_BIN_SUBFINI_PERF	/* ����ݐ��{�@�r���g���C�@(08A�ł͂Ȃ�ׂ���������g�p���Ă�������) */
#define	GPS_BIN_FOLD_PROOF		(0x0411)				/* ���@�\�܂�v���[�t�g���C */

	unsigned char		outmode;			/* ������[�h */
/*#define	GPS_OUT_IMGINFO					(0)	*/	/* �摜�������̎w��ɏ]��*/
/*#define	GPS_OUT_SINGLE					(1)	*/	/* �Жʈ�� */
/*#define	GPS_OUT_DUPLEX					(2)	*/	/* ���ʈ�� */

	unsigned char		binding;			/* ���ʂƂ����� */
/*#define	GPS_BIND_LEFT					(0)	*/	/* ���Ԃ� */
/*#define	GPS_BIND_TOP					(1)	*/	/* ��Ԃ� */
/*#define	GPS_BIND_RIGHT					(2)	*/	/* �E�Ԃ� */
/*#define	GPS_BIND_LEFTRIGHT				(4)	*/	/* ���E�Ԃ� (RTIFF, PCL) */
/*#define	GPS_BIND_TOPBOTTOM				(5)*/		/* �㉺�Ԃ�(RTIFF, PCL) */

	gpsMargin			Margin;				/* �Ԃ��� */

	gpsCover			Cover;				/* �\�� */

	gpsSlip				Slip;				/* ���� */

	gpsPartition		Partition;			/* �d�؂莆 */

	unsigned char		shiftoff;			/* �W���u�P�ʂ̃V�t�g */
/*#define	GPS_SHIFT_ON					(0)	*/	/* �W���u�P�ʂɃV�t�g���� */
/*#define	GPS_SHIFT_OFF					(1)	*/	/* �V�t�g���Ȃ� */

	unsigned char		finish;				/* �d�����w�� */
/*#define	GPS_FINISH_OFF					(0) */		/* �d�������Ȃ� */
/*#define	GPS_SORT						(1)	*/	/* �\�[�g */
/*#define	GPS_STACK						(2)	*/	/* �X�^�b�N */
/*#define	GPS_ROT_SORT					(3)	*/	/* ��]�\�[�g */
#define	GPS_SHIFT_SORT					(4)		/* �V�t�g�\�[�g */

	unsigned char		staple;		/* �X�e�[�v�� */
/*#define	GPS_STAPLE_OFF					(0)	*/	/* �Ȃ� */
/*#define	GPS_STAPLE_LEFT_TOP_HORIZ		(1)	*/	/* ���㐅�� */
/*#define	GPS_STAPLE_LEFT_TOP_VERT		(2)	*/	/* ���㐂�� */
/*#define	GPS_STAPLE_LEFT_TOP_SLANT		(3)	*/	/* ����΂� */
/*#define	GPS_STAPLE_RIGHT_TOP_HORIZ		(5)	*/	/* �E�㐅�� */
/*#define	GPS_STAPLE_RIGHT_TOP_VERT		(6)	*/	/* �E�㐂�� */
/*#define	GPS_STAPLE_RIGHT_TOP_SLANT		(7)	*/	/* �E��΂� */
/*#define	GPS_STAPLE_DOUBLE_LEFT			(9)	*/	/* �����Q�� */
/*#define	GPS_STAPLE_DOUBLE_TOP			(10)*/	/* �㑤�Q�� */
/*#define	GPS_STAPLE_DOUBLE_RIGHT			(11)*/	/* �E���Q�� */
/*#define	GPS_STAPLE_BOOKLET				(12)*/	/* �^���Q�� */
/*#define	GPS_STAPLE_LEFT_TOP				(16)*/	/* ���� */
/*#define	GPS_STAPLE_RIGHT_TOP			(17)*/	/* �E�� */

	gpsPunch			Punch;		/* �p���` */

	/* --�y�܂�-- */
	unsigned char		z_fold;		/* �y�܂� */
/*#define	GPS_Z_FOLD_OFF					(0)	*/	/* �y�܂�Ȃ� */
/*#define	GPS_Z_FOLD_RIGHT				(1)	*/	/* �E�܂� */
/*#define	GPS_Z_FOLD_BOTTOM				(2)	*/	/* ���܂� */
/*#define	GPS_Z_FOLD_LEFT					(3)	*/	/* ���܂� */

	gpsW_Fold			w_fold;		/* �L���܂� */

	unsigned char		tonersave;		/* �g�i�[�Z�[�u */
/*#define	GPS_TONERSAVE_OFF				(0)	*/	/* �g�i�[�Z�[�uOFF */
/*#define	GPS_TONERSAVE_MODE1				(1)	*/	/* �g�i�[�Z�[�u�E���[�h1 */
/*#define	GPS_TONERSAVE_MODE2				(2)	*/	/* �g�i�[�Z�[�u�E���[�h2 */
/*#define	GPS_TONERSAVE_SOFT				(3)	*/	/* �\�t�g�g�i�[�Z�[�u */

	unsigned char		priority_tray;	/* �D�拋���g���C */

	unsigned char		upsidedown;		/* 180�x��] */
/*#define	GPS_UPSIDE_UP					(0) */		/* ��]���Ȃ� */
/*#define	GPS_UPSIDE_DOWN					(1)	*/	/* ��]���� */

	unsigned char		color_count;		/* �F�� */
#define	GPS_COLOR_1C				GPS_COLOR_1		/* 1���F */
/*#define	GPS_COLOR_RK					(2)	*/	/* �ԍ� */
/*#define	GPS_COLOR_CMYK					(4)	*/	/* 4���F */
/*#define	GPS_COLOR_XRGB					(5)	*/	/* RGB[COSMOS] */
/*#define	GPS_COLOR_2C					(6)	*/	/* 2���F */

	unsigned char		mixeddirrot;		/* �p���������ݎ��̉�]���� */
/*#define	GPS_MIXED_OFF					(0)	*/	/* GPS�d�l�ɏ]�� */
/*#define	GPS_MIXED_LEFT					(1)	*/	/* �� */
/*#define	GPS_MIXED_RIGHT					(2)*/		/* �E */

	unsigned char		jamrecovery;		/* �W�����E���J�o���[ */
/*#define	GPS_JAMRECOVERY_OFF				(0)	*/	/* ���J�o���[���Ȃ� */
/*#define	GPS_JAMRECOVERY_ON				(1)	*/	/* ���J�o���[���� */

	unsigned char		acs;			/* ACS */
/*#define	GPS_ACS_OFF						(0)	*/	/* ACS���Ȃ� */
/*#define	GPS_ACS_ON						(1)	*/	/* ACS���� */

	unsigned char		stamp;			/* �{�̃X�^���v���g�p���� */
/*#define	GPS_STAMP_OFF					(0)	*/	/* �g�p���Ȃ� */
/*#define	GPS_STAMP_ON					(1)*/		/* �g�p���� */

	unsigned char		duplexmode;		/* �h���C�o�[���痼�ʎw�� */
/*#define	GPS_DUPLEXMODE_OFF				(0)  */   	/* ���ʎw��Ȃ� */
/*#define	GPS_DUPLEXMODE_ON				(1)    */ 	/* ���ʎw�肠�� */

	unsigned char		white_suppress;	/* �����}��[COSMOS] */
#define	GPS_WHITE_SUPPRESS_OFF			(0)		/* OFF */
#define	GPS_WHITE_SUPPRESS_ON			(1)		/* ON */
#define	GPS_WHITE_SUPPRESS_SPACE		(2)		/* �X�y�[�X��� */

	unsigned char		color_separate;	/* �F����[COSMOS] */
#define	GPS_COLOR_SEPARATE_K			(1<<0)		/* �u���b�N */
#define	GPS_COLOR_SEPARATE_C			(1<<1)		/* �V�A�� */
#define	GPS_COLOR_SEPARATE_M			(1<<2)		/* �}�[���_ */
#define	GPS_COLOR_SEPARATE_Y			(1<<3)		/* �C�G���[ */

	gpsRingBind			Ringbind;		/* �����O���{ */

	gpsPerfectBind		Perfectbind;	/* ����ݐ��{ */

	gpsMarking			Marking;		/* �}�[�L���O[COSMOS] */

	gpsMultifold		Multifold;		/* ���@�\�܂� */

	gpsTrim				Trim;			/* �g���~���O�w�� */

	unsigned char		face_up;		/* �t�F�[�X�A�b�v�r���i�t�F�[�X�A�b�v�@�̂ݗL���j */
#define	GPS_FACEUP_OFF					(0)		/* �t�F�[�X�_�E���r�� */
#define	GPS_FACEUP_ON					(1)		/* �t�F�[�X�A�b�v�r�� */

/* ----- �p�����[�^�Q ----- */
	unsigned char		magazine;		/* �T�����Ԃ�(PS��p) */
#define	GPS_MAGAZINE_OFF				(0)		/* �T�����Ԃ��Ȃ� */
#define	GPS_MAGAZINE_RIGHT				(1)		/* �E�Ԃ� */
#define	GPS_MAGAZINE_LEFT				(2)		/* ���Ԃ� */
#define	GPS_MAGAZINE_UP					(3)		/* ��Ԃ� */
#define	GPS_MAGAZINE_DOWN				(4)		/* ���Ԃ� */

	unsigned char		prthead_direction;	/* �Е���/�o������� */
#define	GPS_PRTHEAD_AUTO				(0)		/* ���� */
#define	GPS_PRTHEAD_UNIDIRECTIONAL		(1)		/* �Е��� */

	unsigned char		saddle_fold;		/* ���܂�(���Ԃ��g���C) */
#define	GPS_SADDLE_FOLD_OFF				(0)		/* ���܂肵�Ȃ� */
#define	GPS_SADDLE_FOLD_INSIDE			(1)		/* ���܂� */
#define	GPS_SADDLE_FOLD_OUTSIDE			(2)		/* �O�܂� */
#define	GPS_SADDLE_FOLD_SHEETS			(3)		/* �d�ː܂� */

} gps_pageparam_shm_t, *gps_pageparam_shm_p;

/*      */

#ifdef  __cplusplus
}
#endif  /* !__cplusplus */
#endif  /* !_PAGEPRINT_H */
/* EOF  */
