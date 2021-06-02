/**************************************************************************/
/*                                                                        */
/* declare.h: declaration-symbols (uchar, ulong...;and their size         */
/*                                                                        */
/**************************************************************************/

#ifndef _DECLARE_H_INCLUDED
#define _DECLARE_H_INCLUDED

#if !defined(__OS2__) && !defined(_WINDOWS_)
  typedef int             BOOL;

  typedef char               CHAR;
  typedef unsigned char      UCHAR;
  typedef UCHAR             *PUCHAR;
  typedef char              *PSZ;

  typedef short              SHORT;
  typedef unsigned short     USHORT;
  typedef USHORT            *PUSHORT;

  typedef long               LONG;
  typedef unsigned long      ULONG;

  typedef ULONG             *PULONG;

  typedef int                INT;
  typedef unsigned int       UINT;
  typedef unsigned int      *PUINT;

  typedef CHAR              *LPSTR;
#endif

#if __WATCOMC__==1060
  typedef long               __int64[2];
  typedef __int64            LONGLONG;
  typedef LONGLONG          *PLONGLONG;
  typedef __int64            ULONGLONG;
  typedef ULONGLONG          DWORDLONG;
#else
  #if !defined(_WINDOWS_)
    #if !defined(__WATCOMC__) && !defined(__int64)
      #define __int64  long long
    #endif

    typedef __int64            LONGLONG;
    typedef LONGLONG          *PLONGLONG;
    typedef unsigned __int64   ULONGLONG;
    typedef ULONGLONG          DWORDLONG;
  #endif
#endif


#if !defined(_WINDOWS_)
  typedef BOOL           *PBOOL;
  typedef INT            *PINT;
#endif

#if !defined(__wtypes_h__)
  typedef void           *PVOID;
  typedef CHAR           *PCHAR;
  typedef SHORT          *PSHORT;
  typedef LONG           *PLONG;
  typedef ULONGLONG      *PULONGLONG;
#endif

#if defined(_GNU_H_WINDOWS32_BASE)
  typedef LONGLONG  	  ULONGLONG;
  typedef ULONGLONG      *PULONGLONG;
#endif

typedef signed char     SCHAR;

#ifndef NULL
 #if defined(__SMALL__) || defined(__MEDIUM__) || defined(__386__) || defined(__AXP__) || defined(__PPC__)
  #define NULL   0
 #else
  #define NULL   0L
 #endif
#endif


#endif
