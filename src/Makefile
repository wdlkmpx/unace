
include ../config.mk

APP  = unace
# find . -name '*.c' | sed 's%\.c%.o%'
OBJS = acefuncs.o \
	base/all.o \
	base/unused.o \
	base/arcblk/arcblk.o \
	base/archives/ace.o \
	base/archives/read.o \
	base/archives/test.o \
	base/bitwidth/bitwidth.o \
	base/bufread/bufread.o \
	base/comments/comments.o \
	base/convert/convert.o \
	base/cprdcpr/cprdcpr.o \
	base/crc/crc.o \
	base/crypt/crypt.o \
	base/dcpr/comments.o \
	base/dcpr/dcpr.o \
	base/dcpr/huff.o \
	base/dcpr/lz77.o \
	base/dcpr/pic.o \
	base/dcpr/sound.o \
	base/dosfuncs/dosfuncs.o \
	base/error/error.o \
	base/errorout/errorout.o \
	base/extract/extract.o \
	base/filelist/filelist.o \
	base/funcs/funcs.o \
	base/lfn/lfn.o \
	base/memory/memory.o \
	base/msgout/msgout.o \
	base/options/options.o \
	base/pathfunc/pathfunc.o \
	base/qsort/qsort.o \
	base/state/state.o \
	base/uninorm/unincore.o \
	base/uninorm/uninorm.o \
	base/volume/volume.o \
	commline.o \
	convert/convert.o \
	input/input.o \
	lin.o \
	main.o \
	messages/messages.o \
	messages/msgfiles/eng.o \
	outpterr/outpterr.o \
	output/output.o \
	state/state.o

# -D__EMULATE_UNALIGNED__
CFLAGS += -I. -I.. -I../lib

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(APP) $(LDFLAGS) $(LIBS)

strip: $(APP)
	@if test -f $(APP).exe ; then \
		echo $(STRIP) $(APP).exe; \
		$(STRIP) $(APP).exe; \
	else \
		echo $(STRIP) $(APP); \
		$(STRIP) $(APP); \
	fi;

distclean: clean

clean:
	rm -f *.o *~ $(APP) $(APP).exe
	find . -name '*.o' -delete

install: all
	mkdir -p $(DESTDIR)$(bindir)
	@if test -f $(APP).exe ; then \
		echo install $(APP).exe; \
		install $(APP).exe $(DESTDIR)$(bindir); \
	else \
		echo install $(APP); \
		install $(APP) $(DESTDIR)$(bindir); \
	fi;

install-strip: strip install

uninstall:
	rm -f $(DESTDIR)$(bindir)/$(APP)
