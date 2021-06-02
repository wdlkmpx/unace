#define INCL_BASE_MEMORY

#include "base/all/includes.h"


/*-----------------BASE_MEMORY_MemCopy-----------------------------------*/

void    BASE_MEMORY_MemCopy(PCHAR Dest, PCHAR Source, INT Len)
{
  while (Len--)
  {
    *Dest++ = *Source++;
  }
}


/*-----------------BASE_MEMORY_MemSet16----------------------------------*/

void    BASE_MEMORY_MemSet16(PUSHORT Buf, USHORT Code, INT Len)
{
  while (Len--)
  {
    *Buf++ = Code;
  }
}


/*-----------------BASE_MEMORY_MemSet32----------------------------------*/

void    BASE_MEMORY_MemSet32(PULONG Buf, ULONG Code, INT Len)
{
  while (Len--)
  {
    *Buf++ = Code;
  }
}
