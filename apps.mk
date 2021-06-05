APPS_SRCS                         = $(SRCS)apps/
APPS_OBJ_DIR                      = $(OBJ_DIR)apps/
EXE_OBJ_DIR                       = $(APPS_OBJ_DIR)

##############################################################################
acefuncs.obj      : $(APPS_SRCS)acefuncs/acefuncs.c
convert.obj       : $(APPS_SRCS)convert/convert.c
##############################################################################
EXE_INPUT_DIR                     = $(APPS_SRCS)input/#########################

input.obj         : $(EXE_INPUT_DIR)input.c
##############################################################################
MESSAGEDIR                        = $(APPS_SRCS)messages/######################
MSGFILESDIR                       = $(MESSAGEDIR)msgfiles/####################
messages.obj      : $(MESSAGEDIR)messages.c

##############################################################################
outpterr.obj      : $(APPS_SRCS)outpterr/outpterr.c

##############################################################################
output.obj        : $(APPS_SRCS)output/output.c
##############################################################################
EXE_STATE_SRCS                    = $(APPS_SRCS)state/#########################
state.obj         : $(EXE_STATE_SRCS)state.c

##############################################################################
APPS_EXE_CFILES =								\
  $(APPS_SRCS)acefuncs/acefuncs.c \
  $(APPS_SRCS)convert/convert.c		$(EXE_INPUT_DIR)input.c			\
  $(EXE_INPUT_DIR)lin.c								\
  $(MSGFILESDIR)eng.c			$(MESSAGEDIR)messages.c			\
  $(APPS_SRCS)outpterr/outpterr.c	$(APPS_SRCS)output/output.c		\
  $(EXE_STATE_SRCS)state.c

##############################################################################

APPS_EXE_OBJS                     =                                       \
  acefuncs.obj                                            \
  convert.obj          input.obj          \
  messages.obj         outpterr.obj       \
  output.obj           state.obj


##############################################################################

UNACE_SRCS                          = $(APPS_SRCS)

$(UNACE_SRCS)commline.obj     : $(UNACE_SRCS)commline.c
$(UNACE_SRCS)exe.obj          : $(UNACE_SRCS)exe.c

APPS_UNACEEXE_CFILES =									\
  $(UNACE_SRCS)commline.c $(UNACE_SRCS)exe.c $(UNACE_SRCS)lin.c

