#include <stdlib.h>

#define INCL_BASE_BITWIDTH
#define INCL_BASE_MEMORY

#include "base/all/includes.h"

/*-----------------BASE_MEMORY_ReAlloc-----------------------------------*/

PVOID  BASE_MEMORY_ReAlloc(PVOID OldPointer, INT NewSize)
{
PVOID     NewPointer;
INT       OldSize;

  OldSize = BASE_MEMORY_Size(OldPointer);

  if ((NewPointer = realloc((PVOID) ((PULONG) OldPointer - 1), NewSize + 4)))
  {
    BASE_MEMORY.MaxAllocate += OldSize - NewSize;
    *(PULONG) NewPointer = NewSize;
    NewPointer = (PVOID) ((PULONG) NewPointer + 1);

    return NewPointer;
  }
  else
  {
    return OldPointer;
  }
}

/*-----------------BASE_MEMORY_MemAvailBase2-----------------------------*/

INT     BASE_MEMORY_MemAvailBase2(INT Base)
{
PVOID     Pointer;
INT       I;

  I = BASE_MEMORY.MaxAllocate >> (Base + 11);

  I = 1 << ((I < 256 ? BASE_BITWIDTH_GetBitWidth(I)
                     : BASE_BITWIDTH_GetBitWidth(I >> 8) + 8) + 10);

  while (!(Pointer = malloc(I)))
  {
    I -= I >> 2;
  }

  free(Pointer);

  return I;
}

/*-----------------BASE_MEMORY_MemAvailBase2Plus-------------------------*/

INT     BASE_MEMORY_MemAvailBase2Plus(INT Base, INT Plus)
{
PVOID     Pointer;
INT       I;

  I = BASE_MEMORY.MaxAllocate >> (Base + 11);

  I = 1 << ((I < 256 ? BASE_BITWIDTH_GetBitWidth(I)
                     : BASE_BITWIDTH_GetBitWidth(I >> 8) + 8) + 10);

  while (!(Pointer = malloc(I + Plus)))
  {
    I >>= 1;
  }

  free(Pointer);

  return I;
}
