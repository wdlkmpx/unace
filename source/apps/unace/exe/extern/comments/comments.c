#define INCL_BASE_COMMENTS

#define INCL_APPS_EXE_EXTERN_COMMENTS

#include "apps/unace/exe/includes.h"


/*-----------------BASE_COMMENTS_EXTERN_Output---------------------------*/

void    BASE_COMMENTS_EXTERN_Output(void)
{
  BASE_COMMENTS_ReadComment();

  if (BASE_COMMENTS.Comment[0])
  {
    APPS_EXE_EXTERN_COMMENTS_StdOutput();
  }
}
