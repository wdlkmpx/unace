#ifndef _BASE_VOLUME_H_INCLUDED
#define _BASE_VOLUME_H_INCLUDED

#ifdef INCL_BASE_VOLUME_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


typedef struct
{
  BOOL    DoNotProcessNextVolume,
          DoProcessAllVolumes;
  UINT    CurrentVolumeNumber;
} tBASE_VOLUME;

DECLEXT tBASE_VOLUME
        BASE_VOLUME;

PCHAR   BASE_VOLUME_GetVolumeName(PCHAR NewVolumeName, PCHAR VolumeName,
                                  INT Type, INT AddToVolumeNumber,
                                  BOOL IsSFX);

INT     BASE_VOLUME_NextVolumeToProcess(BOOL IsZeroLengthFile);
void    BASE_VOLUME_PreviousVolumeToProcess(void);
INT     BASE_VOLUME_FirstVolumeToProcess(PCHAR VolumeName);
INT     BASE_VOLUME_EXTERN_ChangeVolumeToProcess(PCHAR VolumeName);


#undef DECLEXT

#endif
