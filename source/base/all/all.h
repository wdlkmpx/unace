#ifndef _BASE_ALL_H_INCLUDED
#define _BASE_ALL_H_INCLUDED

#if defined(__MACOSX__) || defined(__sun__)
#include <sys/types.h>
#include <unistd.h>
#endif

#define SETALIGNMENT
#include "base/all/packprag.h"

#if defined(__NT__)
  #include <windows.h>
#else
  #if defined(__OS2__)
    #include <os2.h>
  #endif
#endif

#if defined(_GNU_H_WINDOWS32_BASE)
  #define _WINDOWS_
  #define __wtypes_h__
#endif

#include "declare.h"

#define RESTOREALIGNMENT
#include "base/all/packprag.h"

#include "base/all/lfn/lfn.h"

#ifdef INCL_BASE_ALL_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


#define in(v1,v2,v3) ((((INT) v1) >= ((INT) v2)) && (((INT) v1)<=((INT) v3)))

DECLEXT PCHAR const
        ARCHIVEEXTENSIONS[5] 
#ifdef INCL_BASE_ALL_EXCLUSIVE
 = {"ACE", "RAR", "ZIP", "ARJ", "EXE"}
#endif
;

#undef DECLEXT

#ifdef __EMULATE_UNALIGNED__
#include <string.h>

#define get_unaligned(ptr) \
({ __typeof__(*(ptr)) __tmp; memmove(&__tmp, (ptr), sizeof(*(ptr))); __tmp; })
#define put_unaligned(ptr, val) \
({ __typeof__(*(ptr)) __tmp = (val); \
memmove((ptr), &__tmp, sizeof(*(ptr))); \
(void)0; })
#else
#define get_unaligned(ptr) (*(ptr))
#define put_unaligned(ptr, val) ((void)( *(ptr) = (val) ))
#endif /* __EMULATE_UNALIGNED__ */

#ifdef __BIG_ENDIAN__
#define ADJUST_ENDIANNESS16(Ptr) {\
  USHORT x = get_unaligned((USHORT*) (Ptr));\
  put_unaligned((USHORT*) (Ptr), x >> 8 | x << 8);\
}
#define ADJUST_ENDIANNESS32(Ptr) {\
  ULONG x = get_unaligned((ULONG*) (Ptr));\
  x = x >> 16 | x << 16;\
  put_unaligned((ULONG*) (Ptr), (x&0xff00ff00) >> 8 | (x&0x00ff00ff) << 8);\
}
#define ADJUST_ENDIANNESS64(Ptr) {\
  ULONG x1 = get_unaligned((ULONG*) (Ptr)), x2 = get_unaligned(((ULONG*) (Ptr))+1);\
  x1 = x1 >> 16 | x1 << 16;\
  put_unaligned(((ULONG*) (Ptr))+1, (x1&0xff00ff00) >> 8 | (x1&0x00ff00ff) << 8);\
  x2 = x2 >> 16 | x2 << 16;\
  put_unaligned(((ULONG*) (Ptr)), (x2&0xff00ff00) >> 8 | (x2&0x00ff00ff) << 8);\
}
#else
#define ADJUST_ENDIANNESS16(Ptr) 
#define ADJUST_ENDIANNESS32(Ptr) 
#define ADJUST_ENDIANNESS64(Ptr) 
#endif

#endif
