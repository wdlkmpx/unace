#ifndef _BASE_STATE_H_INCLUDED
#define _BASE_STATE_H_INCLUDED


#include "base/all/lfn/lfn.h"

#ifdef INCL_BASE_STATE_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif

typedef struct
{
  BOOL    IsInitialized,
          DoNotCount;
  tLFN    CurrentFileName;
  tBASE_LFN_DBL
          DestinationFileName;
  ULONG   StartTime,
          FileCount,
          SummaryFileCount,
          DirCount;
  ULONGLONG
          FileSize,
          NewSkipSize,
          SkipSize,
          TotalUnComprBytes,
          TotalComprBytes,
          SummaryUnComprBytes,
          SummaryComprBytes,
          SavedUnComprBytes,
          SavedComprBytes,
          FileUnComprBytes,
          FileComprBytes,
          ReadBytes,
          WriteBytes;
  INT     SumProcessedFiles,
          SumErrors;
} tBASE_STATE;

DECLEXT tBASE_STATE
        BASE_STATE;

INT     BASE_STATE_WriteFile(INT Handle, PVOID Buf, INT Len,
                             BOOL IsUncompressedSize);

void    BASE_STATE_TestOnly(INT Len, BOOL IsUncompressedSize);

void    BASE_STATE_OutputProgress(INT ReadBytes,  INT WriteBytes,
                                  INT UnCprBytes, INT CprBytes,
                                  INT Attributes);

void    BASE_STATE_OutputCRCOk(BOOL CRCIsOk);

void    BASE_STATE_EXTERN_IsCRCOk(PBOOL IsCRCOk, BOOL IsEncrypted);
void    BASE_STATE_EXTERN_IsCRCOkSet(PBOOL IsCRCOk, BOOL IsEncrypted);
void    BASE_STATE_EXTERN_OutputProgressData(PCHAR Buf, INT Bytes);

void    BASE_STATE_EXTERN_OutputProcess(PCHAR OperationStr, PCHAR FileName,
                                        BOOL IsImportant);

void    BASE_STATE_EXTERN_SetExtractString(void);
void    BASE_STATE_EXTERN_SetTestString(void);
void    BASE_STATE_EXTERN_OutputProgressEnd(BOOL DoInit, BOOL IsFileStart);
void    BASE_STATE_EXTERN_OutputCRCOkEnd(BOOL CRCIsOk);


#undef DECLEXT

#endif
