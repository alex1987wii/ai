/***********************************************
*	Filename    :errno.h
*	Author      :alex
*	Date	    :Sun Oct 28 20:41:56 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	ERRNO_H
#define	ERRNO_H

#include <errno.h>

#define AI_ERRNO_START		256
#define AI_ERRNO_NUM		512
#define AI_ERRNO_END		(AI_ERRNO_START+AI_ERRNO_NUM)

/*AI errno definition */
#define ENOELEM				(AI_ERRNO_START)

const char *ai_strerror(int errno);

#endif
