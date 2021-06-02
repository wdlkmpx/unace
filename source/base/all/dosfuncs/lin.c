#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>

#ifdef __HAS_IO_H__
	#include <io.h>
#endif

#if defined(__MACOSX__) 
	#include <stdint.h>

#endif

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_PATHFUNC

#include "base/all/includes.h"


/*-----------------_dos_findfirsti64-------------------------------------*/

UINT    _dos_findfirsti64(CHAR *Path, UINT Attr, struct findi64_t *Bufi64)
{
DIR      *DirStruc;
struct stat
          StatBuf;
tLFN	  DirToOpen,
	  SearchMask;
PCHAR	  ChPtr;

  if (stat(BASE_LFN_ShortName(Path), &StatBuf))
  {
    return 1;
  }
  else
  {
    strcpy(DirToOpen, Path);

    if (!(StatBuf.st_mode & S_IFDIR))
    {
      BASE_PATHFUNC_CompletePath(DirToOpen);

      if (ChPtr = strrchr(DirToOpen, BASE_PATHFUNC_SEPARATOR))
      {
        strcpy(SearchMask, ChPtr + 1);
    
        if (ChPtr == DirToOpen)
	{
          ChPtr++;
	}

        *ChPtr = 0;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      strcpy(SearchMask, "*");
    }

    if ((DirStruc = opendir(DirToOpen)) == NULL)
    {
      return 1;
    }
    else
    {
      *(DIR**) &Bufi64->reserved[0] = DirStruc;
      strcpy(Bufi64->SearchMask, SearchMask);

      return _dos_findnexti64(Bufi64);
    }
  }
}

/*-----------------_dos_findnexti64--------------------------------------*/

UINT    _dos_findnexti64(struct findi64_t *Bufi64)
{
DIR      *Dir;
struct dirent
	 *Ent;

  Dir = *(DIR**) &Bufi64->reserved[0];

  while (1)
  {
    if ((Ent = readdir(Dir)) == NULL)
    {
      return 1;
    }
    else
    {
      if (BASE_PATHFUNC_WildCardCheck(Ent->d_name, Bufi64->SearchMask))
      {
        memcpy(Bufi64, Dir, sizeof(Dir));
        Bufi64->size = 0;//_filelengthi64(Dir->dd_handle);
        strcpy(Bufi64->name, Ent->d_name);
        *(DIR**) &Bufi64->reserved[0] = Dir;

        return 0;
      }
    }
  }
}

/*-----------------_dos_findclosei64-------------------------------------*/

UINT    _dos_findclosei64( struct findi64_t *Bufi64)
{
  return closedir(*(DIR**) &Bufi64->reserved[0]);
}

/*-----------------_filelengthi64----------------------------------------*/

LONGLONG
        _filelengthi64(INT Handle)
{
LONGLONG
 	OldPos,
	EndPos;

  OldPos = lseek(Handle, 0, SEEK_CUR);
  EndPos = lseek(Handle, 0, SEEK_END);
  lseek(Handle, OldPos, SEEK_SET);

  return EndPos;
}

/*-----------------BASE_DOSFUNCS_IsDir-----------------------------------*/

BOOL	BASE_DOSFUNCS_IsDir(PCHAR Name)
{
struct stat
          StatBuf;

  if (!stat(BASE_LFN_ShortName(Name), &StatBuf))
  {
    return !(StatBuf.st_mode & S_IFDIR);
  }

  return 0;
}

/*-----------------BASE_DOSFUNCS_SetFileTime-----------------------------*/

void    BASE_DOSFUNCS_SetFileTime(PCHAR FileName, INT Handle, ULONG MSDOSTime)
{
struct utimbuf UTimeBuf;
struct tm TimeTM;

  TimeTM.tm_sec   = ((MSDOSTime >>  0) & 31) << 1;
  TimeTM.tm_min   = (MSDOSTime >>  5) & 63;
  TimeTM.tm_hour  = (MSDOSTime >> 11) & 31;
  TimeTM.tm_mday  = (MSDOSTime >> 16) & 31;
  TimeTM.tm_mon   = (MSDOSTime >> 21) & 15;
  TimeTM.tm_year  = 80 + ((MSDOSTime >> 25) & 127);
  TimeTM.tm_isdst = -1; // divine, if tm_hour is summer or winter time

  UTimeBuf.modtime  = UTimeBuf.actime = mktime(&TimeTM);

  utime(FileName, &UTimeBuf);
}

/*-----------------BASE_DOSFUNCS_SetDrive--------------------------------*/

void    BASE_DOSFUNCS_SetDrive(INT Drive)
{
tLFN      Directory;

  Directory[0] = 'A' + Drive;
  Directory[1] = ':';
  Directory[2] = 0;

  chdir(Directory);

  if (BASE_DOSFUNCS_GetDrive() != Drive)
  {
    BASE_ERROR.HardwareError      = 2;
    BASE_ERROR.HardwareErrorDrive = Drive;
  }
}

/*-----------------BASE_DOSFUNCS_ShareOpen-------------------------------*/

INT     BASE_DOSFUNCS_ShareOpen(PCHAR Path, INT Access, BOOL WriteAccess,
                                INT Permission)
{
  return open(Path, Access, Permission);
}

/*-----------------BASE_DOSFUNCS_GetFileAttributes-----------------------*/

UINT    BASE_DOSFUNCS_GetFileAttributes(PCHAR Path, PUINT Attr)
{
  struct stat StatBuf;

  if (stat(BASE_LFN_ShortName(Path), &StatBuf) == 0)
  {
    *Attr = 0;
  
    if (!(StatBuf.st_mode & S_IWUSR))
    {
      *Attr |= BASE_DOSFUNCS_RDONLY;
    }
  
    if (StatBuf.st_mode & S_IFDIR)
    {
      *Attr |= BASE_DOSFUNCS_SUBDIR;
    }
    
    return 0;
  }
  else
  {
    return 1; // error!
  }
}

/*-----------------BASE_DOSFUNCS_SetFileAttributes-----------------------*/

UINT    BASE_DOSFUNCS_SetFileAttributes(PCHAR Path, UINT Attr)
{
struct stat
          StatBuf;

  if (Attr & BASE_DOSFUNCS_RDONLY)
  {
    if (!stat(BASE_LFN_ShortName(Path), &StatBuf))
    {
      chmod(Path, StatBuf.st_mode & 0555);
    }
  }
 
  return 0;
}

/*-----------------BASE_DOSFUNCS_GetFileTime-----------------------------*/

UINT    BASE_DOSFUNCS_GetFileTime(INT Handle, PUSHORT Date, PUSHORT Time)
{
  return 1; // error!
}

/*-----------------BASE_DOSFUNCS_Initialize------------------------------*/

void    BASE_DOSFUNCS_Initialize(void)
{
}

/*-----------------BASE_DOSFUNCS_GetFileSecurity------------------------*/

void    BASE_DOSFUNCS_GetFileSecurity(PCHAR FileName, PCHAR *Security, PUINT Size)
{
  *Size = 0;
  *Security = NULL;
}

/*-----------------BASE_DOSFUNCS_SetFileSecurity------------------------*/

void    BASE_DOSFUNCS_SetFileSecurity(PCHAR FileName, PCHAR Security)
{
}
