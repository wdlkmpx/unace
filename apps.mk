APPS_SRCS                         = $(SRCS)apps/
APPS_OBJ_DIR                      = $(OBJ_DIR)apps/
EXE_OBJ_DIR                       = $(APPS_OBJ_DIR)
UNACE_SRCS                        = $(APPS_SRCS)

##############################################################################

acefuncs.obj      : $(APPS_SRCS)acefuncs/acefuncs.c
convert.obj       : $(APPS_SRCS)convert/convert.c
input.obj         : $(APPS_SRCS)input/input.c
messages.obj      : $(APPS_SRCS)messages/messages.c
outpterr.obj      : $(APPS_SRCS)outpterr/outpterr.c
output.obj        : $(APPS_SRCS)output/output.c
state.obj         : $(APPS_SRCS)state/state.c

##############################################################################

APPS_EXE_CFILES =                 \
  $(APPS_SRCS)acefuncs/acefuncs.c \
  $(APPS_SRCS)convert/convert.c   \
  $(APPS_SRCS)input/input.c       \
  $(APPS_SRCS)input/lin.c         \
  $(APPS_SRCS)messages/msgfiles/eng.c \
  $(APPS_SRCS)messages/messages.c \
  $(APPS_SRCS)outpterr/outpterr.c \
  $(APPS_SRCS)output/output.c     \
  $(APPS_SRCS)state/state.c

##############################################################################

APPS_EXE_OBJS                     =                                       \
  acefuncs.obj                                            \
  convert.obj          input.obj          \
  messages.obj         outpterr.obj       \
  output.obj           state.obj

##############################################################################

$(UNACE_SRCS)commline.obj     : $(UNACE_SRCS)commline.c
$(UNACE_SRCS)exe.obj          : $(UNACE_SRCS)exe.c

APPS_UNACEEXE_CFILES = $(UNACE_SRCS)commline.c $(UNACE_SRCS)exe.c $(UNACE_SRCS)lin.c

