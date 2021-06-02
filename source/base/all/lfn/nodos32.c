//#include <direct.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_LFN

#include "base/all/includes.h"


/*-----------------BASE_LFN_FindFirst------------------------------------*/

INT     BASE_LFN_FindFirst(PCHAR Specification, INT Attr,
                      pBASE_LFN_FINDSTRUCT DirStruc)
{
struct findi64_t
         *FindStruc;

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
struct findi64_t
         *FindStruc;

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

