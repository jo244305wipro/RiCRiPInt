/**file
 * in group pcl5in
 * Contains stub implementations to update media attributes
 */
#include "mhwrapper.h"
#include "pageprint.h"
#include "omstub.h"

OMenum OMGetCurrentInt(OMenum omvar, OMenum omsystem)
{
    OMenum xres, yres, bit;
    if (omsystem == 1)
    { 
        switch(omvar)
        {
           case XRES: xres = 600; /*PCL default */
                               return xres;
                               break;
           case YRES: yres = 600; /*PCL default */
                               return yres;
                               break;
           case OMBITSPERPIXEL: bit = 2; /*check bit value*/
                               return bit;
                               break;
           default: break;
         }
      }
}

OMEnum OMGetCurrentEnum(OMenum omvar, OMenum omsystem)
{
    int afour = 26;
    int letter = 2;
    OMEnum papersource, bypasstray, frontcoverprint, binding;
    if (omsystem == 1)
    { 
        switch(omvar)
        {
              case OMPAPERSRC: papersource = 3;
                               return papersource;
                               break;
              case OMBYPASSTRAYSETTING: bypasstray = 0;
                                        return bypasstray;
                                        break;
              case OMFRONTCOVERPRINT:  frontcoverprint = 1;
			                           return frontcoverprint;
									   break;
              case OMBINDINGEDGE: binding = GetBinding();
                                  return binding;
                                  break;
              case OMTRAY1_SIZE: return afour;
			                     break;
			  case OMTRAY2_SIZE: return letter;
			                     break;
			  case OMTRAY1_MEDIATYPE:
			  case OMTRAY2_MEDIATYPE: return MEDIATYPE_PLAIN;
				                      break;
              default: break;
        }
     }
}

OMEnum OMGetDefaultEnum(OMenum omvar, OMenum omsystem)
{
    OMEnum papersource, bypasstray, frontcoverprint, binding;
    if (omsystem == 1)
    { 
        switch(omvar)
        {
              case OMPAPERSRC: papersource = 3;
                               return papersource;
                                break;
                            default: break;
        }
     }
}
bool OMGetCurrentBool(OMenum omvar, OMenum omtype)
{
    int duplex =0;
    if (omtype == 1)
    { 
        switch(omvar)
        {
            case OMAUTOTRAYCHANGE2: return FALSE; /* hardcoded */
			                        break;
			case OMTRAYSEARCHMODE: return TRUE;  /*hardcoded */
			                       break;
			case OMDUPLEX: duplex = GetDuplex(); /*duplex off*/ 
		        	               return duplex;
                                    break;
            case LONGEDGEFEED: return 1;
                               break;

            default: break;
            
        }                          
     }

     if(omtype == 2)
     {
         switch(omvar)
         {
             case LONGEDGEFEED: return TRUE;
                                break;
             default: break;
          }
      }
}


int PRpapertable(PAPERINFO *paper, int xres, int yres)
{
     paper->OMcode = PAPERSIZE_A4;
     /*paper->OMcode = PAPERSIZE_LETTER;*/
     return 0;
}

int  PRpaperinfo(PAPERCODE paper, int xres, int yres)
{
    return PAPERSIZE_A4;
}

