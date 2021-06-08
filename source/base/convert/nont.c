#include <string.h>

#define INCL_BASE_CONVERT

#include "base/includes.h"


/*-----------------BASE_CONVERT_ToOEM------------------------------------*/

PCHAR   BASE_CONVERT_ToOEM(PCHAR Str)
{
  strcpy(BASE_CONVERT.ToOEMStr, Str);

  return BASE_CONVERT.ToOEMStr;
}

/*-----------------BASE_CONVERT_ToANSI-----------------------------------*/

PCHAR   BASE_CONVERT_ToANSI(PCHAR Str)
{
  strcpy(BASE_CONVERT.ToANSIStr, Str);

  return BASE_CONVERT.ToANSIStr;
}
