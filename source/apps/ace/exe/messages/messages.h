#ifndef _APPS_ACE_EXE_MESSAGES_H_INCLUDED
#define _APPS_ACE_EXE_MESSAGES_H_INCLUDED


#ifdef INCL_APPS_ACE_EXE_MESSAGES_EXCLUSIVE
  #define DECLEXT
#else
  #define DECLEXT extern
#endif


#define APPS_ACE_EXE_MESSAGES_ARCHIVEOPTIONWINLINES             16
#define APPS_ACE_EXE_MESSAGES_CREATIONARCHIVINGOPTIONSLINES     17
#define APPS_ACE_EXE_MESSAGES_MAXHELPLINES                      19
#define APPS_ACE_EXE_MESSAGES_SHELLHELPPAGES                    6
#define APPS_ACE_EXE_MESSAGES_VIEWERHELPPAGES                   1
#define APPS_ACE_EXE_MESSAGES_COMMLINEHELPLINES                 46
#define APPS_ACE_EXE_MESSAGES_SFXDESCRIPTIONLINES               17
#define APPS_ACE_EXE_MESSAGES_CHANGEOPTIONSLINES                6
#define APPS_ACE_EXE_MESSAGES_HOTKEYLINES                       9

typedef struct
{
        INT     LevelDisPos[6],
                ChangeArchiveOptionsPos[6],
                ChangeFileOptionsPos[2],
                ChangeOptionsPos[APPS_ACE_EXE_MESSAGES_CHANGEOPTIONSLINES],
                ExternalProgramsPos[2];
} tAPPS_ACE_EXE_MESSAGES;

DECLEXT tAPPS_ACE_EXE_MESSAGES
        APPS_ACE_EXE_MESSAGES;

BOOL    APPS_ACE_EXE_MESSAGES_GetMessageFileInfo(tLFN FileName,
                                                 tLFN LongTitle);


#undef DECLEXT

#endif
