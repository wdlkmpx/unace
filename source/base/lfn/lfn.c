#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef _WIN32
	#include <io.h>
	#include <direct.h>
#else
	#define mkdir(_a) mkdir(_a,  S_IRWXU | S_IRWXG | S_IRWXO)
#endif

#define INCL_BASE_LFN_EXCLUSIVE

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC
#include "base/includes.h"


/*-----------------BASE_LFN_ChangeDir------------------------------------*/

INT     BASE_LFN_ChangeDir(PCHAR Directory)
{
//  return chdir(BASE_LFN_ShortName(Directory));
  return chdir(BASE_LFN_ShortNameChangeDir(Directory));
}

/*-----------------BASE_LFN_GetCurrentDir--------------------------------*/

PCHAR   BASE_LFN_GetCurrentDir(PCHAR Directory, size_t Size)
{
  Directory = (PCHAR) getcwd(Directory, Size);

  return Directory;
}

/*-----------------BASE_LFN_GetCurrentDirOfDrive-------------------------*/

PCHAR   BASE_LFN_GetCurrentDirOfDrive(INT Drive, PCHAR Directory, size_t Size)
{
INT       SavedDrive;

  SavedDrive = BASE_DOSFUNCS_GetDrive();
  BASE_DOSFUNCS_SetDrive(Drive);
  BASE_LFN_GetCurrentDir(Directory, Size);
  BASE_DOSFUNCS_SetDrive(SavedDrive);

  return Directory;
}

/*-----------------BASE_LFN_Open-----------------------------------------*/

INT     BASE_LFN_Open(PCHAR Path, INT Access,...)
{
INT       Permission;
va_list   ArgumentList;

  if (Access & O_CREAT)
  {
    va_start(ArgumentList, Access);
    Permission = va_arg(ArgumentList, INT);

    va_end(ArgumentList);

    BASE_LFN_CheckExistence(Path);
  }

  return open(BASE_LFN_ShortName(Path), Access, Permission);
}

/*-----------------BASE_LFN_ShareOpen------------------------------------*/

INT     BASE_LFN_ShareOpen(PCHAR Path, INT Access, BOOL WriteAccess,...)
{
INT       Permission;
va_list   ArgumentList;

  if (Access & O_CREAT)
  {
    va_start(ArgumentList, WriteAccess);
    Permission = va_arg(ArgumentList, INT);

    va_end(ArgumentList);

    BASE_LFN_CheckExistence(Path);
  }

  return
    BASE_DOSFUNCS_ShareOpen(BASE_LFN_ShortName(Path), Access,
                            WriteAccess, Permission);
}

/*-----------------BASE_LFN_GetFileAttributes----------------------------*/

UINT    BASE_LFN_GetFileAttributes(PCHAR Path, PUINT Attr)
{
  return BASE_DOSFUNCS_GetFileAttributes(BASE_LFN_ShortName(Path), Attr);
}

/*-----------------BASE_LFN_SetFileAttributes----------------------------*/

UINT    BASE_LFN_SetFileAttributes(PCHAR Path, UINT Attr)
{
  return BASE_DOSFUNCS_SetFileAttributes(BASE_LFN_ShortName(Path), Attr);
}

/*-----------------BASE_LFN_RemoveFile-----------------------------------*/

INT     BASE_LFN_RemoveFile(PCHAR Path)
{
  return remove(BASE_LFN_ShortName(Path));
}

/*-----------------BASE_LFN_Access---------------------------------------*/

INT     BASE_LFN_Access(PCHAR Path, INT Mode)
{
PCHAR     ShortPath;

  ShortPath = BASE_LFN_ShortName(Path);

  if (!ShortPath[0])
  {
    errno = ENOENT;

    return -1;
  }

  return access(ShortPath, Mode);
}

/*-----------------BASE_LFN_GetFileTime----------------------------------*/

ULONG   BASE_LFN_GetFileTime(PCHAR FileName)
{
struct findi64_t
          FindStruc;
INT       Handle,
          Result;
USHORT    Date,
          Time;

  if (-1 == (Handle = BASE_LFN_Open(BASE_LFN_ShortName(FileName), 0)))
  {
    if (_dos_findfirsti64(BASE_LFN_ShortName(FileName),
          BASE_LFN_GetFindAllFilesAndDirsAttr(), &FindStruc))
    {
      return 0;
    }

    Result = FindStruc.wr_date << 16 | FindStruc.wr_time;
    _dos_findclosei64(&FindStruc);

    return Result;
  }

  BASE_DOSFUNCS_GetFileTime(Handle, &Date, &Time);
  close(Handle);

  return Date << 16 | Time;
}



// ============================================================================
// lin.c

static char * my_strsep(char **stringp, char *delim)
{
  char *start = *stringp;
  char *cp;
  char ch;

  if (start == NULL)
    return NULL;

  for (cp = start; ch = *cp; cp++) {
    if (strchr(delim, ch)) {
      *cp++ = 0;
      *stringp = cp;
      return start;
    }
  }
  *stringp = NULL;
  return start;
}
#undef strsep
#define strsep my_strsep

/*-----------------BASE_LFN_CompleteArg0---------------------------------*/
void    BASE_LFN_CompleteArg0(PCHAR *Arg0)
{
PCHAR  Env, SepStr;
struct stat st;
tLFN   SearchFile, Path;

  strcpy(SearchFile, *Arg0);

  if (SearchFile[0] != '.')
  {
    SepStr = getenv("PATH");

    if ((Env = (PCHAR) BASE_MEMORY_GetMem(strlen(SepStr) + 1)))
    {
      strcpy(Env, SepStr);
      SepStr = Env;

      while (SepStr)
      {
       sprintf(Path, "%s/%s", strsep(&SepStr, ":"), SearchFile);

        if (!stat(Path, &st))
        {
          strcpy(SearchFile, Path);

          break;
        }
      }

      BASE_MEMORY_FreeCheck(Env);
    }
  }

  strcpy(BASE_LFN.Arg0, SearchFile);
  *Arg0 = BASE_LFN.Arg0;
}

/*-----------------BASE_LFN_ExtendPath-----------------------------------*/
PCHAR   BASE_LFN_ExtendPath(PCHAR Path, INT MaxLen)
{
  return Path;
}

/*-----------------BASE_LFN_ShortName------------------------------------*/
PCHAR   BASE_LFN_ShortName(PCHAR Path)
{
  return Path;
}

/*-----------------BASE_LFN_LongName-------------------------------------*/
PCHAR   BASE_LFN_LongName(PCHAR Path)
{
  return Path;
}

/*-----------------BASE_LFN_DriveSupportsLFN-----------------------------*/
BOOL    BASE_LFN_DriveSupportsLFN(PCHAR Drive)
{
  return 1;
}

/*-----------------BASE_LFN_MakeDir--------------------------------------*/
INT     BASE_LFN_MakeDir(PCHAR Dir)
{
INT	  Result;

  Result = mkdir(Dir);
  if (!Result) chmod(Dir, 0755);
  return Result;
}


// ============================================================================
// nodos32.c

/*-----------------BASE_LFN_FindFirst------------------------------------*/
INT     BASE_LFN_FindFirst(PCHAR Specification, INT Attr,
                      pBASE_LFN_FINDSTRUCT DirStruc)
{
struct findi64_t *FindStruc;
  FindStruc = (struct findi64_t*) &DirStruc->DosFindStruct;

  if (_dos_findfirsti64(Specification, Attr, FindStruc))
  {
    errno = -1;
    return 1;
  }

  strcpy(DirStruc->Name, FindStruc->name);
  DirStruc->Attributes = FindStruc->attrib;
  DirStruc->Time = FindStruc->wr_time;
  DirStruc->Date = FindStruc->wr_date;
  DirStruc->Size = FindStruc->size;

  return 0;
}

/*-----------------BASE_LFN_FindNext-------------------------------------*/
INT     BASE_LFN_FindNext(pBASE_LFN_FINDSTRUCT DirStruc)
{
struct findi64_t *FindStruc;

  FindStruc = (struct findi64_t*) &DirStruc->DosFindStruct;

  if (_dos_findnexti64(FindStruc))
  {
    errno = -1;
    return 1;
  }
  strcpy(DirStruc->Name, FindStruc->name);

  DirStruc->Attributes = FindStruc->attrib;
  DirStruc->Time = FindStruc->wr_time;
  DirStruc->Date = FindStruc->wr_date;
  DirStruc->Size = FindStruc->size;

  return 0;
}

/*-----------------BASE_LFN_FindClose------------------------------------*/
INT     BASE_LFN_FindClose(pBASE_LFN_FINDSTRUCT DirStruc)
{
  if (_dos_findclosei64((struct findi64_t*)&DirStruc->DosFindStruct))
  {
    errno = -1;
    return 1;
  }

  return 0;
}

/*-----------------BASE_LFN_CheckExistence-------------------------------*/
void    BASE_LFN_CheckExistence(PCHAR Path)
{
}

/*-----------------BASE_LFN_RemoveDir------------------------------------*/
INT     BASE_LFN_RemoveDir(PCHAR Dir)
{
  return rmdir(Dir);
}

/*-----------------BASE_LFN_ShortNameChangeDir---------------------------*/
PCHAR   BASE_LFN_ShortNameChangeDir(PCHAR Path)
{
  return Path;
}



// ============================================================================
// nont.c

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
INT       I, Result, Len;
PCHAR     CharPos1, CharPos2;
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
