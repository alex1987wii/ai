/***********************************************
*	Filename    :alloc.h
*	Author      :alex
*	Date	    :Sun Oct 28 17:42:19 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	ALLOC_H
#define	ALLOC_H
#include <stdlib.h>

#define ai_malloc(size)				malloc(arg)
#define ai_realloc(ptr,size)		realloc(ptr,size)
#define ai_calloc(nmemb,size)		calloc(nmemb,size)

#endif
