#ifndef _APPS_UNACE_EXE_INCLUDES_H_INCLUDED
#define _APPS_UNACE_EXE_INCLUDES_H_INCLUDED

#include "base/all/includes.h"
#include "apps/exe/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_UNACE_EXE_COMMLINE) || defined(INCL_APPS_UNACE_EXE_COMMLINE_EXCLUSIVE) || defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP) || defined(INCL_APPS_UNACE_EXE_COMMLINE_HELP_EXCLUSIVE)
       #include "apps/unace/commline.h"
#endif

#if defined(INCL_APPS_UNACE_EXE)                       || defined(INCL_APPS_UNACE_EXE_EXCLUSIVE)
       #include "apps/unace/exe.h"
#endif

#endif