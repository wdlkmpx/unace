#include <string.h>
#include <stdio.h>

#define INCL_APPS_EXE_EXTERN_ARCBLK_EXCLUSIVE

#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_DIRDATA
#define INCL_BASE_STATE

#define INCL_APPS_EXE
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_STATE

#include "apps/exe/includes.h"

/*-----------------BASE_ARCBLK_EXTERN_OutputArchiveInfo------------------*/
void    BASE_ARCBLK_EXTERN_OutputArchiveInfo(INT AccesFlags,
                                             BOOL DoResetCrypt)
{
  APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo(1);
}


/*-----------------APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo--------------*/

void    APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo(BOOL DoOutputAV)
{
CHAR      OutputStr[80];

  if (BASE_ARCBLK.DoOutputComments)
  {
    BASE_COMMENTS_EXTERN_Output();
  }

  if (DoOutputAV
      && BASE_ARCBLK.Header.Main.HEAD_FLAGS & BASE_ACESTRUC_FLAG_AV)
  {
    sprintf(OutputStr, "%s %d.%d.%d %s %d.%d %s", STR.created_on,
            BASE_DIRDATA_Dir1.TimeCreated.Day,
            BASE_DIRDATA_Dir1.TimeCreated.Month,
            1980 + BASE_DIRDATA_Dir1.TimeCreated.Year,
            STR.with_ver,
            BASE_DIRDATA_Dir1.VersionCreated >> 8,
            BASE_DIRDATA_Dir1.VersionCreated & 0xff,
            STR.by);

    BASE_STATE_EXTERN_OutputProcess(OutputStr, "", 1);

    strncpy(OutputStr, BASE_ARCBLK.Header.Main.AV,
            BASE_ARCBLK.Header.Main.AV_SIZE);

    OutputStr[BASE_ARCBLK.Header.Main.AV_SIZE] = 0;
    OutputStr[50] = 0;
    BASE_STATE_EXTERN_OutputProcess(OutputStr, "", 1);
    APPS_EXE_STATE_Delay(APPS_EXE_DELAYLENGTH);
  }
}

/*-----------------BASE_ARCBLK_EXTERN_SetFileData------------------------*/

void    BASE_ARCBLK_EXTERN_SetFileData(void)
{
}
