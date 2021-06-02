#include <stdio.h>
#include <string.h>

#define INCL_BASE_CONVERT_EXCLUSIVE

#define INCL_BASE_FILELIST

#include "base/all/includes.h"


/*-----------------BASE_CONVERT_LowCase----------------------------------*/

INT     BASE_CONVERT_LowCase(INT CharCode)
{
  return in(CharCode, 'A', 'Z') ? CharCode + 32 : CharCode;
}

/*-----------------BASE_CONVERT_UpCase-----------------------------------*/

INT     BASE_CONVERT_UpCase(INT CharCode)
{
  return in(CharCode, 'a', 'z') ? CharCode - 32 : CharCode;
}

/*-----------------BASE_CONVERT_StrCatBefore-----------------------------*/

void    BASE_CONVERT_StrCatBefore(PCHAR Str1, PCHAR Str2)
{
tBASE_LFN_DBL     
	TempStr;

  strcpy(TempStr, Str2);
  sprintf(Str2, "%s%s", Str1, TempStr);
}
