#include <stdio.h>

#define INCL_BASE_VERSION

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "apps/unace/exe/includes.h"


/*-----------------APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific----------*/

void    APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific(void)
{
  sprintf(APPS_EXE_MESSAGES.FirstCommandLineHelpLine,
          "UNACE v" BASE_VERSION_VERSIONSTR "   %-44s"
          __DATE__ " " __TIME__
#ifdef __MACOSX__
          "\n(Mac OS X)     ported to the Mac by Kolja Koischwitz"
#endif
#ifdef __sun__
          "\n(SunOS5.9)     ported to Solaris by Kolja Koischwitz"
#endif
          , STR.Copyright_by_ACE_Compression_Software);  
  STR.CommlineHelp[0] = APPS_EXE_MESSAGES.FirstCommandLineHelpLine;
}

/*-----------------APPS_EXE_MESSAGES_EXTERN_LoadMessages-----------------*/

void    APPS_EXE_MESSAGES_EXTERN_LoadMessages(void)
{
  APPS_EXE_MESSAGES_LoadMessagesPROC(&STR.END_MARKER, "END OF UNACE PART");
}
