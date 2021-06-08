#ifdef _WIN32
	#include <io.h>
#endif

#include <stdio.h>
#include <string.h>

#define INCL_BASE_DOSFUNCS

#include "base/includes.h"


/*-----------------BASE_DOSFUNCS_LSeek-----------------------------------*/

LONGLONG
        BASE_DOSFUNCS_LSeek(INT Handle, LONGLONG Offset, INT Origin)
{
  return lseek(Handle, (INT)Offset, Origin);
}

/*-----------------BASE_DOSFUNCS_Tell------------------------------------*/

LONGLONG
        BASE_DOSFUNCS_Tell(INT Handle)
{
  return lseek(Handle, 0, SEEK_CUR);
}
