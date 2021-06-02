#ifndef _INPUT_LINUX_H_INCLUDED
#define _INPUT_LINUX_H_INCLUDED

#include <termios.h>

#ifdef INCL_APPS_EXE_INPUT_LINUX_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
  struct termios
          OldtiMode;
  PCHAR   OldStdInBuf;
} tAPPS_EXE_INPUT_LINUX;

DECLEXT tAPPS_EXE_INPUT_LINUX
        APPS_EXE_INPUT_LINUX;

void    APPS_EXE_INPUT_LINUX_SetRawMode(void);
void    APPS_EXE_INPUT_LINUX_UnSetRawMode(void);

#undef DECLEXT

#endif
