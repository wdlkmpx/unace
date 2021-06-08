BASE_SRCS                         = $(SRCS)base/
BASE_ALL_SRCS                     = $(BASE_SRCS)all/
BASE_OBJ_DIR                      = $(OBJ_DIR)base/

##############################################################################
all.obj          : $(BASE_ALL_SRCS)all.c

arcblk.obj       : $(BASE_ALL_SRCS)arcblk/arcblk.c

arcace.obj       : $(BASE_ALL_SRCS)archives/ace/ace.c
arcread.obj      : $(BASE_ALL_SRCS)archives/read/read.c

arcinfo.obj      : $(BASE_ALL_SRCS)arcinfo/arcinfo.c
bitwidth.obj     : $(BASE_ALL_SRCS)bitwidth/bitwidth.c
bufread.obj      : $(BASE_ALL_SRCS)bufread/bufread.c
comments.obj     : $(BASE_ALL_SRCS)comments/comments.c

convert.obj      : $(BASE_ALL_SRCS)convert/convert.c
connont.obj      : $(BASE_ALL_SRCS)convert/nont.c

cdhuff.obj       : $(BASE_ALL_SRCS)cprdcpr/huff/huff.c
cdpic.obj        : $(BASE_ALL_SRCS)cprdcpr/pic/pic.c
cdsound.obj      : $(BASE_ALL_SRCS)cprdcpr/sound/sound.c

crc.obj          : $(BASE_ALL_SRCS)crc/crc.c
crypt.obj        : $(BASE_ALL_SRCS)crypt/crypt.c

dcpr.obj         : $(BASE_ALL_SRCS)dcpr/dcpr.c
dcprcomm.obj     : $(BASE_ALL_SRCS)dcpr/comments/comments.c
dcprhuff.obj     : $(BASE_ALL_SRCS)dcpr/huff/huff.c
dcprlz77.obj     : $(BASE_ALL_SRCS)dcpr/lz77/lz77.c
dcprpic.obj      : $(BASE_ALL_SRCS)dcpr/pic/pic.c
dcprsnd.obj      : $(BASE_ALL_SRCS)dcpr/sound/sound.c

dirdata.obj      : $(BASE_ALL_SRCS)dirdata/dirdata.c

dosfuncs.obj     : $(BASE_ALL_SRCS)dosfuncs/dosfuncs.c
dosfni64.obj     : $(BASE_ALL_SRCS)dosfuncs/noi64.c
dosfnont.obj     : $(BASE_ALL_SRCS)dosfuncs/nont.c

error.obj        : $(BASE_ALL_SRCS)error/error.c
errorout.obj     : $(BASE_ALL_SRCS)errorout/errorout.c
extract.obj      : $(BASE_ALL_SRCS)extract/extract.c
filelist.obj     : $(BASE_ALL_SRCS)filelist/filelist.c
funcs.obj        : $(BASE_ALL_SRCS)funcs/funcs.c

lfn.obj          : $(BASE_ALL_SRCS)lfn/lfn.c
lfnntdos.obj     : $(BASE_ALL_SRCS)lfn/nont.c
lfnnodos.obj     : $(BASE_ALL_SRCS)lfn/nodos32.c

memory.obj       : $(BASE_ALL_SRCS)memory/memory.c
memndos.obj      : $(BASE_ALL_SRCS)memory/nodos32.c

msgout.obj       : $(BASE_ALL_SRCS)msgout/msgout.c
options.obj      : $(BASE_ALL_SRCS)options/options.c
pathfunc.obj     : $(BASE_ALL_SRCS)pathfunc/pathfunc.c
qsort.obj        : $(BASE_ALL_SRCS)qsort/qsort.c
state.obj        : $(BASE_ALL_SRCS)state/state.c
uninorm.obj      : $(BASE_ALL_SRCS)uninorm/uninorm.c
unincore.obj     : $(BASE_ALL_SRCS)uninorm/unincore.c
volume.obj       : $(BASE_ALL_SRCS)volume/volume.c
##############################################################################

BASE_ALL_CFILES =                      \
  $(BASE_ALL_SRCS)all.c                \
  $(BASE_ALL_SRCS)arcblk/arcblk.c      \
  $(BASE_ALL_SRCS)archives/ace/ace.c   \
  $(BASE_ALL_SRCS)archives/read/read.c \
  $(BASE_ALL_SRCS)archives/test/test.c \
  $(BASE_ALL_SRCS)arcinfo/arcinfo.c    \
  $(BASE_ALL_SRCS)bitwidth/bitwidth.c  \
  $(BASE_ALL_SRCS)bufread/bufread.c    \
  $(BASE_ALL_SRCS)comments/comments.c  \
  $(BASE_ALL_SRCS)convert/convert.c    \
  $(BASE_ALL_SRCS)convert/lin.c	       \
  $(BASE_ALL_SRCS)convert/nont.c       \
  $(BASE_ALL_SRCS)cprdcpr/huff/huff.c  \
  $(BASE_ALL_SRCS)cprdcpr/pic/pic.c    \
  $(BASE_ALL_SRCS)cprdcpr/sound/sound.c     \
  $(BASE_ALL_SRCS)crc/crc.c                 \
  $(BASE_ALL_SRCS)crypt/crypt.c             \
  $(BASE_ALL_SRCS)dcpr/dcpr.c               \
  $(BASE_ALL_SRCS)dcpr/comments/comments.c  \
  $(BASE_ALL_SRCS)dcpr/huff/huff.c          \
  $(BASE_ALL_SRCS)dcpr/lz77/lz77.c          \
  $(BASE_ALL_SRCS)dcpr/pic/pic.c            \
  $(BASE_ALL_SRCS)dcpr/sound/sound.c        \
  $(BASE_ALL_SRCS)dirdata/dirdata.c         \
  $(BASE_ALL_SRCS)dosfuncs/noi64.c          \
  $(BASE_ALL_SRCS)dosfuncs/dosfuncs.c       \
  $(BASE_ALL_SRCS)dosfuncs/noi64lin.c       \
  $(BASE_ALL_SRCS)dosfuncs/lin.c            \
  $(BASE_ALL_SRCS)error/error.c             \
  $(BASE_ALL_SRCS)errorout/errorout.c       \
  $(BASE_ALL_SRCS)extract/extract.c         \
  $(BASE_ALL_SRCS)filelist/filelist.c       \
  $(BASE_ALL_SRCS)funcs/funcs.c             \
  $(BASE_ALL_SRCS)lfn/lfn.c                 \
  $(BASE_ALL_SRCS)lfn/lin.c	                \
  $(BASE_ALL_SRCS)lfn/nont.c                \
  $(BASE_ALL_SRCS)lfn/nodos32.c             \
  $(BASE_ALL_SRCS)memory/memory.c           \
  $(BASE_ALL_SRCS)memory/nodos32.c          \
  $(BASE_ALL_SRCS)memory/nowat.c            \
  $(BASE_ALL_SRCS)msgout/msgout.c           \
  $(BASE_ALL_SRCS)options/options.c         \
  $(BASE_ALL_SRCS)pathfunc/pathfunc.c       \
  $(BASE_ALL_SRCS)qsort/qsort.c             \
  $(BASE_ALL_SRCS)state/state.c             \
  $(BASE_ALL_SRCS)uninorm/uninorm.c         \
  $(BASE_ALL_SRCS)uninorm/unincore.c        \
  $(BASE_ALL_SRCS)volume/volume.c

BASE_ALL_NT_CFILES = $(BASE_ALL_CFILES)   $(BASE_ALL_SRCS)memory/nowatnt.c
BASE_ALL_LIN_CFILES = $(BASE_ALL_CFILES)  $(BASE_ALL_SRCS)memory/lin.c

##############################################################################

BASE_DCPR_OBJS                    =                                       \
  dcpr.obj            dcprcomm.obj      \
  dcprhuff.obj        dcprpic.obj       \
  dcprlz77.obj        dcprsnd.obj       

BASE_ALL_OBJS_NO_ALL_OBJ          =                                       \
  $(BASE_DCPR_OBJS)                                                       \
  arcace.obj          arcread.obj       \
  arcblk.obj                 \
  arcinfo.obj         bitwidth.obj      \
  bufread.obj         comments.obj      \
  convert.obj         cdhuff.obj        \
  cdpic.obj           cdsound.obj       \
  crc.obj                     \
  crypt.obj           dirdata.obj       \
  dosfuncs.obj            \
  error.obj           errorout.obj      \
  extract.obj         filelist.obj      \
  funcs.obj           lfn.obj           \
  memory.obj                 \
  msgout.obj          options.obj       \
  pathfunc.obj        qsort.obj         \
  state.obj           volume.obj

BASE_ALL_OBJS = $(BASE_ALL_OBJS_NO_ALL_OBJ) all.obj

##############################################################################
BASE_DOS_OBJS = connont.obj dosfni64.obj lfndosas.obj  lfnntdos.obj dosfnont.obj
BASE_NT_OBJS  = lfnnodos.ob memndos.ob
BASE_OS2_OBJS = connont.obj dosfni64.obj lfnnodos.obj memndos.obj dosfnont.obj

