#ifndef _APPS_INCLUDES_H_INCLUDED
#define _APPS_INCLUDES_H_INCLUDED

#include "base/all/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_EXE)                          || defined(INCL_APPS_EXE_EXCLUSIVE)
       #include "apps/exe/exe.h"
#endif

#if defined(INCL_APPS_EXE_COMMLINE)                 || defined(INCL_APPS_EXE_COMMLINE_EXCLUSIVE)
   #include "apps/exe/commline/commline.h"
#endif

#if defined(INCL_APPS_EXE_EXTERN_ARCBLK)            || defined(INCL_APPS_EXE_EXTERN_ARCBLK_EXCLUSIVE)
   #include "apps/exe/extern/arcblk/arcblk.h"
#endif

#if defined(INCL_APPS_EXE_EXTERN_COMMENTS)          || defined(INCL_APPS_EXE_EXTERN_COMMENTS_EXCLUSIVE)
   #include "apps/exe/extern/comments/comments.h"
#endif

#if defined(INCL_APPS_EXE_EXTERN_ERROR)             || defined(INCL_APPS_EXE_EXTERN_ERROR_EXCLUSIVE)
   #include "apps/exe/extern/error/error.h"
#endif

#if defined(INCL_APPS_EXE_EXTERN_STATE)             || defined(INCL_APPS_EXE_EXTERN_STATE_EXCLUSIVE)
   #include "apps/exe/extern/state/state.h"
#endif

#if defined(INCL_APPS_EXE_EXTERN_VOLUME)            || defined(INCL_APPS_EXE_EXTERN_VOLUME_EXCLUSIVE)
       #include "apps/exe/extern/volume/volume.h"
#endif

#if defined(INCL_APPS_EXE_ACEFUNCS)                 || defined(INCL_APPS_EXE_ACEFUNCS_EXCLUSIVE)
   #include "apps/exe/acefuncs/acefuncs.h"
#endif

#if defined(INCL_APPS_EXE_CONVERT)                  || defined(INCL_APPS_EXE_CONVERT_EXCLUSIVE)
   #include "apps/exe/convert/convert.h"
#endif

#if defined(INCL_APPS_EXE_INPUT)                    || defined(INCL_APPS_EXE_INPUT_EXCLUSIVE)
   #include "apps/exe/input/input.h"
#endif

  #if defined(INCL_APPS_EXE_INPUT_LINUX)              || defined(INCL_APPS_EXE_INPUT_LINUX_EXCLUSIVE)
     #include "apps/exe/input/lin.h"
  #endif

  #if defined(INCL_APPS_EXE_INPUT_NT)                 || defined(INCL_APPS_EXE_INPUT_NT_EXCLUSIVE)
     #include "apps/exe/input/nt.h"
  #endif

#if defined(INCL_APPS_EXE_MESSAGES)                 || defined(INCL_APPS_EXE_MESSAGES_EXCLUSIVE)
   #include "apps/exe/messages/messages.h"
#endif

#if defined(INCL_APPS_EXE_OUTPTERR)                 || defined(INCL_APPS_EXE_OUTPTERR_EXCLUSIVE)
   #include "apps/exe/outpterr/outpterr.h"
#endif

#if defined(INCL_APPS_EXE_OUTPUT)                   || defined(INCL_APPS_EXE_OUTPUT_EXCLUSIVE)
   #include "apps/exe/output/output.h"
#endif

  #if defined(INCL_APPS_EXE_OUTPUT_DOS32)             || defined(INCL_APPS_EXE_OUTPUT_DOS32_EXCLUSIVE)
     #include "apps/exe/output/dos32.h"
  #endif

  #if defined(INCL_APPS_EXE_OUTPUT_NT)                || defined(INCL_APPS_EXE_OUTPUT_NT_EXCLUSIVE)
     #include "apps/exe/output/nt.h"
  #endif

#if defined(INCL_APPS_EXE_STATE)                    || defined(INCL_APPS_EXE_STATE_EXCLUSIVE)
   #include "apps/exe/state/state.h"
#endif

#endif
