/******************************************************
 * $Id$
 *
 * Copyright (C) 2000 Ricoh Company, Ltd.  All Rights Reserved.
 *
 *   FILE NAME       : bitsw.h
 *   VERSION         : $Revision$
 *   AUTHOR          : Satoshi MIYAZAKI
 *-----------------------------------------------------
 *       HISTORY
 *	 miyazaki - 19 Apr 2000: Created.
 *	 $Log$
 *	
 ******************************************************/
#ifndef _GPS_BITSW_H_
#define	_GPS_BITSW_H_

#define	BIT_SW_001	0
#define	BIT_SW_002	1
#define	BIT_SW_003	2
#define	BIT_SW_004	3
#define	BIT_SW_005	4
#define	BIT_SW_006	5
#define	BIT_SW_007	6
#define	BIT_SW_008	7
#define	BIT_SW_009	8
#define	BIT_SW_010	9
#define	BIT_SW_011	10
#define	BIT_SW_012	11
#define	BIT_SW_013	12
#define	BIT_SW_014	13
#define	BIT_SW_015	14
#define	BIT_SW_016	15
#define BIT_SW_NUM	16

/*
 * NAD, Russian ���̃v�����^�̃r�b�g�X�C�b�`�Ƃ̓r�b�g�̏��Ԃ��t�Ȃ̂�
 * ���ӂ��K�v�B
 * �݌v�҂ɂ͂�����̕��������I�ɃR�[�f�B���O�ł���悤�ɂȂ��Ă���B
 * �ԍ��̒�`���]���̂P�`�f�ł͂Ȃ��A�r�o�ԍ��ɑ������O�O�P�`�O�P�U
 * �ɕύX����
 *
 * �Ⴆ�΁u�r�b�g�X�C�b�`�R�|�V�v�Ǝd�l����}�j���A���ɏ����Ă���ꍇ�A
 * ���̒l������ɂ�
 *
 *  u_char val;
 *  val = (u_char)gpsGetBitSw(BIT_SW_003);
 *  if (val & (1<<7))    // BitSW 3-7 ���^�Ȃ�
 *  {
 *    .
 *    .
 *    .
 *  }
 *
 * �̗l�ɒP���ɂV�r�b�g�V�t�g�Œ��ׂ鎖���o����B
 */

#endif /* !_GPS_BITSW_H_ */
/*
 * Copyright (c) 2000 Ricoh Company, Ltd.  All Rights Reserved.
 */

