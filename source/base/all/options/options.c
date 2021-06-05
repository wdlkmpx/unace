#include <string.h>

#define INCL_BASE_OPTIONS_EXCLUSIVE

#include "base/all/includes.h"

#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#include "apps/unace/exe/includes.h"

/*-----------------BASE_OPTIONS_EXTERN_SetPassword-----------------------*/

INT     BASE_OPTIONS_EXTERN_SetPassword(
          pBASE_CRYPT_CRYPTIONDATA CryptionData, BOOL DoReEnter)
{
CHAR      Password[51];

  Password[0] = 0;
  APPS_EXE_INPUT_Input(Password, 50, STR.Password, STR.Enter_password_, 1);

  if (APPS_EXE_INPUT.LastKey != 27)
  {
    strcpy(CryptionData->Password, Password);
  }

  return APPS_EXE_INPUT.LastKey == 27;
}
