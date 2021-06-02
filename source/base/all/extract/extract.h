#ifndef _BASE_EXTRACT_H_INCLUDED
#define _BASE_EXTRACT_H_INCLUDED

#ifdef INCL_BASE_EXTRACT_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
        BOOL    DoRemovePaths,
                DoExtractAllVolumes,
                DoProcessAllVolumes;
} tBASE_EXTRACT;

DECLEXT tBASE_EXTRACT
        BASE_EXTRACT;

void    BASE_EXTRACT_DecompressFile(BOOL DoWriteData, BOOL IsTest);
void    BASE_EXTRACT_ExtractFiles(BOOL DoWriteData, BOOL IsTest);
void    BASE_EXTRACT_Extract(BOOL DoWriteData, BOOL IsTest);
void    BASE_EXTRACT_Test(PCHAR ArchiveName, BOOL IsTest);
void    BASE_EXTRACT_EXTERN_ExtractBegin(void);
void    BASE_EXTRACT_EXTERN_ExtractEnd(void);


#undef DECLEXT

#endif
