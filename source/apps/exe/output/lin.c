#define INCL_APPS_EXE_OUTPUT

#include "apps/exe/includes.h"


/*-----------------APPS_EXE_OUTPUT_Beep----------------------------------*/

void    APPS_EXE_OUTPUT_Beep(void)
{
  printf("\x7");
}

/*-----------------APPS_EXE_OUTPUT_GetScreenSize-------------------------*/

void    APPS_EXE_OUTPUT_GetScreenSize(void)
{
  APPS_EXE_OUTPUT.ScreenHeight = 80;
}
