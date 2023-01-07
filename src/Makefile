
include ../config.mk

APP  = unace
# find . -name '*.c' | sed 's%\.c%.o%'
OBJS = acefuncs.o \
	base/all.o \
	base/unused.o \
	base/arcblk.o \
	base/archives/ace.o \
	base/archives/read.o \
	base/archives/test.o \
	base/bitwidth.o \
	base/bufread.o \
	base/comments.o \
	base/convert.o \
	base/cprdcpr/cprdcpr.o \
	base/crc.o \
	base/crypt.o \
	base/dcpr/comments.o \
	base/dcpr/dcpr.o \
	base/dcpr/huff.o \
	base/dcpr/lz77.o \
	base/dcpr/pic.o \
	base/dcpr/sound.o \
	base/dosfuncs.o \
	base/error.o \
	base/errorout.o \
	base/extract.o \
	base/filelist.o \
	base/funcs.o \
	base/lfn.o \
	base/memory.o \
	base/msgout.o \
	base/options.o \
	base/pathfunc.o \
	base/qsort.o \
	base/state.o \
	base/uninorm/unincore.o \
	base/uninorm/uninorm.o \
	base/volume.o \
	commline.o \
	convert.o \
	input.o \
	main.o \
	messages/messages.o \
	output.o \
	state.o

# -D__EMULATE_UNALIGNED__
CFLAGS += -I. -I.. -I../lib

all: $(APP)

$(APP): $(OBJS)
	@if ! test -f $(APP) && ! test -f $(APP).exe ; then \
		echo "$(CC) $(CFLAGS) $(OBJS) -o $(APP) $(LDFLAGS) $(LIBS)"; \
		$(CC) $(CFLAGS) $(OBJS) -o $(APP) $(LDFLAGS) $(LIBS); \
	fi;

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
