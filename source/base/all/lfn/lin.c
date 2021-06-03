#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define INCL_BASE_LFN
#define INCL_BASE_MEMORY

#include "base/all/includes.h"


#ifdef __sun__
static char *
strsep(char **stringp, char *delim)
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
#endif

/*-----------------BASE_LFN_CompleteArg0---------------------------------*/

void    BASE_LFN_CompleteArg0(PCHAR *Arg0)
{
PCHAR	  Env,
	  SepStr;
struct stat
  	  st;
tLFN      SearchFile,
	  Path;

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

      BASE_MEMORY_FreeCheck((PVOID*)&Env);
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

  Result = mkdir(Dir, 0755);
  if (!Result) chmod(Dir, 0755);
  return Result;
}
