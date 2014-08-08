#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "gps/gps_client.h"
#include "gps/gwipc.h"
#include "bfd.h"
#include "gw_gps.h"
#include "gps_func.h"
#include "modelinfo.h"
#include "gps_color_mtype.h"
#include "info.h"
#include "pageprint.h"
#include "memory.h"
#include "gps/pageio.h"

#define	GPS_INTERP_RTIFF		6
#define GPS_PRMINFO_SUCCESS     0
#define GPS_PRMINFO_FAILED      1
#define PM_SUCCESS              0
#define GPS_PRMINFO_GET_COLOR_MODEL 6

#define GPS_PENV_NAME_COMMON "COMMON"
#define GPS_PENV_NAME_PCL "PCL"

#define	PENV_HANDLER 	      5
#define	GPS_PENV_ERR_NOTABLE  (-3)
#define	GPS_PENV_ERR_BUSY	  (-2)

#define	GPS_PENV_VAR_ID_COPIES			1
#define	GPS_PENV_VAR_ID_RESOLUTION		5
#define	GPS_FONT_PCL		            2


#define GPS_INTERP_PCL5c            10  
#define BIT_SW_003                   2  
#define BIT_SW_001					 0
#define BIT_SW_004                   3
#define BIT_SW_016					15   
#define SET_DISP                   3
#define	GPS_HDD_TMP		             4 
#define PHOTO_DRAWMODE               0
#define	HIGH_PRINTMODE		         1	
#define GPS_PAPER_NORMAL        (0x01)      
#define   RESET_DISP           5
#define GPS_INTERP_FIN_NORMAL 0 /* Normal end */
#define GPS_PRINT_NORMAL (0) /* Normal printing */


//typedef	unsigned short	gps_color_rid_t;

//static gwmsg_client_t gpsClient;
//static gwmsg_client_t *gps_client = &gpsClient;
//static char *shdm_addr;
gps_color_rid_t rID[4];

static gps_bininfo_t gpsBinInfo;
static gps_trayinfo_t gpsTrayInfo;
static gps_sysinfo_t  sysinfo;
static gps_hddinfo2_t hddinfo;
static gps_paperinfo_t gpsPaperInfo;
static gps_prtstatus2_t prtStatus;
static gps_plotprepareparam_t plotPrepare;
static gps_pageparam_shm_t param;
static gps_pagemode2_t pagemode2;

static gps_pageinfo2_t pageinfo2;
static gps_pagemode_t pagemode;
static gps_pageinfo_t pageinfo;
static gwmsg_GpsPage_FrameCreate_Res_t	pFCR;
static gwmsg_GpsPage_FrameGetBand_Res_t pFGBR;
static gwmsg_GpsPage_FrameFlushBand_Res_t pFFBR;
static int gwmsg_interp_handler(void *cl, gwmsg_t *m)
{
    printf("interp handler\n");
    return 0;
}


int  GPS_Open(gwmsg_client_t *client, gwmsg_handler_t gwmsg_interp_handler, pthread_attr_t attr, void **shdm_addr);
int  GPS_GetPrmInfo(gwmsg_client_t *client, int f_id, int *status, int size, long *maxsize);
char  GPS_PmInit(gwmsg_client_t *client, void(*pfunc1)(), void(*pfunc2)());
int  GPS_GetModelInfo(gwmsg_client_t *client, char dummy, char num,	char	*key, char *category, unsigned char value_len, unsigned char	*value);
int GPS_PenvOpen(gwmsg_client_t *client, char *penv_name, long size);
int	GPS_PenvGetValue( gwmsg_client_t* client, int penv, long gps_var, long *penv_val );
void GPS_PenvClose(gwmsg_client_t *client, int penv);
long GPS_Color_getShrd(gwmsg_client_t *client);
int	GPS_Color_getRID( gwmsg_client_t* client, int modeID, gps_color_rid_t *rID, long *rID_size );
int GPS_Color_getProfile(gwmsg_client_t 	*client, void **addr, long	*num);
int GPS_GetFontInfo(gwmsg_client_t *client, int font, gps_fontinfo_t *fontinfo);
int  GPS_GetBitSw(gwmsg_client_t *, int);
int  GPS_InterpNotifyStart(gwmsg_client_t *, int);
void GPS_InterpNotifyOnline(gwmsg_client_t *);
int  GPS_PenvGetValueList(gwmsg_client_t *, int, long, long, long, long *, long *);
int  GPS_PenvGetDefValue(gwmsg_client_t *, int, long, long *);
int  GPS_BinInfo(gwmsg_client_t *, int , gps_bininfo_t *, long *, int );
int  GPS_TrayInfo(gwmsg_client_t *, int , gps_trayinfo_t *, long *, int); 
void GPS_PmDispSetEmulation(char, char, char, char *);
int GPS_GetSysInfo(gwmsg_client_t *, gps_sysinfo_t *);
caddr_t GPS_WkMalloc(gwmsg_client_t *client, long mallocsize);
int GPS_WkSizeFree(gwmsg_client_t *);
int GPS_ColorgetID2(gwmsg_client_t *, int, int, int, int, unsigned char, unsigned char, int *) ; 
int GPS_gpsGetHddInfo2(gwmsg_client_t *, int, int, gps_hddinfo2_t);

int GPS_GetPdlPrintConditionShm(gwmsg_client_t *, int, int *, unsigned long *);
int GPS_GetPaperInfo(gwmsg_client_t *, int, gps_paperinfo_t *, int);
void GPS_InterpNotifyState(gwmsg_client_t *, int);
gps_hostbuf_p GPS_SinOpen(gwmsg_client_t *, int);
gps_hostbuf_p GPS_SoutOpen(gwmsg_client_t *, int);
int GPS_GetPdlTable(gwmsg_client_t *, long *, int *);
int GPS_GetPrtStatus2(gwmsg_client_t *, gps_prtstatus2_t *, int, int *);
int GPS_PlotPrepare(gwmsg_client_t *, int, gps_plotprepareparam_t *);
int GPS_PlotOpen(gwmsg_client_t *client, int plotOpen_ujobid, int plotOpen_openmode);
int GPS_PlotSetPageParamShm(gwmsg_client_t *client, int	PlotSet_plotid, gps_pageparam_shm_t	*param, int	*PlotSet_result);
int GPS_FrameCreateEx(gwmsg_client_t *client, int framecreate_plotid, const gps_pagemode2_t *pagemode2, const gps_pageinfo2_t *pageinfo2, int	*framecreate_result);
int GPS_FrameCreateInfoRes(gwmsg_client_t *client, int FCinfo_plotid, gps_pagemode_p pagemode, gps_pageinfo_t *pageinfo, int FCinfo_force, gwmsg_GpsPage_FrameCreate_Res_t	*pFCR);
int GPS_FrameGetBandRes(gwmsg_client_t *client, int	FGband_frameid, int FGband_bandid, int FGband_planeid, gwmsg_GpsPage_FrameGetBand_Res_t *pFGBR);
int GPS_FrameFlushBandRes(gwmsg_client_t *client,int FFB_frameid,int FFB_bandid,int	FFB_planeid,int	FFB_drawn,int FFB_flush,gwmsg_GpsPage_FrameFlushBand_Res_t	*pFFBR);
int GPS_FramePrintInfo(gwmsg_client_t *client, int FP_frameid, const gps_pageinfo2_t *pageinfo2, unsigned long *FP_flag);
int GPS_FramePrint(gwmsg_client_t *client, int FP_frameid, const gps_pageinfo_t *pageinfo, int FP_force);
int GPS_FrameClose(gwmsg_client_t *client, int FP_frameid);
int GPS_PenvSetDefValue(gwmsg_client_t *client, int penv, long penv_var, long penv_val);
int GPS_PlotClose(gwmsg_client_t *client, int plotid);
int GPS_SinClose(gps_hostbuf_p host_inBuff);
int GPS_SoutClose(gps_hostbuf_p host_outBuff);
void GPS_InterpFinishProcData(gwmsg_client_t *client, int ujobid, int fin, int uel_found);
void GPS_Close(gwmsg_client_t *client, void *shdm_addr);
void init_page_structs();

#if 0
int main()
{
	int GPSOpenRetVal;
   	int GPSInterPNotifyStartRetVal;
	int GPSBitSWRetVal = 0;	
	int GPSPenvGetValueListRetVal;
	int GPSPenvGetDefListRetVal;
	int GPSBinInfoRetVal;
	int GPSTrayInfoRetVal;
	int GPSGetSysInfoRetVal;
	int Wsbytes;
	int GPSgpsGetHddInfo2RetVal;
	int GPSPlotPrepRetVal;
	int GPSSinCloseval, GPSSoutCloseval;
	int GPSGetPrtStatus2val;
	static caddr_t memaddr;
	int GPSColorgetID2RetVal;
	int retGPSPrmInfo;
	char retGPSPmInit;
	int retGPSGetModelInfo;
	long maxsize[2];
	int f_id = GPS_PRMINFO_GET_COLOR_MODEL;
 	unsigned char value[65];
    int status;
   	int retGPSPenvOpen, retGPSPenvGetVal, retGPSColorGetProfile, retGetFontInfo;
    int retGPSColorGetRID;
	long retColorGetShrd;
	char *penv_name = GPS_PENV_NAME_PCL;
    int penv = 5;
	long size = 7;
    int font = GPS_FONT_PCL;
	gps_fontinfo_t fontinfo ;
    long penv_var = 158; //= (long)GPS_PENV_NAME_COMMON;
	long penv_val;
	int modeID;
	long rID_size=4;
	void *addr; 
	long num;
    long mallocsize = 100;
    int interp_ID = GPS_INTERP_PCL5c;
    int number = BIT_SW_004;
    int gps_penv = 5;
    long gps_var = 8, gps_start = 0, gps_num = 8;
    long gps_value;
    long gps_value_num;
    long gpsBinInfoNum, gpsTrayInfoNum;
    int gps_notify=0;
    int trays = 5;
	int job_id = 1;
	int interp_num=1;
	unsigned long offset = 0;
	int GPSPlotOpenRetVal;
	int GPSFrameFlushBandResRetVal;
	int gps_paperId = 133;
	int GPS_GetPdlPrintConditionShmRetVal;
	int GPSGetPaperInfoRetVal;
	gps_hostbuf_p host_inBuff, host_outBuff;
	int host_id = -1;
	long pdl_offset = 0;
	int pdl_num = 0;
	int GPSPdlTableval;
	int prt_notify = 0, prt_res;
	int uJobId = 1;
	int	PlotSet_plotid = 1, PlotSet_result;
	int GPSPlotSetPageParamShmval;
	int framecreate_plotid = 1, framecreate_result;
	int GPSFrameCreateExval;
	int FCinfo_plotid = 1, FCinfo_force = 0;
	int GPSFrameCreateInfoResval;
	int	FGband_frameid=1, FGband_bandid=0, FGband_planeid=0;
	int GPSFrameGetBandResval;
	int FFB_frameid=1, FFB_bandid=0, FFB_planeid=0, FFB_drawn=1, FFB_flush=0;
	int FP_frameid=1;
	unsigned long FP_flag;
	int GPSFramePrintInfoval;
	int FP_force=GPS_PRINT_NORMAL;
	int GPSFramePrintval;
	int GPSFrameCloseval;
	int GPSPenvSetDefValueval;
	int GPSPlotCloseval;
	int fin =GPS_INTERP_FIN_NORMAL, uel_found=1;
	int plotOpen_openmode=0;
	int i,j,k;
	
	pthread_attr_t attr;
	struct sched_param di_param;
	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, SCHED_RR);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	di_param.sched_priority = sched_get_priority_max(SCHED_RR);
	pthread_attr_setschedparam(&attr, &di_param);

    GPSOpenRetVal = GPS_Open(gps_client, gwmsg_interp_handler, attr, (void *)(&shdm_addr));
    
	
	retGPSPrmInfo = GPS_GetPrmInfo( gps_client, f_id, &status, sizeof(long)*2, maxsize );
	if(retGPSPrmInfo == 1)
	      printf("GPS_GetPrmInfo: SUCCESS \n");
    else 
	      printf("GPS_GetPrmInfo: FAILED \n");
		  
	if(status == GPS_PRMINFO_SUCCESS)
	      printf("GPS_GetPrmInfo: STATUS SUCCESS\n");
    else 
	      printf("GPS_GetPrmInfo:STATUS FAILED\n");
             
		  
  
	retGPSPmInit = GPS_PmInit(gps_client, 0,0);
	if(retGPSPmInit == PM_SUCCESS)
	     printf("GPS_PmInit: SUCCESS\n");
	else
		 printf("GPS_PmInit: FAILED\n"); 


	  
	retGPSGetModelInfo = GPS_GetModelInfo(gps_client, 0, 1,	"color_prm_val", "COLOR", 32, value);
	if(retGPSGetModelInfo == 0)
	     printf("GPS_GetModelInfo: Search Successful\n");
	else
	     printf("GPS_GetModelInfo: Search Failed\n"); //Either key or category not found, buffer overflow, illegal param, init error.

    GPSGetSysInfoRetVal = GPS_GetSysInfo(gps_client,&sysinfo);
  	if(GPSGetSysInfoRetVal == 0)
	{
		printf("Sys Info is success\n");
	}
	else
	{
		printf("Sys Info is failed\n");
	}
	
	Wsbytes = GPS_WkSizeFree(gps_client);
	if(Wsbytes)
	{
		printf("GPS_WkSizeFree success\n");
	}
	else
	{
		printf("GPS_WkSizeFree failed\n");
	}
	
	GPS_PmDispSetEmulation(SET_DISP, SET_DISP,SET_DISP, "PCL5e");
	
	
	
    retGPSPenvOpen = GPS_PenvOpen( gps_client, penv_name, size);
	
    if(retGPSPenvOpen == PENV_HANDLER)
		     printf("GPS_PenvOpen: SUCCESS\n");
    else 
             printf("GPS_PenvOpen: FAILED\n");
 
    GPSPenvGetDefListRetVal = GPS_PenvGetDefValue(gps_client, gps_penv, gps_var, &gps_value);

	if(GPSPenvGetDefListRetVal >= 0)
		{
			printf("Environment Def List: success\n");
		}
		else
		{
			printf("Environment Def List: failed\n");
		}


    retGPSPenvGetVal = GPS_PenvGetValue( gps_client, penv, gps_var, &penv_val );
	
    if(retGPSPenvGetVal < 0)
	     printf("GPS_PenvGetValue: FAILED\n");
	else
        printf("GPS_PenvGetValue: SUCCESS\n"); 	


    memaddr = GPS_WkMalloc(gps_client, mallocsize);
	
    if(memaddr)
	    printf("GPS_WkMalloc success\n");
	else
		printf("GPS_WkMalloc failed\n");
	

	GPSColorgetID2RetVal = GPS_ColorgetID2(gps_client, 600, 600, 2, PHOTO_DRAWMODE, HIGH_PRINTMODE, GPS_PAPER_NORMAL,&modeID);
	if(GPSColorgetID2RetVal)
		printf("GPS_ColorgetID2 is success\n");
	else
		printf("GPS_ColorgetID2 is failed\n");
		

    retGPSColorGetRID = GPS_Color_getRID( gps_client, modeID, rID, &rID_size );

    if(retGPSColorGetRID >= 0)
	    printf("GPS_Color_getRID: SUCCESS\n");
	else 
	    printf("GPS_Color_getRID: FAILED\n"); 
	

    retGPSColorGetProfile = GPS_Color_getProfile( gps_client, &addr, &num );
	
    if(retGPSColorGetProfile == 1)
	     printf("GPS_Color_getProfile: SUCCESS\n");
	else 
	     printf("GPS_Color_getProfile: FAILED\n");


    GPSTrayInfoRetVal = GPS_TrayInfo(gps_client, trays, &gpsTrayInfo, &gpsTrayInfoNum, gps_notify);
	
    if(GPSTrayInfoRetVal == 0)
		printf("Tray Info value success\n");
	else
		printf("Tray Info value failed\n");
	
	
	GPSBinInfoRetVal = GPS_BinInfo(gps_client, gps_num, &gpsBinInfo, &gpsBinInfoNum, gps_notify);
	
    if(GPSBinInfoRetVal >= 0)
		printf("Bin Info value success\n");
	else
		printf("Bin Info value failed \n");
	
				
	GPSgpsGetHddInfo2RetVal = GPS_gpsGetHddInfo2( gps_client, GPS_HDD_TMP, status, hddinfo );
	
    if(GPSgpsGetHddInfo2RetVal)
		printf("GPS_gpsGetHddInfo2 is success\n");
	else 
	    printf("GPS_gpsGetHddInfo2 is failed\n");
		
	 
    retGetFontInfo = GPS_GetFontInfo(gps_client, font, &fontinfo);	
	
    if(retGetFontInfo == 0)
	     printf("GPS_GetFontInfo: SUCCESS\n");
	else 
	     printf("GPS_GetFontInfo: FAILED\n");
   
  
    GPSPenvGetValueListRetVal = GPS_PenvGetValueList(gps_client, gps_penv, gps_var, gps_start, gps_num, &gps_value, &gps_value_num);
	
    if(GPSPenvGetValueListRetVal == 0)
		printf("Environmental value list: success\n");
	else
	    printf("Environmental value list: failed\n");
				
    GPS_PenvClose(gps_client, penv);
    
    retColorGetShrd = GPS_Color_getShrd(gps_client);
	
    if(retColorGetShrd < 0)
	    printf("GPS_Color_getShrd: FAILED\n");
	else 
	    printf("GPS_Color_getShrd: SUCCESS\n");


    GPSBitSWRetVal = GPS_GetBitSw(gps_client, number);
	
    if((GPSBitSWRetVal = BIT_SW_001) || (GPSBitSWRetVal <= BIT_SW_016))
		printf("GPS_getBitSW is success\n");
	else
		printf("GPS_getBitSW is failed\n");
	

	GPSInterPNotifyStartRetVal = GPS_InterpNotifyStart(gps_client, interp_ID); 
		
	if(GPSInterPNotifyStartRetVal == 0)
		printf("GPS_InterpNotifyStart: SUCCESS\n");
	else 
		printf("GPS_InterpNotifyStart: FAILED\n");
	    
	GPS_InterpNotifyOnline(gps_client);
	printf("NotifyOnline: SUCCESS\n");
	printf("\n************JOB START************\n");
	GPS_PmDispSetEmulation(RESET_DISP, RESET_DISP, RESET_DISP, "PCL5e");
	
	GPS_GetPdlPrintConditionShmRetVal = GPS_GetPdlPrintConditionShm(gps_client,job_id,&status, &offset);
	if(GPS_GetPdlPrintConditionShmRetVal)
		{
			printf("GPS_GetPdlPrintConditionShm : SUCCESS\n");
		}
		else
		{
			printf("GPS_GetPdlPrintConditionShm : FAILED\n");
		}
	
	retGPSPenvOpen = GPS_PenvOpen( gps_client, penv_name, size);
	
    if(retGPSPenvOpen == PENV_HANDLER)
		     printf("GPS_PenvOpen: SUCCESS\n");
    else 
             printf("GPS_PenvOpen: FAILED\n");
 
    GPSPenvGetDefListRetVal = GPS_PenvGetDefValue(gps_client, gps_penv, gps_var, &gps_value);

	if(GPSPenvGetDefListRetVal >= 0)
		{
			printf("Environment Def List: success\n");
		}
		else
		{
			printf("Environment Def List: failed\n");
		}


    retGPSPenvGetVal = GPS_PenvGetValue( gps_client, penv, gps_var, &penv_val );
	
    if(retGPSPenvGetVal < 0)
	     printf("GPS_PenvGetValue: FAILED\n");
	else
        printf("GPS_PenvGetValue: SUCCESS\n"); 	
		
	GPSGetPaperInfoRetVal = GPS_GetPaperInfo(gps_client, gps_paperId, &gpsPaperInfo, gps_notify);
	
	if(GPSGetPaperInfoRetVal)
		{
			printf("GPS_GetPaperInfo : SUCCESS\n");
		}
		else
		{
			printf("GPS_GetPaperInfo : FAILED\n");
		}	
		
	
    GPS_PenvClose(gps_client, penv);
	GPS_InterpNotifyState(gps_client, interp_num);
	printf("Notify state is success and returns void\n");	
	host_inBuff = GPS_SinOpen(gps_client, host_id);
	if(host_inBuff)
	{
		printf("GPS_SinOpen : Successful\n");
	}
	else
	{
		printf("GPS_SinOpen : Failed\n");
	}
	host_outBuff = GPS_SoutOpen(gps_client, host_id);
	if(host_outBuff)
	{
		printf("GPS_SoutOpen : Successful\n");
	}
	else
	{
		printf("GPS_SoutOpen : Failed\n");
	}
	GPSBitSWRetVal = GPS_GetBitSw(gps_client, BIT_SW_001);
	GPSPdlTableval = GPS_GetPdlTable(gps_client, &pdl_offset, &pdl_num);
	if(!GPSPdlTableval)
	{
		printf("GetPdlTable : Successful\n");
	}
	retGPSPrmInfo = GPS_GetPrmInfo( gps_client, GPS_PRMINFO_GET_NUMFLASHMEM, &status, sizeof(long)*2, maxsize );
	if(retGPSPrmInfo == 1)
	      printf("GPS_GetPrmInfo: SUCCESS \n");
    else 
	      printf("GPS_GetPrmInfo: FAILED \n");
		  
	if(status == GPS_PRMINFO_SUCCESS)
	      printf("GPS_GetPrmInfo: STATUS SUCCESS\n");
    else 
	      printf("GPS_GetPrmInfo:STATUS FAILED\n");
    
	GPSGetPrtStatus2val = GPS_GetPrtStatus2(gps_client, &prtStatus, prt_notify, &prt_res);
	if(GPSGetPrtStatus2val)
	{
		printf("GetPrtStatus2 : Success\n");
	}
	retGPSGetModelInfo = GPS_GetModelInfo(gps_client, 0, 1,	"color_prm_val", "COLOR", 32, value);
	if(retGPSGetModelInfo == 0)
	     printf("GPS_GetModelInfo: Search Successful\n");
	else
	     printf("GPS_GetModelInfo: Search Failed\n"); //Either key or category not found, buffer overflow, illegal param, init error.
	GPSgpsGetHddInfo2RetVal = GPS_gpsGetHddInfo2( gps_client, GPS_HDD_TMP, status, hddinfo );
	
    if(GPSgpsGetHddInfo2RetVal)
		printf("GPS_gpsGetHddInfo2 is success\n");
	else 
	    printf("GPS_gpsGetHddInfo2 is failed\n");
	
	GPSPlotPrepRetVal = GPS_PlotPrepare(gps_client, uJobId, &plotPrepare);
	if(GPSPlotPrepRetVal)
	{
		printf("GPS_PlotPrepare : Success\n");
	}
	else 
	{
		printf("GPS_PlotPrepare : Failed\n");
	}
	GPSPlotOpenRetVal = GPS_PlotOpen(gps_client, uJobId, plotOpen_openmode);
	if(GPSPlotOpenRetVal >= 0)
	{
		printf("GPS_PlotOpen : Success\n");
	}
	else
	{
		printf("GPS_PlotOpen : Failed\n");
	}
	GPSPlotSetPageParamShmval = GPS_PlotSetPageParamShm(gps_client, PlotSet_plotid, &param, &PlotSet_result);
	if(GPSPlotSetPageParamShmval)
	{
		printf("GPS_PlotSetPageParamShm : Success\n");
	}
	memset(&pagemode, 0, sizeof(pagemode));
	memset(&pagemode2, 0, sizeof(pagemode2));
	memset(&pageinfo, 0, sizeof(pageinfo));
	memset(&pageinfo2, 0, sizeof(pageinfo2));
	init_page_structs();
	GPSFrameCreateExval = GPS_FrameCreateEx(gps_client, framecreate_plotid, &pagemode2, &pageinfo2, &framecreate_result);
	if(GPSFrameCreateExval)
	{
		printf("GPS_FrameCreateExval : Success\n");
	}
	else
	{
		printf("GPS_FrameCreateExval : Failed\n");
	}
	GPSFrameCreateInfoResval = GPS_FrameCreateInfoRes(gps_client, FCinfo_plotid, &pagemode, &pageinfo, FCinfo_force, &pFCR);
	if(GPSFrameCreateInfoResval>=0)
	{
		printf("GPS_FrameCreateInfoRes : Success\n");
	}
	else
	{
		printf("GPS_FrameCreateInfoRes : Failed\n");
	}
	for(k=0;k<3;k++)
	{	
		for(i=0;i<4;i++)
		{
			GPSFrameGetBandResval = GPS_FrameGetBandRes(gps_client, FGband_frameid, FGband_bandid+k, FGband_planeid+i, &pFGBR);
			if(!GPSFrameGetBandResval)
			{
				printf("GPS_FrameGetBandRes : Success\n");
			}
			else
			{
				printf("GPS_FrameGetBandRes : Failed\n");
			}
		}
		for( j=0;j<4;j++)
		{
			GPSFrameFlushBandResRetVal = GPS_FrameFlushBandRes(gps_client, FFB_frameid, FFB_bandid+k, FFB_planeid+j, FFB_drawn, FFB_flush, &pFFBR);
			if(!GPSFrameFlushBandResRetVal)
			{
				printf("GPS_FrameFlushBandRes : Success\n");
			}
			else
			{
				printf("GPS_FrameFlushBandRes : Failed\n");
			}
		}
	}
	
	 GPSFramePrintInfoval = GPS_FramePrintInfo(gps_client, FP_frameid, &pageinfo2, &FP_flag);
	 if(GPSFramePrintInfoval)
	 {
		printf("GPS_FramePrintInfo : Success\n");
	 }
	 else
	 {
		printf("GPS_FramePrintInfo : Failed\n");
	 }
	GPSFramePrintval = GPS_FramePrint(gps_client, FP_frameid, &pageinfo, FP_force);
	if(!GPSFramePrintval)
	{
		printf("GPS_FramePrint : Success\n");
	}
	else
	{
		printf("GPS_FramePrint : Failed\n");
	}
	GPSFrameCloseval = GPS_FrameClose(gps_client, FP_frameid);
	if(!GPSFrameCloseval)
	{
		printf("GPS_FrameClose : Success\n");
	}
	else
	{
		printf("GPS_FrameClose : Failed\n");
	}

    retGPSPenvOpen = GPS_PenvOpen( gps_client, penv_name, size);
	
    if(retGPSPenvOpen == PENV_HANDLER)
		     printf("GPS_PenvOpen: SUCCESS\n");
    else 
             printf("GPS_PenvOpen: FAILED\n");
	GPSPenvSetDefValueval = GPS_PenvSetDefValue(gps_client, penv, penv_var, penv_val);
	if(GPSPenvSetDefValueval>=0)
	{
		printf("GPS_PenvSetDefValue : Success\n");
	}
	else
	{
		printf("GPS_PenvSetDefValue : Failed\n");
	}
	GPS_PenvClose(gps_client, penv);

	GPSPlotCloseval = GPS_PlotClose(gps_client, PlotSet_plotid);
	if(GPSPlotCloseval>=0)
	{
		printf("GPS_PlotClose : Success\n");
	}
	else
	{
		printf("GPS_PlotClose : Failed\n");
	}
	GPSSinCloseval=GPS_SinClose(host_inBuff);
	if(GPSSinCloseval==0)
	{
		printf("GPS_SinClose : Success\n");
	}
	else
	{
		printf("GPS_SinClose : Failed\n");
	}
	GPSSoutCloseval=GPS_SoutClose(host_outBuff);
	if(GPSSoutCloseval==0)
	{
		printf("GPS_SoutClose : Success\n");
	}
	else
	{
		printf("GPS_SoutClose : Failed\n");
	}
	GPS_InterpFinishProcData(gps_client, job_id, fin, uel_found);
	
	GPS_Close(gps_client, shdm_addr);

	return(0);
}
#endif

void init_page_structs()
 {
 /* assign values to structures*/
pagemode2.flag = 0x7;
pagemode2.frame_width = 6814;
pagemode2.frame_length = 4760;
pagemode2.band_length = 2048;
//memset(&pagemode2.res, 0, sizeof(pagemode2.res));

pageinfo2.flag = 0x7e;
pageinfo2.bypass_dir = 0x0;
pageinfo2.page_shift = 0x0;
pageinfo2.print_mode = 0x2;
pageinfo2.paper_width = 2970;
pageinfo2.paper_length = 2100;
pageinfo2.frame_width = 6814;
pageinfo2.frame_length = 4760;
pageinfo2.band_length = 2048;
//memset(&pageinfo2.res1, 0, sizeof(pageinfo2.res1));
//memset(&pageinfo2.res2, 0, sizeof(pageinfo2.res2));
//memset(&pageinfo2.res3, 0, sizeof(pageinfo2.res3));

pagemode.frame_width = 6814;
pagemode.frame_length = 4760;
pagemode.band_length = 2048;
pagemode.color_count = 4;
pagemode.depth = 1;
pagemode.skip_level = 0;
pagemode.rotate = 2;
pagemode.face = 1;
pagemode.upsidedown = 0;
pagemode.ra_id_k = 1;
pagemode.ra_id_c = 1;
pagemode.ra_id_m = 1;
pagemode.ra_id_y = 1;
pagemode.ra_offx_k = 0;
pagemode.ra_offy_k = 0;
pagemode.ra_offx_c = 0;
pagemode.ra_offy_c = 0;
pagemode.ra_offx_m = 0;
pagemode.ra_offy_m = 0;
pagemode.ra_offx_y = 0;
pagemode.ra_offy_y = 0;

pageinfo.paper_code = 5;
pageinfo.paper_width = 2970;
pageinfo.paper_length = 2100;
pageinfo.band_length = 2048;
pageinfo.line_size = 0;
pageinfo.xoffset = 100;
pageinfo.yoffset = 100;
pageinfo.resolution_x = 600;
pageinfo.resolution_y = 600;
pageinfo.compress = 4;
pageinfo.color = 1;
pageinfo.fci = 0;
pageinfo.input_tray = 15;
pageinfo.paper_type = 0;
pageinfo.limitless_feed = 1;
pageinfo.paper_count = 1;
pageinfo.count_off = 0;
 }
 
 
 
/***********************************************************************************************************
*Function Name: GPS_Open()
*Attributes:
*client  IN   Client identifier
*handler IN   GW-IPC handler to process events coming from GPS
*attr    IN   Specifies an attribute of pthread to process GW-IPC events.
*shm_addr OUT   Sheared memory address that is necessary to receive/send data with GPS.
*Description: This function initializes the system to act as the client connected to GPS.
************************************************************************************************************/
int GPS_Open(gwmsg_client_t *client, gwmsg_handler_t gwmsg_handler_t, pthread_attr_t attr, void **shm_addr)
{
    printf("------------------------------------- \n");
	printf("Call gpsOpen\n");
    return gpsOpen(gps_client, gwmsg_interp_handler, &attr, (void *)(&shm_addr));
}
/***********************************************************************************************************
*Function Name: GPS_GetPrmInfo()
*Attributes:
*client  IN   Client identifier
*f_id IN Type of information that has been obtained
**status OUT Status of obtained information
*size IN Size of buf // use only when ID is specified to use buf 
*buf OUT Obtained information // use only when the ID is designated to use buf 
*Description: This function obtains information of print material.
************************************************************************************************************/
int GPS_GetPrmInfo(gwmsg_client_t *client, int f_id, int *status, int size,	long *maxsize)
{
	printf("------------------------------------- \n");   
   printf("Call gpsGetPrmInfo\n");
    return gpsGetPrmInfo( client, f_id, status, size, maxsize );
    printf("Returned from gpsGetPrmInfo\n");
}
/***********************************************************************************************************
*Function Name: GPS_PmInit()
*Attributes:
*client  IN   Client identifier
*Description: 'gps' entry to initialize panel manager.
************************************************************************************************************/
char GPS_PmInit(gwmsg_client_t *client, void(*pfunc1)(), void(*pfunc2)())
{
     printf("------------------------------------- \n");
	printf("Call gpsPmInit\n");
    return gpsPmInit(client, pfunc1, pfunc2);
}
/***********************************************************************************************************
*Function Name: GPS_GetModelInfo()
*Attributes:
*client  IN   Client identifier
*dummy   IN   Remove the loops from the code
*num     IN   The integer starting from 1.
*key     IN   Search key
*category  IN Category
*value_len IN The size of value[] (the array for return value).
*value     OUT The address for the array for return value. Values acceptable for key are copied.
*Description: This function retrieves model-specific information.
************************************************************************************************************/
int GPS_GetModelInfo(gwmsg_client_t *client, char  dummy, char num,char	*key, char	*category, 	unsigned char value_len, unsigned char	*value)
{
   printf("------------------------------------- \n");
   printf("Call gpsGetModelInfo \n");
   return gpsGetModelInfo(client, 0, 1, (unsigned char *) key, (unsigned char *)category, value_len, value);
}
/***********************************************************************************************************
*Function Name: GPS_PenvOpen()
*Attributes:
*client  IN   Client identifier
*penv IN Environment variable table handler
*Description: This function opens the environment variable table.
************************************************************************************************************/
int GPS_PenvOpen(gwmsg_client_t *client, char *penv_name, long size)
{
    printf("------------------------------------- \n");
	printf("Calling gpsPenvOpen\n");
	return gpsPenvOpen(gps_client, penv_name, size);
}
/***********************************************************************************************************
*Function Name: GPS_PenvGetValue()
*Attributes:
*client  IN   Client identifier
*penv IN Environment variable table handler
*        Value obtained as the return value of gpsPenvOpen() function
*var IN Environment variable ID (defined separately)
*val OUT Environment variable value obtained
*Description: This function obtains the current environment variable setting.
************************************************************************************************************/
int GPS_PenvGetValue( gwmsg_client_t* client, int penv, long gps_var, long *penv_val )
{
	printf("------------------------------------- \n");
    printf("Calling gpsPenvGetVal \n");
	return gpsPenvGetValue( gps_client, penv, gps_var, penv_val );
}
/***********************************************************************************************************
*Function Name: GPS_Color_getShrd()
*Attributes:
*client  IN   Client identifier
*= Return value =
*Offset from the shared memory pointer to the color data shared memory pointer.
*Description: This function retrieves color data shared memory
************************************************************************************************************/
long GPS_Color_getShrd(gwmsg_client_t *client)
{
    printf("------------------------------------- \n");
	printf("Calling gpsColor_getShrd\n");
   return gpsColor_getShrd( gps_client );
}
/***********************************************************************************************************
*Function Name: GPS_Color_getRID()
*Attributes:
*client  IN   Client identifier
*modeID IN ID obtained by gpsColor_getID()
*rID OUT Stores rearrange ID
*rID_size OUT Number of bytes of rID
*Description: This function retrieves ID for Page Structure's rearrange matrix pattern ID, from color mode ID.
************************************************************************************************************/
int	GPS_Color_getRID( gwmsg_client_t *client, int modeID, gps_color_rid_t *rID, long *rID_size )
{ 
    printf("------------------------------------- \n");
	printf("Calling gpsColor_getRID\n");
   return gpsColor_getRID(client, 1, rID, rID_size);
}
/***********************************************************************************************************
*Function Name: GPS_Color_getProfile()
*Attributes:
*client  IN   Client identifier
**addr   OUT  Address of the shared memory area for the Color Matching Profile table
*num     OUT  Number of profiles in Color Matching Profile table
*Description: This function obtains the address to the shared memory for the Color Matching Profile table used for PDL.
************************************************************************************************************/
int GPS_Color_getProfile(gwmsg_client_t  *client, void **addr, long	*num)
{ 
     printf("------------------------------------- \n");
	 printf("Calling gpsColor_getProfile\n");
    return gpsColor_getProfile( gps_client, addr, num );
}
/***********************************************************************************************************
*Function Name: GPS_GetFontInfo()
*Attributes:
*client  IN   Client identifier
*font IN Font type
**fontinfo OUT Font Information Structure
*Description: This function obtains font information.
************************************************************************************************************/
int GPS_GetFontInfo(gwmsg_client_t *client, int font, gps_fontinfo_t *fontinfo)
{
     printf("------------------------------------- \n");
	 printf("Calling gpsGetFontInfo\n");
	return gpsGetFontInfo(gps_client, font, fontinfo);
}
/***********************************************************************************************************
*Function Name: GPS_PenvClose()
*Attributes:
*client  IN   Client identifier
*penv    IN Environment variable table handler
*Description: This function closes the environment variable table.
************************************************************************************************************/
void GPS_PenvClose(gwmsg_client_t *client, int penv)
{
    printf("------------------------------------- \n");
	printf("Calling gpsPenvClose\n");
   gpsPenvClose( gps_client , penv );
   
}
/***********************************************************************************************************
*Function Name: GPS_TrayInfo()
*Attributes:
*client  IN   Client identifier
*num     IN   Number of the trayinfo[] arrays. Set the number of trays indicated in the information obtained
*                by gpsGetSysInfo() function.
*trayinfo OUT Input Tray Information Structure
*trayinfo_num OUT Returns the number of trays set to trayinfo[] array.
*notify IN Set to receive / not receive event whenever there is a change in the information.
*Description: This function obtains input tray information.
************************************************************************************************************/
int GPS_TrayInfo(gwmsg_client_t *client, int num, gps_trayinfo_t *gpsTrayInfo, long *trayNum, int notify)
{
	 printf("------------------------------------- \n");
	 printf("Call Tray Info value\n");
	return gpsGetTrayInfo(client, num, gpsTrayInfo, trayNum, notify);
}
/***********************************************************************************************************
*Function Name: GPS_BinInfo()
*Attributes:
*client  IN   Client identifier
*num     IN Number of bininfo[] array. Set the number of output bins obtained by gpsGetSysInfo().
*bininfo OUT Output Bin Information Structure
*bininfo_num OUT Returns the number of bins set to bininfo[] array.
*notify  IN Enable/disable receiving an event whenever there is a change in the information.
*Description: This function obtains output bin information.
************************************************************************************************************/
int GPS_BinInfo(gwmsg_client_t *client, int num, gps_bininfo_t *gpsBinInfo, long *binInfo, int notify)
{
	 printf("------------------------------------- \n");
	 printf("Call Bin Info value\n");
	return gpsGetBinInfo(client, num, gpsBinInfo, binInfo, notify);
}
/***********************************************************************************************************
*Function Name: GPS_PenvGetDefValue()
*Attributes:
*client  IN   Client identifier
*penv IN Environment variable table handler
*         IN Value obtained as the return value by gpsPenvOpen() function
*var IN Environment variable ID (defined separately)
*val OUT Environment variable value obtained
*Description: This function retrieves default environment variable value.
************************************************************************************************************/
int GPS_PenvGetDefValue(gwmsg_client_t *client, int p_env, long Var, long *Val)
{
	 printf("------------------------------------- \n");
	 printf("Call Environment Def value\n");
	return gpsPenvGetDefValue(client, p_env, Var, Val);
}
/***********************************************************************************************************
*Function Name: GPS_PenvGetValueList()
*Attributes:
*client  IN   Client identifier
*penv    IN   Handler for environment variable table
*              The value obtained as returned value by gpsPenvOpen() function
*var IN Environment variable ID
*start IN Number of the environment variable to be obtained from the list (the number starting
*           from the top)
*num IN Number of the environment variable values to be obtained == the length of the array
*         value[]
*value OUT Pointer to the array to assign the list of values
*value_size OUT Number of valid entries from the variable list entered to var[]
*Description: This function obtains the list of environment variable values.
************************************************************************************************************/
int  GPS_PenvGetValueList(gwmsg_client_t *client, int p_env, long Var, long Start, long Number1, long *Val, long *Val_num)
{
	 printf("------------------------------------- \n");
	 printf("Call Environmental variable\n");
          return gpsPenvGetValueList(client, p_env, Var, Start, Number1, Val, Val_num);
}
/***********************************************************************************************************
*Function Name: GPS_GetBitSw()
*Attributes:
*client  IN   Client identifier
*no IN Bit Switch number (BIT_SW_001 -- BIT_SW_016)
*Description: This function obtains values of specified Bit Switch number.
************************************************************************************************************/
int GPS_GetBitSw(gwmsg_client_t *client, int num)
{
	 printf("------------------------------------- \n");
	 printf("Call GPS_getBitSW\n");
	return gpsGetBitSw(client, num);
}
/***********************************************************************************************************
*Function Name: GPS_InterpNotifyStart()
*Attributes:
*client  IN   Client identifier
*interp_id IN Interpreter ID
*Description: This function notifies the system the start of the interpreter.
************************************************************************************************************/
int GPS_InterpNotifyStart(gwmsg_client_t *client, int interpre_ID)
{
	 printf("------------------------------------- \n");
	 printf("call notifyStart\n");
	return gpsInterpNotifyStart(client, interpre_ID);
}
/***********************************************************************************************************
*Function Name: GPS_InterpNotifyOnline()
*Attributes:
*client  IN   Client identifier
*Description: This event notifies the printer's online state to the interpreter.
************************************************************************************************************/
void GPS_InterpNotifyOnline(gwmsg_client_t *client)
	{
		 printf("------------------------------------- \n");
		 printf("Call notify Online\n");
		return gpsInterpNotifyOnline(client);
	}
	
/***********************************************************************************************************
*Function Name: GPS_PmDispSetEmulation()
*Attributes:
*client  IN   Client identifier
*
*Description: 
************************************************************************************************************/
void GPS_PmDispSetEmulation(char	cond_exist,	char	pnum_exist,	char	tray_exist,	char	*str)
{
     printf("------------------------------------- \n");
	 printf("Call gpsPmDispSetEmulation\n");
    gpsPmDispSetEmulation(cond_exist, pnum_exist,tray_exist, str);
}
/***********************************************************************************************************
*Function Name: GPS_GetSysInfo()
*Attributes:
*client  IN   Client identifier
*sysinfo OUT System Information Structure
*Description: This function obtains system information.
************************************************************************************************************/
int GPS_GetSysInfo(gwmsg_client_t	*client, gps_sysinfo_t *sysinfo)
{
     printf("------------------------------------- \n");
	 printf("Call gpsGetSysInfo\n");
   	return gpsGetSysInfo( client, sysinfo );

}
/***********************************************************************************************************
*Function Name: GPS_WkSizeFree()
*Attributes:
*client  IN   Client identifier
*= Return value =
*byte value
*Description: This function obtains the size of available working memory in bytes.
************************************************************************************************************/
int GPS_WkSizeFree(gwmsg_client_t *client)  
{
	printf("------------------------------------- \n");
	printf("Call gpsWkSizeFree\n");

	return gpsWkSizeFree(client );
}
/***********************************************************************************************************
*Function Name: GPS_WkMalloc()
*Attributes:
*client  IN   Client identifier
*= Return value =
*byte value
*Description: This function obtains the size of available working memory in bytes.
************************************************************************************************************/
caddr_t GPS_WkMalloc(gwmsg_client_t *client, long mallocsize) 
{
  printf("------------------------------------- \n");
  printf("Call gpsWkMalloc\n");
  return gpsWkMalloc(client, mallocsize );
  
}
/***********************************************************************************************************
*Function Name: GPS_ColorgetID2()
*Attributes:
*client  IN   Client identifier
*hdpi IN Horizontal resolution
*vdpi IN Vertical resolution
*bit IN Quantifying bit
*draw IN Drawing mode
*prt IN Print mode
*paper IN Paper type
*modeID OUT Color mode ID
*Description: Obtains dither data and gamma data array number within shared memory.
************************************************************************************************************/
int GPS_ColorgetID2(gwmsg_client_t *client, int hdpi, int vdpi, int bit, int draw, unsigned char prt,unsigned char paper, int *modeID)  
{
	printf("------------------------------------- \n");
	printf("Call gpsColor_getID2\n");
	return gpsColor_getID2(client, hdpi, vdpi, bit, draw, prt, paper, modeID);
}

/***********************************************************************************************************
*Function Name: PS_gpsGetHddInfo2()
*Attributes:
*client   IN   Client identifier
*hdd      IN   Memory type: HDD/RAM/SD
**status  OUT  indicates whether information is obtained.
**hddinfo2 OUT HDD information structure 2
*Description: Obtains information of HDD/RAM/SD.
************************************************************************************************************/
int GPS_gpsGetHddInfo2(gwmsg_client_t* client, int hdd, int status, gps_hddinfo2_t hddinfo2)  
{
	printf("------------------------------------- \n");
	printf("Call gpsGetHddInfo2\n");
	return gpsGetHddInfo2( client, hdd, &status, &hddinfo2 );
}

/***********************************************************************************************************
*Function Name: GPS_GetPdlPrintConditionShm()
*Attributes:
*client IN      Client identifier
*ujobid IN      User job ID
*status OUT     result
**offset OUT    Offset to the storage area of Printing Conditions
*Description: This API retrieves information on printing conditions
************************************************************************************************************/

int GPS_GetPdlPrintConditionShm(gwmsg_client_t *client,int ujobid,int *status,unsigned long *offset)
{
	printf("------------------------------------- \n");
    printf("Call gpsGetPdlPrintConditionShm\n");
    return gpsGetPdlPrintConditionShm(client, ujobid,status,offset);
}

/***********************************************************************************************************
*Function Name: GPS_GetPaperInfo()
*Attributes:
*client    IN     Client identifier
*paper_id  IN     Paper size ID
*paperinfo OUT     Paper Information Structure (Reply is currently not supported)
*notify    IN     Undefined
*Description: This function obtains paper (media) information
************************************************************************************************************/

int GPS_GetPaperInfo(gwmsg_client_t *client, int PaperId, gps_paperinfo_t *gpsPaperInfo, int notify)
{
	printf("------------------------------------- \n");
	printf("Call gpsGetPaperInfo\n");
	return gpsGetPaperInfo(client, PaperId, gpsPaperInfo, notify);
}

/***********************************************************************************************************
*Function Name: GPS_InterpNotifyState()
*Attributes:
*client IN      Client identifier
*state  IN      Status
*Description: This function notifies the status of the interpreter
************************************************************************************************************/

void GPS_InterpNotifyState(gwmsg_client_t *client, int number)
{
	printf("------------------------------------- \n");
	printf("Call gpsInterpNotifyState\n");
	return gpsInterpNotifyState(client, number);
}

/***********************************************************************************************************
*Function Name: GPS_SinOpen()
*Attributes:
*client IN      Client identifier
*hostid IN      Host ID
*Description: This function opens receiving buffer.
************************************************************************************************************/
gps_hostbuf_p GPS_SinOpen(gwmsg_client_t *client, int host_id)
{
	printf("------------------------------------- \n");
	printf("Call gpsSinOpen\n");
	return gpsSinOpen(client, host_id);
}

/***********************************************************************************************************
*Function Name: GPS_SoutOpen()
*Attributes:
*client IN     Client identifier
*hostid IN     Host ID
*Description: This function opens sending buffer.
************************************************************************************************************/
gps_hostbuf_p GPS_SoutOpen(gwmsg_client_t *client, int host_id)
{
	printf("------------------------------------- \n");
	printf("Call gpsSoutOpen\n");
	return gpsSoutOpen(client, host_id);
}

/***********************************************************************************************************
*Function Name: GPS_GetPdlTable()
*Attributes:
*client     IN     Client identifier
**offset    OUT     Offset of the PDL Information Structure arrays
**num       OUT     The number of structures (arrays)
*Description: This function obtains information of the installed PDL.
************************************************************************************************************/
int GPS_GetPdlTable(gwmsg_client_t *client, long *pdl_offset, int *pdl_num)
{
	printf("------------------------------------- \n");
	printf("Call gpsGetPdlTable\n");
	return gpsGetPdlTable(client, pdl_offset, pdl_num);
}

/***********************************************************************************************************
*Function Name: GPS_GetPrtStatus2()
*Attributes:
*client     IN    Client identifier
*prtstatus  OUT    Printer Status Information Structure
*notify     IN    Enable/disable receiving event notification whenever printer status changes.
*result     OUT    Return value (0: Successful, -1: Failed)
*Description: This function obtains printer status information.
************************************************************************************************************/
int GPS_GetPrtStatus2(gwmsg_client_t *client, gps_prtstatus2_t *prtStatus, int prt_notify, int *prt_res)
{
	printf("------------------------------------- \n");
	printf("Call gpsGetPrtStatus2\n");
	return gpsGetPrtStatus2(client, prtStatus, prt_notify, prt_res);
}

/***********************************************************************************************************
*Function Name: GPS_PlotPrepare()
*Attributes:
*client     IN   
*uJobid     OUT    
**Param     OUT    
*Description: 
************************************************************************************************************/
int GPS_PlotPrepare(gwmsg_client_t *client, int uJobid, gps_plotprepareparam_t *Param)
{
	printf("------------------------------------- \n");
	printf("Call gpsPlotPrepare\n");
	return 0;/* Call to gpsPlotPrepare(client, uJobid, Param); is commented
                as there is dependency on _CNF_API_gpsPlotPrepare*/
}

/***********************************************************************************************************
*Function Name: GPS_PlotOpen()
*Attributes:
*client    IN    Client identifier
*ujobid    IN    User Job ID
*openmode  IN    Open mode    
*Description:  This function obtains plotter structure for printing, and starts print process.
************************************************************************************************************/
int GPS_PlotOpen(gwmsg_client_t *client, int plotOpen_ujobid, int plotOpen_openmode)
{
	printf("------------------------------------- \n");
	printf("Call gpsPlotOpen\n");
	return gpsPlotOpen(client, plotOpen_ujobid, plotOpen_openmode);
}

/***********************************************************************************************************
*Function Name: GPS_PlotSetPageParamShm()
*Attributes:
*client         IN      Client identifier
*plotid         IN      Plotter ID
*ppageparam_shm IN      Print Page Conditions structure
*result         OUT      Return value (0: Successful, -1: Busy, -2: Failed)   
*Description:  This function sets the printing conditions for the Plotter structure
************************************************************************************************************/
int GPS_PlotSetPageParamShm(gwmsg_client_t *client, int	PlotSet_plotid, gps_pageparam_shm_t	*param, int	*PlotSet_result)
{
	printf("------------------------------------- \n");
	printf("Call gpsPlotSetPageParamShm\n");
	return 0;/* Call to gpsPlotSetPageParamShm(client, PlotSet_plotid, param, PlotSet_result); is commented as there is dependency on _CNF_API_gpsPlotSetPageParamShm */
}

/***********************************************************************************************************
*Function Name: GPS_FrameCreateEx()
*Attributes:
*client                     
*framecreate_plotid         
*pagemode2                 
*pageinfo2                    
*framecreate_result 
*Description:  
************************************************************************************************************/
int GPS_FrameCreateEx(gwmsg_client_t *client, int framecreate_plotid, const gps_pagemode2_t *pagemode2, const gps_pageinfo2_t *pageinfo2, int *framecreate_result)
{
	printf("------------------------------------- \n");
	printf("Call gpsFrameCreateEx\n");
	return gpsFrameCreateEx(client, framecreate_plotid, pagemode2, pageinfo2, framecreate_result);
}

/***********************************************************************************************************
*Function Name: GPS_FrameCreateInfoRes()
*Attributes:
*client         IN     Client identifier
*plotid         IN     Plotter ID
*pagemode       IN   Pointer to the Print Page Mode Structure
*ppageinfo      IN  Print page information
*force          IN      Form Feed flag
*pFCR           OUT       Frame creation result
*Description:  This function creates frame, and passes the information necessary to print frame.
************************************************************************************************************/
int GPS_FrameCreateInfoRes(gwmsg_client_t *client, int FCinfo_plotid, gps_pagemode_p pagemode, gps_pageinfo_t *pageinfo, int FCinfo_force, gwmsg_GpsPage_FrameCreate_Res_t	*pFCR)
{
	printf("------------------------------------- \n");
	printf("Call gpsFrameCreateInfoRes\n");
	return gpsFrameCreateInfoRes(client, FCinfo_plotid, pagemode, pageinfo, FCinfo_force, pFCR);
}

/***********************************************************************************************************
*Function Name: GPS_FrameGetBandRes()
*Attributes:
*client    IN        Client identifier
*frameid   IN        Frame ID
*bandid    IN        Band ID (ID for the frame buffer)
*planeid   IN        Plane ID
*pFGBR     OUT        Frame buffer obtained result
*Description:  This function Obtains frame buffer.
************************************************************************************************************/
int GPS_FrameGetBandRes(gwmsg_client_t *client, int	FGband_frameid, int FGband_bandid, int FGband_planeid, gwmsg_GpsPage_FrameGetBand_Res_t *pFGBR)
{
	printf("------------------------------------- \n");
	printf("Call gpsFrameGetBandRes\n");
	return gpsFrameGetBandRes(client, FGband_frameid, FGband_bandid, FGband_planeid, pFGBR);
}

/***********************************************************************************************************
*Function Name: GPS_FrameFlushBandRes()
*Attributes:
*client    IN      Client identifier
*frameid   IN      Frame ID
*bandid    IN      Band ID (assigned from 0)
*planeid   IN      Plane ID
*drawn     IN      Drawing result
*flush     IN      Flush flag
*pFFBR     OUT      Result of the ending of drawing
*Description:  This function ends drawing to the frame buffer.
************************************************************************************************************/
int GPS_FrameFlushBandRes(gwmsg_client_t *client,int FFB_frameid,int FFB_bandid,int	FFB_planeid,int	FFB_drawn,int FFB_flush,gwmsg_GpsPage_FrameFlushBand_Res_t	*pFFBR)
{
	printf("------------------------------------- \n");
	printf("Call gpsFrameFlushBandRes\n");
	return gpsFrameFlushBandRes(client, FFB_frameid, FFB_bandid, FFB_planeid, FFB_drawn, FFB_flush, pFFBR);
}

/***********************************************************************************************************
*Function Name: GPS_FramePrintInfo()
*Attributes:
*client      IN      Client identifier
*frameid 	 IN      Frame ID
*ppageinfo2  IN      Print Page Information Structure 2
*flag 		 OUT      Supported parameters
*Description:  This function Sets the information of the page to print.
************************************************************************************************************/
int GPS_FramePrintInfo(gwmsg_client_t *client, int FP_frameid, const gps_pageinfo2_t *pageinfo2, unsigned long *FP_flag)
{
	printf("------------------------------------- \n");
	printf("Call gpsFramePrintInfo\n");
	return gpsFramePrintInfo(client, FP_frameid, pageinfo2, FP_flag);
}

/***********************************************************************************************************
*Function Name: GPS_FramePrint()
*Attributes:
*client 	IN     Client identifier
*frameid 	IN     Frame ID
*ppageinfo 	IN     Print Page Information
*force 		IN     Form Feed flag
*Description:  This function prints frames.
************************************************************************************************************/
int GPS_FramePrint(gwmsg_client_t *client, int FP_frameid, const gps_pageinfo_t *pageinfo, int FP_force)
{
	printf("------------------------------------- \n");
	printf("Call gpsFramePrint\n");
	return gpsFramePrint(client, FP_frameid, pageinfo, FP_force);
}

/***********************************************************************************************************
*Function Name: GPS_FrameClose()
*Attributes:
*client     IN         Client identifier
*frameid    IN         Frame ID
*Description:  This function ends creating frames.
************************************************************************************************************/
int GPS_FrameClose(gwmsg_client_t *client, int FP_frameid)
{
	printf("------------------------------------- \n");
	printf("Call gpsFrameClose\n");
	return gpsFrameClose(client, FP_frameid);
}

/***********************************************************************************************************
*Function Name: GPS_PenvSetDefValue()
*Attributes:
*client 			IN 		Client identifier
*penv 				IN 		Environment variable table handler
*penv_var 			IN 		Environment variable ID (defined separately)
*penv_val 			IN 		Environment variable value to set
*Description:  This function sets default environment variable value
************************************************************************************************************/
int GPS_PenvSetDefValue(gwmsg_client_t *client, int penv, long penv_var, long penv_val)
{
	printf("------------------------------------- \n");
	printf("Call gpsPenvSetDefValue\n");
	return gpsPenvSetDefValue(client, penv, penv_var, penv_val);
}

/***********************************************************************************************************
*Function Name: GPS_PlotClose()
*Attributes:
*client 	IN 		Client identifier
*plotid 	IN 		Plotter ID
*Description:  This function ends print process, and frees the Plotter Structure
************************************************************************************************************/
int GPS_PlotClose(gwmsg_client_t *client, int plotid)
{
	printf("------------------------------------- \n");
	printf("Call gpsPlotClose\n");
	return gpsPlotClose(client, plotid);
}
/***********************************************************************************************************
*Function Name: GPS_SinClose()
*Attributes:
*hostbuf 	IN 		Pointer to the Host Buffer Structure retrieved by gpsSinOpen() function
*Description:  This function closes receiving buffer.
************************************************************************************************************/
int GPS_SinClose(gps_hostbuf_p hostbuf)
{
	printf("------------------------------------- \n");
	printf("Call gpsSinClose\n");
	return gpsSinClose(hostbuf);
}
/***********************************************************************************************************
*Function Name: GPS_SoutClose()
*Attributes:
*hostbuf 	IN 		Pointer to Host Buffer Structure obtained by gpsSoutOpen() function.
*Description:  This function closes the sending buffer
************************************************************************************************************/
int GPS_SoutClose(gps_hostbuf_p hostbuf)
{
	printf("------------------------------------- \n");
	printf("Call gpsSoutClose\n");
	return gpsSoutClose(hostbuf);
}
/***********************************************************************************************************
*Function Name: GPS_InterpFinishProcData()
*Attributes:
*client 	IN    Client identifier
*ujobid 	IN    User Job ID
*fin 		IN    End status
*uel_found 	IN    Set 1 if UEL is detected and read from the host buffer. Set 0 if UEL is not detected
*Description:  Interpreter notifies GPS the end of PDL data processing
************************************************************************************************************/
void GPS_InterpFinishProcData(gwmsg_client_t *client, int ujobid, int fin, int uel_found)
{
	printf("------------------------------------- \n");
	printf("Call gpsInterpFinishProcData\n");
	return gpsInterpFinishProcData(client, ujobid, fin, uel_found);
}
/***********************************************************************************************************
*Function Name: GPS_Close()
*Attributes:
*client   IN   Client identifier
*shm_addr IN Shared memory address
*Description: This function closes GPS as the client connecting to GPS.
************************************************************************************************************/
void GPS_Close(gwmsg_client_t *client, void *shm_addr)
{
   printf("------------------------------------- \n");   
   printf("Call gpsClose\n");
	gpsClose(client, shm_addr); 
}
