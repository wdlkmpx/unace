#define INCL_BASE_QSORT_EXCLUSIVE

#include "base/all/includes.h"


#ifdef USE_ASM
  #include "base/all/qsort/asm/qsort.c"
#else
  #include "base/all/qsort/c/qsort.c"
#endif

/*-----------------BASE_QSORT_DoQuicksort--------------------------------*/

void    BASE_QSORT_DoQuicksort(INT NumberOfElements)
{
INT       I;

  for (I = NumberOfElements + 1; I--;)
  {
    BASE_QSORT.Elements[I] = I;
  }

  BASE_QSORT_SortRange(0, NumberOfElements);
}
