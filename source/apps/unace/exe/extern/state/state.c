#include <string.h>

#define INCL_BASE_CONVERT
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_FILELIST
#define INCL_BASE_STATE

#define INCL_APPS_EXE_EXTERN_STATE
#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "apps/unace/exe/includes.h"

/*-----------------BASE_STATE_EXTERN_OutputProgressEnd-------------------*/

void    BASE_STATE_EXTERN_OutputProgressEnd(BOOL DoInit, BOOL IsFileStart)
{
  APPS_EXE_EXTERN_STATE_StdOutputProgressEnd();
}

/*-----------------BASE_STATE_EXTERN_OutputProcess-----------------------*/

void    BASE_STATE_EXTERN_OutputProcess(PCHAR OperationStr, PCHAR FileName,
                                   BOOL IsImportant)
{
CHAR      ShorterStr[80],
          OutputStr[80];

  sprintf(OutputStr, "  %s %s", OperationStr,
          BASE_CONVERT_ToOEM(APPS_EXE_CONVERT_MakeStrShorter(ShorterStr,
                                               FileName,
                                               50 - strlen(OperationStr))));

  APPS_EXE_OUTPUT_Write(&OutputStr[IsImportant ? 2 : 0]);
  APPS_EXE_OUTPUT.DoStdDeleteRight = 1;
}

/*-----------------BASE_STATE_EXTERN_OutputCRCOkEnd----------------------*/

void    BASE_STATE_EXTERN_OutputCRCOkEnd(BOOL CRCIsOk)
{
  APPS_EXE_EXTERN_STATE_OutputCRCOkEnd(CRCIsOk);
  APPS_EXE_EXTERN_STATE_CRCError(CRCIsOk);
}
