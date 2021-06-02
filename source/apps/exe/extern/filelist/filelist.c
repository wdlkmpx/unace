#include <string.h>

#define INCL_BASE_CONVERT
#define INCL_BASE_FILELIST

#define INCL_APPS_EXE_COMMLINE

#include "apps/exe/includes.h"


/*-----------------BASE_FILELIST_EXTERN_CommandLineCheck-----------------*/

BOOL    BASE_FILELIST_EXTERN_CommandLineCheck(PCHAR FileName,
                                              PCHAR CompareFileName1,
                                              PCHAR CompareFileName2)
{
  return !BASE_CONVERT_StrICmp(CompareFileName2, APPS_EXE_COMMLINE.ErrorFile)
         || !BASE_CONVERT_StrICmp(CompareFileName2, APPS_EXE_COMMLINE.OutFile);
}
