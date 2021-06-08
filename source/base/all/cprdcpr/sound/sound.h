#ifndef _BASE_CPRDCPR_SOUND_H_INCLUDED
#define _BASE_CPRDCPR_SOUND_H_INCLUDED

#define BASE_CPRDCPR_SOUND_RUNLENCODES       32
#define BASE_CPRDCPR_SOUND_MAXCODE           (256 + BASE_CPRDCPR_SOUND_RUNLENCODES + 1)
#define BASE_CPRDCPR_SOUND_MAXCODEWIDTH      10
#define BASE_CPRDCPR_SOUND_TYPECODE          (256 + BASE_CPRDCPR_SOUND_RUNLENCODES)
#define BASE_CPRDCPR_SOUND_MAXCHANNELS       3
#define BASE_CPRDCPR_SOUND_MAXMODELS         (BASE_CPRDCPR_SOUND_MAXCHANNELS * 3)
#define BASE_CPRDCPR_SOUND_CHANNELBLOCKSIZE  2000
#define BASE_CPRDCPR_SOUND_HISTORYSIZE       256

#define BASE_CPRDCPR_SOUND_MAXBLOCKSIZE      (BASE_CPRDCPR_SOUND_CHANNELBLOCKSIZE * BASE_CPRDCPR_SOUND_MAXMODELS + 8)

#define SETNOALIGNMENT
#include "base/all/packprag.h"

typedef struct
{
  INT     PredictorDifCnt    [BASE_CPRDCPR_SOUND_MAXCHANNELS][2],
          LastPredictorDifCnt[BASE_CPRDCPR_SOUND_MAXCHANNELS][2],
          RarDifCnt          [BASE_CPRDCPR_SOUND_MAXCHANNELS][4],
          RarCoefficient     [BASE_CPRDCPR_SOUND_MAXCHANNELS][4],
          RarDif             [BASE_CPRDCPR_SOUND_MAXCHANNELS][9],
          ByteCount          [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          LastByte           [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          LastDelta          [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          State              [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          Code               [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          AdaptiveModelCnt   [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          AdaptiveModelUse   [BASE_CPRDCPR_SOUND_MAXCHANNELS],
          Models,
          Mode,
          BlockSize;
} tBASE_CPRDCPR_SOUND_DATA;

#define RESTOREALIGNMENT
#include "base/all/packprag.h"


typedef struct
{
  INT     QUANTIZER[256];
} tBASE_CPRDCPR_SOUND;

tBASE_CPRDCPR_SOUND BASE_CPRDCPR_SOUND;

INT const BASE_CPRDCPR_SOUND_CHANNELNUM[4][4] 
#ifdef INCL_BASE_CPRDCPR_SOUND_EXCLUSIVE
={{0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 0, 2},
  {1, 0, 2, 0}}
#endif
;

INT const BASE_CPRDCPR_SOUND_MODELS[4] 
#ifdef INCL_BASE_CPRDCPR_SOUND_EXCLUSIVE
={3, 6, 9, 9}
#endif
;

#endif
