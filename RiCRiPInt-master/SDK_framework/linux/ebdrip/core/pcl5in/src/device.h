/**
 * @file device.h
 * @brief DI�̌��J�t�@�C��
 *
 * @author kumagai
 * @date 2005-09-13
 * $Revision: 1.4 $
 *
 * Copyright (c) 2001-2007 by RICOH CO., LTD.
 */

/** \mainpage DI Library �����݌v�d�l��
 *
 * �{�d�l���́ADI�iDevice Infomation) Library �̓����d�l���L�q�������̂ł��B
 *
 * DI�́A�v�����^�[�A�v���i�ȉ��A�v���j�����삷�邽�߂ɕK�v�ȏ��̒񋟂�
 * �s�����C�u�����ł��B
 * �A�v���ł́A�v�����^�[�̂n�r��@��Ɉˑ�������񂪕K�v�ł����A���̂悤
 * �ȕϓ��p�����[�^��DI����擾���邱�Ƃɂ��A�p�[�X���A�����_�����O����
 * ���������������̔ėp�������߂܂��B
 *
 * \date 2005/09
 * \author M.Kumagai
 */

#ifndef	__DEVICE_H__
#define	__DEVICE_H__

#define DI_MAX_TRAY_NUM	8

/*
 * di_select_idevice�֐���I/O��`
 */
#define DI_HOST_IO         0
#define DI_MEMORY_IO       1
#define DI_FILE_IO         2

/*
 * �V�X�e�����痈��C�x���g�l
 */
#define	DI_REQ_PROCESS	0x01	/* �ʏ폈�� */
#define	DI_REQ_CANCEL	0x02	/* �p�l������̃W���u���Z�b�g */
#define	DI_REQ_EXIT		0x04	/* �I���v�� */
#define	DI_REQ_PAUSE    0x08	/* ���荞�݂ɂ��ꎞ��~�v�� */
#define	DI_REQ_RESUME   0x10	/* �����ĊJ�v�� */
#define	DI_REQ_PROGENTRY	0x20	/* �v���O�����o�^�v���iMSIS�nPDL��p�j */
#define	DI_REQ_PROGDELETE	0x40	/* �v���O�����폜�v���iMSIS�nPDL��p�j */
#define	DI_REQ_TERM		0x80	/* �v�����^�A�v���I���v���iMSIS�nPDL��p�j */
#define	DI_REQ_INTRAY		0x100	/* �����g���C���m�F�v���iMSIS�nPDL��p */

/*
 * �V�X�e���ւ̒ʒm���b�Z�[�W
 */
#define DI_NOTIFYMSG_JOBEND		0x01	/* �W���u�̏I�� */
#define DI_NOTIFYMSG_STATE		0x02	/* ��Ԃ̒ʒm */
#define DI_NOTIFYMSG_STRING		0x03	/* ������ɂ���Ԃ̒ʒm */
#define DI_NOTIFYMSG_ERRFORCE		0x11	/* �G���[�̋����ʒm */
#define DI_NOTIFYMSG_START		0x12	/* �����I�ȋN���ʒm */
#define DI_NOTIFYMSG_FINISH_FONTCOUNT	0x13	/* �t�H���g�J�E���g�̏I���ʒm */
#define DI_NOTIFYMSG_PAUSE		0x14	/* �ꎞ��~�v���ɑ΂��鉞���i�����A�������͈ꎞ��~�ł��Ȃ��j�ʒm */
#define DI_NOTIFYMSG_RESUME		0x15	/* �����ĊJ�ʒm */
#define DI_NOTIFYMSG_ERR		0x16    /* �G���[�̒ʒm */
#define DI_NOTIFYMSG_WARNNING		0x17	/* ���[�j���O���x���̃G���[�̒ʒm */
#define DI_NOTIFYMSG_CLEAR_WARNNING	0x18	/* ���[�j���O���x���̃G���[�̃N���A�̒ʒm */
#define DI_NOTIFYMSG_ALERT		0x19	/* �I�y���[�^�R�[�����x���̃G���[�̒ʒm */
#define DI_NOTIFYMSG_CLEAR_ALERT	0x1A	/* �I�y���[�^�R�[�����x���̃G���[�̃N���A�̒ʒm */

/*
 *�ꎟ��~�v���ɑ΂��鉞���̈���
 */
#define DI_INTERP_PAUSE_OK	0	/* �ꎞ��~������ */
#define DI_INTERP_PAUSE_NG	-1	/* �ꎞ��~�ł��Ȃ� */

/*
 * �C���^�v���^�̏��
 */
#define DI_INTERP_STATE_IDLE       0   /* idle */
#define DI_INTERP_STATE_PROCESSING 1   /* processing */
#define DI_INTERP_STATE_WAITING    2   /* waiting data */
#define DI_INTERP_STATE_FLUSHING   3   /* flushing data */

/*
 * �R�[���o�b�N�֐��̎w��
 */
/* di_singetc �ǂݍ��ݎ��s�̎��ɃR�[������֐� */
#define DI_CALLBACK_READERR_SINGETC		0x01
/* di_singet �ǂݍ��ݎ��s�̎��ɃR�[������֐� */
#define DI_CALLBACK_READERR_SINGET		0x02
/* di_singetc �T�C�Y�w��s�����ɃR�[������֐� */
#define DI_CALLBACK_SIZEERR_SINGET		0x03
/* �V�X�e������f�[�^�����̊J�n�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_PROCDATA		0x11
/* �V�X�e������C���^�v���^�I���v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_EXIT			0x12
/* �V�X�e������f�[�^�����̒��~�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_CANCEL			0x13
/* �V�X�e������I�����C���v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_ONLINE			0x14
/* �V�X�e������I�t���C���v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_OFFLINE			0x15
/* �V�X�e������e�X�g�v�����g�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_TESTPRINT		0x16
/* �V�X�e�����狋���g���C�̕ύX�ʒm���������ɃR�[������֐� */
#define DI_CALLBACK_REQ_TRAYINFO		0x17
/* �V�X�e������r���r���̕ύX�ʒm���������ɃR�[������֐� */
#define DI_CALLBACK_REQ_BININFO			0x18
/* �V�X�e�����狭���r���v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_EXITPAPER		0x19
/* �V�X�e������t�H���g���̃J�E���g�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_FONTCOUNT		0x1A
/* �V�X�e������v�����^�X�e�[�^�X���̕ύX�ʒm���������ɃR�[������֐� */
#define DI_CALLBACK_REQ_PRTSTATUS		0x1B
/* �V�X�e������K���}�Čv�Z���������ɃR�[������֐� */
#define DI_CALLBACK_REQ_GAM				0x1C
/* �V�X�e������f�[�^�����̈ꎞ��~�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_PAUSE				0x1D
/* �V�X�e������f�[�^�����̏����ĊJ�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_RESUME				0x1E
/* �V�X�e�����烁�j���[�A�C�e���̓o�^�v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_MENU_INIT			0x20
/* �V�X�e�����烁�j���[��ʂ̏I���v�����������ɃR�[������֐� */
#define DI_CALLBACK_REQ_MENU_EXIT			0x21
#define DI_CALLBACK_REQ_TRAY			0x26

/*
 * �𑜓x
 */
#define DI_RESO_200x200x1	(1 << 0)
#define DI_RESO_300x300x1	(1 << 1)
#define DI_RESO_400x400x1	(1 << 2)
#define DI_RESO_600x600x1	(1 << 3)
#define DI_RESO_1200x1200x1	(1 << 4)
#define DI_RESO_1200x600x1	(1 << 5)
#define DI_RESO_600x600x2	(1 << 6)
#define DI_RESO_600x600x4	(1 << 7)
#define DI_RESO_1200x1200x2	(1 << 8)
#define DI_RESO_600x1200x1	(1 << 9)

/*
 * di_getinfo( )�̃G���[�̎��
 */
#define DI_GI_ERR_CONDITION  	(1 << 0)
#define DI_GI_ERR_DITHER     	(1 << 1)
#define DI_GI_ERR_GAMMA      	(1 << 2)
#define DI_GI_ERR_FONT       	(1 << 3)
#define DI_GI_ERR_PROF       	(1 << 4)
#define DI_GI_ERR_RESO       	(1 << 5)
#define DI_GI_ERR_NDIT       	(1 << 6)
#define DI_GI_ERR_NPLANE     	(1 << 7)
#define DI_GI_ERR_BGUCR      	(1 << 8)
#define DI_GI_ERR_TSAVE      	(1 << 9)
#define DI_GI_ERR_TSAVE_R    	(1 << 10)
#define DI_GI_ERR_TLIMIT     	(1 << 11)
#define DI_GI_ERR_TLIMIT_R   	(1 << 12)
#define DI_GI_ERR_SHDM       	(1 << 13)
#define DI_GI_ERR_SYSH       	(1 << 14)
#define DI_GI_ERR_EXTENDTSAVE   (1 << 15)
#define DI_GI_ERR_DROP      	(1 << 16)
#define DI_GI_ERR_DUPGAM    	(1 << 17)
#define DI_GI_ERR_SUPPORT_DROP  (1 << 18)
#define DI_GI_ERR_CMYMEDIA	(1 << 19)
#define DI_GI_ERR_GCR		(1 << 20)
#define DI_GI_ERR_MINBH		(1 << 21)
#define DI_GI_ERR_MAXBH		(1 << 22)
#define DI_GI_ERR_BANDSIZE	(1 << 23)

/*
 * operation value of di_setrenderinfo
 */
#define DI_SRI_DITHER	0
#define DI_SRI_GAMMA	1
#define DI_SRI_BGUCR	2
#define DI_SRI_TLIMIT	3

/*
 * di_get_appinfo( )�̕Ԃ�l
 */
#define DI_PINI_OK                  0
#define DI_PINI_KEY_NOT_FOUND      -1
#define DI_PINI_CATEGORY_NOT_FOUND -2
#define DI_PINI_TOOLONG_VALUE      -3
#define DI_PINI_ILLEGAL_ARG        -4
#define DI_PINI_FAILURE            -5
#define DI_PINI_ERROR              -6

/*
 * di_get_appinfo( )�̒l���i�[����z��̍ő咷
 */
#define DI_MAX_VALUE_LEN 32

/*
 * di_get/set_envalue( )�̕Ԃ�l
 */
#define DI_ENV_ASSIGN          1
#define DI_ENV_DEFAULT         0
#define DI_ENV_ERROR          -1
#define DI_ENV_NOEXIST_TABLE  -2
#define DI_ENV_NOEXIST_VALUE  -3
#define DI_ENV_READONLY       -4
#define DI_ENV_ILLEGAL_VALUE  -5
#define DI_ENV_TABLE_BUSY     -6
/*
 * di_get_envdata( )�̕Ԃ�l
 * �������di_get_envdata( )�Ŏg�p���Ă���
 */
#define DI_ENV_TOOLONG_VALUE  -4

/*
 * di_soutput�Ŏw�肷�鏑�����ݕ��@
 */
#define DI_HOST_BLOCK		0x00
#define DI_HOST_NONBLOCK	0x01

/*
 * �f�B�X�N�̎��
 */
#define DI_HDD_DOWNLOAD 0
#define DI_HDD_SPOOL    1
#define DI_RAM_DOWNLOAD 2
#define DI_RAM_SPOOL    3
#define DI_HDD_TMP      4
#define DI_SD_DOWNLOAD  5
#define DI_HDD_IPDS_DOWNLOAD	6
#define DI_SD_IPDS_DOWNLOAD	7
#define DI_SD_PICTBRIDGE	8

/*
 * �X�g���[�W�̎��
 */
#define DI_STORAGE_NVRAM 0 /* NVRAM */

/*
 * �@�\���
 */
#define DI_SYS_FUNC_DUPLEX             (1 << 0)        /* duplex */
#define DI_SYS_FUNC_STAPLE             (1 << 1)        /* staple */
#define DI_SYS_FUNC_PUNCH              (1 << 2)        /* punch */
#define DI_SYS_FUNC_SORT               (1 << 3)        /* sorting */
#define DI_SYS_FUNC_HDD_FS             (1 << 4)        /* HDD for FileSystem */
#define DI_SYS_FUNC_SHIFT              (1 << 5)        /* shift */
#define DI_SYS_FUNC_FINISHER           (1 << 6)        /* Finisher */
#define DI_SYS_FUNC_MAILBOX            (1 << 7)        /* Mail Box */
#define DI_SYS_FUNC_COLOR              (1 << 8)        /* Color (CMYK) */
#define DI_SYS_FUNC_HDD                (1 << 9)        /* HDD */
#define DI_SYS_FUNC_PROOFPRINT         (1 << 10)       /* proof print */
#define DI_SYS_FUNC_SEQUREPRINT        (1 << 11)       /* sequre print */
#define DI_SYS_FUNC_LOCALSTORAGE       (1 << 12)       /* local storage */
#define DI_SYS_FUNC_NETWORK            (1 << 13)       /* network */
#define DI_SYS_FUNC_REMOTEPRINT        (1 << 14)       /* remote print */
#define DI_SYS_FUNC_IEEE1394           (1 << 15)       /* IEEE1394 */
#define DI_SYS_FUNC_MF_MODEL           (1 << 16)       /* MF (not P) Model */
#define DI_SYS_FUNC_LARGEPRINTOUT      (1 << 17)       /* large printout */
#define DI_SYS_FUNC_IEEE802_11b        (1 << 18)       /* IEEE802.11b */
#define DI_SYS_FUNC_USB                (1 << 19)       /* USB */
#define DI_SYS_FUNC_CENTRO             (1 << 20)       /* CENTRO */
#define DI_SYS_FUNC_BLUETOOTH          (1 << 21)       /* Bluetooth */
#define DI_SYS_FUNC_GWMAC              (1 << 22)       /* GWMAC */
#define DI_SYS_FUNC_GIGAETHER          (1 << 23)       /* Gigabit Ethernet */
#define DI_SYS_FUNC_FOLD               (1 << 24)       /* Z�܂� */

/*
 * �p���`���
 */
#define DI_SYS_PUNCH_HOLE_JP2          (1 << 0)        /* 2 JP */
#define DI_SYS_PUNCH_HOLE_US2          (1 << 1)        /* 2 US */ 
#define DI_SYS_PUNCH_HOLE_US3          (1 << 2)        /* 3 US */ 
#define DI_SYS_PUNCH_HOLE_EU4          (1 << 3)        /* 4 EU */
#define DI_SYS_PUNCH_HOLE_NEU4         (1 << 4)        /* 4 Northern EU */

/*
 * �`���l���ԍ�
 */
#define DI_CHANNEL_LPD                 1               /* LPD */
#define DI_CHANNEL_FTP                 2               /* FTP */
#define DI_CHANNEL_RSH                 3               /* RSH */
#define DI_CHANNEL_DIPRINT             4               /* Direct Print */
#define DI_CHANNEL_IPP                 7               /* IPP */
#define DI_CHANNEL_FAX                 11              /* FAX */
#define DI_CHANNEL_CENTRO              12              /* centronics */
#define DI_CHANNEL_PSERVER             13              /* NetWare(PSERVER) */
#define DI_CHANNEL_NPRINTER            14              /* NetWare(NPRINTER) */
#define DI_CHANNEL_SMB                 15              /* SMB */
#define DI_CHANNEL_PAP                 16              /* AppleTalk PAP */
#define DI_CHANNEL_USB                 21              /* USB */
#define DI_CHANNEL_BT                  22              /* BLUETOOTH */

/*
 * PDL ID
 */
#define DI_PDL_AUTO            -1
#define DI_PDL_RPCS            0
#define DI_PDL_RPDL            1
#define DI_PDL_R98             2
#define DI_PDL_R16             3
#define DI_PDL_R55             4
#define DI_PDL_RPGL            5
#define DI_PDL_HPGL2           6
#define DI_PDL_RTIFF           7
#define DI_PDL_POSTSCRIPT      8
#define DI_PDL_PCL             9
#define DI_PDL_PCLXL           10
#define DI_PDL_TIFF            11
#define DI_PDL_PDF             12
#define DI_PDL_BMLINKS         13
#define	DI_PDL_PICTBRIDGE      14
#define	DI_PDL_XPS             16
#define	DI_PDL_MP_TIFF         30
#define	DI_PDL_MP_JPEG         31

#define DI_NOTIFY_CHANGE_OFF    0       /* not notify if changed */
#define DI_NOTIFY_CHANGE_ON     1       /* notify if changed */

#define DI_DISKSTAT_UNKNOWN		0		/* �s��icheck���j */
#define DI_DISKSTAT_NONE		1		/* �f�B�X�N���� */
#define DI_DISKSTAT_READY		2		/* Ready */

#define DI_DEVICETYPE_FILE 0x01
#define DI_STRING_LEN_MAX  112
#define   DI_SET_MODIFY           1
#define   DI_RESET_MODIFY         2
#define   DI_SET_DISP             3
#define   DI_HALF_DISP            4
#define   DI_RESET_DISP           5
#define   DI_SET_ACT              6
#define   DI_RESET_ACT            7

#define DI_LANG_JAPANESE		0		/* ���{�� */
#define DI_LANG_ENGLISH			1		/* �p�� */
#define DI_LANG_FRENCH			2		/* �t�����X�� */
#define DI_LANG_GERMAN			3		/* �h�C�c�� */
#define DI_LANG_ITALIAN			4		/* �C�^���A�� */
#define DI_LANG_SPANISH			5		/* �X�y�C���� */
#define DI_LANG_DUTCH			6		/* �I�����_�� */
#define DI_LANG_SWEDISH			7		/* �X�E�F�[�f���� */
#define DI_LANG_NORWEGIAN		8		/* �m���E�F�[�� */
#define DI_LANG_DANISH			9		/* �f���}�[�N�� */
#define DI_LANG_FINNISH			10		/* �t�B�������h�� */
#define DI_LANG_PORTUGUESE		11		/* �|���g�K���� */
#define DI_LANG_CZECH			12		/* �`�F�R�� */
#define DI_LANG_POLISH			13		/* �|�[�����h�� */
#define DI_LANG_HUNGARIAN		14		/* �n���K���[�� */
#define DI_LANG_CHINESE			15		/* ������ */
#define DI_LANG_TAIWANESE		16		/* ��p�� */
#define DI_LANG_RUSSIAN			17		/* ���V�A�� */
#define DI_LANG_HEBREW			18		/* �w�u���C�� */
#define DI_LANG_ARABIC			19		/* �A���r�A�� */


#define DI_MENU_TYPE_TRAY     5    /* �g���C�ݒ胁�j���[ */
#define DI_MENU_TYPE_EMUSET   8    /* �G�~�����[�V��������������j���[ */
#define DI_MENU_TYPE_PRN_NUM  9    /* �G�~�����[�V��������������j���[ */
#define DI_MENU_TYPE_PCL     15    /* PCL��������j���[ */

#define   DI_ITEM_TYPE_START        0  /* ���[�g�\���̃A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_MENU         1  /* ���j���[�^��ʗp�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_EXECUTING    3  /* ���s�^��ʗp�A�C�e���^�C�v���ʎq  */
#define   DI_ITEM_TYPE_SELECT       2  /* �I�����^��ʗp�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_INTEGER      5  /* �����l�^��ʗp�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_FLOAT        6  /* �����l�^��ʗp�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_PRN_NUM      8  /* ���������ʗp�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_PTIME       14  /* �p���ϔ{���^�C�v���ʎq */
#define   DI_ITEM_TYPE_ANY         15  /* �C�ӃA�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_FLOAT_EXT   16  /* �����l���g�������^�A�C�e���^�C�v���ʎq */
#define   DI_ITEM_TYPE_PTIME_FLT   20  /* �����^�p���ϔ{���^�C�v���ʎq */


#define DI_INTERP_TESTPRINT_SUMMARY			-1	/* �C���^�v���^�T�}���[(�������)��� */
#define DI_INTERP_TESTPRINT_FONTSET				1	/* �t�H���g�Z�b�g��� */
#define DI_INTERP_TESTPRINT_FONTALL				2	/* �S������� */
#define DI_INTERP_TESTPRINT_PROGRAM				3	/* �v���O�����ꗗ��� */
#define DI_INTERP_TESTPRINT_FORMLIST			4	/* �o�^�t�H�[���ꗗ��� */
#define DI_INTERP_TESTPRINT_PSINFO				5	/* PostScript info list */
#define DI_INTERP_TESTPRINT_COLORSAMPLE			6	/* �J���[�T���v����� */
#define DI_INTERP_TESTPRINT_COLORMATCHING		7	/* �F����␳ */
#define DI_INTERP_TESTPRINT_COLORTEST			8	/* �J���[�e�X�g */
#define DI_INTERP_TESTPRINT_GAMMA_USER1			9	/* �K���␳�P */
#define DI_INTERP_TESTPRINT_GAMMA_USER2			10	/* �K���␳�Q */
#define DI_INTERP_TESTPRINT_COLORSHIFT_SET		11	/* �蒅���x�␳�ݒ�p */
#define DI_INTERP_TESTPRINT_COLORSHIFT_CHECK	12	/* �蒅���x�␳�m�F�p */
#define DI_INTERP_TESTPRINT_PDFINFO				13	/* PDF info list */
#define DI_INTERP_TESTPRINT_MICR				20	/* MICR testsheet */
#define DI_INTERP_TESTPRINT_SUMMARY_TEXT		21
#define DI_INTERP_TESTPRINT_FONTSET_DOWNLOAD_PCL	22
#define DI_INTERP_TESTPRINT_FONTSET_DOWNLOAD_PS 	23
#define DI_INTERP_TESTPRINT_FONTSET_DOWNLOAD_PDF	24
#define DI_INTERP_LEN_TESTPRINT_PATH				80

#define	DI_BIT_SW_001	0
#define	DI_BIT_SW_002	1
#define	DI_BIT_SW_003	2
#define	DI_BIT_SW_004	3
#define	DI_BIT_SW_005	4
#define	DI_BIT_SW_006	5
#define	DI_BIT_SW_007	6
#define	DI_BIT_SW_008	7
#define	DI_BIT_SW_009	8
#define	DI_BIT_SW_010	9
#define	DI_BIT_SW_011	10
#define	DI_BIT_SW_012	11
#define	DI_BIT_SW_013	12
#define	DI_BIT_SW_014	13
#define	DI_BIT_SW_015	14
#define	DI_BIT_SW_016	15
#define DI_BIT_SW_NUM	16

/*
 *    request reqson
 */
#define       DI_REQ_PROC_REASON_ENTERLANGUAGE        0       /* PJL ENTER LANGUAGE=XXX */
#define       DI_REQ_PROC_REASON_FILETYPE             1       /* filetype=XXX */
#define       DI_REQ_PROC_REASON_AUTOSENSE            2       /* auto sense */
#define       DI_REQ_PROC_REASON_NOSENSE              3       /* no sense */
#define       DI_REQ_PROC_REASON_EMCHGCMD             4       /* EM CHANGE COMMAND */
#define       DI_REQ_PROC_REASON_PANEL                5       /* panel */

/*
 *	parmanent font
 */
#define DI_DOWNLOADINFO_CREATE		0
#define DI_DOWNLOADINFO_OPEN		1
#define DI_DOWNLOADINFO_DIR		2
#define DI_DOWNLOADINFO_FILE		3

#define DI_PATHMAX	336

#define PERMFONTFILEEXTENSION	".fnt"

/*
*	return of di_get_printcondition()
*/
#define DI_PCND_OK_ALL			3
#define DI_PCND_OK_MEDIA		2
#define DI_PCND_OK_COND			1
#define DI_PCND_OK_NONE			0
#define DI_PCND_NG_ERROR		-1
#define DI_PCND_NG_NOTSUPPORT	-2
/*
*	return of di_get_printconditionShm()
*/
#define DI_PCND_SHM_OK			0
#define DI_PCND_SHM_NG			-1
/*
*	status of di_get_printconditionShm()
*/
#define DI_PCND_SHM_STATUS_COND		0
#define DI_PCND_SHM_STATUS_NONE		-1

/*
*	memory required for zlib
*/
#define DI_ZLIB_MEMORY	(64 * 1024)		/* 64KB */

/*
 *  MICR model type
*/
enum {
	DI_SYS_MODEL_STANDARD,			/* RICOH standard model */
	DI_SYS_MODEL_MICR_SECURE_PCL,	/* Secure PCL MICR model */
	DI_SYS_MODEL_MICR_IPDS,			/* IPDS MICR model */
};

/* memory �m�ۊ֐��̌^ */
typedef char* (*DI_CALLBACK_MEMALLOC)( unsigned long );
/* memory ����֐��̌^ */
typedef void (*DI_CALLBACK_MEMFREE)( char * );
/* �R�[���o�b�N�֐��̌^ */
typedef void (*DI_CALLBACK_FUNC)( void );

/* �f�B�U���\���� */
typedef struct di_ditinfo {
	unsigned char	*dit_ptr;		/* �f�B�U�̐擪�A�h���X */
	unsigned char	x_size;			/* �� */
	unsigned char	y_size;			/* ���� */
	unsigned char	dit_order;		/* �f�B�U�̃I�[�_�l�g�pON/OFF */
									/* [0: �g�p���Ȃ�, 0x40: �g�p����] */
	unsigned short	rearrange;		/* ���A�����W�}�g���b�N�X�p�^�[�� ID */
									/* gps_pagemode_t �Q�� */
	unsigned char	e_flag_max;		/* engine flag for color level: 255 */
	unsigned char	e_flag_mid;		/* engine flag for color level: 1 to 254 */
} dit_info_t, di_ditinfo_t;

/* �𑜓x�\���� */
typedef struct di_resoinfo {
	unsigned int	x;	/* �呖�������𑜓x */
	unsigned int	y;	/* �����������𑜓x */
} reso_info_t, di_resoinfo_t;

/* �𑜓x�\����(�r�b�g�Ƃ̑g����) */
typedef struct di_resolutioninfo {
	unsigned int	x;		/* �呖�������𑜓x */
	unsigned int	y;		/* �����������𑜓x */
	unsigned char	bit;		/* �r�b�g�� */
	unsigned char   paper;		/* ���� */
	unsigned char	dit_mode;	/* �f�B�U���[�h */
	unsigned char   prt_mode;	/* �v�����^�h���C�o�ł̃��[�h */
} resolution_info_t, di_resolutioninfo_t;

/* ���ʋK���l���\���� */
typedef struct di_tlimitinfo {
	di_resolutioninfo_t	reso;	/* �𑜓x�Ball 0�Ȃ�𑜓x�̎w��Ȃ� */
	int					text;	/* �����I�u�W�F�N�g�̑��ʋK���l */
	int					line;	/* ����I�u�W�F�N�g�̑��ʋK���l */
	int					phot;	/* �ʐ^�I�u�W�F�N�g�̑��ʋK���l */
	int					fill;	/* �h��Ԃ��I�u�W�F�N�g�̑��ʋK���l */
} tlimit_info_t, di_tlimitinfo_t;

/* �g���C��� */
typedef struct di_onetrayinfo {
	unsigned short	id;				/* tray ID */
	unsigned char	p_size;			/* �p���T�C�Y(di_paperdef.h�Q��) */
#define DI_PAPER_AUTO          (0x00)          /* ����w��Ȃ� */
#define DI_PAPER_NORMAL        (0x01)          /* ���ʎ� */
#define DI_PAPER_RECYCLE       (0x02)          /* �Đ��� */
#define DI_PAPER_SPECIAL       (0x03)          /* ���ꎆ */
#define DI_PAPER_TRACING       (0x04)          /* �g���[�V���O�� */
#define DI_PAPER_OHP           (0x05)          /* OHP */
#define DI_PAPER_LABEL         (0x06)          /* ���x���� */
#define DI_PAPER_BOND          (0x07)          /* �{���h�� */
#define DI_PAPER_CARDSTOCK     (0x08)          /* �J�[�h�X�g�b�N */
#define DI_PAPER_CARDBOARD     (0x09)          /* ���� */
#define DI_PAPER_PREPRINT      (0x0A)          /* ����ςݎ� */
#define DI_PAPER_LETTER_HEAD   (0x0B)          /* ���^�[�w�b�h�� */
#define DI_PAPER_LTHEAD        (0x0B)          /* �p�~�\�� */
#define DI_PAPER_PUNCH         (0x0C)          /* �p���`�ςݎ� */
#define DI_PAPER_PREPUNCH      (0x0C)          /* �p�~�\�� */
#define DI_PAPER_TAB           (0x0D)          /* �^�u�� */
#define DI_PAPER_COLOR         (0x0E)          /* �F�� */
#define DI_PAPER_NORMAL2ND     (0x0F)          /* ���ʎ�(����) */
#define DI_PAPER_CARDBOARD2ND  (0x10)          /* ����(����) */
#define DI_PAPER_THIN          (0x11)          /* ���� */
#define DI_PAPER_GLOSSY        (0x12)          /* ���� */
#define DI_PAPER_USED          (0x13)          /* �����i�g�p�ς݁j */
#define DI_PAPER_POSTCARD      (0x14)          /* �n�K�L */
#define DI_PAPER_POSTCARD2ND   (0x15)          /* �n�K�L(����) */
#define DI_PAPER_CARDBOARD2    (0x16)          /* �����Q */
#define DI_PAPER_FILM          (0x17)          /* �t�B�������i�}�ʃR�s�[�p�j */
#define DI_PAPER_INKPOST       (0x18)          /* �C���N�W�F�b�g�p�͂��� */
#define DI_PAPER_HG_NORMAL     (0x19)          /* HG���ʎ� */
#define DI_PAPER_ENVELOPE      (0x1A)          /* ���� */
#define DI_PAPER_CARDBOARD3    (0x1B)          /* �����R */
#define DI_PAPER_SPECIAL2      (0x1C)          /* ���ꎆ�Q */
#define DI_PAPER_SPECIAL3      (0x1D)          /* ���ꎆ�R */
#define DI_PAPER_MIDDLETHICK   (0x1E)          /* ������ */
#define DI_PAPER_COATED        (0x1F)          /* �R�[�g�� */
#define DI_PAPER_CARDBOARD2REV (0x20)          /* �����Q(����) */
#define DI_PAPER_CARDBOARD3REV (0x21)          /* �����R(����) */
#define DI_PAPER_NORMAL2       (0x22)          /* ���ʎ��Q */
#define DI_PAPER_THICKGLOSSY   (0x23)          /* ������� */
#define DI_PAPER_SPECIAL4      (0x24)          /* ���ꎆ�S */
#define DI_PAPER_SPECIAL5      (0x25)          /* ���ꎆ�T */
#define DI_PAPER_SPECIAL6      (0x26)          /* ���ꎆ�U */
#define DI_PAPER_USER_DEF1     (0x30)          /* ���[�U�w��P */
#define DI_PAPER_USER_DEF2     (0x31)          /* ���[�U�w��Q */
#define DI_PAPER_USER_DEF3     (0x32)          /* ���[�U�w��R */
#define DI_PAPER_USER_DEF4     (0x33)          /* ���[�U�w��S */
#define DI_PAPER_USER_DEF5     (0x34)          /* ���[�U�w��T */
#define DI_PAPER_USER_DEF6     (0x35)          /* ���[�U�w��U */
#define DI_PAPER_USER_DEF7     (0x36)          /* ���[�U�w��V */
#define DI_PAPER_USER_DEF8     (0x37)          /* ���[�U�w��W */
#define DI_PAPER_USER_DEF0     (0x38)          /* ���[�U�w��O�i���o�^�J�X�^������j */
#define DI_PAPER_COLOR1        (0x40)          /* �F���P           */
#define DI_PAPER_COLOR2        (0x41)          /* �F���Q           */
#define DI_PAPER_COLOR_WHITE   (0x50)          /* �g�p�s��(�W��) */
#define DI_PAPER_COLOR_YELLOW  (0x51)          /* �� */
#define DI_PAPER_COLOR_GREEN   (0x52)          /* �� */
#define DI_PAPER_COLOR_BLUE    (0x53)          /* �� */
#define DI_PAPER_COLOR_PURPLE  (0x54)          /* �� */
#define DI_PAPER_COLOR_IVORY   (0x55)          /* �A�C�{���[ */
#define DI_PAPER_COLOR_ORANGE  (0x56)          /* �� */
#define DI_PAPER_COLOR_PINK    (0x57)          /* �� */
#define DI_PAPER_COLOR_RED     (0x58)          /* �� */
#define DI_PAPER_COLOR_GRAY    (0x59)          /* �D */
#define DI_PAPER_GLOSSY_COATED		(0x60)	/* glossy coated */
#define DI_PAPER_THICK_GLOSSY_COATED	(0x61)	/* thick glossy coated */
#define DI_PAPER_MAT_COATED		(0x62)	/* matt coated */
#define DI_PAPER_THICK_MAT_COATED	(0x63)	/* thick matt coated */
#define DI_PAPER_WATER_PROOF		(0x64)	/* waterproof */
#define DI_PAPER_CARDBOARD4		(0x65)	/* cardboard 4 */
#define DI_PAPER_CARDBOARD4REV		(0x66)	/* cardboard 4 (reverse) */
#define DI_PAPER_COATED_HIGH_GLOSSY	(0x67)	/* high glossy coated */
#define DI_PAPER_SEMIGLOSSY		(0x68)
#define DI_PAPER_INKJETPLAIN	(0x69)
#define DI_PAPER_MATFILM		(0x6C)
#define DI_PAPER_CADCOATED		(0x6D)
#define DI_PAPER_NONE          (0x80)          /* �g���C�ɐݒ肳��Ă��鎆��(����PDL���g���C�w�莞�̂ݎg�p��) */
#define DI_PAPER_USER_DEF9			(0x81)	/* ���[�U�w��X(IMSS) */
#define DI_PAPER_USER_DEF10			(0x82)	/* ���[�U�w��P�O(IMSS) */
#define DI_PAPER_USER_DEF11			(0x83)	/* ���[�U�w��P�P(IMSS) */
#define DI_PAPER_USER_DEF12			(0x84)	/* ���[�U�w��P�Q(IMSS) */
#define DI_PAPER_USER_DEF13			(0x85)	/* ���[�U�w��P�R(IMSS) */
#define DI_PAPER_USER_DEF14			(0x86)	/* ���[�U�w��P�S(IMSS) */
#define DI_PAPER_USER_DEF15			(0x87)	/* ���[�U�w��P�T(IMSS) */
#define DI_PAPER_USER_DEF16			(0x88)	/* ���[�U�w��P�U(IMSS) */
#define DI_PAPER_USER_DEF17			(0x89)	/* ���[�U�w��P�V(IMSS) */
#define DI_PAPER_USER_DEF18			(0x8A)	/* ���[�U�w��P�W(IMSS) */
#define DI_PAPER_USER_DEF19			(0x8B)	/* ���[�U�w��P�X(IMSS) */
#define DI_PAPER_USER_DEF20			(0x8C)	/* ���[�U�w��Q�O(IMSS) */
#define DI_PAPER_USER_DEF21			(0x8D)	/* ���[�U�w��Q�P(IMSS) */
#define DI_PAPER_USER_DEF22			(0x8E)	/* ���[�U�w��Q�Q(IMSS) */
#define DI_PAPER_USER_DEF23			(0x8F)	/* ���[�U�w��Q�R(IMSS) */
#define DI_PAPER_USER_DEF24			(0x90)	/* ���[�U�w��Q�S(IMSS) */
#define DI_PAPER_USER_DEF25			(0x91)	/* ���[�U�w��Q�T(IMSS) */
#define DI_PAPER_USER_DEF26			(0x92)	/* ���[�U�w��Q�U(IMSS) */
#define DI_PAPER_USER_DEF27			(0x93)	/* ���[�U�w��Q�V(IMSS) */
#define DI_PAPER_USER_DEF28			(0x94)	/* ���[�U�w��Q�W(IMSS) */
#define DI_PAPER_USER_DEF29			(0x95)	/* ���[�U�w��Q�X(IMSS) */
#define DI_PAPER_USER_DEF30			(0x96)	/* ���[�U�w��R�O(IMSS) */
#define DI_PAPER_USER_DEF31			(0x97)	/* ���[�U�w��R�P(IMSS) */
#define DI_PAPER_USER_DEF32			(0x98)	/* ���[�U�w��R�Q(IMSS) */
#define DI_PAPER_USER_DEF33			(0x99)	/* ���[�U�w��R�R(IMSS) */
#define DI_PAPER_USER_DEF34			(0x9A)	/* ���[�U�w��R�S(IMSS) */
#define DI_PAPER_USER_DEF35			(0x9B)	/* ���[�U�w��R�T(IMSS) */
#define DI_PAPER_USER_DEF36			(0x9C)	/* ���[�U�w��R�U(IMSS) */
#define DI_PAPER_USER_DEF37			(0x9D)	/* ���[�U�w��R�V(IMSS) */
#define DI_PAPER_USER_DEF38			(0x9E)	/* ���[�U�w��R�W(IMSS) */
#define DI_PAPER_USER_DEF39			(0x9F)	/* ���[�U�w��R�X(IMSS) */
#define DI_PAPER_USER_DEF40			(0xA0)	/* ���[�U�w��S�O(IMSS) */
#define DI_PAPER_USER_DEF41			(0xA1)	/* ���[�U�w��S�P(IMSS) */
#define DI_PAPER_USER_DEF42			(0xA2)	/* ���[�U�w��S�Q(IMSS) */
#define DI_PAPER_USER_DEF43			(0xA3)	/* ���[�U�w��S�R(IMSS) */
#define DI_PAPER_USER_DEF44			(0xA4)	/* ���[�U�w��S�S(IMSS) */
#define DI_PAPER_USER_DEF45			(0xA5)	/* ���[�U�w��S�T(IMSS) */
#define DI_PAPER_USER_DEF46			(0xA6)	/* ���[�U�w��S�U(IMSS) */
#define DI_PAPER_USER_DEF47			(0xA7)	/* ���[�U�w��S�V(IMSS) */
#define DI_PAPER_USER_DEF48			(0xA8)	/* ���[�U�w��S�W(IMSS) */
#define DI_PAPER_USER_DEF49			(0xA9)	/* ���[�U�w��S�X(IMSS) */
#define DI_PAPER_USER_DEF50			(0xAA)	/* ���[�U�w��T�O(IMSS) */
#define DI_PAPER_USER_DEF51			(0xAB)	/* ���[�U�w��T�P(IMSS) */
#define DI_PAPER_USER_DEF52			(0xAC)	/* ���[�U�w��T�Q(IMSS) */
#define DI_PAPER_USER_DEF53			(0xAD)	/* ���[�U�w��T�R(IMSS) */
#define DI_PAPER_USER_DEF54			(0xAE)	/* ���[�U�w��T�S(IMSS) */
#define DI_PAPER_USER_DEF55			(0xAF)	/* ���[�U�w��T�T(IMSS) */
#define DI_PAPER_USER_DEF56			(0xB0)	/* ���[�U�w��T�U(IMSS) */
#define DI_PAPER_USER_DEF57			(0xB1)	/* ���[�U�w��T�V(IMSS) */
#define DI_PAPER_USER_DEF58			(0xB2)	/* ���[�U�w��T�W(IMSS) */
#define DI_PAPER_USER_DEF59			(0xB3)	/* ���[�U�w��T�X(IMSS) */
#define DI_PAPER_USER_DEF60			(0xB4)	/* ���[�U�w��U�O(IMSS) */
#define DI_PAPER_USER_DEF61			(0xB5)	/* ���[�U�w��U�P(IMSS) */
#define DI_PAPER_USER_DEF62			(0xB6)	/* ���[�U�w��U�Q(IMSS) */
#define DI_PAPER_USER_DEF63			(0xB7)	/* ���[�U�w��U�R(IMSS) */
#define DI_PAPER_USER_DEF64			(0xB8)	/* ���[�U�w��U�S(IMSS) */
#define DI_PAPER_USER_DEF65			(0xB9)	/* ���[�U�w��U�T(IMSS) */
#define DI_PAPER_USER_DEF66			(0xBA)	/* ���[�U�w��U�U(IMSS) */
#define DI_PAPER_USER_DEF67			(0xBB)	/* ���[�U�w��U�V(IMSS) */
#define DI_PAPER_USER_DEF68			(0xBC)	/* ���[�U�w��U�W(IMSS) */
#define DI_PAPER_USER_DEF69			(0xBD)	/* ���[�U�w��U�X(IMSS) */
#define DI_PAPER_USER_DEF70			(0xBE)	/* ���[�U�w��V�O(IMSS) */
#define DI_PAPER_USER_DEF71			(0xBF)	/* ���[�U�w��V�P(IMSS) */
#define DI_PAPER_USER_DEF72			(0xC0)	/* ���[�U�w��V�Q(IMSS) */
#define DI_PAPER_USER_DEF73			(0xC1)	/* ���[�U�w��V�R(IMSS) */
#define DI_PAPER_USER_DEF74			(0xC2)	/* ���[�U�w��V�S(IMSS) */
#define DI_PAPER_USER_DEF75			(0xC3)	/* ���[�U�w��V�T(IMSS) */
#define DI_PAPER_USER_DEF76			(0xC4)	/* ���[�U�w��V�U(IMSS) */
#define DI_PAPER_USER_DEF77			(0xC5)	/* ���[�U�w��V�V(IMSS) */
#define DI_PAPER_USER_DEF78			(0xC6)	/* ���[�U�w��V�W(IMSS) */
#define DI_PAPER_USER_DEF79			(0xC7)	/* ���[�U�w��V�X(IMSS) */
#define DI_PAPER_USER_DEF80			(0xC8)	/* ���[�U�w��W�O(IMSS) */
#define DI_PAPER_USER_DEF81			(0xC9)	/* ���[�U�w��W�P(IMSS) */
#define DI_PAPER_USER_DEF82			(0xCA)	/* ���[�U�w��W�Q(IMSS) */
#define DI_PAPER_USER_DEF83			(0xCB)	/* ���[�U�w��W�R(IMSS) */
#define DI_PAPER_USER_DEF84			(0xCC)	/* ���[�U�w��W�S(IMSS) */
#define DI_PAPER_USER_DEF85			(0xCD)	/* ���[�U�w��W�T(IMSS) */
#define DI_PAPER_USER_DEF86			(0xCE)	/* ���[�U�w��W�U(IMSS) */
#define DI_PAPER_USER_DEF87			(0xCF)	/* ���[�U�w��W�V(IMSS) */
#define DI_PAPER_USER_DEF88			(0xD0)	/* ���[�U�w��W�W(IMSS) */
#define DI_PAPER_USER_DEF89			(0xD1)	/* ���[�U�w��W�X(IMSS) */
#define DI_PAPER_USER_DEF90			(0xD2)	/* ���[�U�w��X�O(IMSS) */
#define DI_PAPER_USER_DEF91			(0xD3)	/* ���[�U�w��X�P(IMSS) */
#define DI_PAPER_USER_DEF92			(0xD4)	/* ���[�U�w��X�Q(IMSS) */
#define DI_PAPER_USER_DEF93			(0xD5)	/* ���[�U�w��X�R(IMSS) */
#define DI_PAPER_USER_DEF94			(0xD6)	/* ���[�U�w��X�S(IMSS) */
#define DI_PAPER_USER_DEF95			(0xD7)	/* ���[�U�w��X�T(IMSS) */
#define DI_PAPER_USER_DEF96			(0xD8)	/* ���[�U�w��X�U(IMSS) */
#define DI_PAPER_USER_DEF97			(0xD9)	/* ���[�U�w��X�V(IMSS) */
#define DI_PAPER_USER_DEF98			(0xDA)	/* ���[�U�w��X�W(IMSS) */
#define DI_PAPER_USER_DEF99			(0xDB)	/* ���[�U�w��X�X(IMSS) */
#define DI_PAPER_USER_DEF100		(0xDC)	/* ���[�U�w��P�O�O(IMSS) */

	unsigned char	p_kind;			/* �����`(�������define) */
#define DI_TRAY_MANUAL          (1 << 0)    /* (attr) manual */
#define DI_TRAY_TANDEM          (1 << 1)    /* (attr) tandem */
#define DI_TRAY_NODUPLEX        (1 << 2)    /* (attr) noduplex */
#define DI_TRAY_LOCKED          (1 << 3)    /* (attr) tray locked */
#define DI_TRAY_SIZE_SENSE      (1 << 4)    /* (attr) sense paper size */
#define DI_TRAY_NODUPLEX_PAPER  (1 << 5)    /* (attr) noduplex paper(size | type) */
#define DI_TRAY_FRONTCOVERPRINT (1 << 6)    /* (attr) frontcoverprint */
#define DI_TRAY_SLIPSHEET       (1 << 7)    /* (attr) slipsheet */
#define DI_TRAY_INNERLCT        (1 << 8)    /* (attr) INNER LCT */
#define DI_TRAY_CHAPTERSHEET1   (1 << 9)    /* (attr) chaptersheet1 */
#define DI_TRAY_CHAPTERSHEET2   (1 << 10)   /* (attr) chaptersheet2 */
#define DI_TRAY_CHAPTERSHEET3   (1 << 11)   /* (attr) chaptersheet3 */
#define DI_TRAY_CHAPTERSHEET4   (1 << 12)   /* (attr) chaptersheet4 */
#define DI_TRAY_CHAPTERSHEET5   (1 << 13)   /* (attr) chaptersheet5 */
#define DI_TRAY_CHAPTERSHEET6   (1 << 14)   /* (attr) chaptersheet6 */
#define DI_TRAY_CHAPTERSHEET7   (1 << 15)   /* (attr) chaptersheet7 */
#define DI_TRAY_BACKCOVERPRINT  (1 << 16)   /* (attr) backcoverprint */
#define DI_TRAY_PARTITION       (1 << 17)   /* (attr) partition */
#define DI_TRAY_TANDEM_SEPARATE (1 << 18)   /* (attr) tandem(separate) */
#define DI_TRAY_ROLL            (1 << 19)   /* (attr) roll tray */
#define DI_TRAY_MSIZESENSE_VALID	(1 << 20)	/* (attr) �荷�������T�C�Y���m�L�� */
#define DI_TRAY_SINGLE_PAPER    (1 << 21)   /* (attr) �ꖇ�g���C */
#define DI_TRAY_CHAPTERSHEET8   (1 << 22)   /* (attr) chaptersheet8 */
#define DI_TRAY_CHAPTERSHEET9   (1 << 23)   /* (attr) chaptersheet9 */
#define DI_TRAY_SMALLSIZE_TYPE  (1 << 24)   /* (attr) ���T�C�Y�g���C�ݒ肪ON */
	unsigned long	attr;			/* �g���C���(�������define) */
#define DI_TRAY_PAPEREND       (1 << 0)
#define DI_TRAY_BUSY           (1 << 1)
#define DI_TRAY_SETFAIL        (1 << 2)
#define DI_TRAY_ERROR          (1 << 3)
#define DI_TRAY_COPEN          (1 << 4)
#define DI_TRAY_MAN_PAPEREXIST (1 << 5)
#define DI_TRAY_MAN_OPEN       (1 << 6)
#define DI_TRAY_MAN_SIZE       (1 << 7)
#define DI_TRAY_TAN_MISSSET    (1 << 8)
#define DI_TRAY_TAN_BUSY       (1 << 9)
#define DI_TRAY_UNLOAD         (1 << 10)
#define DI_TRAY_TAN_PAPEREXIST (1 << 11)
#define DI_TRAY_TAN_INVALID    (1 << 12)
#define DI_TRAY_DOOR_OPEN      (1 << 13)
	unsigned long	status;			/* �X�e�[�^�X(�������define) */
	unsigned long	p_length;		/* �p������(0.1mm�P��) */
	unsigned long	p_width;		/* �p����(0.1mm�P��) */
} tray_info_t, di_onetrayinfo_t;

typedef struct di_trayinfo {
	long				tray_num;					/* �g���C�� */
	di_onetrayinfo_t	trayinfo[DI_MAX_TRAY_NUM];	/* �e�g���C�̏�� */
} di_trayinfo_t;

typedef struct di_optinfo {
#define DI_OPT_EXT_EXTLCT              (1 << 31)       /* ext. LCT */
#define DI_OPT_EXT_TRAY2               (1 << 30)       /* Tray2 */
#define DI_OPT_EXT_TRAY3               (1 << 29)       /* Tray3 */
#define DI_OPT_EXT_BANK                (1 << 28)       /* BANK */
#define DI_OPT_EXT_TANDEM              (1 << 27)       /* TANDEM */
#define DI_OPT_EXT_TRAYMAN             (1 << 26)       /* MANUAL TRAY */
#define DI_OPT_EXT_INLCT               (1 << 25)       /* INNER LCT */
#define DI_OPT_EXT_TRAY4               (1 << 24)       /* Tray4 */
#define DI_OPT_EXT_TRAY5               (1 << 23)       /* Tray5 */
#define DI_OPT_EXT_INSERTER            (1 << 22)       /* INSERTER */
#define DI_OPT_EXT_TRAY7               (1 << 21)       /* Tray7 */
#define DI_OPT_EXT_ROLL_FEEDER         (1 << 20)       /* Roll Unit */
#define DI_OPT_EXT_INSERTER2           (1 << 19)       /* INSERTER2(2�i) */
#define DI_OPT_EXT_LARGELCT            (1 << 18)       /* Large Size LCT */
#define DI_OPT_EXT_ROLL_FEEDER2        (1 << 17)       /* Roll Unit2 */
	unsigned long	tray;		/* �����n�I�v�V�����@��t���O */
#define DI_OPT_EXT_1BIN                (1 << 31)       /* 1BIN */
#define DI_OPT_EXT_EXTTRAY             (1 << 30)       /* ext. tray */
#define DI_OPT_EXT_INSHIFT             (1 << 29)       /* INNER SHIFT */
#define DI_OPT_EXT_SUPERIOR            (1 << 28)       /* SUPERIOR */
	unsigned long	bin;		/* �r���n�I�v�V�����@��t���O */
#define DI_OPT_EXT_DUPLEX              (1)
	unsigned long	duplex;		/* ���ʃ��j�b�g�I�v�V�����@��t���O */
#define DI_OPT_EXT_FIN_YUKON           (1)
#define DI_OPT_EXT_FIN_LAWRENCE        (2)
#define DI_OPT_EXT_FIN_SADDLE          (3)             /* TONEGAWA */
#define DI_OPT_EXT_FIN_SHINKAWA        (4)
#define DI_OPT_EXT_FIN_FUJIGAWA        (5)
#define DI_OPT_EXT_FIN_KING            (6)
#define DI_OPT_EXT_FIN_BRAZOS_NON      (7)
#define DI_OPT_EXT_FIN_BRAZOS_PRF      (8)
#define DI_OPT_EXT_FIN_VICTORIA_B      (9)
#define DI_OPT_EXT_FIN_ZAIRE_SDL       (10)
#define DI_OPT_EXT_FIN_ZAIRE_NON       (11)
#define DI_OPT_EXT_FIN_TONEGAWA_C      (12)
#define DI_OPT_EXT_FIN_PLOKMATIC       (13)    /* VICTORIA-B+PLOKMATIC */
#define DI_OPT_EXT_FIN_KINUGAWA        (14)
#define DI_OPT_EXT_FIN_HUDOSON         (15)    /* GAIA_P1�pFIN �{�̔r�����Ԃ��ăX�e�[�v���̂݉\ */
#define DI_OPT_EXT_FIN_EUPHRATES_SDL   (16)
#define DI_OPT_EXT_FIN_EUPHRATES_NON   (17)
#define DI_OPT_EXT_FIN_TIGRIS          (18)
#define DI_OPT_EXT_FIN_KANOGAWA        (19)
#define DI_OPT_EXT_FIN_ATLANTIC_A      (20)    /* �W���o���@ */
#define DI_OPT_EXT_FIN_ATLANTIC_B      (21)    /* �t�H���_�[�@�i�W���o���@�{�N���X���j�b�g�j */
#define	DI_OPT_EXT_FIN_ELBE            (23)	/* ELBE */
#define	DI_OPT_EXT_FIN_SAKAWAGAWA	(24)
#define DI_OPT_EXT_FIN_COLUMBIA        (25)    /* COLUMBIA */
#define DI_OPT_EXT_FIN_SHINJIKO        (26)    /* COLUMBIA+SHINJIKO */
#define DI_OPT_EXT_FIN_EUPHRATES_1BIT  (27)    /* EUPHRATES-D(1 hole) */
#define DI_OPT_EXT_FIN_EUPHRATES_2BIT  (28)    /* EUPHRATES-D(2 holes) */
#define DI_OPT_EXT_FIN_RUBICON         (29)    /* RUBICON */
#define DI_OPT_EXT_FIN_AMUR_SDL        (30)    /* AMUR(saddle stitch) */
#define DI_OPT_EXT_FIN_AMUR_NON        (31)    /* AMUR */
#define DI_OPT_EXT_FIN_VOLGA_SDL       (32)    /* VOLGA(saddle stitch) */
#define DI_OPT_EXT_FIN_VOLGA_NON       (33)    /* VOLGA */
#define DI_OPT_EXT_FIN_COLUMBIA_SDL    (34)    /* COLUMBIA(saddle stitch) */
#define DI_OPT_EXT_FIN_UYUNI           (35)    /* UYUNI(�j�����Ԃ�) */
	unsigned long	fin;		/* �t�B�j�b�V���n�I�v�V�����@��t���O */
#define DI_OPT_EXT_MB_9BIN             (1)             /* MB 9BIN */
#define DI_OPT_EXT_MB_9BIN_P           (2)             /* MB_P 9BIN+proof */
#define DI_OPT_EXT_MB_SAXBY            (3)             /* SAXBY */
#define DI_OPT_EXT_MB_POTOMAC          (4)             /* POTOMAC */
#define DI_OPT_EXT_MB_JACK             (5)             /* JACK */
#define DI_OPT_EXT_MB_ONTARIO          (6)             /* ONTARIO */
	unsigned long	mbox;		/* ���[���{�b�N�X�n�I�v�V�����@��t���O */
#define DI_OPT_EXT_DEVELOPMENT_R       (1 << 31)       /* RED DEVELOPMENT */
#define DI_OPT_EXT_ZFOLD_UNIT          (1 << 30)       /* ZFOLD UNIT */
	unsigned long	misc;		/* ��L�ȊO�̃I�v�V�����@��t���O */
#define DI_OPT_EXT_CF_UNIT             (1 << 31)       /* CF UNIT */
#define DI_OPT_EXT_ADF                 (1 << 30)       /* ADF */
#define DI_OPT_EXT_GBC_PUNCH           (1 << 29)       /* GBC�p���`���j�b�g */
#define DI_OPT_EXT_KARUN_SDL           (1 << 28)       /* ���Ԃ����j�b�g(KARUN) */
	unsigned long	non_prt;	/* �v�����^�Ɋ֘A���Ȃ��I�v�V�����@��t���O */
} di_optinfo_t;

typedef struct di_ethertalk_info {
/* length */
#define	DI_MAX_ATINFO_OBJECT_NAME_LEN	32
#define	DI_MAX_ATINFO_TYPE_NAME_LEN		32
#define	DI_MAX_ATINFO_ZONE_NAME_LEN		32
#define	DI_MAX_ATINFO_MACADDR_LEN		6

#define	DI_ATINFO_FLAG_OBJECT_NAME		(1 << 0)
#define	DI_ATINFO_FLAG_TYPE_NAME		(1 << 1)
#define	DI_ATINFO_FLAG_ZONE_NAME		(1 << 2)
#define	DI_ATINFO_FLAG_MACADDR			(1 << 3)
	unsigned long		flag;								/* �t���O */
	unsigned char		object_name[DI_MAX_ATINFO_OBJECT_NAME_LEN + 1];		/* NULL�^�[�~�l�[�g (R/W) */
	unsigned char		type_name[DI_MAX_ATINFO_TYPE_NAME_LEN + 1];		/* NULL�^�[�~�l�[�g (ReadOnly)*/
	unsigned char		zone_name[DI_MAX_ATINFO_ZONE_NAME_LEN + 1];		/* NULL�^�[�~�l�[�g (R/W)*/
	unsigned char		macaddr[DI_MAX_ATINFO_MACADDR_LEN];			/* (ReadOnly) */
} di_ethertalk_info_t;

typedef struct di_ujob_info {

/*
 *	flag
 */
#define	DI_UPARAM_DATE					(1 << 0)
#define	DI_UPARAM_TIME					(1 << 1)
#define	DI_UPARAM_TRACKID				(1 << 2)
#define	DI_UPARAM_USERCODE				(1 << 3)
#define	DI_UPARAM_USERID				(1 << 4)
#define	DI_UPARAM_JOBID					(1 << 5)
#define	DI_UPARAM_JOBPASSWORD			(1 << 6)
#define	DI_UPARAM_DISPCHARSET			(1 << 7)
#define	DI_UPARAM_HOSTCHARSET			(1 << 8)
#define	DI_UPARAM_HOSTLOGINNAME			(1 << 9)
#define	DI_UPARAM_HOSTNAME				(1 << 10)
#define	DI_UPARAM_HOSTPORTNAME			(1 << 11)
#define	DI_UPARAM_HOSTPRINTERNAME		(1 << 12)
#define	DI_UPARAM_PROOFJOB				(1 << 13)
#define	DI_UPARAM_SECUREJOB				(1 << 14)
#define	DI_UPARAM_JOBNAME				(1 << 15)
#define	DI_UPARAM_OWNERID				(1 << 16)
#define	DI_UPARAM_PRINTINFO				(1 << 17)
#define	DI_UPARAM_AUTHUSERNAME			(1 << 18)
#define	DI_UPARAM_AUTHPASSWORD			(1 << 19)
#define	DI_UPARAM_AUTHENCRYPTMETHOD		(1 << 20)
#define	DI_UPARAM_AUTHENCRYPTSETTING	(1 << 21)
#define	DI_UPARAM_JOBPASSWORD_EXT		(1 << 22)
#define	DI_UPARAM_PAUSEDJOB			(1 << 23)
#define	DI_UPARAM_FORMJOB			(1 << 24)
#define	DI_UPARAM_AUTHUSERNAMECHARSET	(1 << 25)
#define	DI_UPARAM_AUTHPASSWORDCHARSET	(1 << 26)
#define	DI_UPARAM_NDISPCHARSET		(1 << 27)
#define	DI_UPARAM_NHOSTCHARSET		(1 << 28)
#define	DI_UPARAM_BILLINGCODE		(1 << 29)
#define	DI_UPARAM_PRINTAPPOINTEDTIME	(1 << 30)
#define	DI_UPARAM_EXT2					(1 << 31)
/*
 *	flag2
 */
#define	DI_UPARAM_DRIVERKINDINFO		(1 << 0)
#define	DI_UPARAM_FOLDERNUMBER			(1 << 1)
#define	DI_UPARAM_FOLDERPASSWORD		(1 << 2)
#define	DI_UPARAM_EXT3					(1 << 31)
/*
 *	max length
 */
#define	DI_MAX_UPARAM_DATE_LEN				10
#define	DI_MAX_UPARAM_TIME_LEN				8
#define	DI_MAX_UPARAM_TRACKID_LEN			20
#define	DI_MAX_UPARAM_USERCODE_LEN			8
#define	DI_MAX_UPARAM_USERID_LEN			8
#define	DI_MAX_UPARAM_JOBID_LEN				20
#define	DI_MAX_UPARAM_JOBPASSWORD_LEN		4
#define	DI_MAX_UPARAM_DISPCHARSET_LEN		63
#define	DI_MAX_UPARAM_HOSTCHARSET_LEN		63
#define	DI_MAX_UPARAM_HOSTLOGINNAME_LEN		20
#define	DI_MAX_UPARAM_HOSTNAME_LEN			63
#define	DI_MAX_UPARAM_HOSTPORTNAME_LEN		64
#define	DI_MAX_UPARAM_HOSTPRINTERNAME_LEN	64
#define	DI_MAX_UPARAM_JOBNAME_LEN			232
#define	DI_MAX_UPARAM_OWNERID_LEN			20
#define	DI_MAX_UPARAM_PRINTINFO_LEN			230
#define	DI_MAX_UPARAM_AUTHUSERNAME_LEN		217
#define	DI_MAX_UPARAM_AUTHPASSWORD_LEN		217
#define	DI_MAX_UPARAM_JOBPASSWORD_EXT_LEN	8
#define	DI_MAX_UPARAM_BILLINGCODE_LEN		32
#define	DI_MAX_UPARAM_PRINTAPPOINTEDTIME_LEN	5
#define	DI_MAX_UPARAM_FOLDERPASSWORD_LEN	8
/*
 *	driver kind info
 */
#define	DI_UPARAM_DRIVERKINDINFO_INBOX			(1)
#define	DI_UPARAM_DRIVERKINDINFO_PCL6			(2)
#define	DI_UPARAM_DRIVERKINDINFO_PCL6UD			(3)
#define	DI_UPARAM_DRIVERKINDINFO_PCL6UDGENERIC	(4)
#define	DI_UPARAM_DRIVERKINDINFO_PS				(5)
#define	DI_UPARAM_DRIVERKINDINFO_PSUD			(6)
#define	DI_UPARAM_DRIVERKINDINFO_PSUDGENERIC	(7)
#define	DI_UPARAM_DRIVERKINDINFO_RPCSBASIC		(8)
#define	DI_UPARAM_DRIVERKINDINFO_RPCSXPS		(9)
#define	DI_UPARAM_DRIVERKINDINFO_RPCS			(10)


	unsigned long	flag;
	union {
		unsigned char	date[DI_MAX_UPARAM_DATE_LEN + 1];
		unsigned char	time[DI_MAX_UPARAM_TIME_LEN + 1];
		unsigned char	trackid[DI_MAX_UPARAM_TRACKID_LEN + 1];
		unsigned char	usercode[DI_MAX_UPARAM_USERCODE_LEN + 1];
		unsigned char	billingcode[DI_MAX_UPARAM_BILLINGCODE_LEN + 2];
		unsigned char	userid[DI_MAX_UPARAM_USERID_LEN + 1];
		unsigned char	jobid[DI_MAX_UPARAM_JOBID_LEN + 1];
		unsigned char	jobpassword[DI_MAX_UPARAM_JOBPASSWORD_LEN + 1];
		unsigned char	dispcharset[DI_MAX_UPARAM_DISPCHARSET_LEN + 1];
		unsigned char	hostcharset[DI_MAX_UPARAM_HOSTCHARSET_LEN + 1];
		unsigned char	hostloginname[DI_MAX_UPARAM_HOSTLOGINNAME_LEN + 1];
		unsigned char	hostname[DI_MAX_UPARAM_HOSTNAME_LEN + 1];
		unsigned char	hostportname[DI_MAX_UPARAM_HOSTPORTNAME_LEN + 1];
		unsigned char	hostprintername[DI_MAX_UPARAM_HOSTPRINTERNAME_LEN + 1];
		unsigned char	jobname[DI_MAX_UPARAM_JOBNAME_LEN + 1];
		unsigned char	ownerid[DI_MAX_UPARAM_OWNERID_LEN + 1];
		unsigned char	printinfo[DI_MAX_UPARAM_PRINTINFO_LEN + 1];
		unsigned char	authusername[DI_MAX_UPARAM_AUTHUSERNAME_LEN + 1];
		unsigned char	authpassword[DI_MAX_UPARAM_AUTHPASSWORD_LEN + 1];
		int		authencryptmethod;
		int		authencryptsetting;
		unsigned char	jobpassword_ext[DI_MAX_UPARAM_JOBPASSWORD_EXT_LEN + 1];
		short			authusernamecharset;
		short			authpasswordcharset;
		short			ndispcharset;
		short			nhostcharset;
		unsigned char	printappointedtime[DI_MAX_UPARAM_PRINTAPPOINTEDTIME_LEN + 1];
		int				driverkindinfo;
		unsigned short	foldernumber;
		unsigned char	folderpassword[DI_MAX_UPARAM_FOLDERPASSWORD_LEN + 1];
		unsigned char	dummy[240];
	} up;
	unsigned long	flag2;
} di_ujob_info_t;


typedef struct di_status {

#define	DI_ST_CODE_MAX		32

	unsigned char		cur_interpreter;			/* ���쒆�̃C���^�v���^ID */
	int					state;						/* state */
	int					st_code_num;				/* st_code[]�ŗL���Ȑ� */
	unsigned long		st_code[DI_ST_CODE_MAX];	/* status code list */
#define	DI_SYS_FUNC_DUPLEX			(1 << 0)		/* duplex */
#define	DI_SYS_FUNC_STAPLE			(1 << 1)		/* staple */
#define	DI_SYS_FUNC_PUNCH			(1 << 2)		/* punch */
#define	DI_SYS_FUNC_SORT			(1 << 3)		/* sorting */
#define	DI_SYS_FUNC_HDD_FS			(1 << 4)		/* HDD for FileSystem */
#define	DI_SYS_FUNC_SHIFT			(1 << 5)		/* shift */
#define	DI_SYS_FUNC_FINISHER		(1 << 6)		/* Finisher */
#define	DI_SYS_FUNC_MAILBOX			(1 << 7)		/* Mail Box */
#define	DI_SYS_FUNC_COLOR			(1 << 8)		/* Color (CMYK) */
#define	DI_SYS_FUNC_HDD				(1 << 9)		/* HDD */
#define	DI_SYS_FUNC_PROOFPRINT		(1 << 10)	/* proof print */
#define	DI_SYS_FUNC_SEQUREPRINT		(1 << 11)	/* sequre print */
#define	DI_SYS_FUNC_LOCALSTORAGE	(1 << 12)	/* local storage */
#define	DI_SYS_FUNC_NETWORK			(1 << 13)	/* network */
#define	DI_SYS_FUNC_REMOTEPRINT		(1 << 14)	/* remote print */
#define	DI_SYS_FUNC_IEEE1394		(1 << 15)	/* IEEE1394 */
#define	DI_SYS_FUNC_IEEE802_11b		(1 << 18)	/* IEEE802.11b */
#define	DI_SYS_FUNC_USB				(1 << 19)	/* USB */
#define	DI_SYS_FUNC_BLUETOOTH		(1 << 21)	/* Bluetooth */
	unsigned long		function_disable;	/* �@�\�g�p�s��(SC) */
#define	DI_STATE_OFFLINE			(1 << 0)		/* ST_OFFLINE */
#define	DI_STATE_HEXDUMP			(1 << 1)		/* ST_HEXDUMP */
#define	DI_STATE_WARMING_UP			(1 << 2)		/* ST_WARMING_UP */
#define	DI_STATE_ENERGY_SAVE		(1 << 3)		/* ST_ENERGY_SAVE */
#define	DI_STATE_PRINTING			(1 << 4)		/* ST_PROCESSIG (�����) */
#define	DI_STATE_PROCESSING			(1 << 5)		/* ST_PROCESSING�i�f�[�^�������j */
#define	DI_STATE_PREHEAT			(1 << 6)		/* ST_PREHEAT */
#define	DI_STATE_WAITING			(1 << 7)		/* ST_WAITING */
#define	DI_STATE_JOB_RESETTING		(1 << 8)		/* ST_JOB_RESETTING */
#define	DI_STATE_INT_REQ			(1 << 9)		/* �����݃R�s�[�i�����~�j�v�� */
#define	DI_STATE_INT_PAUSE			(1 << 10)	/* �����݃R�s�[�� */
#define	DI_STATE_CALIBRATING		(1 << 11)	/* calibrating */ 
#define	DI_STATE_SUPPLYING_TONER	(1 << 12)	/* supplying toner */
#define	DI_STATE_INIT_DEVELOPER		(1 << 13)	/* initial developer */
#define	DI_STATE_COOLING_DOWN		(1 << 14)	/* cooling down */
#define	DI_STATE_CARDSAVE			(1 << 31)	/* �J�[�h�Z�[�u */
	unsigned long		state_detail;		/* ��Ԃ̏ڍׂ��r�b�g�ł���킷 */
	/* st_code[]�̌x�������̃G���[�R�[�h�̐� */
	int			st_code_num_warning;
	/* st_code[]�̃I�y���[�^�R�[�������̃G���[�R�[�h�̐� */
	int			st_code_num_error;
} di_status_t;


typedef struct di_diskinfo {

#define DI_MAX_HDD_PATH_LEN 64

	char	stat;						/* status              */
	char	path[DI_MAX_HDD_PATH_LEN];	/* path                */
	long	f_bsize;					/* block size (bytes)  */
	long	f_blocks;					/* total blocks        */
	long	f_bfree;					/* free blocks         */
	long	reserve;					/* reserve             */
} di_diskinfo_t;

typedef struct di_res_reqpaper{
	unsigned short	type;		/* GWID_GpsPage_TrayRequest_Res */
	unsigned short	length;
	int				pid;
	int				result;		/* ���� */
#define	DI_TRAY_FOUND	(0)		/* �����ɍ����g���C���o������ */
#define	DI_TRAY_ERRSKIP	(1)		/* �G���[�X�L�b�v���Ă������� */
#define	DI_TRAY_CANCEL	(2)		/* �L�����Z�����w�����ꂽ */
#define	DI_TRAY_FORCE	(3)		/* ����������w�����ꂽ */
#define	DI_TRAY_ANOTHER	(4)		/* �p���T�C�Y���ގ������g���C���� */
	int			tray_id;		/* �g���CID */
	int			paper_code;		/* �p���T�C�Y�R�[�h */
	int			paper_width;	/* �p����   (0.1mm�P��) */
	int			paper_length;	/* �p������ (0.1mm�P��) */
} di_res_reqpaper_t;

typedef struct di_envinfo {
	long           id; /* variable ID */
#define DI_PENV_VARFLAG_READONLY (1 << 0) /* PJL READ ONLY */
	unsigned long  flag; /* variable flag */
	long           init_val; /* initial value */
	long           def_val; /* default value */
	long           cur_val; /* current value */
	unsigned char  val_denom; /* value denominaator (use if type is FLOAT) */
#define DI_PENV_VALTYPE_ENUM    0 /* ENUMERATE */
#define DI_PENV_VALTYPE_INT     1 /* INTEGER(range) */
#define DI_PENV_VALTYPE_FLOAT   2 /* FLOAT(range) */
#define DI_PENV_VALTYPE_NETADDR 3 /* Network address */
	unsigned char  val_type; /* value type */
	long           val_num; /* number of value list */
} di_envinfo_t;

typedef struct di_flashmem_info {
#define DI_FLASHMEM_ATTR_RW (1 << 0) /* Read/Write�\ */
	unsigned long attr;          /* attribute */
#define DI_FLASHMEM_MEDIA_UNKNOWN 0 /* �s�� */
#define DI_FLASHMEM_MEDIA_ROM     1 /* ROM DIMM / SD Card */
	unsigned long media;         /* kind of media */
#define DI_MAX_FM_PATH_LEN 64
	char path[DI_MAX_FM_PATH_LEN];  /* directory path */
} di_flashmem_info_t;


typedef  struct {
	unsigned short idPanel;   /* �A�C�e�����g�̃p�l���h�c */
	unsigned short idDown;    /* ���K�w�̃p�l���h�c */
	/* �g���b�v�p�֐��|�C���^ */
	void (*fchecker)(unsigned short, unsigned char, unsigned char);
#define   FILENAME_LEN         14
	unsigned char  filename[FILENAME_LEN];   /* �t�@�C���l�[�� */
	unsigned char  panel_lock_stat; /* �p�l�����b�N��ԏ�� */       
	unsigned char  ucReserved[3];   /* ���g�p */
	unsigned char  reserve_cid[4];  /* �N���C�A���g�h�c�p�\��̈� */
	unsigned char  ucItem;          /* �A�C�e���^�C�v  */
	unsigned char  ucMenu;          /* ���j���[�^�C�v  */
} di_menu_type_t;


typedef  struct {
	unsigned short idPanel;    /* �A�C�e�����g�̃p�l���h�c */
	unsigned short idNext;     /* ���K�w�̎��̃p�l���h�c */
	unsigned short idPrev;     /* ���K�w�̑O�̃p�l���h�c */
	unsigned short idDown;     /* ���K�w�̃p�l���h�c */
	unsigned short idBack;     /* �ďo���� ��ʊK�w�̃p�l���h�c */
	unsigned short str1_id;    /* �^�C�g�����i�P�s�ځj�̕�����h�c */
	unsigned short str1_mod;   /* �^�C�g�����i�P�s�ځj�̕�����C����� */
	unsigned short str2_id;    /* ���ڕ��i�Q�s�ځj�̕�����h�c */
    /* �g���b�v�p�֐��|�C���^ */
	void (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  disp_flg;   /* �\���^���P�x�^��\���̃t���O */
        unsigned char  ucReserved[5];   /* ���g�p */
        unsigned char  reserve_cid[4];  /* �N���C�A���g�h�c�ۑ��p�\��̈� */
        unsigned char  ucItem;          /* �A�C�e���^�C�v */
        unsigned char  ucMenu;          /* ���j���[�^�C�v */
} di_item_type_menu_t;

typedef  struct {
	unsigned short idPanel;  /* �A�C�e�����g�̃p�l���h�c */
	unsigned short idNext;   /* ���K�w�̎��̃p�l���h�c */
	unsigned short idPrev;   /* ���K�w�̑O�̃p�l���h�c */
	unsigned short idDown;   /* ���K�w�̃p�l���h�c */
	unsigned short idBack;   /* �ďo���� ��ʊK�w�̃p�l���h�c */
	unsigned short str1_id;  /* �^�C�g�����i�P�s�ځj�̕�����h�c */
	unsigned short str1_mod; /* �^�C�g�����i�P�s�ځj�̕�����C����� */
	unsigned short str2_id;  /* ���ڕ��i�Q�s�ځj�̕�����h�c */
	/* �g���b�v�p�֐��|�C���^ */
	void (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned char  up_num;   /* ���s��ɑJ�ڂ����ւ̊K�w�� */
	unsigned char  disp_flg; /* �\���^���P�x�^��\���̃t���O */
	unsigned char  fselect;  /* �I���^��I���̃t���O */
	unsigned char  disp_fselect; /* �I���t���O�̕\���^��\���̃t���O */
	unsigned char  ucReserved[2]; /* ���g�p */
	unsigned char  reserve_cid[4]; /* �N���C�A���g�h�c�ۑ��p�\��̈� */
	unsigned char  ucItem;         /* �A�C�e���^�C�v */
	unsigned char  ucMenu;         /* ���j���[�^�C�v */
} di_item_type_select_t;

typedef  struct {
	unsigned short idPanel;  /* �A�C�e�����g�̃p�l���h�c */
	unsigned short idBack;   /* �ďo���� ��ʊK�w�̃p�l���h�c */
	unsigned short str1_id;  /* �^�C�g�����i�P�s�ځj�̕�����h�c */
	unsigned short str1_mod; /* �^�C�g�����i�P�s�ځj�̕�����C����� */
	short          sMax;     /* �ő�l */
	short          sMin;     /* �ŏ��l */
	unsigned short step;     /* �ω��� */
	short          value;    /* �ݒ�l */
	/* �g���b�v�p�֐��|�C���^ */
	void (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;         /* �P�ʕ�����h�c */
	unsigned char  up_num;         /* ���s��ɑJ�ڂ����ւ̊K�w�� */
	unsigned char  fig_num;        /* �\������ */
	unsigned char  ucReserved[2];  /* ���g�p */
	unsigned char  reserve_cid[4]; /* �N���C�A���g�h�c�ۑ��p�\��̈� */
	unsigned char  ucItem;         /* �A�C�e���^�C�v */
	unsigned char  ucMenu;         /* ���j���[�^�C�v */
} di_item_type_integer_t;

typedef  struct {
	unsigned short idPanel;    /* �A�C�e�����g�̃p�l���h�c             */
	unsigned short idBack;     /* �ďo���� ��ʊK�w�̃p�l���h�c        */
	unsigned short str1_id;    /* �^�C�g�����i�P�s�ځj�̕�����h�c     */
	unsigned short str1_mod;   /* �^�C�g�����i�P�s�ځj�̕�����C����� */
	short          sMax;       /* �ő�l                               */
	short          sMin;       /* �ŏ��l                               */
	unsigned short step;       /* �ω���                               */
	short          value;      /* �ݒ�l                               */
	/* �g���b�v�p�֐��|�C���^               */
	void           (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;     /* �P�ʕ�����h�c                       */
	unsigned char  up_num;     /* ���s��ɑJ�ڂ����ւ̊K�w��         */
	unsigned char  fig_num;    /* �\������                             */
	unsigned char  ucMulti;    /* �w���l                               */
	unsigned char  ucReserved; /* ���g�p                               */
	unsigned char  reserve_cid[4]; /* �N���C�A���g�h�c�ۑ��p�\��̈�       */
	unsigned char  ucItem;     /* �A�C�e���^�C�v                       */
	unsigned char  ucMenu;     /* ���j���[�^�C�v                       */
} di_item_type_float_t;

typedef  struct {
	unsigned short idPanel; /* �A�C�e�����g�̃p�l���h�c             */
	unsigned short idBack;  /* �ďo���� ��ʊK�w�̃p�l���h�c        */
	unsigned short str1_id; /* �^�C�g�����i�P�s�ځj�̕�����h�c     */
	short          sMin;    /* �ŏ��l                               */
	int            sMax;    /* �ő�l                               */
	int            value;   /* �ݒ�l                               */
	/* �g���b�v�p�֐��|�C���^               */
	void           (*fchecker)(unsigned short, unsigned char, unsigned char);
	unsigned short msr_id;  /* �P�ʕ�����h�c                       */
	unsigned char  str1_mod; /* �^�C�g�����i�P�s�ځj�̕�����C����� */
	unsigned char  step;     /* �ω���                               */
	unsigned char  fig_num;  /* �\������                             */
	unsigned char  ucMulti;  /* �w���l                               */
	unsigned char  reserve_cid[4]; /* �N���C�A���g�h�c�ۑ��p�\��̈�       */
	unsigned char  ucItem;   /* �A�C�e���^�C�v                       */
	unsigned char  ucMenu;   /* ���j���[�^�C�v                       */
} di_item_type_floatext_t;

typedef  struct di_fontinfo {
	unsigned char *addr;  /* �A�h���X */
	unsigned long size;   /* �T�C�Y */
	unsigned long offset; /* �I�t�Z�b�g */
} di_fontinfo_t;

typedef  struct di_pdlinfo {
#define DI_INTERP_LEN_SHORTNAME 3
#define DI_MINFO_KEY_PDL_CATEGORY_LEN 7
	int interp_id; /* �C���^�v���^ID */
	/* �V���[�g�l�[��(��`����Ă��Ȃ��ꍇ��NULL) */
	char shortname[DI_INTERP_LEN_SHORTNAME + 1];
	char path; /* printer.ini path ID  */
	/* printer.ini �t�@�C���̃J�e�S���� */
	char category[DI_MINFO_KEY_PDL_CATEGORY_LEN + 1];
} di_pdlinfo_t;

/**
 * ���i���\����
 */
typedef struct di_initinfo {
#define	DI_MACHINECODE_ADONIS_C2		0x00
#define	DI_MACHINECODE_KIR_P			0x10
#define	DI_MACHINECODE_KIR_P2			0x13
#define	DI_MACHINECODE_KIR_P3			0x15
#define	DI_MACHINECODE_JUPITER_P		0x20
#define	DI_MACHINECODE_URANOS_P			0x30
#define	DI_MACHINECODE_RUSSIAN_C2		0x40
#define DI_MACHINECODE_ADONIS_P3		0x50
#define DI_MACHINECODE_URANOS_C			0x60
#define DI_MACHINECODE_ARES_P			0x70
#define DI_MACHINECODE_KAISER3			0x80
#define DI_MACHINECODE_JUPITER_P2		0x90
#define DI_MACHINECODE_JUPITER_P2Y		0x93		/* ��� */
#define DI_MACHINECODE_JUPITER_P2M		0xa0
#define DI_MACHINECODE_JUPITER_P2K		0xb0
#define	DI_MACHINECODE_URANOS_P2		0xc0
#define DI_MACHINECODE_JUPITER_C0		0xe0
#define	DI_MACHINECODE_CASSIS_P1_DOM	0xf0		/* DOM */

#define	DI_MACHINECODE_MARTINI_C1		0x00080000
#define	DI_MACHINECODE_BELLINI_C2		0x00090000
#define	DI_MACHINECODE_ADONIS_C3		0x000A0000
#define	DI_MACHINECODE_RUSSIAN_C3		0x000B0000
#define	DI_MACHINECODE_SEADRAGON_C1		0x000C0000
#define	DI_MACHINECODE_JUPITER_C1		0x000D0000
#define	DI_MACHINECODE_KIR_P3_EXP		0x00010000	/* EXP */
#define	DI_MACHINECODE_KIR_C2			0x00120000
#define	DI_MACHINECODE_CASSIS_P1_EXP	0x00130000	/* EXP */
#define	DI_MACHINECODE_PLUTO_P1			0x00140000
#define DI_MACHINECODE_VENUS_C1			0x00150000
#define DI_MACHINECODE_URANOS_C2		0x00160000
#define	DI_MACHINECODE_JUPITER_P3		0x00170000
#define DI_MACHINECODE_GAIA_P1			0x00180000
#define DI_MACHINECODE_MARTINI_C2		0x00190000
#define DI_MACHINECODE_STELLA_C2		0x001A0000
#define DI_MACHINECODE_DOLPHIN_C2		0x001B0000	/* DOLPHIN-C2 group */
#define DI_MACHINECODE_JUPITER_C2		0x001C0000	/* JUPITER_C2 group */
#define	DI_MACHINECODE_CASSIS_P2		0x001D0000	/* CASSIS-P2 group */
#define	DI_MACHINECODE_MARTINI_P1		0x001E0000	/* MARTINI-P1 group */
#define	DI_MACHINECODE_ADONIS_C4		0x001F0000	/* ADONIS-C4 group */
#define	DI_MACHINECODE_RUSSIAN_C4		0x00200000	/* RUSSIAN-C4 group */
#define	DI_MACHINECODE_KIR_P4			0x00210000	/* KIR-P4 group */
#define	DI_MACHINECODE_JUPITER_P4		0x00220000	/* JUPITER-P4 group */
#define DI_MACHINECODE_PEGASUS_C1		0x00230000	/* PegasusC1 group */
#define DI_MACHINECODE_APOLLON_C1		0x00240000	/* ApollonC1 group */
#define DI_MACHINECODE_ATHENA_C1		0x00250000	/* AthenaC1 group */
#define DI_MACHINECODE_BELLINI_C3		0x00260000	/* BELLINI-C3 group */
#define DI_MACHINECODE_MARTINI_C3		0x00270000	/* MARTINI-C3 group */
#define DI_MACHINECODE_ARES_P2			0x00280000	/* ARES-P2 group */
#define DI_MACHINECODE_GAIA_P2			0x00290000	/* Gaia-P2 group */
#define DI_MACHINECODE_APOLLON_P1		0x002A0000	/* Apollon-P1 group */
#define DI_MACHINECODE_ADONIS_P4		0x002B0000	/* Adonis-P4 group */
#define	DI_MACHINECODE_MARTINI_P2		0x002C0000	/* MARTINI-P2 group */
#define	DI_MACHINECODE_KIR_C3			0x002D0000	/* KIR-C3 group */
#define	DI_MACHINECODE_NEPTUNE_C2		0x002E0000	/* NEPTUNE-C2 group */
#define	DI_MACHINECODE_SEADRAGON_C2		0x002F0000	/* SEADRAGON_C2 group */
#define	DI_MACHINECODE_ADONIS_C4_5		0x00300000	/* ADONIS-C4.5 group */
#define	DI_MACHINECODE_RUSSIAN_C4_5		0x00310000	/* RUSSIAN-C4.5 group */
#define DI_MACHINECODE_STELLA_C3		0x00320000	/* STELLA-C3 group */
#define DI_MACHINECODE_KRISS_P1			0x00330000	/* Kriss-P1 group */
#define DI_MACHINECODE_LUNA_P1			0x00340000	/* Luna-P1 group */
#define DI_MACHINECODE_SINCERE_P1		0x00350000	/* Sincere-P1 group */
#define DI_MACHINECODE_PARISIAN_C1		0x00360000	/* Parisian-C1 group */
#define DI_MACHINECODE_VENUS_C2			0x00370000	/* Venus-C2 group */
#define DI_MACHINECODE_ALEX_C1			0x003A0000	/* Alex-C1 group */
#define DI_MACHINECODE_RUSSIAN_C5		0x003B0000	/* Russian-C5 group */
#define DI_MACHINECODE_NEPTUNE_P1		0x003C0000	/* Neptune-P1 group */
#define DI_MACHINECODE_ATHENA_C2		0x003D0000	/* Athena-C2 group */
#define DI_MACHINECODE_ALEX_P1			0x003E0000	/* Alex-P1 group */
#define DI_MACHINECODE_APOLLON_C2		0x003F0000	/* Apollon-C2 group */
#define DI_MACHINECODE_PEGASUS_C2		0x00400000	/* Pegasus-C2 group */
#define DI_MACHINECODE_BELUGA_C1		0x00410000	/* Beluga-C1 group */
#define DI_MACHINECODE_DIANA_C1			0x00420000	/* Diana-C1 group */
#define DI_MACHINECODE_GAIA_P3			0x00430000	/* Gaia-P3 group */
#define DI_MACHINECODE_APOLLON_P2		0x00440000	/* Apollon-P2 group */
#define DI_MACHINECODE_SINCERE_P2		0x00450000	/* Sincere-P2 group */
#define DI_MACHINECODE_BELLINI_C4		0x00460000	/* Bellini-C4 group */
#define DI_MACHINECODE_MARTINI_C4		0x00470000	/* Martini-C4 group */
#define DI_MACHINECODE_LUNA_P2			0x00480000	/* Luna-P2 group */
#define DI_MACHINECODE_DIANA_C1L		0x00490000	/* Diana-C1L group */
	/**
	 * \brief �@��R�[�h
	 * �l�͈ȉ�
	 * \li DI_MACHINECODE_ADONIS_C2
	 */
	unsigned long	machinecode;	/**< �@��R�[�h */
	unsigned char	*model;			/* ���f�����B"IPSiO CX8200"�� */
	unsigned char	*maker;			/* ���[�J�[ */
	unsigned char	*machine_number;/* �@�� */
	di_optinfo_t	option;			/* �I�v�V�����@�� */
	unsigned long	function;		/* �@�\���(DI_SYS_FUNC_xx) */
	unsigned char	disp_lines;		/* �\����ʂ̃��C���� */
	unsigned char	disp_columns;	/* �\����ʂ̂P���C���̕����� */
	unsigned char	punch_hole;		/* �p���`�\�Ȍ��̏��(DI_SYS_PUNCH_HOLE_xx) */
	unsigned long	total_ram_size;	/* �v�����^�ɓ��ڂ���Ă���RAM�e��(Byte) */
#define DI_DEST_DOM		0	/* DOM */
#define DI_DEST_NA		1	/* NA */
#define DI_DEST_EU		2	/* EU */
	unsigned char	destination;	/* �d�����n�R�[�h(�������define) */
	unsigned long	memory_size;	/* �C���^�v���^���g�p�ł��� */
					/* �������T�C�Y(Byte) */
	unsigned char	*ver_printer;			/* �v�����^�̃o�[�W���� */
} di_initinfo_t;

/* BG/UCR�e�[�u�����\���� */
typedef struct di_bgucrinfo {
	unsigned char	*bg;	/* BG�e�[�u�� */
	unsigned char	*ucr;	/* UCR�e�[�u�� */
	unsigned char	*bg_hgr;	/* BG�e�[�u��(���n�p) */
	unsigned char	*ucr_hgr;	/* UCR�e�[�u��(���n�p) */
	unsigned char	*bg_compbk;	/* for composite black */
	unsigned char	*ucr_compbk;
} di_bgucrinfo_t;

/* structure of information of GCR table */
typedef struct di_gcrinfo {
	unsigned long	flag;
	short			*CB_bg;
	short			*CB_ucr;
	short			*CG_bg;
	short			*CG_ucr;
	short			*YG_bg;
	short			*YG_ucr;
	short			*MB_bg;
	short			*MB_ucr;
	short			*MR_bg;
	short			*MR_ucr;
	short			*YR_bg;
	short			*YR_ucr;
} di_gcrinfo_t;

/* �K�ʃe�[�u�����\���� */
typedef struct di_dropinfo {
	unsigned char	*lit;	/* �K�ʃf�[�^ */
	unsigned char	*inv;	/* �t�ϊ��e�[�u�� */
} di_dropinfo_t;

/* ���ʃ��������\���� */
typedef struct di_dupgaminfo {
	unsigned char	*gam_front;	/* �\�ʊ���[�ʐ^,����,�h��,����] */
	unsigned char	*gam_back;	/* ���ʊ���[�ʐ^,����,�h��,����] */
} di_dupgaminfo_t;


/* �@����\���� */
typedef struct di_devinfo {
	/*
	 * �f�B�U���
	 * ���ۂ̐���
	 *  �T�|�[�g�r�b�g�� x �𑜓x��ސ� x �f�B�U��ސ� x �T�|�[�g�ő�v���[����
	 * �ƂȂ�B�e�l�͋@��\�͏��B
	 * �z�u����
	 *  for �r�b�g��(�l �� -> ��)
	 *    for �𑜓x��(�呖��+������ �� -> ��)
	 *      for �f�B�U��(photo -> text -> cad -> graphics)
	 *        for �v���[����(K -> C -> M -> Y)
	 *          dither_info
	 * �ƂȂ�
	 */
	di_ditinfo_t	*dither_info;
	di_ditinfo_t	*dither_info_mono;

	/*
	 * �K���}���
	 * ��,�z�u���� dither_info �Ɠ��l
	 */
	unsigned char	**gamma_info;
	unsigned char	**gamma_info_mono;

	/*
	 * �f�o�C�X�t�H���g���
	 */
	/*
	 * �t�H���g�̐擪�A�h���X
	 */
	unsigned char	*font_address;
	/*
	 * �t�H���g�T�C�Y
	 */
	unsigned long	font_size;
	/* �t�H���g��� */
#define DI_FONT_RPCS		0	/* RPCS DOM�p */
#define DI_FONT_RPCS_EXP	1	/* RPCS EXP�p */
#define DI_FONT_PS			2	/* PS ���� */
#define DI_FONT_PSDOM		3	/* PS ���{�� */
#define DI_FONT_PCL			4	/* PCL�p */
	unsigned char	font_type;

	/*
	 * CMM�Ŏg�p����v���t�@�C�����
	 */
	void	*profaddress;
	long	profnumber;

	/*
	 * �@��\�͏��
	 */
	unsigned int		resonum;	/* �T�|�[�g�𑜓x&�r�b�g�g�ݍ��킹��ސ� */
	di_resolutioninfo_t	*reso_set;	/* �𑜓x&�r�b�g�g���� */
						/* reso������(=reso_set[resonum]) */
	int		ndit;		/* �f�B�U��ސ� */
	int		nplane;		/* �T�|�[�g�ő�v���[���� */
	float	bg_startp;	/* BG ���n�܂�J�n���x�� */
	float	bg_slant;	/* BG �������z */
	float	ucr_startp;	/* UCR ���n�܂�J�n���x�� */
	float	ucr_slant;	/* UCR �������z */
	int		soft_tsave;	/* �\�t�g�g�i�[�Z�[�u�̃T�|�[�g */
				/* [1:����, 0:�Ȃ�] */
	float	tsave_ratio;	/* �\�t�g�g�i�[�Z�[�u����(0.0 - 1.0) */
	int		extend_soft_tsave;	/* �g���\�t�g�g�i�[�Z�[�u�̑Ή� */
					/* [1:����, 0:�Ȃ�] */
	int		toner_limit;	/* ���ʋK���̃T�|�[�g */
				/* [1:����, 0:�Ȃ�] */
	unsigned int	tlimit_num;	/* �@�킪�T�|�[�g���Ă��鑍�ʋK���l�̎�ސ� */
	di_tlimitinfo_t	*tlimit_val;/* ���ʋK���l�̃o���G�[�V���� */
				/* tlimit_num ���� */
				/* ��ԍŏ����f�t�H���g�l */
				/* ����ȊO�͓��ꃂ�[�h�̒l */
				/* �T�|�[�g���Ă��Ȃ����NULL */

	/*
	 * �V�X�e�����
	 */
	char	*shdm_addr;	/* �V�F�A�[�h�������̐擪�A�h���X */
	long	sys_handle;	/* �V�X�e���n���h�� */

	/*
	 * �g�����
	 */
#define DI_NOTSUPPORT_EXT_DEVINFO_PARAM	0 /* ����ȍ~�̃����o������ */
#define DI_SUPPORT_EXT_DEVINFO_PARAM	1 /* ����ȍ~�̃����o���L�� */
	unsigned long	flag;		/* �e��t���O */
				/* 1bit�� -- �g�����̗L��/���� */

	di_bgucrinfo_t	**bgucr_info;	/* BG/UCR(�e�[�u��) */

	di_gcrinfo_t	*gcr_info;	/* WiShGCR */

	di_gcrinfo_t	*gcrhgr_info;	/* WiShGCR(���n�p) */

	di_dropinfo_t	**drop_info;	/* �K�ʃe�[�u�� */

	di_dupgaminfo_t	**dupgam_info;	/* ���ʃ����� */

	int	support_drop;	/* �K�ʂ̃T�|�[�g */
				/* [1:����, 0:�Ȃ�] */
	int		cmy_media_num;	/* CMY��������鎆��̐� */
	unsigned char	*cmy_media;	/* CMY��������鎆��̔z�� */
	int		minbandheight;
	int		maxbandheight;
	int		bandsize;
} dev_info_t, di_devinfo_t;

/*
 * �ȍ~��di_init()�Ń��[�U��DI�ɓn���p�����[�^
 */

/* �񓯊���DI�����ōX�V�����p�����[�^ */
typedef struct di_async_para {
	/*
	 * �W���u���Z�b�g���
	 * �V�X�e������W���u���Z�b�g�v�����������ꍇ�ɍX�V�����
	 * [0: ���Z�b�g����Ă��Ȃ�, ��0: ���Z�b�g���ꂽ]
	 */
	int	jobreset;
	/*
	 * ������O���ǂ���
	 * ����̋��E�ōX�V�����
	 * [0: �����, ��0: ����O]
	 */
	int	not_joblang;
	/*
	 * �W���uID
	 * �V�X�e���������v�����������ꍇ�ɍX�V�����
	 */
	int	job_id;
	/*
	 * �e�X�g�v�����g���v�����ꂽ�� [0: ����Ă��Ȃ�, ��0: ���ꂽ]
	 * �e�X�g�v�����g�v�����������ꍇ�ɍX�V�����B
	 * di_notify_msg(DI_NOTIFYMSG_JOBEND)�ŃN���A(=0)�����B
	 * �e�X�g�v�����g�@�\���T�|�[�g���Ă�����̂ݕK�v�B
	 */
	int	testprint;
	/*
	 * �l�b�g�W���uID
	 * �V�X�e���������v�����������ꍇ�ɍX�V�����
	 */
	int	njob_id;
	/*
	 * �`���l���ԍ�
	 * �V�X�e���������v�������������ɍX�V�����
	 * �l�� DI_CHANNEL_xxx
	 */
	int	host_channel;
	/*
	 * PDL ID
	 * �V�X�e���������v�������������ɍX�V�����
	 * �l�� DI_PDL_xxx
	 */
	int	pdl_id;
	/*
	 * �v���Z�XID
	 * �V�X�e���������v�������������ɍX�V�����
	 */
	long	pid;
	/*
	 * �v���O�����ԍ� 
	 * �V�X�e������v���O�����o�^/�폜�v�������������ɍX�V�����iMSIS�nPDL��p�j
	 * �l�̃N���A�̓��[�U�������I�ɍs���Ă�������
	 */
	int	pno;
	/*
	 * �V�X�e������v���C�����Z�b�g�v�������������ɔ�O�ɍX�V�����iMSIS�nPDL��p�j
	 * �l�̃N���A�̓��[�U�������I�ɍs���Ă�������
	 */
	int	prime_reset;
	/*
	 * ���[�U�X�C�b�`�ԍ�
	 * �V�X�e���������v�������������ɍX�V�����iMSIS�nPDL��p�j
	 */
	int		uswitch;
	/*
	 * �f�[�^�����J�n���R
	 * �V�X�e���������v�������������ɍX�V�����iMSIS�nPDL��p�j
	 */
	int		reason;
	unsigned char	filepath[DI_INTERP_LEN_TESTPRINT_PATH];
} async_para_t, di_async_para_t;

typedef struct di_setinfo {
	/*
	 * �񓯊��ɕω�����p�����[�^
	 * ����GPS��̓���ł̂ݗL��
	 */
	di_async_para_t	*async;
	/*
	 * DI���X�g���[������ǂݍ��񂾃o�C�g���B
	 * di_singet(c) or di_sinseek ���R�[�����邽�тɎ����I�ɍX�V�����B
	 * DEBUG��define���ăR���p�C�������ꍇ�̂ݗL��
	 */
	int	cmd_offset;
	/*
	 * �C���^�v���^ID(�l�͈ȉ���define)
	 */
#define DI_INTERP_RPCS			0x0000	/* RPCS */
#define DI_INTERP_XHTML			0x0010	/* XHTML */
#define DI_INTERP_EXIF			0x0100	/* EXIF */
#define DI_INTERP_BMLINKS		0x0101	/* BMLinkS */
#define DI_INTERP_PS			0x1000	/* PS */
#define DI_INTERP_PCL			0x1001	/* PCL */

#define DI_INTERP_RPDL			0x10000	/* RPDL */
#define DI_INTERP_R98			0x10001	/* R98 */
#define DI_INTERP_R16			0x10010	/* R16 */
#define DI_INTERP_R55			0x10011	/* R55 */
#define DI_INTERP_RPGL2			0x10100	/* RPGL2 */
#define DI_INTERP_RTIFF			0x10101	/* RTIFF */
#define DI_INTERP_RPGL2c		0x10110	/* RPGL2c */
#define DI_INTERP_PICTBRIDGE	0x0110	/* PictBridge */
#define DI_INTERP_XPS			0x0111	/* XPS */
#define DI_INTERP_MP_TIFF		0x11000	/* MediaPrintTIFF */
#define DI_INTERP_MP_JPEG		0x11001	/* MediaPrintJPEG */
	 int	interp_id;
	/*
	 * �V�X�e���������̂��߂̃I�v�V�����p�����[�^(-1�Ŗ��g�p)
	 * interp_id �ɂ���ĈӖ����ω�����
	 * DI_INTERP_RPCS	�N�����R�ʒm
	 * ���̑�			���g�p
	 */
	long	option;
} di_setinfo_t;

/* ���[�U�[�W���u�ϐ��\���� */
typedef struct ujobparam_var {
	unsigned long	flag;
/* di_ujob_info_t�Ƀ}�N����`������ */
} ujobparam_var_t;

typedef struct di_onebininfo {
	unsigned short	id;		/* �r���r����ID */
#define DI_BIN_STAPLER            (1 << 0)        /* �X�e�[�v���� */
#define DI_BIN_PUNCH              (1 << 1)        /* �p���`�� */
#define DI_BIN_SHIFT              (1 << 2)        /* �V�t�g�r���� */
#define DI_BIN_PAPER_SENSE        (1 << 3)        /* sense paper exist */
#define DI_BIN_FULL_SENSE         (1 << 4)        /* sense paper full */
#define DI_BIN_NODUPLEX           (1 << 5)        /* noduplex */
#define DI_BIN_SADDLE             (1 << 6)        /* saddle */
#define DI_BIN_FOLD               (1 << 7)        /* �܂�@�\ */
	unsigned long	attr;	/* �r���r���̎�� */
#define DI_BIN_FULL               (1 << 0)        /* ���t */
#define DI_BIN_ERROR              (1 << 1)        /* �̏��� */
#define DI_BIN_STOPEXIT           (1 << 2)        /* �r���}�� */
#define DI_BIN_SADDLE_DISABLE     (1 << 3)        /* ���Ԃ��r���֎~ */
#define DI_BIN_NORMAL_DISABLE     (1 << 4)        /* ���Ԃ��ȊO�̔r���֎~ */
	unsigned long	status;	/* �X�e�[�^�X */
} di_onebininfo_t;

#define DI_MAX_BIN_NUM 32

typedef struct di_bininfo {
	long			bin_num;					/* �r���r���̐� */
	di_onebininfo_t	bininfo[DI_MAX_BIN_NUM];	/* �e�r���̏�� */
} di_bininfo_t;

typedef struct di_filectrl {
	int	ope;
	char	Fontfilename[DI_PATHMAX];
	char	Tempfilename[DI_PATHMAX];
	int	fd;
} di_filectrl_t;

typedef struct di_rotenvinfo {
#define	DI_CHKDIR_STAPLE     (1<<0)	    /* staple�p�����[�^�w�� */
#define DI_CHKDIR_PUNCH      (1<<1)	    /* punch�p�����[�^�w�� */
#define DI_CHKDIR_BINDING    (1<<2)	    /* binding�p�����[�^�w�� */
#define DI_CHKDIR_RESOLUTION (1<<3)	    /* reso_x��reso_y�p�����[�^�w�� */
#define DI_CHKDIR_DEPTH      (1<<5)	    /* depth�p�����[�^�w�� */
	unsigned long		flag;			/* �ݒ肷��p�����[�^ */
	int					psize;			/* �p���T�C�Y�i�K�{�j */
	unsigned long		pwidth;			/* �p�����i0.1mm�P�ʁj */
	unsigned long		plength;		/* �p�����i0.1mm�P�ʁj */
#define DI_ORIENTATION_PORTRAIT  (1<<0)	/* Portrait */
#define DI_ORIENTATION_LANDSCAPE (1<<1)	/* Landscape */
	unsigned char		orientation;	/* �I���G���e�[�V���� */
#define DI_STAPLE_OFF              (0)  /* �Ȃ� */
#define DI_STAPLE_LEFT_TOP_HORIZ   (1)  /* �g�p�͐������Ȃ� */
#define DI_STAPLE_LEFT_TOP_VERT    (2)  /* �g�p�͐������Ȃ� */
#define DI_STAPLE_LEFT_TOP_SLANT   (3)  /* ����΂� */
#define DI_STAPLE_RIGHT_TOP_HORIZ  (5)  /* �g�p�͐������Ȃ� */
#define DI_STAPLE_RIGHT_TOP_VERT   (6)  /* �g�p�͐������Ȃ� */
#define DI_STAPLE_RIGHT_TOP_SLANT  (7)  /* �E��΂� */
#define DI_STAPLE_DOUBLE_LEFT      (9)  /* �����Q�� */
#define DI_STAPLE_DOUBLE_TOP       (10) /* �㑤�Q�� */
#define DI_STAPLE_DOUBLE_RIGHT     (11) /* �E���Q�� */
#define DI_STAPLE_BOOKLET          (12) /* �^���Q�� */
#define DI_STAPLE_LEFT_TOP         (16) /* ���� */
#define DI_STAPLE_RIGHT_TOP        (17) /* �E�� */
	unsigned char		staple;			/* �X�e�[�v�� */
#define DI_PUNCH_OFF   (0)              /* �Ȃ� */
#define DI_PUNCH_LEFT  (1)              /* ���� */
#define DI_PUNCH_TOP   (2)              /* ��� */
#define DI_PUNCH_RIGHT (3)              /* �E�� */
#define DI_PUNCH_JP2   (0x00)           /* ��ʂ̃p���`��ނ̎w��͂����Ă��Ȃ��Ă��ǂ� */
#define DI_PUNCH_US2   (0x10)
#define DI_PUNCH_US3   (0x20)
#define DI_PUNCH_EU4   (0x30)
#define DI_PUNCH_NEU4  (0x40)
	unsigned char		punch;			/* �p���` */
#define DI_BIND_LEFT      (0)           /* ���Ԃ� */
#define DI_BIND_TOP       (1)           /* ��Ԃ� */
#define DI_BIND_RIGHT     (2)           /* �E�Ԃ� */
#define DI_BIND_BOTTOM    (3)           /* ���Ԃ�(���g�p) */
#define DI_BIND_LEFTRIGHT (4)           /* ���E�Ԃ�(RTIFF) */
#define DI_BIND_TOPBOTTOM (5)           /* �㉺�Ԃ�(RTIFF) */
#define DI_BIND_OFF       (0xF)         /* �w��Ȃ�(gpsPlotChkDirection()�p) */
	unsigned char		binding;		/* �Ƃ����� */
	unsigned short		reso_x;			/* X�����̉𑜓x */
	unsigned short		reso_y;			/* Y�����̉𑜓x */
#define DI_DEPTH_2        (1)           /* �Q�l(1bit) */
#define DI_DEPTH_4        (2)           /* �S�l(2bit) */
unsigned char		depth;			    /* �K�� */
} di_rotenvinfo_t;

typedef struct di_imgrotinfo {
#define DI_ROT_0B    (1<<0) /* �O�x */
#define DI_ROT_90B   (1<<1) /* �X�O�x */
#define DI_ROT_180B  (1<<2) /* �P�W�O�x */
#define DI_ROT_270B  (1<<3) /* �Q�V�O�x */
#define DI_ROT_ALL   (DI_ROT_0B|DI_ROT_90B|DI_ROT_180B|DI_ROT_270B) /* ��]�����s�K�v */
#define DI_ROT_NG    (0x80) /* ��]�����s�� */
#define DI_ROT_ERROR (0)    /* �G���[ (�ʎ��s�Ȃ�) */

	int direction;	    	/* �摜���� */
#define DI_ROT_0B    (1<<0)	/* �O�x */
#define DI_ROT_90B   (1<<1)	/* �X�O�x */
#define DI_ROT_180B  (1<<2)	/* �P�W�O�x */
#define DI_ROT_270B  (1<<3)	/* �Q�V�O�x */
#define DI_ROT_ERROR (0)	/* �΂߃X�e�[�v���o���Ȃ��A���̓p�����[�^�����i�X�e�[�v���w�肵�Ă��Ȃ��ꍇ�Ȃǁj */
	int slantdirection;		/* �΂߃X�e�[�v�����ł���摜���� */
} di_imgrotinfo_t;

/* �J���[�v���t�@�C����� */
/* GPS�̍\���� gps_color_profile_info�Ɠ����^ */
#define	DI_MAX_CPF_PATH_LEN		96
#define	DI_MAX_CPF_ATTR_LEN		27

typedef struct di_color_profile_info {
	unsigned long		key;	/* profile ID */
	unsigned char		media;	/* profile in media */
	unsigned char		attr[DI_MAX_CPF_ATTR_LEN];	/* ���� */
	char			path[DI_MAX_CPF_PATH_LEN];	/* �p�X�� */
} di_color_profile_info_t;

/* �v���O�����e�[�u�� */
typedef struct di_progtable {
	unsigned char eml_name[3];	/* �G�~�����[�V������ */
	unsigned char file_no;	/*�G�~�����[�V�����P�ʂŊǗ�����Ă���v���O�����ԍ��BNVRAM�t�@�C���̃t�@�C���ԍ��ɑΉ�����B */
} di_progtable_t;

#define	DI_AUTH_LIMIT_ADMINMACHINE	(1 << 0)		/* �@��Ǘ��ҋ@�\ 	*/
#define	DI_AUTH_LIMIT_ADMINUSER		(1 << 1)		/* ���[�U�[�Ǘ��ҋ@�\ */
#define	DI_AUTH_LIMIT_ADMINDOCUMENT	(1 << 2)		/* �����Ǘ��ҋ@�\ 	*/
#define	DI_AUTH_LIMIT_ADMINNETWORK	(1 << 3)		/* �l�b�g���[�N�Ǘ��ҋ@�\ */
#define	DI_AUTH_LIMIT_CERUSER		(1 << 4)		/* �F�؃��[�U�@�\ 	*/
#define	DI_AUTH_LIMIT_SUPERVISOR      	(1 << 5)		/* �X�[�p�[�o�C�U�[�@�\ */
#define	DI_AUTH_LIMIT_SERVICE		(1 << 6)		/* �T�[�r�X�@�\ 	*/
#define DI_ALL_FUNCTION_LIMIT		0xffffffff		/* �S�@�\���� */

/*
	NVRAM FILE ACCESS
*/
#define DI_AUTHORIZED		 0
#define DI_AUTH_LIMITED		-1
#define DI_AUTH_NOT_NOTIFY	-2

/* flag to check paper size and kind for di_query_duplex() */
#define DI_DUPLEX_CHK_SIZE	(1 << 0)
#define DI_DUPLEX_CHK_KIND	(1 << 1)

typedef struct di_chkduplexok {
	unsigned long	flag;		/* check flag */
	unsigned long	pwidth;		/* the width of free size paper (0.1mm) */
	unsigned long	plength;	/* the height of free size paper (0.1mm) */
	unsigned char	psize;		/* size of paper */
	unsigned char	pkind;		/* kind of paper */
	unsigned char	reserved[18];	/* reserved parameter for new function */
} di_chkduplexok_t;

typedef struct di_trayrequest {
	unsigned long		flag;
#define DI_TRAYREQFLAG_ALL			(0xFFFFFFFF)
#define DI_TRAYREQFLAG_PWIDTH		(1<<0)
#define DI_TRAYREQFLAG_PLENGTH		(1<<1)
#define DI_TRAYREQFLAG_MODE			(1<<2)
	unsigned long		pwidth;
	unsigned long		plength;
	unsigned char		mode:1;
#define	DI_REQ_MODE1				(0)
#define	DI_REQ_MODE2				(1)
	unsigned char		res1:7;
	unsigned char		res2[31];

} di_trayrequest_t; 

typedef struct di_res_reqtray {
	int result;
	int tray_id;
	int paper_code;
	unsigned long paper_width;
	unsigned long paper_length;
} di_res_reqtray_t;

typedef struct di_printcondition {
	unsigned int job_type;
#define DI_PCND_SDK_THUMBNAILJOB	4
#define DI_PCND_SDK_PRINTJOB		3
#define DI_PCND_THUMBNAILJOB		2
#define DI_PCND_MEDIAPRINTJOB		1
#define DI_PCND_PRINTJOB			0
	unsigned long chg_paper_kind;
#define DI_PCND_CHG_PAPERKIND_EXIST	(1 << 0)
	unsigned int paper_kind;
	unsigned long duplex;
#define DI_PCND_DUPLEX_OFF		(1 << 0)
#define DI_PCND_DUPLEX_LEFT		(1 << 1)
#define DI_PCND_DUPLEX_TOP		(1 << 3)
	unsigned long tonersave_color;
#define DI_PCND_TONERSAVE_COLOR_OFF		(1 << 0)
#define DI_PCND_TONERSAVE_COLOR_ON		(1 << 1)
	unsigned long nup;
#define DI_PCND_NUP_OFF			(1 << 0)
#define DI_PCND_NUP_2IN1		(1 << 1)
#define DI_PCND_NUP_4IN1		(1 << 2)
#define DI_PCND_NUP_6IN1		(1 << 3)
#define DI_PCND_NUP_8IN1		(1 << 4)
#define DI_PCND_NUP_9IN1		(1 << 5)
#define DI_PCND_NUP_16IN1		(1 << 6)
	unsigned long nup_option;
#define DI_PCND_NUPPAGEORDER_RIGHTTHENDOWN		(1 << 0)
#define DI_PCND_NUPPAGEORDER_LEFTTHENDOWN		(1 << 1)
#define DI_PCND_NUPPAGEORDER_DOWNTHENRIGHT		(1 << 2)
#define DI_PCND_NUPPAGEORDER_DOWNTHENLEFT		(1 << 3)
	unsigned long nup_border;
#define DI_PCND_NUPBORDER_OFF	(1 << 0)
#define DI_PCND_NUPBORDER_ON	(1 << 1)
	unsigned long colormode;
#define DI_PCND_COLORMODE_MONO	(1 << 0)
#define DI_PCND_COLORMODE_COLOR	(1 << 1)
	unsigned long inputtray;
#define DI_PCND_INPUTTRAY_AUTO	(1 << 0)
#define DI_PCND_INPUTTRAY_1		(1 << 1)
#define DI_PCND_INPUTTRAY_2		(1 << 2)
#define DI_PCND_INPUTTRAY_3		(1 << 3)
#define DI_PCND_INPUTTRAY_4		(1 << 4)
#define DI_PCND_INPUTTRAY_5		(1 << 5)
#define DI_PCND_INPUTTRAY_6		(1 << 6)
#define DI_PCND_INPUTTRAY_7		(1 << 7)
#define DI_PCND_INPUTTRAY_LCT	(1 << 30)
#define DI_PCND_INPUTTRAY_MAN	(1 << 31)
	unsigned long staple;
#define DI_PCND_STAPLE_OFF				(1 << 0)
#define DI_PCND_STAPLE_LEFTTOP			(1 << 1)
#define DI_PCND_STAPLE_RIGHTTOP			(1 << 2)
#define DI_PCND_STAPLE_LEFTTOPSLANT		(1 << 3)
#define DI_PCND_STAPLE_RIGHTTOPSLANT	(1 << 4)
#define DI_PCND_STAPLE_LEFT2			(1 << 5)
#define DI_PCND_STAPLE_TOP2				(1 << 6)
#define DI_PCND_STAPLE_RIGHT2			(1 << 7)
#define DI_PCND_STAPLE_BOOKLET			(1 << 8)
	unsigned long punch;
#define DI_PCND_PUNCH_OFF			(1 << 0)
#define DI_PCND_PUNCH_LEFT2			(1 << 1)
#define DI_PCND_PUNCH_TOP2			(1 << 2)
#define DI_PCND_PUNCH_RIGHT2		(1 << 3)
#define DI_PCND_PUNCH_LEFT3			(1 << 4)
#define DI_PCND_PUNCH_TOP3			(1 << 5)
#define DI_PCND_PUNCH_RIGHT3		(1 << 6)
#define DI_PCND_PUNCH_LEFT4			(1 << 7)
#define DI_PCND_PUNCH_TOP4			(1 << 8)
#define DI_PCND_PUNCH_RIGHT4		(1 << 9)
#define DI_PCND_PUNCH_LEFTGBC		(1 << 10)
#define DI_PCND_PUNCH_TOPGBC		(1 << 11)
#define DI_PCND_PUNCH_RIGHTGBC		(1 << 12)
#define DI_PCND_PUNCH_LEFTTOP		(1 << 13)
} di_printcondition_t;

typedef struct di_printcondition2 {
#define DI_PDF_PASSWORD_LEN			36
	unsigned char pdfpassword[DI_PDF_PASSWORD_LEN];
	unsigned long reserve[16];
} di_printcondition2_t;

typedef struct di_media_printcondition {
	unsigned long bind;
#define DI_PCND_MEDIA_BIND_OFF				(1 << 0)
#define DI_PCND_MEDIA_BIND_MAGAZIGE_LEFT	(1 << 1)
#define DI_PCND_MEDIA_BIND_MAGAZIGE_RIGHT	(1 << 2)
	struct {
			unsigned long magnification;
#define DI_PCND_MEDIA_MAG_OFF		(1 << 0)
#define DI_PCND_MEDIA_MAG_ON		(1 << 1)
			unsigned int size_code;
			unsigned long paper_width;
			unsigned long paper_length;
	} paper_size;
	struct {
			unsigned long tiff;
#define DI_PCND_MEDIA_RESOL_TIFF_200		(1 << 0)
#define DI_PCND_MEDIA_RESOL_TIFF_300		(1 << 1)
#define DI_PCND_MEDIA_RESOL_TIFF_400		(1 << 2)
#define DI_PCND_MEDIA_RESOL_TIFF_600		(1 << 3)
			unsigned long pdf;
#define DI_PCND_MEDIA_RESOL_PDF_600_FAST	(1 << 0)
#define DI_PCND_MEDIA_RESOL_PDF_600_STD		(1 << 1)
#define DI_PCND_MEDIA_RESOL_PDF_600_HIGH	(1 << 2)
#define DI_PCND_MEDIA_RESOL_PDF_1200		(1 << 3)
#define DI_PCND_MEDIA_RESOL_PDF_300			(1 << 4)
#define DI_PCND_MEDIA_RESOL_PDF_1200_2		(1 << 5)
	} resolution;
	unsigned long printquality;
#define DI_PCND_MEDIA_PRTQUAL_NORMAL		(1 << 0)
#define DI_PCND_MEDIA_PRTQUAL_DRAFT			(1 << 1)
#define DI_PCND_MEDIA_PRTQUAL_FINE			(1 << 2)
	unsigned long reserve1;
	unsigned long reserve2;
	unsigned long reserve3;
} di_media_printcondition_t;

typedef struct di_sdk_printcondition {
#define DI_PDL_PAGES_LEN		229
	unsigned char printpages[DI_PDL_PAGES_LEN];
	unsigned long forced_duplex;
#define DI_PCND_SDK_FORCEDDUPLEX_LEFT		(1 << 1)
#define DI_PCND_SDK_FORCEDDUPLEX_TOP		(1 << 3)
	unsigned long duplex;
#define DI_PCND_SDK_DUPLEX_OFF			(1 << 0)
#define DI_PCND_SDK_DUPLEX_LEFT			(1 << 1)
#define DI_PCND_SDK_DUPLEX_TOP			(1 << 3)
	unsigned long forced_colormode;
	unsigned long colormode;
#define DI_PCND_SDK_COLORMODE_MONO		(1 << 0)
#define DI_PCND_SDK_COLORMODE_COLOR		(1 << 1)
	unsigned long tonersave_color;
#define DI_PCND_SDK_TONERSAVE_OFF		(1 << 0)
#define DI_PCND_SDK_TONERSAVE_ON		(1 << 1)
	unsigned long tonersave_mono;
#define DI_PCND_SDK_TONERSAVE_MONO_OFF	(1 << 0)
#define DI_PCND_SDK_TONERSAVE_MONO_ON	(1 << 1)
	unsigned int print_num;
	unsigned int chg_paper_kind;
#define DI_PCND_SDK_CHG_PAPERKIND_EXIST	(1 << 0)
	unsigned int paper_kind;
	unsigned long nup;
#define DI_PCND_SDK_NUP_OFF				(1 << 0)
#define DI_PCND_SDK_NUP_2IN1			(1 << 1)
#define DI_PCND_SDK_NUP_4IN1			(1 << 2)
#define DI_PCND_SDK_NUP_6IN1			(1 << 3)
#define DI_PCND_SDK_NUP_8IN1			(1 << 4)
#define DI_PCND_SDK_NUP_9IN1			(1 << 5)
#define DI_PCND_SDK_NUP_16IN1			(1 << 6)
	unsigned long nup_option;
#define DI_PCND_SDK_NUPOPT_PAGEORDER_RIGHT_THEN_DOWN	(1 << 0)
#define DI_PCND_SDK_NUPOPT_PAGEORDER_LEFT_THEN_DOWN		(1 << 1)
#define DI_PCND_SDK_NUPOPT_PAGEORDER_DOWN_THEN_RIGHT	(1 << 2)
#define DI_PCND_SDK_NUPOPT_PAGEORDER_DOWN_THEN_LEFT		(1 << 3)
	unsigned long nup_border;
#define DI_PCND_SDK_NUP_BORDER_OFF		(1 << 0)
#define DI_PCND_SDK_NUP_BORDER_ON		(1 << 1)
#define DI_SDK_PDF_PASSWORD_LEN			(36)
	unsigned char pdfpassword[DI_SDK_PDF_PASSWORD_LEN];
	unsigned long inputtray;
#define DI_PCND_SDK_INPUTTRAY_AUTO		(1 << 0)
#define DI_PCND_SDK_INPUTTRAY_1			(1 << 1)
#define DI_PCND_SDK_INPUTTRAY_2			(1 << 2)
#define DI_PCND_SDK_INPUTTRAY_3			(1 << 3)
#define DI_PCND_SDK_INPUTTRAY_4			(1 << 4)
#define DI_PCND_SDK_INPUTTRAY_5			(1 << 5)
#define DI_PCND_SDK_INPUTTRAY_6			(1 << 6)
#define DI_PCND_SDK_INPUTTRAY_7			(1 << 7)
#define DI_PCND_SDK_INPUTTRAY_LCT		(1 << 30)
#define DI_PCND_SDK_INPUTTRAY_MAN		(1 << 31)
	 unsigned long sort;
#define DI_PCND_SDK_SORT_NORMAL			(1 << 0)
#define DI_PCND_SDK_SORT_ROTATE			(1 << 1)
#define DI_PCND_SDK_SORT_SHIFT			(1 << 2)
	unsigned long stack;
#define DI_PCND_SDK_STACK				(1 << 0)
	unsigned long staple;
#define DI_PCND_SDK_STAPLE_OFF				(1 << 0)
#define DI_PCND_SDK_STAPLE_LEFTTOP			(1 << 1)
#define DI_PCND_SDK_STAPLE_RIGHTTOP			(1 << 2)
#define DI_PCND_SDK_STAPLE_LEFTTOPSLANT		(1 << 3)
#define DI_PCND_SDK_STAPLE_RIGHTTOPSLANT	(1 << 4)
#define DI_PCND_SDK_STAPLE_LEFT2			(1 << 5)
#define DI_PCND_SDK_STAPLE_TOP2				(1 << 6)
#define DI_PCND_SDK_STAPLE_RIGHT2			(1 << 7)
#define DI_PCND_SDK_STAPLE_BOOKLET			(1 << 8)
	unsigned long punch;
#define DI_PCND_SDK_PUNCH_OFF			(1 << 0)
#define DI_PCND_SDK_PUNCH_LEFT2			(1 << 1)
#define DI_PCND_SDK_PUNCH_TOP2			(1 << 2)
#define DI_PCND_SDK_PUNCH_RIGHT2		(1 << 3)
#define DI_PCND_SDK_PUNCH_LEFT3			(1 << 4)
#define DI_PCND_SDK_PUNCH_TOP3			(1 << 5)
#define DI_PCND_SDK_PUNCH_RIGHT3		(1 << 6)
#define DI_PCND_SDK_PUNCH_LEFT4			(1 << 7)
#define DI_PCND_SDK_PUNCH_TOP4			(1 << 8)
#define DI_PCND_SDK_PUNCH_RIGHT4		(1 << 9)
#define DI_PCND_SDK_PUNCH_LEFTGBC		(1 << 10)
#define DI_PCND_SDK_PUNCH_TOPGBC		(1 << 11)
#define DI_PCND_SDK_PUNCH_RIGHTGBC		(1 << 12)
#define DI_PCND_SDK_PUNCH_LEFTTOP		(1 << 13)
	unsigned long bind;
#define DI_PCND_SDK_BIND_OFF			(1 << 0)
#define DI_PCND_SDK_BIND_MAGAZINE_LEFT	(1 << 1)
#define DI_PCND_SDK_BIND_MAGAZINE_RIGHT	(1 << 2)
	struct {
		unsigned long magnification;
#define DI_PCND_SDK_MAG_OFF				(1 << 0)
#define DI_PCND_SDK_MAG_ON				(1 << 1)
		unsigned int  size_code;
		unsigned long paper_width;
		unsigned long paper_length;
	} paper_size;
	struct {
		unsigned long pdf;
#define DI_PCND_SDK_RESOL_PDF_600_FAST	(1 << 0)
#define DI_PCND_SDK_RESOL_PDF_600_STD	(1 << 1)
#define DI_PCND_SDK_RESOL_PDF_600_HIGH	(1 << 2)
#define DI_PCND_SDK_RESOL_PDF_1200		(1 << 3)
#define DI_PCND_SDK_RESOL_PDF_300		(1 << 4)
#define DI_PCND_SDK_RESOL_PDF_1200_2	(1 << 5)
	} resolution;
	unsigned long reserve[13];
} di_sdk_printcondition_t;

typedef struct di_sys2_printcondition {
	unsigned long inputtray;
#define DI_PCND_SYS2_INPUTTRAY_AUTO	(1 << 0)
#define DI_PCND_SYS2_INPUTTRAY_1	(1 << 1)
#define DI_PCND_SYS2_INPUTTRAY_2	(1 << 2)
#define DI_PCND_SYS2_INPUTTRAY_3	(1 << 3)
#define DI_PCND_SYS2_INPUTTRAY_4	(1 << 4)
#define DI_PCND_SYS2_INPUTTRAY_5	(1 << 5)
#define DI_PCND_SYS2_INPUTTRAY_6	(1 << 6)
#define DI_PCND_SYS2_INPUTTRAY_7	(1 << 7)
#define DI_PCND_SYS2_INPUTTRAY_LCT	(1 << 30)
#define DI_PCND_SYS2_INPUTTRAY_MAN	(1 << 31)
	unsigned long duplex;
#define DI_PCND_SYS2_DUPLEX_OFF		(1 << 0)
#define DI_PCND_SYS2_DUPLEX_LEFT	(1 << 1)
#define DI_PCND_SYS2_DUPLEX_TOP		(1 << 3)
	unsigned long sort;
#define DI_PCND_SYS2_SORT_NORMAL	(1 << 0)
#define DI_PCND_SYS2_SORT_ROTATE	(1 << 1)
#define DI_PCND_SYS2_SORT_SHIFT		(1 << 2)
	unsigned long stack;
#define DI_PCND_SYS2_STACK			(1 << 0)
	unsigned long staple;
#define DI_PCND_SYS2_STAPLE_OFF				(1 << 0)
#define DI_PCND_SYS2_STAPLE_LEFTTOP			(1 << 1)
#define DI_PCND_SYS2_STAPLE_RIGHTTOP		(1 << 2)
#define DI_PCND_SYS2_STAPLE_LEFTTOPSLANT	(1 << 3)
#define DI_PCND_SYS2_STAPLE_RIGHTTOPSLANT	(1 << 4)
#define DI_PCND_SYS2_STAPLE_LEFT2			(1 << 5)
#define DI_PCND_SYS2_STAPLE_TOP2			(1 << 6)
#define DI_PCND_SYS2_STAPLE_RIGHT2			(1 << 7)
#define DI_PCND_SYS2_STAPLE_BOOKLET			(1 << 8)
	unsigned long punch;
#define DI_PCND_SYS2_PUNCH_OFF		(1 << 0)
#define DI_PCND_SYS2_PUNCH_LEFT2	(1 << 1)
#define DI_PCND_SYS2_PUNCH_TOP2		(1 << 2)
#define DI_PCND_SYS2_PUNCH_RIGHT2	(1 << 3)
#define DI_PCND_SYS2_PUNCH_LEFT3	(1 << 4)
#define DI_PCND_SYS2_PUNCH_TOP3		(1 << 5)
#define DI_PCND_SYS2_PUNCH_RIGHT3	(1 << 6)
#define DI_PCND_SYS2_PUNCH_LEFT4	(1 << 7)
#define DI_PCND_SYS2_PUNCH_TOP4		(1 << 8)
#define DI_PCND_SYS2_PUNCH_RIGHT4	(1 << 9)
#define DI_PCND_SYS2_PUNCH_LEFTGBC	(1 << 10)
#define DI_PCND_SYS2_PUNCH_TOPGBC	(1 << 11)
#define DI_PCND_SYS2_PUNCH_RIGHTGBC	(1 << 12)
#define DI_PCND_SYS2_PUNCH_LEFTTOP	(1 << 13)
	unsigned int qty;
	unsigned long tonersave_mono;
#define DI_PCND_SYS2_TONERSAVE_MONO_OFF		(1 << 0)
#define DI_PCND_SYS2_TONERSAVE_MONO_ON		(1 << 1)
	unsigned long upsidedown;
#define DI_PCND_SYS2_UPSIDEDOWN_OFF	(1 << 0)
#define DI_PCND_SYS2_UPSIDEDOWN_ON	(1 << 1)
	unsigned long reserve1;
	unsigned long mode;
#define DI_PCND_SYS2_MODE_FORCERIP	(1 << 0)
} di_sys2_printcondition_t;

typedef struct di_printconditionShm {
	unsigned int job_type;
	unsigned long change;
#define DI_PCND_CHG_PDL			(1 << 0)
#define DI_PCND_CHG_PDL2		(1 << 1)
#define DI_PCND_CHG_MEDIA		(1 << 2)
#define DI_PCND_CHG_SDK			(1 << 3)
#define DI_PCND_CHG_SYS			(1 << 4)
	di_printcondition_t	pdl;
	di_printcondition2_t pdl2;
	di_media_printcondition_t media;
	di_sdk_printcondition_t sdk;
	di_sys2_printcondition_t sys;
} di_printconditionShm_t;

typedef struct {
	unsigned long support_flag;
	unsigned long forced_flag;
#define DI_PARAM_PRINTERMARKINGTYPE			(1 << 0)
#define DI_PARAM_UCPMASKTYPE				(1 << 1)
#define DI_PARAM_UCPPATTERNCOLOR			(1 << 2)
#define DI_PARAM_UCPPATTERNDENSITY			(1 << 3)
#define DI_PARAM_UCPEFFECTCOPYGUARD			(1 << 4)
#define DI_PARAM_UCPUCPEFFECTCOPYINHIBITION	(1 << 5)
#define DI_PARAM_UCPSTRPOSITION				(1 << 6)
#define DI_PARAM_UCPSTRREPEATPRINT			(1 << 7)
#define DI_PARAM_UCPFONTNUMBER				(1 << 8)
#define DI_PARAM_UCPFONTSIZE				(1 << 9)
#define DI_PARAM_UCPLINESPACE				(1 << 10)
#define DI_PARAM_UCPSTRANGLE				(1 << 11)
#define DI_PARAM_UCPSTRING					(1 << 12)
#define DI_PARAM_UCPFONTTYPE				(1 << 13)
#define DI_PARAM_UCPFONTNUMBER2				(1 << 14)
#define DI_PARAM_UCPPATTERNCOLOR2			(1 << 15)
	unsigned char printermarkingtype;
	unsigned char ucpmasktype;
	unsigned char ucppatterncolor;
	unsigned char ucppatterndensity;
	unsigned char ucpeffectcopyguard;
	unsigned char ucpeffectcopyinhibition;
	unsigned char ucpstrposition;
	unsigned char ucpstrrepeatprint;
	unsigned char ucpfontnumber;
	unsigned char ucpstring_charcode;
	unsigned char ucpstring_default_charcode;
#define DI_UCP_CHAR_CODE_NONE		0	
#define DI_UCP_CHAR_CODE_SJIS		1
#define DI_UCP_CHAR_CODE_EUSTD		2
#define DI_UCP_CHAR_CODE_CE			3
#define DI_UCP_CHAR_CODE_GREEK		4
#define DI_UCP_CHAR_CODE_CYR		5
#define DI_UCP_CHAR_CODE_TUR		6
#define DI_UCP_CHAR_CODE_BALTIC		7
#define DI_UCP_CHAR_CODE_GB			8
#define DI_UCP_CHAR_CODE_BIG		9
#define DI_UCP_CHAR_CODE_HEBREW		10
#define DI_UCP_CHAR_CODE_ARABIC		11
#define DI_UCP_CHAR_CODE_THAI		12
#define DI_UCP_CHAR_CODE_KS			13
	unsigned short ucpfontsize;
	unsigned short ucplinespace;
	unsigned short ucpstrangle;
#define DI_MAX_UCPSTRING_LEN				64
	unsigned char ucpstring[DI_MAX_UCPSTRING_LEN + 1];
	unsigned char ucpstring_default[DI_MAX_UCPSTRING_LEN + 1];
#define DI_MAX_UCPFONTTYPE_LEN				210
	unsigned char ucpfonttype[DI_MAX_UCPFONTTYPE_LEN + 1];
	unsigned char ucpfontnumber2;
	unsigned char ucppatterncolor2;
} di_ucp_param_t;

enum {
	DI_STRING_DOT_DENSITY1,
	DI_STRING_DOT_DENSITY2,
	DI_STRING_DOT_DENSITY3,
	DI_STRING_DOT_DENSITY4,
	DI_STRING_DOT_DENSITY5,
	DI_BACKGROUND_DOT_DENSITY1,
	DI_BACKGROUND_DOT_DENSITY2,
	DI_BACKGROUND_DOT_DENSITY3,
	DI_BACKGROUND_DOT_DENSITY4,
	DI_BACKGROUND_DOT_DENSITY5,
	DI_MASKTYPE_AMIME,
	DI_MASKTYPE_HIGAKI,
	DI_MASKTYPE_KIKKOU,
	DI_MASKTYPE_KOUSHI1,
	DI_MASKTYPE_KOUSHI2,
	DI_MASKTYPE_MATSUKAWABISHI,
	DI_MASKTYPE_SEIGAIHA,
	DI_MASKTYPE_SHIPPOU,
	DI_MASKTYPE_SYOKKOU,
	DI_MASKTYPE_UROKO,
	DI_EFFECTCOPYGUARD_BACKGROUND,
	DI_EFFECTCOPYGUARD_STRING
};

typedef struct {
	unsigned char kind;
	unsigned char resolution;
#define DI_UCP_DATA_RES_200x200		(1)
#define DI_UCP_DATA_RES_300x300		(2)
#define DI_UCP_DATA_RES_400x400		(3)
#define DI_UCP_DATA_RES_600x600		(4)
#define DI_UCP_DATA_RES_600x1200	(5)
#define DI_UCP_DATA_RES_1200x600	(6)
#define DI_UCP_DATA_RES_1200x1200	(7)
	unsigned char depth;
#define DI_UCP_DATA_DEPTH_1BIT		(1)
#define DI_UCP_DATA_DEPTH_2BIT		(2)
#define DI_UCP_DATA_DEPTH_4BIT		(4)
} di_ucp_info_t;

typedef struct {
	unsigned char width;
	unsigned char length;
	long offset;
} di_ucp_data_t;

typedef struct {
	unsigned long flag;
#define DI_PINFO_NUP 		(1 << 0)
#define DI_PINFO_UPSIDEDOWN (1 << 1)
	struct {
			unsigned char layout;
#define DI_PINFO_NUPLAYOUT_OFF		0
#define DI_PINFO_NUPLAYOUT_2in1		1
#define DI_PINFO_NUPLAYOUT_4in1		2
#define DI_PINFO_NUPLAYOUT_6in1		3
#define DI_PINFO_NUPLAYOUT_8in1		4
#define DI_PINFO_NUPLAYOUT_9in1		5
#define DI_PINFO_NUPLAYOUT_16in1	6
			unsigned char option;
#define DI_PINFO_NUPOPTION_RIGHTTHENDOWN	0
#define DI_PINFO_NUPOPTION_LEFTTHENDOWN		1
#define DI_PINFO_NUPOPTION_DOWNTHENRIGHT	2
#define DI_PINFO_NUPOPTION_DOWNTHENLEFT		3
			unsigned char line;
#define DI_PINFO_NUPLINE_OFF	0
#define DI_PINFO_NUPLINE_ON		1
			unsigned char reserve;
	} nup;
	unsigned char upsidedown;
#define DI_PINFO_UPSIDEDOWN_OFF 0
#define DI_PINFO_UPSIDEDOWN_ON 	1
	unsigned char reserve1[3];
	unsigned long reserve2[4];
	unsigned long driver_flag;
#define DI_PINFO_D_WEEKLY			0
#define DI_PINFO_D_OUTPUT_REVERSE	1
#define DI_PINFO_D_USED_PROFILE		2
#define DI_PINFO_D_TAB				3
#define DI_PINFO_D_PRINTER_MARKING		4
#define DI_PINFO_D_TWIN_COLOR			5
	unsigned char driver_prtcond[32];
#define DI_PINFO_D_OFF	0
#define DI_PINFO_D_ON	1
} di_printinfo_t;

#include "di_paperdef.h"
#include "di_envdef.h"
#include "di_errorcode.h"

#ifndef DEFINE_DI_TYPE

#ifndef EXPORT
#ifndef DI_PACKDLL
#define EXPORT
#else
#define EXPORT  __declspec(dllexport)
#endif
#endif

/** \defgroup PublicInterface DI I/F
 * \{
 */

/**
 * \brief DI I/F�̏������A�y�ѐ��i���̎擾���s�Ȃ��B
 *
 * \param initinfo DI���l���Z�b�g����\���́B
 * \param setinfo  DI�ɓn���e��p�����[�^�B����GPS�݂̂ŗL���B
 *
 * \retval 0     ����I��
 * \retval 0�ȊO ���s
 *
 * \pre di_init() ���R�[������Ă��Ȃ��B
 * \pre ���� *initinfo �ɃA�N�Z�X�\�B
 * \pre ���� *setinfo �ɃA�N�Z�X�\�B
 * \pre ���� setinfo->interp_id ���ȉ��̂����ꂩ�B
 *  \li DI_ITNERP_RPCS
 *  \li DI_INTERP_XHTML
 *  \li DI_INTERP_EXIF
 *  \li DI_INTERP_BMLINKS
 *  \li DI_INTERP_PS
 *  \li DI_INTERP_PCL
 * \pre ���� setinfo->async ���A�N�Z�X�\(GPS����̂�)�B
 *
 * \post di_term() ���R�[�������܂� di_init() �͎g�p�s�\�B
 * \post di_term() ���R�[�������܂�di_init()�������S�Ă̂c�h�̃C���^�[
 * �t�F�[�X���g�p�\�B
 * \post di_term()���R�[�������܂�setinfo->async�̊e�p�����[�^���񓯊�
 * �ɍX�V�����(GPS����̂�)�B
 * \post �p�l���ɂc�h���g�p���Ă���v�����^�A�v�����\��(GPS����̂�)�B
 * \post ���� *initinfo ���̃����o���K�؂Ȓl�ɍX�V�����B
 */
extern EXPORT int di_init( di_initinfo_t *initinfo, di_setinfo_t *setinfo );

/**
 * \brief DI���Z�b�g�����p�����[�^���N���A����B
 *
 *  \param devinfo   ��񂪊i�[����Ă���\���́B
 *  \param free_func �{�֐����Ń�������������邽�߂̃R�[���o�b�N�֐��B
 *
 * \retval 0     ����I��
 * \retval 0�ȊO ���s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *devinfo �ɃA�N�Z�X�\�B
 * \pre free_func �ɃR�[���\�B
 *
 * \post di_getinfo()�Ŋm�ۂ����������́Afree_func���g�p���ĉ�������B
 * \post *devinfo�̃p�����[�^�̓[���N���A�����B
 */
extern EXPORT int di_clear( di_devinfo_t *devinfo, DI_CALLBACK_MEMFREE free_func );

/**
 * \brief DI I/F�̏I���������s�Ȃ��B
 *
 * \post di_init(),di_term()�������S�Ă̂c�h�̃C���^�[�t�F�[�X���g�p�s�B
 * \post �v�����^�n�r���A�c�h���g�p���Ă���v�����^�A�v���̏I����F���B
 */
extern EXPORT void di_term();

/**
 * \brief �v�����^�A�v���̋N������I���܂ŕω����Ȃ��@��ˑ����̎擾��
 *�s�Ȃ��B
 *
 *  \param devinfo �����i�[����\���́B
 *  \param alloc_func �{�֐����Ń��������m�ۂ��邽�߂̃R�[���o�b�N�֐��B
 *	\param dither_gamma_file �f�B�U��K���}�t�@�C���̃t�@�C�����i�t���p�X
 *�w��j�B
 *
 * \return �Ԃ�l���O�ȊO�̏ꍇ�́A�ȉ��̃r�b�g�t���O��On�̈Ӗ��ƂȂ�B
 *�����̃t���O��On�ƂȂ�ꍇ������B
 *
 * \retval 0     ����I��
 * \retval DI_GI_ERR_CONDITION  ���O�����𖞂����Ă��Ȃ�
 * \retval DI_GI_ERR_DITHER     dither_info �擾���s
 * \retval DI_GI_ERR_GAMMA      gamma_info �擾���s
 * \retval DI_GI_ERR_FONT       font_address & font_size �擾���s
 * \retval DI_GI_ERR_PROF       profaddress & profnumber �擾���s
 * \retval DI_GI_ERR_RESO       resonum & reso_set �擾���s
 * \retval DI_GI_ERR_NDIT       ndit �擾���s
 * \retval DI_GI_ERR_NPLANE     nplane �擾���s
 * \retval DI_GI_ERR_BGUCR      bg_(startp/slant) & ucr_(startp/slant)
 *�擾���s
 * \retval DI_GI_ERR_TSAVE      soft_tsave �擾���s
 * \retval DI_GI_ERR_TSAVE_R    tsave_ratio �擾���s
 * \retval DI_GI_ERR_TLIMIT     toner_limit �擾���s
 * \retval DI_GI_ERR_TLIMIT_R   tlimit_num & tlimit_val �擾���s
 * \retval DI_GI_ERR_SHDM       shdm_addr �擾���s
 * \retval DI_GI_ERR_SYSH       sys_handle �擾���s
 * \retval DI_GI_ERR_EXTENDTSAVE      extend_soft_tsave �擾���s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *devinfo���A�N�Z�X�\�B
 * \pre alloc_func( size )���R�[������ƁAsize �����m�ۂ����������̐擪
 *�A�h���X�̒l���Ԃ��Ă���B
 * \pre dither_gamma_file �Ƃ����t�@�C�������݂���A��������
 *dither_gamma_file��NULL�B
 * \pre alloc_func�Ŏ擾���郁�����T�C�Y�́AGPS���Ŗ�300Byte�AGPS�ȊO
 *�̊��Ŗ�65KByte �ƂȂ�B
 *
 * \post *devinfo���̃����o���K�؂Ȓl�ɍX�V�����B
 */
extern EXPORT int di_getinfo(di_devinfo_t *devinfo,
							 DI_CALLBACK_MEMALLOC alloc_func,
							 char *dither_gamma_file);

/**
 * \brief �v�����^�n�r����C�x���g�v�����擾����B
 *
 * �I���v���ȊO�̗v���̏ꍇ,�C���^�v���^�̓f�[�^�����\��ԂƂȂ�B
 *
 * \retval DI_REQ_PROCESS    �ʏ폈���v��
 * \retval DI_REQ_CANCEL     �ʏ폈���{�W���u�L�����Z���v��
 * \retval DI_REQ_EXIT       �I���v��
 * \retval -1                �G���[
 *
 * \pre di_init() ���R�[������Ă���
 *
 * \post �Ԃ�l�ɃV�X�e������̗v�����i�[�����B
 * \post �Ԃ�l��DI_REQ_PROCESS,DI_REQ_CANCEL�̏ꍇ�ɂ́A�v�����^�n�r
 *�̓v�����^�A�v�����f�[�^������ԂɂȂ����Ɣ��f����B
 * \post �Ԃ�l��DI_REQ_EXIT�̏ꍇ�ɂ́A�v�����^�n�r�̓v�����^�A�v����
 *�A�C�h����ԂɂȂ����Ɣ��f����B
 */
extern EXPORT int di_get_request();

/**
 * \brief �g���C���̎擾���s���B
 *
 * \param trayinfo �g���C�����i�[����\����
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[�A�g���C���擾���s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *trayinfo���A�N�Z�X�\�B
 *
 * \post *trayinfo���̃����o���K�؂Ȓl�ɍX�V�����B
 */
extern EXPORT int di_get_trayinfo(di_trayinfo_t *trayinfo );

/**
 * \brief �A�v���ŗL��񂩂�w��J�e�S���̃L�[�̒l���擾����B
 *
 * \param key      �����L�[(������)
 * \param category �����J�e�S��(������)
 * \param value    ��������(������)���i�[����̈�
 *
 * \retval  DI_PINI_OK                 ��������
 * \retval  DI_PINI_KEY_NOT_FOUND      �Y������key��������Ȃ�����
 * \retval  DI_PINI_CATEGORY_NOT_FOUND �Y������category��������Ȃ�
 *����
 * \retval  DI_PINI_ERROR              �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre key�̕��������^�[�~�l�[�g���܂�1�����ȏ�32�����ȓ�
 * \pre category�̕��������^�[�~�l�[�g���܂�1�����ȏ�32�����ȓ�
 * \pre value[0]�`value[DI_MAX_VALUE_LEN-1]�܂ŃA�N�Z�X�\
 *
 * \post ��������������value�ɏ������܂��B������DI_MAX_VALUE_LEN
 *��蒷���ꍇ�́ADI_MAX_VALUE_LEN-1�܂ł̕�������擾���āA
 *value[DI_MAX_VALUE_LEN-1]�ɏI�[������ǉ�����B
 */
extern EXPORT int di_get_appinfo(char *key, char *category, char value[]);

/**
 * \brief ���ϐ��̒l���擾����B
 *
 * \param table_name ���ϐ��e�[�u����
 * \param id         ���ϐ�ID
 * \param val        ����ꂽ���ϐ��̒l
 *
 * \retval  1 ����I���i���ϐ��������I�Ɏw�肳��Ă���j
 * \retval  0 ����I���i���ϐ��������I�Ɏw�肳��ĂȂ����߁A�f�t�H��
 *�g�l�Z�b�g)
 * \retval -1 �G���[�idi_init()���R�[������Ă��Ȃ��j
 * \retval -2 �G���[�itable_name�����݂��Ȃ��j
 * \retval -3 �G���[�i�w�肵�����ϐ����Ȃ��j
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name�Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name�ɑ��݂���B
 * \pre *val���A�N�Z�X�\�B
 *
 * \post *val�Ɏw�肵�����ϐ��̒l���i�[�����B
 */
extern EXPORT int di_get_envvalue( char *table_name, long id, long *val );

/**
 * \brief ���ϐ��̒l���Z�b�g����B
 *
 * \param table_name ���ϐ��e�[�u����
 * \param id         ���ϐ�ID
 * \param val        �Z�b�g������ϐ��̒l
 *
 * \retval  0 ����I��
 * \retval -1 �G���[�idi_init()���R�[������Ă��Ȃ��j
 * \retval -2 �G���[�itable_name�����݂��Ȃ��j
 * \retval -3 �G���[�i �w�肵�����ϐ����Ȃ��j
 * \retval -4 �G���[�i���[�h�I�����[�̊��ϐ��j
 * \retval -5 �G���[�i val ���ݒ�s�\�Ȓl�j
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name�Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���A�ݒ�\�ȕϐ��Ƃ���table_name�ɑ��݂���B
 *
 * \post di_set_envvalue( table_name, id, k )�Ƃ����`���Ŗ{�֐����R�[
 *�������ꍇ�Adi_get_envvalue( table_name, id, &val )�Ƃ����val �� k
 * ���Z�b�g�����B
 */
extern EXPORT int di_set_envvalue( char *table_name, long id, long val );

/**
 * \brief DI�̓���̃^�C�~���O�ŃR�[������֐����w�肷��B
 *
 * \param type ���� func �Ŏw�肳�ꂽ�R�[���o�b�N�֐����R�[������^�C�~���O�B
 *�e�l�ɑ΂���^�C�~���O�͈ȉ��̂Ƃ���B
 *  <table>
 *   <tr>
 *    <td>DI_CALLBACK_READERR_SINGETC</td>
 *    <td>di_singetc() ���œǂݍ��݂����s�����ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_READERR_SINGET</td>
 *    <td>di_singet( )���œǂݍ��݂����s�����ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_SIZEERR_SINGET</td>
 *    <td>di_singet( )�̈����ŁA�T�C�Y�w�肪�s���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_PROCDATA</td>
 *    <td>�V�X�e������f�[�^�����̊J�n�v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_EXIT</td>
 *    <td>�V�X�e������C���^�v���^�I���v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_CANCEL</td>
 *    <td>�V�X�e������f�[�^�����̒��~�v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_ONLINE</td>
 *    <td>�V�X�e������I�����C���v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_OFFLINE</td>
 *    <td>�V�X�e������I�t���C���v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_TESTPRINT</td>
 *    <td>�V�X�e������e�X�g�v�����g�v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_TRAYINFO</td>
 *    <td>�V�X�e�����狋���g���C�̕ύX�ʒm�������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_BININFO</td>
 *    <td>�V�X�e������r���r���̕ύX�ʒm�������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_EXITPAPER</td>
 *    <td>�V�X�e�����狭���r���v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_FONTCOUNT</td>
 *    <td>�V�X�e������t�H���g���̃J�E���g�v���������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_PRTSTATUS</td>
 *    <td>�V�X�e������v�����^�X�e�[�^�X���̕ύX�ʒm�������ꍇ</td>
 *   </tr>
 *   <tr>
 *    <td>DI_CALLBACK_REQ_GAM</td>
 *    <td>�V�X�e������K���}�̍Čv�Z�v���������ꍇ</td>
 *   </tr>
 *  </table>
 * \param func �w�肷��R�[���o�b�N�֐�
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre type �������̐����ɂ���l�̂����ꂩ
 * \pre func ���R�[���\
 *
 * \post type �ɂ��w�肳�ꂽ�^�C�~���O�� func ���R�[������B
 */
extern EXPORT int di_set_callbackfunc( int type, DI_CALLBACK_FUNC func );

/**
 * \brief �v�����^�n�r���Ǘ����Ă��郁�����̊m�ۂ��s���B
 *
 * \param size �m�ۂ��郁�����T�C�Y(Byte)
 *
 * \retval �m�ۂ����������̐擪�A�h���X �m�ې���
 * \retval NULL �G���[�A�������m�ێ��s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre di_memory_alloc()���P�x���R�[������Ă��Ȃ�(GPS����̂�)
 *
 * \post �Ԃ�l�̃A�h���X����size�o�C�g���A�N�Z�X�\
 */
extern EXPORT char *di_memory_alloc(unsigned long size);

/**
 * \brief di_memory_alloc() �Ŋm�ۂ����������̉�����s���B
 *
 * \param ptr ������郁�����̐擪�A�h���X
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre ptr��di_memory_alloc()�Ŋm�ۂ����������̐擪�A�h���X�A�������͂O
 *
 * \post ��������������́A�v�����^�n�r�����p�\
 */
extern EXPORT int di_memory_free(char *ptr);

/**
 * \brief ���̓z�X�g�o�b�t�@���I�[�v������B
 * �f�[�^�ǂݍ��ݑO�ɕK���{�֐����R�[�����邱��
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �V�X�e������ʏ폈���v�������Ă���
 *(di_get_request(),di_trans_process()�Q��)
 *
 * \post di_close_host()�A�������� di_trans_process() ���R�[������܂�
 *�ȉ��� I/F ���g�p�\
 *  \li di_singetc()
 *  \li di_singet()
 *  \li di_sinpeekc()
 *  \li di_sinpeek()
 *  \li di_reset_sinpeek()
 *  \li di_sinseek()
 */
extern EXPORT int di_open_host();

/**
 * \brief di_open_host()�ɂ��I�[�v�����ꂽ �z�X�g�o�b�t�@���N���[�Y
 *����B
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post di_open_host() ���R�[������܂ňȉ���I/F���g�p�s�\�B
 *  \li di_singetc()
 *  \li di_singet()
 *  \li di_sinpeekc()
 *  \li di_sinpeek()
 *  \li di_reset_sinpeek()
 *  \li di_sinseek()
 */
extern EXPORT int di_close_host();

/**
 * \brief ���̓X�g���[������P�o�C�g�̓ǂݍ��ށB
 *
 * \param dat �ǂݍ��񂾃f�[�^�̒l
 *
 * \retval 0     �ǂݍ��ݐ���
 * \retval 0�ȊO �G���[�A�ǂݍ��ݎ��s�AEOF
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre *dat ���A�N�Z�X�\
 *
 * \post *dat�ɓ��̓X�g���[���̐擪�P�o�C�g���i�[�����B
 * \post ���[�h�|�C���^�A�s�[�N�|�C���^�����̓ǂݍ��݈ʒu�Ɉړ�����
 */
extern EXPORT int di_singetc( unsigned char *dat );

/**
 * \brief ���̓X�g���[�����畡���o�C�g�ǂݍ��ށB
 *
 * \param buf �ǂݍ��ݐ�o�b�t�@
 * \param len �ǂݍ��ރT�C�Y(Byte)
 *
 * \retval >0 �ǂݍ��񂾃f�[�^�̃o�C�g��
 * \retval 0  EOF
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre ���̓z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre len ��0�ȏ�
 * \pre len ��1�ȏ�̏ꍇ�� buf[0]�`buf[len-1] ���A�N�Z�X�\
 *
 * \post buf�ɓ��̓X�g���[���̐擪len�o�C�g���i�[�����B
 * \post ���[�h�|�C���^�A�s�[�N�|�C���^�����̓ǂݍ��݈ʒu�Ɉړ�����B
 */
extern EXPORT int di_singet( unsigned char *buf, long len );

/**
 * \brief ���̓X�g���[������P�o�C�g�ǂݍ��ށB
 *
 * �ǂݍ��񂾃f�[�^���e�͔j�����Ȃ����߁Adi_reset_sinpeek() �ɂ��ē�
 *�ݍ��݉\�B
 *
 * \param dat �ǂݍ��񂾃f�[�^�̒l
 *
 * \retval 0     �ǂݍ��ݐ���
 * \retval 0�ȊO �G���[�AEOF�A�ǂݍ��񂾃f�[�^���z�X�g�o�b�t�@�̃T�C�Y
 *�𒴂����ꍇ
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre *dat ���A�N�Z�X�\
 * \pre ���̓X�g���[���� hostI/O�i di_select_idevice()�Q�Ɓj
 * \pre di_reset_sinpeek() ���R�[������Ă���B
 *
 * \post *dat�ɓ��̓X�g���[���̐擪�P�o�C�g���i�[�����B
 * \post �s�[�N�|�C���^���P�o�C�g�����B
 */
extern EXPORT int di_sinpeekc( unsigned char *dat );

/**
 * \brief ���̓X�g���[�����畡���o�C�g�ǂݍ��ށB
 *
 * �ǂݍ��񂾃f�[�^���e�͔j�����Ȃ����߁Adi_reset_sinpeek() �ɂ��ē�
 *�ݍ��݉\�B
 *
 * \param buf �ǂݍ��ݐ�o�b�t�@
 * \param len �ǂݍ��ރT�C�Y(Byte)
 *
 * \retval >0 �ǂݍ��񂾃f�[�^�̃o�C�g��
 * \retval 0  EOF�A�s�[�N�œǂݍ��񂾃f�[�^���z�X�g�o�b�t�@�̃T�C�Y��
 *�������ꍇ
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre len ��0�ȏ�
 * \pre len ��1�ȏ�̏ꍇ�� buf[0]�`buf[len-1] ���A�N�Z�X�\
 * \pre ���̓X�g���[���� hostI/O�i di_select_idevice()�Q�Ɓj
 * \pre di_reset_sinpeek() ���R�[������Ă��āA�����̌��
 * di_singetc() , di_singet() , di_sinseek() �̂�������R�[������Ă�
 *�Ȃ��B
 *
 * \post buf�ɓ��̓X�g���[���̐擪len�o�C�g���i�[�����B
 * \post �s�[�N�|�C���^���P�o�C�g�����B
 */
extern EXPORT int di_sinpeek( unsigned char *buf, long len );

/**
 * \brief �z�X�g�o�b�t�@�̓ǂݍ��݈ʒu���A�L���f�[�^�̐擪�Ɉړ�����B
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre ���̓X�g���[���� hostI/O�i di_select_idevice()�Q�Ɓj
 *
 * \post �s�[�N�|�C���^�����[�h�|�C���^�̈ʒu�Ɉړ�����B
 */
extern EXPORT int di_reset_sinpeek();

/**
 * \brief �z�X�g�o�b�t�@�ɑ΂��āA�w�肵���o�C�g�������ǂݎ̂Ă�B
 *
 * \param len �ǂݍ��ރT�C�Y(Byte)
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �z�X�g���I�[�v������Ă���i di_open_host() �Q�Ɓj
 * \pre ���̓X�g���[���� hostI/O�i di_select_idevice()�Q�Ɓj
 *
 * \post ���[�h�|�C���^�ƃs�[�N�|�C���^�����[�h�|�C���^�̈ʒu�Ɉړ�����B
 */
extern EXPORT int di_sinseek( long len );

/**
 * \brief ���̓X�g���[����ύX����B
 *
 * �f�t�H���g�� DI_HOST_IO
 *
 * \param mode �ȉ��̎w����̓X�g���[��
 *   \li DI_HOST_IO   host I/O
 *   \li DI_MEMORY_IO memory buffer I/O
 *   \li DI_FILE_IO   file I/O
 * \param opt mode�ɂ����e���ω�����
 *  <table>
 *   <tr>
 *    <td><center>mode</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>DI_HOST_IO</td>
 *    <td>�g�p���Ȃ�</td>
 *   </tr>
 *   <tr>
 *    <td>DI_MEMORY_IO</td>
 *    <td>
 *      ����������ǂݍ��ރR�[���o�b�N�֐�<br>
 *      �^:typedef int (*CALLBACK_MEMREAD)( unsigned char **, int * );<br>
 *      ��P����: �ǂݍ��ݐ�A�h���X<br>
 *      ��Q����: �ǂݍ��ރT�C�Y<br>
 *    </td>
 *   </tr>
 *   <tr>
 *    <td>DI_FILE_IO</td>
 *    <td>�t�@�C���|�C���^(�^��FILE *)</td>
 *   </tr>
 *  </table>
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre mode �������̐����ɂ���l�̂����ꂩ
 * \pre opt ���L���p�����[�^�i�����̐����Q�Ɓj
 *
 * \post di_singetc() , di_singet() �̓ǂݍ��ݐ悪 mode �ɕύX�����B
 */
extern EXPORT int di_select_idevice( int mode, void *opt );

/**
 * \brief ����𑼃v���Z�X�ֈڍs����
 *
 * �{�֐��I�����I/O���؂藣���ꂽ��ԂƂȂ邽��,
 *�ēx�o�b�t�@����̓ǂݍ��݂��s�Ȃ��ꍇ��di_open_host()���R�[������
 *���ƁB
 *
 * \return �ēx���䂪�ڍs���Ă������̃V�X�e������̗v��
 * \retval DI_REQ_EXIT    �I���v��
 * \retval DI_REQ_PROCESS �ʏ폈���v��
 * \retval DI_REQ_CANCEL  �W���u�L�����Z���v��
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post �Ԃ�l�ɃV�X�e������̗v�����i�[�����B
 * \post �z�X�g�o�b�t�@���N���[�Y��ԂƂȂ�B
 */
extern EXPORT int di_trans_process();

/**
 * \brief �v�����^OS�փ��b�Z�[�W��ʒm����B
 *
 * \param msg �ʒm���郁�b�Z�[�W
 *  \li DI_NOTIFYMSG_JOBEND    �W���u�̏I��
 *  \li DI_NOTIFYMSG_STATE     ��Ԃ̒ʒm
 *  \li DI_NOTIFYMSG_STRING    ������ɂ���Ԃ̒ʒm
 *  \li DI_NOTIFYMSG_ERRFORCE  �G���[�̋����ʒm
 *  \li DI_NOTIFYMSG_START     �����I�ȋN���ʒm�Bdi_init() �Ŏw�肷��
 *�C���^�v���^ ID ��[ DI_INTERP_PS , DI_INTERP_PCL ] �̏ꍇ�ɕK�v�B
 *  \li DI_NOTIFYMSG_FONTCOUNT �t�H���g�J�E���g�̏I���ʒm
 *  \li DI_NOTIFYMSG_PAUSE �ꎞ��~�v���ɑ΂��鉞���i�����A�������͈ꎞ��~�ł��Ȃ��j�ʒm
 *  \li DI_NOTIFYMSG_RESUME �����ĊJ�ʒm
 * \param opt msg�ɂ����e���ω�����B
 *  <table>
 *   <tr>
 *    <td><center>msg</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_JOBEND</td>
 *    <td>�g�p���Ȃ�</td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_STATE</td>
 *    <td>�ʒm������<br>
 *        DI_INTERP_STATE_IDLE       �i�f�[�^�҂����j<br>
 *        DI_INTERP_STATE_PROCESSING �i�f�[�^�������j<br>
 *        DI_INTERP_STATE_WAITING    �i�f�[�^���������f�[�^�҂��j<br>
 *        DI_INTERP_STATE_FLUSHING   �i�f�[�^�L�����Z�����j<br>
 *    </td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_STRING</td>
 *    <td>������̐擪�A�h���X</td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_ERRFORCE</td>
 *    <td>�G���[�R�[�h(�ڍׂ�GPS�d�l��)</td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_START</td>
 *    <td>�C���^�v���^ID�B di_setinfo_t �Q��</td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_FONTCOUNT</td>
 *    <td>�g�p���Ȃ�</td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_PAUSE</td>
 *    <td>�ʒm������<br>
 *        DI_INTERP_PAUSE_OK	�i�ꎞ��~�������j<br>
 *        DI_INTERP_PAUSE_NG	�i�ꎞ��~�ł��Ȃ��j<br>
 *    </td>
 *   </tr>
 *   <tr>
 *    <td>DI_NOTIFYMSG_RESUME</td>
 *    <td>�g�p���Ȃ�</td>
 *   </tr>
 *  </table>
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre msg �������̐����ɂ���l�̂����ꂩ
 *
 * \post msg �� DI_NOTIFYMSG_JOBEND �Ȃ�A�v�����^�n�r�̓v�����^�A�v��
 *���A�C�h����ԂɂȂ����Ɣ��f����B
 * \post msg �� DI_NOTIFYMSG_STATE �Ȃ�A�v�����^�n�r�̓v�����^�A�v����
 *opt�̏�ԂƔ��f����B
 * \post msg �� DI_NOTIFYMSG_ERRFORCE �Ȃ�A�p�l���ւ̃G���[�\���ƃG��
 *�[���M���O���f���s���B
 * \post msg �� DI_NOTIFYMSG_STRING �Ȃ�A�v�����^�n�r�̓v�����^�A�v��
 *��������w��̏�ԂɂȂ����Ɣ��f����B
 * \post msg �� DI_NOTIFYMSG_START �Ȃ�A�v�����^�n�r�̓v�����^�A�v����
 *�N�����ꂽ�Ɣ��f����B
 * \post msg �� DI_NOTIFYMSG_FINISH_FONTCOUNT �Ȃ�A�v�����^�n�r�̓t�H
 *���g�J�E���g���I�����ꂽ�Ɣ��f����B
 * \post msg �� DI_NOTIFYMSG_PAUSE �Ȃ�A�v�����^�n�r�̓v�����^�A�v����
 *opt�̏�ԂƔ��f����B
 * \post msg �� DI_NOTIFYMSG_RESUME �Ȃ�A�v�����^�n�r�̓v�����^�A�v����
 *�����ĊJ���ꂽ�Ɣ��f����B
 */
extern EXPORT int di_notify_msg( int msg, long opt );

/**
 * \brief �w�肵���p���T�C�Y���v�����^���T�|�[�g���Ă��邩�₢���킹��B
 *
 * \param paper_id �p���T�C�YID(GPS��`)
 *
 * \retval  1 �T�|�[�g����Ă���
 * \retval  0 �T�|�[�g����Ă��Ȃ�
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post �Ԃ�l���P�Ȃ�A���̗p���T�C�Y�ŏo�͉\
 */
extern EXPORT int di_query_supportpaper( int paper_id );

/**
 * \brief �W���u�ɐݒ肳��Ă���I�v�V������������擾����B
 *
 * \param str �I�v�V����������̐擪�A�h���X
 *
 * \retval  0 ����
 * \retval -1 ���s(�w�肳�ꂽ�I�v�V�����������r���܂ł����擾�ł���
 *������)�Bstr�ɂ͓r���܂ł̕�����̃A�h���X��Ԃ�
 * \retval -2 ���s�A�G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *str ���A�N�Z�X�\�B
 * \pre �v�����^OS���ʏ폈���v�������Ă���B
 *
 * \post *str�ɃI�v�V����������̐擪�A�h���X���i�[�����B
 */
extern EXPORT int di_get_optstr( char **str );

/**
 * \brief �G���[�v�����g�p�̃o�b�t�@�̃A�h���X�擾
 *
 * \param buffer ���܂ł̃o�b�t�@�̐擪�A�h���X
 * \param size   �擾�����o�b�t�@�̃T�C�Y
 *
 * \retval �擾�����o�b�t�@�̐擪�A�h���X ����I��
 * \retval NULL  �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *buffer ���A�N�Z�X�\�B
 * \pre *size ���A�N�Z�X�\
 *
 * \post �Ԃ�l�Ɏ擾�����o�b�t�@�̐擪�A�h���X���Ԃ��Ă���B
 */
extern EXPORT char *di_get_epbuffer( char *buffer, int *size );

/**
 * \brief �w�肵���p���̃T�C�Y���擾����
 *
 * \param code   �p���R�[�h
 * \param width  �p�����i0.1mm�P�ʁj
 * \param length �p�������i0.1mm�P�ʁj
 *
 * \retval  1 �T�|�[�g���Ă���
 * \retval  0 �T�|�[�g���Ă��Ȃ�
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post *width ���p���R�[�h code �̗p�����ƂȂ�
 * \post *length ���p���R�[�h code �̗p�������ƂȂ�
 */
extern EXPORT int di_get_papersize( unsigned char code,
									unsigned int *width,
									unsigned int *length );

/**
 * \brief �o�̓z�X�g�o�b�t�@���I�[�v������B
 *
 * �f�[�^�������ݑO�ɕK���{�֐����R�[�����邱��
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �V�X�e������ʏ폈���v�������Ă���i di_get_request() �A
 * di_trans_process() �Q�Ɓj
 *
 * \post di_close_ohost() �A�������� di_trans_process() ���R�[�������
 *�ňȉ���I/F���g�p�\�B
 *  \li di_soutputc()
 *  \li di_soutput()
 *  \li di_soutflush()
 */
extern EXPORT int di_open_ohost();

/**
 * \brief di_open_ohost() �ɂ��I�[�v�����ꂽ�z�X�g�o�b�t�@���N���[�Y
 *����B
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post di_open_ohost() ���R�[������܂ňȉ���I/F���g�p�s�\�B
 *  \li di_soutputc()
 *  \li di_soutput()
 *  \li di_soutflush()
 */
extern EXPORT int di_close_ohost();

/**
 * \brief �o�̓X�g���[���ւP�o�C�g�������ށB
 *
 * ���M�o�b�t�@�ɏ������ݗ̈悪�Ȃ��ꍇ�ɂ́A���M�f�[�^���������ޗ̈�
 *���ł���܂Ńu���b�N����B
 *
 * \param dat �������ރf�[�^�̒l
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[�A�������ݎ��s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �o�̓z�X�g���I�[�v������Ă���i di_open_ohost() �Q�Ɓj
 *
 * \post ���M�o�b�t�@�� dat ���������܂��B
 */
extern EXPORT int di_soutputc( unsigned char dat );

/**
 * \brief �o�̓X�g���[���֕����o�C�g�������ށB
 *
 * \param buf �������ރf�[�^
 * \param len �ǂݍ��ރT�C�Y(Byte)
 * \param flag �������ݕ��@
 *  <table>
 *   <tr>
 *    <td><center>�l</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>DI_HOST_BLOCK</td>
 *    <td>�m���u���b�N�w��Ȃ��B���M�o�b�t�@�ɏ������ݗ̈悪�Ȃ��ꍇ��
 *        �́A���M�f�[�^���������ޗ̈悪�ł���܂Ńu���b�N����B</td>
 *   </tr>
 *   <tr>
 *    <td>DI_HOST_NONBLOCK</td>
 *    <td> �m���u���b�N�w�肠��B���M�o�b�t�@�̃u���b�N�͂��Ȃ��i�o�b
 *        �t�@������܂ŏ������݁A�������߂��o�C�g����߂�l�Ƃ��ĕ�
 *        ���j�B</td>
 *   </tr>
 *  </table>
 *
 * \retval >=0 �������񂾃f�[�^�̃o�C�g��
 * \retval  -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �o�̓z�X�g���I�[�v������Ă���i di_open_ohost() �Q�Ɓj
 * \pre len ��0�ȏ�
 * \pre len ��1�ȏ�̏ꍇ�� buf[0]�`buf[len-1] ���A�N�Z�X�\
 *
 * \post buf �̓��e���o�̓X�g���[���ɏ������܂��
 */
extern EXPORT int di_soutput( unsigned char *buf, long len, int flag );

/**
 * \brief ���M�o�b�t�@���ɏ������܂ꂽ���A�܂����M����Ă��Ȃ��f�[�^��
 *�z�X�g�ɑ��M����B
 *
 * di_soutputc() ���邢�� di_soutput() �ɂĈ��؂�̑��M�f�[�^�𑗐M
 *�o�b�t�@�ɏ������񂾌�A�K���A���̊֐����ĂԂ��ƁB
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �V�X�e������ʏ폈���v�������Ă���i di_get_request() ,
 * di_trans_process() �Q�Ɓj
 *
 * \post ���M�o�b�t�@�̃f�[�^���S�đ��M�����B
 */
extern EXPORT int di_soutflush();

/**
 * \brief ���̓X�g���[���̗L���o�C�g�����擾����B
 *
 * \param len ���̓X�g���[���o�b�t�@���̗L���ȃf�[�^�̃o�C�g��
 *
 * \retval  1 ����I��(EOF���o�b�t�@�Ɋ܂܂�Ă���)
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �o�̓z�X�g���I�[�v������Ă���i di_open_ohost() �Q�Ɓj
 * \pre *len ���A�N�Z�X�\
 *
 * \post *len�ɓ��̓X�g���[���̗L���o�C�g�����i�[�����B
 */
extern EXPORT int di_sinavail( long *len );

/**
 * \brief ���ݎw�肳��Ă���D�拋���g���C�����擾����B
 *
 * \param tray_id �D�拋���g���C���Ɏw�肳��Ă���g���CID�B
 * di_onetrayinfo_t �Q�ƁB
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *tray_id ���A�N�Z�X�\
 *
 * \post �D��g���C�� ID �� *tray_id �Ɋi�[�����B
 */
extern EXPORT int di_get_deftray( int *tray_id );

/**
 * \brief ���ݎw�肳��Ă���D��r���r�������擾����B
 *
 * \param bin_id �D��r���r�����Ɏw�肳��Ă���r��ID�B
 * di_onebininfo_t �Q�ƁB
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *bin_id ���A�N�Z�X�\
 *
 * \post �D��r���r����ID��*bin_id�Ɋi�[�����
 */
extern EXPORT int di_get_defbin( int *bin_id );

/**
 * \brief �r���r�����̎擾���s���B
 *
 * \param bininfo �r���r�����
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *bininfo ���A�N�Z�X�\
 *
 * \post *bininfo �̒l�Ɣr���r���̏�񂪈�v����B
 */
extern EXPORT int di_get_bininfo( di_bininfo_t *bininfo );

/**
 * \brief �v�����^�̃X�e�[�^�X�����擾����B
 *
 * \param status �X�e�[�^�X���
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *status ���A�N�Z�X�\
 *
 * \post *status �̒l�ƃv�����^�̃X�e�[�^�X��񂪈�v����B
 */
extern EXPORT int di_get_status( di_status_t *status );

/**
 * \brief �g�[�^���J�E���^�[�̒l���擾����B
 *
 * \param cnt �g�[�^���J�E���^�[�̒l
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *tray_id ���A�N�Z�X�\
 *
 * \post cnt �̒l�ƃg�[�^���J�E���^�[�̒l����v����B
 */
extern EXPORT int di_get_totalcounter( long *cnt );

/**
 * \brief EhterTalk �p�����[�^���擾����B
 *
 * \param info EtherTalk �p�����[�^
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *info ���A�N�Z�X�\
 *
 * \post info �̒l��EtherTalk�p�����[�^�̒l����v����B
 */
extern EXPORT int di_get_ethertalkinfo( di_ethertalk_info_t *info );

/**
 * \brief EhterTalk �p�����[�^��ݒ肷��B
 *
 * \param info EtherTalk �p�����[�^
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *info ���A�N�Z�X�\
 *
 * \post di_get_ethertalkinfo() �Ŏ擾����Ethertalk�p�����[�^�� *info �Ɠ������Ȃ�B
 */
extern EXPORT int di_set_ethertalkinfo( di_ethertalk_info_t *info );

/**
 * \brief ���[�U�[�W���u����ݒ肷��B
 *
 * \param job_id ���[�U�[�W���uID
 * \param info   ���[�U�[�W���u���
 *
 * \retval 0     ����I��
 * \retval -1    �G���[
 * \retval -2    �w�肵���p�����[�^���T�|�[�g���Ă��Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �V�X�e������ʏ폈���v�������Ă���
 * ( di_get_request() , di_trans_process )�Q��
 * \pre *info ���A�N�Z�X�\
 *
 * \post ���[�U�[�W���u��񂪃V�X�e���ɐݒ肳��Ă���B
 */
extern EXPORT int di_set_ujobinfo( int job_id, di_ujob_info_t *info );

/**
 * \brief ���[�U�[�W���u�����擾����B
 *
 * \param job_id ���[�U�[�W���uID
 * \param info   ���[�U�[�W���u���
 *
 * \retval 0     ����I��
 * \retval -1    �G���[
 * \retval -2    �w�肵���p�����[�^���T�|�[�g���Ă��Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre �V�X�e������ʏ폈���v�������Ă���
 * ( di_get_request() , di_trans_process )�Q��
 * \pre *info ���A�N�Z�X�\
 *
 * \post *info�̋��p��up�Ɍ��ݐݒ肳��Ă���l������B
 * \post �ݒ肳��Ă��Ȃ��ꍇ�ɂ�info->flag�ɂĎw�肳�ꂽ�t���O�����Z�b�g�����B
 */
extern EXPORT int di_get_ujobinfo( int job_id, di_ujob_info_t *info );

/**
 * \brief �r�b�g�X�C�b�`�̒l���擾����B
 *
 * \param no  �r�b�g�X�C�b�`�̔ԍ�
 * \param val �r�b�g�X�C�b�`�̒l
 *
 * \retval 0     ����I��
 * \retval 0�ȊO �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *val ���A�N�Z�X�\
 *
 * \post no�Ԗڂ̃r�b�g�X�C�b�`�̒l�� *val �Ɠ������Ȃ�B
 */
extern EXPORT int di_get_bitswinfo( int no, int *val );

/**
 * �e��f�B�X�N�����擾����B
 *
 * \param type �f�B�X�N�̎��
 *  <table>
 *   <tr>
 *    <td><center>�l</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>DI_HDD_DOWNLOAD</td>
 *    <td>�t�@�C���_�E�����[�h�p�n�[�h�f�B�X�N</td>
 *   </tr>
 *   <tr>
 *    <td>DI_HDD_SPOOL</td>
 *    <td>�X�v�[���p�n�[�h�f�B�X�N</td>
 *   </tr>
 *   <tr>
 *    <td>DI_RAM_DOWNLOAD</td>
 *    <td>�t�@�C���_�E�����[�h�pRAM�f�B�X�N</td>
 *   </tr>
 *   <tr>
 *    <td>DI_RAM_SPOOL</td>
 *    <td>�X�v�[���pRAM�f�B�X�N</td>
 *   </tr>
 *  </table>
 * \param info �f�B�X�N�̏��
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 type�̃f�B�X�N�����ڂ���Ă��Ȃ�
 * \retval -3 ��t���ہi�Ăяo���̓�d�������������ꍇ�j
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre type �������̐����ɂ���l�̂����ꂩ
 * \pre *val ���A�N�Z�X�\
 *
 * \post type �Ŏw�肳�ꂽ�f�B�X�N���l�� *info �Ɠ������Ȃ�B
 */
extern EXPORT int di_get_diskinfo( int type, di_diskinfo_t *info );

/**
 * \brief �X�g���[�W�f�o�C�X�փt�@�C����ۑ�����B
 *
 * \param type �X�g���[�W�̎��
 *  <table>
 *   <tr>
 *    <td><center>�l</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>DI_STORAGE_NVRAM</td>
 *    <td>NVRAM</td>
 *   </tr>
 *  </table>
 * \param fname �S�����̃t�@�C����
 * \param data  �������ރf�[�^�z��̐擪�A�h���X
 * \param size  data�̔z��̒���
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 �e�ʕs���ɂ�鎸�s
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre type �������̐����ɂ���l�̂����ꂩ
 * \pre *fname �Ŏw�肷��t�@�C�������S����
 * \pre data[0]�`data[size-1] �܂ł��A�N�Z�X�\
 *
 * \post �X�g���[�W�� fname �Ƃ����t�@�C���� data �̓��e�� size ������
 *���܂��B
 */
extern EXPORT int di_write_storage( int type, char *fname,
									unsigned char *data, long size );

/**
 * \brief �X�g���[�W�f�o�C�X�ɏ������܂�Ă���t�@�C������f�[�^��ǂ�
 *���ށB
 *
 * \param type    �X�g���[�W�̎��(���e�� di_write_storage() �Ɠ���)
 * \param fname   �S�����̃t�@�C����
 * \param data    �ǂݍ��񂾃f�[�^���i�[����z��̐擪�A�h���X
 * \param size    data�̔z��̒���
 * \param data_size ���ۂɓǂ񂾃f�[�^�̃T�C�Y
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 fname �Ƃ����t�@�C�������݂��Ȃ�
 * \retval -3 data[size]���傫���t�@�C���������̂ōŌ�܂œǂݍ��߂�
 *�������B���̏ꍇ�ł�size��������data[]�ɓǂݍ��܂�A*data_size�ɃR�s
 *�[�����f�[�^�̃o�C�g��(=size)���Ԃ�B
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre type �������̐����ɂ���l�̂����ꂩ
 * \pre *fname �Ŏw�肷��t�@�C�������S����
 * \pre data[0]�`data[size-1] �܂ł��A�N�Z�X�\
 * \pre *data_size ���A�N�Z�X�\
 *
 * \post �X�g���[�W�ɂ��� fname �Ƃ����t�@�C������ size ���̃f�[�^��
 *data�ɓǂݍ��܂��B
 */
extern EXPORT int di_read_storage( int type, char *fname, unsigned char *data,
								   long size, long *data_size );

/**
 * \brief �X�g���[�W�f�o�C�X�ɏ������܂�Ă���t�@�C�����폜����B
 *
 * \param type  �X�g���[�W�̎��(���e�� di_write_storage() �Ɠ���)
 * \param fname �S�����̃t�@�C����
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre type �������̐����ɂ���l�̂����ꂩ
 * \pre *fname �Ŏw�肷��t�@�C�������S����
 *
 * \post �X�g���[�W�� fname �Ƃ����t�@�C�������݂��Ȃ��B
 */
extern EXPORT int di_delete_storage( int type, char *fname );

/**
 * \brief �����ɍ��v����w��p����v������
 *
 * \param plotid  �v���b�^ID
 * \param psize   �p���T�C�YID
 * \param nodir   �p������
 *  <table>
 *   <tr>
 *    <td><center>�l</center></td><td><center>���e</center></td>
 *   </tr>
 *   <tr>
 *    <td>0</td>
 *    <td>�p���T�C�Y�Ŏw�肵�������̂݁B</td>
 *   </tr>
 *   <tr>
 *    <td>1</td>
 *    <td>�p���T�C�Y���قȂ�����ł��n�j�B</td>
 *   </tr>
 *  </table>
 * \param ptype   ����
 * \param trayid  �g���CID
 * \param req     �v������
 *
 * \retval  4 �T�u�y�[�p�[�T�C�Y���L���̂Ƃ��A�v���p���T�C�Y�Ɨގ�����
 *�T�C�Y�̗p�����o������
 * \retval  3 �G���[��ʂɂ����郆�[�U�[�̑���ɂ��A����������I����
 *�ꂽ
 * \retval  2 �G���[��ʂɂ����郆�[�U�[�̑���ɂ��A�W���u�L�����Z��
 *���I�����ꂽ
 * \retval  1 �G���[�X�L�b�v����������
 * \retval  0 �����Ɉ�v����p�����o������
 * \retval -1 �G���[
 * \retval -2 �r�W�[�i�I�[�v���ς݃y�[�W�̈�����I�����Ă��Ȃ��j
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *req ���A�N�Z�X�\
 *
 * \post �v�����ʂ� *req �Ɋi�[�����
 */
extern EXPORT int di_request_paper(int plotid, int psize, int nodir, int ptype,
								   int trayid, di_res_reqpaper_t *req);

/**
 * \brief ���ϐ��̃f�t�H���g�l���擾����B
 *
 * \param table_name  ���ϐ��e�[�u����
 * \param id          ���ϐ�ID
 * \param val         ����ꂽ���ϐ��̒l
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 table_name�����݂��Ȃ�
 * \retval -3 �w�肵�����ϐ����Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name �Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name �ɑ��݂���B
 * \pre *val ���A�N�Z�X�\
 *
 * \post *val �����ϐ� id �̃f�t�H���g�l�Ɠ������Ȃ�B
 */
extern EXPORT int di_get_defenvvalue(char *table_name, long id, long *val);

/**
 * \brief ���ϐ��̃f�t�H���g�l�̃Z�b�g
 *
 * \param table_name  ���ϐ��e�[�u����
 * \param id          ���ϐ�ID
 * \param  val        �Z�b�g������ϐ��̒l
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 table_name�����݂��Ȃ�
 * \retval -3 �w�肵�����ϐ����Ȃ�
 * \retval -4 ���[�h�I�����[�̊��ϐ�
 * \retval -5 val���ݒ�s�\�Ȓl
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name �Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name �ɑ��݂���B
 * \pre ���ϐ� id ���Atable_name �ɐݒ�\�ł���B
 *
 * \post val �����ϐ� id �̃f�t�H���g�l�Ɠ������Ȃ�B
 */
extern EXPORT int di_set_defenvvalue(char *table_name, long id, long val);

/**
 * \brief ���ϐ����̎擾
 *
 * \param table_name  ���ϐ��e�[�u����
 * \param id          ���ϐ�ID
 * \param info        ���ϐ��̏��
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 table_name�����݂��Ȃ�
 * \retval -3 �w�肵�����ϐ����Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name �Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name �ɑ��݂���B
 * \pre *table_name ���A�N�Z�X�\
 * \pre *info ���A�N�Z�X�\
 *
 * \post *info �����ϐ����Ɠ������Ȃ�B
 */
extern EXPORT int di_get_envvalinfo(char *table_name, long id,
									di_envinfo_t *info);

/**
 * \brief ���ϐ��̒l���X�g�̎擾
 *
 * \param table_name  ���ϐ��e�[�u����
 * \param id          ���ϐ�ID
 * \param start       �擾���������ϐ��̒l�̃��X�g���̐擪�ԍ�
 * \param end         �擾���������ϐ��̒l�̃��X�g���̏I���ԍ�
 * \param list        �l�̃��X�g������z��̃|�C���^
 * \param list_num    list�ɓ��͂����L���ȕϐ����X�g�̍��ڐ�
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 table_name�����݂��Ȃ�
 * \retval -3 �w�肵�����ϐ����Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name �Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name �ɑ��݂���B
 * \pre *table_name ���A�N�Z�X�\
 * \pre list[0]�`list[end-start]  ���A�N�Z�X�\
 * \pre *list_num ���A�N�Z�X�\
 *
 * \post list[0]�`list[list_num-1] �����ϐ�id�̒l�̃��X�g�Ɠ������Ȃ�B
 */
extern EXPORT int di_get_envvallist(char *table_name, long id,
									unsigned long start, unsigned long end,
									long *list, long *list_num);

/**
 * \brief �p�l���\��������擾����B
 *
 * \param language   �p�l���\������
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *table_name ���A�N�Z�X�\
 *
 * \post *language ���p�l���\������Ɠ������Ȃ�B
 */
extern EXPORT int di_get_panellang(unsigned char *language);

/**
 * \brief ���ڂ���Ă���t���b�V���������̊e������擾����B
 *
 * \param id         �t���b�V���������̔ԍ�
 * \param info       id�Ԗڂ̃t���b�V���������̏��
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *info ���A�N�Z�X�\
 * \pre id �� 1�`n �͈͓̔��Bn �� di_get_flashmemnum() �Ŏ擾�����
 *�t���b�V���������̐��B
 *
 * \post *info �� id �Ԗڂ̃t���b�V�����������Ɠ������Ȃ�B
 */
extern EXPORT int di_get_flashmeminfo(int id, di_flashmem_info_t *info);

/**
 * \brief ���ڂ���Ă���t���b�V���������̐����擾����B
 *
 * \param num     �t���b�V���������̐�
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *num ���A�N�Z�X�\
 *
 * \post *num �����ڂ���Ă���t���b�V���������̐��Ɠ������Ȃ�B
 */
extern EXPORT int di_get_flashmemnum(long *num);

/**
 * \brief �ʎ��\�ȍő�p���T�C�Y���擾����B
 *
 * \param x     �呖������(�P�� : 1/10mm)
 * \param y     ����������(�P�� : 1/10mm)
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *x ���A�N�Z�X�\
 * \pre *y ���A�N�Z�X�\
 *
 * \post *x ���呖�������̒ʎ��\�ő�T�C�Y�Ɠ������Ȃ�B
 * \post *y �������������̒ʎ��\�ő�T�C�Y�Ɠ������Ȃ�B
 */
extern EXPORT int di_get_maxpapersize(long *x, long *y);

/**
 * \brief �G���W���ō쑜�\�ȍő�T�C�Y���擾����B
 *
 * \param x     �呖������(�P�� : 1/10mm)
 * \param y     ����������(�P�� : 1/10mm)
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *x ���A�N�Z�X�\
 * \pre *y ���A�N�Z�X�\
 *
 * \post *x ���呖�������̍쑜�\�ő�T�C�Y�Ɠ������Ȃ�B
 * \post *y �������������̍쑜�\�ő�T�C�Y�Ɠ������Ȃ�B
 */
extern EXPORT int di_get_maximagesize(long *x, long *y);

/**
 * \brief ���j���[�A�C�e�����̎擾
 *
 * \param panel_id  ���j���[�A�C�e���̃p�l��ID
 * \param itemtype  ���j���[�A�C�e���̃A�C�e���^�C�v
 * \param menutype  ���j���[�A�C�e���̃��j���[�^�C�v
 * \param buf       ���j���[�A�C�e���̏����i�[����o�b�t�@
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre buf[0]�`buf[31] ���A�N�Z�X�\
 *
 * \post buf �����j���[�A�C�e���̏��Ɠ������Ȃ�B
 */
extern EXPORT int di_get_menuitem(unsigned long panel_id,
								  unsigned long itemtype,
								  unsigned long menutype,
								  unsigned char *buf);

/**
 * \brief �w�肷��f�o�C�X���當������擾����B
 *
 * \param type    �f�o�C�X���
 * \param device  �f�o�C�X�̏ڍ�
 * \param id      ������ID
 * \param buf     ��������i�[����o�b�t�@
 * \param size    �I�[�������܂񂾕�����̒���
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre buf[0]�`buf[size-1] ���A�N�Z�X�\
 *
 * \post buf ���w�肳�ꂽ�f�o�C�X�̕�����Ɠ������Ȃ�B
 */
extern EXPORT int di_get_string(int type, long device, unsigned long id,
								unsigned char *buf, unsigned long size);
								
/**
 * \brief �t�H���g�̏����擾����B
 *
 * �t�H���g�̊�{���� di_getinfo() �Ŏ擾�ł��邪�A�ڍ׏����擾��
 *��ꍇ�A�������� di_getinfo() �Ŏ擾�ł���t�H���g�ȊO�̎�ނ̃t�H��
 *�g�����擾����ꍇ�ɖ{�֐����g�p����B
 *
 * \param type  �t�H���g�̎��
 * \param info  �t�H���g�̏��
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *info ���A�N�Z�X�\
 *
 * \post *info �� type �̃t�H���g���Ɠ������Ȃ�B
 */
extern EXPORT int di_get_fontinfo(int type, di_fontinfo_t *info);

/**
 * \brief ����PDL�����擾����
 *
 * \param pdl_id  PDL ID
 * \param info    PDL���
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 �w��PDL�����ڂ���Ă��Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre pdl_id ���L��ID
 *
 * \post *info �� pdl_id �� PDL ���Ɠ������Ȃ�B
 */
extern EXPORT int di_get_pdlinfo(int pdl_id, di_pdlinfo_t *info);

/**
 * \brief ���[�U�[�W���u�ϐ��̒l���擾����B
 *
 * \param ujobparam ���[�U�[�W���u���
 *
 * \retval  0 ����I��
 * \retval -1 �W���uID������
 * \retval -2 �T�|�[�g���Ă��Ȃ��p�����[�^���w�肵��
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre *ujobparam ���A�N�Z�X�\�B
 *
 * \post *ujobparam �����[�U�[�W���u�ϐ��̒l�Ɠ������Ȃ�B
 */
extern EXPORT int di_get_ujobparamvar( ujobparam_var_t *ujobparam );

/**
 * \brief conversion of the paper output bin number to id 
 *
 * \parameter bin_index: the number of the paper output bin
 *  
 * \retval >=0: id of paper output bin
 * \retval -1 : failure
 *
 * \pre di_init() has been called
 *
 * \post return the id of the paper output bin
 */
extern EXPORT int di_convert_binid(int bin_index);

extern EXPORT int di_open_downloadinfo(int ope, int mediatype, char *pdlname, char *filename,
					unsigned long *filesize, unsigned long *hfctrl);
extern EXPORT int di_close_downloadinfo(unsigned long hfctrl);
extern EXPORT int di_read_downloadinfo(unsigned long hfctrl, void *pbuf, long readsize, long *nsize);
extern EXPORT int di_write_downloadinfo(unsigned long hfctrl, void *pbuf, long writesize, long *nsize);
extern EXPORT int di_delete_downloadinfo(int ope, int mediatype, char *pdlname, char *dirname);
extern EXPORT void di_check_interrupt();

extern EXPORT void di_set_ujobid(int ujobid);


/**
 * \brief �w�肳�ꂽ�p�����̏������ɁA�K�v�ȉ摜��]�����̏����擾
 *����B
 *
 * \param plotid �v���b�^ID
 * \param info   �摜��]�����̔�����s�����߂̏��
 * \param result �摜��]�����̔��茋��
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 * \retval -2 �֐����T�|�[�g����Ă��Ȃ�
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre plotid ���L�� ID�B
 * \pre *info ���A�N�Z�X�\�B
 * \pre *result ���A�N�Z�X�\�B
 *
 * \post *result ���摜��]�����̏��Ɠ������Ȃ�B
 */
extern EXPORT int di_get_imgrotinfo( int plotid, di_rotenvinfo_t *info, di_imgrotinfo_t *result );

/**
 * \brief �K���}�Čv�Z���s���B
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init() ���R�[������Ă���B
 *
 * \post �V�X�e�����̃K���}���Čv�Z�����B
 */
extern EXPORT int di_update_gamma();

/**
 * \brief ���ϐ��̒l(�o�C�g��)���擾����B
 *
 * \param table_name ���ϐ��e�[�u����
 * \param id         ���ϐ�ID
 * \param val        ����ꂽ���ϐ��̒l
 * \param in_size    �o�C�g��val�̃o�C�g���B���ϐ���������̏ꍇ�ɂ́ANULL�^�[�~�l�[�g�����邾���̐����w�肷�邱�ƁB
 * \param out_size   �o�C�g��̗L���ȃo�C�g���B���ϐ���������̏ꍇ�ɂ́ANULL�^�[�~�l�[�g���܂ޒ�����Ԃ��B
 *
 * \retval  1 ����I���i���ϐ��������I�Ɏw�肳��Ă���j
 * \retval  0 ����I���i���ϐ��������I�Ɏw�肳��ĂȂ����߁A�f�t�H��
 *�g�l�Z�b�g)
 * \retval -1 �G���[�idi_init()���R�[������Ă��Ȃ��A�֐����T�|�[�g���Ă��Ȃ��j
 * \retval -2 �G���[�itable_name�����݂��Ȃ��j
 * \retval -3 �G���[�i�w�肵�����ϐ����Ȃ��j
 * \retval -4 �G���[�iin_size������������j
 *
 * \pre di_init() ���R�[������Ă���B
 * \pre table_name�Ƃ����e�[�u�������݂���B
 * \pre ���ϐ� id ���Atable_name�ɑ��݂���B
 * \pre val[0]-val[in_size-1]���A�N�Z�X�\�B
 * \pre *out_size���A�N�Z�X�\�B
 *
 * \post val[0]-val[out_size-1]�Ɏw�肵�����ϐ��̒l���i�[�����B
 */
extern EXPORT int di_get_envdata( char *table_name, long id, void *val, unsigned long in_size, unsigned long *out_size );

/**
 * \brief �p�l���ɃG�~�����[�V��������\������B
 *
 * \retval  0 ����I��
 * \retval -1 �G���[
 *
 * \pre di_init()���R�[������Ă���
 * \pre str��NULL�łȂ�
 * \pre str��NULL�^�[�~�l�[�g���܂߂āA8�o�C�g�ȓ��ł���
 *
 * \post �p�l����str�Ŏw�肵���G�~�����[�V���������\�������(GPS����̂�)
 */
extern EXPORT int di_disp_setemulation( char *str );

extern EXPORT int di_disp_setcurrentintray( unsigned short tray_id );
extern EXPORT int di_disp_setcurrentintray2( unsigned short tray_id,
						unsigned short cut_orient_id );
extern EXPORT int di_disp_setdialogueid( char *filename, unsigned short str1_id, unsigned char str1_size,
 unsigned short str2_id, unsigned char str2_size, unsigned char time );
extern EXPORT int di_disp_clrdialogue( void );
extern EXPORT int di_disp_setprognum( unsigned short prog_id );
extern EXPORT int di_disp_menucheckfinish( void );
extern EXPORT int di_disp_addmenuitem( unsigned char *buf );

/* �v���O�����o�^ */
extern EXPORT struct di_progtable * di_get_programinfo ( unsigned int prog_no );
extern EXPORT int di_register_program( int prog_no, di_progtable_t *psw );
extern EXPORT int di_delete_program(int prog_no );
extern EXPORT int di_get_programnum( void );
extern EXPORT int di_write_program( char *name, int fileno, char *data, int data_size );
extern EXPORT int di_read_program( char *name, int fileno, char *data, int data_size );
extern EXPORT int di_finish_program( void );
extern EXPORT int di_write_storage_auth( int type, char *fname, unsigned char *data, long size, unsigned long auth );
extern EXPORT int di_register_program_auth( int prog_no, di_progtable_t *psw, unsigned long auth );
extern EXPORT int di_delete_program_auth( int prog_no, unsigned long auth );
extern EXPORT int di_write_program_auth( char *name, int fileno, char *data, int data_size, unsigned long auth );

/* USE_SET_CATEGORY */
extern EXPORT int di_set_category( char *category );

/* USE_CHANGE_EML */
extern EXPORT int di_change_eml( char *eml_name, int uswitch );

extern EXPORT int di_query_duplex( di_chkduplexok_t *pchkduplex );
extern EXPORT int di_set_ethertalkinfo_auth( di_ethertalk_info_t *info, unsigned long auth );

extern EXPORT int di_open_envtable( char *table_name );
extern EXPORT int di_close_envtable( int penv );
extern EXPORT int di_get_envvalue_direct( int penv, long id, long *val );
extern EXPORT int di_get_defenvvalue_direct( int penv, long id, long *val );
extern EXPORT int di_get_envdata_direct( int penv, long id, void *val,
							unsigned long in_size, unsigned long *out_size );
extern EXPORT int di_request_tray( int plotid, int psize, int nodir, int ptype,
									int trayid, di_trayrequest_t *trayreq, 
									int *result );
extern EXPORT int di_get_micrinfo( long *micrinfo );
extern EXPORT int di_get_printcondition( di_printcondition_t *cond,
										 di_media_printcondition_t *media );
extern EXPORT int di_get_printconditionShm( di_printconditionShm_t *condShm,
											int *status );
extern EXPORT int di_get_trayinfo2( di_trayinfo_t *trayinfo );
extern EXPORT int di_get_ucpdata(di_ucp_info_t ucpinfo,
								di_ucp_data_t *ucpdata,
								int *result);
extern EXPORT int di_get_ucpparam(di_ucp_param_t *ucpparam, int *result);
extern EXPORT int di_set_printinfo(int plotid, di_printinfo_t *prtinfo);

extern EXPORT int di_zinit( di_initinfo_t *initinfo, di_setinfo_t *setinfo );
extern EXPORT int di_zopen_host(void);
extern EXPORT int di_zclose_host(void);
extern EXPORT int di_ztrans_process(void);
extern EXPORT int di_zselect_idevice(int mode, void *opt);
extern EXPORT int di_zinit_memory(unsigned char *mem_zlib_addr);

/** \} */ /* end of group(Interface) */

#else	/* DEFINE_DI_TYPE */

typedef int (*DI_PROC_INIT)( di_initinfo_t *, di_setinfo * );
typedef int (*DI_PROC_CLEAR)( di_devinfo_t *, DI_CALLBACK_MEMFREE );
typedef void (*DI_PROC_TERM)();
typedef int (*DI_PROC_GETINFO)( di_devinfo_t *, DI_CALLBACK_MEMALLOC, char * );
typedef int (*DI_PROC_GET_REQUEST)();
typedef int (*DI_PROC_GET_TRAYINFO)( di_trayinfo_t * );
typedef int (*DI_PROC_GET_ENVVALUE)( char *, long, long * );
typedef int (*DI_PROC_SET_ENVVALUE)( char *, long, long );
typedef int (*DI_PROC_SET_CALLBACKFUNC)( int, DI_CALLBACK_FUNC );
typedef char* (*DI_PROC_MEMORY_ALLOC)( unsigned long );
typedef void (*DI_PROC_MEMORY_FREE)( char * );
typedef void (*DI_PROC_OPEN_HOST)();
typedef void (*DI_PROC_CLOSE_HOST)();
typedef int (*DI_PROC_IGETCH)( unsigned char *);
typedef int (*DI_PROC_IGETS)( unsigned char *, long );
typedef int (*DI_PROC_IPEEKCH)( unsigned char *);
typedef int (*DI_PROC_IPEEKS)( unsigned char *, long );
typedef void (*DI_PROC_RESET_IPEEK)();
typedef int (*DI_PROC_ISEEK)( long );
typedef int (*DI_PROC_SELECT_IDEVICE)( int, void * );
typedef int (*DI_PROC_TRANS_PROCESS)();
typedef int (*DI_PROC_NOTIFY_MSG)(int, long);
typedef int (*DI_PROC_QUERY_SUPPORTPAPER)( int );
typedef int (*DI_PROC_GET_OPTSTR)( char ** );
typedef int (*DI_PROC_GET_PAPERSIZE)( unsigned char, unsigned int, unsigned int );
typedef int (*DI_PROC_OPEN_HOSTS)();
typedef int (*DI_PROC_CLOSE_HOSTS)();
typedef int (*DI_PROC_SOUTPUTC)( unsigned char );
typedef int (*DI_PROC_SOUTPUT)( unsigned char *, long, int );
typedef int (*DI_PROC_SOUTFLUSH)();
typedef int (*DI_PROC_SINAVAIL)( long * );
typedef int (*DI_PROC_GET_DEFTRAY)( int * );
typedef int (*DI_PROC_GET_DEFBIN)( int * );
typedef int (*DI_PROC_GET_BININFO)( di_bininfo_t * );
typedef int (*DI_PROC_GET_STATUS)( di_status_t * );
typedef int (*DI_PROC_GET_TOTALCOUNTER)( long * );
typedef int (*DI_PROC_GET_ETHERTALKINFO)( di_ehtertalk_info_t * );
typedef int (*DI_PROC_SET_ETHERTALKINFO)( di_ehtertalk_info_t * );
typedef int (*DI_PROC_SET_UJOBINFO)( int, di_ujob_info_t * );
typedef int (*DI_PROC_GET_UJOBINFO)( int, di_ujob_info_t * );
typedef int (*DI_PROC_GET_BITSWINFO)( int, int * );
typedef int (*DI_PROC_GET_DISKINFO)( int, di_diskinfo_t * );
typedef int (*DI_PROC_WRITE_STORAGE)( int, char *, unsigned char *, long );
typedef int (*DI_PROC_READ_STORAGE)( int, char *, unsigned char *, long, long * );
typedef int (*DI_PROC_DELETE_STORAGE)( int, char * );
typedef int (*DI_PROC_REQUEST_PAPER)( int, int, int, int, int, di_res_reqpaper_t * );
typedef int (*DI_PROC_GET_DEFENVVALUE)( char *, long, long * );
typedef int (*DI_PROC_SET_DEFENVVALUE)( char *, long, long );
typedef int (*DI_PROC_GET_ENVVALINFO)( char *, long, di_envinfo_t *o );
typedef int (*DI_PROC_GET_ENVVALLIST)( char *, long, unsigned long, unsigned long, long *, long * );
typedef int (*DI_PROC_GET_PANELLANG)( unsigned char * );
typedef int (*DI_PROC_GET_FLASHMEMINFO)( int, di_flashmem_info_t * );
typedef int (*DI_PROC_GET_FLASHMEMNUM)( long * );
typedef int (*DI_PROC_GET_MAXPAPERSIZE)( long *, long * );
typedef int (*DI_PROC_GET_MAXIMAGESIZE)( long *, long * );
typedef int (*DI_PROC_GET_MENUITEM)( unsigned long, unsigned long, unsigned long, unsigned char * );
typedef int (*DI_PROC_GET_STRING)( int, long, unsigned long, unsigned char, unsigned long * );
typedef int (*DI_PROC_GET_FONTINFO)( int, di_fontinfo_t * );
typedef int (*DI_PROC_GET_PDLINFO)( int, di_pdlinfo_t * );
typedef int (*DI_PROC_GET_UJOBPARAMVAR)( ujobparam_var_t *);
typedef int (*DI_PROC_OPEN_DOWNLOADINFO)(int, int, char *, char *, unsigned long *, unsigned long *);
typedef int (*DI_PROC_CLOSE_DOWNLOADINFO)(unsigned long);
typedef int (*DI_PROC_READ_DOWNLOADINFO)(unsigned long, void *, long, long *);
typedef int (*DI_PROC_WRITE_DOWNLOADINFO)(unsigned long, void *, long, long *); 
typedef int (*DI_PROC_DELETE_DOWNLOADINFO)(int, int, char *, char *);
typedef int (*DI_PROC_GET_IMGROTINFO)( int , di_rotenvinfo_t *, di_imgrotinfo_t * );
typedef int (*DI_PROC_UPDATE_GAMMA)();
typedef int (*DI_PROC_GET_ENVDATA)( char *, long, void *, unsigned long, unsigned long * );
typedef int (*DI_PROC_DISP_SETEMULATION)( char * );
typedef void (*DI_PROC_CHECK_INTERRUPT)();
typedef int (*DI_PROC_DISP_SETCURRENTINTRAY)( unsigned short );
typedef int (*DI_PROC_DISP_SETDIALOGUEID)( char *, unsigned short, unsigned char, unsigned short, unsigned char, unsigned char );
typedef int (*DI_PROC_DISP_CLRDIALOGUE)();
typedef int (*DI_PROC_DISP_SETPROGNUM)( unsigned short );
typedef int (*DI_PROC_DISP_MENUCHECKFINISH)();
typedef int (*DI_PROC_DISP_ADDMENUITEM)( unsigned char * );
typedef int (*DI_PROC_CONVERT_BINID)( int );

typedef struct di_progtable* (*DI_GET_PROGRAMINFO)( unsigned int );
typedef int (*DI_REGISTER_PROGMRAM)( int, di_progtable_t * );
typedef int (*DI_DELETE_PROGRAM)( int );
typedef int (*DI_GET_PROGRAMNUM)( void );
typedef int (*DI_WRITE_PROGRAM)( char *, int, char *, int );
typedef int (*DI_READ_PROGRAM)( char *, int, char *, int );
typedef int (*DI_FINISH_PROGRAM)( void );
typedef int (*DI_WRITE_STORAGE_AUTH)( int, char *, unsigned char *, long, unsigned long );
typedef int (*DI_REGISTER_PROGRAM_AUTH)( int, di_progtable_t *, unsigned long );
typedef int (*DI_DELETE_PROGRAM_AUTH)( int, unsigned long );
typedef int (*DI_WRITE_PROGRAM_AUTH)( char *, int, char *, int, unsigned long );

typedef int (*DI_SET_CATEGORY)( char * );

typedef int (*DI_CHANGE_EML)( char *, int );

typedef int (*DI_QUERY_DUPLEX)( di_chkduplexok_t * );
typedef int (*DI_SET_ETHERTALKINFO_AUTH)( di_ehtertalk_info_t *, unsigned long );

typedef int (*DI_OPEN_ENVTABLE)( char * );
typedef int (*DI_CLOSE_ENVTABLE)( int );
typedef int (*DI_GET_ENVVALUE_DIRECT)( int, long, long * );
typedef int (*DI_GET_DEFENVVALUE_DIRECT)( int, long, long * );
typedef int (*DI_REQUEST_TRAY)( int, int, int, int, int, di_trayrequest_t *, int *);
typedef int (*DI_GET_MICRINFO)( long * );
typedef int (*DI_GET_PRINTCONDITION)( di_printcondition_t *,
									  di_media_printcondition_t * );
typedef int (*DI_GET_PRINTCONDITIONSHM)( di_printconditionShm_t *, int * );
typedef int (*DI_GET_TRAYINFO2)( di_trayinfo_t * );
typedef int (*DI_GET_UCPDATA)(di_ucp_info_t ucpinfo,
								di_ucp_data_t *ucpdata
								int *result);
typedef int (*DI_GET_UCPPARAM)(di_ucp_param_t *ucpparam,
											int *result);
typedef int (*DI_SET_PRINTINFO)(int, di_printinfo_t *);

typedef int (*DI_ZINIT)( di_initinfo_t *, di_setinfo_t * );
typedef int (*DI_ZOPEN_HOST)( void );
typedef int (*DI_ZCLOSE_HOST)( void );
typedef int (*DI_ZTRANS_PROCESS)( void );
typedef int (*DI_ZSELECT_IDEVICE)( int, void * );
typedef int (*DI_ZINIT_MEMORY)( unsigned char * );

#endif	/* DEFINE_DI_TYPE */

#endif	/* __DEVICE_H__ */

/*
 *
 *	COPYRIGHT (C) 2001-2007 RICOH COMPANY LTD.
 *	All rights reserved.
 *
 */
