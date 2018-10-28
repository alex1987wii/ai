/***********************************************
*	Filename    :errno.c
*	Author      :alex
*	Date	    :Sun Oct 28 20:50:14 2018
*	Purpose     :
*	Description :
*
***********************************************/
#include "errno.h"
#include "debug.h"

static const char *ai_errno_list[AI_ERRNO_NUM] = {
	"elem not exsit",

};
const char *ai_strerror(int errno)
{
	if(errno < 0)
		ai_quit("errno error");
	else if(errno < AI_ERRNO_START)
		return strerror(errno);
	else if(errno < AI_ERRNO_END)
		return ai_errno_list[errno-AI_ERRNO_START];
	else
		return "unknow ai error";
}
