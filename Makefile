CPPFLAGS   += -Isource
DEFINES		= -D__LINUX__ -D__unix__ -D__GCC__ -U__HAS_IO_H__
#DEFINES	= -D__MACOSX__ -D__unix__ -D__GCC__
#DEFINES	= -D__unix__ -D__GCC__ -D__BIG_ENDIAN__ -D__EMULATE_UNALIGNED__

BASE_ALL_CFILES =                      \
	source/base/all/all.c                \
	source/base/all/arcblk/arcblk.c      \
	source/base/all/archives/ace/ace.c   \
	source/base/all/archives/read/read.c \
	source/base/all/archives/test/test.c \
	source/base/all/arcinfo/arcinfo.c    \
	source/base/all/bitwidth/bitwidth.c  \
	source/base/all/bufread/bufread.c    \
	source/base/all/comments/comments.c  \
	source/base/all/convert/convert.c    \
	source/base/all/convert/lin.c        \
	source/base/all/convert/nont.c       \
	source/base/all/cprdcpr/huff/huff.c  \
	source/base/all/cprdcpr/pic/pic.c    \
	source/base/all/cprdcpr/sound/sound.c     \
	source/base/all/crc/crc.c                 \
	source/base/all/crypt/crypt.c             \
	source/base/all/dcpr/dcpr.c               \
	source/base/all/dcpr/comments/comments.c  \
	source/base/all/dcpr/huff/huff.c          \
	source/base/all/dcpr/lz77/lz77.c          \
	source/base/all/dcpr/pic/pic.c            \
	source/base/all/dcpr/sound/sound.c        \
	source/base/all/dirdata/dirdata.c         \
	source/base/all/dosfuncs/noi64.c          \
	source/base/all/dosfuncs/dosfuncs.c       \
	source/base/all/dosfuncs/noi64lin.c       \
	source/base/all/dosfuncs/lin.c            \
	source/base/all/error/error.c             \
	source/base/all/errorout/errorout.c       \
	source/base/all/extract/extract.c         \
	source/base/all/filelist/filelist.c       \
	source/base/all/funcs/funcs.c             \
	source/base/all/lfn/lfn.c                 \
	source/base/all/lfn/lin.c	                \
	source/base/all/lfn/nont.c                \
	source/base/all/lfn/nodos32.c             \
	source/base/all/memory/memory.c           \
	source/base/all/memory/nodos32.c          \
	source/base/all/memory/nowat.c            \
	source/base/all/msgout/msgout.c           \
	source/base/all/options/options.c         \
	source/base/all/pathfunc/pathfunc.c       \
	source/base/all/qsort/qsort.c             \
	source/base/all/state/state.c             \
	source/base/all/uninorm/uninorm.c         \
	source/base/all/uninorm/unincore.c        \
	source/base/all/volume/volume.c           \
	source/base/all/memory/lin.c
	# source/base/all/memory/nowatnt.c

APPS_CFILES =                 \
	source/apps/acefuncs/acefuncs.c \
	source/apps/convert/convert.c   \
	source/apps/input/input.c       \
	source/apps/input/lin.c         \
	source/apps/messages/msgfiles/eng.c \
	source/apps/messages/messages.c \
	source/apps/outpterr/outpterr.c \
	source/apps/output/output.c     \
	source/apps/state/state.c       \
	source/apps/commline.c          \
	source/apps/exe.c               \
	source/apps/lin.c

UNACE_CFILES = $(BASE_ALL_CFILES) $(APPS_CFILES)

##############################################################################

all: unace

clean:
	rm -f unace
	
unace: $(UNACE_CFILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(DEFINES) $(UNACE_CFILES) -ounace
