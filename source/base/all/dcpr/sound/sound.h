#ifndef _BASE_DCPR_SOUND_H_INCLUDED
#define _BASE_DCPR_SOUND_H_INCLUDED


#include "base/all/cprdcpr/sound/sound.h"

#ifdef INCL_BASE_DCPR_SOUND_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


//------ConstantDefines:

#define BASE_DCPR_SOUND_WIDTHBUFSIZE     BASE_CPRDCPR_SOUND_MAXCODE + 2

//------VariableDefines:

typedef struct
{
        USHORT  HuffSymbols[BASE_CPRDCPR_SOUND_MAXMODELS]
                  [(1 << BASE_CPRDCPR_SOUND_MAXCODEWIDTH) + 1],
                HuffWidths[BASE_CPRDCPR_SOUND_MAXMODELS]
                  [BASE_CPRDCPR_SOUND_MAXCODE + 2];

        tBASE_CPRDCPR_SOUND_DATA
                SoundVar;
} tBASE_DCPR_SOUND;

DECLEXT tBASE_DCPR_SOUND
        BASE_DCPR_SOUND;

#ifdef USE_ASM
extern void BASE_DCPR_SOUND_Init(INT Type);
extern INT  BASE_DCPR_SOUND_Block(PCHAR Buf, INT Len);
#else
void    BASE_DCPR_SOUND_Init(INT Type);
INT     BASE_DCPR_SOUND_Block(PCHAR Buf, INT Len);
UCHAR   BASE_DCPR_SOUND_GetPredictedChar(INT Channel);
INT     BASE_DCPR_SOUND_CalcDcprTabs(void);
INT     BASE_DCPR_SOUND_GetSymbol(INT Model, INT Channel);
INT     BASE_DCPR_SOUND_Get(INT Channel);
INT     BASE_DCPR_SOUND_RarPredict(INT Channel);
void    BASE_DCPR_SOUND_RarAdjust(INT Channel, INT Ch);
#endif

#undef DECLEXT

#endif
