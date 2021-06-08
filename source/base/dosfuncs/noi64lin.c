#ifdef __HAS_IO_H__
	#include <io.h>
#endif

#include <stdio.h>

#define INCL_BASE_DOSFUNCS

#include "base/includes.h"


/*-----------------BASE_DOSFUNCS_IsChSizeSupported-----------------------*/

BOOL    BASE_DOSFUNCS_IsChSizeSupported(void)
{
  return 1;
}

/*-----------------BASE_DOSFUNCS_ChSize----------------------------------*/

LONGLONG
        BASE_DOSFUNCS_ChSize(INT Handle, LONGLONG Size)
{
  return ftruncate(Handle , Size);
}
