#ifndef _APPS_EXE_INPUT_H_INCLUDED
#define _APPS_EXE_INPUT_H_INCLUDED

#ifndef _WIN32
#include <termios.h>
#endif

#define APPS_EXE_INPUT_SHIFT             3
#define APPS_EXE_INPUT_CTRL              4
#define APPS_EXE_INPUT_ALT               8
#define APPS_EXE_INPUT_CTRLALT           (APPS_EXE_INPUT_CTRL | APPS_EXE_INPUT_ALT)

typedef struct
{
        INT     LastKey,
                LastKey2,
                TimeCount;
} tAPPS_EXE_INPUT;

tAPPS_EXE_INPUT APPS_EXE_INPUT;

void    APPS_EXE_INPUT_InputProc(PCHAR StartStr, INT Width, PCHAR TopStr,
                                 PCHAR Discription, BOOL IsPasswInput,
                                 BOOL DoRegInput);

void    APPS_EXE_INPUT_Input(PCHAR StartStr, INT Width, PCHAR TopStr,
                             PCHAR Discription, BOOL IsPasswInput);

INT     APPS_EXE_INPUT_GetKey(void);
BOOL    APPS_EXE_INPUT_KeyHit(void);

INT     APPS_EXE_INPUT_WarningYANCProc(PCHAR TopStr, PCHAR Description1,
                                       PCHAR Description2);

void    APPS_EXE_INPUT_EXTERN_Input(PCHAR StartStr, INT Width,
                                    PCHAR TopStr,
                                    PCHAR Discription, BOOL IsPasswInput);

void    APPS_EXE_INPUT_EXTERN_InputProcOutputMask(BOOL DoRegInput);
void    APPS_EXE_INPUT_EXTERN_InputProcHandleKey(BOOL DoRegInput);

void    APPS_EXE_INPUT_EXTERN_InputProcHandleDelete(BOOL DoRegInput,
                                                    INT InputLen, INT Width);

BOOL    APPS_EXE_INPUT_EXTERN_InputProcInputCondition(BOOL DoRegInput,
                                                      INT InputLen);

void    APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtInput(BOOL DoRegInput,
                                                         INT InputLen,
                                                         INT Width);

INT     APPS_EXE_INPUT_EXTERN_WarningYANC(PCHAR TopStr, PCHAR Description1,
                                          PCHAR Description2);

#ifndef _WIN32
typedef struct
{
  struct termios OldtiMode;
  PCHAR   OldStdInBuf;
} tAPPS_EXE_INPUT_LINUX;

tAPPS_EXE_INPUT_LINUX APPS_EXE_INPUT_LINUX;
#endif

void    APPS_EXE_INPUT_LINUX_SetRawMode(void);
void    APPS_EXE_INPUT_LINUX_UnSetRawMode(void);

#endif
