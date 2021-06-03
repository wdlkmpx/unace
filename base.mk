BASE_SRCS                         = $(SRCS)base/
BASE_ALL_SRCS                     = $(BASE_SRCS)all/
BASE_OBJ_DIR                      = $(OBJ_DIR)base/

##############################################################################
all.obj          : $(BASE_ALL_SRCS)all.c                  .AUTODEPEND

##############################################################################
allacl.obj       : $(BASE_ALL_SRCS)allacl.c               .AUTODEPEND

##############################################################################
arcblk.obj       : $(BASE_ALL_SRCS)arcblk/arcblk.c        .AUTODEPEND

##############################################################################
BASE_ARCHIVE_SRCS                 = $(BASE_ALL_SRCS)archives/#################
arcace.obj       : $(BASE_ARCHIVE_SRCS)ace/ace.c          .AUTODEPEND
arcread.obj      : $(BASE_ARCHIVE_SRCS)read/read.c        .AUTODEPEND
arctest.obj      : $(BASE_ARCHIVE_SRCS)test/test.c        .AUTODEPEND

##############################################################################
arcinfo.obj      : $(BASE_ALL_SRCS)arcinfo/arcinfo.c      .AUTODEPEND

##############################################################################
bitwidth.obj     : $(BASE_ALL_SRCS)bitwidth/bitwidth.c    .AUTODEPEND

##############################################################################
bufread.obj      : $(BASE_ALL_SRCS)bufread/bufread.c      .AUTODEPEND

##############################################################################
comments.obj     : $(BASE_ALL_SRCS)comments/comments.c    .AUTODEPEND

##############################################################################
BASE_CONVERT_SRCS	          = $(BASE_ALL_SRCS)convert/##################

convert.obj      : $(BASE_CONVERT_SRCS)convert.c          .AUTODEPEND

connolin.obj     : $(BASE_CONVERT_SRCS)nolin.c            .AUTODEPEND

connont.obj      : $(BASE_CONVERT_SRCS)nont.c             .AUTODEPEND

connt.obj        : $(BASE_CONVERT_SRCS)nt.c               .AUTODEPEND
	$(CC_WIN32)

##############################################################################
BASE_CPRDCPR_SRCS	          = $(BASE_ALL_SRCS)cprdcpr/##################

cdhuff.obj       : $(BASE_CPRDCPR_SRCS)huff/huff.c        .AUTODEPEND

cdpic.obj        : $(BASE_CPRDCPR_SRCS)pic/pic.c          .AUTODEPEND

cdsound.obj      : $(BASE_CPRDCPR_SRCS)sound/sound.c      .AUTODEPEND


##############################################################################
crc.obj          : $(BASE_ALL_SRCS)crc/crc.c              .AUTODEPEND
crcasm.obj       : $(BASE_ALL_SRCS)crc/asm/crc.asm        .AUTODEPEND
	$(COMPILE_A)


##############################################################################
crypt.obj        : $(BASE_ALL_SRCS)crypt/crypt.c          .AUTODEPEND

##############################################################################
BASE_DCPR_SRCS	                  = $(BASE_ALL_SRCS)dcpr/#####################

dcpr.obj         : $(BASE_DCPR_SRCS)dcpr.c                .AUTODEPEND

dcprcomm.obj     : $(BASE_DCPR_SRCS)comments/comments.c   .AUTODEPEND

dcprhuff.obj     : $(BASE_DCPR_SRCS)huff/huff.c           .AUTODEPEND

dcprlz77.obj     : $(BASE_DCPR_SRCS)lz77/lz77.c           .AUTODEPEND

dcprpic.obj      : $(BASE_DCPR_SRCS)pic/pic.c             .AUTODEPEND

dcprsnd.obj      : $(BASE_DCPR_SRCS)sound/sound.c         .AUTODEPEND

soundasm.obj     : $(BASE_DCPR_SRCS)sound/asm/sound.asm   .AUTODEPEND
	$(COMPILE_A)

picasm.obj       : $(BASE_DCPR_SRCS)pic/asm/pic.asm       .AUTODEPEND
	$(COMPILE_A)

lz77asm.obj      : $(BASE_DCPR_SRCS)lz77/asm/lz77.asm     .AUTODEPEND
	$(COMPILE_A)

##############################################################################
dirdata.obj      : $(BASE_ALL_SRCS)dirdata/dirdata.c      .AUTODEPEND

##############################################################################
BASE_DOSFUNCS_SRCS                = $(BASE_ALL_SRCS)dosfuncs/#################

dosfuncs.obj     : $(BASE_DOSFUNCS_SRCS)dosfuncs.c        .AUTODEPEND

dosfi64.obj      : $(BASE_DOSFUNCS_SRCS)i64.c             .AUTODEPEND

dosfni64.obj     : $(BASE_DOSFUNCS_SRCS)noi64.c           .AUTODEPEND

dfni64wt.obj     : $(BASE_DOSFUNCS_SRCS)noi64wat.c        .AUTODEPEND

dosfnocw.obj     : $(BASE_DOSFUNCS_SRCS)nocw.c            .AUTODEPEND

dosfnont.obj     : $(BASE_DOSFUNCS_SRCS)nont.c            .AUTODEPEND

dosfnt.obj       : $(BASE_DOSFUNCS_SRCS)nt.c              .AUTODEPEND
	$(CC_WIN32)

dfnocwnt.obj     : $(BASE_DOSFUNCS_SRCS)nocwnt.c          .AUTODEPEND

dfnolin.obj      : $(BASE_DOSFUNCS_SRCS)nolin.c           .AUTODEPEND

##############################################################################
error.obj        : $(BASE_ALL_SRCS)error/error.c          .AUTODEPEND

##############################################################################
errorout.obj     : $(BASE_ALL_SRCS)errorout/errorout.c    .AUTODEPEND

##############################################################################
extract.obj      : $(BASE_ALL_SRCS)extract/extract.c      .AUTODEPEND

##############################################################################
filelist.obj     : $(BASE_ALL_SRCS)filelist/filelist.c    .AUTODEPEND

##############################################################################
funcs.obj        : $(BASE_ALL_SRCS)funcs/funcs.c          .AUTODEPEND

##############################################################################
BASE_LFN_SRCS                     = $(BASE_ALL_SRCS)lfn/######################

lfn.obj          : $(BASE_LFN_SRCS)lfn.c                  .AUTODEPEND

lfndos.obj       : $(BASE_LFN_SRCS)dos32.c                .AUTODEPEND

lfndosas.obj     : $(BASE_LFN_SRCS)dos32.asm              .AUTODEPEND
	$(COMPILE_A)

lfnnt.obj        : $(BASE_LFN_SRCS)nt.c                   .AUTODEPEND
	$(CC_WIN32)

lfnntdos.obj     : $(BASE_LFN_SRCS)nont.c                 .AUTODEPEND

lfnntos2.obj     : $(BASE_LFN_SRCS)nont.c                 .AUTODEPEND
	$(CC_OS2)

lfnnodos.obj     : $(BASE_LFN_SRCS)nodos32.c              .AUTODEPEND

lfnos2.obj       : $(BASE_LFN_SRCS)os2.c                  .AUTODEPEND
	$(CC_OS2)


##############################################################################
BASE_MEMORY_SRCS                  = $(BASE_ALL_SRCS)memory/###################

memory.obj       : $(BASE_MEMORY_SRCS)memory.c            .AUTODEPEND

memdos.obj       : $(BASE_MEMORY_SRCS)dos32.c             .AUTODEPEND

memdosas.obj     : $(BASE_MEMORY_SRCS)dos32.asm           .AUTODEPEND
	$(COMPILE_A)

memndos.obj      : $(BASE_MEMORY_SRCS)nodos32.c           .AUTODEPEND
	$(CC_WIN32)

memnt.obj        : $(BASE_MEMORY_SRCS)nt.c                .AUTODEPEND
	$(CC_WIN32)

memos2.obj       : $(BASE_MEMORY_SRCS)os2.c               .AUTODEPEND
	$(CC_OS2)

memnocw.obj      : $(BASE_MEMORY_SRCS)wat.c               .AUTODEPEND

##############################################################################
msgout.obj       : $(BASE_ALL_SRCS)msgout/msgout.c        .AUTODEPEND

##############################################################################
options.obj      : $(BASE_ALL_SRCS)options/options.c      .AUTODEPEND

##############################################################################
pathfunc.obj     : $(BASE_ALL_SRCS)pathfunc/pathfunc.c    .AUTODEPEND

##############################################################################
qsort.obj        : $(BASE_ALL_SRCS)qsort/qsort.c          .AUTODEPEND

qsortasm.obj     : $(BASE_ALL_SRCS)qsort/asm/qsort.asm    .AUTODEPEND
	$(COMPILE_A)

##############################################################################
state.obj        : $(BASE_ALL_SRCS)state/state.c          .AUTODEPEND

##############################################################################
sysdos32.obj     : $(BASE_ALL_SRCS)system/dos32.c         .AUTODEPEND

sysd32as.obj     : $(BASE_ALL_SRCS)system/dos32.asm       .AUTODEPEND
	$(COMPILE_A)

##############################################################################
uninorm.obj       : $(BASE_ALL_SRCS)uninorm/uninorm.c     .AUTODEPEND

##############################################################################
unincore.obj       : $(BASE_ALL_SRCS)uninorm/unincore.c   .AUTODEPEND

##############################################################################
volume.obj       : $(BASE_ALL_SRCS)volume/volume.c        .AUTODEPEND


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
  dcpr.obj            dcprcomm.obj      \
  dcprhuff.obj        dcprpic.obj       \
  dcprlz77.obj        dcprsnd.obj       \
  lz77asm.obj         picasm.obj        \
  soundasm.obj

BASE_ALL_OBJS_NO_ALL_OBJ          =                                       \
  $(BASE_DCPR_OBJS)                                                       \
  arcace.obj          arcread.obj       \
  arcblk.obj          arctest.obj       \
  arcinfo.obj         bitwidth.obj      \
  bufread.obj         comments.obj      \
  convert.obj         connolin.obj      \
  cdhuff.obj                                             \
  cdpic.obj           cdsound.obj       \
  crc.obj             crcasm.obj        \
  crypt.obj           dirdata.obj       \
  dosfuncs.obj        dosfnocw.obj      \
  dfnolin.obj						  \
  error.obj           errorout.obj      \
  extract.obj         filelist.obj      \
  funcs.obj           lfn.obj           \
  memory.obj          memnocw.obj       \
  msgout.obj          options.obj       \
  pathfunc.obj        qsort.obj         \
  qsortasm.obj                                           \
  state.obj           volume.obj

BASE_ALL_OBJS                     =                                       \
  $(BASE_ALL_OBJS_NO_ALL_OBJ)          all.obj

BASE_ALLACL_OBJS                     =                                    \
  $(BASE_ALL_OBJS_NO_ALL_OBJ)          allacl.obj

##############################################################################
BASE_DOS_OBJS                     =                                       \
  connont.obj                                            \
  dosfni64.obj        dfni64wt.obj      \
  dfnocwnt.obj	       lfndosas.obj      \
  lfndos.obj          lfnntdos.obj      \
  memdos.obj          memdosas.obj      \
  sysdos32.obj        sysd32as.obj	  \
  dosfnont.obj

BASE_NT_OBJS                      =                                       \
  connt.obj                                              \
  lfnnodos.obj        lfnnt.obj         \
  memndos.obj         memnt.obj         \
  dosfi64.obj	       dosfnt.obj


BASE_OS2_OBJS                     =                                       \
  connont.obj         dosfni64.obj      \
  dfni64wt.obj        dfnocwnt.obj      \
  lfnnodos.obj        lfnos2.obj        \
  lfnntos2.obj        memndos.obj       \
  memos2.obj	       dosfnont.obj

##############################################################################

##### include $(MAKE_DIR)baseuace.mk

BASE_UNACE_SRCS	                      = $(BASE_SRCS)unace/
BASE_UNACE_OBJ_DIR                    = $(BASE_OBJ_DIR)unace/
BASE_UNACE_EXT_OBJ_DIR                = $(BASE_UNACE_OBJ_DIR)ext/

##############################################################################
BASE_UNACE_EXT_SRCS                   = $(BASE_UNACE_SRCS)extern/#############
$(BASE_UNACE_EXT_OBJ_DIR)arcace.obj   : $(BASE_UNACE_EXT_SRCS)arcace/arcace.c     .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)arcblk.obj   : $(BASE_UNACE_EXT_SRCS)arcblk/arcblk.c     .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)arcinfo.obj  : $(BASE_UNACE_EXT_SRCS)arcinfo/arcinfo.c   .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)dcpr.obj     : $(BASE_UNACE_EXT_SRCS)dcpr/dcpr.c         .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)extract.obj  : $(BASE_UNACE_EXT_SRCS)extract/extract.c   .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)filelist.obj : $(BASE_UNACE_EXT_SRCS)filelist/filelist.c .AUTODEPEND
$(BASE_UNACE_EXT_OBJ_DIR)memory.obj   : $(BASE_UNACE_EXT_SRCS)memory/memory.c     .AUTODEPEND
##############################################################################

BASE_UNACE_CFILES =									  \
  $(BASE_UNACE_EXT_SRCS)arcace/arcace.c		$(BASE_UNACE_EXT_SRCS)arcblk/arcblk.c     \
  $(BASE_UNACE_EXT_SRCS)arcinfo/arcinfo.c	$(BASE_UNACE_EXT_SRCS)dcpr/dcpr.c         \
  $(BASE_UNACE_EXT_SRCS)extract/extract.c	$(BASE_UNACE_EXT_SRCS)filelist/filelist.c \
  $(BASE_UNACE_EXT_SRCS)memory/memory.c

##############################################################################
BASE_UNACE_EXT_OBJS                   =                                       \
  $(BASE_UNACE_EXT_OBJ_DIR)arcace.obj   $(BASE_UNACE_EXT_OBJ_DIR)arcblk.obj   \
  $(BASE_UNACE_EXT_OBJ_DIR)arcinfo.obj                                        \
  $(BASE_UNACE_EXT_OBJ_DIR)dcpr.obj     $(BASE_UNACE_EXT_OBJ_DIR)extract.obj  \
  $(BASE_UNACE_EXT_OBJ_DIR)filelist.obj $(BASE_UNACE_EXT_OBJ_DIR)memory.obj

BASE_UNACE_OBJS                       =                                       \
  $(BASE_UNACE_EXT_OBJS)
##############################################################################
