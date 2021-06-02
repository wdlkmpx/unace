#include <string.h>

#define INCL_BASE_CONVERT
#define INCL_BASE_ERROR

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "apps/unace/exe/includes.h"


/*-----------------APPS_EXE_INPUT_EXTERN_Input---------------------------*/

void    APPS_EXE_INPUT_EXTERN_Input(PCHAR StartStr, INT Width,
                                      PCHAR TopStr,
                                      PCHAR Discription, BOOL IsPasswInput)
{
  APPS_EXE_INPUT_Input(StartStr, Width, TopStr,
                       Discription, IsPasswInput);
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcOutputMask-------------*/

void    APPS_EXE_INPUT_EXTERN_InputProcOutputMask(BOOL DoRegInput)
{
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcHandleKey--------------*/

void    APPS_EXE_INPUT_EXTERN_InputProcHandleKey(BOOL DoRegInput)
{
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcHandleDelete-----------*/

void    APPS_EXE_INPUT_EXTERN_InputProcHandleDelete(BOOL DoRegInput, INT InputLen,
                                           INT Width)
{
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcInputCondition---------*/

BOOL    APPS_EXE_INPUT_EXTERN_InputProcInputCondition(BOOL DoRegInput, INT InputLen)
{
  return 1;
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtOutput-----*/

void    APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtInput(BOOL DoRegInput,
                                                INT InputLen,
                                                INT Width)
{
}

/*-----------------APPS_EXE_INPUT_EXTERN_WarningYANC---------------------*/

INT     APPS_EXE_INPUT_EXTERN_WarningYANC(PCHAR TopStr, PCHAR Description1,
                                 PCHAR Description2)
{
  return APPS_EXE_INPUT_WarningYANCProc(TopStr, Description1, Description2);
}
