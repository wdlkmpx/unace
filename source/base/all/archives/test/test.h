#ifndef _BASE_ARCHIVES_TEST_H_INCLUDED
#define _BASE_ARCHIVES_TEST_H_INCLUDED

#include "base/all/dirdata/dirdata.h"

#ifdef INCL_BASE_ARCHIVES_TEST_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
  INT     MaxTestSectors;
  CHAR    TestBuffer[512 + 32];
  INT     ArchiveHandle;

} tBASE_ARCHIVES_TEST;

DECLEXT tBASE_ARCHIVES_TEST
        BASE_ARCHIVES_TEST;

INT     BASE_ARCHIVES_TEST_ArchiveTest(PCHAR FileName, INT MaxTestSecs,
                                       BOOL IgnoreKeys);

BOOL    BASE_ARCHIVES_TEST_EXTERN_ArchiveTestBreak(BOOL IgnoreKeys,
                                                   INT Sectors);

void    BASE_ARCHIVES_TEST_EXTERN_ArchiveTestOtherFormats(PINT IsArchive,
                                                          INT FilePos,
                                       pBASE_DIRDATA_DirData TempDirData);


#undef DECLEXT

#endif
