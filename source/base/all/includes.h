#ifndef _INCLUDES_H_INCLUDED
#define _INCLUDES_H_INCLUDED

#include "base/all/all.h"

#if defined(INCL_BASE_ACESTRUC)                 || defined(INCL_BASE_ACESTRUC_EXCLUSIVE)
   #include "base/all/acestruc.h"
#endif

#if defined(INCL_BASE_VERSION)                  || defined(INCL_BASE_VERSION_EXCLUSIVE)
   #include "base/all/version.h"
#endif

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_BASE_ARCBLK)                   || defined(INCL_BASE_ARCBLK_EXCLUSIVE)
   #include "base/all/arcblk/arcblk.h"
#endif

#if defined(INCL_BASE_ARCHIVES_ACE)             || defined(INCL_BASE_ARCHIVES_ACE_EXCLUSIVE)
   #include "base/all/archives/ace/ace.h"
#endif

#if defined(INCL_BASE_ARCHIVES_READ)            || defined(INCL_BASE_ARCHIVES_READ_EXCLUSIVE)
   #include "base/all/archives/read/read.h"
#endif

#if defined(INCL_BASE_ARCHIVES_TEST)            || defined(INCL_BASE_ARCHIVES_TEST_EXCLUSIVE)
   #include "base/all/archives/test/test.h"
#endif

#if defined(INCL_BASE_ARCINFO)                  || defined(INCL_BASE_ARCINFO_EXCLUSIVE)
   #include "base/all/arcinfo/arcinfo.h"
#endif

#if defined(INCL_BASE_BITWIDTH)                 || defined(INCL_BASE_BITWIDTH_EXCLUSIVE)
   #include "base/all/bitwidth/bitwidth.h"
#endif

#if defined(INCL_BASE_BUFREAD)                  || defined(INCL_BASE_BUFREAD_EXCLUSIVE)
   #include "base/all/bufread/bufread.h"
#endif

#if defined(INCL_BASE_COMMENTS)                 || defined(INCL_BASE_COMMENTS_EXCLUSIVE)
   #include "base/all/comments/comments.h"
#endif

#if defined(INCL_BASE_CONVERT)                  || defined(INCL_BASE_CONVERT_EXCLUSIVE)
   #include "base/all/convert/convert.h"
#endif

#if defined(INCL_BASE_CPRDCPR_HUFF)               || defined(INCL_BASE_CPRDCPR_HUFF_EXCLUSIVE)
   #include "base/all/cprdcpr/huff/huff.h"
#endif

  #if defined(INCL_BASE_CPRDCPR_LZ77)             || defined(INCL_BASE_CPRDCPR_LZ77_EXCLUSIVE)
     #include "base/all/cprdcpr/lz77/lz77.h"
  #endif

  #if defined(INCL_BASE_CPRDCPR_PIC)              || defined(INCL_BASE_CPRDCPR_PIC_EXCLUSIVE)
     #include "base/all/cprdcpr/pic/pic.h"
  #endif

  #if defined(INCL_BASE_CPRDCPR_SOUND)            || defined(INCL_BASE_CPRDCPR_SOUND_EXCLUSIVE)
     #include "base/all/cprdcpr/sound/sound.h"
  #endif

#if defined(INCL_BASE_CRC)                      || defined(INCL_BASE_CRC_EXCLUSIVE)
   #include "base/all/crc/crc.h"
#endif

#if defined(INCL_BASE_CRYPT)                    || defined(INCL_BASE_CRYPT_EXCLUSIVE)
   #include "base/all/crypt/crypt.h"
#endif

#if defined(INCL_BASE_DCPR)                     || defined(INCL_BASE_DCPR_EXCLUSIVE)
   #include "base/all/dcpr/dcpr.h"
#endif

  #if defined(INCL_BASE_DCPR_COMMENTS)            || defined(INCL_BASE_DCPR_COMMENTS_EXCLUSIVE)
     #include "base/all/dcpr/comments/comments.h"
  #endif

  #if defined(INCL_BASE_DCPR_HUFF)                || defined(INCL_BASE_DCPR_HUFF_EXCLUSIVE)
     #include "base/all/dcpr/huff/huff.h"
  #endif

  #if defined(INCL_BASE_DCPR_LZ77)                || defined(INCL_BASE_DCPR_LZ77_EXCLUSIVE)
     #include "base/all/dcpr/lz77/lz77.h"
  #endif

  #if defined(INCL_BASE_DCPR_PIC)                 || defined(INCL_BASE_DCPR_PIC_EXCLUSIVE)
     #include "base/all/dcpr/pic/pic.h"
  #endif

  #if defined(INCL_BASE_DCPR_SOUND)               || defined(INCL_BASE_DCPR_SOUND_EXCLUSIVE)
     #include "base/all/dcpr/sound/sound.h"
  #endif

#if defined(INCL_BASE_DIRDATA)                  || defined(INCL_BASE_DIRDATA_EXCLUSIVE)
   #include "base/all/dirdata/dirdata.h"
#endif

#if defined(INCL_BASE_DOSFUNCS)                 || defined(INCL_BASE_DOSFUNCS_EXCLUSIVE)
   #include "base/all/dosfuncs/dosfuncs.h"
#endif

  #if defined(INCL_BASE_DOSFUNCS_NT)            || defined(INCL_BASE_DOSFUNCS_NT_EXCLUSIVE)
     #include "base/all/dosfuncs/nt.h"
  #endif

#if defined(INCL_BASE_ERROR)                    || defined(INCL_BASE_ERROR_EXCLUSIVE)
   #include "base/all/error/error.h"
#endif

#if defined(INCL_BASE_ERROROUT)                 || defined(INCL_BASE_ERROROUT_EXCLUSIVE)
   #include "base/all/errorout/errorout.h"
#endif

#if defined(INCL_BASE_EXTRACT)                  || defined(INCL_BASE_EXTRACT_EXCLUSIVE)
   #include "base/all/extract/extract.h"
#endif

#if defined(INCL_BASE_FILELIST)                 || defined(INCL_BASE_FILELIST_EXCLUSIVE)
   #include "base/all/filelist/filelist.h"
#endif

#if defined(INCL_BASE_FUNCS)                    || defined(INCL_BASE_FUNCS_EXCLUSIVE)
   #include "base/all/funcs/funcs.h"
#endif

#if defined(INCL_BASE_LFN)                      || defined(INCL_BASE_LFN_EXCLUSIVE)
   #include "base/all/lfn/lfn.h"
#endif

  #if defined(INCL_BASE_LFN_DOS32)                || defined(INCL_BASE_LFN_DOS32_EXCLUSIVE)
     #include "base/all/lfn/dos32.h"
  #endif

#if defined(INCL_BASE_MEMORY)                   || defined(INCL_BASE_MEMORY_EXCLUSIVE)
   #include "base/all/memory/memory.h"
#endif

  #if defined(INCL_BASE_MEMORY_DOS32)             || defined(INCL_BASE_MEMORY_DOS32_EXCLUSIVE)
     #include "base/all/memory/dos32.h"
  #endif

#if defined(INCL_BASE_MSGOUT)                   || defined(INCL_BASE_MSGOUT_EXCLUSIVE)
       #include "base/all/msgout/msgout.h"
#endif

#if defined(INCL_BASE_OPTIONS)                  || defined(INCL_BASE_OPTIONS_EXCLUSIVE)
   #include "base/all/options/options.h"
#endif

#if defined(INCL_BASE_PATHFUNC)                 || defined(INCL_BASE_PATHFUNC_EXCLUSIVE)
   #include "base/all/pathfunc/pathfunc.h"
#endif

#if defined(INCL_BASE_QSORT)                    || defined(INCL_BASE_QSORT_EXCLUSIVE)
   #include "base/all/qsort/qsort.h"
#endif

#if defined(INCL_BASE_STATE)                    || defined(INCL_BASE_STATE_EXCLUSIVE)
   #include "base/all/state/state.h"
#endif

#if defined(INCL_BASE_SYSTEM)                   || defined(INCL_BASE_SYSTEM_EXCLUSIVE)
   #include "base/all/system/system.h"
#endif

  #if defined(INCL_BASE_SYSTEM_DOS32)             || defined(INCL_BASE_SYSTEM_DOS32_EXCLUSIVE)
     #include "base/all/system/dos32.h"
  #endif

#if defined(INCL_BASE_UNINORM)                   || defined(INCL_BASE_UNINORM_EXCLUSIVE)
   #include "base/all/uninorm/uninorm.h"
#endif

#if defined(INCL_BASE_VOLUME)                   || defined(INCL_BASE_VOLUME_EXCLUSIVE)
   #include "base/all/volume/volume.h"
#endif

#endif
