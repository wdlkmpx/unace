#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define INCL_APPS_EXE_INPUT_EXCLUSIVE

#define INCL_BASE_ERROR
#define INCL_BASE_CONVERT

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_COMMLINE
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#define INCL_APPS_EXE_STATE
#define INCL_APPS_EXE_COMMLINE

#include "unace_includes.h"


/*-----------------APPS_EXE_INPUT_EXTERN_Input---------------------------*/
void    APPS_EXE_INPUT_EXTERN_Input(PCHAR StartStr, INT Width,
                                      PCHAR TopStr,
                                      PCHAR Discription, BOOL IsPasswInput)
{
  APPS_EXE_INPUT_Input(StartStr, Width, TopStr,
                       Discription, IsPasswInput);
}

/*-----------------APPS_EXE_INPUT_EXTERN_InputProcOutputMask-------------*/
void APPS_EXE_INPUT_EXTERN_InputProcOutputMask(BOOL DoRegInput)
{
}
/*-----------------APPS_EXE_INPUT_EXTERN_InputProcHandleKey--------------*/
void APPS_EXE_INPUT_EXTERN_InputProcHandleKey(BOOL DoRegInput)
{
}
/*-----------------APPS_EXE_INPUT_EXTERN_InputProcHandleDelete-----------*/
void APPS_EXE_INPUT_EXTERN_InputProcHandleDelete(BOOL DoRegInput, INT InputLen,
                                           INT Width)
{
}
/*-----------------APPS_EXE_INPUT_EXTERN_InputProcInputCondition---------*/
BOOL APPS_EXE_INPUT_EXTERN_InputProcInputCondition(BOOL DoRegInput, INT InputLen)
{
  return 1;
}
/*-----------------APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtOutput-----*/
void APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtInput(BOOL DoRegInput, INT InputLen, INT Width)
{
}
/*-----------------APPS_EXE_INPUT_EXTERN_WarningYANC---------------------*/
INT APPS_EXE_INPUT_EXTERN_WarningYANC(PCHAR TopStr, PCHAR Description1, PCHAR Description2)
{
  return APPS_EXE_INPUT_WarningYANCProc(TopStr, Description1, Description2);
}

// ==========================================================================


/*-----------------APPS_EXE_INPUT_InputProc------------------------------*/

void    APPS_EXE_INPUT_InputProc(PCHAR StartStr, INT Width, PCHAR TopStr,
                                 PCHAR Discription, BOOL IsPasswInput,
                                 BOOL DoRegInput)
{
BOOL      IsFirstKeyPressed,
          IsTimeOut;
CHAR      InputStr[80],
          TempStr[80];
INT       TimeCount,
          InputLen;

  IsFirstKeyPressed = 1;

  IsTimeOut = 0;

  strcpy(InputStr, BASE_CONVERT_ToOEM(StartStr));
  InputLen = strlen(InputStr);

  APPS_EXE_OUTPUT_DeleteRight();

  sprintf(TempStr, "%s:", TopStr);
  APPS_EXE_OUTPUT_Write(TempStr);

  sprintf(TempStr, "  %s", Discription);
  APPS_EXE_OUTPUT_Write(TempStr);

  printf("\n  %s", InputStr);

  APPS_EXE_INPUT_EXTERN_InputProcOutputMask(DoRegInput);
  
#ifndef __sun__
  fflush(stdout);
#endif

  do
  {
    TimeCount = 0;

    while (!APPS_EXE_INPUT_KeyHit() && !BASE_ERROR.ErrorCode)
    {
      if (IsFirstKeyPressed)
      {
        if (APPS_EXE_COMMLINE.TimeOutLimit
            && TimeCount > APPS_EXE_COMMLINE.TimeOutLimit)
        {
          IsTimeOut = 1;

          break;
        }

        TimeCount++;
        APPS_EXE_STATE_Delay(100);
      }
    }

    if (IsTimeOut)
    {
      break;
    }

    BASE_ERROR_EXTERN_HandleCancel(0);

    APPS_EXE_INPUT_EXTERN_InputProcHandleKey(DoRegInput);

    if (APPS_EXE_INPUT.LastKey != 13 && APPS_EXE_INPUT.LastKey != 27)
    {
      if (APPS_EXE_INPUT.LastKey == 8)                 // Backspace
      {
        if (InputLen)
        {
          APPS_EXE_INPUT_EXTERN_InputProcHandleDelete(DoRegInput, InputLen,
                                                      Width);

          printf("\x8 \x8");
          InputLen--;
#ifndef __sun__
          fflush(stdout);
#endif
        }
      }
      else
      {
        if ((isprint(APPS_EXE_INPUT.LastKey) || strchr("ÑîÅéôö", APPS_EXE_INPUT.LastKey))
            && InputLen < Width)
        {
          if (APPS_EXE_INPUT_EXTERN_InputProcInputCondition(DoRegInput,
                                                            InputLen))
          {
            InputStr[InputLen++] = APPS_EXE_INPUT.LastKey;

            putchar(IsPasswInput ? '*' : APPS_EXE_INPUT.LastKey);

            APPS_EXE_INPUT_EXTERN_InputProcOutputMaskAtInput(
              DoRegInput, InputLen, Width);

#ifndef __sun__
            fflush(stdout);
#endif
          }
        }
      }
    }

    IsFirstKeyPressed = 0;
  }
  while (APPS_EXE_INPUT.LastKey != 13 && APPS_EXE_INPUT.LastKey != 27
         && !BASE_ERROR_EXTERN_HandleCancel(0));

  APPS_EXE_OUTPUT_Write("");

  if (IsTimeOut)
  {
    BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;
    APPS_EXE_OUTPUT_Error(STR.Time_out_error_);
  }
  else
  {
    if (APPS_EXE_INPUT.LastKey != 13)
    {
      InputLen = 0;
    }

    InputStr[InputLen] = 0;

    if (APPS_EXE_INPUT.LastKey == 13)
    {
      strcpy(StartStr, BASE_CONVERT_ToANSI(InputStr));
    }
  }
}

/*-----------------APPS_EXE_INPUT_Input----------------------------------*/

void    APPS_EXE_INPUT_Input(PCHAR StartStr, INT Width, PCHAR TopStr,
                             PCHAR Discription, BOOL IsPasswInput)
{
  APPS_EXE_INPUT_InputProc(StartStr, Width, TopStr, Discription,
                           IsPasswInput, 0);
}


/*-----------------APPS_EXE_INPUT_WarningYANCProc------------------------*/

INT     APPS_EXE_INPUT_WarningYANCProc(PCHAR TopStr, PCHAR Description1,
                                       PCHAR Description2)
{
CHAR      ShortStr1[80],
          ShortStr2[80],
          TempStr[200];
INT       TimeCount;
UINT      ButtonNumber;
PCHAR     ButtonPtr;
PCHAR     Output;

  APPS_EXE_CONVERT_MakeStrShorter(ShortStr1, Description1, 79);
  APPS_EXE_CONVERT_MakeStrShorter(ShortStr2, Description2, 79);
  APPS_EXE_OUTPUT_DeleteRight();

  sprintf(TempStr, "%s:\n  %s\n  %s\n  (%s, %s, %s, %s)", TopStr,
          ShortStr1, ShortStr2, STR.Yes, STR.Always, STR.No, STR.Cancel);

  APPS_EXE_OUTPUT_Write(TempStr);

  do
  {
    TimeCount = 0;

    while (!APPS_EXE_INPUT_KeyHit() && !BASE_ERROR.ErrorCode)
    {
      if (APPS_EXE_COMMLINE.TimeOutLimit
          && TimeCount > APPS_EXE_COMMLINE.TimeOutLimit)
      {
        BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;
        APPS_EXE_OUTPUT_Error(STR.Time_out_error_);

        return 3;
      }

      TimeCount++;
      APPS_EXE_STATE_Delay(100);
    }

    BASE_ERROR_EXTERN_HandleCancel(0);
    APPS_EXE_INPUT.LastKey = BASE_CONVERT_UpCase(APPS_EXE_INPUT.LastKey);

    if (APPS_EXE_INPUT.LastKey == 27)
    {
      APPS_EXE_INPUT.LastKey = APPS_EXE_MESSAGES.YANC[3];
    }
  }
  while (!(ButtonPtr =
             strchr(APPS_EXE_MESSAGES.YANC, APPS_EXE_INPUT.LastKey))
         && !BASE_ERROR_EXTERN_HandleCancel(0));

  ButtonNumber = ButtonPtr - APPS_EXE_MESSAGES.YANC;

  if (!BASE_ERROR.ErrorCode)
  {
    switch (ButtonNumber)
    {
      case 0:
      {
        Output = STR.Yes;

        break;
      }

      case 1:
      {
        Output = STR.Always;

        break;
      }

      case 2:
      {
        Output = STR.No;

        break;
      }

      case 3:
      {
        Output = STR.Cancel;

        break;
      }
    }

    APPS_EXE_OUTPUT_Write(Output);
  }

  return ButtonNumber;
}
