UNACE_SRCS                          = $(APPS_SRCS)unace/
UNACEALL_SRCS                       = $(UNACE_SRCS)all/
UNACE_OBJ_DIR                       = $(APPS_OBJ_DIR)unace/
UNACE_EXT_OBJ_DIR                   = $(UNACE_OBJ_DIR)ext/

##############################################################################
UNACE_EXT_SRCS                      = $(UNACEALL_SRCS)extern/#################
$(UNACE_EXT_OBJ_DIR)arctest.obj     : $(UNACE_EXT_SRCS)arctest/arctest.c
$(UNACE_EXT_OBJ_DIR)funcs.obj       : $(UNACE_EXT_SRCS)funcs/funcs.c

##############################################################################
APPS_UNACE_CFILES =								\
  $(UNACE_EXT_SRCS)arctest/arctest.c	$(UNACE_EXT_SRCS)funcs/funcs.c

##############################################################################
APPS_UNACE_OBJS                     =                                       \
  $(UNACE_EXT_OBJ_DIR)arctest.obj     $(UNACE_EXT_OBJ_DIR)funcs.obj


##############################################################################
#include $(MAKE_DIR)unaceexe.mk

UNACEEXE_SRCS                      = $(UNACE_SRCS)exe/
UNACEEXE_EXT_SRCS                  = $(UNACEEXE_SRCS)extern/
UNACEEXE_OBJ_DIR                   = $(APPS_OBJ_DIR)unaceexe/
UNACEEXE_EXT_OBJ_DIR               = $(UNACEEXE_OBJ_DIR)ext/

##############################################################################
$(UNACEEXE_EXT_OBJ_DIR)arcblk.obj   : $(UNACEEXE_EXT_SRCS)arcblk/arcblk.c
$(UNACEEXE_EXT_OBJ_DIR)arcread.obj  : $(UNACEEXE_EXT_SRCS)arcread/arcread.c
$(UNACEEXE_EXT_OBJ_DIR)comments.obj : $(UNACEEXE_EXT_SRCS)comments/comments.c
$(UNACEEXE_EXT_OBJ_DIR)error.obj    : $(UNACEEXE_EXT_SRCS)error/error.c
$(UNACEEXE_EXT_OBJ_DIR)filelist.obj : $(UNACEEXE_EXT_SRCS)filelist/filelist.c
$(UNACEEXE_EXT_OBJ_DIR)input.obj    : $(UNACEEXE_EXT_SRCS)input/input.c
$(UNACEEXE_EXT_OBJ_DIR)inpnt.obj    : $(UNACEEXE_EXT_SRCS)input/nt.c
$(UNACEEXE_EXT_OBJ_DIR)messages.obj : $(UNACEEXE_EXT_SRCS)messages/messages.c
$(UNACEEXE_EXT_OBJ_DIR)msgout.obj   : $(UNACEEXE_EXT_SRCS)msgout/msgout.c
$(UNACEEXE_EXT_OBJ_DIR)options.obj  : $(UNACEEXE_EXT_SRCS)options/options.c
$(UNACEEXE_EXT_OBJ_DIR)output.obj   : $(UNACEEXE_EXT_SRCS)output/output.c
$(UNACEEXE_EXT_OBJ_DIR)volume.obj   : $(UNACEEXE_EXT_SRCS)volume/volume.c
$(UNACEEXE_EXT_OBJ_DIR)state.obj    : $(UNACEEXE_EXT_SRCS)state/state.c
$(UNACEEXE_OBJ_DIR)commline.obj     : $(UNACEEXE_SRCS)commline/commline.c
$(UNACEEXE_OBJ_DIR)clhelp.obj       : $(UNACEEXE_SRCS)commline/help/help.c
$(UNACEEXE_OBJ_DIR)exe.obj          : $(UNACEEXE_SRCS)exe.c
$(UNACEEXE_OBJ_DIR)exent.obj        : $(UNACEEXE_SRCS)nt.c

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

APPS_UNACEEXE_EXT_OBJS              =                                       \
  $(UNACEEXE_EXT_OBJ_DIR)arcblk.obj      $(UNACEEXE_EXT_OBJ_DIR)arcread.obj \
  $(UNACEEXE_EXT_OBJ_DIR)comments.obj                                       \
  $(UNACEEXE_EXT_OBJ_DIR)error.obj       $(UNACEEXE_EXT_OBJ_DIR)filelist.obj\
  $(UNACEEXE_EXT_OBJ_DIR)input.obj       $(UNACEEXE_EXT_OBJ_DIR)messages.obj\
  $(UNACEEXE_EXT_OBJ_DIR)msgout.obj      $(UNACEEXE_EXT_OBJ_DIR)options.obj \
  $(UNACEEXE_EXT_OBJ_DIR)output.obj      $(UNACEEXE_EXT_OBJ_DIR)state.obj   \
  $(UNACEEXE_EXT_OBJ_DIR)volume.obj

APPS_UNACEEXE_OBJS                  =                                       \
  $(APPS_UNACEEXE_EXT_OBJS)                                                 \
  $(APPS_UNACE_OBJS)                     $(APPS_EXE_OBJS)                   \
  $(APPS_EXE_UNACEEXE_OBJS)              $(UNACEEXE_OBJ_DIR)commline.obj    \
  $(UNACEEXE_OBJ_DIR)clhelp.obj          $(UNACEEXE_OBJ_DIR)exe.obj

