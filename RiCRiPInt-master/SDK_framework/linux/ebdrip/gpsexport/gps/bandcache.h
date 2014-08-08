/************************************************************************
 * �t�@�C����   : bandcache.h
 * �@�\�T�v     : GPS - ����y�[�W�Ǘ� - �o���h�������[�L���b�V���@�\
 * �����       : Copyright (C) RICOH CO., LTD. 2000.
 * �݌v��       : T.Kitazawa
 * �ύX����     : 2000-08-26 �J�n
 *                2000-08-26 Version 1.44 std / 2.08 kipw
 ************************************************************************/
/*      */
#ifndef _BANDCACHE_H
#define _BANDCACHE_H
#ifdef  __cplusplus
extern "C" {
#endif  /* !__cplusplus */
/*      */
/************************************************************************
 *      Public Function
 ************************************************************************/
/*      */
extern int      gpsFrameOpenBandCache(  gwmsg_client_t *client, int frameid, int bandid, int planeid,                       gwmsg_GpsPage_FrameGetBand_Res_t   *pFGBR );
extern int      gpsFrameCloseBandCache( gwmsg_client_t *client, int frameid, int bandid, int planeid, int drawn, int flush, gwmsg_GpsPage_FrameFlushBand_Res_t *pFFBR );
extern int      gpsFrameFlushBandCache( gwmsg_client_t *client,                                                             gwmsg_GpsPage_FrameFlushBand_Res_t *pFFBR );
/*      */
#ifdef  __cplusplus
}
#endif  /* !__cplusplus */
#endif  /* _BANDCACHE_H */
/* EOF  */
