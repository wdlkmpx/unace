#ifndef _BASE_ARCHIVES_READ_H_INCLUDED
#define _BASE_ARCHIVES_READ_H_INCLUDED


#include "base/all/filelist/filelist.h"

#ifdef INCL_BASE_ARCHIVES_READ_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
  pBASE_FILELIST_FileData
          FileData;
  PCHAR   FileNames,
          FileNamesEnd;
  INT     MaxFileNumber,
          FileNumber;
  void    (*ProcessFile)
             (PCHAR FileName, tBASE_FILELIST_FileData FileData);
} tBASE_ARCHIVES_READ;

DECLEXT tBASE_ARCHIVES_READ
        BASE_ARCHIVES_READ;

void    BASE_ARCHIVES_READ_FreeArchiveList(void);
void    BASE_ARCHIVES_READ_GetArchiveList(void);
INT     BASE_ARCHIVES_READ_ReadArchive(PCHAR ArchiveName);
void    BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc(void);
void    BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription(void);


#undef DECLEXT

#endif
