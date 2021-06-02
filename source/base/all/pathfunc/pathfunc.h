#ifndef _BASE_PATHFUNC_H_INCLUDED
#define _BASE_PATHFUNC_H_INCLUDED

#ifdef INCL_BASE_PATHFUNC_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif

typedef struct
{
        BOOL    DoWildCardCheckMatchingPath;
        tLFN    AddSlashToEndStr;
} tBASE_PATHFUNC;

DECLEXT tBASE_PATHFUNC
        BASE_PATHFUNC;

//#ifdef _UNIX_
#ifdef __unix__
  #define BASE_PATHFUNC_SEPARATOR '/'
  #define BASE_PATHFUNC_SEPARATORSTR "/"
#else
  #define BASE_PATHFUNC_SEPARATOR '\\'
  #define BASE_PATHFUNC_SEPARATORSTR "\\"
#endif

void    BASE_PATHFUNC_ToDOSPathSeparatorN(PCHAR Path, INT N);
void    BASE_PATHFUNC_ToSystemPathSeparatorN(PCHAR Path, INT N);
void    BASE_PATHFUNC_ToDOSPathSeparator(PCHAR Path);
void    BASE_PATHFUNC_ToSystemPathSeparator(PCHAR Path);
PCHAR   BASE_PATHFUNC_RemoveSlash(PCHAR Path);
PCHAR   BASE_PATHFUNC_AddSlashToEnd(PCHAR Path);
INT     BASE_PATHFUNC_WildCardCheck(PCHAR WildCardStr, PCHAR Path);
void    BASE_PATHFUNC_ExtendWildCardStr(PCHAR SourceStr);
INT     BASE_PATHFUNC_GetDevicePathLen(PCHAR Path);
void    BASE_PATHFUNC_SplitFileName(PCHAR Dir, PCHAR FileName, PCHAR Path);
void    BASE_PATHFUNC_CompletePath(PCHAR Path);
BOOL    BASE_PATHFUNC_IsNTFSStreamName(PCHAR Path);
void    BASE_PATHFUNC_NTFSStreamGetFileName(PCHAR Path);


#undef DECLEXT

#endif
