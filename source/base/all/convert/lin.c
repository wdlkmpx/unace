#include <ctype.h>
#include <string.h>

#define INCL_BASE_CONVERT

#include "base/all/includes.h"


/*-----------------BASE_CONVERT_StrUpr------------------------------------*/

PCHAR   BASE_CONVERT_StrUpr(PCHAR Str)
{
INT       I;

  for (I = 0; I < strlen(Str); I++)
  {
    Str[I] = toupper(Str[I]);
  }

  return Str;
}

/*-----------------BASE_CONVERT_StrLwr----------------------------------*/

PCHAR   BASE_CONVERT_StrLwr(PCHAR Str)
{
INT       I;

  for (I = 0; I < strlen(Str); I++)
  {
    Str[I] = tolower(Str[I]);
  }

  return Str;
}

/*-----------------BASE_CONVERT_StrICmp----------------------------------*/

INT     BASE_CONVERT_StrICmp(PCHAR Str1, PCHAR Str2)
{
  return strcasecmp(Str1, Str2);
}

/*-----------------BASE_CONVERT_StrNICmp---------------------------------*/

INT     BASE_CONVERT_StrNICmp(PCHAR Str1, PCHAR Str2, INT Size)
{
  return strncasecmp(Str1, Str2, Size);
}
