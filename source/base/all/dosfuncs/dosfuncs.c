
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define INCL_BASE_DOSFUNCS_EXCLUSIVE

#define INCL_BASE_CONVERT
#define INCL_BASE_LFN
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE

#include "base/all/includes.h"


/*-----------------BASE_DOSFUNCS_SetDir----------------------------------*/

void    BASE_DOSFUNCS_SetDir(PCHAR Dir)
{
tLFN 	  SystemDir;

  if (Dir[1] == ':')
  {
    BASE_DOSFUNCS_SetDrive(BASE_CONVERT_UpCase(Dir[0]) - 'A');
  }

  strcpy(SystemDir, Dir);
  BASE_PATHFUNC_ToSystemPathSeparatorN(SystemDir, strlen(SystemDir));

  BASE_LFN_ChangeDir(SystemDir);
}

/*-----------------BASE_DOSFUNCS_FileExists------------------------------*/

BOOL    BASE_DOSFUNCS_FileExists(PCHAR FileName)
{
struct stat 
          StatBuf;

  return !stat(BASE_LFN_ShortName(FileName), &StatBuf)
         && !strpbrk((PCHAR) FileName, "?*") && FileName[0];
}

/*-----------------BASE_DOSFUNCS_GetDrive--------------------------------*/

INT     BASE_DOSFUNCS_GetDrive(void)
{
tLFN      Directory;

  getcwd(Directory, sizeof(Directory));

  return Directory[0] >= 'a' ? Directory[0] - 'a' : Directory[0] - 'A';
}

/*-----------------BASE_DOSFUNCS_CalcFileTime----------------------------*/

tBASE_DOSFUNCS_FileTime BASE_DOSFUNCS_CalcFileTime(ULONG MSDOSTime)
{
tBASE_DOSFUNCS_FileTime Time;

  Time.Second   = ((MSDOSTime >>  0) & 31) << 1;
  Time.Minute   = (MSDOSTime >>  5) & 63;
  Time.Hour  = (MSDOSTime >>  11) & 31;
  Time.Day  = (MSDOSTime >> 16) & 31;
  Time.Month   = (MSDOSTime >> 21) & 15;
  Time.Year  = (MSDOSTime >> 25) & 127; /* since 1980 */
  
  return Time;
}
