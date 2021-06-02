#include <stdlib.h>
#include <string.h>

#define INCL_BASE_DCPR_SOUND_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_HUFF
#define INCL_BASE_DCPR_LZ77

#include "base/all/includes.h"


#ifndef USE_ASM
  #include "base/all/dcpr/sound/c/sound.c"
#endif
