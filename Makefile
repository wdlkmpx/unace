CPPFLAGS   += -Isource
#DEFINES	= -D__EMULATE_UNALIGNED__

BASE_ALL_CFILES =                      \
	source/base/arcblk/arcblk.c      \
	source/base/archives/ace/ace.c   \
	source/base/archives/read/read.c \
	source/base/archives/test/test.c \
	source/base/arcinfo/arcinfo.c    \
	source/base/bitwidth/bitwidth.c  \
	source/base/bufread/bufread.c    \
	source/base/comments/comments.c  \
	source/base/convert/convert.c    \
	source/base/convert/lin.c        \
	source/base/convert/nont.c       \
	source/base/cprdcpr/huff/huff.c  \
	source/base/cprdcpr/pic/pic.c    \
	source/base/cprdcpr/sound/sound.c     \
	source/base/crc/crc.c                 \
	source/base/crypt/crypt.c             \
	source/base/dcpr/dcpr.c               \
	source/base/dcpr/comments/comments.c  \
	source/base/dcpr/huff/huff.c          \
	source/base/dcpr/lz77/lz77.c          \
	source/base/dcpr/pic/pic.c            \
	source/base/dcpr/sound/sound.c        \
	source/base/dirdata/dirdata.c         \
	source/base/dosfuncs/noi64.c          \
	source/base/dosfuncs/dosfuncs.c       \
	source/base/dosfuncs/noi64lin.c       \
	source/base/dosfuncs/lin.c            \
	source/base/error/error.c             \
	source/base/errorout/errorout.c       \
	source/base/extract/extract.c         \
	source/base/filelist/filelist.c       \
	source/base/funcs/funcs.c             \
	source/base/lfn/lfn.c                 \
	source/base/memory/memory.c           \
	source/base/msgout/msgout.c           \
	source/base/options/options.c         \
	source/base/pathfunc/pathfunc.c       \
	source/base/qsort/qsort.c             \
	source/base/state/state.c             \
	source/base/uninorm/uninorm.c         \
	source/base/uninorm/unincore.c        \
	source/base/volume/volume.c

APPS_CFILES =                 \
	source/convert/convert.c   \
	source/input/input.c       \
	source/input/lin.c         \
	source/messages/msgfiles/eng.c \
	source/messages/messages.c \
	source/outpterr/outpterr.c \
	source/output/output.c     \
	source/state/state.c       \
	source/acefuncs.c          \
	source/commline.c          \
	source/main.c               \
	source/lin.c

UNACE_CFILES = $(BASE_ALL_CFILES) $(APPS_CFILES)

##############################################################################

all: unace

clean:
	rm -f unace
	
unace: $(UNACE_CFILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(UNACE_CFILES) -o unace
