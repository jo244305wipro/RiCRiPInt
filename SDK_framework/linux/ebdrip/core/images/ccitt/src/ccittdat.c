/** \file
 * \ingroup ccitt
 *
 * $HopeName: COREccitt!src:ccittdat.c(EBDSDK_P.1) $
 *
 * Copyright (C) 1991-2007 Global Graphics Software Ltd. All rights reserved.
 * Global Graphics Software Ltd. Confidential Information.
 *
 * \brief
 * Data tables used for CCITT fax image decompression
 */


/* ccittdat.c */

#include "core.h"
#include "ccitt.h"
#include "ccittdat.h"

TERMCODE white_terminators[] = {
  { 8 , 0x35 ,  0 } ,
  { 6 , 0x07 ,  1 } ,
  { 4 , 0x07 ,  2 } ,
  { 4 , 0x08 ,  3 } ,
  { 4 , 0x0b ,  4 } ,
  { 4 , 0x0c ,  5 } ,
  { 4 , 0x0e ,  6 } ,
  { 4 , 0x0f ,  7 } ,
  { 5 , 0x13 ,  8 } ,
  { 5 , 0x14 ,  9 } ,
  { 5 , 0x07 , 10 } ,
  { 5 , 0x08 , 11 } ,
  { 6 , 0x08 , 12 } ,
  { 6 , 0x03 , 13 } ,
  { 6 , 0x34 , 14 } ,
  { 6 , 0x35 , 15 } ,
  { 6 , 0x2a , 16 } ,
  { 6 , 0x2b , 17 } ,
  { 7 , 0x27 , 18 } ,
  { 7 , 0x0c , 19 } ,
  { 7 , 0x08 , 20 } ,
  { 7 , 0x17 , 21 } ,
  { 7 , 0x03 , 22 } ,
  { 7 , 0x04 , 23 } ,
  { 7 , 0x28 , 24 } ,
  { 7 , 0x2b , 25 } ,
  { 7 , 0x13 , 26 } ,
  { 7 , 0x24 , 27 } ,
  { 7 , 0x18 , 28 } ,
  { 8 , 0x02 , 29 } ,
  { 8 , 0x03 , 30 } ,
  { 8 , 0x1a , 31 } ,
  { 8 , 0x1b , 32 } ,
  { 8 , 0x12 , 33 } ,
  { 8 , 0x13 , 34 } ,
  { 8 , 0x14 , 35 } ,
  { 8 , 0x15 , 36 } ,
  { 8 , 0x16 , 37 } ,
  { 8 , 0x17 , 38 } ,
  { 8 , 0x28 , 39 } ,
  { 8 , 0x29 , 40 } ,
  { 8 , 0x2a , 41 } ,
  { 8 , 0x2b , 42 } ,
  { 8 , 0x2c , 43 } ,
  { 8 , 0x2d , 44 } ,
  { 8 , 0x04 , 45 } ,
  { 8 , 0x05 , 46 } ,
  { 8 , 0x0a , 47 } ,
  { 8 , 0x0b , 48 } ,
  { 8 , 0x52 , 49 } ,
  { 8 , 0x53 , 50 } ,
  { 8 , 0x54 , 51 } ,
  { 8 , 0x55 , 52 } ,
  { 8 , 0x24 , 53 } ,
  { 8 , 0x25 , 54 } ,
  { 8 , 0x58 , 55 } ,
  { 8 , 0x59 , 56 } ,
  { 8 , 0x5a , 57 } ,
  { 8 , 0x5b , 58 } ,
  { 8 , 0x4a , 59 } ,
  { 8 , 0x4b , 60 } ,
  { 8 , 0x32 , 61 } ,
  { 8 , 0x33 , 62 } ,
  { 8 , 0x34 , 63 } ,
  {-1 ,   -1 , -1 } 
} ;

TERMCODE black_terminators[] = {
  {  10 , 0x37 ,  0 } ,
  {   3 , 0x02 ,  1 } ,
  {   2 , 0x03 ,  2 } ,
  {   2 , 0x02 ,  3 } ,
  {   3 , 0x03 ,  4 } ,
  {   4 , 0x03 ,  5 } ,
  {   4 , 0x02 ,  6 } ,
  {   5 , 0x03 ,  7 } ,
  {   6 , 0x05 ,  8 } ,
  {   6 , 0x04 ,  9 } ,
  {   7 , 0x04 , 10 } ,
  {   7 , 0x05 , 11 } ,
  {   7 , 0x07 , 12 } ,
  {   8 , 0x04 , 13 } ,
  {   8 , 0x07 , 14 } ,
  {   9 , 0x18 , 15 } ,
  {  10 , 0x17 , 16 } ,
  {  10 , 0x18 , 17 } ,
  {  10 , 0x08 , 18 } ,
  {  11 , 0x67 , 19 } ,
  {  11 , 0x68 , 20 } ,
  {  11 , 0x6c , 21 } ,
  {  11 , 0x37 , 22 } ,
  {  11 , 0x28 , 23 } ,
  {  11 , 0x17 , 24 } ,
  {  11 , 0x18 , 25 } ,
  {  12 , 0xca , 26 } ,
  {  12 , 0xcb , 27 } ,
  {  12 , 0xcc , 28 } ,
  {  12 , 0xcd , 29 } ,
  {  12 , 0x68 , 30 } ,
  {  12 , 0x69 , 31 } ,
  {  12 , 0x6a , 32 } ,
  {  12 , 0x6b , 33 } ,
  {  12 , 0xd2 , 34 } ,
  {  12 , 0xd3 , 35 } ,
  {  12 , 0xd4 , 36 } ,
  {  12 , 0xd5 , 37 } ,
  {  12 , 0xd6 , 38 } ,
  {  12 , 0xd7 , 39 } ,
  {  12 , 0x6c , 40 } ,
  {  12 , 0x6d , 41 } ,
  {  12 , 0xda , 42 } ,
  {  12 , 0xdb , 43 } ,
  {  12 , 0x54 , 44 } ,
  {  12 , 0x55 , 45 } ,
  {  12 , 0x56 , 46 } ,
  {  12 , 0x57 , 47 } ,
  {  12 , 0x64 , 48 } ,
  {  12 , 0x65 , 49 } ,
  {  12 , 0x52 , 50 } ,
  {  12 , 0x53 , 51 } ,
  {  12 , 0x24 , 52 } ,
  {  12 , 0x37 , 53 } ,
  {  12 , 0x38 , 54 } ,
  {  12 , 0x27 , 55 } ,
  {  12 , 0x28 , 56 } ,
  {  12 , 0x58 , 57 } ,
  {  12 , 0x59 , 58 } ,
  {  12 , 0x2b , 59 } ,
  {  12 , 0x2c , 60 } ,
  {  12 , 0x5a , 61 } ,
  {  12 , 0x66 , 62 } ,
  {  12 , 0x67 , 63 } ,
  {  -1 , -1 , -1 } 
} ;

TERMCODE white_makeup_codes[] = {
  {  5 , 0x1b , 64 } ,
  {  5 , 0x12 , 128 } ,
  {  6 , 0x17 , 192 } ,
  {  7 , 0x37 , 256 } ,
  {  8 , 0x36 , 320 } ,
  {  8 , 0x37 , 384 } ,
  {  8 , 0x64 , 448 } ,
  {  8 , 0x65 , 512 } ,
  {  8 , 0x68 , 576 } ,
  {  8 , 0x67 , 640 } ,
  {  9 , 0xcc , 704 } ,
  {  9 , 0xcd , 768 } ,
  {  9 , 0xd2 , 832 } ,
  {  9 , 0xd3 , 896 } ,
  {  9 , 0xd4 , 960 } ,
  {  9 , 0xd5 , 1024 } ,
  {  9 , 0xd6 , 1088 } ,
  {  9 , 0xd7 , 1152 } ,
  {  9 , 0xd8 , 1216 } ,
  {  9 , 0xd9 , 1280 } ,
  {  9 , 0xda , 1344 } ,
  {  9 , 0xdb , 1408 } ,
  {  9 , 0x98 , 1472 } ,
  {  9 , 0x99 , 1536 } ,
  {  9 , 0x9a , 1600 } ,
  {  6 , 0x18 , 1664 } ,
  {  9 , 0x9b , 1728 } ,
  {-1 ,   -1 ,   -1 } 
} ;

TERMCODE black_makeup_codes[] = {
  {  10 , 0x0f , 64 } ,
  {  12 , 0xc8 , 128 } ,
  {  12 , 0xc9 , 192 } ,
  {  12 , 0x5b , 256 } ,
  {  12 , 0x33 , 320 } ,
  {  12 , 0x34 , 384 } ,
  {  12 , 0x35 , 448 } ,
  {  13 , 0x6c , 512 } ,
  {  13 , 0x6d , 576 } ,
  {  13 , 0x4a , 640 } ,
  {  13 , 0x4b , 704 } ,
  {  13 , 0x4c , 768 } ,
  {  13 , 0x4d , 832 } ,
  {  13 , 0x72 , 896 } ,
  {  13 , 0x73 , 960 } ,
  {  13 , 0x74 , 1024 } ,
  {  13 , 0x75 , 1088 } ,
  {  13 , 0x76 , 1152 } ,
  {  13 , 0x77 , 1216 } ,
  {  13 , 0x52 , 1280 } ,
  {  13 , 0x53 , 1344 } ,
  {  13 , 0x54 , 1408 } ,
  {  13 , 0x55 , 1472 } ,
  {  13 , 0x5a , 1536 } ,
  {  13 , 0x5b , 1600 } ,
  {  13 , 0x64 , 1664 } ,
  {  13 , 0x65 , 1728 } ,
  {  -1 , -1 , -1 } 
} ;

TERMCODE extended_makeup_codes[] = {
  {  11 , 0x08 , 1792 } ,
  {  11 , 0x0c , 1856 } ,
  {  11 , 0x0d , 1920 } ,
  {  12 , 0x12 , 1984 } ,
  {  12 , 0x13 , 2048 } ,
  {  12 , 0x14 , 2112 } ,
  {  12 , 0x15 , 2176 } ,
  {  12 , 0x16 , 2240 } ,
  {  12 , 0x17 , 2304 } ,
  {  12 , 0x1c , 2368 } ,
  {  12 , 0x1d , 2432 } ,
  {  12 , 0x1e , 2496 } ,
  {  12 , 0x1f , 2560 } , 
  {  -1 , -1 , -1 } 
} ;

TERMCODE twod_codetable[] = {
  {  4 , 0x01 , PassModeCode } ,
  {  3 , 0x01 , HorizontalModeCode } ,
  {  7 , 0x03 , VerticalR3Code } ,
  {  6 , 0x03 , VerticalR2Code } ,
  {  3 , 0x03 , VerticalR1Code } ,
  {  1 , 0x01 , Vertical0Code } ,
  {  3 , 0x02 , VerticalL1Code } ,
  {  6 , 0x02 , VerticalL2Code } ,
  {  7 , 0x02 , VerticalL3Code } ,
  { 10 , 0x0f , Extension2DCode } ,
  { 12 , 0x0f , Extension2DCode } ,
  {  -1 , -1 , -1 }
} ;

/* End of line codes for all fax modes */
TERMCODE Data0     = {  1 , 0x00 , Data0Code } ;
TERMCODE Data1     = {  1 , 0x01 , Data1Code } ;
TERMCODE EndOfLine = { 12 , 0x01 ,   EolCode } ;

TERMCODE uncompressed_codes[] = {
  {   1 , 0x01 ,  0 } ,
  {   2 , 0x01 ,  1 } ,
  {   3 , 0x01 ,  2 } ,
  {   4 , 0x01 ,  3 } ,
  {   5 , 0x01 ,  4 } ,
  {   6 , 0x01 ,  5 } ,
  {   8 , 0x02 ,  6 } ,
  {   8 , 0x03 ,  7 } ,
  {   9 , 0x02 ,  8 } ,
  {   9 , 0x03 ,  9 } ,
  {  10 , 0x02 , 10 } ,
  {  10 , 0x03 , 11 } ,
  {  11 , 0x02 , 12 } ,
  {  11 , 0x03 , 13 } ,
  {  12 , 0x02 , 14 } ,
  {  12 , 0x03 , 15 } ,
  {  -1 ,   -1 , -1 }
} ;

/* The codes in the above table (3rd number) act as an index into the
 * table below. This then gives the number of 0's and 1's to put into
 * the image. Note that indexes >= 6 indicate repeated uncompressed codes.
 */

IMAGETABLE uncompressed_image[] = {
  { 1 , 0 } ,
  { 1 , 1 } ,
  { 1 , 2 } ,
  { 1 , 3 } ,
  { 1 , 4 } ,
  { 0 , 5 } ,
  { 0 , 0 } ,
  { 0 , 0 } ,
  { 0 , 1 } ,
  { 0 , 1 } ,
  { 0 , 2 } ,
  { 0 , 2 } ,
  { 0 , 3 } ,
  { 0 , 3 } ,
  { 0 , 4 } ,
  { 0 , 4 }
} ;


/* Log stripped */
