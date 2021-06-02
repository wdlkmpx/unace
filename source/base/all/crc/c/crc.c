
/*-----------------BASE_CRC_GetCRC---------------------------------------*/

ULONG   BASE_CRC_GetCRC(ULONG CRC, PCHAR Addr, int Len)
{
  while (Len--)
  {
    CRC = BASE_CRC.CRCTable[(UCHAR) (CRC ^ (*Addr++))] ^ (CRC >> 8);
  }

  return CRC;
}
