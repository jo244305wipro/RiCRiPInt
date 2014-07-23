/* $HopeName: HQNlibopenssl!crypto:asn1:asn1_err.c(EBDSDK_P.1) $ */
/* crypto/asn1/asn1_err.c */
/* ====================================================================
 * Copyright (c) 1999-2004 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

/* NOTE: this file was auto generated by the mkerr.pl script: any changes
 * made to it will be overwritten when the script next updates this file,
 * only reason strings will be preserved.
 */

#include <stdio.h>
#include <openssl/err.h>
#include <openssl/asn1.h>

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR
static ERR_STRING_DATA ASN1_str_functs[]=
	{
{ERR_PACK(0,ASN1_F_A2D_ASN1_OBJECT,0),	"a2d_ASN1_OBJECT"},
{ERR_PACK(0,ASN1_F_A2I_ASN1_ENUMERATED,0),	"a2i_ASN1_ENUMERATED"},
{ERR_PACK(0,ASN1_F_A2I_ASN1_INTEGER,0),	"a2i_ASN1_INTEGER"},
{ERR_PACK(0,ASN1_F_A2I_ASN1_STRING,0),	"a2i_ASN1_STRING"},
{ERR_PACK(0,ASN1_F_ASN1_BIT_STRING_SET_BIT,0),	"ASN1_BIT_STRING_set_bit"},
{ERR_PACK(0,ASN1_F_ASN1_CHECK_TLEN,0),	"ASN1_CHECK_TLEN"},
{ERR_PACK(0,ASN1_F_ASN1_COLLATE_PRIMITIVE,0),	"ASN1_COLLATE_PRIMITIVE"},
{ERR_PACK(0,ASN1_F_ASN1_COLLECT,0),	"ASN1_COLLECT"},
{ERR_PACK(0,ASN1_F_ASN1_D2I_BIO,0),	"ASN1_d2i_bio"},
{ERR_PACK(0,ASN1_F_ASN1_D2I_EX_PRIMITIVE,0),	"ASN1_D2I_EX_PRIMITIVE"},
{ERR_PACK(0,ASN1_F_ASN1_D2I_FP,0),	"ASN1_d2i_fp"},
{ERR_PACK(0,ASN1_F_ASN1_DIGEST,0),	"ASN1_digest"},
{ERR_PACK(0,ASN1_F_ASN1_DO_ADB,0),	"ASN1_DO_ADB"},
{ERR_PACK(0,ASN1_F_ASN1_DUP,0),	"ASN1_dup"},
{ERR_PACK(0,ASN1_F_ASN1_ENUMERATED_SET,0),	"ASN1_ENUMERATED_set"},
{ERR_PACK(0,ASN1_F_ASN1_ENUMERATED_TO_BN,0),	"ASN1_ENUMERATED_to_BN"},
{ERR_PACK(0,ASN1_F_ASN1_GENERALIZEDTIME_SET,0),	"ASN1_GENERALIZEDTIME_set"},
{ERR_PACK(0,ASN1_F_ASN1_GET_OBJECT,0),	"ASN1_get_object"},
{ERR_PACK(0,ASN1_F_ASN1_HEADER_NEW,0),	"ASN1_HEADER_new"},
{ERR_PACK(0,ASN1_F_ASN1_I2D_BIO,0),	"ASN1_i2d_bio"},
{ERR_PACK(0,ASN1_F_ASN1_I2D_FP,0),	"ASN1_i2d_fp"},
{ERR_PACK(0,ASN1_F_ASN1_INTEGER_SET,0),	"ASN1_INTEGER_set"},
{ERR_PACK(0,ASN1_F_ASN1_INTEGER_TO_BN,0),	"ASN1_INTEGER_to_BN"},
{ERR_PACK(0,ASN1_F_ASN1_ITEM_EX_D2I,0),	"ASN1_ITEM_EX_D2I"},
{ERR_PACK(0,ASN1_F_ASN1_ITEM_NEW,0),	"ASN1_item_new"},
{ERR_PACK(0,ASN1_F_ASN1_MBSTRING_COPY,0),	"ASN1_mbstring_copy"},
{ERR_PACK(0,ASN1_F_ASN1_OBJECT_NEW,0),	"ASN1_OBJECT_new"},
{ERR_PACK(0,ASN1_F_ASN1_PACK_STRING,0),	"ASN1_pack_string"},
{ERR_PACK(0,ASN1_F_ASN1_PBE_SET,0),	"ASN1_PBE_SET"},
{ERR_PACK(0,ASN1_F_ASN1_SEQ_PACK,0),	"ASN1_seq_pack"},
{ERR_PACK(0,ASN1_F_ASN1_SEQ_UNPACK,0),	"ASN1_seq_unpack"},
{ERR_PACK(0,ASN1_F_ASN1_SIGN,0),	"ASN1_sign"},
{ERR_PACK(0,ASN1_F_ASN1_STRING_SET,0),	"ASN1_STRING_set"},
{ERR_PACK(0,ASN1_F_ASN1_STRING_TABLE_ADD,0),	"ASN1_STRING_TABLE_add"},
{ERR_PACK(0,ASN1_F_ASN1_STRING_TYPE_NEW,0),	"ASN1_STRING_type_new"},
{ERR_PACK(0,ASN1_F_ASN1_TEMPLATE_D2I,0),	"ASN1_TEMPLATE_D2I"},
{ERR_PACK(0,ASN1_F_ASN1_TEMPLATE_EX_D2I,0),	"ASN1_TEMPLATE_EX_D2I"},
{ERR_PACK(0,ASN1_F_ASN1_TEMPLATE_NEW,0),	"ASN1_TEMPLATE_NEW"},
{ERR_PACK(0,ASN1_F_ASN1_TIME_SET,0),	"ASN1_TIME_set"},
{ERR_PACK(0,ASN1_F_ASN1_TYPE_GET_INT_OCTETSTRING,0),	"ASN1_TYPE_get_int_octetstring"},
{ERR_PACK(0,ASN1_F_ASN1_TYPE_GET_OCTETSTRING,0),	"ASN1_TYPE_get_octetstring"},
{ERR_PACK(0,ASN1_F_ASN1_UNPACK_STRING,0),	"ASN1_unpack_string"},
{ERR_PACK(0,ASN1_F_ASN1_UTCTIME_SET,0),	"ASN1_UTCTIME_set"},
{ERR_PACK(0,ASN1_F_ASN1_VERIFY,0),	"ASN1_verify"},
{ERR_PACK(0,ASN1_F_BN_TO_ASN1_ENUMERATED,0),	"BN_to_ASN1_ENUMERATED"},
{ERR_PACK(0,ASN1_F_BN_TO_ASN1_INTEGER,0),	"BN_to_ASN1_INTEGER"},
{ERR_PACK(0,ASN1_F_COLLECT_DATA,0),	"COLLECT_DATA"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_BIT_STRING,0),	"D2I_ASN1_BIT_STRING"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_BOOLEAN,0),	"d2i_ASN1_BOOLEAN"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_BYTES,0),	"d2i_ASN1_bytes"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_GENERALIZEDTIME,0),	"D2I_ASN1_GENERALIZEDTIME"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_HEADER,0),	"d2i_ASN1_HEADER"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_INTEGER,0),	"D2I_ASN1_INTEGER"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_OBJECT,0),	"d2i_ASN1_OBJECT"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_SET,0),	"d2i_ASN1_SET"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_TYPE_BYTES,0),	"d2i_ASN1_type_bytes"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_UINTEGER,0),	"d2i_ASN1_UINTEGER"},
{ERR_PACK(0,ASN1_F_D2I_ASN1_UTCTIME,0),	"D2I_ASN1_UTCTIME"},
{ERR_PACK(0,ASN1_F_D2I_NETSCAPE_RSA,0),	"d2i_Netscape_RSA"},
{ERR_PACK(0,ASN1_F_D2I_NETSCAPE_RSA_2,0),	"D2I_NETSCAPE_RSA_2"},
{ERR_PACK(0,ASN1_F_D2I_PRIVATEKEY,0),	"d2i_PrivateKey"},
{ERR_PACK(0,ASN1_F_D2I_PUBLICKEY,0),	"d2i_PublicKey"},
{ERR_PACK(0,ASN1_F_D2I_X509,0),	"D2I_X509"},
{ERR_PACK(0,ASN1_F_D2I_X509_CINF,0),	"D2I_X509_CINF"},
{ERR_PACK(0,ASN1_F_D2I_X509_NAME,0),	"D2I_X509_NAME"},
{ERR_PACK(0,ASN1_F_D2I_X509_PKEY,0),	"d2i_X509_PKEY"},
{ERR_PACK(0,ASN1_F_I2D_ASN1_SET,0),	"i2d_ASN1_SET"},
{ERR_PACK(0,ASN1_F_I2D_ASN1_TIME,0),	"I2D_ASN1_TIME"},
{ERR_PACK(0,ASN1_F_I2D_DSA_PUBKEY,0),	"i2d_DSA_PUBKEY"},
{ERR_PACK(0,ASN1_F_I2D_NETSCAPE_RSA,0),	"i2d_Netscape_RSA"},
{ERR_PACK(0,ASN1_F_I2D_PRIVATEKEY,0),	"i2d_PrivateKey"},
{ERR_PACK(0,ASN1_F_I2D_PUBLICKEY,0),	"i2d_PublicKey"},
{ERR_PACK(0,ASN1_F_I2D_RSA_PUBKEY,0),	"i2d_RSA_PUBKEY"},
{ERR_PACK(0,ASN1_F_LONG_C2I,0),	"LONG_C2I"},
{ERR_PACK(0,ASN1_F_OID_MODULE_INIT,0),	"OID_MODULE_INIT"},
{ERR_PACK(0,ASN1_F_PKCS5_PBE2_SET,0),	"PKCS5_pbe2_set"},
{ERR_PACK(0,ASN1_F_X509_CINF_NEW,0),	"X509_CINF_NEW"},
{ERR_PACK(0,ASN1_F_X509_CRL_ADD0_REVOKED,0),	"X509_CRL_add0_revoked"},
{ERR_PACK(0,ASN1_F_X509_INFO_NEW,0),	"X509_INFO_new"},
{ERR_PACK(0,ASN1_F_X509_NAME_NEW,0),	"X509_NAME_NEW"},
{ERR_PACK(0,ASN1_F_X509_NEW,0),	"X509_NEW"},
{ERR_PACK(0,ASN1_F_X509_PKEY_NEW,0),	"X509_PKEY_new"},
{0,NULL}
	};

static ERR_STRING_DATA ASN1_str_reasons[]=
	{
{ASN1_R_ADDING_OBJECT                    ,"adding object"},
{ASN1_R_AUX_ERROR                        ,"aux error"},
{ASN1_R_BAD_CLASS                        ,"bad class"},
{ASN1_R_BAD_OBJECT_HEADER                ,"bad object header"},
{ASN1_R_BAD_PASSWORD_READ                ,"bad password read"},
{ASN1_R_BAD_TAG                          ,"bad tag"},
{ASN1_R_BN_LIB                           ,"bn lib"},
{ASN1_R_BOOLEAN_IS_WRONG_LENGTH          ,"boolean is wrong length"},
{ASN1_R_BUFFER_TOO_SMALL                 ,"buffer too small"},
{ASN1_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER  ,"cipher has no object identifier"},
{ASN1_R_DATA_IS_WRONG                    ,"data is wrong"},
{ASN1_R_DECODE_ERROR                     ,"decode error"},
{ASN1_R_DECODING_ERROR                   ,"decoding error"},
{ASN1_R_ENCODE_ERROR                     ,"encode error"},
{ASN1_R_ERROR_GETTING_TIME               ,"error getting time"},
{ASN1_R_ERROR_LOADING_SECTION            ,"error loading section"},
{ASN1_R_ERROR_PARSING_SET_ELEMENT        ,"error parsing set element"},
{ASN1_R_ERROR_SETTING_CIPHER_PARAMS      ,"error setting cipher params"},
{ASN1_R_EXPECTING_AN_INTEGER             ,"expecting an integer"},
{ASN1_R_EXPECTING_AN_OBJECT              ,"expecting an object"},
{ASN1_R_EXPECTING_A_BOOLEAN              ,"expecting a boolean"},
{ASN1_R_EXPECTING_A_TIME                 ,"expecting a time"},
{ASN1_R_EXPLICIT_LENGTH_MISMATCH         ,"explicit length mismatch"},
{ASN1_R_EXPLICIT_TAG_NOT_CONSTRUCTED     ,"explicit tag not constructed"},
{ASN1_R_FIELD_MISSING                    ,"field missing"},
{ASN1_R_FIRST_NUM_TOO_LARGE              ,"first num too large"},
{ASN1_R_HEADER_TOO_LONG                  ,"header too long"},
{ASN1_R_ILLEGAL_CHARACTERS               ,"illegal characters"},
{ASN1_R_ILLEGAL_NULL                     ,"illegal null"},
{ASN1_R_ILLEGAL_OPTIONAL_ANY             ,"illegal optional any"},
{ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE ,"illegal options on item template"},
{ASN1_R_ILLEGAL_TAGGED_ANY               ,"illegal tagged any"},
{ASN1_R_INTEGER_TOO_LARGE_FOR_LONG       ,"integer too large for long"},
{ASN1_R_INVALID_BMPSTRING_LENGTH         ,"invalid bmpstring length"},
{ASN1_R_INVALID_DIGIT                    ,"invalid digit"},
{ASN1_R_INVALID_SEPARATOR                ,"invalid separator"},
{ASN1_R_INVALID_TIME_FORMAT              ,"invalid time format"},
{ASN1_R_INVALID_UNIVERSALSTRING_LENGTH   ,"invalid universalstring length"},
{ASN1_R_INVALID_UTF8STRING               ,"invalid utf8string"},
{ASN1_R_IV_TOO_LARGE                     ,"iv too large"},
{ASN1_R_LENGTH_ERROR                     ,"length error"},
{ASN1_R_MISSING_EOC                      ,"missing eoc"},
{ASN1_R_MISSING_SECOND_NUMBER            ,"missing second number"},
{ASN1_R_MSTRING_NOT_UNIVERSAL            ,"mstring not universal"},
{ASN1_R_MSTRING_WRONG_TAG                ,"mstring wrong tag"},
{ASN1_R_NON_HEX_CHARACTERS               ,"non hex characters"},
{ASN1_R_NOT_ENOUGH_DATA                  ,"not enough data"},
{ASN1_R_NO_MATCHING_CHOICE_TYPE          ,"no matching choice type"},
{ASN1_R_NULL_IS_WRONG_LENGTH             ,"null is wrong length"},
{ASN1_R_ODD_NUMBER_OF_CHARS              ,"odd number of chars"},
{ASN1_R_PRIVATE_KEY_HEADER_MISSING       ,"private key header missing"},
{ASN1_R_SECOND_NUMBER_TOO_LARGE          ,"second number too large"},
{ASN1_R_SEQUENCE_LENGTH_MISMATCH         ,"sequence length mismatch"},
{ASN1_R_SEQUENCE_NOT_CONSTRUCTED         ,"sequence not constructed"},
{ASN1_R_SHORT_LINE                       ,"short line"},
{ASN1_R_STRING_TOO_LONG                  ,"string too long"},
{ASN1_R_STRING_TOO_SHORT                 ,"string too short"},
{ASN1_R_TAG_VALUE_TOO_HIGH               ,"tag value too high"},
{ASN1_R_THE_ASN1_OBJECT_IDENTIFIER_IS_NOT_KNOWN_FOR_THIS_MD,"the asn1 object identifier is not known for this md"},
{ASN1_R_TOO_LONG                         ,"too long"},
{ASN1_R_TYPE_NOT_CONSTRUCTED             ,"type not constructed"},
{ASN1_R_UNABLE_TO_DECODE_RSA_KEY         ,"unable to decode rsa key"},
{ASN1_R_UNABLE_TO_DECODE_RSA_PRIVATE_KEY ,"unable to decode rsa private key"},
{ASN1_R_UNEXPECTED_EOC                   ,"unexpected eoc"},
{ASN1_R_UNKNOWN_FORMAT                   ,"unknown format"},
{ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM ,"unknown message digest algorithm"},
{ASN1_R_UNKNOWN_OBJECT_TYPE              ,"unknown object type"},
{ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE          ,"unknown public key type"},
{ASN1_R_UNSUPPORTED_ANY_DEFINED_BY_TYPE  ,"unsupported any defined by type"},
{ASN1_R_UNSUPPORTED_CIPHER               ,"unsupported cipher"},
{ASN1_R_UNSUPPORTED_ENCRYPTION_ALGORITHM ,"unsupported encryption algorithm"},
{ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE      ,"unsupported public key type"},
{ASN1_R_WRONG_TAG                        ,"wrong tag"},
{ASN1_R_WRONG_TYPE                       ,"wrong type"},
{0,NULL}
	};

#endif

void ERR_load_ASN1_strings(void)
	{
	static int init=1;

	if (init)
		{
		init=0;
#ifndef OPENSSL_NO_ERR
		ERR_load_strings(ERR_LIB_ASN1,ASN1_str_functs);
		ERR_load_strings(ERR_LIB_ASN1,ASN1_str_reasons);
#endif

		}
	}
