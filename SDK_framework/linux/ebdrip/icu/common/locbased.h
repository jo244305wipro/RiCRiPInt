/* $HopeName: HQNlibicu_3_4!common:locbased.h(EBDSDK_P.1) $ */
/*
**********************************************************************
* Copyright (c) 2004, International Business Machines
* Corporation and others.  All Rights Reserved.
**********************************************************************
* Author: Alan Liu
* Created: January 16 2004
* Since: ICU 2.8
**********************************************************************
*/
#ifndef LOCBASED_H
#define LOCBASED_H

#include "unicode/locid.h"
#include "unicode/uobject.h"

/**
 * Macro to declare a locale LocaleBased wrapper object for the given
 * object, which must have two members named `validLocale' and
 * `actualLocale'.
 */
#define U_LOCALE_BASED(varname, objname) \
  LocaleBased varname((objname).validLocale, (objname).actualLocale);

U_NAMESPACE_BEGIN

/**
 * A utility class that unifies the implementation of getLocale() by
 * various ICU services.  This class is likely to be removed in the
 * ICU 3.0 time frame in favor of an integrated approach with the
 * services framework.
 * @since ICU 2.8
 */
class U_COMMON_API LocaleBased : public UMemory {

 public:

    /**
     * Construct a LocaleBased wrapper around the two pointers.  These
     * will be aliased for the lifetime of this object.
     */
    inline LocaleBased(char* validAlias, char* actualAlias);

    /**
     * Construct a LocaleBased wrapper around the two const pointers.
     * These will be aliased for the lifetime of this object.
     */
    inline LocaleBased(const char* validAlias, const char* actualAlias);

    /**
     * Return locale meta-data for the service object wrapped by this
     * object.  Either the valid or the actual locale may be
     * retrieved.
     * @param type either ULOC_VALID_LOCALE or ULOC_ACTUAL_LOCALE
     * @param status input-output error code
     * @return the indicated locale
     */
    Locale getLocale(ULocDataLocaleType type, UErrorCode& status) const;

    /**
     * Return the locale ID for the service object wrapped by this
     * object.  Either the valid or the actual locale may be
     * retrieved.
     * @param type either ULOC_VALID_LOCALE or ULOC_ACTUAL_LOCALE
     * @param status input-output error code
     * @return the indicated locale ID
     */
    const char* getLocaleID(ULocDataLocaleType type, UErrorCode& status) const;

    /**
     * Set the locale meta-data for the service object wrapped by this
     * object.  If either parameter is zero, it is ignored.
     * @param valid the ID of the valid locale
     * @param actual the ID of the actual locale
     */
    void setLocaleIDs(const char* valid, const char* actual);

 private:

    char* valid;

    char* actual;
};

inline LocaleBased::LocaleBased(char* validAlias, char* actualAlias) :
    valid(validAlias), actual(actualAlias) {
}

inline LocaleBased::LocaleBased(const char* validAlias,
                                const char* actualAlias) :
    // ugh: cast away const
    valid((char*)validAlias), actual((char*)actualAlias) {
}

U_NAMESPACE_END

#endif

/* Log stripped */