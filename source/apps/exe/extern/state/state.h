#ifndef _APPS_EXE_EXTERN_STATE_H_INCLUDED
#define _APPS_EXE_EXTERN_STATE_H_INCLUDED

#ifdef INCL_APPS_EXE_EXTERN_STATE_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
        PCHAR   ActionString;
} tAPPS_EXE_EXTERN_STATE;

DECLEXT tAPPS_EXE_EXTERN_STATE
        APPS_EXE_EXTERN_STATE;

void    APPS_EXE_EXTERN_STATE_StdOutputProgressEnd(void);
void    APPS_EXE_EXTERN_STATE_OutputCRCOkEnd(BOOL CRCIsOk);
void    APPS_EXE_EXTERN_STATE_CRCError(BOOL CRCIsOk);


#undef DECLEXT

#endif
