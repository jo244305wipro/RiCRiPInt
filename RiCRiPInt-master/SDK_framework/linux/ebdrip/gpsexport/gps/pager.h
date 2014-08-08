/*
 *	Copyright(c) 1997,2002 by RICOH Co.,LTD.
 *
 *	$Author: shihab $
 *	$Date: 2009/03/16 06:03:43 $
 *	$Revision: 1.38 $
 */

#ifndef __PAGER_H__
#define __PAGER_H__


/*
 *	Return Value
 *		������� OK = 1(TRUE), ERROR = 0(FALSE) �ɕύX�\��B
 */

#define	PR_OK			 0
#define	PR_ERROR		 1
#define	PR_OK_BLANKPAGE		-1	/* pr_pagestart() ��p */

/*
 * support function
 */
#define PR_FUNC_DEFAULT_SETTING		0x00000000  /* ���ׂ�default���w�肳��� */

//Permanent Font
#define PR_FUNC_PERMANENTFONT_OFF	0x00000000 /* �O���@�\OFF */
#define PR_FUNC_PERMANENTFONT_ON	0x00000001 /* �O���@�\ON */
#define PR_FUNC_PERMANENTFONT_MASK	0x00000001 /* �O���@�\ �}�X�N */

/* Alignment Size */
#define PR_FUNC_8BYTE_ALIGN			0x00000002 /* 8byte alignment size */
#define PR_FUNC_4BYTE_ALIGN			0x00000000 /* 4byte alignment size (default)*/
#define PR_FUNC_ALIGNSIZE_MASK		0x00000002 /* alignment size mask */

//Source trans

#define PR_FUNC_SOURCETRANS_OFF  0x00000000 
#define PR_FUNC_SOURCETRANS_ON	0x00000010
#define PR_FUNC_SOURCETRANS_MASK	0x00000010

/*
 *	������[�h
 */
#define	PR_PENV_VAL_INT_QUALITYMODE_STANDARD	(0)
#define	PR_PENV_VAL_INT_QUALITYMODE_FAST	(1)
#define	PR_PENV_VAL_INT_QUALITYMODE_FINE	(2)
#define	PR_PENV_VAL_INT_QUALITYMODE_SUPERFINE	(3)

#define	PR_PRINT_MODE_HIGH			(0x01)
#define	PR_PRINT_MODE_NORMAL			(0x02)
#define	PR_PRINT_MODE_QUALITY			(0x03)
#define	PR_PRINT_MODE_HIGHQUALITY		(0x04)
#define	PR_PRINT_MODE_MASK			(0x0F)
#define	PR_PRINT_DENSITY_STANDARD		(0x40)
#define	PR_PRINT_DENSITY_LIGHT			(0x30)
#define	PR_PRINT_DENSITY_DARK			(0x50)
#define	PR_PRINT_DENSITY_MASK			(0xF0)

/*
 *	color mode
 */

#define	PR_COLOR_GRAY		0	/* ���m�N�� */
#define	PR_COLOR_RGB		1	/* RGB �J���[ */
#define	PR_COLOR_CMYK		2	/* CMYK �J���[ */
#define	PR_COLOR_NOUSE		3	/* ���g�p �J���[���[�h */
#define	PR_COLOR_MASK		3	/* �J���[���[�h�}�X�N */
#define	PR_COLOR_BGMODE		8

/*
 *	PR2�p pr_setcolor�ǉ��}�N��
 */
#define PR_COLOR_FILL		0	/* FILL�p�^�[�� �ʏ�̓h��Ԃ� */
#define PR_COLOR_GRADATION	0x10	/* FILL�p�^�[�� �O���f�[�V���� */

/*
 *	bit depth
 */
#define	PR_DEPTH_1BIT		0x00	/* 1bit			*/
#define	PR_DEPTH_2BIT		0x10	/* 2bit			*/
#define	PR_DEPTH_4BIT		0x20	/* 4bit			*/
#define	PR_DEPTH_8BIT		0x30	/* 8bit			*/
#define	PR_DEPTH_MASK		0x30	/* �r�b�g�[���}�X�N	*/

/*
 *	device color
 */
#define	PR_DEVICE_MONO		0x00	/* ����			*/
#define	PR_DEVICE_RGB		0x01	/* RGB			*/
#define	PR_DEVICE_CMY		0x02	/* CMY			*/
#define	PR_DEVICE_CMYK		0x03	/* CMYK			*/
#define	PR_DEVICE_RK		0x04	/* �ԍ���F		*/
#define	PR_DEVICE_RK2		0x05	/* �S�I�u�W�F�N�g�ԍ���F	*/
#define	PR_DEVICE_MASK		0x0F	/* Device Color�}�X�N	*/

/*
 *	rotation direction
 */
#define	PR_ROTATE_R0		0x00	/* ��]�Ȃ�		*/
#define	PR_ROTATE_R90		0x40	/* �E90�x��]		*/
#define	PR_ROTATE_R180		0x80	/* 180�x��]		*/
#define	PR_ROTATE_R270		0xC0	/* �E270�x��]		*/
#define	PR_ROTATE_DIRECTION	0xC0	/* ��]�w��}�X�N	*/

/*
 *	rotation direction
 */
#define	PR_ROT_R0		0x00	/* ��]�Ȃ�		*/
#define	PR_ROT_R90		0x01	/* �E90�x��]		*/
#define	PR_ROT_R180		0x02	/* 180�x��]		*/
#define	PR_ROT_R270		0x03	/* �E270�x��]		*/
#define	PR_ROT_DIRECTION	0x03	/* ��]�w��}�X�N	*/

/*
 *	rendering color
 */
#define PR_RENDERING_NONE	0x0000	/* Use device color	*/
#define PR_RENDERING_MONO	0x0100	/* Monochrome		*/
#define PR_RENDERING_RGB	0x0200	/* RGB			*/
#define PR_RENDERING_CMY	0x0300	/* CMY			*/
#define PR_RENDERING_CMYK	0x0400	/* CMYK			*/
#define PR_RENDERING_RK		0x0500	/* RK			*/
#define PR_RENDERING_MASK	0x0F00	/* Rendering color mask	*/

/*
 *	�d�Ȃ蔻���}��(pr_pagestart)
 */
#define	PR_CUTOUT_AVAIL		0x00010000

/*
 *	gray mode
 */

#define	PR_GRAY_G2K		0	/* �O���C�̂ݍ��ϊ�orBG/UCR	*/
#define	PR_GRAY_CMYK		1	/* ���BG/UCR			*/
#define	PR_GRAY_K2K		2	/* ���̂ݍ��ϊ�orBG/UCR		*/
#define	PR_GRAY_CMY		3	/* BG/UCR���Ȃ�(RGB->CMY�̂�)	*/
#define	PR_GRAY_PIXELK		4	/* �J���[�C���[�W�ł��O���C�̂�
					   ���ϊ�orBG/UCR�i�{����G2K�j  */
#define	PR_GRAY_MAYBEK		5	/* ��f����������GRAY->K�ϊ����s�Ȃ� */
#define	PR_GRAY_ABOUTK		6	/* R��G��B��GRAY->K�ϊ����s�Ȃ� */
#define	PR_GRAY_IMAGEK		7	/* �C���[�W�ł�K2K�ϊ����s�Ȃ�	*/
#define	PR_GRAY_COMPBK		8	/* Composite black */
#define	PR_GRAY_HGRG2K		10	/* �O���C�̂ݍ��ϊ�orBG/UCR(���n)	*/
#define	PR_GRAY_HGRCMYK		11	/* ���BG/UCR(���n)			*/
#define	PR_GRAY_MAX		11	/* �O���C�w��ő�l */

#define	PR_GRAY_MASK		3	/* �O���C�w��}�X�N */

#define PR_JUDGE_GRAY_AFTER_CMM_ON	0	/* CMM��̃O���C���菈�����s�Ȃ��i�f�t�H���g�j */
#define PR_JUDGE_GRAY_AFTER_CMM_OFF	1	/* CMM��̃O���C���菈�����s�Ȃ�Ȃ� */
#define PR_JUDGE_GRAY_MAX 1				/* CMM��̃O���C���菈���w��ő�l */


/*
 *	output mode
 */
#define	PR_PAPERFEED_NORMAL			0	/* �ʏ�r��   */
#define	PR_PAPERFEED_NOTPRINT		1	/* �r�����Ȃ� */
#define	PR_PAPERFEED_OVERLAY		2	/* �������   */
#define	PR_PAPERFEED_NOWHITE		3	/* �����}��   */
#define	PR_PAPERFEED_FORCE			4	/* �������   */
#define PR_PAPERFEED_FORCE_NOWHITE	5	/* ��������������}�� */
#define PR_PAPERFEED_NOTDRAW_NOTPRINT	6	/* Only GJ support it */

/*
 *	dither type
 */

#define	PR_DIT_PHOT		0	/* �ʐ^�f�B�U */
#define	PR_DIT_TEXT		1	/* �����f�B�U */
#define	PR_DIT_GRAP		2	/* �O���t�B�b�N�X�f�B�U */
#define	PR_DIT_CAD		3	/* CAD�f�B�U */
#define	PR_DIT_MASK		3	/* �f�B�U�w��}�X�N */

/*
 * �덷�g�U���[�h
 */
#define	PR_IMAGE_ED		0x01	/* �C���[�W�덷�g�U(���󖢎g�p) */
#define	PR_FRAME_ED		0x02	/* �S�ʌ덷�g�U */
#define	PR_ED_MASK		0x03

/*
 * ���� ID (iRPJL, PR ���ɓ��� ID ���g�p����)
 */
#define	PR_MEDIA_PLAIN		1	/* ���ʎ� */
#define	PR_MEDIA_THICK		3	/* ���� */
#define	PR_MEDIA_TRANSPARENCY	17	/* OHP */
#define	PR_MEDIA_GLOSSY		19	/* ���� */
#define	PR_MEDIA_JPOST		24	/* �����͂��� */
#define	PR_MEDIA_COATED		38	/* ��p�R�[�g�� */
#define	PR_MEDIA_INKJETJPOST	39	/* �C���N�W�F�b�g�����͂��� */
#define	PR_MEDIA_ENVELOPE	40	/* ���� */
#define	PR_MEDIA_MASK		0x7f

/*
 *	brush types.
 */

#define	PR_BRUSH_MONO		0	/* mono brush.			*/
#define	PR_BRUSH_RGB		1	/* RGB brush.			*/
#define	PR_BRUSH_CMYK		2	/* CMYK brush.			*/
#define	PR_BRUSH_MASK		3	/* �u���V�p�}�X�N		*/

#define PR_BRUSH_TRANS		8	/* ���߃p�^�[���w�肠��		*/

/*
 *	BackGround Mode
 */

#define	PR_TRANS		1	/* ���� */
#define	PR_OPAQUE		2	/* �s���� */
#define	PR_BGMODE_MASK		3	/* �o�b�N�O���E���h�p�}�X�N */

#define PR_SOURCE_TRANS		0x04	/* �\�[�X���߃��[�h */
#define PR_SOURCE_OPAQUE	0x00	/* �\�[�X�񓧉߃��[�h */
#define PR_SOURCE_MASK		0x04	/* �\�[�X���߃��[�h�p�}�X�N */

#define PR_PATTERN_TRANS	0x08	/* �u���V���߃��[�h */
#define PR_PATTERN_OPAQUE	0x00	/* �u���V�񓧉߃��[�h */
#define PR_PATTERN_MASK		0x08	/* �u���V���߃��[�h�p�}�X�N */

#define PR_TRANS_EXCEPTION_ON	0x10	/* ���߃��[�h��O�����L�� */
#define PR_TRANS_EXCEPTION_OFF	0x00	/* ���߃��[�h��O�������� */
#define PR_TRANS_EXCEPTION_MASK	0x10	/* ���߃��[�h��O�����p�}�X�N */

#define PR_SOLID_BRUSH_EXCEPTION_ON	0x20	/* SOLID BRUSH��O�����L�� */
#define PR_SOLID_BRUSH_EXCEPTION_OFF	0x00	/* SOLID BRUSH��O�������� */
#define PR_SOLID_BRUSH_EXCEPTION_MASK	0x20	/* SOLID BRUSH��O�����p�}�X�N */

/*
 *	line cap types.
 */

#define	PR_CAP_ROUND		0	/* windows default line cap.	*/
#define	PR_CAP_BUTT		1	/* butt cap.			*/
#define	PR_CAP_SQUARE		2	/* square cap.			*/
#define	PR_CAP_TRIANGLE		3	/* triangle cap.		*/
#define	PR_CAP_MASK		3	/* CAP �w��}�X�N		*/

/*
 *	joint types.
 */

#define	PR_JOINT_ROUND		0	/* round type.         */
#define	PR_JOINT_BEVEL		1	/* bevel connecttion.  */
#define	PR_JOINT_MITER		2	/* miter connection    */
#define	PR_JOINT_MASK		3	/* JOINT �w��}�X�N    */

/*
 *	object type
 */
#define	PR_OBJ_IMAG		0
#define	PR_OBJ_GRAP		1
#define	PR_OBJ_TEXT		2
#define	PR_OBJ_LINE		3
#define	PR_OBJ_MASK		3

/*
 *	graphic object flag
 */

#define	PR_DRAW			0x00	/* Draw */
#define	PR_ALTFILL		0x01	/* Alt Fill */
#define	PR_WINDFILL		0x02	/* Wind Fill */
#define	PR_DRAWALTFILL		0x03	/* Draw and Alt Fill */
#define	PR_DRAWWINDFILL		0x04	/* Draw and Wind Fill */
#define	PR_ALTCLIP		0x05	/* Alt Clip */
#define	PR_WINDCLIP		0x06	/* Wind Clip */
#define	PR_DRAW_NOUSE		0x07	/* Reserve */
#define	PR_DRAW_MASK		0x07	/* Draw Mask */
#define	PR_PATHCLOSE		0x08	/* path Open/Close mode */
#define	PR_SHORT_COORD		0x20	/* Spool 2BYTE COORD */
#define	PR_FLOAT_COORD		0x40	/* Spool FLOAT COORD */
#define	PR_COORD_MASK		0x60	/* Spool COORD Mask */
#define	PR_SCRECT_DRAW		0x40	/* SC Rectangle Draw */
#define PR_ARC_DRAW		0x00	/* Arc Draw */
#define PR_ARC_FILL		0x01	/* Arc Fill */
#define PR_ARC_DRAWFILL		0x03	/* Arc Draw and Fill */
#define PR_ARC_CLIP		0x05	/* Arc Clip */

#define	PR_CLIP_STACK		0x00010000	/* Clip STACK */

/* for scanline */

#define PR_SC_FILL		0x00	/* Fill */
#define PR_SC_CLIP		0x01	/* Clip */
#define PR_SC_NOCOMP		0x00	/* not compress */
#define PR_SC_DLDE		0x04	/* DLDE */
#define PR_SC_COMPMASK		0x06	/* compress flag mask */

#define	PR_ATTR_DRAW_DEFAULT		0x00000000
#define	PR_ATTR_DRAW_IMAGE_COLOR	0x08000000
#define	PR_ATTR_DRAW_IMAGE_MONO		0x10000000
#define	PR_ATTR_DRAW_GRAPH		0x18000000
#define	PR_ATTR_DRAW_TEXT		0x20000000
#define	PR_ATTR_DRAW_LINE		0x28000000
#define	PR_ATTR_DRAW_MASK		0x38000000

#define	PR_ATTR_FILL_DEFAULT		0x00000000
#define	PR_ATTR_FILL_IMAGE_COLOR	0x01000000
#define	PR_ATTR_FILL_IMAGE_MONO		0x02000000
#define	PR_ATTR_FILL_GRAPH		0x03000000
#define	PR_ATTR_FILL_TEXT		0x04000000
#define	PR_ATTR_FILL_LINE		0x05000000
#define	PR_ATTR_FILL_MASK		0x07000000

#define	PR_ATTR_DEFAULT		0x00000000
#define	PR_ATTR_IMAGE_COLOR	0x01000000
#define	PR_ATTR_IMAGE_MONO	0x02000000
#define	PR_ATTR_GRAPH		0x03000000
#define	PR_ATTR_TEXT		0x04000000
#define	PR_ATTR_LINE		0x05000000
#define	PR_ATTR_MASK		0x07000000

#define PR_BOP_IMAG		0x40
#define PR_BOP_GRAP		0x10
#define PR_BOP_TEXT		0x04
#define PR_BOP_LINE		0x01

#define PR_SUPPRESS_NORMAL	0x00000000
#define PR_SUPPRESS_SPACE	0x00000001
#define	PR_SUPPRESS_MASK	(PR_SUPPRESS_NORMAL | PR_SUPPRESS_SPACE)

#define	PR_RULE_WIN		0x00	/* scanline rule (Windows)	*/
#define	PR_RULE_PS		0x80	/* scanline rule (PS)		*/

/*
 *	ROP modes.
 */
#define PR_ROP_COLOR_SRC	0x00
#define PR_ROP_COLOR_BRUSH	0x01
#define PR_ROP_COLOR_MASK	0x01
#define PR_ROP_CC_BRUSH		0x00
#define PR_ROP_CC_SRC		0x02
#define PR_ROP_CC_MASK		0x02

/*
 *	print mode (pr_setratio_rgb, pr_setratio_tonerlimit)
 */
#define PR_PRINT_NORMAL		0x00	/* Normal Print */
#define PR_PRINT_COMPBK		0x01	/* CompositeBlack Print */

/*******************************************************************
 **	cached object data tags.				  **
 *******************************************************************/

#define	PR_SINGLE_SFONT		0x00	/* single char with soft font.	*/
#define	PR_SINGLE_SFONT_CTL	0x02	/* regist single char with soft font.(comp) */
#define	PR_SINGLE_SFONT_CTLn	0x03	/* regist single char with soft font.(nocomp(run)) */
#define	PR_POLYLINE		0x11	/* polyline.			*/
#define	PR_POLYLINE_PATH	0x12	/* polyline.(path many)		*/
#define	PR_POLYBEZIER		0x13	/* polybezier.			*/
#define	PR_POLYBEZIER_PATH	0x14	/* polybezier.(path many)	*/
#define	PR_SCANLINE		0x15	/* scanline.			*/
#define	PR_BITBLT		0x20	/* bitblt.			*/
#define	PR_STRETCHBLT		0x21	/* stretchblt.			*/
#define	PR_BRUSH		0x30	/* brush.			*/

/*
 *	inforamtion of errors.
 *		�e�֐��̃G���[����͊�{�Ƃ��āA
 *			PR_ERR_FATAL
 *			PR_ERR_SYNTAX
 *			PR_ERR_STATUS
 *			PR_ERR_INVALID
 *			���̑��B�B�B
 *			�̏��ōs�Ȃ��B
 */
#define	PR_ERR_FATAL		0x01	/* NULL pointer.		*/
#define	PR_ERR_DRAW		0x02	/* draw error.	        	*/
#define	PR_ERR_MEMORY		0x03	/* memory allocation error.	*/
#define	PR_ERR_STATUS		0x04	/* status error.		*/
#define	PR_ERR_INIT		0x05	/* init error.     		*/
#define	PR_ERR_FUNC		0x06	/* function error.     		*/
#define PR_ERR_DOWNLOAD		0x07	/* download error.		*/
#define	PR_ERR_INVALID		0x08	/* invalid value error.		*/
#define	PR_ERR_SYNTAX		0x09	/* invalid parameter error.	*/
#define	PR_ERR_SUPPORT		0x0a	/* support error */

/*
 *	memory type
 */

#define	PR_MEMORY_USED		0x80000000
				/* 0: �Ăяo�����̈�, 1: pr �̈�	*/
/*
 *	for pr_definefont_device
 */
#define	PR_FNT_R0	0x00	/* �����v�����  0�x��] */
#define	PR_FNT_R90	0x04	/* �����v����� 90�x��] */
#define	PR_FNT_R180	0x08	/* �����v�����180�x��] */
#define	PR_FNT_R270	0x0c	/* �����v�����270�x��] */

#define PR_FNT_NOSTY		0x00	/* �X�^�C���Ȃ� */
#define PR_FNT_STY_BLD		0x10	/* Bold */
#define PR_FNT_STY_ITL		0x20	/* Italic */
#define PR_FNT_STY_BLDITL	0x30	/* BoldItalic */

#define	PR_F_PMINCHO		0x0000	/* MS-P mincho font.		*/
#define	PR_F_PGOTHIC		0x0004	/* MS-P gothic font.		*/
#define	PR_F_MINCHO		0x0008	/* MS mincho font.		*/
#define	PR_F_GOTHIC		0x000c	/* MS gothic font.		*/
#define	PR_F_TIMES_ROME		0x0010	/* times new roman.		*/
#define	PR_F_TIMES_ROMEB	0x0011	/* times new roman(bold).	*/
#define	PR_F_TIMES_ROMEI	0x0012	/* times new roman(italic).	*/
#define	PR_F_TIMES_ROMEBI	0x0013	/* times new roman(italic/bold).*/
#define	PR_F_ARIAL		0x0014	/* arial.			*/
#define	PR_F_ARIALB		0x0015	/* arial(bold).			*/
#define	PR_F_ARIALI		0x0016	/* arial(italic).		*/
#define	PR_F_ARIALBI		0x0017	/* arial(italic/bold).		*/
#define	PR_F_COURIER		0x0018	/* Courier.			*/
#define	PR_F_COURIERB		0x0019	/* Courier(bold).		*/
#define	PR_F_COURIERI		0x001a	/* Courier(Italic).		*/
#define	PR_F_COURIERBI		0x001b	/* Courier(Italic/Bold).	*/
#define	PR_F_WINGDINGS		0x0020	/* wingdings.			*/
#define	PR_F_SYMBOL		0x0024	/* Symbol.			*/
#define	PR_F_CENTURY		0x0028	/* Century.			*/
#define PR_F_OCRB		0x002c	/* OCR B('P'&'I')		*/
#define PR_F_OCRB2		0x0030	/* OCR B2('P'&'I')		*/
#define PR_F_PROLQ10		0x0034	/* PRO_LQ 10 ('P'&'U')		*/
#define PR_F_PROLQ12		0x0038	/* PRO_LQ 12 ('P'&'U')		*/
#define PR_F_PROLQ15		0x003c	/* PRO_LQ 15 ('P'&'U')		*/
#define	PR_F_HGPAGOTHIC_EUSTD	0x0040  /* HGP-AGothic ('P'&'S')	*/
#define	PR_F_HGPAGOTHIC_CE	0x0044  /* HGP-AGothic ('P'&'Q')	*/
#define	PR_F_HGPAGOTHIC_CYR	0x0048  /* HGP-AGothic ('P'&'R')	*/
#define	PR_F_HGPAGOTHIC_GREEK	0x004c  /* HGP-AGothic ('P'&'D')	*/
#define	PR_F_ATPMINCHO		0x8000	/* MS-P mincho '@' font.	*/
#define	PR_F_ATPGOTHIC		0x8004	/* MS-P gothic '@' font.	*/
#define	PR_F_ATMINCHO		0x8008	/* MS mincho '@' font.		*/
#define	PR_F_ATGOTHIC		0x800c	/* MS gothic '@' font.		*/
/*
 *	for pr_putchar_download
 */
#define	PR_FNT_JAGGY		0x00000100	/* �W���M�[�␳ 0:OFF, 1:ON */
#define	PR_FNT_CTYPE		0x00000003	/* CompressDataTypeMask */
#define	PR_FNT_CTYPE_BMP		0	/* BMP */
#define	PR_FNT_CTYPE_RUN		1	/* RUN */
#define	PR_FNT_CTYPE_MMR		2	/* MMR */

#define	PR_FNT_CACHETYPE	0x30		/* CachingDataTypeMask */

/*
 *	for permanent font
 */
#define	FNT_CTLDEVICE_SAVE		0x00
#define	FNT_CTLDEVICE_LOAD		0x01
#define	FNT_CTLDEVICE_DELETE_FILE	0x02
#define	FNT_CTLDEVICE_DELETE_DIR	0x03

#define	EXTERNALFONT_FILENAMESZ		229

#define	FNT_CTLDEVDEL_FILE		0x00
#define	FNT_CTLDEVDEL_DIRECTORY		0x01

#define	PERMFONTIDSTART		0xf000
#define	PERMFONTIDEND		0xfffe
#define	EXTERNALFONTIDSTART	0xf000
#define	EXTERNALFONTIDEND	0xf100

/*
 *	for BitBlt
 */
#define	PR_BITBLT_BPP_MASK	0x00000003
#define	PR_BITBLT_1BPP		0x00000000
#define	PR_BITBLT_2BPP		0x00000001
#define	PR_BITBLT_4BPP		0x00000002
#define	PR_BITBLT_8BPP		0x00000003
#define	PR_BITBLT_COLORMODE	0x00000004	/* 0: Mono, 1: Color */

/* �X�v�[���̈�̐擪�A�h���X���C���[�W�i�[�̈�擪���狁�߂� */
#define PR_BITBLT_GETSPOOLADR(adr)	(adr - sizeof(int) * 5)
/* �C���[�W�i�[�̈�̐擪�A�h���X���X�v�[���擪���狁�߂� */
#define PR_BITBLT_GETIMAGEADR(adr)	(adr + sizeof(int) * 5)

/*
 *	for StretchBlt
 */
#define	PR_STRBLT_BPP_MASK	0x00000007 /* BPP ��ʃ}�X�N */
#define	PR_STRBLT_1BPP		0x00000000 /* 1BPP */
#define	PR_STRBLT_4BPP		0x00000001 /* 4BPP */
#define	PR_STRBLT_8BPP		0x00000002 /* 8BPP */
#define	PR_STRBLT_24BPP		0x00000003 /* 24BPP */
#define	PR_STRBLT_32BPP		0x00000004 /* 32BPP */
#define	PR_STRBLT_COLOR_MASK	0x00000038 /* �f�[�^��ʃ}�X�N */
#define	PR_STRBLT_MONO		0x00000000 /* �����f�[�^ */
#define	PR_STRBLT_RGB		0x00000008 /* RGB �f�[�^ */
#define	PR_STRBLT_KCMY		0x00000010 /* KCMY �f�[�^ */
#define	PR_STRBLT_INDEX_MASK	0x000000c0 /* Index Table ��ʃ}�X�N */
#define	PR_STRBLT_INDEX_OFF	0x00000000 /* Index Table ���� */
#define	PR_STRBLT_INDEX_ON	0x00000040 /* Index Table �L�� */
#define	PR_STRBLT_INDEX_EXIST	0x00000080 /* �@�\������ */
#define	PR_STRBLT_INDEX_REGIST	0x000000c0 /* �@�\������ */
#define	PR_STRBLT_INDEX_CMD2PR	6 /* �R�}���h�d�l����PR�d�l�ւ� shift */
#define	PR_STRBLT_REPEAT	0x00000200 /* �J��Ԃ��`�� */
#define	PR_STRBLT_SEQUENTIAL	0x00000400 /* �ʏ��� */
#define	PR_STRBLT_REVERSE	0x00000800 /* �ʏ��� */
#define	PR_STRBLT_CMOSTMASK	0x00003000 /* CMOST ���[�h�}�X�N */
#define	PR_STRBLT_ZOOMCMOST	0x00001000 /* CMOST ON */
#define	PR_STRBLT_EDMASK	0x0000c000 /* ED ���[�h�}�X�N */
#define	PR_STRBLT_ED		0x00004000 /* ED ON */
#define	PR_STRBLT_DATAALIGN	0x00030000 /* Data Align ��ʃ}�X�N */
#define	PR_STRBLT_NO_ALIGN	0x00000000 /* Align ���� */
#define	PR_STRBLT_ALIGN_1BYTE	0x00010000 /* 1Byte Align */
#define	PR_STRBLT_ALIGN_4BYTE	0x00020000 /* 4Byte Align */
#define	PR_STRBLT_THROUGH	0x00040000 /* Through gamma and toner limit */
#define	PR_STRBLT_RGB_ORDER	0x00000200 /* on:R,G,B  off:B,G,R */
#define	PR_STRBLT_EX_DATA	0x00000100 /* on:�g���f�[�^ off:�ʏ�f�[�^ */
#define	PR_IMAGE_ROTATE_MASK	0x30000000 /* �R�}���h���̉�]�t���O�p�}�X�N */
#define	PR_IMAGE_ROTATE_0	0x00000000 /* �C���[�W�f�[�^�����̂܂܉�]�����ɕ`�悷�� */
#define	PR_IMAGE_ROTATE_90	0x10000000 /* �C���[�W�f�[�^���E�X�O�x��]���`�悷�� */
#define	PR_IMAGE_ROTATE_180	0x20000000 /* �C���[�W�f�[�^���P�W�O�x��]���`�悷�� */
#define	PR_IMAGE_ROTATE_270	0x30000000 /* �C���[�W�f�[�^���E�Q�V�O�x��]���`�悷�� */

/* pr_bitmap_clip�p */
#define	PR_BITCLIP_DATAALIGN	0x00000003 /* Data Align ��ʃ}�X�N(�r�b�g�}�b�v�N���b�v) */
#define	PR_BITCLIP_ALIGN_1BYTE	0x00000001 /* 1Byte Align(�r�b�g�}�b�v�N���b�v) */
#define	PR_BITCLIP_ALIGN_4BYTE	0x00000002 /* 4Byte Align(�r�b�g�}�b�v�N���b�v) */

/* �X�v�[���̈�̐擪�A�h���X���C���[�W�i�[�̈�擪���狁�߂� */
#define	PR_STRBLT_GETSPOOLADR(adr)	(adr - sizeof(int) * 11)
/* �C���[�W�i�[�̈�̐擪�A�h���X���X�v�[���擪���狁�߂� */
#define	PR_STRBLT_GETIMAGEADR(adr)	(adr + sizeof(int) * 11)

/* �ʒm��� */
#define PR_VALUE_PROTID		0x00000001 /* �v���b�^ID */
#define PR_VALUE_PAGECOUNT	0x00000002 /* �t���[���쐬��v�������y�[�W���i�W���u���j */
#define PR_VALUE_PRINTCOUNT	0x00000003 /* ���ۂɃt���[�������v�������y�[�W���i�W���u���j */
#define PR_VALUE_USEDCOLOR	0x00000004

/* CMM �f�W�J���␳�e�[�u���T�C�Y */
#define PR_ACCENTPHOTOTABLESIZE 256

/* �������팸���[�h */
#define	PR_REDUCEMEMORY_MASK	0x00000001U
#define	PR_REDUCEMEMORY_OFF	0x00000000U
#define	PR_REDUCEMEMORY_MODE1	0x00000001U

/*
 *	for URF
 */
#define	PR_URF_MONO			0
#define	PR_URF_RGB			1
#define	PR_URF_ROTATE_0		0
#define	PR_URF_ROTATE_90	1
#define	PR_URF_ROTATE_180	2
#define	PR_URF_ROTATE_270	3

/*
 *	for Barcode
 */

/* Declaration for command param */

#define	PR_BC_CODE128		0x01
#define	PR_BC_JAN		0x02
#define	PR_BC_JANS		0x03
#define	PR_BC_UPCA		0x04
#define	PR_BC_UPCE		0x05
#define	PR_BC_NW7		0x06
#define	PR_BC_CODE39		0x07
#define	PR_BC_25ID		0x08
#define	PR_BC_25M		0x09
#define	PR_BC_25IL		0x0a
#define	PR_BC_CUSTOM		0x0b
#define	PR_BC_QR		0x0c
#define	PR_BC_EAN128		0x0d

/* Declaration for buffer data */

#define	PR_BC_MAX_PARAM		256
#define	PR_BC_MAX_DATA		259
#define	PR_BC_MAX_CHAR		(PR_BC_MAX_DATA * 2)

/* Declaration for CODE128 */

#define	PR_BC_CODE128_UNIT	11

#define	PR_BC_CODE128_START_A	103
#define	PR_BC_CODE128_START_B	104
#define	PR_BC_CODE128_START_C	105
#define	PR_BC_EAN128_AI1	106
#define	PR_BC_EAN128_AI2	107
#define	PR_BC_EAN128_AI3	108
#define	PR_BC_CODE128_STOP	109

#define PR_BC_CODE_SET_A	1
#define PR_BC_CODE_SET_B	2
#define PR_BC_CODE_SET_C	3

typedef struct pr_bc_code128
{
	unsigned short h;
	unsigned short uw;
	unsigned short fid;
	unsigned short dfid;
	unsigned short cw;
	unsigned short ch;
	unsigned char cg;
	unsigned short sum;
	char start;
} pr_bc_code128_t;

/* Declaration for JAN */

#define	PR_BC_JAN_UNIT	7

typedef struct pr_bc_jan
{
	unsigned short h;
	unsigned short uw;
	unsigned short fid;
	unsigned short dfid;
	unsigned short cw;
	unsigned short ch;
	unsigned char cg;
	unsigned short sum;
	char ns;
} pr_bc_jan_t;

/* Declaration for NW7 */

typedef struct pr_bc_nw7
{
	unsigned short h;
	unsigned short nbw;
	unsigned short nsw;
	unsigned short wbw;
	unsigned short wsw;
	unsigned char g;
	unsigned short fid;
	unsigned short dfid;
	unsigned short cw;
	unsigned short ch;
	unsigned char cg;
	unsigned short sum;
	char start;
	char stop;
} pr_bc_nw7_t;

/* Declaration for CUSTOM */

#define	PR_BC_CUSTOM_START	19
#define	PR_BC_CUSTOM_STOP	20

typedef struct pr_bc_custom
{
	unsigned char p;
} pr_bc_custom_t;

/* Declaration for QR */

#define	PR_BC_QR_DIR_V		0
#define	PR_BC_QR_DIR_H		1

typedef struct pr_bc_qr
{
	char m;
	unsigned short cell;
	char quality;
	char imode;
	unsigned char div;
	char dir;
} pr_bc_qr_t;

typedef struct pr_qrhead
{
	unsigned char div_mark;
	unsigned char div_numerator0;
	unsigned char div_numerator1;
	unsigned char div_denominator0;
	unsigned char div_denominator1;
	unsigned char parity_h;
	unsigned char parity_l;
	unsigned char separater1;
	unsigned char quality_level;
	unsigned char input_mode;
	unsigned char separater2;
} pr_bc_qrhead_t;

/* Declaration for EAN128 */
typedef struct pr_bc_ean128
{
	unsigned short h;
	unsigned short uw;
	unsigned short fid;
	unsigned short dfid;
	unsigned short cw;
	unsigned short ch;
	unsigned char cg;
	unsigned short sum;
	char start;
	char ai1;
	char ai2;
} pr_bc_ean128_t;

typedef union pr_barcode
{
	pr_bc_code128_t code128;
	pr_bc_jan_t jan;
	pr_bc_nw7_t nw7;
	pr_bc_custom_t custom;
	pr_bc_qr_t qr;
	pr_bc_ean128_t ean128;
} pr_barcode_t;

/*
 *	PR�p TRUE / FALSE
 */
#define	PR_TRUE  		 1
#define	PR_FALSE		 0

/* Graphics */
/* pr_scanlinepath�p�|�C���^�e�[�u���\���� */
typedef struct pr_spl_scanlinepath_data
{
	unsigned long size;		/* �p�X�̃T�C�Y */
	unsigned char *data;		/* �p�X�̃f�[�^�ւ̃|�C���^ */
} pr_scpath_data;

/* �f�B�U���\���� */
typedef struct pr_dit_info
{
	unsigned char *dit_ptr;		/* �f�B�U�̐擪�A�h���X */
	unsigned char x_size;			/* �� */
	unsigned char y_size;			/* ���� */
	unsigned char dit_order;		/* DIT_ORDER(�}�l) */
	unsigned short rearrange;		/* rearrange ID */
	unsigned char	e_flag_max;		/* engine flag for color level: 255 */
	unsigned char	e_flag_mid;		/* engine flag for color level: 1 to 254 */
} pr_dit_info_t;

/* �𑜓x�\���� */
typedef struct pr_reso_info
{
	unsigned int x;	/* �呖�������𑜓x */
	unsigned int y;	/* �����������𑜓x */
} pr_reso_info_t;

/* �𑜓x�\����(�r�b�g�Ƃ̑g����) */
typedef struct pr_resolution_info
{
	unsigned int x;		/* �呖�������𑜓x */
	unsigned int y;		/* �����������𑜓x */
	unsigned char bit;	/* �r�b�g�� */

	unsigned char pkgroup;      /* ����O���[�v */
	unsigned char dit_mode;     /* �f�B�U���[�h */
	unsigned char prtmode;       /* ������[�h(����/�W��/������) */

} pr_resolution_info_t;

/* ���ʋK���l���\���� */
typedef struct pr_tlimit_info
{
	pr_resolution_info_t reso;	/* �𑜓x&�[�� */
	int text;	/* �����I�u�W�F�N�g */
	int line;	/* ����I�u�W�F�N�g */
	int phot;	/* �ʐ^�I�u�W�F�N�g */
	int fill;	/* �h��Ԃ��I�u�W�F�N�g */
} pr_tlimit_info_t;


/* imaqual.dat�p���\���� */
typedef struct pr_bgucrinfo
{
	unsigned char *bg;  /* BG�e�[�u�� */
	unsigned char *ucr;/* UCR�e�[�u�� */
	unsigned char *bg_hgr;  /* BG�e�[�u��(���n) */
	unsigned char *ucr_hgr;/* UCR�e�[�u��(���n) */
	unsigned char *bg_compbk; /* for composite black */
	unsigned char *ucr_compbk;
} pr_bgucrinfo_t;

typedef struct pr_gcrinfo
{
	unsigned long flag;
	short *CB_bg;
	short *CB_ucr;
	short *CG_bg;
	short *CG_ucr;
	short *YG_bg;
	short *YG_ucr;
	short *MB_bg;
	short *MB_ucr;
	short *MR_bg;
	short *MR_ucr;
	short *YR_bg;
	short *YR_ucr;
} pr_gcrinfo_t;

typedef struct pr_dropinfo
{
	unsigned char *lit;/* �H�ʃf�[�^ */
	unsigned char *inv;/* �t�ϊ��e�[�u�� */
} pr_dropinfo_t;

typedef struct pr_dupgaminfo
{
	unsigned char *gam_front; /* �\�ʊ���  */
	unsigned char *gam_back; /* ���ʊ��� */
} pr_dupgaminfo_t;


typedef struct ExternalFontImage
{
	unsigned short regimgw;
	unsigned short regimgh;
	unsigned short offsetx;
	unsigned short offsety;
	unsigned char direct;
	unsigned char reserved[3];
	void *data;
} pr_external_fontimg_t;

/* IJ�f�o�C�X���\���� */
typedef struct pr_ij_info
{
	unsigned long headnum;		/* �w�b�h�� */
	unsigned long nozzlenum;	/* �m�Y���� */
	unsigned long nozzlepitch;	/* �m�Y���s�b�`�� */
	unsigned long overlapnum;	/* �I�[�o�[���b�v�� */
	unsigned long multipath;	/* �}���`�p�X�� */
	unsigned long direction;	/* �X�L��������:�Е����E�o���� */
	unsigned long compmode;		/* ���k�p�����[�^ */
	unsigned long bound;		/* ���o���h�C���[�W��boundary��:byte */
	unsigned long planemode;	/* �����w��:�������E�ʏ����E�_���� */
	unsigned long machineID;	/* �@�� ID */
	/* Alsace-P1	: 0x01010001	*/
	/* Alsace-P1W	: 0x01010011	*/
	/* Provence-P1	: 0x01020001	*/
	unsigned long supplement;	/* �ߑ��@�\ */
	/* �P�F�o��������  : 0x00000001	*/
	/* ��[�����x��    : 0x00000002	*/
	/* ��[�����x��    : 0x00000004	*/
	/* overlap������   : 0x00000008	*/
	/* �g�ݕt���덷����: 0x00000010	*/
	char dllname[260];		/* IJ Renderer �� DLL ��	*/
	unsigned char headid[4];	/* �w�b�h�΂�� ID �ԍ�	*/
	unsigned long ffeedline;	/* ��[�x������C��		*/
	unsigned long reserve[9];	/* �\��̈�			*/
} pr_ij_info_t;

/* �@����\���� */
typedef struct pr_dev_info
{
	/*
	 * �f�B�U���
	 * ���ۂ̐���
	 *  �𑜓x&�r�b�g�� x �f�B�U��ސ� x �v���[����
	 * �z�u����
	 *  for �𑜓x&�r�b�g�g�ݍ��킹��(���Ԃ�reso_set�Ŏw��)
	 *      for �f�B�U��ސ�(photo -> text -> cad -> graphics)
	 *        for �v���[����(C -> M -> Y -> K)
	 *          dither_info
	 * �ƂȂ�
	 */
	pr_dit_info_t *dither_info;

	/*
	 * �K���}���
	 * ��,�z�u���� dither_info �Ɠ��l
	 */
	unsigned char **gamma_info;

	unsigned char *font_address;	/* �f�o�C�X�t�H���g�̐擪�A�h���X */
	/* NULL�̏ꍇ�͎g�p���Ȃ� */
	unsigned long font_size;		/* �f�o�C�X�t�H���g�T�C�Y */

	long dither_cache;	/* �f�B�U�L���b�V���T�C�Y(byte �P��) */
	/*
	 * �S�F�����`�悷��ꍇ���}�l
	 * �P�o���h�`��ɕK�v�ȃo�C�g�� <= band_4C_thresh
	 * �Ȃ�S�F�����`�悷��(PR���T�|�[�g���Ă���ꍇ�̂ݗL��)
	 */
	int band_4C_thresh;
	/*
	 * PR���Ńo���f�B���O���鎞�ɕK�v�ȃp�����[�^
	 * �o���h������
	 * (bandsize * 100 * 1024) / (�S�o�C�g�A���C���C�����ꂽ)�y�[�W��
	 */
	int bandsize;
	int minbandheight;
	int maxbandheight;

	unsigned int resonum;	/* �T�|�[�g�𑜓x&�r�b�g�g�ݍ��킹��ސ�  */
	pr_resolution_info_t *reso_set;	/* �𑜓x&�r�b�g�g���� */
	/* reso������(=reso_set[resonum]) */
	int ndit;			/* dither��ސ� */
	int nplane;			/* �v���[����[1:mono, 4:color] */
	float bg_startp;		/* BG ���n�܂�J�n���x�� */
	float bg_slant;		/* BG �������z */
	float ucr_startp;		/* UCR ���n�܂�J�n���x�� */
	float ucr_slant;		/* UCR �������z */
	int soft_tsave;		/* �\�t�g�g�i�[�Z�[�u�̃T�|�[�g[1:����, 0:�Ȃ�] */
	float tsave_ratio;	/* �\�t�g�g�i�[�Z�[�u����(0.0 - 1.0) */

	int extend_soft_tsave;	/* �g���\�t�g�g�i�[�Z�[�u�̑Ή�[1:����, 0:�Ȃ�] */

	int toner_limit;	/* ���ʋK���̃T�|�[�g[1:����, 0:�Ȃ�] */
	unsigned int tlimit_num;	/* �@�킪�T�|�[�g���Ă��鑍�ʋK���l�̎�ސ� */
	/*
	 * ���ʋK���l�̃o���G�[�V����
	 * tlimit_num ������(=tlimit_val[tlimit_num])
	 * ��ԍŏ����f�t�H���g�l(�𑜓x,�[����0�ɃZ�b�g),
	 * ����ȊO�͓��ꃂ�[�h
	 */
	pr_tlimit_info_t *tlimit_val;

	/* �V�X�e���n���h���B����GPS�̂ݗL�� */
	long sys_handle;
	/*
	 * �W���u���Z�b�g�̒ʒm��M�ϐ�
	 * �O���ŕύX�����
	 * �ʒm���Ȃ��ꍇ��NULL
	 */
	int *notified_job_resetted;
	int *notified_forced_job_reset;

	/* CMM�Ŏg�p����v���t�@�C����� */
	void *profaddress;
	long profnumber;


	unsigned long flag;                     /* �t���O */
	unsigned int mode_num;                 /* �`�惂�[�h�̑��� */
	pr_bgucrinfo_t **bgucr_info;  /* BG/UCR��� */
	pr_gcrinfo_t *gcr_info;     /* WiShGCR */
	pr_gcrinfo_t *gcrhgr_info;     /* WiShGCR(���n) */
	pr_dropinfo_t **drop_info;   /* �H�ʕ␳��� */
	pr_dupgaminfo_t **dupgam_info; /* ���ʃ�������� */

	int pqtc;        /* �K�ʕ␳��ON/OFF(OFF:FALSE,ON:TRUE) */
} pr_dev_info_t;

typedef struct pr_preceding_info
{
	int job_id;			/* �W���uID */
	unsigned short resox;			/* X�����𑜓x (25.4mm������̃h�b�g��) */
	unsigned short resoy;			/* Y�����𑜓x (25.4mm������̃h�b�g��) */
	unsigned char depth;			/* �ʎq����(�K��) */
	unsigned char paper_type;		/* ���� */
	unsigned char color_count;	/* �F�� */
} pr_preceding_info_t;

typedef struct pr_job_info
{
	/* �e��t���O */
	int flag;
#define PR_JOBINFO_IS_DUPLEX			0x00000001
#define PR_JOBINFO_IS_IMAGE_SKIP		0x00000002
#define PR_JOBINFO_IS_PANELOUT_ROTATED	0x00000004
#define PR_JOBINFO_FULL_SLANT_ITALIC		0x00000008
#define PR_JOBINFO_XRGB_ACCUMULATION		0x00000010

	/* job_id */
	int job_id;

	/* gps_pageparam_t �̏�� */
	unsigned long para;		/* �ݒ肷��p�����[�^(�I���W�i���ł�flag) */
	unsigned short qty;		/* ������� */
	unsigned char outmode;	/* ������[�h */
	unsigned char binding;	/* �c�Ƃ�����*/
	short margin1v;	/* �c�Ƃ���(���ʑ�P��) */
	short margin1h;	/* ���Ƃ���(���ʑ�P��) */
	short margin2v;	/* �c�Ƃ���(���ʑ�Q��) */
	short margin2h;	/* ���Ƃ���(���ʑ�Q��) */
	unsigned char finish;		/* �d�����w�� */
	unsigned char upsidedown;	/* 180�x��] */
	unsigned char color_count;	/* �F�� */
	unsigned char paper_code;
	unsigned char paper_type;
	unsigned char slip;		/* �������[�h */
	unsigned char slip_tray;		/* �����g���C */
} pr_job_info_t;


typedef struct pr_page_info
{
	/* �e��t���O */
	int flag;
#define PR_PAGEINFO_IS_LANDSCAPE		0x00000001
#define PR_PAGEINFO_IS_SEF				0x00000002
#define PR_PAGEINFO_IS_CUSTOM			0x00000004
#define PR_PAGEINFO_IS_REVERSE			0x00000008
#define PR_PAGEINFO_LOAD_ENV			0x00000010

#define PR_PAGEINFO_HARDTONERSAVE_OFF	0x00000020

#define PR_PAGEINFO_IS_DUPLEX			0x00000040
#define PR_PAGEINFO_IGNORE_2NDFACE_DIR	0x00000080

	/* gps_pageinfo_t �̏�� */
	unsigned char paper_code;			/* �p���T�C�Y�E�R�[�h */
	unsigned short paper_width;		/* �t���[�T�C�Y���̗p���� */
	unsigned short paper_length;		/* �t���[�T�C�Y���̗p���� */
	unsigned long xoffset;			/* ���������I�t�Z�b�g */
	unsigned long yoffset;			/* ���������I�t�Z�b�g */
	unsigned char fci;				/* fci */
	unsigned char input_tray;			/* �����g���C */
	unsigned char paper_type;			/* ���� */
	unsigned char limitless_feed;		/* ���~�b�g���X����*/
	unsigned short paper_count;		/* �o�͖��� */
	unsigned char count_off;			/* �y�[�W�J�E���g���Ȃ� */
	unsigned long para;
#define PR_COUNT_ON			(0)	/* �J�E���g����  */
#define PR_COUNT_OFF			(1)	/* �J�E���g���Ȃ� */
	unsigned char outmode;	/* ������[�h*/
	unsigned char binding;	/* �c�Ƃ����� */
	short margin1v;	/* �c�Ƃ���(���ʑ�P��) */
	short margin1h;	/* ���Ƃ���(���ʑ�P��) */
	short margin2v;	/* �c�Ƃ���(���ʑ�Q��) */
	short margin2h;	/* ���Ƃ���(���ʑ�Q��) */

	/* gps_pagemode_t �̏�� */
	int memory_rotate;		/* ��������̉摜���� */

	unsigned long paper_width2;            /* �t���[�T�C�Y���̗p����(ulong) */
	unsigned long paper_length2;          /* �t���[�T�C�Y���̗p������(ulong) */


	unsigned char pkgroup;    /* ����O���[�v */
	unsigned char prtmode;    /* ������[�h */


	unsigned char page_shift;	/* �y�[�W�V�t�g */
	unsigned char eco_color;	/* �G�R�m�~�[�J���[���[�h */

} pr_page_info_t;

typedef struct pr_page_info_s
{
	unsigned long flag;			/* �ݒ肷��p�����[�^ */
	unsigned short output_tray;	/* �r���g���C */
	unsigned char limitless_exit;	/* �V�[�P���V�����X�^�b�N */
	unsigned char staple;			/* �X�e�[�v�� */
	unsigned char punch;				/* �p���` */
	unsigned char z_fold;			/* Z�܂� */
	unsigned char tonersave;		/* �g�i�[�Z�[�u */
	unsigned char jamrecovery;	/* �W�������J�o���[ */
	unsigned char face;			/* ����ʂ̎w�� */
#define PR_FACE_SINGLE	(0)		/* �Ж� */
#define PR_FACE_DPX1ST	(1)		/* ���ʑ�P�� */
#define PR_FACE_DPX2ND	(2)		/* ���ʑ�Q�� */
	unsigned char shift;			/* ���ԂŃV�t�g������^���Ȃ� */
	unsigned short paper_count;	/* �o�͖��� */
	unsigned char count_off;	/* �y�[�W�J�E���g�̎w�� */
	unsigned char slip;		/* �������[�h�̎w�� */
	unsigned char slip_tray;	/* �������[�h�̃g���C�ԍ��w�� */
	unsigned char cover;		/* �\�����[�h */
	unsigned char coverprint;	/* �\���摜����� */
	unsigned char cover_tray;	/* �\���g���C */
	unsigned char backcover;	/* ���\�����[�h */
	unsigned char backcoverprint;	/* ���\���摜����� */
	unsigned char backcovertray;	/* ���\���g���C */
} pr_page_info_s_t;

/* define the members of pr_page_info_shm_t */
typedef struct prMargin {
	signed short		margin1v;		/* �c�Ƃ���(���ʎ��A��1�� 0.1mm�P��) */
	signed short		margin1h;		/* ���Ƃ���(�@�@    �V �@ �@   ) */
	signed short		margin2v;		/* �c�Ƃ���(���ʑ�2�� 0.1mm�P��) */
	signed short		margin2h;		/* ���Ƃ���(�@�@  �V �@    ) */
} prMargin_t;

/* --�\��-- */
typedef struct prCover {
	unsigned char		mode;			/* ���[�h */
#define	PR_SHM_COVER_OFF		PR_COVER_OFF		/* �\���n�e�e */
#define	PR_SHM_COVER_FRONT		PR_COVER_FRONT		/* �����ĕ\���n�m */
#define	PR_SHM_COVER_BACK		PR_COVER_BACK		/* ����\���n�m */

	unsigned char		front;			/* �����ĕ\�����[�h */
#define	PR_SHM_COVER_OFF		PR_COVER_OFF		/* �\���Ɉ�����Ȃ� */
#define	PR_SHM_COVER_FRONT		PR_COVER_FRONT		/* �\���ɕЖʈ������ */
#define	PR_SHM_COVER_FRONT_D	PR_COVER_FRONT_D	/* �\���ɗ��ʈ������ */

	unsigned char		back;			/* ����\�����[�h */
#define	PR_SHM_COVER_OFF		PR_COVER_OFF		/* ���\���Ɉ�����Ȃ� */
#define	PR_SHM_COVER_BACK		PR_COVER_BACK		/* ���\���Ɉ������ */
#define	PR_SHM_COVER_BACK_R		PR_COVER_BACK_R		/* ���\�����]�r�� */
													/* (�摜���Жʂ̏ꍇ�̂�) */

	unsigned char		fcover_tray;	/* �\���g���C */
	unsigned char		bcover_tray;	/* ���\���g���C */
} prCover_t;

typedef struct prSlip {
	unsigned char	mode;
#define	PR_SHM_SLIP_OFF			PR_SLIP_OFF
#define	PR_SHM_SLIP_ON			PR_SLIP_ON
#define	PR_SHM_SLIP_PRINT		PR_SLIP_PRINT

	unsigned char	slip_tray;
} prSlip_t;

typedef struct prPartition {
	unsigned char	mode;
#define	PR_SHM_PARTITION_OFF		(0)
#define	PR_SHM_PARTITION_SORT		(1)
#define	PR_SHM_PARTITION_JOB		(2)

	unsigned short	cycle;
} prPartition_t;

typedef struct prPunch {
	unsigned char	pos;
#define	PR_SHM_PUNCH_OFF			(0)
#define	PR_SHM_PUNCH_LEFT			(1)
#define	PR_SHM_PUNCH_TOP			(2)
#define	PR_SHM_PUNCH_RIGHT			(3)
#define	PR_SHM_PUNCH_LEFT_TOP		(4)

	unsigned char	unit;
#define	PR_SHM_PUNCH_JP2			(0)
#define	PR_SHM_PUNCH_US2			(1)
#define	PR_SHM_PUNCH_US3			(2)
#define	PR_SHM_PUNCH_EU4			(3)
#define	PR_SHM_PUNCH_NEU4			(4)
#define	PR_SHM_PUNCH_JP1			(5)
#define	PR_SHM_PUNCH_MULTI			(6)
} prPunch_t;

typedef struct prW_Fold {
	unsigned char	w_fold;
#define	PR_SHM_W_FOLD_OFF			(0)		/* �܂�Ȃ� */
#define	PR_SHM_W_FOLD_ZIGZAG		(1)		/* �W���o���܂� */
#define	PR_SHM_W_FOLD_ZIGZAGFILE	(2)		/* �W���o���t�@�C���܂� */
#define	PR_SHM_W_FOLD_BASIC			(3)		/* ��{�܂� */
#define	PR_SHM_W_FOLD_BAG			(4)		/* �ܐ܂� */
#define	PR_SHM_W_FOLD_FILE			(5)		/* �t�@�C���܂� */
#define	PR_SHM_W_FOLD_CUSTOM1		(6)		/* ����܂�P */
#define	PR_SHM_W_FOLD_CUSTOM2		(7)		/* ����܂�Q */
#define	PR_SHM_W_FOLD_PROGRAM1		(8)		/* �v���O�����܂�P */
#define	PR_SHM_W_FOLD_PROGRAM2		(9)		/* �v���O�����܂�Q */
#define	PR_SHM_W_FOLD_PROGRAM3		(10)	/* �v���O�����܂�R */
#define	PR_SHM_W_FOLD_PROGRAM4		(11)	/* �v���O�����܂�S */
#define	PR_SHM_W_FOLD_ZIGZAGCUSTOM1	(12)	/* Special Fan Fold 1 */
#define	PR_SHM_W_FOLD_ZIGZAGCUSTOM2	(13)	/* Special Fan Fold 2 */
	
	unsigned long	zigzag_width;	/* �W���o���܂�̐܂蕝(0.1mm�P��) */
	unsigned char	w_punch;		/* �܂�@�p���` */
#define	PR_SHM_W_PUNCH_OFF			(0)		/* �܂�@�p���`�Ȃ� */
#define	PR_SHM_W_PUNCH_ON			(1)		/* �܂�@�p���`���� */

	unsigned char	w_edgefold;		/* ���܂� */
#define	PR_SHM_W_EDGEFOLD_OFF		(0)		/* ���܂�Ȃ� */
#define	PR_SHM_W_EDGEFOLD_ON		(1)		/* ���܂肠�� */
	
	unsigned char	w_machinestamp;
#define	PR_SHM_W_MACHINE_STAMP_OFF	(0)
#define	PR_SHM_W_MACHINE_STAMP_ON	(1)

	unsigned char	reserve[64];
} prW_Fold_t;

/* --�����O���{-- */
typedef struct prRingBind {
	unsigned char		ring_bind;	/* �����O���{�ݒ� */
#define	PR_SHM_RING_BIND_OFF		(0)		/* �����O���{���Ȃ� */
#define	PR_SHM_RING_BIND_ON			(1)		/* �����O���{���� */

	unsigned char		bind_pos;	/* �����O���{�Ԃ��ʒu */
#define	PR_SHM_RING_BIND_LEFT		(1)		/* ���Ԃ� */
#define	PR_SHM_RING_BIND_TOP		(2)		/* ��Ԃ� */
#define	PR_SHM_RING_BIND_RIGHT		(3)		/* �E�Ԃ� */

	unsigned char		bind_mode;	/* �����O���{���[�h�ݒ� */
#define	PR_SHM_RING_BIND_MODE_PUNCH	(1)		/* �p���`�̂݃��[�h */
#define	PR_SHM_RING_BIND_MODE_RING	(2)		/* �����O���{���[�h */

	unsigned char		reserve[5];
} prRingBind_t;

typedef struct prPerfectBind {
	unsigned char		perf_bind;	/* ����ݐ��{�ݒ� */
#define	PR_SHM_PERF_BIND_OFF		(0)		/* ����ݐ��{���Ȃ� */
#define	PR_SHM_PERF_BIND_ON			(1)		/* ����ݐ��{���� */

	unsigned char		bind_pos;	/* ����ݐ��{�Ԃ��ʒu */
#define	PR_SHM_PERF_BIND_LEFT		(1)		/* ���Ԃ� */
#define	PR_SHM_PERF_BIND_TOP		(2)		/* ��Ԃ� */
#define	PR_SHM_PERF_BIND_RIGHT		(3)		/* �E�Ԃ� */

	unsigned char		perf_trim;	/* ����ݐ��{�ْf�ݒ� */
#define	PR_SHM_PERF_TRIM_NONE		(0)		/* �ْf�Ȃ� */
#define	PR_SHM_PERF_TRIM_SINGLE		(1)		/* �����J�b�g */
#define	PR_SHM_PERF_TRIM_TRIPLE		(2)		/* �O�ӃJ�b�g */

	unsigned char		trim_mode;	/* ����ݐ��{�ْf���[�h�ݒ� */
#define	PR_SHM_PERF_TRIM_MODE_FINALSIZE	(1)		/* �d�オ��T�C�Y�w�� */
#define	PR_SHM_PERF_TRIM_MODE_CUTSIZE	(2)		/* �J�b�g�͈͎w�� */

	unsigned char		perf_paper_code;	/* ����ݐ��{ �����T�C�Y�R�[�h */
	unsigned long		perf_paper_width;	/* ����ݐ��{ �t���[�T�C�Y���̒�����(���������)�@ (0.1mm�P��) */
	unsigned long		perf_paper_length;	/* ����ݐ��{ �t���[�T�C�Y���̒�������(�呀�����) (0.1mm�P��) */
	unsigned char		perf_input_tray;	/* ����ݐ��{ ���������g���C */
	unsigned char		perf_cover_tray;	/* ����ݐ��{ �\���g���C */
#define	PR_TRAY_1			(1)		/* �{�̑�P�����g���C */
#define	PR_TRAY_2			(2)		/* �{�̑�Q�����g���C */
#define	PR_TRAY_3			(3)		/* �{�̑�R�����g���C */
#define	PR_TRAY_4			(4)		/* �{�̑�S�����g���C */
#define	PR_TRAY_5			(5)		/* �{�̑�T�����g���C */
#define	PR_TRAY_6			(6)		/* �{�̑�U�����g���C */
#define	PR_TRAY_7			(7)		/* �{�̑�V�����g���C */
#define	PR_TRAY_LCT			(0x0A)		/* ��ʋ����g���C */
#define	PR_TRAY_PERF_INSERTER		(0x12)		/* ����݃C���T�[�^��i */
#define	PR_TRAY_PERF_INSERTER2		(0x13)		/* ����݃C���T�[�^���i */

	unsigned char		perf_cover_mode;	/* ����ݐ��{ �\�����[�h */
#define	PR_SHM_PERF_COVER_BLANK		(0)	/* ����ݕ\���Ɉ�����Ȃ� */
#define	PR_SHM_PERF_COVER_PRINT_INSIDE	(1)	/* ����ݕ\���ɕЖʓ���������� */
#define	PR_SHM_PERF_COVER_PRINT_OUTSIDE	(2)	/* ����ݕ\���ɕЖʊO��������� */
#define	PR_SHM_PERF_COVER_PRINT_DUPLEX	(3)	/* ����ݕ\���ɗ��ʈ������ */

	long			perf_cover_vert;		/* ����ݐ��{ �\���쑜�V�n(�呖��)�ʒu���� (0.1mm�P��) */
	long			perf_cover_hori;		/* ����ݐ��{ �\���쑜����(������)�ʒu���� (0.1mm�P��) */
	long			perf_image_vert;		/* ����ݐ��{ �쑜�V�n(�呖��)�ʒu���� (0.1mm�P��) */
	long			perf_image_hori;		/* ����ݐ��{ �쑜����(������)�ʒu���� (0.1mm�P��) */
	unsigned char	perf_final_paper_code;	/* �d�オ��T�C�Y�w�莞 ���{�T�C�Y�R�[�h(paper.h �Q��) */
	unsigned long	perf_final_paper_width;	/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{��(���������)�@ (0.1mm�P��) */
	unsigned long	perf_final_paper_length;/* �d�オ��T�C�Y�w�莞 �t���[�T�C�Y���̐��{����(�呀�����) (0.1mm�P��) */
	long			perf_final_paper_vert;	/* �d�オ��T�C�Y�w�莞 �d�オ��T�C�Y�ʒu���� (0.1mm�P��) */
	unsigned long	perf_cut_paper_top;	 	/* �J�b�g�͈͎w�莞 �V�����@ (0.1mm�P��) */
	unsigned long	perf_cut_paper_bottom;	/* �J�b�g�͈͎w�莞 �n�����@ (0.1mm�P��) */
	unsigned long	perf_cut_paper_side;	/* �J�b�g�͈͎w�莞 �������� (0.1mm�P��) */
	unsigned char	reserve[32];			/* �@�\�ǉ��p */
} prPerfectBind_t;

/* --�}�[�L���O[COSMOS]-- */
typedef struct prMarking {
	unsigned char	markingtype;	/* ���ߍ��ݎ�� */
#define	PR_SHM_MARKING_OFF				(0)		/* ���ߍ��݂��Ȃ� */
#define	PR_SHM_MARKING_COPYGUARD		(1)		/* �s���R�s�[�K�[�h */
#define	PR_SHM_MARKING_SECURITY			(2)		/* �Z�L�����e�B�[�g���[�X */
#define	PR_SHM_MARKING_FALSIFICATION	(3)		/* �����񌟒m */
	
	/* �s���R�s�[�K�[�h�d�w���ߍ��� */
	unsigned long	pattern_type;		/* �n���� */
#define	PR_SHM_UCP_PATTERN_ON			(1<<0)	/* �}�~���� */
#define	PR_SHM_COPYGUARD_ON				(1<<1)	/* �s���R�s�[�K�[�h */
#define	PR_SHM_COPYGUARD_EX_ON			(1<<2)	/* �s���R�s�[�K�[�h�d�w */
#define	PR_SHM_SECURUTY_TRACE_ON		(1<<3)	/* �Z�L�����e�B�g���[�X */
#define	PR_SHM_PATTERN_AREA_FULL		(1<<4)	/* �n��̈�iON:�S�� OFF:�g�̂݁j */

	unsigned char	ucp_pattern_color;	/* �}�~�����̐F */
#define	PR_SHM_COLOR_K					(0)		/* �u���b�N */
#define	PR_SHM_COLOR_C					(1)		/* �V�A�� */
#define	PR_SHM_COLOR_M					(2)		/* �}�[���_ */	

	unsigned char	ucp_pattern_density;/* �}�~�����̔Z�x */
	unsigned char	ucp_fg_effect;		/* �}�~�����̌��ʁE�����F */
#define	PR_SHM_UCP_FG_EFFECT_WHITE		(0)		/* �n�߂�������Ă��� */
#define	PR_SHM_UCP_FG_EFFECT_VANISH		(1)		/* ������ */
#define	PR_SHM_UCP_FG_EFFECT_REMAIN		(2)		/* �����Ȃ� */

	unsigned char	ucp_bg_effect;		/* �}�~�����̌��ʁE�w�i�F */
#define	PR_SHM_UCP_BG_EFFECT_WHITE		(0)		/* �n�߂�������Ă��� */
#define	PR_SHM_UCP_BG_EFFECT_VANISH		(1)		/* ������ */
#define	PR_SHM_UCP_BG_EFFECT_REMAIN		(2)		/* �����Ȃ� */

	unsigned char	ucp_mask_type;		/* �}�~�����̖͗l */
#define	PR_SHM_MASK_TYPE_NONE			(0)		/* �͗l�Ȃ� */
#define	PR_SHM_MASK_TYPE_SEIGAIHA		(1)		/* �C�g */
#define	PR_SHM_MASK_TYPE_AMIME			(2)		/* �Ԗ� */
#define	PR_SHM_MASK_TYPE_KOUSHI1		(3)		/* �i�q�P */
#define	PR_SHM_MASK_TYPE_KOUSHI2		(4)		/* �i�q�Q */
#define	PR_SHM_MASK_TYPE_SHIPPOU		(5)		/* ���� */
#define	PR_SHM_MASK_TYPE_SYOKKOU		(6)		/* 再] */
#define	PR_SHM_MASK_TYPE_MATSUKAWABISHI	(7)		/* ����H */
#define	PR_SHM_MASK_TYPE_UROKO			(8)		/* �� */
#define	PR_SHM_MASK_TYPE_HIGAKI			(9)		/* �w�_ */
#define	PR_SHm_MASK_TYPE_KIKKOU			(10)	/* �T�b */

	unsigned short	device_ctl_type;	/* �s���R�s�[�K�[�h�d�w�̋@�퐧��R�[�h */
	unsigned char	trace_info;			/* �Z�L�����e�B�[�g���[�X���`�� */
#define	PR_SHM_CG_FORMAT_USERID			(0)		/* ���[�U�[�h�c */
#define	PR_SHM_CG_FORMAT_PAPERID		(1)		/* ���h�c */

	/* �Z�L�����e�B�[�g���[�X���ߍ��� */
	unsigned char	embed_mode;			/* ���ߍ��݃��[�h */
#define	PR_SHM_SE_MODE_IMAGEQUALITY		(0)		/* �掿�D�� */
#define	PR_SHM_SE_MODE_NORMAL			(1)		/* ���� */
#define	PR_SHM_SE_MODE_TOLERANCE		(2)		/* �ϐ��D�� */

	/* �����񌟒m���ߍ��� */
	unsigned char	pattern_density;	/* �n��Z�x */
#define	PR_SHM_FA_DENSITY_LIGHT			(0)		/* ���� */
#define	PR_SHM_FA_DENSITY_MIDDLE		(1)		/* ���� */
#define	PR_SHM_FA_DENSITY_DARK			(2)		/* �Z�� */

	unsigned char	pattern_status;		/* pattern status*/
#define	PR_SHM_FA_STATUS_NONE			(0)		/* no pattern */
#define	PR_SHM_FA_STATUS_ADDED			(1)		/* use pattern */
	
	unsigned short	errorcorrection_level;		/* ���������x�� */

	/* ���t���b�V���R�s�[ */
	unsigned char	refreshcopy;		/* ���ߍ��� */
#define	PR_SHM_RF_MODE_OFF				(0)		/* OFF */
#define	PR_SHM_RF_MODE_ON				(1)		/* ON */

	unsigned char	embedding_position;	/* ���ߍ��݈ʒu */
#define	PR_SHM_RF_POS_RIGHTTOP			(0)		/* �E�� */
#define	PR_SHM_RF_POS_LEFTTOP			(1)		/* ���� */
#define	PR_SHM_RF_POS_RIGHTBOTTOM		(2)		/* �E�� */
#define	PR_SHM_RF_POS_LEFTBOTTOM		(3)		/* ���� */

	unsigned long	embedding_pos_adj_vert;	/* ���ߍ��݈ʒu�����i�c�����j(0.1mm�P��) */
	unsigned long	embedding_pos_adj_horiz;/* ���ߍ��݈ʒu�����i�������j(0.1mm�P��) */
	unsigned char	barcode_format;		/* �o�[�R�[�h�`�� */
#define	PR_SHM_RF_FORMAT_QR				(0)		/* QR */
#define	PR_SHM_RF_FORMAT_PDF417			(1)		/* PDF417 */
#define	PR_SHM_RF_FORMAT_DATAMATRIX		(2)		/* DataMatrix */

	unsigned char	reserve[64];		/* �@�\�ǉ��p */
} prMarking_t;

/* --���@�\�܂�-- */
typedef struct prMultifold {
	unsigned char	multifold_kind;		/* ���@�\�܂��� */
#define	PR_SHM_MULTIFOLD_KIND_OFF				(0)	/* ���@�\�܂�Ȃ� */
#define	PR_SHM_MULTIFOLD_KIND_HALF				(1)	/* �Q�܂�i���܂�j */
#define	PR_SHM_MULTIFOLD_KIND_THIRDS_INSIDE		(2)	/* ���R�܂� */
#define	PR_SHM_MULTIFOLD_KIND_THIRDS_OUTSIDE	(3)	/* �O�R�܂� */
#define	PR_SHM_MULTIFOLD_KIND_QUART				(4)	/* �P���S�܂� */
#define	PR_SHM_MULTIFOLD_KIND_GATE				(5)	/* �ω��܂� */

	unsigned char	multifold_printposition;/* �󎚖� */
#define	PR_SHM_MULTIFOLD_PRINTPOSITION_INSIDE	(0)	/* ������ */
#define	PR_SHM_MULTIFOLD_PRINTPOSITION_OUTSIDE	(1)	/* �O���� */

	unsigned char	multifold_direction;	/* �J���i�܂�j���� */
#define	PR_SHM_MULTIFOLD_DIRECTION_LEFT			(0)	/* ���J�� */
#define	PR_SHM_MULTIFOLD_DIRECTION_BOTTOM		(1)	/* ���J�� */
#define	PR_SHM_MULTIFOLD_DIRECTION_RIGHT		(2)	/* �E�J�� */
#define	PR_SHM_MULTIFOLD_DIRECTION_TOP			(3)	/* ��J�� */

	unsigned char	multifold_sheets;		/* �d�ː܂� */
#define	PR_SHM_MULTIFOLD_SHEETS_OFF				(0)	/* �d�ː܂肵�Ȃ� */
#define	PR_SHM_MULTIFOLD_SHEETS_ON				(1)	/* �d�ː܂肷�� */

	unsigned char	reserve[16];			/* �@�\�ǉ��p */
} prMultifold_t;

/* --�g�����w��-- */
typedef struct prTrim {
	unsigned char	trim_mode;		/* �g���}�[�ْ̍f����ݒ� */
#define	PR_SHM_TRIM_OFF					(0)		/* �J�b�g�Ȃ� */
#define	PR_SHM_TRIM_SINGLECUT			(1)		/* �����J�b�g */

	unsigned long	side_edge_cut;	/* �g���}�[�̃J�b�g�ʁ@���������ݒ�(0.1mm�P��) */
	unsigned char	reserve[16];	/* �@�\�ǉ��p */
} prTrim_t; 

typedef struct pr_page_info_shm {
#define	PR_MAX_PAGEPARAM_SHM			8
	unsigned long flag[PR_MAX_PAGEPARAM_SHM];
	
	/* declaration for flag[0] */
#define	PR_SHM_QTY							(1 <<  0)
#define	PR_SHM_LIMITLESS_EXIT				(1 <<  1)
#define	PR_SHM_OUTPUT_TRAY					(1 <<  2)
#define	PR_SHM_OUTMODE						(1 <<  3)
#define	PR_SHM_BINDING						(1 <<  4)
#define	PR_SHM_MARGIN						(1 <<  5)
#define	PR_SHM_COVER						(1 <<  6)
#define	PR_SHM_SLIP							(1 <<  7)
#define	PR_SHM_PARTITION					(1 <<  8)
#define	PR_SHM_SHIFTOFF						(1 <<  9)
#define	PR_SHM_FINISH						(1 << 10)
#define	PR_SHM_STAPLE						(1 << 11)
#define	PR_SHM_PUNCH						(1 << 12)
#define	PR_SHM_Z_FOLD						(1 << 13)
#define	PR_SHM_W_FOLD						(1 << 14)
#define	PR_SHM_TONERSAVE					(1 << 15)
#define	PR_SHM_PRIORITY_TRAY				(1 << 16)
#define	PR_SHM_UPSIDEDOWN					(1 << 17)
#define	PR_SHM_COLOR						(1 << 18)
#define	PR_SHM_MIXEDDIRROT					(1 << 19)
#define	PR_SHM_JAMRECOVERY					(1 << 20)
#define	PR_SHM_ACS							(1 << 21)
#define	PR_SHM_STAMP						(1 << 22)
#define	PR_SHM_DUPLEXMODE					(1 << 23)
#define	PR_SHM_WHITESUPPRESS				(1 << 24)
#define	PR_SHM_COLORSEPARATE				(1 << 25)
#define	PR_SHM_RING							(1 << 26)
#define	PR_SHM_PERFECT						(1 << 27)
#define	PR_SHM_MARKING						(1 << 28)
#define	PR_SHM_MULTIFOLD					(1 << 29)
#define	PR_SHM_TRIM							(1 << 30)
#define	PR_SHM_FACEUP						(1 << 31)
	
	unsigned short	qty;
	unsigned char	limitless_exit;
#define	PR_SHM_LIMITLESS_OFF				PR_LIMITLESS_OFF
#define	PR_SHM_LIMITLESS_ON					PR_LIMITLESS_ON

	unsigned short	output_tray;
	unsigned char	outmode;
#define	PR_SHM_OUT_IMGINFO					PR_OUT_IMGINFO
#define	PR_SHM_OUT_SINGLE					PR_OUT_SINGLE
#define	PR_SHM_OUT_DUPLEX					PR_OUT_DUPLEX

	unsigned char	binding;
#define	PR_SHM_BIND_LEFT					PR_BIND_LEFT
#define	PR_SHM_BIND_TOP						PR_BIND_TOP
#define	PR_SHM_BIND_RIGHT					PR_BIND_RIGHT
#define	PR_SHM_BIND_LEFTRIGHT				PR_BIND_LEFTRIGHT
#define	PR_SHM_BIND_TOPBOTTOM				PR_BIND_TOPBOTTOM

	prMargin_t		Margin;
	prCover_t		Cover;
	prSlip_t		Slip;
	prPartition_t	Partition;
	unsigned char	shiftoff;
#define	PR_SHM_SHIFT_ON						PR_SHIFT_ON
#define	PR_SHM_SHIFT_OFF					PR_SHIFT_OFF
	
	unsigned char	finish;
#define	PR_SHM_SORT							PR_SORT
#define	PR_SHM_STACK						PR_STACK
#define	PR_SHM_ROT_SORT						PR_ROT_SORT
#define	PR_SHM_SHIFT_SORT					PR_SHIFT_SORT
	
	unsigned char	staple;
#define	PR_SHM_STAPLE_OFF					PR_STAPLE_OFF
#define	PR_SHM_STAPLE_LEFT_TOP_HORIZ		PR_STAPLE_LEFT_TOP_HORIZ
#define	PR_SHM_STAPLE_LEFT_TOP_VERT			PR_STAPLE_LEFT_TOP_VERT
#define	PR_SHM_STAPLE_LEFT_TOP_SLANT		PR_STAPLE_LEFT_TOP_SLANT
#define	PR_SHM_STAPLE_RIGHT_TOP_HORIZ		PR_STAPLE_RIGHT_TOP_HORIZ
#define	PR_SHM_STAPLE_RIGHT_TOP_VERT		PR_STAPLE_RIGHT_TOP_VERT
#define	PR_SHM_STAPLE_RIGHT_TOP_SLANT		PR_STAPLE_RIGHT_TOP_SLANT
#define	PR_SHM_STAPLE_DOUBLE_LEFT			PR_STAPLE_DOUBLE_LEFT
#define	PR_SHM_STAPLE_DOUBLE_TOP			PR_STAPLE_DOUBLE_TOP
#define	PR_SHM_STAPLE_DOUBLE_RIGHT			PR_STAPLE_DOUBLE_RIGHT
#define	PR_SHM_STAPLE_BOOKLET				PR_STAPLE_BOOKLET
#define	PR_SHM_STAPLE_LEFT_TOP				PR_STAPLE_LEFT_TOP
#define	PR_SHM_STAPLE_RIGHT_TOP				PR_STAPLE_RIGHT_TOP

	prPunch_t		Punch;
	unsigned char	z_fold;
#define	PR_SHM_Z_FOLD_OFF					PR_Z_FOLD_OFF
#define	PR_SHM_Z_FOLD_RIGHT					PR_Z_FOLD_RIGHT
#define	PR_SHM_Z_FOLD_BOTTOM				PR_Z_FOLD_BOTTOM
#define	PR_SHM_Z_FOLD_LEFT					PR_Z_FOLD_LEFT

	prW_Fold_t		w_fold;
	unsigned char	tonersave;
#define	PR_SHM_TONERSAVE_OFF				PR_TONERSAVE_OFF
#define	PR_SHM_TONERSAVE_MODE1				PR_TONERSAVE_MODE1
#define	PR_SHM_TONERSAVE_MODE2				PR_TONERSAVE_MODE2
#define	PR_SHM_TONERSAVE_SOFT				(3)	/* soft tonersave */

	unsigned char	priority_tray;
	unsigned char	upsidedown;
#define	PR_SHM_UPSIDE_UP					(0)
#define	PR_SHM_UPSIDE_DOWN					(1)

	unsigned char	color_count;
#define	PR_SHM_COLORCOUNT_MONO				PR_COLORCOUNT_MONO
#define	PR_SHM_COLORCOUNT_RK				PR_COLORCOUNT_RK
#define	PR_SHM_COLORCOUNT_CMYK				PR_COLORCOUNT_CMYK
#define	PR_SHM_COLORCOUNT_XRGB				(5)
#define	PR_SHM_COLORCOUNT_2C				(6)

	unsigned char	mixeddirrot;		/* for RPCS only*/
#define	PR_SHM_MIXED_OFF					(0)
#define	PR_SHM_MIXED_LEFT					(1)
#define	PR_SHM_MIXED_RIGHT					(2)

	unsigned char	jamrecovery;
#define	PR_SHM_JAMRECOVERY_OFF				PR_JAMRECOVERY_OFF
#define	PR_SHM_JAMRECOVERY_ON				PR_JAMRECOVERY_ON

	unsigned char	acs;
#define	PR_SHM_ACS_OFF						(0)	/* no ACS */
#define	PR_SHM_ACS_ON						(1)	/* do ACS*/

	unsigned char	stamp;
#define	PR_SHM_STAMP_OFF					(0)
#define	PR_SHM_STAMP_ON						(1)

	unsigned char	duplexmode;
#define	PR_SHM_DUPLEXMODE_OFF				(0)
#define	PR_SHM_DUPLEXMODE_ON				(1)

	unsigned char	white_suppress;
	unsigned char	color_separate;
	prRingBind_t	Ringbind;
	prPerfectBind_t	Perfectbind;
	prMarking_t		Marking;
	prMultifold_t	Multifold;
	prTrim_t		Trim;
	unsigned char	face_up;
#define	PR_SHM_FACEUP_OFF					(0)
#define	PR_SHM_FACEUP_ON					(1)

	/* declaration for flag[1] */
#define PR_SHM_SADDLE_FOLD	(1 << 2)

	unsigned char	saddle_fold;
#define PR_SHM_SADDLE_FOLD_OFF			(0)
#define PR_SHM_SADDLE_FOLD_INSIDE		(1)
#define PR_SHM_SADDLE_FOLD_OUTSIDE		(2)
#define PR_SHM_SADDLE_FOLD_SHEETS		(3)

} pr_page_info_shm_t;

typedef struct pr_gradation
{
	long x;		/* ���_��X���W */
	long y;		/* ���_��Y���W */
	long xgradient;	/* X���ω��ʂ̊�_ */
	long ygradient;	/* Y���ω��ʂ̊�_ */
	float *color;	/* �F���̐擪�A�h���X */
} pr_gradation_t;

/* �W���u���� */
#define	PR_DIVIDE_SUCCESS	(0)
#define	PR_JOBCLOSE_ERROR	(1)
#define	PR_UJOBSTART_ERROR	(2)
#define	PR_SETPARAM_ERROR	(3)
#define	PR_JOBSTART_ERROR	(4)
#define	PR_CANCEL		(-1)

typedef struct pr_ujob_info
{

	unsigned long flag;
	/* flag */
#define	PR_UPARAM_DATE			(1 << 0)
#define	PR_UPARAM_TIME			(1 << 1)
#define	PR_UPARAM_TRACKID			(1 << 2)
#define	PR_UPARAM_USERCODE			(1 << 3)
#define	PR_UPARAM_USERID			(1 << 4)
#define	PR_UPARAM_JOBID			(1 << 5)
#define	PR_UPARAM_JOBPASSWORD		(1 << 6)
#define	PR_UPARAM_DISPCHARSET		(1 << 7)
#define	PR_UPARAM_HOSTCHARSET		(1 << 8)
#define	PR_UPARAM_HOSTLOGINNAME		(1 << 9)
#define	PR_UPARAM_HOSTNAME			(1 << 10)
#define	PR_UPARAM_HOSTPORTNAME		(1 << 11)
#define	PR_UPARAM_HOSTPRINTERNAME		(1 << 12)
#define	PR_UPARAM_PROOFJOB			(1 << 13)
#define	PR_UPARAM_SECUREJOB			(1 << 14)
#define	PR_UPARAM_JOBNAME			(1 << 15)
#define	PR_UPARAM_OWNERID			(1 << 16)
#define	PR_UPARAM_PRINTINFO			(1 << 17)
#define	PR_UPARAM_AUTHUSERNAME		(1 << 18)
#define	PR_UPARAM_AUTHPASSWORD		(1 << 19)
#define	PR_UPARAM_AUTHENCRYPTMETHOD		(1 << 20)
#define	PR_UPARAM_AUTHENCRYPTSETTING	(1 << 21)
#define	PR_UPARAM_JOBPASSWORD_EXT		(1 << 22)
#define	PR_UPARAM_PAUSEDJOB			(1 << 23)
#define	PR_UPARAM_FORMJOB			(1 << 24)
#define	PR_UPARAM_AUTHUSERNAMECHARSET	(1 << 25)
#define	PR_UPARAM_AUTHPASSWORDCHARSET	(1 << 26)
#define	PR_UPARAM_NDISPCHARSET		(1 << 27)
#define	PR_UPARAM_NHOSTCHARSET		(1 << 28)
#define	PR_UPARAM_BILLINGCODE		(1 << 29)
#define	PR_UPARAM_REUSABLESTOREDJOB		(1 << 30)
#define	PR_UPARAM_PRINTAPPOINTEDTIME	(1 << 30)
#define	PR_UPARAM_EXT2				(1 << 31)

	unsigned long flag2;
	/* flag2 */
#define	PR_UPARAM_DRIVERKINDINFO	(1 << 0)
#define	PR_UPARAM_FOLDERNUMBER		(1 << 1)
#define	PR_UPARAM_FOLDERPASSWORD	(1 << 2)
#define	PR_UPARAM_EXT3				(1 << 31)

	struct
	{
		/* max length */
#define	PR_MAX_UPARAM_DATE_LEN			(10+1)
#define	PR_MAX_UPARAM_TIME_LEN			(8+1)
#define	PR_MAX_UPARAM_TRACKID_LEN			(20+1)
#define	PR_MAX_UPARAM_USERCODE_LEN		(8+1)
#define	PR_MAX_UPARAM_USERID_LEN			(8+1)
#define	PR_MAX_UPARAM_JOBID_LEN			(20+1)
#define	PR_MAX_UPARAM_JOBPASSWORD_LEN		(4+1)
#define	PR_MAX_UPARAM_DISPCHARSET_LEN		(63+1)
#define	PR_MAX_UPARAM_HOSTCHARSET_LEN		(63+1)
#define	PR_MAX_UPARAM_HOSTLOGINNAME_LEN		(20+1)
#define	PR_MAX_UPARAM_HOSTNAME_LEN		(63+1)
#define	PR_MAX_UPARAM_HOSTPORTNAME_LEN		(64+1)
#define	PR_MAX_UPARAM_HOSTPRINTERNAME_LEN	(64+1)
#define	PR_MAX_UPARAM_JOBNAME_LEN			(232+1)
#define	PR_MAX_UPARAM_OWNERID_LEN			(20+1)
#define	PR_MAX_UPARAM_PRINTINFO_LEN		(230+1)
#define	PR_MAX_UPARAM_AUTHUSERNAME_LEN		(217+1)
#define	PR_MAX_UPARAM_AUTHPASSWORD_LEN		(217+1)
#define	PR_MAX_UPARAM_JOBPASSWORD_EXT_LEN	(8+1)
#define	PR_MAX_UPARAM_BILLINGCODE_LEN		(32+2)
#define	PR_MAX_UPARAM_PRINTAPPOINTEDTIME_LEN	(5+1)
#define	PR_MAX_UPARAM_FOLDERPASSWORD_LEN	(8+1)

		unsigned char date[PR_MAX_UPARAM_DATE_LEN];
		unsigned char time[PR_MAX_UPARAM_TIME_LEN];
		unsigned char trackid[PR_MAX_UPARAM_TRACKID_LEN];
		unsigned char usercode[PR_MAX_UPARAM_USERCODE_LEN];
		unsigned char billingcode[PR_MAX_UPARAM_BILLINGCODE_LEN];
		unsigned char userid[PR_MAX_UPARAM_USERID_LEN];
		unsigned char jobid[PR_MAX_UPARAM_JOBID_LEN];
		unsigned char jobpassword[PR_MAX_UPARAM_JOBPASSWORD_LEN];
		unsigned char dispcharset[PR_MAX_UPARAM_DISPCHARSET_LEN];
		unsigned char hostcharset[PR_MAX_UPARAM_HOSTCHARSET_LEN];
		unsigned char hostloginname[PR_MAX_UPARAM_HOSTLOGINNAME_LEN];
		unsigned char hostname[PR_MAX_UPARAM_HOSTNAME_LEN];
		unsigned char hostportname[PR_MAX_UPARAM_HOSTPORTNAME_LEN];
		unsigned char hostprintername[PR_MAX_UPARAM_HOSTPRINTERNAME_LEN];
		unsigned char jobname[PR_MAX_UPARAM_JOBNAME_LEN];
		unsigned char ownerid[PR_MAX_UPARAM_OWNERID_LEN];
		unsigned char printinfo[PR_MAX_UPARAM_PRINTINFO_LEN];
		unsigned char authusername[PR_MAX_UPARAM_AUTHUSERNAME_LEN];
		unsigned char authpassword[PR_MAX_UPARAM_AUTHPASSWORD_LEN];
		int authencryptmethod;
		int authencryptsetting;
		unsigned char jobpassword_ext[PR_MAX_UPARAM_JOBPASSWORD_EXT_LEN];
		short authusernamecharset;
		short authpasswordcharset;
		short ndispcharset;
		short nhostcharset;
		unsigned char printappointedtime[PR_MAX_UPARAM_PRINTAPPOINTEDTIME_LEN];
		int driverkindinfo;
		/* driver kind info */
#define	PR_UPARAM_DRIVERKINDINFO_INBOX			(1)
#define	PR_UPARAM_DRIVERKINDINFO_PCL6			(2)
#define	PR_UPARAM_DRIVERKINDINFO_PCL6UD			(3)
#define	PR_UPARAM_DRIVERKINDINFO_PCL6UDGENERIC	(4)
#define	PR_UPARAM_DRIVERKINDINFO_PS				(5)
#define	PR_UPARAM_DRIVERKINDINFO_PSUD			(6)
#define	PR_UPARAM_DRIVERKINDINFO_PSUDGENERIC	(7)
#define	PR_UPARAM_DRIVERKINDINFO_RPCSBASIC		(8)
#define	PR_UPARAM_DRIVERKINDINFO_RPCSXPS		(9)
#define	PR_UPARAM_DRIVERKINDINFO_RPCS			(10)

		unsigned short foldernumber;
		unsigned char folderpassword[PR_MAX_UPARAM_FOLDERPASSWORD_LEN];
	} up;
} pr_ujob_info_t;

#define	PR_UJOB_UNDEF	(0)	/* �R�}���h�Ŗ����I�ɒ�`����Ă��Ȃ��ꍇ */
#define	PR_UJOB_PJL	(1)	/* PJL��JOB�R�}���h�Œ�`���ꂽ�W���u�̏ꍇ */
#define	PR_UJOB_RPDL	(2)	/* RPDL�̃W���u�R�}���h�ɂĒ�`���ꂽ�W���u�̏ꍇ */
#define	PR_UJOB_HEXDUMP	(11)	/* HEXDUMP */

#define	PR_MAX_UJOB_ATTR_NAME_LEN	80

typedef struct pr_ujob_attr
{
	unsigned long flag;
#define	PR_UJOB_ATTR_NAME	(1 << 0)

	char name[PR_MAX_UJOB_ATTR_NAME_LEN + 1];	/* PJL��JOB/EOJ�R�}���h�Œʒm�����NAME */

} pr_ujob_attr_t;

typedef struct pr_dividejob_info
{
	int njobid;	/* �l�b�g�W���uID�B�Q�ƁB */
	pr_ujob_info_t *ujob_info;	/* ���[�U�[�W���u�p�����[�^�\���� */
	int kind;		/* �W���u�̎�� */
	pr_ujob_attr_t *ujob_attr;	/* ���[�U�[�W���u�A�g���r���[�g�\���� */
} pr_dividejob_info_t;

/*
 *	pr_setmargin()�p
 *	�]���V�t�g���@
 */
#define	PR_MARGIN_MASK		0x03
#define	PR_MARGIN_MASK_TB	0x01	/* �㉺(����) */
#define	PR_MARGIN_MASK_LR	0x02	/* ���E(����) */

/* �o�͐� */
#define	PR_OUT_FRAME	0	/* �t���[��������(�f�t�H���g) */
#define	PR_OUT_SPOOLER	1	/* �X�v�[�� */
#define	PR_OUT_FILE	2	/* �t�@�C�� */
#define	PR_OUT_MEMORY	3	/* ������ */
#define	PR_OUT_RASTER	4	/* �t�@�C��(Raster�`��) */

/* �G���[��� */
#define	PR_ERRINFO_RENDERINIT    	0x1001	  /* render_init() error */
#define	PR_ERRINFO_RENDERINITPAGE	0x1002	  /* render_init_page() error */
#define	PR_ERRINFO_GEINIT		0x1003	  /* ge_initialize() error */
#define	PR_ERRINFO_INITGRAPHICS 	0x1004	  /* init_graphics() error */
#define	PR_ERRINFO_POSITION     	0x2001	  /* illegal command position */
#define	PR_ERRINFO_BANDLINES    	0x3005	  /* livalid band lines */
#define	PR_ERRINFO_GMALLOC		0x4011	  /* gmAlloc() error */
#define	PR_ERRINFO_FMALLOC		0x4021	  /* fmAlloc() error */
#define	PR_ERRINFO_OMALLOC		0x4031	  /* omAlloc() error */
#define	PR_ERRINFO_BRUSHSIZE    	0x4041	  /* Brush area not allocated */
#define	PR_ERRINFO_SPOOLSIZE    	0x4042	  /* Spool area not allocated */
#define	PR_ERRINFO_OBJECTSIZE   	0x4043	  /* Object area not allocated */
#define	PR_ERRINFO_GRAPHICSIZE  	0x4044	  /* Graphic area too small */
#define	PR_ERRINFO_FONTSIZE     	0x4045	  /* Font area not allocated */
#define	PR_ERRINFO_FRAMECREATE  	0x7001	  /* FrameCreate */
#define	PR_ERRINFO_FRAMEPRINT   	0x7002	  /* FramePrint */
#define	PR_ERRINFO_FRAMECLOSE   	0x7003	  /* FrameClose */
#define	PR_ERRINFO_GETBAND		0x7004	  /* GetBand */
#define	PR_ERRINFO_FLUSHBAND    	0x7005	  /* FlushBand */

/*
 * pr_job_info_t�̃����o���
 */
/* �ݒ肷��p�����[�^ */
#define	PR_PARAM_QTY 			(1 <<  1)	/* ������� */
#define	PR_PARAM_LIMITLESS_EXIT		(1 <<  2)	/* ���~�b�g���X�r�� */
#define	PR_PARAM_OUTPUT_TRAY		(1 <<  3)	/* �r���g���C */
#define	PR_PARAM_OUTMODE		(1 <<  4)	/* ������[�h */
#define	PR_PARAM_BINDING		(1 <<  5)	/* �c�Ƃ����� */
#define	PR_PARAM_MARGIN1V		(1 <<  6)	/* �c�Ƃ���(���ʑ�P��) */
#define	PR_PARAM_MARGIN1H		(1 <<  7)	/* ���Ƃ���(���ʑ�P��) */
#define	PR_PARAM_MARGIN2V		(1 <<  8)	/* �c�Ƃ���(���ʑ�Q��) */
#define	PR_PARAM_MARGIN2H		(1 <<  9)	/* ���Ƃ���(���ʑ�Q��) */
#define	PR_PARAM_COVER			(1 << 10)	/* �\�����[�h */
#define	PR_PARAM_COVERPRINT		(1 << 11)	/* �\���摜����� */
#define	PR_PARAM_SLIP			(1 << 12)	/* �������[�h */
#define	PR_PARAM_SHIFTOFF		(1 << 13)	/* �W���u�P�ʂ̃V�t�g */
#define	PR_PARAM_FINISH			(1 << 14)	/* �d�����w�� */
#define	PR_PARAM_STAPLE			(1 << 15)	/* �X�e�[�v�� */
#define	PR_PARAM_PUNCH			(1 << 16)	/* �p���` */
#define	PR_PARAM_COVERTRAY		(1 << 17)	/* �\���g���C */
#define	PR_PARAM_SLIPTRAY		(1 << 18)	/* �����g���C */
#define	PR_PARAM_TONERSAVE		(1 << 23)	/* �g�i�[�Z�[�u */
#define	PR_PARAM_PRIORITY_TRAY		(1 << 24)	/* �D�拋���g���C */
#define	PR_PARAM_UPSIDEDOWN		(1 << 25)	/* 180�x��] */
#define	PR_PARAM_COLORCOUNT		(1 << 26)	/* �F�� */
#define	PR_PARAM_DOCBODYTRAY		(1 << 27)	/* ���g�p */
#define	PR_PARAM_MIXEDDIRROT		(1 << 28)	/* �p���������ݎ��̉�]���� */
#define	PR_PARAM_1STPAGEORDER		(1 << 29)	/* ���g�p */
#define	PR_PARAM_JAMRECOVERY		(1 << 30)	/* �W�����E���J�o���[ */
#define	PR_PARAM_ACS			(1 << 31)	/* ACS */

#define	PR_PARAM_PAGE_SHIFT		(1 << 20)	/* �y�[�W�V�t�g(PR�Ǝ���`) */
#define PR_PARAM_ECO_COLOR		(1 << 21)	/* �G�R�m�~�[�J���[(PR�Ǝ���`) */

/* ������[�h */
#define	PR_OUT_IMGINFO	(0)		/* �摜�������̎w��ɏ]��*/
#define	PR_OUT_SINGLE	(1)		/* �Жʈ�� */
#define	PR_OUT_DUPLEX	(2)		/* ���ʈ�� */
/* �Ԃ����� */
#define	PR_BIND_LEFT		(0)		/* ���Ԃ� */
#define	PR_BIND_TOP		(1)		/* ��Ԃ� */
#define	PR_BIND_RIGHT		(2)		/* �E�Ԃ� */
#define	PR_BIND_BOTTOM		(3)		/* ���Ԃ� */
#define	PR_BIND_LEFTRIGHT	(4)		/* ���E�Ԃ� */
#define	PR_BIND_TOPBOTTOM	(5)		/* �㉺�Ԃ� */

#define PR_BIND_SUCCESS		(0)		/* ���� */
#define PR_BIND_BUSY		(-1)		/* �r�W�[ */
#define PR_BIND_FAILURE		(-2)		/* ���s */
/* �d�����w�� */
#define	PR_SORT			(1)		/* �\�[�g */
#define	PR_STACK		(2)		/* �X�^�b�N */
#define	PR_ROT_SORT		(3)		/* ��]�\�[�g */
#define	PR_SHIFT_SORT		(4)		/* �V�t�g�\�[�g */
/* �F�� */
#define PR_COLORCOUNT_MONO	(1)	/* �P�F(�P�F�v���[��) */
#define PR_COLORCOUNT_RK	(2)	/* �ԍ� */
#define PR_COLORCOUNT_CMYK	(4)	/* �S�F(�b�l�x�j) */
#define PR_COLORCOUNT_RGB_PIXEL_ORDER	(8)	/* �w�q�f�a�_���� */
#define PR_SLIP_OFF		(0x00)	/* �������Ȃ� */
#define PR_SLIP_ON		(0x01)	/* �������� */
#define PR_SLIP_PRINT		(0x11)	/* �������Ȃ� */

/*
 * pr_page_info_t�̃����o���
 */
/* �����g���C */
#define		PR_TRAY_MAN		(0)		/* �荷�������g���C */
#define		PR_TRAY_1		(1)		/* ��P�����g���C */
#define		PR_TRAY_2		(2)		/* ��Q�����g���C */
#define		PR_TRAY_3		(3)		/* ��R�����g���C */
#define		PR_TRAY_4		(4)		/* ��S�����g���C */
#define		PR_TRAY_5		(5)		/* ��T�����g���C */
#define		PR_TRAY_6		(6)		/* ��U�����g���C */
#define		PR_TRAY_7		(7)		/* ��V�����g���C */
#define		PR_TRAY_LCT		(0x0A)		/* ��ʋ����g���C */
#define		PR_TRAY_AUTO		(0x0F)		/* �����p���I�� */
#define		PR_TRAY_INSERTER	(0x10)		/* �����}�����j�b�g */
#define		PR_TRAY_INSERTER2	(0x11)		/* �����}�����j�b�g�i�Q�i�j */
/* ���� */
#define		PR_PAPER_AUTO		(0x00)          /* ����w��Ȃ� */
#define		PR_PAPER_NORMAL		(0x01)          /* ���ʎ� */
#define		PR_PAPER_RECYCLE	(0x02)          /* �Đ��� */
#define		PR_PAPER_SPECIAL	(0x03)          /* ���ꎆ */
#define		PR_PAPER_TRACING	(0x04)          /* �g���[�V���O�� */
#define		PR_PAPER_OHP		(0x05)          /* OHP */
#define		PR_PAPER_LABEL		(0x06)          /* ���x���� */
#define		PR_PAPER_BOND		(0x07)          /* �{���h�� */
#define		PR_PAPER_CARDSTOCK	(0x08)          /* �J�[�h�X�g�b�N */
#define		PR_PAPER_CARDBOARD	(0x09)          /* ���� */
#define		PR_PAPER_PREPRINT	(0x0A)          /* ����ςݎ� */
#define		PR_PAPER_LETTER_HEAD	(0x0B)          /* ���^�[�w�b�h�� */
#define		PR_PAPER_LETTER_PUNCH	(0x0C)
#define		PR_PAPER_TAB		(0x0D)          /* �^�u�� */
#define		PR_PAPER_COLOR		(0x0E)          /* �F�� */
#define		PR_PAPER_NORMAL2ND	(0x0F)          /* ���ʎ�(����) */
#define		PR_PAPER_CARDBOARD2ND	(0x10)          /* ����(����) */
#define		PR_PAPER_THIN		(0x11)          /* ���� */
#define		PR_PAPER_GLOSSY        	(0x12)          /* ���� */
#define		PR_PAPER_USED          	(0x13)          /* �����i�g�p�ς݁j */
#define		PR_PAPER_POSTCARD      	(0x14)          /* �n�K�L */
#define		PR_PAPER_POSTCARD2ND   	(0x15)          /* �n�K�L(����) */
#define		PR_PAPER_CARDBOARD2		(0x16)
#define		PR_PAPER_FILM		(0x17)
#define		PR_PAPER_INKPOST		(0x18)
#define		PR_PAPER_HG_NORMAL		(0x19)
#define		PR_PAPER_ENVELOPE		(0x1A)
#define		PR_PAPER_CARDBOARD3		(0x1B)
#define		PR_PAPER_SPECIAL2		(0x1C)
#define		PR_PAPER_SPECIAL3		(0x1D)
#define		PR_PAPER_MIDDLETHICK	(0x1E)
#define		PR_PAPER_COATED		(0x1F)
#define		PR_PAPER_CARDBOARD2REV	(0x20)
#define		PR_PAPER_CARDBOARD3REV	(0x21)
#define		PR_PAPER_NORMAL2		(0x22)
#define		PR_PAPER_THICKGLOSSY	(0x23)
#define		PR_PAPER_SPECIAL4		(0x24)
#define		PR_PAPER_SPECIAL5		(0x25)
#define		PR_PAPER_SPECIAL6		(0x26)
#define		PR_PAPER_USER_DEF1		(0x30)
#define		PR_PAPER_USER_DEF2		(0x31)
#define		PR_PAPER_USER_DEF3		(0x32)
#define		PR_PAPER_USER_DEF4		(0x33)
#define		PR_PAPER_USER_DEF5		(0x34)
#define		PR_PAPER_USER_DEF6		(0x35)
#define		PR_PAPER_USER_DEF7		(0x36)
#define		PR_PAPER_USER_DEF8		(0x37)
#define		PR_PAPER_USER_DEF0		(0x38)
#define		PR_PAPER_COLOR1        	(0x40)          /* �F���P */
#define		PR_PAPER_COLOR2        	(0x41)          /* �F���Q */
#define		PR_PAPER_COLOR_YELLOW	(0x51)          /* �� */
#define		PR_PAPER_COLOR_GREEN	(0x52)          /* �� */
#define		PR_PAPER_COLOR_BLUE	(0x53)          /* �� */
#define		PR_PAPER_COLOR_PURPLE	(0x54)          /* �� */
#define		PR_PAPER_COLOR_IVORY	(0x55)          /* �A�C�{���[ */
#define		PR_PAPER_COLOR_ORANGE	(0x56)          /* �� */
#define		PR_PAPER_COLOR_PINK	(0x57)          /* �� */
#define		PR_PAPER_COLOR_RED	(0x58)          /* �� */
#define		PR_PAPER_COLOR_GRAY	(0x59)          /* �D */
#define		PR_PAPER_GLOSSY_COATED		(0x60)	/* glossy coated */
#define		PR_PAPER_THICK_GLOSSY_COATED	(0x61)	/* thick glossy coated */
#define		PR_PAPER_MAT_COATED		(0x62)	/* matt coated */
#define		PR_PAPER_THICK_MAT_COATED	(0x63)	/* thick matt coated */
#define		PR_PAPER_WATER_PROOF		(0x64)	/* waterproof */
#define		PR_PAPER_CARDBOARD4		(0x65)	/* cardboard 4 */
#define		PR_PAPER_CARDBOARD4REV		(0x66)	/* cardboard 4 (reverse) */
#define		PR_PAPER_COATED_HIGH_GLOSSY	(0x67)	/* high glossy coated */
#define		PR_PAPER_SEMIGLOSSY		(0x68)
#define		PR_PAPER_INKJETPLAIN	(0x69)
#define		PR_PAPER_MATFILM		(0x6C)
#define		PR_PAPER_CADCOATED		(0x6D)
#define		PR_PAPER_NONE			(0x80)
#define		PR_PAPER_USER_DEF9			(0x81)	/* ���[�U�w��X(IMSS) */
#define		PR_PAPER_USER_DEF10			(0x82)	/* ���[�U�w��P�O(IMSS) */
#define		PR_PAPER_USER_DEF11			(0x83)	/* ���[�U�w��P�P(IMSS) */
#define		PR_PAPER_USER_DEF12			(0x84)	/* ���[�U�w��P�Q(IMSS) */
#define		PR_PAPER_USER_DEF13			(0x85)	/* ���[�U�w��P�R(IMSS) */
#define		PR_PAPER_USER_DEF14			(0x86)	/* ���[�U�w��P�S(IMSS) */
#define		PR_PAPER_USER_DEF15			(0x87)	/* ���[�U�w��P�T(IMSS) */
#define		PR_PAPER_USER_DEF16			(0x88)	/* ���[�U�w��P�U(IMSS) */
#define		PR_PAPER_USER_DEF17			(0x89)	/* ���[�U�w��P�V(IMSS) */
#define		PR_PAPER_USER_DEF18			(0x8A)	/* ���[�U�w��P�W(IMSS) */
#define		PR_PAPER_USER_DEF19			(0x8B)	/* ���[�U�w��P�X(IMSS) */
#define		PR_PAPER_USER_DEF20			(0x8C)	/* ���[�U�w��Q�O(IMSS) */
#define		PR_PAPER_USER_DEF21			(0x8D)	/* ���[�U�w��Q�P(IMSS) */
#define		PR_PAPER_USER_DEF22			(0x8E)	/* ���[�U�w��Q�Q(IMSS) */
#define		PR_PAPER_USER_DEF23			(0x8F)	/* ���[�U�w��Q�R(IMSS) */
#define		PR_PAPER_USER_DEF24			(0x90)	/* ���[�U�w��Q�S(IMSS) */
#define		PR_PAPER_USER_DEF25			(0x91)	/* ���[�U�w��Q�T(IMSS) */
#define		PR_PAPER_USER_DEF26			(0x92)	/* ���[�U�w��Q�U(IMSS) */
#define		PR_PAPER_USER_DEF27			(0x93)	/* ���[�U�w��Q�V(IMSS) */
#define		PR_PAPER_USER_DEF28			(0x94)	/* ���[�U�w��Q�W(IMSS) */
#define		PR_PAPER_USER_DEF29			(0x95)	/* ���[�U�w��Q�X(IMSS) */
#define		PR_PAPER_USER_DEF30			(0x96)	/* ���[�U�w��R�O(IMSS) */
#define		PR_PAPER_USER_DEF31			(0x97)	/* ���[�U�w��R�P(IMSS) */
#define		PR_PAPER_USER_DEF32			(0x98)	/* ���[�U�w��R�Q(IMSS) */
#define		PR_PAPER_USER_DEF33			(0x99)	/* ���[�U�w��R�R(IMSS) */
#define		PR_PAPER_USER_DEF34			(0x9A)	/* ���[�U�w��R�S(IMSS) */
#define		PR_PAPER_USER_DEF35			(0x9B)	/* ���[�U�w��R�T(IMSS) */
#define		PR_PAPER_USER_DEF36			(0x9C)	/* ���[�U�w��R�U(IMSS) */
#define		PR_PAPER_USER_DEF37			(0x9D)	/* ���[�U�w��R�V(IMSS) */
#define		PR_PAPER_USER_DEF38			(0x9E)	/* ���[�U�w��R�W(IMSS) */
#define		PR_PAPER_USER_DEF39			(0x9F)	/* ���[�U�w��R�X(IMSS) */
#define		PR_PAPER_USER_DEF40			(0xA0)	/* ���[�U�w��S�O(IMSS) */
#define		PR_PAPER_USER_DEF41			(0xA1)	/* ���[�U�w��S�P(IMSS) */
#define		PR_PAPER_USER_DEF42			(0xA2)	/* ���[�U�w��S�Q(IMSS) */
#define		PR_PAPER_USER_DEF43			(0xA3)	/* ���[�U�w��S�R(IMSS) */
#define		PR_PAPER_USER_DEF44			(0xA4)	/* ���[�U�w��S�S(IMSS) */
#define		PR_PAPER_USER_DEF45			(0xA5)	/* ���[�U�w��S�T(IMSS) */
#define		PR_PAPER_USER_DEF46			(0xA6)	/* ���[�U�w��S�U(IMSS) */
#define		PR_PAPER_USER_DEF47			(0xA7)	/* ���[�U�w��S�V(IMSS) */
#define		PR_PAPER_USER_DEF48			(0xA8)	/* ���[�U�w��S�W(IMSS) */
#define		PR_PAPER_USER_DEF49			(0xA9)	/* ���[�U�w��S�X(IMSS) */
#define		PR_PAPER_USER_DEF50			(0xAA)	/* ���[�U�w��T�O(IMSS) */
#define		PR_PAPER_USER_DEF51			(0xAB)	/* ���[�U�w��T�P(IMSS) */
#define		PR_PAPER_USER_DEF52			(0xAC)	/* ���[�U�w��T�Q(IMSS) */
#define		PR_PAPER_USER_DEF53			(0xAD)	/* ���[�U�w��T�R(IMSS) */
#define		PR_PAPER_USER_DEF54			(0xAE)	/* ���[�U�w��T�S(IMSS) */
#define		PR_PAPER_USER_DEF55			(0xAF)	/* ���[�U�w��T�T(IMSS) */
#define		PR_PAPER_USER_DEF56			(0xB0)	/* ���[�U�w��T�U(IMSS) */
#define		PR_PAPER_USER_DEF57			(0xB1)	/* ���[�U�w��T�V(IMSS) */
#define		PR_PAPER_USER_DEF58			(0xB2)	/* ���[�U�w��T�W(IMSS) */
#define		PR_PAPER_USER_DEF59			(0xB3)	/* ���[�U�w��T�X(IMSS) */
#define		PR_PAPER_USER_DEF60			(0xB4)	/* ���[�U�w��U�O(IMSS) */
#define		PR_PAPER_USER_DEF61			(0xB5)	/* ���[�U�w��U�P(IMSS) */
#define		PR_PAPER_USER_DEF62			(0xB6)	/* ���[�U�w��U�Q(IMSS) */
#define		PR_PAPER_USER_DEF63			(0xB7)	/* ���[�U�w��U�R(IMSS) */
#define		PR_PAPER_USER_DEF64			(0xB8)	/* ���[�U�w��U�S(IMSS) */
#define		PR_PAPER_USER_DEF65			(0xB9)	/* ���[�U�w��U�T(IMSS) */
#define		PR_PAPER_USER_DEF66			(0xBA)	/* ���[�U�w��U�U(IMSS) */
#define		PR_PAPER_USER_DEF67			(0xBB)	/* ���[�U�w��U�V(IMSS) */
#define		PR_PAPER_USER_DEF68			(0xBC)	/* ���[�U�w��U�W(IMSS) */
#define		PR_PAPER_USER_DEF69			(0xBD)	/* ���[�U�w��U�X(IMSS) */
#define		PR_PAPER_USER_DEF70			(0xBE)	/* ���[�U�w��V�O(IMSS) */
#define		PR_PAPER_USER_DEF71			(0xBF)	/* ���[�U�w��V�P(IMSS) */
#define		PR_PAPER_USER_DEF72			(0xC0)	/* ���[�U�w��V�Q(IMSS) */
#define		PR_PAPER_USER_DEF73			(0xC1)	/* ���[�U�w��V�R(IMSS) */
#define		PR_PAPER_USER_DEF74			(0xC2)	/* ���[�U�w��V�S(IMSS) */
#define		PR_PAPER_USER_DEF75			(0xC3)	/* ���[�U�w��V�T(IMSS) */
#define		PR_PAPER_USER_DEF76			(0xC4)	/* ���[�U�w��V�U(IMSS) */
#define		PR_PAPER_USER_DEF77			(0xC5)	/* ���[�U�w��V�V(IMSS) */
#define		PR_PAPER_USER_DEF78			(0xC6)	/* ���[�U�w��V�W(IMSS) */
#define		PR_PAPER_USER_DEF79			(0xC7)	/* ���[�U�w��V�X(IMSS) */
#define		PR_PAPER_USER_DEF80			(0xC8)	/* ���[�U�w��W�O(IMSS) */
#define		PR_PAPER_USER_DEF81			(0xC9)	/* ���[�U�w��W�P(IMSS) */
#define		PR_PAPER_USER_DEF82			(0xCA)	/* ���[�U�w��W�Q(IMSS) */
#define		PR_PAPER_USER_DEF83			(0xCB)	/* ���[�U�w��W�R(IMSS) */
#define		PR_PAPER_USER_DEF84			(0xCC)	/* ���[�U�w��W�S(IMSS) */
#define		PR_PAPER_USER_DEF85			(0xCD)	/* ���[�U�w��W�T(IMSS) */
#define		PR_PAPER_USER_DEF86			(0xCE)	/* ���[�U�w��W�U(IMSS) */
#define		PR_PAPER_USER_DEF87			(0xCF)	/* ���[�U�w��W�V(IMSS) */
#define		PR_PAPER_USER_DEF88			(0xD0)	/* ���[�U�w��W�W(IMSS) */
#define		PR_PAPER_USER_DEF89			(0xD1)	/* ���[�U�w��W�X(IMSS) */
#define		PR_PAPER_USER_DEF90			(0xD2)	/* ���[�U�w��X�O(IMSS) */
#define		PR_PAPER_USER_DEF91			(0xD3)	/* ���[�U�w��X�P(IMSS) */
#define		PR_PAPER_USER_DEF92			(0xD4)	/* ���[�U�w��X�Q(IMSS) */
#define		PR_PAPER_USER_DEF93			(0xD5)	/* ���[�U�w��X�R(IMSS) */
#define		PR_PAPER_USER_DEF94			(0xD6)	/* ���[�U�w��X�S(IMSS) */
#define		PR_PAPER_USER_DEF95			(0xD7)	/* ���[�U�w��X�T(IMSS) */
#define		PR_PAPER_USER_DEF96			(0xD8)	/* ���[�U�w��X�U(IMSS) */
#define		PR_PAPER_USER_DEF97			(0xD9)	/* ���[�U�w��X�V(IMSS) */
#define		PR_PAPER_USER_DEF98			(0xDA)	/* ���[�U�w��X�W(IMSS) */
#define		PR_PAPER_USER_DEF99			(0xDB)	/* ���[�U�w��X�X(IMSS) */
#define		PR_PAPER_USER_DEF100		(0xDC)	/* ���[�U�w��P�O�O(IMSS) */


/*
 * ������[�h
 */
#define PR_PLOT_NORMAL   (0)     /* �ʏ��� */
#define PR_PLOT_PROOF    (2)     /* ������� */
#define PR_PLOT_SECURE   (3)     /* �@����� */
#define PR_PLOT_STORED   (4)     /* �ۑ����� �h�L�������g�{�b�N�X */
#define PR_PLOT_PAUSE    (5)     /* �ۗ���� */
#define PR_PLOT_KEEP     (6)     /* �ۑ�������� */

#define PR_ECO_COLOR_NONE		(0)		/* �G�R�m�~�[�J���[���[�h�w��Ȃ� */
#define PR_ECO_COLOR_PRT		(1)		/* �G�R�m�~�[�J���[���[�h�w�肠�� */

/*
 * pr_page_info_s_t�̃����o���
 */
/* �ݒ肷��p�����[�^�w��(bit) */
#define PR_OUTPUT_TRAY		(1 << 0)	/* output_tray ���L�� */
#define PR_LIMITLESS_EXIT	(1 << 1)	/* limitless_exit ���L�� */
#define PR_STAPLE		(1 << 2)	/* staple ���L�� */
#define PR_PUNCH		(1 << 3)	/* punch ���L�� */
#define PR_Z_FOLD		(1 << 4)	/* z_fold ���L�� */
#define PR_TONERSAVE		(1 << 5)	/* tonersave ���L�� */
#define PR_JAMRECOVERY		(1 << 6)	/* jamrecovery ���L�� */
#define PR_FACE			(1 << 7)	/* face ���L�� */
#define PR_PAPER_COUNT		(1 << 8)	/* paper_count ���L�� */
#define PR_SHIFT		(1 << 9)	/* shift ���L�� */
#define PR_COUNTOFF		(1 << 10)	/* �p�����[�^ count_off ���L�� */
#define PR_SLIP			(1 << 11)		/* �p�����[�^ slip,slip_tray ���L�� */
#define PR_COVER		(1 << 12)	/* �p�����[�^ cover,coverprint,cover_tray ���L�� */
#define PR_BACKCOVER		(1 << 13)	/* �p�����[�^ backcover,backcoverprint,backcovertray ���L�� */
/* �V�[�P���V�����X�^�b�N */
#define PR_LIMITLESS_OFF	(0x0000)
#define PR_LIMITLESS_ON		(0x0010)
/* �r���g���C */
#define PR_BIN_MAIN             (0x0000)        /* �{�̔r��(����/�}���`�r��) */
#define PR_BIN_FINISHER         (0x0100)        /* �t�B�j�b�V�� */
#define PR_BIN_MAILBOX          (0x0200)        /* ���[���{�b�N�X */
#define PR_BIN_MULTI            (0x0300)        /* �}���`�r��(CF�g���C) */
#define PR_BIN_MAIN_STD         (0x0000)        /* FD/�W���r�� */
#define PR_BIN_MAIN_BIN1        (0x0001)        /* 1�r���r�� */
#define PR_BIN_MAIN_EXTED       (0x0002)        /* �g��(�X�g���[�g)�r�� */
#define PR_BIN_FINI_PROOF       (0x0100)        /* �v���[�t�g���C */
#define PR_BIN_FINI_SHIFT       (0x0101)        /* �V�t�g�g���C */
#define PR_BIN_FINI_BOOKLET     (0x0105)        /* �u�b�N���b�g */
#define PR_BIN_MAILBOX1         (0x0201)        /* ���[���{�b�N�X�P */
#define PR_BIN_MULTI_1          (0x0300)        /* �}���`�r���P */
#define PR_BIN_MULTI_2          (0x0301)        /* �}���`�r���Q */
/* �X�e�[�v�� */
#define PR_STAPLE_OFF              (0)
#define PR_STAPLE_LEFT_TOP_HORIZ   (1)         /* ���㐅�� */
#define PR_STAPLE_LEFT_TOP_VERT    (2)         /* ���㐂�� */
#define PR_STAPLE_LEFT_TOP_SLANT   (3)         /* ����΂� */
#define PR_STAPLE_RIGHT_TOP_HORIZ  (5)         /* �E�㐅�� */
#define PR_STAPLE_RIGHT_TOP_VERT   (6)         /* �E�㐂�� */
#define PR_STAPLE_RIGHT_TOP_SLANT  (7)         /* �E��΂� */
#define PR_STAPLE_DOUBLE_LEFT      (9)         /* �����Q�� */
#define PR_STAPLE_DOUBLE_TOP       (10)        /* �㑤�Q�� */
#define PR_STAPLE_DOUBLE_RIGHT     (11)        /* �E���Q�� */
#define PR_STAPLE_BOOKLET          (12)        /* �^���Q�� */
#define PR_STAPLE_NONE             (15)        /* ��ł�(GPS���Ή��̂��ߎg�p�֎~) */
#define PR_STAPLE_LEFT_TOP         (16)        /* ���� */
#define PR_STAPLE_RIGHT_TOP        (17)        /* �E�� */
/* �p���`�ʒu */
#define PR_PUNCH_POS_BIT_MASK  (0x07)          /* �p���`�ʒu�w��r�b�g */
#define PR_PUNCH_OFF           (0)			   /* �Ȃ� */
#define PR_PUNCH_LEFT          (1)             /* ���� */
#define PR_PUNCH_TOP           (2)             /* ��� */
#define PR_PUNCH_RIGHT         (3)             /* �E�� */
#define PR_PUNCH_LEFT_TOP      (4)			   /* ���� */
/* �p���`��� */
#define PR_PUNCH_TYPE_BIT_MASK (0xF0)          /* �p���`��ʎw��r�b�g */
#define PR_PUNCH_JP2           (0x00)          /* ���{2�� */
#define PR_PUNCH_US2           (0x10)          /* �k��2��*/
#define PR_PUNCH_US3           (0x20)          /* �k��3��*/
#define PR_PUNCH_EU4           (0x30)          /* ���B4��*/
#define PR_PUNCH_NEU4          (0x40)          /* �k��4��*/
#define PR_PUNCH_JP1           (0x50)          /* ���{1�� */
#define PR_PUNCH_MULTI         (0x60)          /* GBC�p���` */
/* Z�܂� */
#define	PR_Z_FOLD_OFF		(0)		/* �y�܂�Ȃ� */
#define	PR_Z_FOLD_RIGHT		(1)		/* �E�܂� */
#define	PR_Z_FOLD_BOTTOM	(2)		/* ���܂� */
#define	PR_Z_FOLD_LEFT		(3)		/* ���܂� */
/* �g�i�[�Z�[�u */
#define PR_TONERSAVE_OFF       (0)             /* �g�i�[�Z�[�uOFF */
#define PR_TONERSAVE_MODE1     (1)             /* �g�i�[�Z�[�u�E���[�h1 */
#define PR_TONERSAVE_MODE2     (2)             /* �g�i�[�Z�[�u�E���[�h2 */
/* �W�������J�o���[ */
#define PR_JAMRECOVERY_OFF     (0)
#define PR_JAMRECOVERY_ON      (1)
/* ���ԂŃV�t�g������^���Ȃ� */
#define PR_SHIFT_ON		(0)		/* �V�t�g���� */
#define PR_SHIFT_OFF		(1)		/* �V�t�g���Ȃ� */

#define	PR_PAGE_CHAP_OFF		0		/* �Ȃ� */
#define	PR_PAGE_CHAP_BLANK		1		/* �͋�؂�F������Ȃ� */
#define	PR_PAGE_CHAP_COPY		2		/* �͋�؂�F������� */
#define	PR_PAGE_CHAP_DIVIDE		3		/* �͕��� */

#define	PR_PAGE_CHAP_SHEET1		1		/* ��؂�p���P */
#define	PR_PAGE_CHAP_SHEET2		2		/* ��؂�p���Q */
#define	PR_PAGE_CHAP_SHEET3		3		/* ��؂�p���R */
#define	PR_PAGE_CHAP_SHEET4		4		/* ��؂�p���S */
#define	PR_PAGE_CHAP_SHEET5		5		/* ��؂�p���T */
#define	PR_PAGE_CHAP_SHEET6		6		/* ��؂�p���U */
#define	PR_PAGE_CHAP_SHEET7		7		/* ��؂�p���V */

/* �\�����[�h */
#define	PR_COVER_OFF		(0x00)		/* �\���n�e�e */
#define	PR_COVER_FRONT		(0x01)		/* �\���n�m */

/* �\���摜����� */
#define	PR_COVER_OFF		(0x00)		/* �\���Ɉ�����Ȃ� */
#define	PR_COVER_FRONT		(0x01)		/* �\���ɕЖʈ������ */
#define	PR_COVER_FRONT_D	(0x11)		/* �\���ɗ��ʈ������ */

/* ���\�����[�h */
#define	PR_COVER_BACK		(0x02)		/* ���\������ */

/* ���\���摜����� */
#define	PR_COVER_BACK		(0x02)		/* ���\��������� */
#define	PR_COVER_BACK_R		(0x22)		/* ���\�����]�r��(�摜���Жʂ̏ꍇ�̂�) */

#define PR_UCP_BITMASK	0x00000003
#define PR_UCP_1BPP		0x00000000
#define PR_UCP_2BPP		0x00000001
#define PR_UCP_4BPP		0x00000002
#define PR_UCP_ENABLEBP		0x00004000
#define PR_UCP_ENABLEBMP	0x00008000

typedef struct pr_backpattern {
	unsigned long flag;
	unsigned long bpw;
	unsigned long bph;
	unsigned long bpsize;
	unsigned char *bpimg;
	unsigned long bpmw;
	unsigned long bpmh;
	unsigned long bpmsize;
	unsigned char *bpmimg;
} pr_backpattern_t;

typedef struct pr_forepattern {
	unsigned long flag;
	unsigned long fpw;
	unsigned long fph;
	unsigned long fosize;
	unsigned char *fppimg;
} pr_forepattern_t;

#define PR_UCP_TEXT_MASK		0x00000007
#define PR_UCP_TEXT_CENTER		0x00000000
#define PR_UCP_TEXT_TOPLEFT		0x00000001
#define PR_UCP_TEXT_TOPMID		0x00000002
#define PR_UCP_TEXT_TOPRIGHT	0x00000003
#define PR_UCP_TEXT_BOTLEFT		0x00000004
#define PR_UCP_TEXT_BOTMID		0x00000005
#define PR_UCP_TEXT_BOTRIGHT	0x00000006
#define PR_UCP_TEXT_REPEAT		0x00000007

#define PR_UCP_TEXT_REVERSE		0x00000008

#define PR_UCP_PRINT_MASK		0x00000060	
#define PR_UCP_PRINT_FG			0x00000020
#define PR_UCP_PRINT_BG			0x00000040
#define PR_UCP_PRINT_ALL		0x00000000
#define PR_UCP_PRINT_REVERSE	0x00000060	

#define PR_UCP_ROTATE_MASK		0x30000000
#define PR_UCP_ROTATE_0			0x00000000
#define PR_UCP_ROTATE_90		0x10000000
#define PR_UCP_ROTATE_180		0x20000000
#define PR_UCP_ROTATE_270		0x30000000

#define PR_UCP_CLR_MASK			0x0000000F
#define PR_UCP_CLR_BGP			0x00000001
#define PR_UCP_CLR_BGMP			0x00000002
#define PR_UCP_CLR_FGP			0x00000004
#define PR_UCP_CLR_TEXT			0x00000008

/*
 *	GIPA 
 */
#define PR_ACCELERATION_OFF		0x00000000
#define PR_ACCELERATION_ON		0x00000001

/* GIPA�p�������̍ŏ��l[KB] */
#define PR_GIPA_MIN_MEMSIZE		(1024*15)

/*
 *	PageRenderer commands.
 */


#ifndef EXPORT
#ifndef PACKDLL
#define EXPORT
#else
#define EXPORT	__declspec(dllexport)
#endif
#endif

/* Common functions */
#ifdef __cplusplus

/* Common functions */

extern "C" EXPORT int pr_resetusergamma(long lprh);
extern "C" EXPORT int pr_setusergamma(long lprh, unsigned long flag,
	unsigned char *gamma);
extern "C" EXPORT int pr_setscanlinerule(long, unsigned char);
extern "C" EXPORT int pr_bitmap_clip(long, unsigned long, unsigned
	long, unsigned long, long, long, unsigned long, unsigned long,
	unsigned long, unsigned char *);
extern "C" EXPORT int pr_barcode(long, unsigned char, unsigned long,
	long, long, pr_barcode_t*, long, unsigned char *, long, unsigned
	char *);
extern "C" EXPORT long pr_init(unsigned char *, unsigned long);
extern "C" EXPORT long pr_init_ext(unsigned char *, unsigned long,
	unsigned long);
extern "C" EXPORT int pr_end(long);
extern "C" EXPORT unsigned char * pr_getalloc(long, int, unsigned long);
extern "C" EXPORT unsigned char * pr_realloc(long, unsigned char *,
	int, unsigned long);
extern "C" EXPORT long pr_availalloc(long, int);
extern "C" EXPORT unsigned char * pr_memory_alloc(long, unsigned long);
extern "C" EXPORT unsigned char * pr_memory_realloc(long, unsigned
	char *, unsigned long);
extern "C" EXPORT int pr_memory_free(long, unsigned char *);
extern "C" EXPORT unsigned char * pr_memory_shrink(long, unsigned char
	*, unsigned long);
extern "C" EXPORT int pr_memory_avail(long);
extern "C" EXPORT int pr_memory_avail_free (long lprh);
extern "C" EXPORT int pr_getworkinuse (long lprh);
extern "C" EXPORT int pr_getworksize (long lprh);
extern "C" EXPORT int pr_limit_memory(long lprh, unsigned long size);
extern "C" EXPORT int pr_setworksize(long lprh, unsigned long worksize);
extern "C" EXPORT int pr_setdevice(long, pr_dev_info_t *);
extern "C" EXPORT int pr_setprecedinginfo(long, pr_preceding_info_t *);
extern "C" EXPORT int pr_setjobinfo(long, pr_job_info_t *);
extern "C" EXPORT int pr_setpageinfo(long, pr_page_info_t *);
extern "C" EXPORT int pr_getvalue(long, int, int *);
extern "C" EXPORT int pr_setprintmode(long, int);
extern "C" EXPORT int pr_setpageinfo_specified(long, pr_page_info_s_t *);
extern "C" EXPORT int pr_setpageinfo_extend(long, pr_page_info_shm_t *);
extern "C" EXPORT int pr_changebinding(long, unsigned char, long *);
extern "C" EXPORT int pr_setchaptermode(long, long, long);
extern "C" EXPORT int pr_reducememory_mode(long, unsigned long);
extern "C" EXPORT int pr_popclip(long);
extern "C" EXPORT int pr_saveclip(long);
extern "C" EXPORT int pr_restoreclip(long);
extern "C" EXPORT int pr_settransmode(long, unsigned long, unsigned
	char *);
extern "C" EXPORT int pr_setrop3mode(long, unsigned long);
extern "C" EXPORT int pr_scanline_slope(long, unsigned long, long,
	long, long, unsigned long, long, long, char *, char *);
extern "C" EXPORT int pr_selectdevicedither(long, pr_resolution_info_t
	*, pr_resolution_info_t *);
extern "C" EXPORT int pr_getallocmemsize(long, unsigned char *);
extern "C" EXPORT int pr_getmemsize(long,unsigned char *);
extern "C" EXPORT int pr_getabsmemsize(long,unsigned char *);

/* Job Control Category functions */
extern "C" EXPORT int pr_jobstart(long);
extern "C" EXPORT int pr_jobend(long);
extern "C" EXPORT int pr_delayed_jobend(long);
extern "C" EXPORT int pr_pagestart(long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned long, unsigned long);
extern "C" EXPORT int pr_pageend(long, long);
extern "C" EXPORT int pr_bandstart(long, unsigned long);
extern "C" EXPORT int pr_bandend(long);
extern "C" EXPORT int pr_bandcancel(long);
extern "C" EXPORT int pr_abort(long);
extern "C" EXPORT int pr_dividejob (long, pr_dividejob_info_t *, int *);

/* Page Control Category function */
extern "C" EXPORT int pr_setgraymode(long, unsigned char, unsigned
	char, unsigned char, unsigned char);
extern "C" EXPORT int pr_setgrayjudgemode(long, unsigned char, unsigned
	char, unsigned char, unsigned char);
extern "C" EXPORT int pr_setusedplane(long, unsigned char, unsigned
	char, unsigned char, unsigned char);
extern "C" EXPORT int pr_settonersave(long, char);
extern "C" EXPORT int pr_settonerlimit(long, int);
extern "C" EXPORT int pr_setdeftonerlimit_ratio(long, int, int, int,
	int, int);
extern "C" EXPORT int pr_setusedframe(long, unsigned char);
extern "C" EXPORT int pr_settonerlimit_ratio(long, int, int, int, int,
	int *, int *, int *, int *);
extern "C" EXPORT int pr_settonersave_ratio(long, char, char, char,
	char);
extern "C" EXPORT int pr_setgammathrough(long, char);
extern "C" EXPORT int pr_clipinit(long, long, long, unsigned long,
	unsigned long);
extern "C" EXPORT int pr_densityadjust(long, unsigned char, unsigned
	char, unsigned char, unsigned char);
extern "C" EXPORT int pr_setmediatype(long, unsigned char);
extern "C" EXPORT int pr_setratio_rgb(long, unsigned char,
				unsigned char, unsigned char,
				unsigned char, unsigned char);
extern "C" EXPORT int pr_setratio_tonerlimit(long, unsigned char,
				unsigned char, unsigned char,
				unsigned char, unsigned char);


/* Graphics Category functions */
extern "C" EXPORT int pr_rectangle(long, unsigned long, long, long,
	long, long);
extern "C" EXPORT int pr_polyline(long, unsigned long, unsigned long,
	void *);
extern "C" EXPORT int pr_polylinepath(long, unsigned long, unsigned
	long, void *);
extern "C" EXPORT int pr_polybezier(long, unsigned long, unsigned long,
	void *);
extern "C" EXPORT int pr_polybezierpath(long, unsigned long, unsigned
	long, void *);
extern "C" EXPORT int pr_scanline(long, unsigned long, unsigned long,
	void *);
extern "C" EXPORT int pr_scanlinepath(long, unsigned long, void *);

/* Font Category functions */
extern "C" EXPORT int pr_init_devfont(long, unsigned char *, unsigned
	long);
extern "C" EXPORT int pr_font_savetodevice(long lprh, unsigned char
	deviceobject, char *filename);
extern "C" EXPORT int pr_font_loadfromdevice(long lprh, unsigned char
	deviceobject, char *filename);
extern "C" EXPORT int pr_font_deleteofdevice(long lprh, unsigned char
	deviceobject, unsigned char deleteobject, char *filename);
extern "C" EXPORT int pr_definefont_device(long, unsigned short,
	unsigned char, unsigned short, unsigned short, unsigned short);
extern "C" EXPORT int pr_definefont_download(long, unsigned short);
extern "C" EXPORT int pr_selectfont(long, unsigned short);
extern "C" EXPORT int pr_deletefont(long, unsigned short);
extern "C" EXPORT int pr_deleteallfont(long);
extern "C" EXPORT int pr_registchar(long, unsigned long, unsigned
	short, unsigned char, unsigned long, unsigned short, unsigned
	short, void *);
extern "C" EXPORT int pr_deletechar(long, unsigned short, unsigned
	short *);
extern "C" EXPORT int pr_deleteallchar(long);
extern "C" EXPORT int pr_putchar_device(long, long, long, unsigned
	short);
extern "C" EXPORT int pr_putchar_download(long, unsigned long, long,
	long, unsigned long, unsigned short, unsigned short, void *);
extern "C" EXPORT int pr_putchar_cached(long, long, long, unsigned
	short);
extern "C" EXPORT int pr_putstring_device(long, unsigned short, long,
	long, unsigned short *);
extern "C" EXPORT int pr_getcharbox(long, unsigned char, unsigned
	short, unsigned short, unsigned short, unsigned short, short *,
	short *, unsigned short *, unsigned short *);
extern "C" EXPORT int pr_getbaseline(long, unsigned short, float *);

/* Image Category functions */
extern "C" EXPORT int pr_bitblt(long, unsigned long, unsigned short,
	long, long, unsigned long, unsigned long, unsigned long, unsigned
	char *);
extern "C" EXPORT int pr_stretchblt(long, unsigned long, unsigned long,
	unsigned long, long, long, unsigned long, unsigned long, unsigned
	char *, unsigned long);
extern "C" EXPORT int pr_stretchblt_index(long, unsigned long,
	unsigned long, unsigned long, long, long, unsigned long, unsigned
	long, unsigned char *, unsigned char *, unsigned long);
extern "C" EXPORT int pr_stretchblt_repeat(long, unsigned long,
	unsigned long, unsigned long, long, long, unsigned long, unsigned
	long, unsigned long, unsigned long, unsigned char *, unsigned long);
extern "C" EXPORT int pr_stretchblt_index_repeat(long, unsigned long,
	unsigned long, unsigned long, long, long, unsigned long, unsigned
	long, unsigned long, unsigned long, unsigned char *, unsigned char
	*, unsigned long);
extern "C" EXPORT int pr_drawurf(long, unsigned short, unsigned short,
	unsigned long, unsigned long, long, long, unsigned long, unsigned long,
	unsigned char *);
#ifdef  PR_XPS_SUPPORT 
extern "C" EXPORT int pr_enableblending(long prh, int bBlending);
extern "C" EXPORT int pr_setalpha(long prh, unsigned int uiFlag,
	unsigned int uiAlpha);
extern "C" EXPORT int pr_setblendcolorspace(long prh, unsigned int
	uiBlendColorSpace);
extern "C" EXPORT int pr_setblendmode(long prh, int Blendmode);
#endif
/* Graphics Setting Category functions */
extern "C" EXPORT int pr_setrop3(long, unsigned char);
extern "C" EXPORT int pr_setlinewidth(long, unsigned long);
extern "C" EXPORT int pr_setlinedash(long, unsigned long, unsigned
	short);
#ifndef NOT_SUPPORT_IPS
extern "C" EXPORT int pr_setlinedash_ex(long, unsigned char *,
	unsigned long, unsigned long);
extern "C" EXPORT int pr_setlineshift(long, unsigned long);
#else /* NOT_SUPPORT_IPS */
extern "C" EXPORT int pr_setlineshift(long, unsigned char);
#endif /* NOT_SUPPORT_IPS */
extern "C" EXPORT int pr_setbrushorg(long, long, long);
extern "C" EXPORT int pr_resetclip(long);
extern "C" EXPORT int pr_setbkmode(long, unsigned char);
extern "C" EXPORT int pr_setcolor(long, unsigned char, unsigned char *);
extern "C" EXPORT int pr_setcolordrawfill(long, unsigned char,
	unsigned char *);
extern "C" EXPORT int pr_setlinecap(long, unsigned char);
extern "C" EXPORT int pr_setlinejoin(long, unsigned char);
extern "C" EXPORT int pr_setmiterlimit(long, float);
extern "C" EXPORT int pr_setflatness(long, float);
extern "C" EXPORT int pr_setdithermode(long, unsigned char, unsigned
	char, unsigned char, unsigned char);
extern "C" EXPORT int pr_setwidthadjust(long, unsigned char);
extern "C" EXPORT int pr_setbop(long, unsigned char);
extern "C" EXPORT int pr_setcutoutmode(long, char);
extern "C" EXPORT int pr_setpapersuppress(long, unsigned int);

extern "C" EXPORT int pr_setaccelerationmode(long, unsigned long, unsigned long);

/* Object Category functions */
extern "C" EXPORT int pr_defobject(long, unsigned short);
extern "C" EXPORT int pr_allclearobject(long);
extern "C" EXPORT int pr_paintobject(long, unsigned short);

/* Rendering Category functions */
extern "C" EXPORT int pr_defbrush(long, unsigned long, unsigned char,
	unsigned char, unsigned char, unsigned short, unsigned char *);
extern "C" EXPORT int pr_selectbrush(long, unsigned long);
extern "C" EXPORT int pr_allclearbrush(long);
extern "C" EXPORT int pr_defbrush_anysize(long, unsigned long,
	unsigned long, unsigned long, unsigned long, unsigned long,
	unsigned long, unsigned char *, unsigned char *);

/* Error Code Control function */
extern "C" EXPORT int pr_get_errorcode(long);
extern "C" EXPORT void pr_clear_errorcode(long);

/* CMM functions */
extern "C" EXPORT long pr_setprofileid(long, unsigned long, unsigned
	long, unsigned long, unsigned long);
extern "C" EXPORT long pr_defineprofile(long, unsigned long, unsigned
	long, unsigned char *);
extern "C" EXPORT long pr_setaccentphototable(long, unsigned char *);
extern "C" EXPORT int pr_applyprofilergb(long, unsigned char, unsigned
	char *, unsigned char *, unsigned char *, unsigned char *,
	unsigned char *, unsigned char *, unsigned long);
extern "C" EXPORT long pr_setprofileid_ext(long, unsigned char,
	unsigned long, unsigned long, unsigned long, unsigned long);

/* IJ Renderer Category */
extern "C" EXPORT int pr_setmargin(long, unsigned char, long, long);
extern "C" EXPORT int pr_setinfo_ij(long, pr_ij_info_t *);
extern "C" EXPORT int pr_setoutput(long, long, unsigned long, unsigned
	long);

/* Other Category */
extern "C" EXPORT int pr_rgb2cmyk(long, unsigned char, unsigned char,
	unsigned char, unsigned char, unsigned char *, unsigned char *,
	unsigned char *, unsigned char *);
extern "C" EXPORT int pr_rgb2cmyk_pixels(long, unsigned char,
	unsigned char *, unsigned char *, unsigned long);
extern "C" EXPORT int pr_rgb2k(long, unsigned char, unsigned char,
	unsigned char, unsigned char, unsigned char *);
extern "C" EXPORT int pr_rgb2k_pixels(long, unsigned char,
	unsigned char *, unsigned char *, unsigned long);
extern "C" EXPORT int pr_notify_noerror_display(long, long *);
extern "C" EXPORT int pr_set_pageerror_continue(long, int);
extern "C" EXPORT int pr_notify_errorinformation(long, long *);

/* Unauthorized Copy Prevention */
extern "C" EXPORT int pr_ucp_start(long, int);
extern "C" EXPORT int pr_set_ucp_backpattern(long, pr_backpattern_t *);
extern "C" EXPORT int pr_set_ucp_forepattern(long, pr_forepattern_t *);
extern "C" EXPORT int pr_set_ucp_text(long, unsigned long, long, long,
	unsigned long,  unsigned long, unsigned long, void *);
extern "C" EXPORT int pr_set_ucp_text_device(long, unsigned short,
	unsigned short,  unsigned short, unsigned short, unsigned short,
	unsigned short *);
extern "C" EXPORT int pr_ucp_end(long);
extern "C" EXPORT int pr_ucp_paint(long, unsigned long, unsigned short,
	unsigned long);
extern "C" EXPORT int pr_ucp_clear(long, unsigned long);
#else /* __cplusplus */
// If CPLUSPLUS is not defined , c compiler

extern EXPORT long pr_init(unsigned char *, unsigned long);
extern EXPORT long pr_init_ext(unsigned char *, unsigned long,
	unsigned long);
extern EXPORT int pr_end(long);
extern EXPORT unsigned char * pr_getalloc(long, int, unsigned long);
extern EXPORT unsigned char * pr_realloc(long, unsigned char *, int,
	unsigned long);
extern EXPORT long pr_availalloc(long, int);
extern EXPORT unsigned char * pr_memory_alloc(long, unsigned long);
extern EXPORT unsigned char *pr_memory_realloc(long, unsigned char *,
	unsigned long);
extern EXPORT int pr_memory_free(long, unsigned char *);
extern EXPORT unsigned char * pr_memory_shrink(long, unsigned char *,
	unsigned long);
extern EXPORT int pr_memory_avail(long);
extern EXPORT int pr_setdevice(long, pr_dev_info_t *);
extern EXPORT int pr_setprecedinginfo(long, pr_preceding_info_t *);
extern EXPORT int pr_setjobinfo(long, pr_job_info_t *);
extern EXPORT int pr_setpageinfo(long, pr_page_info_t *);
extern EXPORT int pr_getvalue(long, int, int *);
extern EXPORT int pr_setprintmode(long, int);
extern EXPORT int pr_setpageinfo_specified(long, pr_page_info_s_t *);
extern EXPORT int pr_setpageinfo_extend(long, pr_page_info_shm_t *);
extern EXPORT int pr_changebinding(long, unsigned char, long *);
extern EXPORT int pr_setchaptermode(long, long, long);
extern EXPORT int pr_reducememory_mode(long, unsigned long);
extern EXPORT int pr_popclip(long);
extern EXPORT int pr_saveclip(long);
extern EXPORT int pr_restoreclip(long);
extern EXPORT int pr_settransmode(long, unsigned long, unsigned char *);
extern EXPORT int pr_setrop3mode(long, unsigned long);
extern EXPORT int pr_scanline_slope(long, unsigned long, long, long,
	long, unsigned long, long, long, char *, char *);
extern EXPORT int pr_selectdevicedither(long, pr_resolution_info_t *,
	pr_resolution_info_t *);
extern EXPORT int pr_limit_memory(long, unsigned long);
extern EXPORT int pr_setworksize(long, unsigned long);
extern EXPORT int pr_memory_avail_free(long);
extern EXPORT int pr_getworksize(long);
extern EXPORT int pr_getworkinuse(long);
extern EXPORT int pr_getallocmemsize(long, unsigned char *);
extern EXPORT int pr_getmemsize(long,unsigned char *);
extern EXPORT int pr_getabsmemsize(long,unsigned char *);

/* Job Control Category functions */
extern EXPORT int pr_jobstart(long);
extern EXPORT int pr_jobend(long);
extern EXPORT int pr_delayed_jobend(long);
extern EXPORT int pr_pagestart(long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned long, unsigned long);
extern EXPORT int pr_pageend(long, long);
extern EXPORT int pr_bandstart(long, unsigned long);
extern EXPORT int pr_bandend(long);
extern EXPORT int pr_bandcancel(long);
extern EXPORT int pr_abort(long);
extern EXPORT int pr_dividejob(long, pr_dividejob_info_t *, int *);

/* Page Control Category function */
extern EXPORT int pr_setgraymode(long, unsigned char, unsigned char,
	unsigned char, unsigned char);
extern EXPORT int pr_setgrayjudgemode(long, unsigned char, unsigned char,
	unsigned char, unsigned char);
extern EXPORT int pr_setusedplane(long, unsigned char, unsigned char,
	unsigned char, unsigned char);
extern EXPORT int pr_settonersave(long, char);
extern EXPORT int pr_settonerlimit(long, int);
extern EXPORT int pr_setusedframe(long, unsigned char);
extern EXPORT int pr_settonerlimit_ratio(long, int, int, int, int, int
	*, int *, int *, int *);
extern EXPORT int pr_settonerlimit_ratio(long, int, int, int, int, int
	*, int *, int *, int *);
extern EXPORT int pr_settonersave_ratio(long, char, char, char, char);
extern EXPORT int pr_setgammathrough(long, char);
extern EXPORT int pr_clipinit(long, long, long, unsigned long,
	unsigned long);
extern EXPORT int pr_densityadjust(long, unsigned char, unsigned char,
	unsigned char, unsigned char);
extern EXPORT int pr_setmediatype(long, unsigned char);
extern EXPORT int pr_setratio_rgb(long, unsigned char,
				unsigned char, unsigned char,
				unsigned char, unsigned char);
extern EXPORT int pr_setratio_tonerlimit(long, unsigned char,
				unsigned char, unsigned char,
				unsigned char, unsigned char);


/* Graphics Category functions */
extern EXPORT int pr_rectangle(long, unsigned long, long, long, long,
	long);
extern EXPORT int pr_polyline(long, unsigned long, unsigned long, void
	*);
extern EXPORT int pr_polylinepath(long, unsigned long, unsigned long,
	void *);
extern EXPORT int pr_polybezier(long, unsigned long, unsigned long,
	void *);
extern EXPORT int pr_polybezierpath(long, unsigned long, unsigned long,
	void *);
extern EXPORT int pr_scanline(long, unsigned long, unsigned long, void
	*);
extern EXPORT int pr_scanlinepath(long, unsigned long, void *);
extern EXPORT int pr_arc(long, unsigned long, long, long, unsigned
	long, unsigned long, unsigned long);
extern EXPORT int pr_barcode(long, unsigned char, unsigned long, long,
	long, pr_barcode_t *, long, unsigned char *, long, unsigned char *);


/* Font Category functions */
extern EXPORT int pr_init_devfont(long, unsigned char *, unsigned long);
extern EXPORT int pr_font_savetodevice(long lprh, unsigned char
	deviceobject, char *filename);
extern EXPORT int pr_font_loadfromdevice(long lprh, unsigned char
	deviceobject, char *filename);
extern EXPORT int pr_font_deleteofdevice(long lprh, unsigned char
	deviceobject, unsigned char deleteobject, char *filename);
extern EXPORT int pr_definefont_device(long, unsigned short, unsigned
	char, unsigned short, unsigned short, unsigned short);
extern EXPORT int pr_definefont_download(long, unsigned short);
extern EXPORT int pr_selectfont(long, unsigned short);
extern EXPORT int pr_deletefont(long, unsigned short);
extern EXPORT int pr_deleteallfont(long);
extern EXPORT int pr_registchar(long, unsigned long, unsigned short,
	unsigned char, unsigned long, unsigned short, unsigned short, void *);
extern EXPORT int pr_deletechar(long, unsigned short, unsigned short *);
extern EXPORT int pr_deleteallchar(long);
extern EXPORT int pr_putchar_device(long, long, long, unsigned short);
extern EXPORT int pr_putchar_download(long, unsigned long, long, long,
	unsigned long, unsigned short, unsigned short, void *);
extern EXPORT int pr_putchar_cached(long, long, long, unsigned short);
extern EXPORT int pr_putstring_device(long, unsigned short, long, long,
	unsigned short *);
extern EXPORT int pr_getcharbox(long, unsigned char, unsigned short,
	unsigned short, unsigned short, unsigned short, short *, short *,
	unsigned short *, unsigned short *);
extern EXPORT int pr_getbaseline(long, unsigned short, float *);

/* Image Category functions */
extern EXPORT int pr_bitblt(long, unsigned long, unsigned short, long,
	long, unsigned long, unsigned long, unsigned long, unsigned char *);
extern EXPORT int pr_stretchblt(long, unsigned long, unsigned long,
	unsigned long, long, long, unsigned long, unsigned long, unsigned
	char *, unsigned long);
extern EXPORT int pr_stretchblt_index(long, unsigned long, unsigned
	long, unsigned long, long, long, unsigned long, unsigned long,
	unsigned char *, unsigned char *, unsigned long);
extern EXPORT int pr_stretchblt_repeat(long, unsigned long, unsigned
	long, unsigned long, long, long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned char *, unsigned long);
extern EXPORT int pr_stretchblt_index_repeat(long, unsigned long,
	unsigned long, unsigned long, long, long, unsigned long, unsigned
	long, unsigned long, unsigned long, unsigned char *, unsigned char
	*, unsigned long);
extern EXPORT int pr_drawurf(long, unsigned short, unsigned short,
	unsigned long, unsigned long, long, long, unsigned long, unsigned long,
	unsigned char *);
extern EXPORT int pr_bitmap_clip(long, unsigned long, unsigned long,
	unsigned long, long, long, unsigned long, unsigned long, unsigned
	long, unsigned char *);

/* Graphics Setting Category functions */
extern EXPORT int pr_setrop3(long, unsigned char);
extern EXPORT int pr_setlinewidth(long, unsigned long);
extern EXPORT int pr_setlinedash(long, unsigned long, unsigned short);
#ifndef NOT_SUPPORT_IPS
extern EXPORT int pr_setlinedash_ex(long, unsigned char *, unsigned
	long, unsigned long);
extern EXPORT int pr_setlineshift(long, unsigned long);
#else /* NOT_SUPPORT_IPS */
extern EXPORT int pr_setlineshift(long, unsigned char);
#endif /* NOT_SUPPORT_IPS */
extern EXPORT int pr_setbrushorg(long, long, long);
extern EXPORT int pr_resetclip(long);
extern EXPORT int pr_setbkmode(long, unsigned char);
extern EXPORT int pr_setcolor(long, unsigned char, unsigned char *);
extern EXPORT int pr_setcolordrawfill(long, unsigned char, unsigned
	char *);
extern EXPORT int pr_setlinecap(long, unsigned char);
extern EXPORT int pr_setlinejoin(long, unsigned char);
extern EXPORT int pr_setmiterlimit(long, float);
extern EXPORT int pr_setflatness(long, float);
extern EXPORT int pr_setdithermode(long, unsigned char, unsigned char,
	unsigned char, unsigned char);
extern EXPORT int pr_setwidthadjust(long, unsigned char);
extern EXPORT int pr_setbop(long, unsigned char);
extern EXPORT int pr_setcutoutmode(long, char);
extern EXPORT int pr_setpapersuppress(long, unsigned int);
extern EXPORT int pr_setscanlinerule(long, unsigned char);

extern EXPORT int pr_setaccelerationmode(long, unsigned long, unsigned long);

/* Object Category functions */
extern EXPORT int pr_defobject(long, unsigned short);
extern EXPORT int pr_allclearobject(long);
extern EXPORT int pr_paintobject(long, unsigned short);

/* Rendering Category functions */
extern EXPORT int pr_defbrush(long, unsigned long, unsigned char,
	unsigned char, unsigned char, unsigned short, unsigned char *);
extern EXPORT int pr_selectbrush(long, unsigned long);
extern EXPORT int pr_allclearbrush(long);
extern EXPORT int pr_defbrush_anysize(long, unsigned long, unsigned
	long, unsigned long, unsigned long, unsigned long, unsigned long,
	unsigned char *, unsigned char *);

/* Error Code Control function */
extern EXPORT int pr_get_errorcode(long);
extern EXPORT void pr_clear_errorcode(long);

/* CMM functions */
extern EXPORT long pr_setprofileid(long, unsigned long, unsigned long,
	unsigned long, unsigned long);
extern EXPORT long pr_defineprofile(long, unsigned long, unsigned long,
	unsigned char *);
extern EXPORT long pr_setaccentphototable(long, unsigned char *);
extern EXPORT int pr_applyprofilergb(long, unsigned char, unsigned
	char *, unsigned char *, unsigned char *, unsigned char *,
	unsigned char *, unsigned char *, unsigned long);
extern EXPORT long pr_setprofileid_ext(long, unsigned char,
	unsigned long, unsigned long, unsigned long, unsigned long);

/* IJ Renderer Category */
extern EXPORT int pr_setmargin(long, unsigned char, long, long);
extern EXPORT int pr_setinfo_ij(long, pr_ij_info_t *);
extern EXPORT int pr_setoutput(long, long, unsigned long, unsigned
	long);

/* Dither, Gamma Category */
extern EXPORT int pr_setusergamma(long, unsigned long, unsigned char *);
extern EXPORT int pr_resetusergamma(long);

/* Other Category */
extern EXPORT int pr_rgb2cmyk(long, unsigned char, unsigned char,
	unsigned char, unsigned char, unsigned char *, unsigned char *,
	unsigned char *, unsigned char *);
extern EXPORT int pr_rgb2cmyk2(long, unsigned char, unsigned char,
	unsigned char, unsigned char, unsigned char *, unsigned char *,
	unsigned char *, unsigned char *);
extern EXPORT int pr_rgb2cmyk_pixels(long, unsigned char,
	unsigned char *, unsigned char *, unsigned long);
extern EXPORT int pr_rgb2k(long, unsigned char, unsigned char,
	unsigned char, unsigned char, unsigned char *);
extern EXPORT int pr_rgb2k_pixels(long, unsigned char,
	unsigned char *, unsigned char *, unsigned long);
extern EXPORT int pr_notify_noerror_display(long, long *);
extern EXPORT int pr_set_pageerror_continue(long, int);
extern EXPORT int pr_notify_errorinformation(long, long *);

/* Unauthorized Copy Prevention */
extern EXPORT int pr_ucp_start(long, int);
extern EXPORT int pr_set_ucp_backpattern(long, pr_backpattern_t *);
extern EXPORT int pr_set_ucp_forepattern(long, pr_forepattern_t *);
extern EXPORT int pr_set_ucp_text(long, unsigned long, long, long,
	unsigned long,  unsigned long, unsigned long, void *);
extern EXPORT int pr_set_ucp_text_device(long, unsigned short, unsigned short,
	unsigned short,  unsigned short, unsigned short, unsigned short *);
extern EXPORT int pr_ucp_end(long);
extern EXPORT int pr_ucp_paint(long, unsigned long, unsigned short,
	unsigned long);
extern EXPORT int pr_ucp_clear(long, unsigned long);
#endif /* __cplusplus */

#endif  /*  __PAGER_H__  */

