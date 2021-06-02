#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define INCL_APPS_EXE_EXTERN_COMMENTS_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_STATE

#define INCL_BASE_ACE_CPR_BASE_COMMENTS
#define INCL_BASE_ACE_OUTPUT

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_OUTPUT

#include "apps/exe/includes.h"


/*-----------------BASE_COMMENTS_EXTERN_ReadCommentEnd-------------------*/

void    BASE_COMMENTS_EXTERN_ReadCommentEnd(void)
{
}

/*-----------------APPS_EXE_EXTERN_COMMENTS_StdOutput--------------------*/

void    APPS_EXE_EXTERN_COMMENTS_StdOutput(void)
{
  APPS_EXE_OUTPUT_DeleteRight();

  APPS_EXE_OUTPUT_Write(
    BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE ?
      STR.File_comment : STR.Main_comment);

  printf("\n%s", BASE_COMMENTS.Comment);

  if (strchr(BASE_COMMENTS.Comment, 27))
  {
    printf("[0m");
  }

  APPS_EXE_OUTPUT_KeyWait();
}
