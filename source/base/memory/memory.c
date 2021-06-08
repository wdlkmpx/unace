#include <stdlib.h>
#include <string.h>

#ifndef __MACOSX__
	#include <malloc.h>
#endif

#define INCL_BASE_MEMORY_EXCLUSIVE

#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_DCPR_PIC
#define INCL_BASE_ERROROUT
#define INCL_BASE_FILELIST

#include "base/includes.h"

/*-----------------BASE_MEMORY_EXTERN_OptimizeOtherMemory----------------*/
void    BASE_MEMORY_EXTERN_OptimizeOtherMemory(void)
{
}
/*-----------------BASE_MEMORY_EXTERN_MaxMemoryRequirement---------------*/
ULONG   BASE_MEMORY_EXTERN_MaxMemoryRequirement(void)
{
  return 16*1024*1024;
}


/*-----------------BASE_MEMORY_GetMemCheck-------------------------------*/

PVOID   BASE_MEMORY_GetMemCheck(BOOL DoCheck, INT Size)
{
PVOID     Pointer;
BOOL      MemIsMaxed;
INT       MemBlockSize;

  MemIsMaxed = 1;

  while (Size > (MemBlockSize = BASE_MEMORY_MemMax()) && MemIsMaxed)
  {
    BASE_MEMORY_Optimize();
    MemIsMaxed = MemBlockSize + 8 * 1024 < BASE_MEMORY_MemMax();
  }

  if (Size + 4 > BASE_MEMORY.MaxAllocate)
  {
    if (DoCheck)
    {
      BASE_ERROROUT_EXTERN_Mem();
    }

    return NULL;
  }

  if (!(Pointer = malloc(Size + 4)))
  {
    if (DoCheck)
    {
      BASE_ERROROUT_EXTERN_Mem();
    }
  }
  else
  {
    BASE_MEMORY.MaxAllocate -= Size + 4;

    *(PULONG) Pointer = Size;
    Pointer = (PVOID) ((PULONG) Pointer + 1);
  }

  return Pointer;
}

/*-----------------BASE_MEMORY_GetMem------------------------------------*/

PVOID   BASE_MEMORY_GetMem(INT Size)
{
  return BASE_MEMORY_GetMemCheck(1, Size);
}

/*-----------------BASE_MEMORY_Size--------------------------------------*/

INT     BASE_MEMORY_Size(PVOID Pointer)
{
  return *((PULONG) Pointer - 1);
}

/*-----------------BASE_MEMORY_GetMemBase2-------------------------------*/

PVOID   BASE_MEMORY_GetMemBase2(PINT Size, INT Base)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2(Base);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize);
}

/*-----------------BASE_MEMORY_GetMemBase2Max----------------------------*/

PVOID  BASE_MEMORY_GetMemBase2Max(PINT Size, INT Base, INT Maximum)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2(Base);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (MemSize > Maximum)
  {
    MemSize = Maximum;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize);
}

/*-----------------BASE_MEMORY_GetMemBase2PlusMax------------------------*/

PVOID  BASE_MEMORY_GetMemBase2PlusMax(PINT Size, INT Base, INT Maximum,
                                        INT Plus)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2Plus(Base, Plus);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (MemSize > Maximum)
  {
    MemSize = Maximum;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize + Plus);
}

/*-----------------BASE_MEMORY_FreeCheck---------------------------------*/

void    BASE_MEMORY_FreeCheck_(PVOID Pointer)
{
  if (Pointer)
  {
    BASE_MEMORY.MaxAllocate += BASE_MEMORY_Size(Pointer);
    free((PVOID) (((PULONG) Pointer) - 1));
  }
}

/*-----------------BASE_MEMORY_ReAllocSameSize---------------------------*/

PVOID   BASE_MEMORY_ReAllocSameSize(PVOID OldPointer)
{
PVOID     NewPointer;
INT       OldSize,
          MemMaxSize;

  if (!OldPointer)
  {
    return NULL;
  }

  MemMaxSize = BASE_MEMORY_MemMax();
  OldSize    = BASE_MEMORY_Size(OldPointer);

  if (MemMaxSize < OldSize
      || !(NewPointer = BASE_MEMORY_GetMemCheck(0, OldSize)))
  {
    return OldPointer;
  }

  memcpy(NewPointer, OldPointer, OldSize);
  BASE_MEMORY_FreeCheck(OldPointer);

  if (BASE_MEMORY_MemMax() < MemMaxSize)
  {
    if (!(OldPointer = BASE_MEMORY_GetMemCheck(0, OldSize)))
    {
      return NewPointer;
    }

    memcpy(OldPointer, NewPointer, OldSize);
    BASE_MEMORY_FreeCheck(NewPointer);

    return OldPointer;
  }
  else
  {
    return NewPointer;
  }
}

/*-----------------BASE_MEMORY_InitAlloc---------------------------------*/

void    BASE_MEMORY_InitAlloc(void)
{
PVOID     Pointer;
INT       Size;

  Pointer = NULL;
  Size    = BASE_MEMORY.MaxAllocate;

  while (!Pointer && Size > 32768)
  {
    Pointer = malloc(Size);

    if (!Pointer)
    {
      Size -= Size / 4;
    }
  }

  if (Pointer)
  {
    free(Pointer);
    BASE_MEMORY.MaxAllocate = Size;
  }
}

/*-----------------BASE_MEMORY_Optimize----------------------------------*/

void    BASE_MEMORY_Optimize(void)
{
INT       I, J;

  BASE_MEMORY_EXTERN_OptimizeOtherMemory();

  I             = BASE_FILELIST.Last - BASE_FILELIST.List;
  J             = BASE_FILELIST.Pos  - BASE_FILELIST.List;
  BASE_FILELIST.List = (PCHAR)BASE_MEMORY_ReAllocSameSize(BASE_FILELIST.List);
  BASE_FILELIST.Last = BASE_FILELIST.List + I;
  BASE_FILELIST.Pos  = BASE_FILELIST.List + J;

  BASE_DCPR.ReadBuf               =
    (PULONG) BASE_MEMORY_ReAllocSameSize(BASE_DCPR.ReadBuf);

  BASE_DCPR_LZ77.Dictionary       =
    (PCHAR) BASE_MEMORY_ReAllocSameSize(BASE_DCPR_LZ77.Dictionary);

  for (I = 0; I < 2; I++)
  {
    BASE_DCPR_PIC.Data[I]         =
      (PCHAR) BASE_MEMORY_ReAllocSameSize(BASE_DCPR_PIC.Data[I]);
  }
}
