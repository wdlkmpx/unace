/*-----------------BASE_DCPR_PIC_GetContext------------------------------*/

INT     BASE_DCPR_PIC_GetContext(void)
{
  return BASE_CPRDCPR_PIC_QuantizerArrx9x9(BASE_DCPR_PIC.PixelD
                                           - BASE_DCPR_PIC.PixelA)
       + BASE_CPRDCPR_PIC_QuantizerArrx9  (BASE_DCPR_PIC.PixelA
                                           - BASE_DCPR_PIC.PixelC)
       + BASE_CPRDCPR_PIC_QuantizerArr    (BASE_DCPR_PIC.PixelC
                                           - BASE_DCPR_PIC.PixelB);
}

/*-----------------BASE_DCPR_PIC_SetPixels1-------------------------------*/

void    BASE_DCPR_PIC_SetPixels1(void)
{
  BASE_DCPR_PIC.PixelD = BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurPlane];

  BASE_DCPR_PIC.PixelA   =
    BASE_DCPR_PIC.PixelB =
    BASE_DCPR_PIC.PixelC =
    BASE_DCPR_PIC.PixelX = 0;

  if (BASE_DCPR_PIC.CurPred == 1)
  {
    BASE_DCPR_PIC.PixelA   =
      BASE_DCPR_PIC.PixelB =
      BASE_DCPR_PIC.PixelC =
      BASE_DCPR_PIC.PixelX = 128;

    BASE_DCPR_PIC.PixelD -= BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurPlane - 1] - 128;
  }
  else
  {
    if (BASE_DCPR_PIC.CurPred == 2)
    {
      BASE_DCPR_PIC.PixelA   =
        BASE_DCPR_PIC.PixelB =
        BASE_DCPR_PIC.PixelC =
        BASE_DCPR_PIC.PixelX = 128;

      BASE_DCPR_PIC.PixelD -=
        (BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurPlane - 1] * 11 >> 4) - 128;
    }
  }
}

/*-----------------BASE_DCPR_PIC_SetPixels2-------------------------------*/

void    BASE_DCPR_PIC_SetPixels2(void)
{
  BASE_DCPR_PIC.PixelC = BASE_DCPR_PIC.PixelA;
  BASE_DCPR_PIC.PixelA = BASE_DCPR_PIC.PixelD;
  BASE_DCPR_PIC.PixelB = BASE_DCPR_PIC.PixelX;
}

/*-----------------BASE_DCPR_PIC_SetPixels3-------------------------------*/

void    BASE_DCPR_PIC_SetPixels3(void)
{
  BASE_DCPR_PIC.PixelA =
    BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol];

  BASE_DCPR_PIC.PixelB =
    BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol - BASE_DCPR_PIC.Planes];

  BASE_DCPR_PIC.PixelC =
    BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol - BASE_DCPR_PIC.Planes];

  if (BASE_DCPR_PIC.CurPred == 1)
  {
    BASE_DCPR_PIC.PixelA -=
      BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol - 1] - 128;

    BASE_DCPR_PIC.PixelB -=
      BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol - BASE_DCPR_PIC.Planes - 1]
      - 128;

    BASE_DCPR_PIC.PixelC -=
      BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol - BASE_DCPR_PIC.Planes - 1]
      - 128;
  }
  else
  {
    if (BASE_DCPR_PIC.CurPred == 2)
    {
      BASE_DCPR_PIC.PixelA -=
        (BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol - 1] * 11 >> 4) - 128;

      BASE_DCPR_PIC.PixelB -=
        (BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol
         - BASE_DCPR_PIC.Planes - 1] * 11 >> 4) - 128;

      BASE_DCPR_PIC.PixelC -=
        (BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol
         - BASE_DCPR_PIC.Planes - 1] * 11 >> 4) - 128;
    }
  }
}

/*-----------------BASE_DCPR_PIC_SetPixelState----------------------------*/

void    BASE_DCPR_PIC_SetPixelState(void)
{
  BASE_DCPR_PIC.PixelD =
    BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol
    + BASE_DCPR_PIC.Planes];

  if (BASE_DCPR_PIC.CurPred == 1)
  {
    BASE_DCPR_PIC.PixelD -=
        BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol
        + BASE_DCPR_PIC.Planes - 1] - 128;
  }
  else
  {
    if (BASE_DCPR_PIC.CurPred == 2)
    {
      BASE_DCPR_PIC.PixelD -=
        (BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.CurCol
         + BASE_DCPR_PIC.Planes - 1] * 11 >> 4) - 128;
    }
  }

  BASE_DCPR_PIC.CurState = abs(BASE_DCPR_PIC_GetContext());
}

/*-----------------BASE_DCPR_PIC_Pixel-----------------------------------*/

void    BASE_DCPR_PIC_Pixel(void)
{
INT       K,
          BestPredictor,
          BestErrorCount;
CHAR      MEpsilon,
          Predicted;
SCHAR     Epsilon;

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].UsedCounter++;

  K = BASE_BITWIDTH.BitWidthArray[
        BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].AverageCounter
          / BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].UsedCounter];

  MEpsilon = BASE_DCPR_PIC_GolombRice(K);

  if (MEpsilon & 1)
  {
    Epsilon = - MEpsilon / 2 - 1;
  }
  else
  {
    Epsilon = MEpsilon / 2;
  }

  switch (BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].PredictorNumber)
  {
    case 0:
    {
      Predicted = BASE_DCPR_PIC.PixelA;

      break;
    }
    case 1:
    {
      Predicted = BASE_DCPR_PIC.PixelB;

      break;
    }
    case 2:
    {
      Predicted = (BASE_DCPR_PIC.PixelA + BASE_DCPR_PIC.PixelB) >> 1;

      break;
    }
    case 3:
    {
      Predicted =
        BASE_DCPR_PIC.PixelA + BASE_DCPR_PIC.PixelB - BASE_DCPR_PIC.PixelC;

      break;
    }
  }

  BASE_DCPR_PIC.PixelX = Epsilon + Predicted;

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[0] +=
    BASE_BITWIDTH.DifBitWidthArray[
      (UCHAR)(BASE_DCPR_PIC.PixelX - BASE_DCPR_PIC.PixelA)];

  BestPredictor  = 0;

  BestErrorCount =
    BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[0];

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[1] +=
    BASE_BITWIDTH.DifBitWidthArray[
      (UCHAR) (BASE_DCPR_PIC.PixelX - BASE_DCPR_PIC.PixelB)];

  if (BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[1]
      < BestErrorCount)
  {
    BestPredictor  = 1;

    BestErrorCount =
      BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[1];
  }

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[2] +=
    BASE_BITWIDTH.DifBitWidthArray[
      (UCHAR) (BASE_DCPR_PIC.PixelX
               - ((BASE_DCPR_PIC.PixelA + BASE_DCPR_PIC.PixelB) >> 1))];

  if (BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[2]
      < BestErrorCount)
  {
    BestPredictor  = 2;

    BestErrorCount =
      BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[2];
  }

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[3] +=
    BASE_BITWIDTH.DifBitWidthArray[
      (UCHAR) (BASE_DCPR_PIC.PixelX -
                 (BASE_DCPR_PIC.PixelA + BASE_DCPR_PIC.PixelB
                 - BASE_DCPR_PIC.PixelC))];

  if (BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].ErrorCounters[3]
      < BestErrorCount)
  {
    BestPredictor = 3;
  }

  if (*(PULONG) &BASE_DCPR_PIC.CurContext[
        BASE_DCPR_PIC.CurState].ErrorCounters & 0x80808080)
  {
    *(PULONG) &BASE_DCPR_PIC.CurContext[
        BASE_DCPR_PIC.CurState].ErrorCounters =
            (*(PULONG) &BASE_DCPR_PIC.CurContext[
              BASE_DCPR_PIC.CurState].ErrorCounters>> 1) & 0x7f7f7f7f;
  }

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].PredictorNumber =
    BestPredictor;

  BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].AverageCounter +=
    abs(Epsilon);

  if (BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].UsedCounter
      == BASE_CPRDCPR_PIC_N0)
  {
    BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].UsedCounter =
      BASE_CPRDCPR_PIC_N0 >> 1;

    BASE_DCPR_PIC.CurContext[BASE_DCPR_PIC.CurState].AverageCounter >>= 1;
  }

  switch (BASE_DCPR_PIC.CurPred)
  {
    case 0:
    {
      BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol] = BASE_DCPR_PIC.PixelX;

      break;
    }

    case 1:
    {
      BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol] =
        BASE_DCPR_PIC.PixelX
        + BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol - 1] - 128;

      break;
    }

    case 2:
    {
      BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol] =
        BASE_DCPR_PIC.PixelX
        + (BASE_DCPR_PIC.Data[0][BASE_DCPR_PIC.CurCol - 1] * 11 >> 4) - 128;

      break;
    }
  }
}

/*-----------------BASE_DCPR_PIC_Symbol-----------------------------------*/

void    BASE_DCPR_PIC_Symbol(void)
{
  BASE_DCPR_PIC_SetPixels2();
  BASE_DCPR_PIC_SetPixelState();
  BASE_DCPR_PIC_Pixel();
}

/*-----------------BASE_DCPR_PIC_Line------------------------------------*/

void    BASE_DCPR_PIC_Line(void)
{
PCHAR     Temp;

  for (BASE_DCPR_PIC.CurPlane = 0;
       BASE_DCPR_PIC.CurPlane < BASE_DCPR_PIC.Planes;
       BASE_DCPR_PIC.CurPlane++)
  {
    if (BASE_DCPR_PIC.CurPlane)
    {
      BASE_DCPR_PIC.CurContext = BASE_DCPR_PIC.Context[1];
      BASE_DCPR_PIC.CurPred    = BASE_DCPR.ReadCode >> (32 - 2);
      BASE_DCPR_AddBits(2);
    }
    else
    {
      BASE_DCPR_PIC.CurContext = BASE_DCPR_PIC.Context[0];
      BASE_DCPR_PIC.CurPred    = 0;
    }

    BASE_DCPR_PIC_SetPixels1();

    for (BASE_DCPR_PIC.CurCol = BASE_DCPR_PIC.CurPlane;
         BASE_DCPR_PIC.CurCol < BASE_DCPR_PIC.Width;
         BASE_DCPR_PIC.CurCol += BASE_DCPR_PIC.Planes)
    {
      BASE_DCPR_PIC_Symbol();
    }
  }

  BASE_DCPR_PIC.DataPos = BASE_DCPR_PIC.Width;

  Temp                  = BASE_DCPR_PIC.Data[0];
  BASE_DCPR_PIC.Data[0] = BASE_DCPR_PIC.Data[1];
  BASE_DCPR_PIC.Data[1] = Temp;
}

/*-----------------BASE_DCPR_PIC_Block------------------------------------*/

INT     BASE_DCPR_PIC_Block(PCHAR Buf, INT Len)
{
INT       I,
          RestLen;

  RestLen = Len;

  while (RestLen)
  {
    if (!BASE_DCPR_PIC.DataPos)
    {
      if (BASE_DCPR.FileSize)
      {
        I = BASE_DCPR.ReadCode >> (32 - 1);
        BASE_DCPR_AddBits(1);

        if (!I)
        {
          BASE_DCPR.NextType = BASE_DCPR.ReadCode >> (32 - 8);
          BASE_DCPR_AddBits(8);

          switch (BASE_DCPR.NextType)
          {
            case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA:
            {
              BASE_DCPR_LZ77.NextDeltaDist = BASE_DCPR.ReadCode >> (32 - 8);
              BASE_DCPR_AddBits(8);
              BASE_DCPR_LZ77.NextDeltaLen  = BASE_DCPR.ReadCode >> (32 - 17);
              BASE_DCPR_AddBits(17);

              break;
            }

            case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
            {
              BASE_DCPR_LZ77.NextExeMode = BASE_DCPR.ReadCode >> (32 -8);
              BASE_DCPR_AddBits(8);

              break;
            }
          }

          break;
        }
      }
      else
      {
        break;
      }

      BASE_DCPR_PIC_Line();
    }

    I = RestLen > BASE_DCPR_PIC.DataPos ? BASE_DCPR_PIC.DataPos : RestLen;

    memcpy(Buf, &(BASE_DCPR_PIC.Data[1][BASE_DCPR_PIC.Width
                  - BASE_DCPR_PIC.DataPos]), I);

    Buf              += I;
    RestLen          -= I;
    BASE_DCPR_PIC.DataPos -= I;
    BASE_DCPR.FileSize    -= I;
  }

  return Len - RestLen;
}
