BASE_SRCS                         = $(SRCS)base/
BASE_ALL_SRCS                     = $(BASE_SRCS)all/
BASE_OBJ_DIR                      = $(OBJ_DIR)base/
BASE_OBJ16_DIR                    = $(BASE_OBJ_DIR)16/
BASE_OBJ32_DIR                    = $(BASE_OBJ_DIR)32/

dosBASE_SRCS                      = $(SRCS)base\ #

##############################################################################
$(BASE_OBJ32_DIR)all.obj          : $(BASE_ALL_SRCS)all.c                  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)allacl.obj       : $(BASE_ALL_SRCS)allacl.c               .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)arcblk.obj       : $(BASE_ALL_SRCS)arcblk/arcblk.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
BASE_ARCHIVE_SRCS                 = $(BASE_ALL_SRCS)archives/#################
$(BASE_OBJ32_DIR)arcace.obj       : $(BASE_ARCHIVE_SRCS)ace/ace.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(BASE_OBJ32_DIR)arcread.obj      : $(BASE_ARCHIVE_SRCS)read/read.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(BASE_OBJ32_DIR)arctest.obj      : $(BASE_ARCHIVE_SRCS)test/test.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)arcinfo.obj      : $(BASE_ALL_SRCS)arcinfo/arcinfo.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)bitwidth.obj     : $(BASE_ALL_SRCS)bitwidth/bitwidth.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)bufread.obj      : $(BASE_ALL_SRCS)bufread/bufread.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)comments.obj     : $(BASE_ALL_SRCS)comments/comments.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
BASE_CONVERT_SRCS	          = $(BASE_ALL_SRCS)convert/##################

$(BASE_OBJ32_DIR)convert.obj      : $(BASE_CONVERT_SRCS)convert.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)connolin.obj     : $(BASE_CONVERT_SRCS)nolin.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)connont.obj      : $(BASE_CONVERT_SRCS)nont.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)connt.obj        : $(BASE_CONVERT_SRCS)nt.c               .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

##############################################################################
BASE_CPRDCPR_SRCS	          = $(BASE_ALL_SRCS)cprdcpr/##################

$(BASE_OBJ32_DIR)cdhuff.obj       : $(BASE_CPRDCPR_SRCS)huff/huff.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)cdpic.obj        : $(BASE_CPRDCPR_SRCS)pic/pic.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)cdsound.obj      : $(BASE_CPRDCPR_SRCS)sound/sound.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
$(BASE_OBJ32_DIR)crc.obj          : $(BASE_ALL_SRCS)crc/crc.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(BASE_OBJ32_DIR)crcasm.obj       : $(BASE_ALL_SRCS)crc/asm/crc.asm        .AUTODEPEND
	$(COMPILE_A)


##############################################################################
$(BASE_OBJ32_DIR)crypt.obj        : $(BASE_ALL_SRCS)crypt/crypt.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
BASE_DCPR_SRCS	                  = $(BASE_ALL_SRCS)dcpr/#####################

$(BASE_OBJ32_DIR)dcpr.obj         : $(BASE_DCPR_SRCS)dcpr.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dcprcomm.obj     : $(BASE_DCPR_SRCS)comments/comments.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dcprhuff.obj     : $(BASE_DCPR_SRCS)huff/huff.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dcprlz77.obj     : $(BASE_DCPR_SRCS)lz77/lz77.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dcprpic.obj      : $(BASE_DCPR_SRCS)pic/pic.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dcprsnd.obj      : $(BASE_DCPR_SRCS)sound/sound.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)soundasm.obj     : $(BASE_DCPR_SRCS)sound/asm/sound.asm   .AUTODEPEND
	$(COMPILE_A)

$(BASE_OBJ32_DIR)picasm.obj       : $(BASE_DCPR_SRCS)pic/asm/pic.asm       .AUTODEPEND
	$(COMPILE_A)

$(BASE_OBJ32_DIR)lz77asm.obj      : $(BASE_DCPR_SRCS)lz77/asm/lz77.asm     .AUTODEPEND
	$(COMPILE_A)

##############################################################################
$(BASE_OBJ32_DIR)dirdata.obj      : $(BASE_ALL_SRCS)dirdata/dirdata.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
BASE_DOSFUNCS_SRCS                = $(BASE_ALL_SRCS)dosfuncs/#################

$(BASE_OBJ32_DIR)dosfuncs.obj     : $(BASE_DOSFUNCS_SRCS)dosfuncs.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dosfi64.obj      : $(BASE_DOSFUNCS_SRCS)i64.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dosfni64.obj     : $(BASE_DOSFUNCS_SRCS)noi64.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dfni64wt.obj     : $(BASE_DOSFUNCS_SRCS)noi64wat.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dosfnocw.obj     : $(BASE_DOSFUNCS_SRCS)nocw.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dosfnont.obj     : $(BASE_DOSFUNCS_SRCS)nont.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dosfnt.obj       : $(BASE_DOSFUNCS_SRCS)nt.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(BASE_OBJ32_DIR)dfnocwnt.obj     : $(BASE_DOSFUNCS_SRCS)nocwnt.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)dfnolin.obj      : $(BASE_DOSFUNCS_SRCS)nolin.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)error.obj        : $(BASE_ALL_SRCS)error/error.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)errorout.obj     : $(BASE_ALL_SRCS)errorout/errorout.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)extract.obj      : $(BASE_ALL_SRCS)extract/extract.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)filelist.obj     : $(BASE_ALL_SRCS)filelist/filelist.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)funcs.obj        : $(BASE_ALL_SRCS)funcs/funcs.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
BASE_LFN_SRCS                     = $(BASE_ALL_SRCS)lfn/######################

$(BASE_OBJ32_DIR)lfn.obj          : $(BASE_LFN_SRCS)lfn.c                  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)lfndos.obj       : $(BASE_LFN_SRCS)dos32.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)lfndosas.obj     : $(BASE_LFN_SRCS)dos32.asm              .AUTODEPEND
	$(COMPILE_A)

$(BASE_OBJ32_DIR)lfnnt.obj        : $(BASE_LFN_SRCS)nt.c                   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(BASE_OBJ32_DIR)lfnntdos.obj     : $(BASE_LFN_SRCS)nont.c                 .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)lfnntos2.obj     : $(BASE_LFN_SRCS)nont.c                 .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)

$(BASE_OBJ32_DIR)lfnnodos.obj     : $(BASE_LFN_SRCS)nodos32.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)lfnos2.obj       : $(BASE_LFN_SRCS)os2.c                  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)


##############################################################################
BASE_MEMORY_SRCS                  = $(BASE_ALL_SRCS)memory/###################

$(BASE_OBJ32_DIR)memory.obj       : $(BASE_MEMORY_SRCS)memory.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)memdos.obj       : $(BASE_MEMORY_SRCS)dos32.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)memdosas.obj     : $(BASE_MEMORY_SRCS)dos32.asm           .AUTODEPEND
	$(COMPILE_A)

$(BASE_OBJ32_DIR)memndos.obj      : $(BASE_MEMORY_SRCS)nodos32.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(BASE_OBJ32_DIR)memnt.obj        : $(BASE_MEMORY_SRCS)nt.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(BASE_OBJ32_DIR)memos2.obj       : $(BASE_MEMORY_SRCS)os2.c               .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)

$(BASE_OBJ32_DIR)memnocw.obj      : $(BASE_MEMORY_SRCS)wat.c               .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)msgout.obj       : $(BASE_ALL_SRCS)msgout/msgout.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)options.obj      : $(BASE_ALL_SRCS)options/options.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)pathfunc.obj     : $(BASE_ALL_SRCS)pathfunc/pathfunc.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)qsort.obj        : $(BASE_ALL_SRCS)qsort/qsort.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)qsortasm.obj     : $(BASE_ALL_SRCS)qsort/asm/qsort.asm    .AUTODEPEND
	$(COMPILE_A)

##############################################################################
$(BASE_OBJ32_DIR)state.obj        : $(BASE_ALL_SRCS)state/state.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)sysdos32.obj     : $(BASE_ALL_SRCS)system/dos32.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(BASE_OBJ32_DIR)sysd32as.obj     : $(BASE_ALL_SRCS)system/dos32.asm       .AUTODEPEND
	$(COMPILE_A)

##############################################################################
$(BASE_OBJ32_DIR)uninorm.obj       : $(BASE_ALL_SRCS)uninorm/uninorm.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)unincore.obj       : $(BASE_ALL_SRCS)uninorm/unincore.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_OBJ32_DIR)volume.obj       : $(BASE_ALL_SRCS)volume/volume.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
BASE_ALL_CFILES =								\
  $(BASE_ALL_SRCS)all.c			$(BASE_ALL_SRCS)arcblk/arcblk.c         \
  $(BASE_ARCHIVE_SRCS)ace/ace.c         $(BASE_ARCHIVE_SRCS)read/read.c         \
  $(BASE_ARCHIVE_SRCS)test/test.c	$(BASE_ALL_SRCS)arcinfo/arcinfo.c       \
  $(BASE_ALL_SRCS)bitwidth/bitwidth.c	$(BASE_ALL_SRCS)bufread/bufread.c       \
  $(BASE_ALL_SRCS)comments/comments.c	$(BASE_CONVERT_SRCS)convert.c           \
  $(BASE_CONVERT_SRCS)lin.c		$(BASE_CONVERT_SRCS)nont.c              \
  $(BASE_CPRDCPR_SRCS)huff/huff.c         					\
  $(BASE_CPRDCPR_SRCS)pic/pic.c		$(BASE_CPRDCPR_SRCS)sound/sound.c       \
  $(BASE_ALL_SRCS)crc/crc.c							\
  $(BASE_ALL_SRCS)crypt/crypt.c		$(BASE_DCPR_SRCS)dcpr.c                 \
  $(BASE_DCPR_SRCS)comments/comments.c	$(BASE_DCPR_SRCS)huff/huff.c            \
  $(BASE_DCPR_SRCS)lz77/lz77.c		$(BASE_DCPR_SRCS)pic/pic.c              \
  $(BASE_DCPR_SRCS)sound/sound.c	$(BASE_ALL_SRCS)dirdata/dirdata.c       \
  $(BASE_DOSFUNCS_SRCS)noi64.c		$(BASE_DOSFUNCS_SRCS)dosfuncs.c         \
  $(BASE_DOSFUNCS_SRCS)noi64lin.c       					\
  $(BASE_DOSFUNCS_SRCS)lin.c							\
  $(BASE_ALL_SRCS)error/error.c		$(BASE_ALL_SRCS)errorout/errorout.c     \
  $(BASE_ALL_SRCS)extract/extract.c	$(BASE_ALL_SRCS)filelist/filelist.c     \
  $(BASE_ALL_SRCS)funcs/funcs.c		$(BASE_LFN_SRCS)lfn.c                   \
  $(BASE_LFN_SRCS)lin.c								\
  $(BASE_LFN_SRCS)nont.c		$(BASE_LFN_SRCS)nodos32.c               \
  $(BASE_MEMORY_SRCS)memory.c							\
  $(BASE_MEMORY_SRCS)nodos32.c            					\
  $(BASE_MEMORY_SRCS)nowat.c							\
  $(BASE_ALL_SRCS)msgout/msgout.c         					\
  $(BASE_ALL_SRCS)options/options.c	$(BASE_ALL_SRCS)pathfunc/pathfunc.c     \
  $(BASE_ALL_SRCS)qsort/qsort.c		$(BASE_ALL_SRCS)state/state.c           \
  $(BASE_ALL_SRCS)uninorm/uninorm.c     $(BASE_ALL_SRCS)uninorm/unincore.c  \
  $(BASE_ALL_SRCS)volume/volume.c

BASE_ALL_NT_CFILES =								\
  $(BASE_ALL_CFILES)                                                            \
  $(BASE_MEMORY_SRCS)nowatnt.c

BASE_ALL_LIN_CFILES =								\
  $(BASE_ALL_CFILES)                                                            \
  $(BASE_MEMORY_SRCS)lin.c

##############################################################################
##############################################################################
BASE_DCPR_OBJS                    =                                       \
  $(BASE_OBJ32_DIR)dcpr.obj            $(BASE_OBJ32_DIR)dcprcomm.obj      \
  $(BASE_OBJ32_DIR)dcprhuff.obj        $(BASE_OBJ32_DIR)dcprpic.obj       \
  $(BASE_OBJ32_DIR)dcprlz77.obj        $(BASE_OBJ32_DIR)dcprsnd.obj       \
  $(BASE_OBJ32_DIR)lz77asm.obj         $(BASE_OBJ32_DIR)picasm.obj        \
  $(BASE_OBJ32_DIR)soundasm.obj

BASE_ALL_OBJS_NO_ALL_OBJ          =                                       \
  $(BASE_DCPR_OBJS)                                                       \
  $(BASE_OBJ32_DIR)arcace.obj          $(BASE_OBJ32_DIR)arcread.obj       \
  $(BASE_OBJ32_DIR)arcblk.obj          $(BASE_OBJ32_DIR)arctest.obj       \
  $(BASE_OBJ32_DIR)arcinfo.obj         $(BASE_OBJ32_DIR)bitwidth.obj      \
  $(BASE_OBJ32_DIR)bufread.obj         $(BASE_OBJ32_DIR)comments.obj      \
  $(BASE_OBJ32_DIR)convert.obj         $(BASE_OBJ32_DIR)connolin.obj      \
  $(BASE_OBJ32_DIR)cdhuff.obj                                             \
  $(BASE_OBJ32_DIR)cdpic.obj           $(BASE_OBJ32_DIR)cdsound.obj       \
  $(BASE_OBJ32_DIR)crc.obj             $(BASE_OBJ32_DIR)crcasm.obj        \
  $(BASE_OBJ32_DIR)crypt.obj           $(BASE_OBJ32_DIR)dirdata.obj       \
  $(BASE_OBJ32_DIR)dosfuncs.obj        $(BASE_OBJ32_DIR)dosfnocw.obj      \
  $(BASE_OBJ32_DIR)dfnolin.obj						  \
  $(BASE_OBJ32_DIR)error.obj           $(BASE_OBJ32_DIR)errorout.obj      \
  $(BASE_OBJ32_DIR)extract.obj         $(BASE_OBJ32_DIR)filelist.obj      \
  $(BASE_OBJ32_DIR)funcs.obj           $(BASE_OBJ32_DIR)lfn.obj           \
  $(BASE_OBJ32_DIR)memory.obj          $(BASE_OBJ32_DIR)memnocw.obj       \
  $(BASE_OBJ32_DIR)msgout.obj          $(BASE_OBJ32_DIR)options.obj       \
  $(BASE_OBJ32_DIR)pathfunc.obj        $(BASE_OBJ32_DIR)qsort.obj         \
  $(BASE_OBJ32_DIR)qsortasm.obj                                           \
  $(BASE_OBJ32_DIR)state.obj           $(BASE_OBJ32_DIR)volume.obj

BASE_ALL_OBJS                     =                                       \
  $(BASE_ALL_OBJS_NO_ALL_OBJ)          $(BASE_OBJ32_DIR)all.obj

BASE_ALLACL_OBJS                     =                                    \
  $(BASE_ALL_OBJS_NO_ALL_OBJ)          $(BASE_OBJ32_DIR)allacl.obj

##############################################################################
BASE_DOS_OBJS                     =                                       \
  $(BASE_OBJ32_DIR)connont.obj                                            \
  $(BASE_OBJ32_DIR)dosfni64.obj        $(BASE_OBJ32_DIR)dfni64wt.obj      \
  $(BASE_OBJ32_DIR)dfnocwnt.obj	       $(BASE_OBJ32_DIR)lfndosas.obj      \
  $(BASE_OBJ32_DIR)lfndos.obj          $(BASE_OBJ32_DIR)lfnntdos.obj      \
  $(BASE_OBJ32_DIR)memdos.obj          $(BASE_OBJ32_DIR)memdosas.obj      \
  $(BASE_OBJ32_DIR)sysdos32.obj        $(BASE_OBJ32_DIR)sysd32as.obj	  \
  $(BASE_OBJ32_DIR)dosfnont.obj

BASE_NT_OBJS                      =                                       \
  $(BASE_OBJ32_DIR)connt.obj                                              \
  $(BASE_OBJ32_DIR)lfnnodos.obj        $(BASE_OBJ32_DIR)lfnnt.obj         \
  $(BASE_OBJ32_DIR)memndos.obj         $(BASE_OBJ32_DIR)memnt.obj         \
  $(BASE_OBJ32_DIR)dosfi64.obj	       $(BASE_OBJ32_DIR)dosfnt.obj


BASE_OS2_OBJS                     =                                       \
  $(BASE_OBJ32_DIR)connont.obj         $(BASE_OBJ32_DIR)dosfni64.obj      \
  $(BASE_OBJ32_DIR)dfni64wt.obj        $(BASE_OBJ32_DIR)dfnocwnt.obj      \
  $(BASE_OBJ32_DIR)lfnnodos.obj        $(BASE_OBJ32_DIR)lfnos2.obj        \
  $(BASE_OBJ32_DIR)lfnntos2.obj        $(BASE_OBJ32_DIR)memndos.obj       \
  $(BASE_OBJ32_DIR)memos2.obj	       $(BASE_OBJ32_DIR)dosfnont.obj

##############################################################################

ifndef ISWMAKE
include $(MAKE_DIR)baseace.mk
include $(MAKE_DIR)baseuace.mk
else
!include $(MAKE_DIR)baseace.mk
!include $(MAKE_DIR)baseuace.mk
endif
