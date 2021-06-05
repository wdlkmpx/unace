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

