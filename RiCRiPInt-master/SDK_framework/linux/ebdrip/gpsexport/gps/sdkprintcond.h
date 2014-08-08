/*
 * sdkprintcond.h
 *
 *  Created on: 2011/08/11
 */

#ifndef SDKPRINTCOND_H_
#define SDKPRINTCOND_H_


/*
 * SDK�A�v���v�����g��p�������(PDL)
 */

#define GPS_SDK_PAGES_LEN								(229) /* �_���y�[�W�w��ő啶���� */
#define GPS_SDK_PDF_PASSWORD_LEN						(36) /* PDF�p�X���[�h�ő啶���� */

#define GPS_PCND_SDK_FORCEDDUPLEX_LEFT					(1<<1) /* �������ʐݒ�F���J�� */
#define GPS_PCND_SDK_FORCEDDUPLEX_TOP					(1<<3) /* �������ʐݒ�F��J�� */

#define GPS_PCND_SDK_DUPLEX_OFF							(1<<0) /* �Ж� */
#define GPS_PCND_SDK_DUPLEX_LEFT						(1<<1) /* ���ʍ��J�� */
#define GPS_PCND_SDK_DUPLEX_TOP							(1<<3) /* ���ʏ�J�� */

#define GPS_PCND_SDK_COLORMODE_MONO						(1<<0) /* ���� */
#define GPS_PCND_SDK_COLORMODE_COLOR					(1<<1) /* �J���[ */

#define GPS_PCND_SDK_TONERSAVE_OFF						(1<<0) /* (�J���[�@�p)OFF */
#define GPS_PCND_SDK_TONERSAVE_ON						(1<<1) /* (�J���[�@�p)ON */

#define GPS_PCND_SDK_TONERSAVE_MONO_OFF					(1<<0) /* OFF */
#define GPS_PCND_SDK_TONERSAVE_MONO_ON					(1<<1) /* ON */

#define GPS_PCND_SDK_CHG_PAPERKIND_EXIST				(1<<0) /* �ύX�L�� */

#define GPS_PCND_SDK_NUP_OFF							(1<<0) /* �W�񖳂� */
#define GPS_PCND_SDK_NUP_2IN1							(1<<1) /* 2in1 */
#define GPS_PCND_SDK_NUP_4IN1							(1<<2) /* 4in1 */
#define GPS_PCND_SDK_NUP_6IN1							(1<<3) /* 6in1 */
#define GPS_PCND_SDK_NUP_8IN1							(1<<4) /* 8in1 */
#define GPS_PCND_SDK_NUP_9IN1							(1<<5) /* 9in1 */
#define GPS_PCND_SDK_NUP_16IN1							(1<<6) /* 16in1 */

#define GPS_PCND_SDK_NUPOPT_PAGEORDER_RIGHT_THEN_DOWN	(1<<0) /* �W����� 2in1�ȊO:���と�E�と�������E�� 2in1:������E�� */
#define GPS_PCND_SDK_NUPOPT_PAGEORDER_LEFT_THEN_DOWN	(1<<1) /* �W����� 2in1�ȊO:�E�と���と�E�������� 2in1:�E���獶�� */
#define GPS_PCND_SDK_NUPOPT_PAGEORDER_DOWN_THEN_RIGHT	(1<<2) /* �W����� 2in1�ȊO:���と�������E�と�E�� 2in1:���g�p */
#define GPS_PCND_SDK_NUPOPT_PAGEORDER_DOWN_THEN_LEFT	(1<<3) /* �W����� 2in1�ȊO:�E�と�E�������と���� 2in1:���g�p */

#define GPS_PCND_SDK_NUP_BORDER_OFF						(1<<0) /* ���� */
#define GPS_PCND_SDK_NUP_BORDER_ON						(1<<1) /* �L�� */

#define GPS_PCND_SDK_INPUTTRAY_AUTO						(1<<0) /* �����g���C */
#define GPS_PCND_SDK_INPUTTRAY_1						(1<<1) /* �g���C1 */
#define GPS_PCND_SDK_INPUTTRAY_2						(1<<2) /* �g���C2 */
#define GPS_PCND_SDK_INPUTTRAY_3						(1<<3) /* �g���C3 */
#define GPS_PCND_SDK_INPUTTRAY_4						(1<<4) /* �g���C4 */
#define GPS_PCND_SDK_INPUTTRAY_5						(1<<5) /* �g���C5 */
#define GPS_PCND_SDK_INPUTTRAY_6						(1<<6) /* �g���C6 */
#define GPS_PCND_SDK_INPUTTRAY_7						(1<<7) /* �g���C7 */
#define GPS_PCND_SDK_INPUTTRAY_LCT						(1<<30) /* ��ʋ����g���C */
#define GPS_PCND_SDK_INPUTTRAY_MAN						(1<<31) /* �荷���g���C */

#define GPS_PCND_SDK_SORT_NORMAL						(1<<0) /* �\�[�g */
#define GPS_PCND_SDK_SORT_ROTATE						(1<<1) /* ��]�\�[�g */
#define GPS_PCND_SDK_SORT_SHIFT							(1<<2) /* �V�t�g�\�[�g */

#define GPS_PCND_SDK_STACK								(1<<0) /* �X�^�b�N */

#define GPS_PCND_SDK_STAPLE_OFF							(1<<0) /* �X�e�[�v������ */
#define GPS_PCND_SDK_STAPLE_LEFTTOP						(1<<1) /* ���� */
#define GPS_PCND_SDK_STAPLE_RIGHTTOP					(1<<2) /* �E�� */
#define GPS_PCND_SDK_STAPLE_LEFTTOPSLANT				(1<<3) /* ����΂� */
#define GPS_PCND_SDK_STAPLE_RIGHTTOPSLANT				(1<<4) /* �E��΂� */
#define GPS_PCND_SDK_STAPLE_LEFT2						(1<<5) /* ��2�� */
#define GPS_PCND_SDK_STAPLE_TOP2						(1<<6) /* ��2�� */
#define GPS_PCND_SDK_STAPLE_RIGHT2						(1<<7) /* �E2�� */
#define GPS_PCND_SDK_STAPLE_BOOKLET						(1<<8) /* ���Ԃ� */

#define GPS_PCND_SDK_PUNCH_OFF							(1<<0) /* �p���`���� */
#define GPS_PCND_SDK_PUNCH_LEFT2						(1<<1) /* ��2�� */
#define GPS_PCND_SDK_PUNCH_TOP2							(1<<2) /* ��2�� */
#define GPS_PCND_SDK_PUNCH_RIGHT2						(1<<3) /* �E2�� */
#define GPS_PCND_SDK_PUNCH_LEFT3						(1<<4) /* ��3�� */
#define GPS_PCND_SDK_PUNCH_TOP3							(1<<5) /* ��3�� */
#define GPS_PCND_SDK_PUNCH_RIGHT3						(1<<6) /* �E3�� */
#define GPS_PCND_SDK_PUNCH_LEFT4						(1<<7) /* ��4�� */
#define GPS_PCND_SDK_PUNCH_TOP4							(1<<8) /* ��4�� */
#define GPS_PCND_SDK_PUNCH_RIGHT4						(1<<9) /* �E4�� */
#define GPS_PCND_SDK_PUNCH_LEFTGBC						(1<<10) /* GBC�� */
#define GPS_PCND_SDK_PUNCH_TOPGBC						(1<<11) /* GBC�� */
#define GPS_PCND_SDK_PUNCH_RIGHTGBC						(1<<12) /* GBC�E */
#define GPS_PCND_SDK_PUNCH_LEFTTOP						(1<<13) /* ����1�� */

#define GPS_PCND_SDK_BIND_OFF							(1<<0) /* ���{���� */
#define GPS_PCND_SDK_BIND_MAGAZINE_LEFT					(1<<1) /* �T����(���֊J��) */
#define GPS_PCND_SDK_BIND_MAGAZINE_RIGHT				(1<<2) /* �T����(�E�֊J��) */

#define GPS_PCND_SDK_MAG_OFF							(1<<0) /* OFF */
#define GPS_PCND_SDK_MAG_ON								(1<<1) /* ON */

#define GPS_PCND_SDK_RESOL_PDF_600_FAST					(1<<0) /* 600dpi(2�K��) */
#define GPS_PCND_SDK_RESOL_PDF_600_STD					(1<<1) /* 600dpi(�W��) */
#define GPS_PCND_SDK_RESOL_PDF_600_HIGH					(1<<2) /* 600dpi(���掿) */
#define GPS_PCND_SDK_RESOL_PDF_1200						(1<<3) /* 1200dpi */
#define GPS_PCND_SDK_RESOL_PDF_300						(1<<4) /* 300dpi */
#define GPS_PCND_SDK_RESOL_PDF_1200_2					(1<<5) /* 1200dpi(2bit) */

typedef struct gps_pdl_skd_printcondition{

	unsigned char printpages[GPS_SDK_PAGES_LEN];	/* �_���y�[�W�w��(�����Ώۃy�[�W)  �vNULL�^�[�~�l�[�g */

	/* �������� */
	unsigned long forced_duplex;

	/* ���� */ /* PDF�p */
	unsigned long duplex;

	/* �������m�N�� */
	unsigned long forced_colormode;

	/* �J���[���[�h */ /* PDF�p */
	unsigned long colormode;

	/* �g�i�[�Z�[�u(�J���[�@) */
	unsigned long tonersave_color;

	/* �g�i�[�Z�[�u(���m�N���@) */
	unsigned long tonersave_mono;

	/* ���� */
	unsigned int print_num;

	/* �p����ޕύX�L�� */ /* PDF�p */
	unsigned long chg_paper_kind;

	/* �p����� */ /* PDF�p */
	unsigned int  paper_kind;

	/* �W�� */ /* PDF�p */
	unsigned long nup;

	/* �W��p�����[�^ */ /* PDF�p */
	unsigned long nup_option;

	/* �W��d�؂�� */ /* PDF�p */
	unsigned long nup_border;

	/* PDF�p�X���[�h������ �vNULL�^�[�~�l�[�g */ /* PDF�p */
	unsigned char pdfpassword[GPS_SDK_PDF_PASSWORD_LEN];

	/* �����g���C�I�� */ /* PDF�p */
	unsigned long inputtray;

	/* �\�[�g */ /* PDF�p */
	unsigned long sort;

	/* �X�^�b�N */ /* PDF�p */
	unsigned long stack;

	/* �X�e�[�v�� */ /* PDF�p */
	unsigned long staple;

	/* �p���` */ /* PDF�p */
	unsigned long punch;

	/* ���{ */ /* PDF�p */
	unsigned long bind;

	/* �p���T�C�Y�w�� */ /* PDF�p */
	struct {

		/* �p���T�C�Y�ϔ{ */
		unsigned long magnification;

		/* ���T�C�Y�R�[�h */
		unsigned int  size_code;

		/* �t���[�T�C�Y���̗p����  (0.1mm�P��) */
		unsigned long paper_width;

		/* �t���[�T�C�Y���̗p������(0.1mm�P��) */
		unsigned long paper_length;

	} paper_size;
	
	/* �𑜓x */
	struct {

		/* PDF�p */
		unsigned long pdf;

	} resolution;

	unsigned long reserve[13];					/* �\�� */

} gps_pdl_sdk_printcondition_t;


#endif /* SDKPRINTCOND_H_ */
