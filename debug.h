/***********************************************
*	Filename    :debug.h
*	Author      :alex
*	Date	    :Sun Oct 28 14:19:54 2018
*	Purpose     :
*	Description :
*
***********************************************/

#ifndef	DEBUG_H
#define	DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include "ai_base.h"

#ifdef AI_DEBUG
extern volatile struct elem_t **elem_table;
extern volatile long nr_elem;
extern volatile long cap_elem;
#define	debug_init
#define debug_destroy

#define ai_info(fmt,args...)	fprintf(stdout,fmt"\n",##args)
#define ai_notice(fmt,args...)	fprintf(stdout,"NOTICE:%s\t"fmt"\n",__func__,##args)
#define ai_warning(fmt,args...)	fprintf(stdout,"WARNING:%s:%s\t"fmt"\n",__FILE__,__func__,##args)
#define ai_err(fmt,args...)		fprintf(stderr,"ERR:%s:%s:%d\t"fmt"\n",__FILE__,__func__,__LINE__,##args)
#define ai_quit(fmt,args...)	({fprintf(stderr,"QUIT:%s:%s:%d\t"fmt"\n",__FILE__,__func__,__LINE__,##args);exit(1);})

#else

extern FILE *logfile;
#define AI_LOGFILE		"ai.log"
#define debug_init		({if((logfile = fopen(AI_LOGFILE,"w+")) == NULL) {fprintf(stderr,"logfile open failed!\n");exit(1);}})
#define debug_destroy	fclose(logfile)
#define ai_info(fmt,args...)	fprintf(logfile,fmt"\n",##args)
#define ai_notice(fmt,args...)	fprintf(logfile,"NOTICE:%s\t"fmt"\n",__func__,##args)
#define ai_warning(fmt,args...)	fprintf(logfile,"WARNING:%s:%s\t"fmt"\n",__FILE__,__func__,##args)
#define ai_err(fmt,args...)		fpritnf(logfile,"ERR:%s:%s:%d\t"fmt"\n",__FILE__,__func__,__LINE__,##args)
#define ai_quit(fmt,args...)	({fprintf(logfile,"QUIT:%s:%s:%d\t"fmt"\n",__FILE__,__func__,__LINE__,##args);exit(1);})

#endif

#endif
