#include <stdio.h>
#include <string.h>

#define INCL_APPS_UNACE_EXE_COMMLINE_HELP_EXCLUSIVE

#define INCL_BASE_ERROR

#define INCL_BASE_ACE_AV

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "apps/unace/exe/includes.h"


/*-----------------APPS_UNACE_EXE_COMMLINE_HELP_PrintCommandLineHelp-----*/

void    APPS_UNACE_EXE_COMMLINE_HELP_PrintHelp(BOOL DoPrintCopyRight)
{
INT       I;

  for (I = (DoPrintCopyRight ? 0 : APPS_UNACE_EXE_COMMLINE_HELP_COPYRIGHTLINES);
       (I < (DoPrintCopyRight ? APPS_UNACE_EXE_COMMLINE_HELP_COPYRIGHTLINES :
             APPS_EXE_MESSAGES_COMMLINEHELPLINES))
       && !BASE_ERROR_EXTERN_HandleCancel(1); I++)
  {
    APPS_EXE_OUTPUT_Write(STR.CommlineHelp[I]);
    APPS_EXE_OUTPUT_FullScreenKeyWait();
  }
}
