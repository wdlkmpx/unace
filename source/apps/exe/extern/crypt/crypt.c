#define INCL_BASE_CRYPT
#define INCL_BASE_DCPR
#define INCL_BASE_ERROR
#define INCL_BASE_OPTIONS

#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "apps/exe/includes.h"


/*-----------------BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent-------------*/

void    BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent(
          pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
INT       Input;

  if (!(BASE_CRYPT.DoUseCurrentPassword |=
          BASE_OPTIONS.ExtractOptions.DoUseCurrentPassword)
      && BASE_DCPR.Options.CryptionData.Password[0])
  {
    do
    {
      Input = APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Extract,
                                       STR.Found_encrypted_file_,
                                       STR.Use_current_password_);

      if (Input == 3)
      {
        BASE_ERROR.ErrorCode = BASE_ERROR_USER;
      }
      else
      {
        if (Input == 2)
        {
          if (BASE_OPTIONS_EXTERN_SetPassword(&BASE_DCPR.Options.CryptionData, 0))
          {
            BASE_ERROR.ErrorCode = BASE_ERROR_USER;
          }
          else
          {
            BASE_CRYPT_InitCryptKey(&BASE_DCPR.Options.CryptionData);
          }
        }
      }
    }
    while (!BASE_ERROR.ErrorCode && !BASE_DCPR.Options.CryptionData.Password[0]);

    BASE_CRYPT.DoUseCurrentPassword = (Input == 1);
  }

  if (!BASE_ERROR.ErrorCode && !BASE_DCPR.Options.CryptionData.Password[0])
  {
    APPS_EXE_OUTPUT_EXTERN_Warning(STR.Extract,
                          STR.Found_encrypted_file__No_password_specified_,
                          STR.Enter_password_);
  }
}
