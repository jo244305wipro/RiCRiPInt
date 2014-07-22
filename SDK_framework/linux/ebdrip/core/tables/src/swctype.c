/** \file
 * \ingroup core
 *
 * $HopeName: COREtables!src:swctype.c(EBDSDK_P.1) $
 * $Id: src:swctype.c,v 1.10.10.1.1.1 2013/12/19 11:25:07 anon Exp $
 *
 * Copyright (C) 1991-2007 Global Graphics Software Ltd. All rights reserved.
 * Global Graphics Software Ltd. Confidential Information.
 *
 * \brief
 * Defines a virtual C locale for ScriptWorks Core RIP
 */

#include "std.h"
#include "swctype.h"
#include "tables.h"

uint8 swctype [256] = { /* a straight copy from sun-os */
/* 00 */ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
/* 08 */ 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x20, 0x20, 
/* 10 */ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
/* 18 */ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
/* 20 */ 0x88, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
/* 28 */ 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
/* 30 */ 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
/* 38 */ 0x44, 0x44, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
/* 40 */ 0x10, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 
/* 48 */ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
/* 50 */ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
/* 58 */ 0x01, 0x01, 0x01, 0x10, 0x10, 0x10, 0x10, 0x10, 
/* 60 */ 0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x02,
/* 68 */ 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
/* 70 */ 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
/* 78 */ 0x02, 0x02, 0x02, 0x10, 0x10, 0x10, 0x10, 0x20, 
/* 80 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 88 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 90 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 98 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* a0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* a8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* b0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* b8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* c0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* c8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* d0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* d8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* e0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* e8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* f0 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* f8 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static int8 rhex_table[257] = {
  /*  -1 */  -1,
  /*   0 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*   8 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  16 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  24 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  32 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  40 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  48 */   0,   1,   2,   3,   4,   5,   6,   7,
  /*  56 */   8,   9,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  64 */  -1,  10,  11,  12,  13,  14,  15,  -1,
  /*  72 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  80 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  88 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /*  96 */  -1,  10,  11,  12,  13,  14,  15,  -1,
  /* 104 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 112 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 120 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 128 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 136 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 144 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 152 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 160 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 168 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 176 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 184 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 192 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 200 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 208 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 216 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 224 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 232 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 240 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  /* 248 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1
} ;

int8 *char_to_hex_nibble = &rhex_table[1] ;

uint8 nibble_to_hex_char[16] = {
  (uint8)'0', (uint8)'1', (uint8)'2', (uint8)'3',
  (uint8)'4', (uint8)'5', (uint8)'6', (uint8)'7',
  (uint8)'8', (uint8)'9', (uint8)'A', (uint8)'B',
  (uint8)'C', (uint8)'D', (uint8)'E', (uint8)'F'
} ;

/*
Log stripped */