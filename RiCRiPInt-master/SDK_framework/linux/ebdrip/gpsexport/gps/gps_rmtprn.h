/************************************************************************
 * �t�@�C����   : gps_rmtprn.h
 * �@�\�T�v     : GPS - �����[�g����Ǘ�
 * �����       : Copyright (C) RICOH CO., LTD. 1999,2000
 * �݌v��       : Masaki Tsusaka
 * �ύX����     : 2000.04.17 1st created.
 ************************************************************************/

#ifndef _GPS_RMTPRN_H_INCLUDED_
#define _GPS_RMTPRN_H_INCLUDED_

/*  gpsRmtprnTxStart() �̖߂�l */
#define  GPS_RMTPRN_TS_SUCCESS		(0)	/* ���� */
#define  GPS_RMTPRN_TS_ERROR		(-1)	/* �\��O�̃G���[ */
#define  GPS_RMTPRN_TS_ERROR_RTY	(-2)	/* �������󂯕t�����Ȃ��̂ŁA�����wait�ナ�g���C */

/*  �����[�g�v�����g���M�p�����[�^�\���� */
typedef struct gps_rmtprn_param {
    char	telno[256];	/* �d�b�ԍ� (������`��) */
    char	line[32];	/* ������ (������`��) */
    char	ver[16];	/* RPCS�o�[�W���� (������`��) */
    char	limit[16];	/* ���M�f�[�^�̏�� (������`��) */
} gps_rmtprn_param_t;

/*  �����[�g�v�����g���M���� �J�n�v�� */
int	gpsRmtprnTxStart(gwmsg_client_t *client, int ujobid, gps_rmtprn_param_t *rprm);

#endif /* _GPS_RMTPRN_H_INCLUDED_ */
