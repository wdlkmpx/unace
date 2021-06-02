UNACEEXE_SRCS                      = $(UNACE_SRCS)exe/
UNACEEXE_EXT_SRCS                  = $(UNACEEXE_SRCS)extern/
UNACEEXE_OBJ_DIR                   = $(APPS_OBJ_DIR)unaceexe/
UNACEEXE_EXT_OBJ_DIR               = $(UNACEEXE_OBJ_DIR)ext/
SFXDDIR 			   = $(BASE_SRCS)ace/sfx/

##############################################################################
UNACEEXE_EXT_SRCS         = $(UNACEEXE_SRCS)extern/###########################
$(UNACEEXE_EXT_OBJ_DIR)arcblk.obj   : $(UNACEEXE_EXT_SRCS)arcblk/arcblk.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)arcread.obj  : $(UNACEEXE_EXT_SRCS)arcread/arcread.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)comments.obj : $(UNACEEXE_EXT_SRCS)comments/comments.c .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)error.obj    : $(UNACEEXE_EXT_SRCS)error/error.c       .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)filelist.obj : $(UNACEEXE_EXT_SRCS)filelist/filelist.c .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)input.obj    : $(UNACEEXE_EXT_SRCS)input/input.c       .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(UNACEEXE_EXT_OBJ_DIR)inpnt.obj    : $(UNACEEXE_EXT_SRCS)input/nt.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)messages.obj : $(UNACEEXE_EXT_SRCS)messages/messages.c .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)msgout.obj   : $(UNACEEXE_EXT_SRCS)msgout/msgout.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)options.obj  : $(UNACEEXE_EXT_SRCS)options/options.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)output.obj   : $(UNACEEXE_EXT_SRCS)output/output.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)volume.obj   : $(UNACEEXE_EXT_SRCS)volume/volume.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)state.obj    : $(UNACEEXE_EXT_SRCS)state/state.c       .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
##############################################################################
##############################################################################
$(UNACEEXE_OBJ_DIR)commline.obj     : $(UNACEEXE_SRCS)commline/commline.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(UNACEEXE_OBJ_DIR)clhelp.obj       : $(UNACEEXE_SRCS)commline/help/help.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(UNACEEXE_OBJ_DIR)exe.obj          : $(UNACEEXE_SRCS)exe.c                    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(UNACEEXE_OBJ_DIR)exent.obj        : $(UNACEEXE_SRCS)nt.c                     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(UNACEEXE_OBJ_DIR)exedos32.obj      : $(UNACEEXE_SRCS)dos32.c                 .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(UNACEEXE_OBJ_DIR)exeos2.obj        : $(UNACEEXE_SRCS)os2.c                   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)


##############################################################################
APPS_UNACEEXE_CFILES =									\
  $(UNACEEXE_EXT_SRCS)arcblk/arcblk.c		$(UNACEEXE_EXT_SRCS)arcread/arcread.c	\
  $(UNACEEXE_EXT_SRCS)comments/comments.c       $(UNACEEXE_EXT_SRCS)error/error.c       \
  $(UNACEEXE_EXT_SRCS)filelist/filelist.c	$(UNACEEXE_EXT_SRCS)input/input.c	\
  $(UNACEEXE_EXT_SRCS)messages/messages.c						\
  $(UNACEEXE_EXT_SRCS)msgout/msgout.c		$(UNACEEXE_EXT_SRCS)options/options.c	\
  $(UNACEEXE_EXT_SRCS)output/output.c		$(UNACEEXE_EXT_SRCS)volume/volume.c	\
  $(UNACEEXE_EXT_SRCS)state/state.c		$(UNACEEXE_SRCS)commline/commline.c	\
  $(UNACEEXE_SRCS)commline/help/help.c		$(UNACEEXE_SRCS)exe.c			\
  $(UNACEEXE_SRCS)lin.c


##############################################################################
##############################################################################


APPS_UNACEEXE_EXT_OBJS              =                                       \
  $(UNACEEXE_EXT_OBJ_DIR)arcblk.obj      $(UNACEEXE_EXT_OBJ_DIR)arcread.obj \
  $(UNACEEXE_EXT_OBJ_DIR)comments.obj                                       \
  $(UNACEEXE_EXT_OBJ_DIR)error.obj       $(UNACEEXE_EXT_OBJ_DIR)filelist.obj\
  $(UNACEEXE_EXT_OBJ_DIR)input.obj       $(UNACEEXE_EXT_OBJ_DIR)messages.obj\
  $(UNACEEXE_EXT_OBJ_DIR)msgout.obj      $(UNACEEXE_EXT_OBJ_DIR)options.obj \
  $(UNACEEXE_EXT_OBJ_DIR)output.obj      $(UNACEEXE_EXT_OBJ_DIR)state.obj   \
  $(UNACEEXE_EXT_OBJ_DIR)volume.obj

APPS_EXE_UNACEEXE_OBJS              =                                       \
  $(EXE_OBJ32_DIR)eng.obj

APPS_UNACEEXE_OBJS                  =                                       \
  $(APPS_UNACEEXE_EXT_OBJS)                                                 \
  $(APPS_UNACE_OBJS)                     $(APPS_EXE_OBJS)                   \
  $(APPS_EXE_UNACEEXE_OBJS)              $(UNACEEXE_OBJ_DIR)commline.obj    \
  $(UNACEEXE_OBJ_DIR)clhelp.obj          $(UNACEEXE_OBJ_DIR)exe.obj

##############################################################################
##############################################################################

ifndef ISWMAKE
include $(MAKE_DIR)unexeln.mk
else
!include $(MAKE_DIR)UNEXE2.MK
!include $(MAKE_DIR)UNEXE32.MK
!include $(MAKE_DIR)UNEXE86.MK
endif
