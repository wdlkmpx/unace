#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <termios.h>

#define INCL_APPS_EXE_INPUT_LINUX_EXCLUSIVE

#define INCL_APPS_EXE_INPUT

#include <apps/exe/includes.h>


/*-----------------APPS_EXE_INPUT_GetKey---------------------------------*/

INT     APPS_EXE_INPUT_GetKey(void)
{
CHAR      Ch;

  Ch = getchar();

  switch (Ch)
  {
    case 127:
    {
      Ch = 8;

      break;
    }
  }

  return Ch;
}

/*-----------------APPS_EXE_INPUT_KeyHit---------------------------------*/

BOOL    APPS_EXE_INPUT_KeyHit(void)
{
fd_set fds;
struct timeval tv;

  if (!isatty(0))
  {
    return 0;
  }
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  return select(1, &fds, NULL, NULL, &tv);
}

/*-----------------APPS_EXE_INPUT_LINUX_SetRawMode-----------------------*/

void    APPS_EXE_INPUT_LINUX_SetRawMode(void)
{
struct termios
          ti;
  if (tcgetattr(STDIN_FILENO, &APPS_EXE_INPUT_LINUX.OldtiMode) < 0)
  {
    return;
  }

  ti = APPS_EXE_INPUT_LINUX.OldtiMode;

  ti.c_iflag &= ~ICRNL;
  ti.c_iflag |= IGNBRK | BRKINT;
  ti.c_lflag &= ~(ICANON | ECHO);
  ti.c_lflag |= ISIG;

  if (tcsetattr(STDIN_FILENO, TCSANOW, &ti) < 0)
  {
    return;
  }

  return;
}

/*-----------------APPS_EXE_INPUT_LINUX_UnSetRawMode---------------------*/

void    APPS_EXE_INPUT_LINUX_UnSetRawMode(void)
{
  if (tcsetattr(STDIN_FILENO, TCSANOW, &APPS_EXE_INPUT_LINUX.OldtiMode) < 0)
  {
    return;
  }

  return;
}
