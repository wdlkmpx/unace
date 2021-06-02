#define INCL_BASE_DIRDATA
#define INCL_BASE_MSGOUT
#define INCL_BASE_STATE

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT

#define INCL_APPS_EXE_MESSAGES

#include "apps/unace/exe/includes.h"


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
