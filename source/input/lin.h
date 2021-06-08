#ifndef _INPUT_LINUX_H_INCLUDED
#define _INPUT_LINUX_H_INCLUDED

#include <termios.h>
typedef struct
{
  struct termios
          OldtiMode;
  PCHAR   OldStdInBuf;
} tAPPS_EXE_INPUT_LINUX;

tAPPS_EXE_INPUT_LINUX APPS_EXE_INPUT_LINUX;

void    APPS_EXE_INPUT_LINUX_SetRawMode(void);
void    APPS_EXE_INPUT_LINUX_UnSetRawMode(void);

#endif
