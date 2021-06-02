#include <string.h>

#define INCL_APPS_EXE_OUTPUT

#include "apps/unace/exe/includes.h"


/*-----------------APPS_EXE_OUTPUT_EXTERN_Warning------------------------*/

void    APPS_EXE_OUTPUT_EXTERN_Warning(PCHAR TopStr, PCHAR TextStr1,
					 PCHAR TextStr2)
{
CHAR      ShortStr1[80],
          ShortStr2[80];
INT       Width;

  APPS_EXE_OUTPUT_InfoOrWarningProc(TopStr, TextStr1, TextStr2, 1,
                                ShortStr1, ShortStr2, &Width);
}

/*-----------------APPS_EXE_OUTPUT_EXTERN_Message------------------------*/

void    APPS_EXE_OUTPUT_EXTERN_Message(INT Width, PCHAR TopStr,
                                         PCHAR MessageText)
{
  APPS_EXE_OUTPUT_MessageProc(TopStr, MessageText);
}

