#ifndef _BASE_CONVERT_H_INCLUDED
#define _BASE_CONVERT_H_INCLUDED

#ifdef INCL_BASE_CONVERT_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
  tLFN    ToOEMStr,
          ToANSIStr;
} tBASE_CONVERT;

DECLEXT tBASE_CONVERT
        BASE_CONVERT;


INT     BASE_CONVERT_UpCase(INT CharCode);
INT     BASE_CONVERT_LowCase(INT CharCode);
void    BASE_CONVERT_StrCatBefore(PCHAR Str1, PCHAR Str2);
PCHAR   BASE_CONVERT_ToOEM(PCHAR Str);
PCHAR   BASE_CONVERT_ToANSI(PCHAR Str);
PCHAR   BASE_CONVERT_StrUpr(PCHAR Str);
PCHAR   BASE_CONVERT_StrLwr(PCHAR Str);
INT     BASE_CONVERT_StrICmp(PCHAR Str1, PCHAR Str2);
INT     BASE_CONVERT_StrNICmp(PCHAR Str1, PCHAR Str2, INT Size);

#undef DECLEXT

#endif
