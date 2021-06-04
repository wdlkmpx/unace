#include <fcntl.h>
#include <string.h>

#define INCL_BASE_ARCINFO_EXCLUSIVE

#define INCL_BASE_ARCBLK
#define INCL_BASE_ARCHIVES_READ
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_FILELIST
#define INCL_BASE_MEMORY
#define INCL_BASE_MSGOUT
#define INCL_BASE_VOLUME

#include "base/all/includes.h"

/*-----------------BASE_ARCINFO_EXTERN_DidNotCreateArchive---------------*/
BOOL    BASE_ARCINFO_EXTERN_DidNotCreateArchive(void)
{
  return 1;
}


/*-----------------BASE_ARCINFO_GetArchiveInfo---------------------------*/

void    BASE_ARCINFO_GetArchiveInfo(PCHAR ArchiveName)
{
  BASE_DIRDATA_Dir1.UnPackedSize = 0;

  if (BASE_ARCINFO_EXTERN_DidNotCreateArchive())
  {
    if (!BASE_ARCHIVES_READ_ReadArchive(ArchiveName))
    {
      BASE_DIRDATA_Dir1.UnPackedSize =
        BASE_DIRDATA_Dir1.IsMultiVol = 0;

      BASE_DIRDATA_Dir1.Dictionary = 1;
    }

    BASE_VOLUME.CurrentVolumeNumber = BASE_DIRDATA_Dir1.VolumeNumber;
  }

  BASE_FILELIST.SizeOfFiles =
    BASE_DIRDATA_Dir1.IsMultiVol ? 0 : BASE_DIRDATA_Dir1.UnPackedSize;
}
