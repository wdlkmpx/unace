#ifndef _APPS_INCLUDES_H_INCLUDED
#define _APPS_INCLUDES_H_INCLUDED

#include "base/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_EXE)                          || defined(INCL_APPS_EXE_EXCLUSIVE)
# ifndef APPS_EXE_DELAYLENGTH
#   define APPS_EXE_DELAYLENGTH 500
# endif
#endif

#if defined(INCL_APPS_EXE_COMMLINE)                 || defined(INCL_APPS_EXE_COMMLINE_EXCLUSIVE)
 #include "apps/commline.h"
#endif

#if defined(INCL_APPS_EXE_ACEFUNCS)                 || defined(INCL_APPS_EXE_ACEFUNCS_EXCLUSIVE)
	#ifndef _APPS_EXE_ACEFUNCS_H_INCLUDED
	#define _APPS_EXE_ACEFUNCS_H_INCLUDED
	void    APPS_EXE_ACEFUNCS_List(BOOL Verbose);
	#endif
#endif

#if defined(INCL_APPS_EXE_CONVERT)                  || defined(INCL_APPS_EXE_CONVERT_EXCLUSIVE)
   #include "apps/convert/convert.h"
#endif

#if defined(INCL_APPS_EXE_INPUT)                    || defined(INCL_APPS_EXE_INPUT_EXCLUSIVE)
   #include "apps/input/input.h"
#endif

  #if defined(INCL_APPS_EXE_INPUT_LINUX)              || defined(INCL_APPS_EXE_INPUT_LINUX_EXCLUSIVE)
     #include "apps/input/lin.h"
  #endif

  #if defined(INCL_APPS_EXE_INPUT_NT)                 || defined(INCL_APPS_EXE_INPUT_NT_EXCLUSIVE)
     #include "apps/input/nt.h"
  #endif

#if defined(INCL_APPS_EXE_MESSAGES)                 || defined(INCL_APPS_EXE_MESSAGES_EXCLUSIVE)
   #include "apps/messages/messages.h"
#endif

#if defined(INCL_APPS_EXE_OUTPTERR)                 || defined(INCL_APPS_EXE_OUTPTERR_EXCLUSIVE)
	#ifndef _APPS_EXE_OUTPTERR_H_INCLUDED
	#define _APPS_EXE_OUTPTERR_H_INCLUDED
	void    APPS_EXE_OUTPTERR_OutputError(PCHAR TextStr1, PCHAR TextStr2);
	#endif
#endif

#if defined(INCL_APPS_EXE_OUTPUT)                   || defined(INCL_APPS_EXE_OUTPUT_EXCLUSIVE)
   #include "apps/output/output.h"
#endif

#if defined(INCL_APPS_EXE_STATE) || defined(INCL_APPS_EXE_STATE_EXCLUSIVE) || defined(INCL_APPS_EXE_EXTERN_STATE) || defined(INCL_APPS_EXE_EXTERN_STATE_EXCLUSIVE)
   #include "apps/state/state.h"
#endif

#if defined(INCL_APPS_UNACE_EXE_COMMLINE) || defined(INCL_APPS_UNACE_EXE_COMMLINE_EXCLUSIVE) || defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP) || defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP_EXCLUSIVE)
       #include "apps/commline.h"
#endif

#if defined(INCL_APPS_UNACE_EXE)                       || defined(INCL_APPS_UNACE_EXE_EXCLUSIVE)
       #include "apps/exe.h"
#endif


#endif
