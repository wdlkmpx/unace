/**************************************************************************/
/*                                                                        */
/* declare.h: declaration-symbols (uchar, ulong...;and their size         */
/*                                                                        */
/**************************************************************************/

#ifndef _DECLARE_H_INCLUDED
#define _DECLARE_H_INCLUDED

#include <stdint.h>

#ifndef _WIN32
typedef int             BOOL;
typedef BOOL           *PBOOL;

typedef char               CHAR;
typedef CHAR              *PCHAR;
typedef unsigned char      UCHAR;
typedef UCHAR             *PUCHAR;
typedef signed char        SCHAR;
typedef CHAR              *PSZ;
typedef CHAR              *LPSTR;

typedef int                INT;
typedef INT               *PINT;
typedef unsigned int       UINT;
typedef unsigned int      *PUINT;

typedef int16_t            SHORT;
typedef SHORT             *PSHORT;
typedef uint16_t           USHORT;
typedef USHORT            *PUSHORT;

typedef int32_t            LONG;
typedef LONG              *PLONG;
typedef uint32_t           ULONG;
typedef ULONG             *PULONG;

typedef int64_t            LONGLONG;
typedef LONGLONG          *PLONGLONG;
typedef uint64_t           ULONGLONG;
typedef ULONGLONG         *PULONGLONG;

typedef void              *PVOID;
#endif

#endif
