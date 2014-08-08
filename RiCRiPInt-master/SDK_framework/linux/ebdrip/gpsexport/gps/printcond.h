/******************************************************
 * $Id$
 *
 * Copyright (C) 2010 Ricoh Company, Ltd.  All Rights Reserved.
 *
 *   FILE NAME       : printcond.h
 *   VERSION         : $Revision$
 *   AUTHOR          : Yusuke Nomura
 *-----------------------------------------------------
 *   HISTORY
 *	 30 Sep 2010: Created.
 *	 $Log$
 *	
 ******************************************************/
#ifndef _GPS_PRINTCOND_H_
#define	_GPS_PRINTCOND_H_


#include "sdkprintcond.h" /* �������(SDK) 12A�` */

/* PDL��������擾���� 12A�ȍ~���g�p */
#define GPS_PDLPRTCOND_OK_ALL     (3) /* ����(*cond�A*media���Ɉ�������ύX�L��) */
#define GPS_PDLPRTCOND_OK_MEDIA   (2) /* ����(*media�݈̂�������ύX�L��) */
#define GPS_PDLPRTCOND_OK_COND    (1) /* ����(*cond �݈̂�������ύX�L��) */
#define GPS_PDLPRTCOND_OK_NONE    (0) /* ����(*cond�A*media���Ɉ�������ύX����) */
#define GPS_PDLPRTCOND_NG_IDERR  (-1) /* ujobid�Ɏw�肵�����[�U�[�W���u�h�c���s�� */
#define GPS_PDLPRTCOND_NG_PRMERR (-2) /* �p�����[�^�G���[ */

/* PDF��p�p�����[�^�擾���� 12A�ȍ~���g�p */
#define GPS_PDFPRM_OK         (0) /* ���� */
#define GPS_PDFPRM_NG_IDERR  (-1) /* ujobid�Ɏw�肵�����[�U�[�W���u�h�c���s�� */
#define GPS_PDFPRM_NG_PRMERR (-2) /* �p�����[�^�G���[ */

#define GPS_PDF_PASSWORD_LEN (36)

/*
 * �������(PDL)
 */

/* �W���u�^�C�v�ݒ�l */
#define GPS_PCND_PDL_JOBTYPE_PRINT			(0)	/* �v�����^�W���u */
#define GPS_PCND_PDL_JOBTYPE_MEDIA			(1)	/* ���f�B�A�v�����g�W���u */
#define GPS_PCND_PDL_JOBTYPE_THUMBNAIL		(2)	/* �v���r���[�W���u(12A�`) */
#define GPS_PCND_PDL_JOBTYPE_SDK_PRINT		(3)	/* SDK�v�����g�W���u(12A�`) */
#define GPS_PCND_PDL_JOBTYPE_SDK_THUMBNAIL	(4)	/* SDK�v���r���[�W���u(12A�`) */

/* �p����ޕύX�L���ݒ�l */
#define GPS_PCND_PDL_CHG_PAPERKIND_EXIST (1<<0) /* �ύX�L�� */

/* ���ʈ���ݒ�l */
#define GPS_PCND_PDL_DUPLEX_OFF   (1<<0) /* �Ж� */
#define GPS_PCND_PDL_DUPLEX_LEFT  (1<<1) /* ���ʍ��J�� */
#define GPS_PCND_PDL_DUPLEX_TOP   (1<<3) /* ���ʏ�J�� */

/* �g�i�[�Z�[�u(�J���[)�ݒ�l */
#define GPS_PCND_PDL_TONERSAVE_COLOR_OFF (1<<0) /* OFF */
#define GPS_PCND_PDL_TONERSAVE_COLOR_ON  (1<<1) /* ON */

/* �W��ݒ�l */
#define GPS_PCND_PDL_NUP_OFF   (1<<0) /* �W�񖳂� */
#define GPS_PCND_PDL_NUP_2IN1  (1<<1) /* 2in1 */
#define GPS_PCND_PDL_NUP_4IN1  (1<<2) /* 4in1 */
#define GPS_PCND_PDL_NUP_6IN1  (1<<3) /* 6in1 */
#define GPS_PCND_PDL_NUP_8IN1  (1<<4) /* 8in1 */ /* �\��(�����̂���) */
#define GPS_PCND_PDL_NUP_9IN1  (1<<5) /* 9in1 */
#define GPS_PCND_PDL_NUP_16IN1 (1<<6) /* 16in1 */

/* �W��p�����[�^�ݒ�l */
#define GPS_PCND_PDL_NUPOPT_PAGEORDER_RIGHT_THEN_DOWN (1<<0) /* 2in1�ȊO:���と�E�と�������E�� 2in1:������E�� */
#define GPS_PCND_PDL_NUPOPT_PAGEORDER_LEFT_THEN_DOWN  (1<<1) /* 2in1�ȊO:�E�と���と�E�������� 2in1:�E���獶�� */
#define GPS_PCND_PDL_NUPOPT_PAGEORDER_DOWN_THEN_RIGHT (1<<2) /* 2in1�ȊO:���と�������E�と�E�� 2in1:���g�p */
#define GPS_PCND_PDL_NUPOPT_PAGEORDER_DOWN_THEN_LEFT  (1<<3) /* 2in1�ȊO:�E�と�E�������と���� 2in1:���g�p */

/* �W��d�؂�� */
#define GPS_PCND_PDL_NUP_BORDER_OFF (1<<0) /* ���� */
#define GPS_PCND_PDL_NUP_BORDER_ON  (1<<1) /* �L�� */

/* �J���[/�����ݒ�l */
#define GPS_PCND_PDL_COLORMODE_MONO  (1<<0) /* ���� */
#define GPS_PCND_PDL_COLORMODE_COLOR (1<<1) /* �J���[ */

/* �����g���C�I��ݒ�l 12A�ȍ~���g�p */
#define GPS_PCND_PDL_INPUTTRAY_AUTO (1<<0)  /* �����g���C */
#define GPS_PCND_PDL_INPUTTRAY_1    (1<<1)  /* �g���C1 */
#define GPS_PCND_PDL_INPUTTRAY_2    (1<<2)  /* �g���C2 */
#define GPS_PCND_PDL_INPUTTRAY_3    (1<<3)  /* �g���C3 */
#define GPS_PCND_PDL_INPUTTRAY_4    (1<<4)  /* �g���C4 */
#define GPS_PCND_PDL_INPUTTRAY_5    (1<<5)  /* �g���C5 */
#define GPS_PCND_PDL_INPUTTRAY_6    (1<<6)  /* �g���C6 */
#define GPS_PCND_PDL_INPUTTRAY_7    (1<<7)  /* �g���C7 */
#define GPS_PCND_PDL_INPUTTRAY_LCT  (1<<30) /* ��ʋ����g���C */
#define GPS_PCND_PDL_INPUTTRAY_MAN  (1<<31) /* �荷���g���C */

/* �X�e�[�v���ݒ�l 12A�ȍ~���g�p */
#define GPS_PCND_PDL_STAPLE_OFF           (1<<0) /* �X�e�[�v������ */
#define GPS_PCND_PDL_STAPLE_LEFTTOP       (1<<1) /* ���� */
#define GPS_PCND_PDL_STAPLE_RIGHTTOP      (1<<2) /* �E�� */
#define GPS_PCND_PDL_STAPLE_LEFTTOPSLANT  (1<<3) /* ����΂� */
#define GPS_PCND_PDL_STAPLE_RIGHTTOPSLANT (1<<4) /* �E��΂� */
#define GPS_PCND_PDL_STAPLE_LEFT2         (1<<5) /* ��2�� */
#define GPS_PCND_PDL_STAPLE_TOP2          (1<<6) /* ��2�� */
#define GPS_PCND_PDL_STAPLE_RIGHT2        (1<<7) /* �E2�� */
#define GPS_PCND_PDL_STAPLE_BOOKLET       (1<<8) /* ���Ԃ� */

/* �p���`�ݒ�l 12A�ȍ~���g�p */
#define GPS_PCND_PDL_PUNCH_OFF      (1<<0)  /* �p���`���� */
#define GPS_PCND_PDL_PUNCH_LEFT2    (1<<1)  /* ��2�� */
#define GPS_PCND_PDL_PUNCH_TOP2     (1<<2)  /* ��2�� */
#define GPS_PCND_PDL_PUNCH_RIGHT2   (1<<3)  /* �E2�� */
#define GPS_PCND_PDL_PUNCH_LEFT3    (1<<4)  /* ��3�� */
#define GPS_PCND_PDL_PUNCH_TOP3     (1<<5)  /* ��3�� */
#define GPS_PCND_PDL_PUNCH_RIGHT3   (1<<6)  /* �E3�� */
#define GPS_PCND_PDL_PUNCH_LEFT4    (1<<7)  /* ��4�� */
#define GPS_PCND_PDL_PUNCH_TOP4     (1<<8)  /* ��4�� */
#define GPS_PCND_PDL_PUNCH_RIGHT4   (1<<9)  /* �E4�� */
#define GPS_PCND_PDL_PUNCH_LEFTGBC  (1<<10) /* GBC�� */
#define GPS_PCND_PDL_PUNCH_TOPGBC   (1<<11) /* GBC�� */
#define GPS_PCND_PDL_PUNCH_RIGHTGBC (1<<12) /* GBC�E */
#define GPS_PCND_PDL_PUNCH_LEFTTOP  (1<<13) /* ����1�� */

typedef struct gps_pdl_printcondition {
	unsigned int  job_type;        /* �W���u�^�C�v */
	unsigned long chg_paper_kind;  /* �p����ޕύX�L�� */
	unsigned int  paper_kind;      /* �p����� */
	unsigned long duplex;          /* ���ʈ�� */
	unsigned long tonersave_color; /* �g�i�[�Z�[�u(�J���[) */
	unsigned long nup;             /* �W�� */
	unsigned long nup_option;      /* �W��p�����[�^ */
	unsigned long nup_border;      /* �W��d�؂�� */
	unsigned long colormode;       /* �J���[/���� */
	unsigned long inputtray;       /* �����g���C�I�� */
	unsigned long staple;          /* �X�e�[�v�� */
	unsigned long punch;           /* �p���` */
} gps_pdl_printcondition_t;


/*
 * �������(PDL2) 12A�`
 */

typedef struct gps_pdl_printcondition2{
	unsigned char pdfpassword[GPS_PDF_PASSWORD_LEN]; /* PDF�p�X���[�h������ */
	unsigned long reserve[16];                       /* �\��(�g���p) */
} gps_pdl_printcondition2_t;


/*
 * ���f�B�A�v�����g��p�������(PDL)
 */

/* ���{�ݒ�l */
#define GPS_PCND_MEDIA_BIND_OFF            (1<<0) /* ���{���� */
#define GPS_PCND_MEDIA_BIND_MAGAZINE_LEFT  (1<<1) /* �T����(���֊J��) */
#define GPS_PCND_MEDIA_BIND_MAGAZINE_RIGHT (1<<2) /* �T����(�E�֊J��) */

/* �p���T�C�Y�w��(�p���T�C�Y�ϔ{)�ݒ�l */
#define GPS_PCND_MEDIA_MAG_OFF (1<<0) /* OFF */
#define GPS_PCND_MEDIA_MAG_ON  (1<<1) /* ON */

/* �𑜓x(TIFF�p)�ݒ�l */
#define GPS_PCND_MEDIA_RESOL_TIFF_200 (1<<0) /* 200dpi */
#define GPS_PCND_MEDIA_RESOL_TIFF_300 (1<<1) /* 300dpi */
#define GPS_PCND_MEDIA_RESOL_TIFF_400 (1<<2) /* 400dpi */
#define GPS_PCND_MEDIA_RESOL_TIFF_600 (1<<3) /* 600dpi */

/* �𑜓x(PDF�p)�ݒ�l */
#define GPS_PCND_MEDIA_RESOL_PDF_600_FAST (1<<0) /* 600dpi(2�K��) */
#define GPS_PCND_MEDIA_RESOL_PDF_600_STD  (1<<1) /* 600dpi(�W��) */
#define GPS_PCND_MEDIA_RESOL_PDF_600_HIGH (1<<2) /* 600dpi(���掿) */
#define GPS_PCND_MEDIA_RESOL_PDF_1200     (1<<3) /* 1200dpi */
#define GPS_PCND_MEDIA_RESOL_PDF_300      (1<<4) /* 300dpi */
#define GPS_PCND_MEDIA_RESOL_PDF_1200_2   (1<<5) /* 1200dpi 2bit */

/* ����i��(JPEG�p)�ݒ�l */
#define GPS_PCND_MEDIA_PRTQUAL_NORMAL (1<<0) /* �m�[�}�� */
#define GPS_PCND_MEDIA_PRTQUAL_DRAFT  (1<<1) /* �h���t�g */
#define GPS_PCND_MEDIA_PRTQUAL_FINE   (1<<2) /* �t�@�C�� */

typedef struct gps_pdl_media_printcondition {
	unsigned long bind;          /* ���{ */
	struct {                     /* �p���T�C�Y�w�� */
		unsigned long magnification; /* �p���T�C�Y�ϔ{ */
		unsigned int  size_code;     /* ���T�C�Y�R�[�h */
		unsigned long paper_width;   /* �t���[�T�C�Y���̗p����  (0.1mm�P��) */
		unsigned long paper_length;  /* �t���[�T�C�Y���̗p������(0.1mm�P��) */
	} paper_size;
	struct {                     /* �𑜓x */
		unsigned long tiff;          /* TIFF�p */
		unsigned long pdf;           /* PDF�p */
	} resolution;
	unsigned long printquality;  /* ����i��(JPEG�p) */
	unsigned long reserve1;      /* �\��1 */
	unsigned long reserve2;      /* �\��2 */
	unsigned long reserve3;      /* �\��3 */
} gps_pdl_media_printcondition_t;


/*
 * �������(SYS) 12A�`
 */

/* �����g���C�I��ݒ�l */
#define GPS_PCND_SYS2_INPUTTRAY_AUTO (1<<0)  /* �����g���C */
#define GPS_PCND_SYS2_INPUTTRAY_1    (1<<1)  /* �g���C1 */
#define GPS_PCND_SYS2_INPUTTRAY_2    (1<<2)  /* �g���C2 */
#define GPS_PCND_SYS2_INPUTTRAY_3    (1<<3)  /* �g���C3 */
#define GPS_PCND_SYS2_INPUTTRAY_4    (1<<4)  /* �g���C4 */
#define GPS_PCND_SYS2_INPUTTRAY_5    (1<<5)  /* �g���C5 */
#define GPS_PCND_SYS2_INPUTTRAY_6    (1<<6)  /* �g���C6 */
#define GPS_PCND_SYS2_INPUTTRAY_7    (1<<7)  /* �g���C7 */
#define GPS_PCND_SYS2_INPUTTRAY_LCT  (1<<30) /* ��ʋ����g���C */
#define GPS_PCND_SYS2_INPUTTRAY_MAN  (1<<31) /* �荷���g���C */

/* ���ʈ���ݒ�l */
#define GPS_PCND_SYS2_DUPLEX_OFF   (1<<0) /* �Ж� */
#define GPS_PCND_SYS2_DUPLEX_LEFT  (1<<1) /* ���ʍ��J�� */
#define GPS_PCND_SYS2_DUPLEX_TOP   (1<<3) /* ���ʏ�J�� */

/* �\�[�g�ݒ�l */
#define GPS_PCND_SYS2_SORT_NORMAL (1<<0) /* �\�[�g */
#define GPS_PCND_SYS2_SORT_ROTATE (1<<1) /* ��]�\�[�g */
#define GPS_PCND_SYS2_SORT_SHIFT  (1<<2) /* �V�t�g�\�[�g */

/* �X�^�b�N�ݒ�l */
#define GPS_PCND_SYS2_STACK (1<<0) /* �X�^�b�N */

/* �X�e�[�v���ݒ�l */
#define GPS_PCND_SYS2_STAPLE_OFF           (1<<0) /* �X�e�[�v������ */
#define GPS_PCND_SYS2_STAPLE_LEFTTOP       (1<<1) /* ���� */
#define GPS_PCND_SYS2_STAPLE_RIGHTTOP      (1<<2) /* �E�� */
#define GPS_PCND_SYS2_STAPLE_LEFTTOPSLANT  (1<<3) /* ����΂� */
#define GPS_PCND_SYS2_STAPLE_RIGHTTOPSLANT (1<<4) /* �E��΂� */
#define GPS_PCND_SYS2_STAPLE_LEFT2         (1<<5) /* ��2�� */
#define GPS_PCND_SYS2_STAPLE_TOP2          (1<<6) /* ��2�� */
#define GPS_PCND_SYS2_STAPLE_RIGHT2        (1<<7) /* �E2�� */
#define GPS_PCND_SYS2_STAPLE_BOOKLET       (1<<8) /* ���Ԃ� */

/* �p���`�ݒ�l */
#define GPS_PCND_SYS2_PUNCH_OFF      (1<<0)  /* �p���`���� */
#define GPS_PCND_SYS2_PUNCH_LEFT2    (1<<1)  /* ��2�� */
#define GPS_PCND_SYS2_PUNCH_TOP2     (1<<2)  /* ��2�� */
#define GPS_PCND_SYS2_PUNCH_RIGHT2   (1<<3)  /* �E2�� */
#define GPS_PCND_SYS2_PUNCH_LEFT3    (1<<4)  /* ��3�� */
#define GPS_PCND_SYS2_PUNCH_TOP3     (1<<5)  /* ��3�� */
#define GPS_PCND_SYS2_PUNCH_RIGHT3   (1<<6)  /* �E3�� */
#define GPS_PCND_SYS2_PUNCH_LEFT4    (1<<7)  /* ��4�� */
#define GPS_PCND_SYS2_PUNCH_TOP4     (1<<8)  /* ��4�� */
#define GPS_PCND_SYS2_PUNCH_RIGHT4   (1<<9)  /* �E4�� */
#define GPS_PCND_SYS2_PUNCH_LEFTGBC  (1<<10) /* GBC�� */
#define GPS_PCND_SYS2_PUNCH_TOPGBC   (1<<11) /* GBC�� */
#define GPS_PCND_SYS2_PUNCH_RIGHTGBC (1<<12) /* GBC�E */
#define GPS_PCND_SYS2_PUNCH_LEFTTOP  (1<<13) /* ����1�� */

/* �g�i�[�Z�[�u(���m�N��)�ݒ�l */
#define GPS_PCND_SYS2_TONERSAVE_MONO_OFF (1<<0) /* OFF */
#define GPS_PCND_SYS2_TONERSAVE_MONO_ON  (1<<1) /* ON */

/* 180�x��]�ݒ�l */
#define GPS_PCND_SYS2_UPSIDEDOWN_OFF (1<<0) /* OFF */
#define GPS_PCND_SYS2_UPSIDEDOWN_ON  (1<<1) /* ON */

/* ���[�h */
#define GPS_PCND_SYS2_MODE_FORCERIP  (1<<0)  /* ����RIP */

typedef struct gps_sys2_printcondition {
	unsigned long inputtray;      /* �����g���C�I�� */
	unsigned long duplex;         /* ���ʈ�� */
	unsigned long sort;           /* �\�[�g */
	unsigned long stack;          /* �X�^�b�N */
	unsigned long staple;         /* �X�e�[�v�� */
	unsigned long punch;          /* �p���` */
	unsigned int  qty;            /* �o�͕��� */
	unsigned long tonersave_mono; /* �g�i�[�Z�[�u(���m�N��) */
	unsigned long upsidedown;     /* 180�x��] */
	unsigned long reserve1;       /* �\��1 */
	unsigned long mode;           /* ���[�h */
} gps_sys2_printcondition_t;


/*
 * ��������\����(���L��������) 12A�`
 */

/* ��������ύX�̗L��(change) */
#define GPS_PCND_CHG_PDL   (1<<0) /* bit0: �������(PDL) */
#define GPS_PCND_CHG_PDL2  (1<<1) /* bit1: ��������Q(PDL) */
#define GPS_PCND_CHG_MEDIA (1<<2) /* bit2: ���f�B�A�v�����g�������(PDL) */
#define GPS_PCND_CHG_SDK   (1<<3) /* bit3: �r�c�j�A�v���v�����g�������(PDL) */
#define GPS_PCND_CHG_SYS   (1<<4) /* bit4: �������(�V�X�e��) */

typedef struct gps_printconditionShm {
	unsigned int                   job_type; /* �W���u�^�C�v�ݒ�l */
	unsigned long                  change;   /* ��������ύX�̗L�� */
	gps_pdl_printcondition_t       pdl;      /* �������(PDL)�i�[�̈� */
	gps_pdl_printcondition2_t      pdl2;     /* ��������Q(PDL)�i�[�̈� */
	gps_pdl_media_printcondition_t media;    /* ���f�B�A�v�����g��p�������(PDL)�i�[�̈� */
	gps_pdl_sdk_printcondition_t   sdk;      /* SDK�A�v���v�����g��p�������(PDL)�i�[�̈�  ��CPS���Ǘ��\���� */
	gps_sys2_printcondition_t      sys;      /* �������(�V�X�e��)�i�[�̈� �������p�ɒǉ� */
} gps_printconditionShm_t;


/*
 * PDF��p�p�����[�^ 12A�ȍ~���g�p
 */

#define GPS_PDF_PRINTPAGES_LEN 12

typedef struct {
	unsigned char pdfpassword[GPS_PDF_PASSWORD_LEN];  /* PDF�p�X���[�h������ */
	unsigned char printpages[GPS_PDF_PRINTPAGES_LEN]; /* �_���y�[�W�w��(�����Ώۃy�[�W) */
} gps_pdf_param_t;

#endif /* !_GPS_PRINTCOND_H_ */
/*
 * Copyright (c) 2010 Ricoh Company, Ltd.  All Rights Reserved.
 */
