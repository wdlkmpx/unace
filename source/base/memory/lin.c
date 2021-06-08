#include <stdlib.h>
#include <string.h>

#define INCL_BASE_MEMORY

#include "base/includes.h"

/*-----------------BASE_MEMORY_InitMaxAllocate---------------------------*/

void    BASE_MEMORY_InitMaxAllocate(void)
{
  BASE_MEMORY.MaxAllocate  = BASE_MEMORY_EXTERN_MaxMemoryRequirement();

  BASE_MEMORY_InitAlloc();
}

/*-----------------BASE_MEMORY_MemMax------------------------------------*/

INT     BASE_MEMORY_MemMax(void)
{
  return BASE_MEMORY.MaxAllocate;
}

/*-----------------BASE_MEMORY_MemAvail----------------------------------*/

INT     BASE_MEMORY_MemAvail(void)
{
  return BASE_MEMORY_MemMax();
}
