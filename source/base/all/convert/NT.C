#include "base/all/wininc.h"

#include <string.h>
#include <windows.h>

#define INCL_BASE_CONVERT

#include "base/all/includes.h"


/*-----------------BASE_CONVERT_ToOEM------------------------------------*/

PCHAR   BASE_CONVERT_ToOEM(PCHAR Str)
{
INT       StrLen;

  StrLen = strlen(Str);
  CharToOemBuffA(Str, BASE_CONVERT.ToOEMStr, StrLen);
  BASE_CONVERT.ToOEMStr[StrLen] = 0;

  return BASE_CONVERT.ToOEMStr;
}

/*-----------------BASE_CONVERT_ToANSI-----------------------------------*/

PCHAR   BASE_CONVERT_ToANSI(PCHAR Str)
{
INT       StrLen;

  StrLen = strlen(Str);
  OemToCharBuffA(Str, BASE_CONVERT.ToANSIStr, StrLen);
  BASE_CONVERT.ToANSIStr[StrLen] = 0;

  return BASE_CONVERT.ToANSIStr;
}
