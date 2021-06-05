APPS_SRCS                         = $(SRCS)apps/
APPS_OBJ_DIR                      = $(OBJ_DIR)apps/

##############################################################################

EXE_SRCS                          = $(APPS_SRCS)exe/
EXE_OBJ_DIR                       = $(APPS_OBJ_DIR)exe/
EXEEXT_OBJ32_DIR                  = ext/

##############################################################################
EXE_EXT_SRCS                      = $(EXE_SRCS)extern/########################
$(EXEEXT_OBJ32_DIR)arcblk.obj     : $(EXE_EXT_SRCS)arcblk/arcblk.c

##############################################################################
$(EXEEXT_OBJ32_DIR)comments.obj   : $(EXE_EXT_SRCS)comments/comments.c

##############################################################################
$(EXEEXT_OBJ32_DIR)crypt.obj      : $(EXE_EXT_SRCS)crypt/crypt.c

##############################################################################
EXE_EXT_ERROR_SRCS                = $(EXE_EXT_SRCS)error/#####################
$(EXEEXT_OBJ32_DIR)error.obj      : $(EXE_EXT_ERROR_SRCS)error.c

##############################################################################
$(EXEEXT_OBJ32_DIR)errorout.obj   : $(EXE_EXT_SRCS)errorout/errorout.c

##############################################################################
$(EXEEXT_OBJ32_DIR)filelist.obj   : $(EXE_EXT_SRCS)filelist/filelist.c

##############################################################################
$(EXEEXT_OBJ32_DIR)funcs.obj      : $(EXE_EXT_SRCS)funcs/funcs.c

##############################################################################
$(EXEEXT_OBJ32_DIR)msgout.obj     : $(EXE_EXT_SRCS)msgout/msgout.c

##############################################################################
$(EXEEXT_OBJ32_DIR)state.obj      : $(EXE_EXT_SRCS)state/state.c

##############################################################################
$(EXEEXT_OBJ32_DIR)volume.obj     : $(EXE_EXT_SRCS)volume/volume.c

##############################################################################
acefuncs.obj      : $(EXE_SRCS)acefuncs/acefuncs.c
convert.obj       : $(EXE_SRCS)convert/convert.c

##############################################################################
EXE_INPUT_DIR                     = $(EXE_SRCS)input/#########################

input.obj         : $(EXE_INPUT_DIR)input.c
##############################################################################
MESSAGEDIR                        = $(EXE_SRCS)messages/######################
MSGFILESDIR                       = $(MESSAGEDIR)msgfiles/####################
messages.obj      : $(MESSAGEDIR)messages.c

##############################################################################
outpterr.obj      : $(EXE_SRCS)outpterr/outpterr.c

##############################################################################
output.obj        : $(EXE_SRCS)output/output.c
##############################################################################
EXE_STATE_SRCS                    = $(EXE_SRCS)state/#########################
state.obj         : $(EXE_STATE_SRCS)state.c

##############################################################################
APPS_EXE_CFILES =								\
  $(EXE_EXT_SRCS)arcblk/arcblk.c	$(EXE_EXT_SRCS)comments/comments.c	\
  $(EXE_EXT_SRCS)crypt/crypt.c		$(EXE_EXT_ERROR_SRCS)error.c            \
  $(EXE_EXT_SRCS)errorout/errorout.c	$(EXE_EXT_SRCS)filelist/filelist.c	\
  $(EXE_EXT_SRCS)funcs/funcs.c		$(EXE_EXT_SRCS)msgout/msgout.c		\
  $(EXE_EXT_SRCS)state/state.c		$(EXE_EXT_SRCS)volume/volume.c		\
  $(EXE_SRCS)acefuncs/acefuncs.c \
  $(EXE_SRCS)convert/convert.c		$(EXE_INPUT_DIR)input.c			\
  $(EXE_INPUT_DIR)lin.c								\
  $(MSGFILESDIR)eng.c			$(MESSAGEDIR)messages.c			\
  $(EXE_SRCS)outpterr/outpterr.c	$(EXE_SRCS)output/output.c		\
  $(EXE_STATE_SRCS)state.c

##############################################################################

APPS_EXEEXT_OBJS                  =                                       \
  $(EXEEXT_OBJ32_DIR)arcblk.obj        $(EXEEXT_OBJ32_DIR)comments.obj    \
  $(EXEEXT_OBJ32_DIR)crypt.obj         $(EXEEXT_OBJ32_DIR)errorout.obj    \
  $(EXEEXT_OBJ32_DIR)error.obj         $(EXEEXT_OBJ32_DIR)filelist.obj    \
  $(EXEEXT_OBJ32_DIR)funcs.obj         $(EXEEXT_OBJ32_DIR)msgout.obj      \
  $(EXEEXT_OBJ32_DIR)state.obj         $(EXEEXT_OBJ32_DIR)volume.obj

APPS_EXE_OBJS                     =                                       \
  $(APPS_EXEEXT_OBJS)                                                     \
  acefuncs.obj                                            \
  convert.obj          input.obj          \
  messages.obj         outpterr.obj       \
  output.obj           state.obj


##############################################################################

UNACE_SRCS                          = $(APPS_SRCS)unace/
UNACEEXE_SRCS                      = $(UNACE_SRCS)exe/
UNACEEXE_EXT_SRCS                  = $(UNACEEXE_SRCS)extern/
UNACEEXE_OBJ_DIR                   = $(APPS_OBJ_DIR)unaceexe/

$(UNACEEXE_OBJ_DIR)commline.obj     : $(UNACEEXE_SRCS)commline/commline.c
$(UNACEEXE_OBJ_DIR)exe.obj          : $(UNACEEXE_SRCS)exe.c

APPS_UNACEEXE_CFILES =									\
  $(UNACEEXE_SRCS)commline/commline.c	\
  $(UNACEEXE_SRCS)exe.c			\
  $(UNACEEXE_SRCS)lin.c

