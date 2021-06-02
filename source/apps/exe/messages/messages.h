#ifndef _APPS_EXE_MESSAGES_H_INCLUDED
#define _APPS_EXE_MESSAGES_H_INCLUDED

#include "apps/ace/exe/messages/messages.h"

#ifdef INCL_APPS_EXE_MESSAGES_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif

#define APPS_EXE_MESSAGES_ENGLISH      "default"
#define APPS_EXE_MESSAGES_COMMLINEHELPLINES 16

typedef struct
{
        tLFN    FileName;
        INT     LanguageIndex;
        INT     Handle;
        PCHAR   ReadPos;
        INT     YANCPos[4];
        CHAR    YANC[5];
        CHAR    FirstCommandLineHelpLine[81];
        PCHAR   MessagesBuf;
} tAPPS_EXE_MESSAGES;

DECLEXT tAPPS_EXE_MESSAGES
        APPS_EXE_MESSAGES;

#ifdef __WATCOMC__
extern  void
          APPS_EXE_MESSAGES_EXTERN_ENGLISH(void);
#else
extern  CHAR
          APPS_EXE_MESSAGES_EXTERN_ENGLISH[];
#endif

void    APPS_EXE_MESSAGES_Open(PCHAR FileName);
INT     APPS_EXE_MESSAGES_Read(void *Buf, INT Len);
void    APPS_EXE_MESSAGES_Skip(INT Len);
void    APPS_EXE_MESSAGES_Close(void);
BOOL    APPS_EXE_MESSAGES_GetMessageFile(tLFN FileName, PULONG Size);

void    APPS_EXE_MESSAGES_LoadMessagesPROC(PCHAR *EndMarkerPos,
                                                  PCHAR EndMarker);

INT     APPS_EXE_MESSAGES_GetHotKey(PCHAR Str);
void    APPS_EXE_MESSAGES_InitMessages(void);
void    APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific(void);
void    APPS_EXE_MESSAGES_EXTERN_LoadMessages(void);


#include "apps/exe/messages/msgstruc.h"


#undef DECLEXT

#endif
