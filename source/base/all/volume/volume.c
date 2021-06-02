#include <string.h>

#define INCL_BASE_VOLUME_EXCLUSIVE

#define INCL_BASE_ARCBLK
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_EXTRACT

#include "base/all/includes.h"


/*-----------------BASE_VOLUME_GetVolumeName-----------------------------*/

PCHAR   BASE_VOLUME_GetVolumeName(PCHAR NewVolumeName, PCHAR VolumeName,
                             INT Type, INT AddToVolumeNumber, BOOL IsSFX)
{
PCHAR     ExtensionPos;
INT       VolumeNumber;

  strcpy(NewVolumeName, VolumeName);

  if ((ExtensionPos = (PCHAR) strrchr(NewVolumeName, '.')) == NULL
      || !*(ExtensionPos + 1))
  {
    VolumeNumber = -1;
    ExtensionPos = NewVolumeName + strlen(NewVolumeName);
  }
  else
  {
    ExtensionPos++;

    VolumeNumber =
      (*(ExtensionPos + 1) - '0') * 10 + *(ExtensionPos + 2) - '0';

    if (!in(VolumeNumber, 0, 99))
    {
      VolumeNumber = -1;
    }

    if (in(*ExtensionPos, '0', '9'))
    {
      VolumeNumber += (*ExtensionPos - '0') * 100;
    }
  }

  VolumeNumber += AddToVolumeNumber;

  if (VolumeNumber < -1)
  {
    VolumeNumber = -1;
  }

  if (!VolumeNumber && Type == 3)
  {
    VolumeNumber = AddToVolumeNumber > 0 ? 1 : -1;
  }

  if (VolumeNumber == -1)
  {
    strcpy(ExtensionPos, ARCHIVEEXTENSIONS[IsSFX ? 4 : Type]);
  }
  else
  {
    if (VolumeNumber < 100)
    {
      *ExtensionPos = Type ? ARCHIVEEXTENSIONS[Type][0] : 'C';
    }
    else
    {
      *ExtensionPos = VolumeNumber / 100 + '0';
    }

    *(ExtensionPos + 1) = (VolumeNumber / 10) % 10 + '0';
    *(ExtensionPos + 2) = VolumeNumber % 10 + '0';

    if (!BASE_DOSFUNCS_FileExists(NewVolumeName) && *ExtensionPos == 'C')
    {
      *ExtensionPos = 'c';
    }
  }

  return NewVolumeName;
}

/*-----------------BASE_VOLUME_NextVolumeToProcess-----------------------*/

INT     BASE_VOLUME_NextVolumeToProcess(BOOL IsZeroLengthFile)
{
INT       Result;

  if (BASE_VOLUME.DoNotProcessNextVolume)
  {
    return 0;
  }

  BASE_VOLUME.CurrentVolumeNumber++;

  BASE_ARCBLK_EXTERN_CloseArchive(1);

  BASE_VOLUME_GetVolumeName(BASE_ARCBLK.ArchiveFile,
                            BASE_ARCBLK.ArchiveFile, 0, 1,
                            BASE_ARCBLK.Options.IsSFX);

  if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(BASE_ARCBLK.ArchiveFile))
  {
    if (!BASE_ERROR.ErrorCode)
    {
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    return 0;
  }

  Result = BASE_ARCBLK_LoadBlock();

  if (Result && IsZeroLengthFile)
  {
    Result = BASE_ARCBLK_LoadBlock();
  }

  return Result;
}

/*-----------------BASE_VOLUME_PreviousVolumeToProcess-------------------*/

void    BASE_VOLUME_PreviousVolumeToProcess(void)
{
  BASE_ARCBLK_EXTERN_CloseArchive(1);

  BASE_VOLUME.CurrentVolumeNumber--;

  BASE_VOLUME_GetVolumeName(BASE_ARCBLK.ArchiveFile,
                            BASE_ARCBLK.ArchiveFile, 0, -1,
                            BASE_DIRDATA_Dir1.IsSFX);

  if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(BASE_ARCBLK.ArchiveFile))
  {
    if (!BASE_ERROR.ErrorCode)
    {
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    return;
  }

  return;
}

/*-----------------BASE_VOLUME_FirstVolumeToProcess----------------------*/

INT     BASE_VOLUME_FirstVolumeToProcess(PCHAR VolumeName)
{
tLFN      FirstVolumeName;

  if ((BASE_EXTRACT.DoExtractAllVolumes || BASE_DIRDATA_Dir1.IsSolid)
      && BASE_DIRDATA_Dir1.VolumeNumber)
  {
    strcpy(FirstVolumeName, VolumeName);
    BASE_VOLUME.CurrentVolumeNumber = 0;

    BASE_VOLUME_GetVolumeName(FirstVolumeName, FirstVolumeName, 0, -100000,
                              BASE_DIRDATA_Dir1.IsSFX);

    if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(FirstVolumeName))
    {
      return 0;
    }
  }
  else
  {
    if (!BASE_ARCBLK_OpenArchive(VolumeName, 0, 1, 1, 1))
    {
      return 0;
    }
  }

//  BASE_VOLUME.CurrentVolumeNumber = 0;

  return !BASE_ERROR.ErrorCode;
}
