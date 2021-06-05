#ifndef _APPS_EXE_COMMLINE_H_INCLUDED
#define _APPS_EXE_COMMLINE_H_INCLUDED

#include "base/all/lfn/lfn.h"

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

tAPPS_EXE_COMMLINE APPS_EXE_COMMLINE;

#endif
