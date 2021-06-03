#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define INCL_BASE_ARCHIVES_TEST_EXCLUSIVE

#define INCL_BASE_ARCBLK
#define INCL_BASE_ARCHIVES_ACE
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT

#include "base/all/includes.h"

/* not implemented? */
static BOOL BASE_ARCHIVES_TEST_EXTERN_ArchiveTestBreak(BOOL IgnoreKeys, INT Sectors)
{
  return 1;
}
static void BASE_ARCHIVES_TEST_EXTERN_ArchiveTestOtherFormats(PINT IsArchive,
                                                          INT FilePos,
                                                          pBASE_DIRDATA_DirData TempDir)
{
}


/*-----------------BASE_ARCHIVES_TEST_ArchiveTest------------------------*/

INT     BASE_ARCHIVES_TEST_ArchiveTest(PCHAR FileName, INT MaxTestSecs,
                                       BOOL IgnoreKeys)
{
BOOL      IsArchive;
PCHAR     ArchiveDescription;
INT       TestPos,
          Sectors,
          Read;
ULONGLONG FilePos;
tBASE_DIRDATA_DirData
          TempDirData;

  BASE_DIRDATA_Dir1.ArchiveBegin =
    BASE_DIRDATA_Dir1.IsSFX      =
    BASE_DIRDATA_Dir1.IsLocked   =
    BASE_DIRDATA_Dir1.HasAV      =
    BASE_DIRDATA_Dir1.HasMainCmt =
    BASE_DIRDATA_Dir1.IsMultiVol =
    BASE_DIRDATA_Dir1.IsSolid    =
    TestPos                      =
    Sectors                 	 =
    FilePos                 	 =
    IsArchive               	 = 0;

  BASE_DIRDATA_Dir1.IsAVOk = 1;

  if (MaxTestSecs)
  {
    errno = 0;
    if ((BASE_ARCHIVES_TEST.ArchiveHandle =
           BASE_LFN_ShareOpen(FileName, O_RDONLY | O_BINARY,
                              0, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    {
      strcpy(BASE_ARCBLK.ArchiveFile, FileName);
      BASE_ERROROUT_EXTERN_OpenArchiveRead();
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    while (BASE_ARCHIVES_TEST_EXTERN_ArchiveTestBreak(IgnoreKeys, Sectors)
           && Sectors < MaxTestSecs)
    {
      Read = read(BASE_ARCHIVES_TEST.ArchiveHandle,
                  (PVOID)&BASE_ARCHIVES_TEST.TestBuffer[TestPos],
                  512 + 32 -TestPos);
                        	
      if ((!Read && !TestPos) || errno)
      {
        break;
      }
    
      memset(&BASE_ARCHIVES_TEST.TestBuffer[TestPos + Read], 0, 512 + 32 -
             TestPos - Read);

      BASE_DIRDATA_Dir1.IsSFX |=
        (!Sectors && *(PUSHORT) &BASE_ARCHIVES_TEST.TestBuffer
                                 == ('M' | ('Z'<< 8)));

      BASE_DIRDATA_Dir1.ArchiveBegin = FilePos;

      if (BASE_ARCHIVES_ACE_ArchiveTest())
      {
        IsArchive = 1;
        TempDirData = BASE_DIRDATA_Dir1;
      }

      BASE_ARCHIVES_TEST_EXTERN_ArchiveTestOtherFormats(&IsArchive, FilePos,
                                                        &TempDirData);

      if (IsArchive)
      {
        ArchiveDescription = BASE_DIRDATA_Dir1.ArchiveDescription;
        BASE_DIRDATA_Dir1 = TempDirData;
        BASE_DIRDATA_Dir1.ArchiveDescription = ArchiveDescription;
        BASE_DIRDATA_Dir1.IsACE = !BASE_DIRDATA_Dir1.ArchiveType;

        close(BASE_ARCHIVES_TEST.ArchiveHandle);

        if (BASE_DIRDATA_Dir1.IsACE && BASE_DIRDATA_Dir1.IsNotCompatible)
        {
          BASE_ERROROUT_EXTERN_IsNotCompatible();
        }

        return 1;
      }

      memcpy(BASE_ARCHIVES_TEST.TestBuffer,
             &BASE_ARCHIVES_TEST.TestBuffer[512], 32);

      TestPos = Read ? 32 : 0;
      Sectors++;
      FilePos += 512;
    }

    close(BASE_ARCHIVES_TEST.ArchiveHandle);
  }

  return 0;
}
