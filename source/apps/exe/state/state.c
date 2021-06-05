#define INCL_APPS_EXE_STATE_EXCLUSIVE
//#define INCL_APPS_EXE_STATE

#include <unistd.h>
#include <sys/time.h>

#include "apps/exe/includes.h"

/*-----------------APPS_EXE_STATE_Delay----------------------------------*/
void    APPS_EXE_STATE_Delay(INT MilliSeconds)
{
struct timeval tv;

  tv.tv_sec = MilliSeconds / 1000;
  tv.tv_usec = (MilliSeconds % 1000) * 100;
  select(0, NULL, NULL, NULL, &tv);
}
