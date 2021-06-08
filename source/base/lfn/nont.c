#include <stdio.h>
#include <string.h>

#ifdef _WIN32
	#include <io.h>
#endif

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_PATHFUNC

#include "base/includes.h"


/*-----------------BASE_LFN_ConvertFileName------------------------------*/

void    BASE_LFN_ConvertFileName(PCHAR Path, INT Attr)
{
BOOL      IsLastName;
tLFN      TestExistencePath,
          TempPath,
          Name,
          ShortName,
          DriveStr;
PCHAR     FirstNamePos,
          NextSlashPos,
          NamePos;
INT       NameNumber,
          NameLen;

  IsLastName = 0;

  strcpy(DriveStr, Path);
  BASE_PATHFUNC_CompletePath(DriveStr);
  DriveStr[2] = 0;

  for (NamePos = Path; *NamePos; NamePos++)
  {
    if (strchr("*\x22<>|", *NamePos))
    {
      *NamePos = '_';
    }
  }

  if (!BASE_LFN_DriveSupportsLFN(DriveStr))
  {
    FirstNamePos  = Path + BASE_PATHFUNC_GetDevicePathLen(Path);

    strcpy(TempPath, FirstNamePos);

    *FirstNamePos = 0;
    NamePos       = TempPath;

    do
    {
      if ((NextSlashPos = (PCHAR) strchr(NamePos, BASE_PATHFUNC_SEPARATOR)))
      {
        NameLen = NextSlashPos - NamePos;
      }
      else
      {
        NameLen    = strlen(NamePos);
        IsLastName = 1;
      }

      strncpy(Name, NamePos, NameLen);

      Name[NameLen] =
        NameNumber  = 0;

      do
      {
        NameNumber++;

        if (!BASE_LFN_ShortenLongFileName(ShortName, Name, NameNumber))
        {
          IsLastName = 0;
        }

        sprintf(TestExistencePath, "%s%s", Path, ShortName);
      }
      while (!(Attr & BASE_DOSFUNCS_SUBDIR) && IsLastName
             && BASE_DOSFUNCS_FileExists(TestExistencePath)
             && Attr != 0xffff);

      strcat(Path, ShortName);

      if (NextSlashPos)
      {
        NameLen           = strlen(Path);
        Path[NameLen]     = BASE_PATHFUNC_SEPARATOR;
        Path[NameLen + 1] = 0;
      }

      NamePos = NextSlashPos + 1;
    }
    while (NextSlashPos);
  }
}

/*-----------------BASE_LFN_GetFindAllFilesAndDirsAttr-------------------*/

INT     BASE_LFN_GetFindAllFilesAndDirsAttr(void)
{
  return BASE_DOSFUNCS_RDONLY | BASE_DOSFUNCS_HIDDEN | BASE_DOSFUNCS_SYSTEM | BASE_DOSFUNCS_SUBDIR | BASE_DOSFUNCS_ARCH;
}

/*-----------------BASE_LFN_GetFindAllFilesAttr--------------------------*/

INT     BASE_LFN_GetFindAllFilesAttr(void)
{
  return BASE_DOSFUNCS_RDONLY | BASE_DOSFUNCS_HIDDEN | BASE_DOSFUNCS_SYSTEM | BASE_DOSFUNCS_ARCH;
}

/*-----------------BASE_LFN_ShortenLongFileName--------------------------*/

INT     BASE_LFN_ShortenLongFileName(PCHAR ShortName, PCHAR Name,
                                     INT NameNumber)
{
INT       I,
          Result,
          Len;
PCHAR     CharPos1,
          CharPos2;
CHAR      NumberStr[8];

  strcpy(ShortName, Name);
  CharPos1 = strrchr(Name, '.');

  if (!CharPos1)
  {
    CharPos1 = &Name[strlen(Name)];
  }

  Len = (PCHAR) CharPos1 - (PCHAR) Name;

  for (I = 0; I < Len; I++)
  {
    if (strchr(".+,;=[] ", ShortName[I]))
    {
      if (Len > 1)
      {
        memmove(&ShortName[I], &ShortName[I + 1], Len - I);
        Len--;
        I--;
      }
      else
      {
        ShortName[I] = '_';
      }
    }
  }

  if (Len > 8)
  {
    sprintf(NumberStr, "%d", NameNumber);
    sprintf(&ShortName[7 - strlen(NumberStr)], "~%s", NumberStr);
    Result = 1;
  }
  else
  {
    ShortName[Len] =
      Result        = 0;
  }

  CharPos2 = CharPos1;

  while (*(++CharPos2))
  {
    if (strchr(".+,;=[] ", *CharPos2))
    {
      *CharPos2 = '_';
    }
  }

  strcat(ShortName, CharPos1);

  return Result;
}
