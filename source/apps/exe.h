#ifndef _APPS_UNACE_EXE_H_INCLUDED
#define _APPS_UNACE_EXE_H_INCLUDED

#include <stdio.h>

#include "base/lfn/lfn.h"

typedef struct
{
        tLFN    LogFile;
} tAPPS_UNACE_EXE;

tAPPS_UNACE_EXE APPS_UNACE_EXE;

INT     main(INT ArgumentsNumber, PCHAR Arguments[]);

void    APPS_UNACE_EXE_ProgramInit(INT ArgumentsNumber, PCHAR Arguments[]);
void    APPS_UNACE_EXE_ProgramDone(void);
void    APPS_UNACE_EXE_InitOSSpecific(PCHAR *ProgramName);
void    APPS_UNACE_EXE_DoneOSSpecific(void);

#endif
