#ifndef _BASE_CRC_H_INCLUDED
#define _BASE_CRC_H_INCLUDED

#ifdef INCL_BASE_CRC_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


#define BASE_CRC_MASK                        0xFFFFFFFFL
#define BASE_CRC_POLYNOMIAL                  0xEDB88320L

typedef struct
{
  ULONG   CRCTable[256];
  INT     WriteCRC,
          ReadCRC;
} tBASE_CRC;

DECLEXT tBASE_CRC
        BASE_CRC;

void    BASE_CRC_MakeCRCTable(void);
USHORT  BASE_CRC_GetCRC16(ULONG CRC, PCHAR Addr, int Len);
ULONG   BASE_CRC_GetCRC(ULONG CRC, PCHAR Addr, INT Len);


#undef DECLEXT

#endif
