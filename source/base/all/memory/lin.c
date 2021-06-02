#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#define INCL_BASE_MEMORY

#include "base/all/includes.h"

/*-----------------BASE_MEMORY_InitMaxAllocate---------------------------*/

void    BASE_MEMORY_InitMaxAllocate(void)
{
#define   STEP 128*1024
int 	  Size,
	  StartMajorFaults;
char 	 *Buf,
	 *NewBuf;
struct 	  rusage ru;

  StartMajorFaults =
    Size 	   = 0;

  Buf = NULL;

  while (Size < BASE_MEMORY_EXTERN_MaxMemoryRequirement()
         && (NewBuf = (char*) realloc(Buf, Size + STEP)))
  {
    Buf = NewBuf;
    memset(&Buf[Size], 0, STEP);
    
    getrusage(RUSAGE_SELF, &ru);

    if (!StartMajorFaults)
    {
      StartMajorFaults = ru.ru_majflt;
    }
    
    if (ru.ru_nswap || ru.ru_majflt != StartMajorFaults)
    {
      free(Buf);
      Buf = NULL;
      
      break;
    }
    
    Size += STEP;
  }

  free(Buf);
  BASE_MEMORY.MaxAllocate  = Size;

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
