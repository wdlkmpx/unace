#ifndef _APPS_EXE_CONVERT_H_INCLUDED
#define _APPS_EXE_CONVERT_H_INCLUDED


#ifdef INCL_APPS_EXE_CONVERT_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif

typedef struct
{
        CHAR    ToPercentStrStr[10];
} tAPPS_EXE_CONVERT;

DECLEXT tAPPS_EXE_CONVERT
        APPS_EXE_CONVERT;

PCHAR   APPS_EXE_CONVERT_ToByteUnitStr(PCHAR Str, ULONGLONG ByteSize);

PCHAR   APPS_EXE_CONVERT_MakeStrShorter(PCHAR DestStr, PCHAR SourceStr,
                                        INT Width);

INT     APPS_EXE_CONVERT_GetPercents(ULONGLONG Value1, ULONGLONG Value2);
PCHAR   APPS_EXE_CONVERT_ToPercentStr(ULONGLONG Value1, ULONGLONG Value2);
PCHAR   APPS_EXE_CONVERT_FormatSize(PCHAR SizeStr, INT Attr, ULONGLONG Size);


#undef DECLEXT

#endif
