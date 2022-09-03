#include <stdio.h>

#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_OUTPUT

#define INCL_APPS_UNACE_EXE
#define INCL_APPS_UNACE_EXE_OUTPUT

#include "unace_includes.h"

/*-----------------APPS_UNACE_EXE_InitOSSpecific-------------------------*/

void    APPS_UNACE_EXE_InitOSSpecific(PCHAR *ProgramPath)
{

  APPS_EXE_OUTPUT.IsNotRedirected = isatty(fileno(stdout));  
  APPS_EXE_OUTPUT.DoNotStdWait    = !APPS_EXE_OUTPUT.IsNotRedirected;
  APPS_EXE_OUTPUT.ScreenHeight 	  = 80;

  APPS_EXE_INPUT_LINUX_SetRawMode();
}

/*-----------------APPS_UNACE_EXE_DoneOSSpecific-------------------------*/

void    APPS_UNACE_EXE_DoneOSSpecific(void)
{
  APPS_EXE_INPUT_LINUX_UnSetRawMode();
}
