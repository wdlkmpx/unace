#include <errno.h>

#define INCL_APPS_EXE_OUTPTERR_EXCLUSIVE

#define INCL_BASE_ERROR

#include "base/includes.h"

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#include "unace_includes.h"


/*-----------------APPS_EXE_OUTPTERR_OutputError-------------------------*/

void    APPS_EXE_OUTPTERR_OutputError(PCHAR TextStr1, PCHAR TextStr2)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(
    STR.Error ? STR.Error : "Error", TextStr1, TextStr2);

  BASE_ERROR.HardwareError =
    errno             = 0;
}
