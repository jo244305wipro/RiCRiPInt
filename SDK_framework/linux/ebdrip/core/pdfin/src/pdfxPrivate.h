/** \file
 * \ingroup pdfin
 *
 * $HopeName: SWpdf!src:pdfxPrivate.h(EBDSDK_P.1) $
 * $Id: src:pdfxPrivate.h,v 1.18.2.1.1.1 2013/12/19 11:25:14 anon Exp $
 *
 * Copyright (C) 2007-2010 Global Graphics Software Ltd. All rights reserved.
 * Global Graphics Software Ltd. Confidential Information.
 *
 * \brief
 * Private Types and Interfaces for PDF/X conformance testing - these should
 * only be accessed by the PDF/X checking files.
 */

#ifndef __pdfxPrivate_h__
#define __pdfxPrivate_h__

#include "swpdf.h"

/* --Public Constants-- */

/* Once the actual version of the PDF file is known, the user specified
acceptance level ends up as one of these enforcement levels, which are bitmask
values, where zero indicates that no enforcement is required.
Note that PDF_ENFORCE_UNKNOWN should be set beyond the last useful value. */
#define PDF_ENFORCE_X1a_2001       (1)
#define PDF_ENFORCE_X3_2002        (1 << 1)
#define PDF_ENFORCE_X1a_2003       (1 << 2)
#define PDF_ENFORCE_X3_2003        (1 << 3)
#define PDF_ENFORCE_X4             (1 << 4)
#define PDF_ENFORCE_X4p            (1 << 5)
#define PDF_ENFORCE_X5g            (1 << 6)
#define PDF_ENFORCE_X5n            (1 << 7)
#define PDF_ENFORCE_X5pg           (1 << 8)

#define PDF_ENFORCE_UNKNOWN 1024

/* Particular PDF/X checks, throughout the code, can apply to one or more PDF/X
versions. The following bit-masks assist in that. */
#define PDF_CHECK_X1a_2001_ONLY (PDF_ENFORCE_X1a_2001)
#define PDF_CHECK_X1a_2003_ONLY (PDF_ENFORCE_X1a_2003)
#define PDF_CHECK_X3_2002_ONLY (PDF_ENFORCE_X3_2002)
#define PDF_CHECK_X3_2003_ONLY (PDF_ENFORCE_X3_2003)
#define PDF_CHECK_ANY_X1a (PDF_ENFORCE_X1a_2001 | PDF_ENFORCE_X1a_2003)
#define PDF_CHECK_ANY_X3 (PDF_ENFORCE_X3_2002 | PDF_ENFORCE_X3_2003)
#define PDF_CHECK_X1a_AND_X3 (PDF_CHECK_ANY_X1a | PDF_CHECK_ANY_X3)
#define PDF_CHECK_ANY_X4 (PDF_ENFORCE_X4 | PDF_ENFORCE_X4p)
#define PDF_CHECK_ANY_X5 (PDF_ENFORCE_X5g | PDF_ENFORCE_X5n | PDF_ENFORCE_X5pg)

#define PDF_CHECK_TRANSPARENCY_FORBIDDEN (PDF_CHECK_X1a_AND_X3)
#define PDF_CHECK_COLORMANAGEMENT_REQUIRED \
  (PDF_CHECK_ANY_X3 | PDF_CHECK_ANY_X4 | PDF_CHECK_ANY_X5)
#define PDF_CHECK_POST_X3 (PDF_CHECK_ANY_X4)
#define PDF_CHECK_EXTERNAL_GRAPHICS_ALLOWED (PDF_ENFORCE_X5g | PDF_ENFORCE_X5pg)
#define PDF_CHECK_EXTERNAL_PROFILE_ALLOWED \
  (PDF_ENFORCE_X4p | PDF_ENFORCE_X5n | PDF_ENFORCE_X5pg)

/* These macros allow you to check the PDF version that the currently enforced
PDF/X version is based on. */
#define PDFX_1_3_BASED (PDF_ENFORCE_X1a_2001 | PDF_ENFORCE_X3_2002)
#define PDFX_1_4_BASED (PDF_ENFORCE_X1a_2003 | PDF_ENFORCE_X3_2003)
#define PDFX_1_6_BASED (PDF_ENFORCE_X4 | PDF_ENFORCE_X4p)


/* Error Values. */
enum {
  PDFXERR_VERSION_UNKNOWN = 0,
  PDFXERR_VERSION_INCORRECT,
  PDFXERR_INFO_KEY_MISSING,
  PDFXERR_NO_PDFX_VERSION,
  PDFXERR_NO_CONFORMANCE_KEY,
  PDFXERR_UNWANTED_CONF_KEY,
  PDFXERR_BAD_CONF_KEY,
  PDFXERR_X1_NOT_SUPPORTED,
  PDFXERR_VERSION_NOT_SUPPORTED,
  PDFXERR_TITLE_KEY_MISSING,
  PDFXERR_CREATION_DATE_MISSING,
  PDFXERR_MODIFICATION_DATE_MISSING,
  PDFXERR_NO_TRAPPED_KEY,
  PDFXERR_TRAPPED_UNKNOWN,
  PDFXERR_TRAILER_ID,
  PDFXERR_ENCRYPT_KEY,
  PDFXERR_INVALID_rg_OPERATOR,
  PDFXERR_INVALID_RG_OPERATOR,
  PDFXERR_INVALID_PS_OPERATOR,
  PDFXERR_INVALID_ri_OPERATOR,
  PDFXERR_INVALID_OPERATOR,
  PDFXERR_HALFTONE_TYPE,
  PDFXERR_HTP,
  PDFXERR_TR,
  PDFXERR_TR2,
  PDFXERR_TR2_INVALID,
  PDFXERR_HALFTONENAME_KEY,
  PDFXERR_FILE_COMPRESSION,
  PDFXERR_NO_FONTDESCRIPTOR,
  PDFXERR_NO_FONTFILE,
  PDFXERR_OPI_KEY,
  PDFXERR_FILESPEC,
  PDFXERR_FILESPEC_NOT_EMBEDDED,
  PDFXERR_F_KEY_PROHIBITED,

  PDFXERR_NO_MEDIABOX,
  PDFXERR_ARTANDTRIM,
  PDFXERR_NO_ARTORTRIM,
  PDFXERR_TA_BOX_NOTIN_BLEEDBOX,
  PDFXERR_BTA_BOX_NOTIN_CROPBOX,
  PDFXERR_CBTA_BOX_NOTIN_MEDIABOX,

  PDFXERR_ANNOT_ON_PAGE,
  PDFXERR_PRINTERMARK_ANNOT_ON_PAGE,

  PDFXERR_OVERPRINT_OVERRIDDEN,
  PDFXERR_PS_XOBJECT,
  PDFXERR_INFO_TRAPPED_NOT_TRUE,
  PDFXERR_TRAPNET_FONTFAUXING,
  PDFXERR_ALTERNATE_FOR_PRINTING,
  PDFXERR_ACTIONS,
  PDFXERR_NO_OUTPUTINTENT,
  PDFXERR_MULTIPLE_GTS_PDFX,
  PDFXERR_NO_OUTPUT_CONDITION,
  PDFXERR_NO_DEST_OUTPUT_PROFILE,
  PDFXERR_BAD_REGNAME,
  PDFXERR_NO_OI_INFO_KEY,
  PDFXERR_NO_PROFILE_FILE,
  PDFXERR_NO_REG_PROFILE,

  PDFXERR_BAD_X1a_COLORSPACE,
  PDFXERR_BAD_X3_COLORSPACE,
  PDFXERR_NOT_VALID_DEFAULT_SPACE,
  PDFXERR_BASE_COLORSPACE,
  PDFXERR_ALTERNATIVE_COLORSPACE,

  PDFXERR_PRESEP,
  PDFXERR_INVALID_PERMISSIONS_DICT,
  PDFXERR_INVALID_VIEWER_PREFS_DICT,
  PDFXERR_VIEWER_PREFS_BLEEDBOX_MISSING,
  PDFXERR_ALTERNATE_PRESENTATIONS,
  PDFXERR_PRESSTEPS,
  PDFXERR_INVALID_INTENT,
  PDFXERR_XFA_KEY,
  PDFXERR_INVALID_OUTPUTCONDITION_DEVICE_CS,

  /* Optional content errors. */
  PDFXERR_OC_NAME_MISSING,
  PDFXERR_OC_AS_INVALID,

  /* OutputIntent Dictionary errors. */
  PDFXERR_UNDEFINED_RESOURCE_IN_OI,
  PDFXERR_BAD_OI_DICT_TYPE,

  /* PDF 1.4 related errors. */
  PDFXERR_REFERENCEXOBJECT,
  PDFXERR_PRINTERMARKS_NOT_IN_1_3,
  PDFXERR_1_3_BASED_USING_1_4_GSTATE,
  PDFXERR_INVALID_CONSTANT_ALPHA,
  PDFXERR_INVALID_SOFT_MASK,
  PDFXERR_INVALID_BLEND_MODE,
  PDFXERR_TRANSPARENCY_GROUP,
  PDFXERR_SOFT_MASKED_IMAGE,

  /* PDF 1.5 related errors. */
  PDFXERR_16_BIT_IMAGE,
  PDFXERR_OBJECT_STREAM,
  PDFXERR_XREF_STREAM,
  PDFXERR_OPTIONAL_CONTENT,

  /* PDF/X-4p related errors. */
  PDFXERR_URLS_MISSING,
  PDFXERR_PROFILE_REF_KEYS_MISSING,
  PDFXERR_PROFILE_REF_CONTAINS_COLORANT_TABLE,
  PDFXERR_FS_MISSING,
  PDFXERR_FS_NOT_URL,
  PDFXERR_F_MISSING,
  PDFXERR_EXTRA_KEYS_IN_URL,
  PDFXERR_EXTERNAL_PROFILE_FORBIDDEN,
  PDFXERR_INTERNAL_AND_EXTERNAL_PROFILES,
  PDFXERR_EXTERNAL_PROFILE_NON_DICTIONARY_URL,
  PDFXERR_EXTERNAL_PROFILE_INVALID_CHECKSUM,
  PDFXERR_EXTERNAL_PROFILE_CHECKSUM_DIFFERS,

  /* PDF/X-5 errors. */
  PDFXERR_TRAILER_ID_MALFORMED,
  PDFXERR_MISSING_REF_ID,
  PDFXERR_CANNOT_VERIFY_EXTERNAL_FILE_ID,
  PDFXERR_EXTERNAL_FILE_IDS_DIFFER,
  PDFXERR_MISSING_REF_METADATA,
  PDFXERR_CANNOT_VERIFY_EXTERNAL_FILE_METADATA,
  PDFXERR_EXTERNAL_FILE_METADATA_DIFFER,

  NUM_PDFXERRS,
};

/**
 * Print the specified message, prefixed with the standard PDF/X prefix string.
 */
void pdfxPrint(PDF_IXC_PARAMS *ixc, uint8* message);

/* For PDF/X checks, reports the given error. Once an error has been reported
it is impeded from being reported again. */
Bool pdfxError(PDF_IXC_PARAMS *ixc, int32 error);


#endif

/* Log stripped */

