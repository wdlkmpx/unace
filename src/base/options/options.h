#ifndef _BASE_OPTIONS_H_INCLUDED
#define _BASE_OPTIONS_H_INCLUDED

#include "base/crypt/crypt.h"

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  BOOL    DoShowComments,
          DoUseCurrentPassword;
  INT     IsSolid;
  INT     DicBits;
  tBASE_CRYPT_CRYPTIONDATA CryptionData;
} tBASE_OPTIONS_DCPR,
 *pBASE_OPTIONS_DCPR;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

typedef struct
{
        tBASE_OPTIONS_DCPR
                ExtractOptions;
} tBASE_OPTIONS;

extern PCHAR const BASE_OPTIONS_DICTIONARYTEXTS[23];
extern tBASE_OPTIONS BASE_OPTIONS;

INT     BASE_OPTIONS_EXTERN_SetPassword(
          pBASE_CRYPT_CRYPTIONDATA CryptionData, BOOL DoReEnter);
#endif
