#include <fcntl.h>

#define INCL_APPS_EXE_EXTERN_VOLUME_EXCLUSIVE

#define INCL_BASE_ARCBLK
#define INCL_BASE_CONVERT
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPTERR
#define INCL_APPS_EXE_OUTPUT

#include "apps/exe/includes.h"


void    APPS_EXE_EXTERN_VOLUME_HandleVolumeChange(PCHAR VolumeName)
{ /* not used */
}

/*-----------------BASE_VOLUME_EXTERN_ChangeVolumeToProcess--------------*/

INT     BASE_VOLUME_EXTERN_ChangeVolumeToProcess(PCHAR VolumeName)
{
BOOL      DoAgain;
INT       Input;
tLFN      VolumeDirectory,
          ShortStr;

  BASE_STATE_EXTERN_OutputProcess(STR.looking_for, VolumeName, 1);

  do
  {
    DoAgain=0;

    if (!BASE_DOSFUNCS_FileExists(VolumeName)
        || !BASE_VOLUME.DoProcessAllVolumes)
    {
      do
      {
        Input = APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy, STR.Ready_to_process,
                  APPS_EXE_CONVERT_MakeStrShorter(ShortStr, VolumeName, 26));

        if (Input == 2)
        {
          BASE_PATHFUNC_SplitFileName(VolumeDirectory, VolumeName, VolumeName);

          APPS_EXE_INPUT_EXTERN_Input(VolumeDirectory, 70, STR.New_Path,
                                      STR.Enter_new_source_path, 0);

          BASE_CONVERT_StrCatBefore(BASE_PATHFUNC_AddSlashToEnd(VolumeDirectory),
                               VolumeName);
        }

        BASE_VOLUME.DoProcessAllVolumes = (Input == 1);

        if (Input == 3)
        {
          BASE_ERROR.ErrorCode = BASE_ERROR_USER;

          return 0;
        }
      }
      while (!BASE_DOSFUNCS_FileExists(VolumeName));
    }

    if (!BASE_ARCBLK_OpenArchive(VolumeName, 0, 0, 1, 0))
    {
      APPS_EXE_OUTPTERR_OutputError(STR.Error_while_reading_archive,
                               STR.File_not_found_or_archive_broken_);

      if (APPS_EXE_INPUT.LastKey != 27)
      {
        DoAgain = 1;
      }

      BASE_ERROR.ErrorCode = BASE_ERROR_USER;
    }
  }
  while (DoAgain);

  BASE_STATE_EXTERN_OutputProcess(STR.processing, VolumeName, 1);

  if (!BASE_ERROR.ErrorCode)
  {
  }

  return !BASE_ERROR.ErrorCode;
}
