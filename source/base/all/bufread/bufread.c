#include <errno.h>
#include <fcntl.h>

#ifdef __HAS_IO_H__
	#include <io.h>
#endif

#include <string.h>
#include <stdio.h>

#define INCL_BASE_BUFREAD_EXCLUSIVE

#define INCL_BASE_ERROR
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROROUT
#define INCL_BASE_MEMORY

#include "base/all/includes.h"


/*-----------------BASE_BUFREAD_Read-------------------------------------*/

INT     BASE_BUFREAD_Read(PCHAR Buf, UINT Len)
{
INT       BytesToRead,
          Read;

  Read = 0;

  while (Len && BASE_BUFREAD.Buf)
  {
    if (BASE_BUFREAD.BufPos >= BASE_BUFREAD.BufEnd)
    {
      BASE_BUFREAD.ReadPos = BASE_BUFREAD.FilePos -
          BASE_BUFREAD.FilePos % BASE_BUFREAD.BufSize;

      BASE_DOSFUNCS_LSeek(BASE_BUFREAD.Handle, BASE_BUFREAD.ReadPos, SEEK_SET);

      BASE_BUFREAD.BufPos =
        BASE_BUFREAD.FilePos - BASE_BUFREAD.ReadPos;

      errno = 0;

      BASE_BUFREAD.FilePos =
        (BASE_BUFREAD.BufEnd = read(BASE_BUFREAD.Handle, BASE_BUFREAD.Buf, BASE_BUFREAD.BufSize))
        + BASE_BUFREAD.ReadPos;

      if (errno)
      {
        BASE_ERROROUT_EXTERN_ReadArchive();
        BASE_ERROR.ErrorCode = BASE_ERROR_READ;
      }
    }

    if (BASE_BUFREAD.BufPos >= BASE_BUFREAD.BufEnd)
    {
      errno = 1;
      return Read;
    }

    BytesToRead = BASE_BUFREAD.BufEnd - BASE_BUFREAD.BufPos;

    if (BytesToRead > Len)
    {
      BytesToRead = Len;
    }

    memcpy(Buf, BASE_BUFREAD.Buf + BASE_BUFREAD.BufPos, BytesToRead);

    Len  -= BytesToRead;
    Buf  += BytesToRead;
    Read += BytesToRead;
    BASE_BUFREAD.BufPos += BytesToRead;
  }

  return Read;
}

/*-----------------BASE_BUFREAD_Seek-------------------------------------*/

void    BASE_BUFREAD_Seek(ULONGLONG Pos, INT Mode)
{
ULONGLONG FilePos;

  BASE_DOSFUNCS_LSeek(BASE_BUFREAD.Handle, BASE_BUFREAD_Tell(), SEEK_SET);
  FilePos = BASE_DOSFUNCS_LSeek(BASE_BUFREAD.Handle, Pos, Mode);

  if (FilePos < BASE_BUFREAD.ReadPos || FilePos >
      BASE_BUFREAD.ReadPos + BASE_BUFREAD.BufEnd)
  {
    BASE_BUFREAD.BufPos   =
      BASE_BUFREAD.BufEnd = 0;

    BASE_BUFREAD.ReadPos   =
      BASE_BUFREAD.FilePos = FilePos;
  }
  else
  {
    BASE_BUFREAD.BufPos = FilePos - BASE_BUFREAD.ReadPos;
  }
}

/*-----------------BASE_BUFREAD_Open-------------------------------------*/

INT     BASE_BUFREAD_Open(PCHAR FileName)
{
  strcpy(BASE_BUFREAD.FileName, FileName);

  if (-1 == (BASE_BUFREAD.Handle =
               BASE_LFN_ShareOpen(FileName, O_RDONLY | O_BINARY, 0)))
  {
    return (-1);
  }

  BASE_BUFREAD.Buf = (PCHAR)
      BASE_MEMORY_GetMemBase2Max(&BASE_BUFREAD.BufSize, 5, 65536);

  BASE_BUFREAD.BufPos    =
    BASE_BUFREAD.BufEnd  =
    BASE_BUFREAD.ReadPos = 0;

  BASE_BUFREAD.FilePos   = BASE_DOSFUNCS_Tell(BASE_BUFREAD.Handle);

  return BASE_BUFREAD.Handle;
}

/*-----------------BASE_BUFREAD_Close------------------------------------*/

void    BASE_BUFREAD_Close(void)
{
  close(BASE_BUFREAD.Handle);
  BASE_BUFREAD.Handle = -1;
  BASE_MEMORY_FreeCheck((PVOID *) &BASE_BUFREAD.Buf);
}

/*-----------------BASE_BUFREAD_Tell-------------------------------------*/

ULONGLONG
        BASE_BUFREAD_Tell(void)
{
  return BASE_BUFREAD.BufPos + BASE_BUFREAD.ReadPos;
}
