#ifndef _BASE_OPTIONS_H_INCLUDED
#define _BASE_OPTIONS_H_INCLUDED

#include "base/all/crypt/crypt.h"

#define SETNOALIGNMENT
#include "base/all/packprag.h"

typedef struct
{
  BOOL    DoShowComments,
          DoUseCurrentPassword;
  INT     IsSolid;
  INT     DicBits;
  tBASE_CRYPT_CRYPTIONDATA CryptionData;
} tBASE_OPTIONS_DCPR,
 *pBASE_OPTIONS_DCPR;

#define RESTOREALIGNMENT
#include "base/all/packprag.h"

typedef struct
{
        tBASE_OPTIONS_DCPR
                ExtractOptions;
} tBASE_OPTIONS;

PCHAR const BASE_OPTIONS_DICTIONARYTEXTS[23] 
#ifdef INCL_BASE_OPTIONS_EXCLUSIVE
=
{ "0K", "0K", "0K", "0K", "0K",
  "0K", "0K", "0K", "0K", "0K",
  "1K", "2K", "4K", "8K", "16K",
  "32K", "64K", "128K", "256K", "512K",
  "1024K", "2048K", "4096K"}
#endif
;

tBASE_OPTIONS BASE_OPTIONS;

INT     BASE_OPTIONS_EXTERN_SetPassword(
          pBASE_CRYPT_CRYPTIONDATA CryptionData, BOOL DoReEnter);
#endif
