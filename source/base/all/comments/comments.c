#include <string.h>

#define INCL_BASE_COMMENTS_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_DCPR_COMMENTS
#include "base/all/includes.h"

#define INCL_APPS_EXE_EXTERN_COMMENTS
#include "apps/exe/includes.h"

/*-----------------BASE_COMMENTS_EXTERN_Output---------------------------*/
void    BASE_COMMENTS_EXTERN_Output(void)
{
  BASE_COMMENTS_ReadComment();

  if (BASE_COMMENTS.Comment[0])
  {
    APPS_EXE_EXTERN_COMMENTS_StdOutput();
  }
}


/*-----------------BASE_COMMENTS_ReadComment---------------------------*/

void    BASE_COMMENTS_ReadComment(void)
{
INT       CommentSize;
PCHAR     CommentPos;

  if (!(BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_COMMENT))
  {
    CommentSize = 0;
  }
  else
  {
    if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
    {
      CommentPos  = BASE_ARCBLK_FileHeaderComment(&BASE_ARCBLK.Header);
      CommentSize = BASE_ARCBLK_FileHeaderCommentSize(&BASE_ARCBLK.Header);
    }
    else
    {
      if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_MAIN)
      {
        CommentPos  = BASE_ARCBLK_MainHeaderComment(&BASE_ARCBLK.Header);
        CommentSize = BASE_ARCBLK_MainHeaderCommentSize(&BASE_ARCBLK.Header);
      }
      else
      {
        CommentSize = 0;
      }
    }
  }

  if (CommentSize > sizeof(BASE_COMMENTS.Comment) - 1)
  {
    CommentSize = sizeof(BASE_COMMENTS.Comment) - 1;
  }

  if(CommentSize > 0)
  {
    memcpy(BASE_COMMENTS.Comment, CommentPos, CommentSize);
  }
  
  BASE_COMMENTS.CompressedSize = CommentSize;
  BASE_DCPR_COMMENTS_GetComment();

  BASE_COMMENTS_EXTERN_ReadCommentEnd();
}
