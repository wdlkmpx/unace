/*-----------------BASE_DCPR_LZ77_WriteChar------------------------------*/

void    BASE_DCPR_LZ77_WriteChar(CHAR Char)
{
  BASE_DCPR_LZ77.Dictionary[BASE_DCPR_LZ77.DictionaryPos] = Char;

  BASE_DCPR_LZ77.DictionaryPos =
    (BASE_DCPR_LZ77.DictionaryPos + 1) & BASE_DCPR_LZ77.DictionaryAnd;

  BASE_DCPR_LZ77.BLOCK_ByteCount++;
}

/*-----------------BASE_DCPR_LZ77_CopyString-----------------------------*/

void    BASE_DCPR_LZ77_CopyString(ULONG Dist, INT Len)
{
INT       I,
          SourcePos;

  SourcePos =
    (BASE_DCPR_LZ77.DictionaryPos - Dist) & BASE_DCPR_LZ77.DictionaryAnd;

  if ((SourcePos >= BASE_DCPR_LZ77.DictionarySize - BASE_CPRDCPR_LZ77_MAXLEN)
      || (BASE_DCPR_LZ77.DictionaryPos
          >= BASE_DCPR_LZ77.DictionarySize - BASE_CPRDCPR_LZ77_MAXLEN))
  {
    for (I = Len; I--;)
    {
      BASE_DCPR_LZ77.Dictionary[BASE_DCPR_LZ77.DictionaryPos] =
          BASE_DCPR_LZ77.Dictionary[SourcePos];

      BASE_DCPR_LZ77.DictionaryPos =
          (BASE_DCPR_LZ77.DictionaryPos + 1) & BASE_DCPR_LZ77.DictionaryAnd;

      SourcePos = (SourcePos + 1) & BASE_DCPR_LZ77.DictionaryAnd;
    }
  }
  else
  {
    BASE_MEMORY_MemCopy(BASE_DCPR_LZ77.Dictionary
                          + BASE_DCPR_LZ77.DictionaryPos,
                        BASE_DCPR_LZ77.Dictionary + SourcePos, Len);

    BASE_DCPR_LZ77.DictionaryPos =
      (BASE_DCPR_LZ77.DictionaryPos + Len) & BASE_DCPR_LZ77.DictionaryAnd;
  }

  BASE_DCPR_LZ77.BLOCK_ByteCount += Len;
}

/*-----------------BASE_DCPR_LZ77_BlockCore------------------------------*/

void    BASE_DCPR_LZ77_BlockCore(void)
{
INT       Symbol,
          LenSymbol,
          I;
LONG      MatchDist;

  while (BASE_DCPR_LZ77.BLOCK_ByteCount < BASE_DCPR_LZ77.BLOCK_BufSize)
  {
    if (BASE_DCPR_LZ77.MainBufPos == BASE_DCPR_LZ77.PartSize)
    {
      if (!BASE_DCPR_LZ77_ReadSymbols())
      {
        return;
      }
    }

    Symbol = BASE_DCPR_LZ77.MainBuf[BASE_DCPR_LZ77.MainBufPos++];

    if (Symbol > 255)
    {
      if (Symbol == BASE_CPRDCPR_LZ77_TYPECODE)
      {
        BASE_DCPR.NextType =
          BASE_DCPR_LZ77.LenBuf[
            BASE_DCPR_LZ77.LenDistBufPos] & 255;

        switch (BASE_DCPR.NextType)
        {
          case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA:
          {
            BASE_DCPR_LZ77.NextDeltaDist =
              BASE_DCPR_LZ77.DistBuf[BASE_DCPR_LZ77.LenDistBufPos] >> 17;

            BASE_DCPR_LZ77.NextDeltaLen  =
              BASE_DCPR_LZ77.DistBuf[BASE_DCPR_LZ77.LenDistBufPos] & 0x1FFFF;

            break;
          }

          case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
          {
            BASE_DCPR_LZ77.NextExeMode =
              BASE_DCPR_LZ77.DistBuf[BASE_DCPR_LZ77.LenDistBufPos];

            break;
          }
        }

        BASE_DCPR_LZ77.LenDistBufPos++;

        break;
      }

      if (Symbol > 259)
      {
        Symbol   -= 260;
        MatchDist = BASE_DCPR_LZ77.DistBuf[BASE_DCPR_LZ77.LenDistBufPos];

        BASE_DCPR_LZ77.OldDistsPos = (BASE_DCPR_LZ77.OldDistsPos + 1) & 3;

        BASE_DCPR_LZ77.OldDists[BASE_DCPR_LZ77.OldDistsPos] =
          MatchDist;

        I = 2;

        if (MatchDist > BASE_CPRDCPR_LZ77_MAXDISTATLEN2)
        {
          I++;

          if (MatchDist > BASE_CPRDCPR_LZ77_MAXDISTATLEN3)
          {
            I++;
          }
        }
      }
      else
      {
        MatchDist = BASE_DCPR_LZ77.OldDists[
                      (BASE_DCPR_LZ77.OldDistsPos - (Symbol &= 255)) & 3];

        for (I = Symbol; I >= 0; I--)
        {
          BASE_DCPR_LZ77.OldDists[(BASE_DCPR_LZ77.OldDistsPos - I) & 3] =
            BASE_DCPR_LZ77.OldDists[(BASE_DCPR_LZ77.OldDistsPos - I + 1) & 3];
        }

        BASE_DCPR_LZ77.OldDists[BASE_DCPR_LZ77.OldDistsPos] = MatchDist;

        I = Symbol > 1 ? 3 : 2;
      }

      LenSymbol = BASE_DCPR_LZ77.LenBuf[BASE_DCPR_LZ77.LenDistBufPos++] + I;

      MatchDist++;
      BASE_DCPR_LZ77_CopyString(MatchDist, LenSymbol);
    }
    else
    {
      BASE_DCPR_LZ77_WriteChar(Symbol);
    }
  }
}

/*-----------------BASE_DCPR_LZ77_ReadSymbolsCore------------------------*/

void    BASE_DCPR_LZ77_ReadSymbolsCore(void)
{
INT       SymbolCount,
          MatchCount,
          Symbol,
          Type;

  MatchCount = 0;

  for (SymbolCount = 0; SymbolCount < BASE_DCPR_LZ77.PartSize; SymbolCount++)
  {
    Symbol = BASE_DCPR_LZ77.MainHuffSymbols[BASE_DCPR.ReadCode
               >> (32 - BASE_CPRDCPR_LZ77_MAXCODEWIDTH)];

    BASE_DCPR_AddBits(BASE_DCPR_LZ77.MainHuffWidths[Symbol]);

    BASE_DCPR_LZ77.MainBuf[SymbolCount] = Symbol;

    if (Symbol > 255)
    {
      if (Symbol == BASE_CPRDCPR_LZ77_TYPECODE)
      {
        Type = BASE_DCPR.ReadCode >> 24;
        BASE_DCPR_LZ77.LenBuf[MatchCount] = Type;
        BASE_DCPR_AddBits(8);

        switch (Type)
        {
          case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA:
          {
            BASE_DCPR_LZ77.DistBuf[MatchCount] =
              BASE_DCPR.ReadCode >> (32 - 25);

            BASE_DCPR_AddBits(25);

            break;
          }

          case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
          {
            BASE_DCPR_LZ77.DistBuf[MatchCount] =
              BASE_DCPR.ReadCode >> (32 - 8);

            BASE_DCPR_AddBits(8);

            break;
          }
        }

        MatchCount++;
      }
      else
      {
        if (Symbol > 259)
        {
          if ((Symbol -= 260) > 1)
          {
            BASE_DCPR_LZ77.DistBuf[MatchCount] =
              (BASE_DCPR.ReadCode >> (33 - Symbol)) + (1 << (Symbol - 1));

            BASE_DCPR_AddBits(Symbol - 1);
          }
          else
          {
            BASE_DCPR_LZ77.DistBuf[MatchCount] = Symbol;
          }
        }

        BASE_DCPR_LZ77.LenBuf[MatchCount] =
          BASE_DCPR_LZ77.LenHuffSymbols[BASE_DCPR.ReadCode
                           >> (32 - BASE_CPRDCPR_LZ77_MAXCODEWIDTH)];

        BASE_DCPR_AddBits(BASE_DCPR_LZ77.LenHuffWidths[
                            BASE_DCPR_LZ77.LenBuf[MatchCount]]);

        MatchCount++;
      }
    }
  }
}
