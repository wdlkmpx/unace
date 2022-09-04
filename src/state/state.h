#ifndef _APPS_EXE_STATE_H_INCLUDED
#define _APPS_EXE_STATE_H_INCLUDED

typedef struct
{
        PCHAR   ActionString;
} tAPPS_EXE_STATE;

extern tAPPS_EXE_STATE APPS_EXE_STATE;

void    APPS_EXE_STATE_Delay(INT MilliSeconds);


typedef struct {
		PCHAR   ActionString;
} tAPPS_EXE_EXTERN_STATE;

extern tAPPS_EXE_EXTERN_STATE APPS_EXE_EXTERN_STATE;

void    APPS_EXE_EXTERN_STATE_StdOutputProgressEnd(void);
void    APPS_EXE_EXTERN_STATE_OutputCRCOkEnd(BOOL CRCIsOk);
void    APPS_EXE_EXTERN_STATE_CRCError(BOOL CRCIsOk);

#endif
