/***********************************************
*	Filename    :ai_base.h
*	Author      :alex
*	Date	    :Sun Oct 28 16:01:30 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	AI_BASE_H
#define	AI_BASE_H


#include "config.h"
#include "types.h"
#include "complier.h"
#include "errno.h"

enum _builtin_type_t{
	T_NONE=0,
	T_CHAR,
	T_UCHAR,
	T_S8,
	T_U8,
	T_WCHAR,
	T_UWCHAR,
	T_S16,
	T_U16,
	T_S32,
	T_U32,
	T_FLOAT,
	T_DOUBLE,
	T_S64,
	T_U64,
};
struct elem_t{
	long type;
	long nr_member;
	volatile long nlink;
	struct elem_t *member_entry;
};
#warning "there is a bug here"
/*i have not code for this function yet,but other files need them,so define them,let complier shut up */
#define link(elem)		++elem->nlink
#define unlink(elem)	--elem->nlink//bug??
#define show_elem(elem)
#endif
