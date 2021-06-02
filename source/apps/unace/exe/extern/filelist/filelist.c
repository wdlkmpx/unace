#include <string.h>

#define INCL_BASE_FILELIST

#include "apps/unace/exe/includes.h"


/*-----------------BASE_FILELIST_EXTERN_AddFileMoveCheck-----------------*/

INT     BASE_FILELIST_EXTERN_AddFileMoveCheck(PCHAR FileName)
{
  return 0;
}

/*-----------------BASE_FILELIST_EXTERN_CreateProc-----------------------*/

void    BASE_FILELIST_EXTERN_CreateProc(BOOL DoAddDirFirst)
{
  BASE_FILELIST_SearchListCreate(DoAddDirFirst);
}

/*-----------------BASE_FILELIST_EXTERN_CreateEnd------------------------*/

void    BASE_FILELIST_EXTERN_CreateEnd(void)
{
}
