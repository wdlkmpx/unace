#define INCL_BASE_MSGOUT_EXCLUSIVE

#define INCL_BASE_DIRDATA
#define INCL_BASE_STATE
#include "base/all/includes.h"

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#define INCL_APPS_EXE_MESSAGES
#include "apps/includes.h"

/*-----------------BASE_MSGOUT_EXTERN_ListCreateBegin--------------------*/
void    BASE_MSGOUT_EXTERN_ListCreateBegin(PVOID *SavedScreenPtr)
{
  APPS_EXE_OUTPUT_EXTERN_Message(55, STR.Working,
                        STR.Creating_listfile__Please_wait_);
}

/*-----------------BASE_MSGOUT_EXTERN_ListCreateEnd----------------------*/
void    BASE_MSGOUT_EXTERN_ListCreateEnd(PVOID *SavedScreenPtr)
{
}

/*-----------------BASE_MSGOUT_EXTERN_ReadingArchive---------------------*/
void    BASE_MSGOUT_EXTERN_ReadingArchive(PVOID *SavedScreen)
{
  APPS_EXE_OUTPUT_EXTERN_Message(55, STR.Working,
                        STR.Reading_archive__Please_wait__);
}

/*-----------------BASE_MSGOUT_EXTERN_ReadingArchiveEnd------------------*/
void    BASE_MSGOUT_EXTERN_ReadingArchiveEnd(PVOID *SavedScreen)
{
}


/*-----------------BASE_MSGOUT_EXTERN_ListCreate-------------------------*/

void    BASE_MSGOUT_EXTERN_ListAddingFile(PCHAR FileName)
{
}

/*-----------------BASE_MSGOUT_EXTERN_Analyzing--------------------------*/

void    BASE_MSGOUT_EXTERN_Analyzing(PCHAR FileName)
{
  BASE_STATE_EXTERN_OutputProcess(STR.__analyzing, FileName, 0);
}

/*-----------------BASE_MSGOUT_EXTERN_ExtractingOrTesting----------------*/

void    BASE_MSGOUT_EXTERN_ExtractingOrTesting(BOOL IsExtracting)
{
  BASE_STATE_EXTERN_OutputProcess(IsExtracting ? STR.extracting : STR.testing,
    BASE_STATE.CurrentFileName, 0);
}

/*-----------------BASE_MSGOUT_EXTERN_TestBegin--------------------------*/

void    BASE_MSGOUT_EXTERN_TestBegin(PCHAR ArchiveName)
{
CHAR      OutputStr[80];

  sprintf(OutputStr, "%s%s %s", STR.testing,
          BASE_DIRDATA_Dir1.IsLocked ? STR.__LOCKED_ : "", STR.archive);

  BASE_STATE_EXTERN_OutputProcess(OutputStr, ArchiveName, 1);
}

