#include <errno.h>

#define INCL_BASE_STATE_EXCLUSIVE

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR

#include "base/all/includes.h"


/*-----------------BASE_STATE_WriteFile----------------------------------*/

INT     BASE_STATE_WriteFile(INT Handle, PVOID Buf, INT Len,
                             BOOL IsUncompressedSize)
{
INT       Wrote;

  if (Len)
  {
    BASE_STATE_OutputProgress(0, Len, IsUncompressedSize ? Len : 0, 0, 0);
  }


  errno = 0;
  Wrote = write(Handle, Buf, Len);

  if ((Wrote != Len) || errno)
  {
    BASE_ERROR.ErrorCode = BASE_ERROR_READ;
    errno = 12;
  }

  return Wrote;
}

/*-----------------BASE_STATE_TestOnly-----------------------------------*/

void    BASE_STATE_TestOnly(INT Len, BOOL IsUncompressedSize)
{
  if (Len)
  {
    BASE_STATE_OutputProgress(0, Len, IsUncompressedSize ? Len : 0, 0, 0);
  }
}

/*-----------------BASE_STATE_OutputProgress-----------------------------*/

void    BASE_STATE_OutputProgress(INT ReadBytes, INT WriteBytes,
                                  INT UnCprBytes, INT CprBytes,
                                  INT Attributes)
{
BOOL      DoInit,
          IsFileStart;

  if (BASE_ERROR.ErrorCode)
  {
    return;
  }

  IsFileStart = !ReadBytes && !WriteBytes && !UnCprBytes && Attributes!=-1;

  DoInit = !BASE_STATE.IsInitialized;

  if (DoInit)
  {
    BASE_STATE.IsInitialized       = 1;

    BASE_STATE.SavedUnComprBytes   =
      BASE_STATE.SavedComprBytes   =
      BASE_STATE.TotalUnComprBytes =
      BASE_STATE.TotalComprBytes   =
      BASE_STATE.ReadBytes         =
      BASE_STATE.WriteBytes        =
      BASE_STATE.DirCount          =
      BASE_STATE.FileCount         =
      BASE_STATE.SkipSize          = 0;
  }

  if (IsFileStart)
  {
    BASE_STATE.SavedUnComprBytes = BASE_STATE.SummaryUnComprBytes;
    BASE_STATE.SavedComprBytes   = BASE_STATE.SummaryComprBytes;

    BASE_STATE.TotalUnComprBytes  += BASE_STATE.SkipSize;
    BASE_STATE.SkipSize            = BASE_STATE.NewSkipSize;

    if (!BASE_STATE.DoNotCount)
    {
      BASE_STATE.SummaryFileCount += !(Attributes & BASE_DOSFUNCS_SUBDIR);
    }

    BASE_STATE.FileCount += !(Attributes & BASE_DOSFUNCS_SUBDIR);
    BASE_STATE.DirCount  += ((Attributes & BASE_DOSFUNCS_SUBDIR) != 0);

    BASE_STATE.FileUnComprBytes =
      BASE_STATE.FileComprBytes = 0;
  }

  BASE_STATE.ReadBytes  += ReadBytes;
  BASE_STATE.WriteBytes += WriteBytes;

  if (BASE_STATE.SkipSize)
  {
    BASE_STATE.TotalUnComprBytes += UnCprBytes;
    BASE_STATE.SkipSize          -= UnCprBytes;
  }

  if (!BASE_STATE.DoNotCount)
  {
    BASE_STATE.SummaryUnComprBytes += UnCprBytes;
    BASE_STATE.SummaryComprBytes   += CprBytes;
  }

  BASE_STATE.FileUnComprBytes += UnCprBytes;
  BASE_STATE.FileComprBytes   += CprBytes;
  BASE_STATE.TotalComprBytes  += CprBytes;

  BASE_STATE_EXTERN_OutputProgressEnd(DoInit,IsFileStart);
}

/*-----------------BASE_STATE_OutputCRCOk--------------------------------*/

void    BASE_STATE_OutputCRCOk(BOOL CRCIsOk)
{
  if (BASE_ERROR.ErrorCode)
  {
    return;
  }

  BASE_STATE_EXTERN_OutputCRCOkEnd(CRCIsOk);
}
