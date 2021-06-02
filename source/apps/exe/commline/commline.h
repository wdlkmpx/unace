#ifndef _APPS_EXE_COMMLINE_H_INCLUDED
#define _APPS_EXE_COMMLINE_H_INCLUDED

#include "base/all/lfn/lfn.h"

#ifdef INCL_APPS_EXE_COMMLINE_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
        BOOL    Error,
                IsHitCTRL;
        INT     ArgumentsNumber,
                ArgumentCount,
                TimeOutLimit;
        PCHAR   Arguments[64];
        tLFN    ErrorFile,
                OutFile;
        tLFN    ProgramPath,
                ProgramDir,
                StartDir;
        PCHAR   EnvironmentSwitches;
        INT     Command;
        tLFN    ArchiveName;
        PCHAR   TargetDir;
} tAPPS_EXE_COMMLINE;

DECLEXT tAPPS_EXE_COMMLINE
        APPS_EXE_COMMLINE;


#undef DECLEXT

#endif
