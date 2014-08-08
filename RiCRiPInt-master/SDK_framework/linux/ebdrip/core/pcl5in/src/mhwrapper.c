/**file
 * in group pcl5in
 * Contains wrapper implementations to update media attributes
 */

#include "mhwrapper.h"
#include "omstub.h"
#include "pcl5context.h"
PCL5Context *pcl5_ctxt;
int mediatype, pagesize, orientation, papersource, pagewidth, pagelength, custompagewidth, custompagelength;

static void CurrentContext()
{
    pcl5_ctxt = pcl5_current_context();
}

void SetMediaType(uint32 media)
{
    mediatype = media;
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        page_ctrl_info->media_type = media;
    }
    
}
void SetPaperSource(int tray)
{
    papersource = tray;
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        page_ctrl_info->paper_source = tray;
    }
}
int GetMediaType()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->media_type;
    }
}

OMenum GetPaperSource()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->paper_source;
    }
}

Uint32 GetPageSize()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->page_size;
    }
}

void SetPageSize(int size)
{
    pagesize = size;
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        page_ctrl_info->page_size = size;
    }
}

Uint32 GetCustomPageWidth()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->custom_page_width;
    }    
}

Uint32 GetCustomPageHeight()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->custom_page_length;
    }
}

Uint32 GetPageWidth()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->page_width;
    }
}

Uint32 GetPageHeight()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return  page_ctrl_info->page_length;
    }
}

Uint32 GetBinding()
{
    CurrentContext();
    JobCtrlInfo *job_ctrl_info = NULL;
    job_ctrl_info = get_job_ctrl_info(pcl5_ctxt);
    if(job_ctrl_info != NULL)
    {
	    return job_ctrl_info->binding;
    }
}

Uint32 GetDuplex()
{
    CurrentContext();
    JobCtrlInfo *job_ctrl_info = NULL;
    job_ctrl_info = get_job_ctrl_info(pcl5_ctxt);
    if(job_ctrl_info != NULL)
    {
	    return job_ctrl_info->duplex;
    }
}

int32 GetOrientation()
{
    CurrentContext();
    PageCtrlInfo *page_ctrl_info = NULL;
    page_ctrl_info = get_page_ctrl_info(pcl5_ctxt);
    if(page_ctrl_info != NULL)
    {
        return page_ctrl_info->orientation;
    }
}

int32 GetQualityMode()
{
  return 0;
}

int getMhPageSize()
{
    return pagesize;

}
int getMhMediaType()
{
    return mediatype;

}
int getMhPaperSource()
{
    return papersource;
}
