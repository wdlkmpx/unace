#ifndef _BASE_CPRDCPR_HUFF_H_INCLUDED
#define _BASE_CPRDCPR_HUFF_H_INCLUDED

#include "base/cprdcpr/sound.h"

#define BASE_CPRDCPR_HUFF_MAXWIDTHSVDWD      7
#define BASE_CPRDCPR_HUFF_MAXWIDTHTOSAVE     15
#define BASE_CPRDCPR_HUFF_MAXCODE            BASE_CPRDCPR_SOUND_MAXCODE

typedef struct
{
        USHORT SaveWidths[BASE_CPRDCPR_HUFF_MAXWIDTHTOSAVE];
} tBASE_CPRDCPR_HUFF;

extern tBASE_CPRDCPR_HUFF BASE_CPRDCPR_HUFF; //huff.c
#endif
