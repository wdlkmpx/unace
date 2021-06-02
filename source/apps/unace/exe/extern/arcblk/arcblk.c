#define INCL_BASE_ARCBLK

#define INCL_APPS_EXE_EXTERN_ARCBLK

#include "apps/unace/exe/includes.h"


/*-----------------BASE_ARCBLK_EXTERN_OutputArchiveInfo------------------*/

void    BASE_ARCBLK_EXTERN_OutputArchiveInfo(INT AccesFlags,
                                             BOOL DoResetCrypt)
{
  APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo(1);
}
