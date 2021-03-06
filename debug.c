/***********************************************
*	Filename    :debug.c
*	Author      :alex
*	Date	    :Sun Oct 28 15:20:10 2018
*	Purpose     :
*	Description :
*
***********************************************/
#include "debug.h"
#include "alloc.h"
#include "ai_base.h"
#include "types.h"

#ifdef AI_DEBUG
/*elem_table will expand when needed but never release memory*/
volatile struct elem_t **elem_table = NULL;
volatile long nr_elem=0;
volatile long cap_elem=0;
int elem_table_add(struct elem_t *new_elem)
{
	if(unlikely(!(cap_elem&(cap_elem-1)))){
		/*if there is not enough memory to store elem,realloc more(*2) memory*/
		elem_table = ai_realloc(elem_table,cap_elem*BYTES_PER_LONG<<1);
		if(unlikely(elem_table == NULL)){
			ai_quit("ai_realloc failed!");
		}
		/*clear bytes just alloced*/
		memset(elem_table+cap_elem,0,cap_elem*BYTES_PER_LONG);
		cap_elem <<= 1;
	}

	long i;
	/*find the first empty elem*/
	for(i = 0; i < cap_elem && elem_table[i] != NULL; ++i)
		;
	if(unlikely(i == cap_elem))
		ai_quit("unexpected error!");
	elem_table[i] = new_elem;
	++nr_elem;
	link(new_elem);

	ai_info("new elem added");
	return 0;
}
int elem_table_del(struct elem_t *del_elem)
{
	/*find the elem from the beginning*/
	long i;
	for(i = 0; i < cap_elem && elem_table[i] != del_elem; ++i)
		;
	if(unlikely(i == cap_elem))
		return ENOELEM;
	elem_table[i]=NULL;
	--nr_elem;
	unlink(del_elem);
	return 0;

}
#else
FILE *logfile;
#endif



