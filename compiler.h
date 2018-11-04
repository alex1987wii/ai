/***********************************************
*	Filename    :compiler.h
*	Author      :alex
*	Date	    :Sun Oct 28 15:31:56 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	COMPILER_H
#define	COMPILER_H

#ifdef __GNUC__

#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)

/* Optimization barrier */
#ifndef barrier
# define barrier() __memory_barrier()
#endif

#else

#define likely(x)		x
#define unlikely(x)		x
#define barrier()

#endif //__GNUC__
#endif
