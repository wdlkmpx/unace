#include <string.h>

#define INCL_BASE_CRYPT_EXCLUSIVE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_DCPR
#define INCL_BASE_ERROR
#define INCL_BASE_OPTIONS

#include "base/all/includes.h"


#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#include "apps/includes.h"

/*-----------------BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent-------------*/

void    BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent(
          pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
INT       Input;

  if (!(BASE_CRYPT.DoUseCurrentPassword |=
          BASE_OPTIONS.ExtractOptions.DoUseCurrentPassword)
      && BASE_DCPR.Options.CryptionData.Password[0])
  {
    do
    {
      Input = APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Extract,
                                       STR.Found_encrypted_file_,
                                       STR.Use_current_password_);

      if (Input == 3)
      {
        BASE_ERROR.ErrorCode = BASE_ERROR_USER;
      }
      else
      {
        if (Input == 2)
        {
          if (BASE_OPTIONS_EXTERN_SetPassword(&BASE_DCPR.Options.CryptionData, 0))
          {
            BASE_ERROR.ErrorCode = BASE_ERROR_USER;
          }
          else
          {
            BASE_CRYPT_InitCryptKey(&BASE_DCPR.Options.CryptionData);
          }
        }
      }
    }
    while (!BASE_ERROR.ErrorCode && !BASE_DCPR.Options.CryptionData.Password[0]);

    BASE_CRYPT.DoUseCurrentPassword = (Input == 1);
  }

  if (!BASE_ERROR.ErrorCode && !BASE_DCPR.Options.CryptionData.Password[0])
  {
    APPS_EXE_OUTPUT_EXTERN_Warning(STR.Extract,
                          STR.Found_encrypted_file__No_password_specified_,
                          STR.Enter_password_);
  }
}

// ---

/*-----------------BASE_CRYPT_MakeSHA------------------------------------*/

void    BASE_CRYPT_MakeSHA(pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
INT       Count,
          I;
ULONG     A,
          B,
          C,
          D,
          E,
          W[80],
          Temp;

  Count = strlen(CryptionData->Password);

//initialize:

  CryptionData->SHAData.Digest[0] = 0x67452301L;
  CryptionData->SHAData.Digest[1] = 0xefcdab89L;
  CryptionData->SHAData.Digest[2] = 0x98badcfeL;
  CryptionData->SHAData.Digest[3] = 0x10325476L;
  CryptionData->SHAData.Digest[4] = 0xc3d2e1f0L;

  memset(&(CryptionData->SHAData.Data), 0,
         sizeof(CryptionData->SHAData.Data));

  memcpy(&(CryptionData->SHAData.Data), &(CryptionData->Password), Count);
  ((PUCHAR) &(CryptionData->SHAData.Data))[Count] = 0x80;
  
  for (I = 0; I < 15; I++) ADJUST_ENDIANNESS32(CryptionData->SHAData.Data+I);

  CryptionData->SHAData.Data[15] = Count << 3;

//calculate:

  for (I = 0; I < 16; I++)
  {
    W[I] = CryptionData->SHAData.Data[I];
  }

  for (I = 16; I < 80; I++)
  {
    W[I] = W[I - 3] ^ W[I - 8] ^ W[I - 14] ^ W[I - 16];
  }

  A = CryptionData->SHAData.Digest[0];
  B = CryptionData->SHAData.Digest[1];
  C = CryptionData->SHAData.Digest[2];
  D = CryptionData->SHAData.Digest[3];
  E = CryptionData->SHAData.Digest[4];

  for (I = 0; I < 20; I++)
  {
    BASE_CRYPT_SHAFUNC_1(I);
  }

  for (I = 20; I < 40; I++)
  {
    BASE_CRYPT_SHAFUNC_2(I);
  }

  for (I = 40; I < 60; I++)
  {
    BASE_CRYPT_SHAFUNC_3(I);
  }

  for (I = 60; I < 80; I++)
  {
    BASE_CRYPT_SHAFUNC_4(I);
  }

  CryptionData->SHAData.Digest[0] += A;
  CryptionData->SHAData.Digest[1] += B;
  CryptionData->SHAData.Digest[2] += C;
  CryptionData->SHAData.Digest[3] += D;
  CryptionData->SHAData.Digest[4] += E;
}

/*-----------------BASE_CRYPT_InitCryptKey-------------------------------*/

void    BASE_CRYPT_InitCryptKey(pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
INT       I,
          J;
PULONG    PixDigitP;
tBASE_CRYPT_BLOWFISHBLOCK
          Block;

  Block.Left    =
    Block.Right = 0;

  if (CryptionData->Password[0])
  {
    PixDigitP = (PULONG) CryptionData->PixDigitsP;

    for (I = 0; I < 1042; I++)
    {
      put_unaligned(PixDigitP+I, BASE_CRYPT_PIXDIGITS[I]);
    }

    PixDigitP = (PULONG) CryptionData->PixDigitsP;
    BASE_CRYPT_MakeSHA(CryptionData);

    for (I = 0; I < ((BASE_CRYPT_BLOWFISHROUNDS * 4 + 8) / 4); I++)
    {
// make a sparc solution without losing the performance for the other platforms
#ifdef __sun__
      ULONG PixDigit = get_unaligned(PixDigitP);
      PixDigit = PixDigit ^ (CryptionData->SHAData).Digest[I % 5];
      put_unaligned(PixDigitP, PixDigit);
      PixDigitP++;
#else
      *PixDigitP++ ^= (CryptionData->SHAData).Digest[I % 5];
#endif
    }

    for (I = 0; I < BASE_CRYPT_BLOWFISHROUNDS + 2; I += 2)
    {
      BASE_CRYPT_EncryptKey(&Block, CryptionData);

      CryptionData->PixDigitsP[I]     = Block.Left;
      CryptionData->PixDigitsP[I + 1] = Block.Right;
    }

    for (J = 0; J < 4; J++)
    {
      for (I = 0; I < 256; I += 2)
      {
        BASE_CRYPT_EncryptKey(&Block, CryptionData);

        CryptionData->PixDigitsS[J][I]     = Block.Left;
        CryptionData->PixDigitsS[J][I + 1] = Block.Right;
      }
    }
  }

  CryptionData->LastBlock.Right  =
    CryptionData->LastBlock.Left = 0;
}

/*-----------------BASE_CRYPT_EncryptKey---------------------------------*/

void    BASE_CRYPT_EncryptKey(pBASE_CRYPT_BLOWFISHBLOCK DataBlock,
                         pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
INT       I;
ULONG     Left,
          Right,
          Temp;

  Left  = DataBlock->Left;
  Right = DataBlock->Right;

  for (I = 0; I < BASE_CRYPT_BLOWFISHROUNDS; I++)
  {
    Left  ^= CryptionData->PixDigitsP[I];

    Right ^= ((CryptionData->PixDigitsS[0][(Left >> 24) & 255] +
               CryptionData->PixDigitsS[1][(Left >> 16) & 255]) ^
               CryptionData->PixDigitsS[2][(Left >> 8) & 255]) +
               CryptionData->PixDigitsS[3][Left & 255];

    Temp  = Left;
    Left  = Right;
    Right = Temp;
  }

  Left  ^= CryptionData->PixDigitsP[BASE_CRYPT_BLOWFISHROUNDS];
  Right ^= CryptionData->PixDigitsP[(BASE_CRYPT_BLOWFISHROUNDS + 1)];

  DataBlock->Left  = Right;
  DataBlock->Right = Left;
}

/*-----------------BASE_CRYPT_DecryptBlock-------------------------------*/

void    BASE_CRYPT_DecryptBlock(pBASE_CRYPT_BLOWFISHBLOCK DataBlock)
{
INT       I;
ULONG     Left,
          Right,
          Temp;

  Left  = DataBlock->Left;
  Right = DataBlock->Right;

  for (I = (BASE_CRYPT_BLOWFISHROUNDS + 1); I > 1; I--)
  {
    Left  ^= BASE_DCPR.Options.CryptionData.PixDigitsP[I];

    Right ^= ((BASE_DCPR.Options.CryptionData.PixDigitsS[0][(Left >> 24) & 255] +
               BASE_DCPR.Options.CryptionData.PixDigitsS[1][(Left >> 16) & 255]) ^
               BASE_DCPR.Options.CryptionData.PixDigitsS[2][(Left >> 8) & 255]) +
               BASE_DCPR.Options.CryptionData.PixDigitsS[3][Left & 255];

    Temp  = Left;
    Left  = Right;
    Right = Temp;
  }

  Left  ^= BASE_DCPR.Options.CryptionData.PixDigitsP[1];
  Right ^= BASE_DCPR.Options.CryptionData.PixDigitsP[0];

  DataBlock->Left  = Right;
  DataBlock->Right = Left;
}

/*-----------------BASE_CRYPT_CryptLen-----------------------------------*/

INT     BASE_CRYPT_CryptLen(INT Len)
{
INT       Blocks;

  Blocks = Len / sizeof(tBASE_CRYPT_BLOWFISHBLOCK);

  if (Blocks * sizeof(tBASE_CRYPT_BLOWFISHBLOCK) < Len)
  {
    Blocks++;
  }

  return Blocks * sizeof(tBASE_CRYPT_BLOWFISHBLOCK);
}

/*-----------------BASE_CRYPT_Decrypt------------------------------------*/

void    BASE_CRYPT_Decrypt(PCHAR Buf, INT Len)
{
INT       I,
          Blocks;
pBASE_CRYPT_BLOWFISHBLOCK
          DataBlock;
tBASE_CRYPT_BLOWFISHBLOCK
          LastBlock;

  if (BASE_DCPR.Options.CryptionData.Password[0])
  {
    Blocks = Len / sizeof(tBASE_CRYPT_BLOWFISHBLOCK);

    DataBlock = (pBASE_CRYPT_BLOWFISHBLOCK) Buf;

    for (I = 0; I < Blocks; I++, DataBlock++)
    {
      ADJUST_ENDIANNESS32(&DataBlock->Left);
      ADJUST_ENDIANNESS32(&DataBlock->Right);
      
      LastBlock = *DataBlock;
      BASE_CRYPT_DecryptBlock(DataBlock);

      DataBlock->Left  ^= BASE_DCPR.Options.CryptionData.LastBlock.Left;
      DataBlock->Right ^= BASE_DCPR.Options.CryptionData.LastBlock.Right;

      ADJUST_ENDIANNESS32(&DataBlock->Left);
      ADJUST_ENDIANNESS32(&DataBlock->Right);

      BASE_DCPR.Options.CryptionData.LastBlock = LastBlock;
    }
  }
}

/*-----------------BASE_CRYPT_ResetCryptKey------------------------------*/

void    BASE_CRYPT_ResetCryptKey(pBASE_CRYPT_CRYPTIONDATA CryptionData)
{
  CryptionData->LastBlock.Right  =
    CryptionData->LastBlock.Left = 0;

  if (CryptionData == &BASE_DCPR.Options.CryptionData
      && (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD))
  {
    BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent(CryptionData);

    if (!BASE_ERROR.ErrorCode && !BASE_DCPR.Options.CryptionData.Password[0])
    {
      if (BASE_OPTIONS_EXTERN_SetPassword(&BASE_DCPR.Options.CryptionData, 0))
      {
        BASE_ERROR.ErrorCode = BASE_ERROR_USER;
      }
      else
      {
        BASE_CRYPT_InitCryptKey(&BASE_DCPR.Options.CryptionData);
      }
    }
  }
}
