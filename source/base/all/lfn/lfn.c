#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __HAS_IO_H__
	#include <io.h>
#endif

#define INCL_BASE_LFN_EXCLUSIVE

#define INCL_BASE_DOSFUNCS

#include "base/all/includes.h"


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
