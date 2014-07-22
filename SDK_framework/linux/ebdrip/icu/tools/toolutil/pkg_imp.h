/* $HopeName: HQNlibicu_3_4!tools:toolutil:pkg_imp.h(EBDSDK_P.1) $ */
/*
*******************************************************************************
*
*   Copyright (C) 2005, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
*******************************************************************************
*   file name:  pkg_imp.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 2005sep18
*   created by: Markus W. Scherer
*
*   Implementation definitions for data package functions in toolutil.
*/

#ifndef __PKG_IMP_H__
#define __PKG_IMP_H__

#include "unicode/utypes.h"

/*
 * Read an ICU data item with any platform type,
 * return the pointer to the UDataInfo in its header,
 * and set the lengths of the UDataInfo and of the whole header.
 * All data remains in its platform type.
 */
U_CFUNC const UDataInfo *
getDataInfo(const uint8_t *data, int32_t length,
            int32_t &infoLength, int32_t &headerLength,
            UErrorCode *pErrorCode);

#endif

/* Log stripped */
