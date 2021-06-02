#include <fcntl.h>
#include <string.h>

#ifdef __HAS_IO_H__
	#include <io.h>
#endif

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_BUFREAD
#define INCL_BASE_CRC
#define INCL_BASE_DCPR
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_PATHFUNC
#define INCL_BASE_VOLUME

#include "base/unace/includes.h"


/*-----------------BASE_ARCBLK_EXTERN_OpenArchiveOverwriteRequest--------*/

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveOverwriteRequest(PCHAR Path, INT AccesFlags)
{
  return 0;
}

/*-----------------BASE_ARCBLK_EXTERN_LoadBlockBegin---------------------*/

void    BASE_ARCBLK_EXTERN_LoadBlockBegin(void)
{
}

/*-----------------BASE_ARCBLK_EXTERN_LoadBlockSetVariables--------------*/

void    BASE_ARCBLK_EXTERN_LoadBlockSetVariables(void)
{
  BASE_ARCBLK_EXTERN_SetFileData();
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchiveWriteOpen---------------*/

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveWriteOpen(INT Access, BOOL DoOutputError)
{
  return 1;
}

/*-----------------BASE_ARCBLK_EXTERN_CloseArchive-----------------------*/

void    BASE_ARCBLK_EXTERN_CloseArchive(INT AddRecovery)
{
  BASE_BUFREAD_Close();
}

/*-----------------BASE_ARCBLK_EXTERN_CurrentArchiveName-----------------*/

PCHAR   BASE_ARCBLK_EXTERN_CurrentArchiveName(void)
{
  return BASE_ARCBLK.ArchiveFile;
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchiveHandlePathRenaming------*/

void    BASE_ARCBLK_EXTERN_OpenArchiveHandlePathRenaming(PCHAR Path, INT Access)
{
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchiveHandlePathRenaming------*/

BOOL    BASE_ARCBLK_EXTERN_OpenArchiveCreateArchive(INT Access)
{
  return 1;
}

/*-----------------BASE_ARCBLK_EXTERN_ArchiveOpenReOpen------------------*/

void    BASE_ARCBLK_EXTERN_ArchiveOpenReOpen(INT Access)
{
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchivesSetVariables-----------*/

void    BASE_ARCBLK_EXTERN_OpenArchivesSetVariables(INT Access, BOOL DoResetCrypt)
{
  BASE_ARCBLK_EXTERN_OutputArchiveInfo(Access, DoResetCrypt);

  BASE_ARCBLK.Options.HasRecoveryRecord =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_RECOVERYREC;

  BASE_ARCBLK.Options.IsVolume          =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_MULTIVOLUME;

  BASE_ARCBLK.Options.IsSolid           =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SOLID;

  BASE_ARCBLK.Options.HasAuthenticityVerification =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_AV;

  BASE_ARCBLK.Options.IsLocked       =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_LOCK;

  BASE_ARCBLK.ArchiveFilePos         = BASE_DIRDATA_Dir1.ArchiveBegin;
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchiveWriteClose--------------*/

void    BASE_ARCBLK_EXTERN_OpenArchiveWriteClose(void)
{
}

/*-----------------BASE_ARCBLK_EXTERN_ReadAddSizeBlockCopyToTempArchive--*/

void    BASE_ARCBLK_EXTERN_ReadAddSizeBlockCopyToTempArchive(PCHAR Buffer, INT Read,
                                                 INT RestLen)
{
}

/*-----------------BASE_ARCBLK_EXTERN_ReadAddSizeBlockEncrypt------------*/

BOOL    BASE_ARCBLK_EXTERN_ReadAddSizeBlockEncrypt(PCHAR Buffer, INT Len)
{
  return 0;
}

/*-----------------BASE_ARCBLK_EXTERN_RemoveCreatedArchive---------------*/

void    BASE_ARCBLK_EXTERN_RemoveCreatedArchive(void)
{
}
