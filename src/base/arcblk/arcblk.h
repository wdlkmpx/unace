#ifndef _BASE_ARCBLK_H_INCLUDED
#define _BASE_ARCBLK_H_INCLUDED

#include "base/acestruc.h"
#include "base/lfn/lfn.h"

typedef struct
{
  BOOL    IsVolume,
          IsSolid,
          IsLocked,
          IsSFX,
          HasMainComent,
          HasRecoveryRecord,
          HasAuthenticityVerification;
} tBASE_ARCBLK_OPTIONS, *pBASE_ARCBLK_OPTIONS;

typedef struct
{
  BOOL    DoOpenForReadOnly,
          DoOutputComments,
          DoCopyBlockToTempArchive,
	  DoNotPrintAV;
  ULONGLONG
          ArchiveFilePos,
          BlockPos,
          HeadPos,
          SkipSize,
          ArchiveBegin;
  tLFN    ArchiveFile;
  tBASE_ACESTRUC_HEADER
          Header;

  tBASE_ARCBLK_OPTIONS
          Options;
} tBASE_ARCBLK;

extern tBASE_ARCBLK BASE_ARCBLK; // arcblk.c

PUSHORT BASE_ARCBLK_MainHeaderCommentSizePos(pBASE_ACESTRUC_HEADER Header);
UINT    BASE_ARCBLK_MainHeaderCommentSize(pBASE_ACESTRUC_HEADER Header);
PCHAR   BASE_ARCBLK_MainHeaderComment(pBASE_ACESTRUC_HEADER Header);
PCHAR   BASE_ARCBLK_MainHeaderStuff(pBASE_ACESTRUC_HEADER Header);
PUSHORT BASE_ARCBLK_FileHeaderCommentSizePos(pBASE_ACESTRUC_HEADER Header);
UINT    BASE_ARCBLK_FileHeaderCommentSize(pBASE_ACESTRUC_HEADER Header);
PCHAR   BASE_ARCBLK_FileHeaderComment(pBASE_ACESTRUC_HEADER Header);
PUSHORT BASE_ARCBLK_FileHeaderSecuritySizePos(pBASE_ACESTRUC_HEADER Header);
PCHAR   BASE_ARCBLK_FileHeaderSecurity(pBASE_ACESTRUC_HEADER Header);
void    BASE_ARCBLK_FileHeaderSecurityRead(pBASE_ACESTRUC_HEADER Header, PCHAR *Security, PUINT Size);
void    BASE_ARCBLK_FileHeaderSecurityWrite(pBASE_ACESTRUC_HEADER Header, PCHAR Security, UINT Size);
UINT    BASE_ARCBLK_CalculateHeaderCRC(pBASE_ACESTRUC_HEADER Header);
BOOL    BASE_ARCBLK_CheckHeaderCRC(void);

ULONGLONG
        BASE_ARCBLK_GetAddSize(pBASE_ACESTRUC_HEADER Header);

PCHAR   BASE_ARCBLK_GetFileName(PCHAR FileName, pBASE_ACESTRUC_HEADER Header);
void    BASE_ARCBLK_SkipFileBlock(void);
void 	BASE_ARCBLK_AdjustEndiannessOfHeaderBase(void);
void 	BASE_ARCBLK_AdjustEndiannessOfHeaderRest(void);
void    BASE_ARCBLK_ConvertHeader32ToHeader64(void);
BOOL    BASE_ARCBLK_LoadBlock(void);
INT     BASE_ARCBLK_ReadAddSizeBlock(PCHAR Buffer, INT Len);

INT     BASE_ARCBLK_OpenArchive(PCHAR Path, INT Access, BOOL DoOutputError,
                                BOOL DoOutputComm, BOOL DoResetCrypt);

void    BASE_ARCBLK_EXTERN_CloseArchive(INT AddRecovery);
void    BASE_ARCBLK_EXTERN_SetFileData(void);

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveOverwriteRequest(PCHAR Path,
                                                       INT AccesFlags);

void    BASE_ARCBLK_EXTERN_LoadBlockBegin(void);
void    BASE_ARCBLK_EXTERN_LoadBlockSetVariables(void);

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveWriteOpen(INT Access,
                                                BOOL DoOutputError);

void    BASE_ARCBLK_EXTERN_OutputArchiveInfo(INT Access, BOOL DoResetCrypt);

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveOverwriteRequest(PCHAR Path,
                                                       INT Access);

PCHAR   BASE_ARCBLK_EXTERN_CurrentArchiveName(void);

void    BASE_ARCBLK_EXTERN_OpenArchiveHandlePathRenaming(PCHAR Path,
                                                         INT Access);

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveCreateArchive(INT Access);
void    BASE_ARCBLK_EXTERN_ArchiveOpenReOpen(INT Access);

void    BASE_ARCBLK_EXTERN_OpenArchivesSetVariables(INT Access,
                                                    BOOL DoResetCrypt);

void    BASE_ARCBLK_EXTERN_OpenArchiveWriteClose(void);

void    BASE_ARCBLK_EXTERN_ReadAddSizeBlockCopyToTempArchive(PCHAR Buffer,
                                                             INT Read,
                                                             INT RestLen);

BOOL    BASE_ARCBLK_EXTERN_ReadAddSizeBlockEncrypt(PCHAR Buffer, INT Len);

void    BASE_ARCBLK_EXTERN_RemoveCreatedArchive(void);

#endif
