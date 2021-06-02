#ifndef _APPS_UNACE_EXE_INCLUDES_H_INCLUDED
#define _APPS_UNACE_EXE_INCLUDES_H_INCLUDED

#include "base/all/includes.h"
#include "apps/exe/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_UNACE_EXE_COMMLINE)              || defined(INCL_APPS_UNACE_EXE_COMMLINE_EXCLUSIVE)
       #include "apps/unace/exe/commline/commline.h"
#endif

  #if defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP)         || defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP_EXCLUSIVE)
         #include "apps/unace/exe/commline/help/help.h"
  #endif


#if defined(INCL_APPS_UNACE_EXE)                       || defined(INCL_APPS_UNACE_EXE_EXCLUSIVE)
       #include "apps/unace/exe/exe.h"
#endif

  #if defined(INCL_APPS_UNACE_EXE_NT)                    || defined(INCL_APPS_UNACE_EXE_NT_EXCLUSIVE)
         #include "apps/unace/exe/nt.h"
  #endif

#endif
