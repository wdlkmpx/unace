#define INCL_BASE_CRC_EXCLUSIVE

#include "base/all/includes.h"


#ifdef USE_ASM
  #include "base/all/crc/asm/crc.c"
#else
  #include "base/all/crc/c/crc.c"
#endif


/*-----------------BASE_CRC_MakeCRCTable---------------------------------*/

void    BASE_CRC_MakeCRCTable(void)
{
UINT      I,
          J;
ULONG     HashValue;

  for (I = 0; I <= 255; I++)
  {
    for (HashValue = I, J = 8; J; J--)
    {
      HashValue = (HashValue & 1) ?
                    (HashValue >> 1) ^ BASE_CRC_POLYNOMIAL : (HashValue >> 1);
    }

    BASE_CRC.CRCTable[I] = HashValue;
  }
}

/*-----------------BASE_CRC_GetCRC16-------------------------------------*/

USHORT  BASE_CRC_GetCRC16(ULONG CRC, PCHAR Addr, int Len)
{
  return (USHORT) BASE_CRC_GetCRC(CRC, Addr, Len);
}
