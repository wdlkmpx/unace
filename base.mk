BASE_SRCS                         = $(SRCS)base/
BASE_ALL_SRCS                     = $(BASE_SRCS)all/
BASE_OBJ_DIR                      = $(OBJ_DIR)base/

##############################################################################
all.obj          : $(BASE_ALL_SRCS)all.c

##############################################################################
allacl.obj       : $(BASE_ALL_SRCS)allacl.c

##############################################################################
arcblk.obj       : $(BASE_ALL_SRCS)arcblk/arcblk.c

##############################################################################
BASE_ARCHIVE_SRCS                 = $(BASE_ALL_SRCS)archives/#################
arcace.obj       : $(BASE_ARCHIVE_SRCS)ace/ace.c
arcread.obj      : $(BASE_ARCHIVE_SRCS)read/read.c
arctest.obj      : $(BASE_ARCHIVE_SRCS)test/test.c

##############################################################################
arcinfo.obj      : $(BASE_ALL_SRCS)arcinfo/arcinfo.c

##############################################################################
bitwidth.obj     : $(BASE_ALL_SRCS)bitwidth/bitwidth.c

##############################################################################
bufread.obj      : $(BASE_ALL_SRCS)bufread/bufread.c

##############################################################################
comments.obj     : $(BASE_ALL_SRCS)comments/comments.c

##############################################################################
BASE_CONVERT_SRCS	          = $(BASE_ALL_SRCS)convert/##################

convert.obj      : $(BASE_CONVERT_SRCS)convert.c

connolin.obj     : $(BASE_CONVERT_SRCS)nolin.c

connont.obj      : $(BASE_CONVERT_SRCS)nont.c

connt.obj        : $(BASE_CONVERT_SRCS)nt.c
	$(CC_WIN32)

##############################################################################
BASE_CPRDCPR_SRCS	          = $(BASE_ALL_SRCS)cprdcpr/##################

cdhuff.obj       : $(BASE_CPRDCPR_SRCS)huff/huff.c

cdpic.obj        : $(BASE_CPRDCPR_SRCS)pic/pic.c

cdsound.obj      : $(BASE_CPRDCPR_SRCS)sound/sound.c


##############################################################################
crc.obj          : $(BASE_ALL_SRCS)crc/crc.c
crcasm.obj       : $(BASE_ALL_SRCS)crc/asm/crc.asm
	$(COMPILE_A)


##############################################################################
crypt.obj        : $(BASE_ALL_SRCS)crypt/crypt.c

##############################################################################
BASE_DCPR_SRCS	                  = $(BASE_ALL_SRCS)dcpr/#####################

dcpr.obj         : $(BASE_DCPR_SRCS)dcpr.c

dcprcomm.obj     : $(BASE_DCPR_SRCS)comments/comments.c

dcprhuff.obj     : $(BASE_DCPR_SRCS)huff/huff.c

dcprlz77.obj     : $(BASE_DCPR_SRCS)lz77/lz77.c

dcprpic.obj      : $(BASE_DCPR_SRCS)pic/pic.c

dcprsnd.obj      : $(BASE_DCPR_SRCS)sound/sound.c

soundasm.obj     : $(BASE_DCPR_SRCS)sound/asm/sound.asm
	$(COMPILE_A)

picasm.obj       : $(BASE_DCPR_SRCS)pic/asm/pic.asm
	$(COMPILE_A)

lz77asm.obj      : $(BASE_DCPR_SRCS)lz77/asm/lz77.asm
	$(COMPILE_A)

##############################################################################
dirdata.obj      : $(BASE_ALL_SRCS)dirdata/dirdata.c

##############################################################################
BASE_DOSFUNCS_SRCS                = $(BASE_ALL_SRCS)dosfuncs/#################

dosfuncs.obj     : $(BASE_DOSFUNCS_SRCS)dosfuncs.c

dosfi64.obj      : $(BASE_DOSFUNCS_SRCS)i64.c

dosfni64.obj     : $(BASE_DOSFUNCS_SRCS)noi64.c

dfni64wt.obj     : $(BASE_DOSFUNCS_SRCS)noi64wat.c

dosfnocw.obj     : $(BASE_DOSFUNCS_SRCS)nocw.c

dosfnont.obj     : $(BASE_DOSFUNCS_SRCS)nont.c

dosfnt.obj       : $(BASE_DOSFUNCS_SRCS)nt.c
	$(CC_WIN32)

dfnocwnt.obj     : $(BASE_DOSFUNCS_SRCS)nocwnt.c

dfnolin.obj      : $(BASE_DOSFUNCS_SRCS)nolin.c

##############################################################################
error.obj        : $(BASE_ALL_SRCS)error/error.c

##############################################################################
errorout.obj     : $(BASE_ALL_SRCS)errorout/errorout.c

##############################################################################
extract.obj      : $(BASE_ALL_SRCS)extract/extract.c

##############################################################################
filelist.obj     : $(BASE_ALL_SRCS)filelist/filelist.c

##############################################################################
funcs.obj        : $(BASE_ALL_SRCS)funcs/funcs.c

##############################################################################
BASE_LFN_SRCS                     = $(BASE_ALL_SRCS)lfn/######################

lfn.obj          : $(BASE_LFN_SRCS)lfn.c

lfndos.obj       : $(BASE_LFN_SRCS)dos32.c

lfndosas.obj     : $(BASE_LFN_SRCS)dos32.asm
	$(COMPILE_A)

lfnnt.obj        : $(BASE_LFN_SRCS)nt.c
	$(CC_WIN32)

lfnntdos.obj     : $(BASE_LFN_SRCS)nont.c

lfnntos2.obj     : $(BASE_LFN_SRCS)nont.c
	$(CC_OS2)

lfnnodos.obj     : $(BASE_LFN_SRCS)nodos32.c

lfnos2.obj       : $(BASE_LFN_SRCS)os2.c
	$(CC_OS2)


##############################################################################
BASE_MEMORY_SRCS                  = $(BASE_ALL_SRCS)memory/###################

memory.obj       : $(BASE_MEMORY_SRCS)memory.c

memdos.obj       : $(BASE_MEMORY_SRCS)dos32.c

memdosas.obj     : $(BASE_MEMORY_SRCS)dos32.asm
	$(COMPILE_A)

memndos.obj      : $(BASE_MEMORY_SRCS)nodos32.c
	$(CC_WIN32)

memnt.obj        : $(BASE_MEMORY_SRCS)nt.c
	$(CC_WIN32)

memos2.obj       : $(BASE_MEMORY_SRCS)os2.c
	$(CC_OS2)

memnocw.obj      : $(BASE_MEMORY_SRCS)wat.c

##############################################################################
msgout.obj       : $(BASE_ALL_SRCS)msgout/msgout.c

##############################################################################
options.obj      : $(BASE_ALL_SRCS)options/options.c

##############################################################################
pathfunc.obj     : $(BASE_ALL_SRCS)pathfunc/pathfunc.c

##############################################################################
qsort.obj        : $(BASE_ALL_SRCS)qsort/qsort.c

qsortasm.obj     : $(BASE_ALL_SRCS)qsort/asm/qsort.asm
	$(COMPILE_A)

##############################################################################
state.obj        : $(BASE_ALL_SRCS)state/state.c

##############################################################################
sysdos32.obj     : $(BASE_ALL_SRCS)system/dos32.c

sysd32as.obj     : $(BASE_ALL_SRCS)system/dos32.asm
	$(COMPILE_A)

##############################################################################
uninorm.obj       : $(BASE_ALL_SRCS)uninorm/uninorm.c

##############################################################################
unincore.obj       : $(BASE_ALL_SRCS)uninorm/unincore.c

##############################################################################
volume.obj       : $(BASE_ALL_SRCS)volume/volume.c


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
$(BASE_UNACE_EXT_OBJ_DIR)arcace.obj   : $(BASE_UNACE_EXT_SRCS)arcace/arcace.c
$(BASE_UNACE_EXT_OBJ_DIR)arcblk.obj   : $(BASE_UNACE_EXT_SRCS)arcblk/arcblk.c
$(BASE_UNACE_EXT_OBJ_DIR)arcinfo.obj  : $(BASE_UNACE_EXT_SRCS)arcinfo/arcinfo.c
$(BASE_UNACE_EXT_OBJ_DIR)dcpr.obj     : $(BASE_UNACE_EXT_SRCS)dcpr/dcpr.c
$(BASE_UNACE_EXT_OBJ_DIR)extract.obj  : $(BASE_UNACE_EXT_SRCS)extract/extract.c
$(BASE_UNACE_EXT_OBJ_DIR)filelist.obj : $(BASE_UNACE_EXT_SRCS)filelist/filelist.c
$(BASE_UNACE_EXT_OBJ_DIR)memory.obj   : $(BASE_UNACE_EXT_SRCS)memory/memory.c
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
