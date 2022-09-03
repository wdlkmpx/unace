#ifndef _APPS_INCLUDES_H_INCLUDED
#define _APPS_INCLUDES_H_INCLUDED

#include "base/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_EXE)
# ifndef APPS_EXE_DELAYLENGTH
#   define APPS_EXE_DELAYLENGTH 500
# endif
#endif

#if defined(INCL_APPS_EXE_COMMLINE)
 #include "commline.h"
#endif

#if defined(INCL_APPS_EXE_ACEFUNCS)
	#ifndef _APPS_EXE_ACEFUNCS_H_INCLUDED
	#define _APPS_EXE_ACEFUNCS_H_INCLUDED
	void    APPS_EXE_ACEFUNCS_List(BOOL Verbose);
	#endif
#endif

#if defined(INCL_APPS_EXE_CONVERT)
   #include "convert/convert.h"
#endif

#if defined(INCL_APPS_EXE_INPUT)
   #include "input/input.h"
#endif

#if defined(INCL_APPS_EXE_MESSAGES)
   #include "messages/messages.h"
#endif

#if defined(INCL_APPS_EXE_OUTPTERR)
	#ifndef _APPS_EXE_OUTPTERR_H_INCLUDED
	#define _APPS_EXE_OUTPTERR_H_INCLUDED
	void    APPS_EXE_OUTPTERR_OutputError(PCHAR TextStr1, PCHAR TextStr2);
	#endif
#endif

#if defined(INCL_APPS_EXE_OUTPUT)
   #include "output/output.h"
#endif

#if defined(INCL_APPS_EXE_STATE)
   #include "state/state.h"
#endif

#if defined(INCL_APPS_UNACE_EXE_COMMLINE) || defined(INCL_APPS_UNACE_EXE_COMMLINE_EXCLUSIVE)
       #include "commline.h"
#endif

#if defined(INCL_APPS_UNACE_EXE)
       #include "main.h"
#endif


#endif
