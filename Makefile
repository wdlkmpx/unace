CPPFLAGS   += -Isrc
#DEFINES	= -D__EMULATE_UNALIGNED__

BASE_ALL_CFILES =                      \
	src/base/all.c      \
	src/base/arcblk/arcblk.c      \
	src/base/archives/ace/ace.c   \
	src/base/archives/read/read.c \
	src/base/archives/test/test.c \
	src/base/arcinfo/arcinfo.c    \
	src/base/bitwidth/bitwidth.c  \
	src/base/bufread/bufread.c    \
	src/base/comments/comments.c  \
	src/base/convert/convert.c    \
	src/base/cprdcpr/huff/huff.c  \
	src/base/cprdcpr/pic/pic.c    \
	src/base/cprdcpr/sound/sound.c     \
	src/base/crc/crc.c                 \
	src/base/crypt/crypt.c             \
	src/base/dcpr/dcpr.c               \
	src/base/dcpr/comments/comments.c  \
	src/base/dcpr/huff/huff.c          \
	src/base/dcpr/lz77/lz77.c          \
	src/base/dcpr/pic/pic.c            \
	src/base/dcpr/sound/sound.c        \
	src/base/dirdata/dirdata.c         \
	src/base/dosfuncs/dosfuncs.c       \
	src/base/error/error.c             \
	src/base/errorout/errorout.c       \
	src/base/extract/extract.c         \
	src/base/filelist/filelist.c       \
	src/base/funcs/funcs.c             \
	src/base/lfn/lfn.c                 \
	src/base/memory/memory.c           \
	src/base/msgout/msgout.c           \
	src/base/options/options.c         \
	src/base/pathfunc/pathfunc.c       \
	src/base/qsort/qsort.c             \
	src/base/state/state.c             \
	src/base/uninorm/uninorm.c         \
	src/base/uninorm/unincore.c        \
	src/base/volume/volume.c

APPS_CFILES =                 \
	src/convert/convert.c   \
	src/input/input.c       \
	src/messages/msgfiles/eng.c \
	src/messages/messages.c \
	src/outpterr/outpterr.c \
	src/output/output.c     \
	src/state/state.c       \
	src/acefuncs.c          \
	src/commline.c          \
	src/main.c               \
	src/lin.c

UNACE_CFILES = $(BASE_ALL_CFILES) $(APPS_CFILES)

##############################################################################

all: unace

clean:
	rm -f unace
	
unace: $(UNACE_CFILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(UNACE_CFILES) -o unace
