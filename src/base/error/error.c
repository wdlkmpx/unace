#define INCL_BASE_ERROR
#include "base/includes.h"

#define INCL_APPS_EXE_INPUT
#include "unace_includes.h"

tBASE_ERROR BASE_ERROR; //error.h


/*-----------------BASE_ERROR_EXTERN_Init--------------------------------*/
void    BASE_ERROR_EXTERN_Init(void)
{
}
/*-----------------BASE_ERROR_EXTERN_HandleCancelPROC--------------------*/
void    BASE_ERROR_EXTERN_HandleCancelPROC(void)
{
}

/*-----------------BASE_ERROR_EXTERN_HandleCancel------------------------*/

INT     BASE_ERROR_EXTERN_HandleCancel(BOOL DoReadAllKeys)
{
  BASE_ERROR_EXTERN_HandleCancelPROC();

  while (APPS_EXE_INPUT_KeyHit())
  {
    APPS_EXE_INPUT.LastKey = APPS_EXE_INPUT_GetKey();
    //APPS_EXE_EXTERN_ERROR_HandleCancelPROC();

    if (!DoReadAllKeys)
    {
      break;
    }
  }

  return BASE_ERROR.ErrorCode;
}
