#include <stdio.h>
#include <string.h>

#define INCL_BASE_CONVERT
#define INCL_BASE_DCPR
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_EXTRACT
#define INCL_BASE_FILELIST
#define INCL_BASE_FUNCS
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES

#include "apps/exe/includes.h"


/*-----------------BASE_FUNCS_EXTERN_MoveRealSysFileRequest--------------*/

INT     BASE_FUNCS_EXTERN_MoveDeleteRealSysFileRequest(void)
{
  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Delete_noun,
                           STR.Found_read_only__hidden_or_system_file_,
                           STR.Delete_it_anyway_);
// BASE_STATE.CurrentFileNameName
}

/*-----------------BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite----*/

BOOL    BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite(void)
{
CHAR      OutputStr[80],
          ShortStr[80];

  sprintf(OutputStr, "%s %s", STR.File_already_exists_,
          APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_STATE.CurrentFileName, 30));

  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy_noun, OutputStr, STR.Overwrite_);
}

/*-----------------BASE_FUNCS_EXTERN_RequestOverwriteSysFile-------------*/

BOOL    BASE_FUNCS_EXTERN_RequestOverwriteSysFile(void)
{
CHAR      OutputStr[80],
          ShortStr[80];

  sprintf(OutputStr, "%s %s",
          BASE_CONVERT_ToOEM(APPS_EXE_CONVERT_MakeStrShorter(ShortStr,
            BASE_STATE.CurrentFileName, 26)),
          STR.is_read_only__hidden_or_system_file_);

  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy, OutputStr,
                                           STR.Overwrite_it_anyway_);
}
