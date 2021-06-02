#define INCL_BASE_ARCHIVES_ACE
#define INCL_BASE_ARCBLK
#define INCL_BASE_CRC
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROROUT

#include "base/unace/includes.h"

/*-----------------BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck-----------*/

BOOL    BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck(BOOL IsUnRegistered)
{
  if (!IsUnRegistered && BASE_DIRDATA_Dir1.HasAV
      && ((BASE_ARCBLK.Header.Main.RES2
            ^ (USHORT) (BASE_ARCBLK.Header.Main.TIME_CR >> 12))
          != BASE_ARCBLK.Header.Main.RES1))
  {
    BASE_ERROROUT_EXTERN_AVBroken();
  }

  return 1;
}
