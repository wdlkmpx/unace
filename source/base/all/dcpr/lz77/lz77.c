#include <string.h>

#define INCL_BASE_DCPR_LZ77_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_HUFF
#define INCL_BASE_MEMORY
#define INCL_BASE_STATE

#include "base/all/includes.h"


#ifndef USE_ASM
  #include "base/all/dcpr/lz77/c/lz77.c"
#endif

/*-----------------BASE_DCPR_LZ77_CalcHuffTabs---------------------------*/

INT     BASE_DCPR_LZ77_CalcHuffTabs(void)
{
  if (!BASE_DCPR_HUFF_ReadWidths(BASE_CPRDCPR_LZ77_MAXCODEWIDTH,
                                 (PUSHORT) BASE_DCPR_LZ77.MainHuffSymbols,
                                 (PUSHORT) BASE_DCPR_LZ77.MainHuffWidths,
                                 BASE_CPRDCPR_LZ77_MAXMAINCODE)
      || !BASE_DCPR_HUFF_ReadWidths(BASE_CPRDCPR_LZ77_MAXCODEWIDTH,
                                    (PUSHORT) &BASE_DCPR_LZ77.LenHuffSymbols,
                                    (PUSHORT) &BASE_DCPR_LZ77.LenHuffWidths,
                                    BASE_CPRDCPR_LZ77_MAXLENCODE))
  {
    return 0;
  }

  BASE_DCPR_LZ77.BlockSize = BASE_DCPR.ReadCode >> (32 - 15);
  BASE_DCPR_AddBits(15);

  return 1;
}

/*-----------------BASE_DCPR_LZ77_Block----------------------------------*/

INT     BASE_DCPR_LZ77_Block(PCHAR Buf, INT Len)
{
INT       OldPos,
          I;

  OldPos = BASE_DCPR_LZ77.DictionaryPos;
  BASE_DCPR_LZ77.BLOCK_ByteCount = 0;

  if (Len < BASE_CPRDCPR_LZ77_MAXLEN)
  {
    return 0;
  }

  if ((BASE_DCPR_LZ77.BLOCK_BufSize = Len - BASE_CPRDCPR_LZ77_MAXLEN)
      > BASE_DCPR.FileSize)
  {
    BASE_DCPR_LZ77.BLOCK_BufSize = BASE_DCPR.FileSize;
  }

  if (BASE_DCPR_LZ77.BLOCK_BufSize >
      BASE_DCPR_LZ77.DictionarySize - BASE_CPRDCPR_LZ77_MAXLEN)
  {
    BASE_DCPR_LZ77.BLOCK_BufSize =
      BASE_DCPR_LZ77.DictionarySize - BASE_CPRDCPR_LZ77_MAXLEN;
  }

  if ((LONGLONG) BASE_DCPR.FileSize > 0
      && BASE_DCPR_LZ77.BLOCK_BufSize)
  {
    BASE_DCPR_LZ77_BlockCore();

    if (BASE_DCPR_LZ77.BLOCK_ByteCount <= Len)
    {
      if (OldPos + BASE_DCPR_LZ77.BLOCK_ByteCount
          > BASE_DCPR_LZ77.DictionarySize)
      {
        I = BASE_DCPR_LZ77.DictionarySize - OldPos;
        memcpy(Buf, &BASE_DCPR_LZ77.Dictionary[OldPos], I);
        memcpy(&Buf[I], BASE_DCPR_LZ77.Dictionary,
               BASE_DCPR_LZ77.BLOCK_ByteCount - I);
      }
      else
      {
        memcpy(Buf, &BASE_DCPR_LZ77.Dictionary[OldPos],
               BASE_DCPR_LZ77.BLOCK_ByteCount);
      }
    }
  }

  BASE_DCPR.FileSize -= BASE_DCPR_LZ77.BLOCK_ByteCount;

  BASE_DCPR_EXTERN_BlockCopyToCprDictionary(
    Buf, BASE_DCPR_LZ77.BLOCK_ByteCount);

  return BASE_DCPR_LZ77.BLOCK_ByteCount;
}

/*-----------------BASE_DCPR_LZ77_PreprocessBlock------------------------*/

INT     BASE_DCPR_LZ77_PreprocessBlock(PCHAR Buf, INT Len)
{
INT       I,
          R,
          Pos,
          Read;

  if (BASE_DCPR.Type == BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA)
  {
    if (!BASE_DCPR_LZ77.PREP_NumKeptBytes
        /*BASE_DCPR.NextType == BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA
        && PREP_NumKeptBytes < BASE_CPRDCPR_LZ77_MAXDELTABLOCK*/)
    {
      BASE_DCPR_LZ77.DeltaDist = BASE_DCPR_LZ77.NextDeltaDist;
      BASE_DCPR_LZ77.DeltaLen  = BASE_DCPR_LZ77.NextDeltaLen;
      BASE_DCPR_LZ77.NextDeltaLen = 0;

//      MaxDeltaBlockSize = BASE_CPRDCPR_LZ77_MAXDELTABLOCK
//                          - BASE_CPRDCPR_LZ77_MAXDELTABLOCK % DeltaDist;

      do
      {
        BASE_DCPR_LZ77.PREP_NumKeptBytes +=
          (Read = BASE_DCPR_LZ77_Block(
                    (PCHAR) &BASE_DCPR_LZ77.PREP_KeptBytesBuf[
                              BASE_DCPR_LZ77.PREP_NumKeptBytes],
                    BASE_CPRDCPR_LZ77_MAXDELTABLOCK
                    + BASE_CPRDCPR_LZ77_MAXLEN
                    - BASE_DCPR_LZ77.PREP_NumKeptBytes));

      } while (BASE_DCPR_LZ77.PREP_NumKeptBytes < BASE_DCPR_LZ77.DeltaLen);

      BASE_DCPR_LZ77.DeltaBlockSize = BASE_DCPR_LZ77.PREP_NumKeptBytes;

      BASE_DCPR_LZ77.DeltaPlaneSize =
        BASE_DCPR_LZ77.DeltaBlockSize / BASE_DCPR_LZ77.DeltaDist;

      BASE_DCPR.OverNextType = BASE_DCPR.NextType;
      BASE_DCPR.NextType     = BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA;

      for (I = 0; I < BASE_DCPR_LZ77.DeltaBlockSize; I++)
      {
        BASE_DCPR_LZ77.PREP_LastDelta =
          (BASE_DCPR_LZ77.PREP_KeptBytesBuf[I]
            += BASE_DCPR_LZ77.PREP_LastDelta);
      }

      BASE_DCPR_LZ77.PREP_KeptBytesPos =
        BASE_DCPR_LZ77.DeltaPlane      =
        BASE_DCPR_LZ77.DeltaPlanePos   = 0;
    }

    R = BASE_DCPR_LZ77.PREP_NumKeptBytes > Len ?
          Len : BASE_DCPR_LZ77.PREP_NumKeptBytes;

    if (BASE_DCPR_LZ77.DeltaPlaneSize)
    {
      for (I = 0; ; BASE_DCPR_LZ77.DeltaPlanePos++)
      {
        for (;BASE_DCPR_LZ77.DeltaPlane < BASE_DCPR_LZ77.DeltaBlockSize;
              BASE_DCPR_LZ77.DeltaPlane += BASE_DCPR_LZ77.DeltaPlaneSize ,
                I++)
        {
          if (I == R)
          {
            goto BREAK;
          }

          Buf[I] = BASE_DCPR_LZ77.PREP_KeptBytesBuf[
                     BASE_DCPR_LZ77.DeltaPlanePos
                     + BASE_DCPR_LZ77.DeltaPlane];
        }

        BASE_DCPR_LZ77.DeltaPlane = 0;
      }
    }

    BREAK: {}

    BASE_DCPR_LZ77.PREP_KeptBytesPos += R;
    BASE_DCPR_LZ77.PREP_NumKeptBytes -= R;

    if (!BASE_DCPR_LZ77.PREP_NumKeptBytes)
    {
      BASE_DCPR.NextType = BASE_DCPR.OverNextType;
    }

    return R;
  }
  else
  {
    memcpy(Buf, BASE_DCPR_LZ77.PREP_KeptBytesBuf,
           BASE_DCPR_LZ77.PREP_NumKeptBytes);

    R = BASE_DCPR_LZ77_Block(&Buf[BASE_DCPR_LZ77.PREP_NumKeptBytes],
                             Len - BASE_DCPR_LZ77.PREP_NumKeptBytes)
        + BASE_DCPR_LZ77.PREP_NumKeptBytes;

    BASE_DCPR_LZ77.PREP_NumKeptBytes = 0;

    switch (BASE_DCPR.Type)
    {
      case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
      {
        BASE_DCPR_LZ77.ExeMode  = BASE_DCPR_LZ77.NextExeMode;

        for (I = 0; I < R - 4; I++)
        {
          Pos = BASE_DCPR.FilePos + I;

          if (Buf[I] == (CHAR) 0xe8)
          {
            if (!BASE_DCPR_LZ77.ExeMode)
            {
              ADJUST_ENDIANNESS16(&Buf[I + 1]);
              *((PUSHORT) &Buf[I + 1]) -= Pos;
              ADJUST_ENDIANNESS16(&Buf[I + 1]);
              
              I += 2;
            }
            else
            {
              ADJUST_ENDIANNESS32(&Buf[I + 1]);
              *((PULONG)  &Buf[I + 1]) -= Pos;
              ADJUST_ENDIANNESS32(&Buf[I + 1]);              

              I += 4;
            }
          }
          else
          {
            if (Buf[I] == (CHAR) 0xe9)
            {
              ADJUST_ENDIANNESS16(&Buf[I + 1]);
              *((PUSHORT) &Buf[I + 1]) -= Pos;
              ADJUST_ENDIANNESS16(&Buf[I + 1]);
              
              I   += 2;
            }
          }
        }

        for (; I < R; I++)
        {
          if (Buf[I] == (CHAR) 0xe8 || Buf[I] == (CHAR) 0xe9)
          {
            BASE_DCPR_LZ77.PREP_NumKeptBytes = R - I;

            memcpy(BASE_DCPR_LZ77.PREP_KeptBytesBuf, &Buf[I],
                   BASE_DCPR_LZ77.PREP_NumKeptBytes);

            break;
          }
        }
      }
    }

    return R - BASE_DCPR_LZ77.PREP_NumKeptBytes;
  }
}

/*-----------------BASE_DCPR_LZ77_CopyToDictionary-----------------------*/

void    BASE_DCPR_LZ77_CopyToDictionary(PCHAR Buf, INT Len)
{
INT       I;

  for (I = 0; I < Len; I++)
  {
    BASE_DCPR_LZ77.Dictionary[BASE_DCPR_LZ77.DictionaryPos] = Buf[I];

    BASE_DCPR_LZ77.DictionaryPos =
        (BASE_DCPR_LZ77.DictionaryPos + 1) & BASE_DCPR_LZ77.DictionaryAnd;
  }
}

/*-----------------BASE_DCPR_LZ77_ReadSymbols----------------------------*/

INT     BASE_DCPR_LZ77_ReadSymbols(void)
{
  if (!BASE_DCPR_LZ77.BlockSize && !BASE_DCPR_LZ77_CalcHuffTabs())
  {
    return 0;
  }

  BASE_DCPR_LZ77.PartSize =
    (BASE_DCPR_LZ77_MAXPARTSIZE > BASE_DCPR_LZ77.BlockSize) ?
      BASE_DCPR_LZ77.BlockSize : BASE_DCPR_LZ77_MAXPARTSIZE;

  BASE_DCPR_LZ77.BlockSize -= BASE_DCPR_LZ77.PartSize;

  BASE_DCPR_LZ77_ReadSymbolsCore();

  BASE_DCPR_LZ77.LenDistBufPos =
    BASE_DCPR_LZ77.MainBufPos  = 0;

  return 1;
}
