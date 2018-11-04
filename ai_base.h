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
#include "compiler.h"
#include "errno.h"

enum ai_type_t{
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
	T_KELEM,
	T_AIELEM,
	T_USERELEM,	/*is this necessary? */
	T_USER,

};
struct elem_t{
	u8 type;
	u8 extern_type;	/*const, static, pointer,array,etc..*/
	u8 member_structure; /*array,list,doublelist,tree,rbtree,graph,etc..*/
	u8 nr_member;
	volatile u32 nlink;
	struct elem_t *parent_entry;
	struct elem_t *member_entry;
	long extern_data;
};
#warning "there is a bug here"
/*i have not code for this function yet,but other files need them,so define them,let compiler shut up */
#define link(elem)		++elem->nlink
#define unlink(elem)	--elem->nlink//bug??
#define show_elem(elem)
#endif
