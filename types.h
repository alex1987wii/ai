/***********************************************
*	Filename    :types.h
*	Author      :alex
*	Date	    :Sun Oct 28 16:06:36 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	TYPES_H
#define	TYPES_H

#include "config.h"
#ifndef BITS_PER_LONG
#error "BITS_PER_LONG undefined"
#elif (BITS_PER_LONG == 32)
typedef long s32;
typedef unsigned long u32;
typedef long long s64;
typedef unsigned long long u64;
#elif (BITS_PER_LONG == 64)
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
#else
#error "BITS_PER_LONG unrecognized"
#endif//BITS_PER_LONG

typedef char s8;
typedef unsigned char u8;
typedef short int s16;
typedef unsigned short u16;

#endif
