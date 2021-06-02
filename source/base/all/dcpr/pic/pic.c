#include <stdlib.h>
#include <string.h>

#define INCL_BASE_DCPR_PIC_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_BITWIDTH
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_MEMORY

#include "base/all/includes.h"


#ifndef USE_ASM
  #include "base/all/dcpr/pic/c/pic.c"
#endif

/*-----------------BASE_DCPR_PIC_GolombRice------------------------------*/

INT     BASE_DCPR_PIC_GolombRice(INT K)
{
INT       I,
          Err;

  Err = K ? BASE_DCPR.ReadCode >> (32 - K) : 0;
  BASE_DCPR_AddBits(K);

  do
  {
    I = BASE_DCPR.ReadCode >> 31;
    
    if (I)
    {
      Err += 1 << K;
    }

    BASE_DCPR_AddBits(1);

  }
  while (I);

  return Err;
}

/*-----------------BASE_DCPR_PIC_InitModel-------------------------------*/

void    BASE_DCPR_PIC_InitModel(void)
{
INT       Predictor,
          I;

  for (Predictor = 0; Predictor <= 1; Predictor++)
  {
    memset(&BASE_DCPR_PIC.Context[Predictor], 0,
           sizeof(BASE_DCPR_PIC.Context[0]));

    for (I = 0; I < BASE_CPRDCPR_PIC_CONTEXTNUMBER; I++)
    {
      BASE_DCPR_PIC.Context[Predictor][I].AverageCounter = 4;
    }
  }
}

/*-----------------BASE_DCPR_PIC_InitQuantizers--------------------------*/

void    BASE_DCPR_PIC_InitQuantizers(void)
{
INT       I;

  for (I = -255; I <= 255; I++)
  {
    if (I <= -BASE_CPRDCPR_PIC_S3)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = -4;
    else if (I <= -BASE_CPRDCPR_PIC_S2)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = -3;
    else if (I <= -BASE_CPRDCPR_PIC_S1)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = -2;
    else if (I <= -1)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = -1;
    else if (!I)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = 0;
    else if (I < BASE_CPRDCPR_PIC_S1)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = 1;
    else if (I < BASE_CPRDCPR_PIC_S2)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = 2;
    else if (I < BASE_CPRDCPR_PIC_S3)
      BASE_CPRDCPR_PIC_QuantizerArr(I) = 3;
    else
      BASE_CPRDCPR_PIC_QuantizerArr(I) = 4;
  }

  for (I = -255; I <= 255; I++)
  {
    BASE_CPRDCPR_PIC_QuantizerArrx9(I) = 9 * BASE_CPRDCPR_PIC_QuantizerArr(I);
  }

  for (I = -255; I <= 255; I++)
  {
    BASE_CPRDCPR_PIC_QuantizerArrx9x9(I) = 9 * BASE_CPRDCPR_PIC_QuantizerArrx9(I);
  }
}

/*-----------------BASE_DCPR_PIC_Init------------------------------------*/

void    BASE_DCPR_PIC_Init(void)
{
INT       I,
          J;

  BASE_DCPR_PIC_Done();

  BASE_DCPR_PIC.Width  = BASE_DCPR_PIC_GolombRice(12);
  BASE_DCPR_PIC.Planes = BASE_DCPR_PIC_GolombRice(2);

  I = BASE_DCPR_PIC.Width + 2 * BASE_DCPR_PIC.Planes;

  for (J = 0; J <= 1; J++)
  {
    BASE_DCPR_PIC.Data[J] = (PCHAR) BASE_MEMORY_GetMemCheck(1, I);
    memset(BASE_DCPR_PIC.Data[J], 0, I);
    BASE_DCPR_PIC.Data[J] += BASE_DCPR_PIC.Planes;
  }

  BASE_DCPR_PIC_InitModel();
  BASE_DCPR_PIC_InitQuantizers();

  BASE_DCPR_PIC.DataPos = 0;
}

/*-----------------BASE_DCPR_PIC_Done------------------------------------*/

void    BASE_DCPR_PIC_Done(void)
{
  if (BASE_DCPR_PIC.Data[0])
  {
    BASE_DCPR_PIC.Data[0] -= BASE_DCPR_PIC.Planes;
    BASE_DCPR_PIC.Data[1] -= BASE_DCPR_PIC.Planes;

    BASE_MEMORY_FreeCheck((PVOID *) &BASE_DCPR_PIC.Data[0]);
    BASE_MEMORY_FreeCheck((PVOID *) &BASE_DCPR_PIC.Data[1]);
  }
}
