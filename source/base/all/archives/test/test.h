#ifndef _BASE_ARCHIVES_TEST_H_INCLUDED
#define _BASE_ARCHIVES_TEST_H_INCLUDED

#include "base/all/dirdata/dirdata.h"

typedef struct
{
  INT     MaxTestSectors;
  CHAR    TestBuffer[512 + 32];
  INT     ArchiveHandle;

} tBASE_ARCHIVES_TEST;

tBASE_ARCHIVES_TEST BASE_ARCHIVES_TEST;

INT     BASE_ARCHIVES_TEST_ArchiveTest(PCHAR FileName, INT MaxTestSecs,
                                       BOOL IgnoreKeys);
#endif
