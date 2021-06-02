#ifndef _APPS_EXE_STATE_H_INCLUDED
#define _APPS_EXE_STATE_H_INCLUDED

#ifdef INCL_APPS_EXE_STATE_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
        PCHAR   ActionString;
} tAPPS_EXE_STATE;

DECLEXT tAPPS_EXE_STATE
        APPS_EXE_STATE;

void    APPS_EXE_STATE_Delay(INT MilliSeconds);


#undef DECLEXT

#endif
