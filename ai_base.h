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

#define OBJ_BIT				0
#define TYPE_BIT			1
#define CONST_BIT			2
#define STATIC_BIT			3
#define POINT_BIT			4
#define ARRAY_BIT			5
#define AITYPE_BIT			6


#define NOTYPE				0 /*reserved*/
#define BUILTIN				1
#define AITYPE				2
#define USERTYPE			3

enum builtin_type_t{

	T_NONE=0,
	T_VOID,
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
};
#warning "need fix here"
/*do we add all the type here?*/
enum ai_type_t{
	/*save for T_NONE*/
	T_SET=1,
	T_FUNC,
	T_OPERATION,
	T_TYPE,
	T_STRUCTURE,
	T_PROPOSTION,
	T_NAMESPACE,
	T_EXPRESSION,
	T_RULE,
	T_RELATION,
};


#warning "need re-edit here"
struct elem_t{
	u8 type;
	u8 member_structure; /*array,list,doublelist,tree,rbtree,graph,etc..*/
	u16 extern_type;	/*const, static, pointer,array,etc..*/
	u16 nr_member;
	u16 nlink;
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
