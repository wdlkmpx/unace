#define INCL_BASE_ARCHIVES_ACE
#define INCL_BASE_ARCHIVES_READ
#define INCL_BASE_DIRDATA

#define INCL_APPS_EXE_MESSAGES

#include "apps/unace/exe/includes.h"


/*-----------------BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc-------------*/

void    BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc(void)
{
  BASE_ARCHIVES_ACE_ReadArchive();
}

/*-----------------BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription-------*/

void    BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription(void)
{
  BASE_DIRDATA_Dir1.ArchiveDescription =
    STR.arcdiscr[(BASE_DIRDATA_Dir1.IsSolid << 2)
    + (BASE_DIRDATA_Dir1.IsSFX << 1) + BASE_DIRDATA_Dir1.IsMultiVol];
}
