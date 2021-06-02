#ifndef _BASE_COMMENTS_H_INCLUDED
#define _BASE_COMMENTS_H_INCLUDED

#include "base/all/lfn/lfn.h"

#ifdef INCL_BASE_COMMENTS_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


#define BASE_COMMENTS_HASHFUNC(A, B)    (A + B)

typedef struct
{
  USHORT  CompressedSize;
  CHAR    Comment[32768];
} tBASE_COMMENTS;

DECLEXT tBASE_COMMENTS
        BASE_COMMENTS;

void    BASE_COMMENTS_ReadComment(void);
void    BASE_COMMENTS_EXTERN_Output(void);
void    BASE_COMMENTS_EXTERN_ReadCommentEnd(void);


#undef DECLEXT

#endif
