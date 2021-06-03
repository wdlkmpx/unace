UNACE_SRCS                          = $(APPS_SRCS)unace/
UNACEALL_SRCS                       = $(UNACE_SRCS)all/
UNACE_OBJ_DIR                       = $(APPS_OBJ_DIR)unace/
UNACE_EXT_OBJ_DIR                   = $(UNACE_OBJ_DIR)ext/

##############################################################################
UNACE_EXT_SRCS                      = $(UNACEALL_SRCS)extern/#################
$(UNACE_EXT_OBJ_DIR)arctest.obj     : $(UNACE_EXT_SRCS)arctest/arctest.c   .AUTODEPEND

##############################################################################
$(UNACE_EXT_OBJ_DIR)funcs.obj       : $(UNACE_EXT_SRCS)funcs/funcs.c       .AUTODEPEND


##############################################################################
APPS_UNACE_CFILES =								\
  $(UNACE_EXT_SRCS)arctest/arctest.c	$(UNACE_EXT_SRCS)funcs/funcs.c

##############################################################################
APPS_UNACE_OBJS                     =                                       \
  $(UNACE_EXT_OBJ_DIR)arctest.obj     $(UNACE_EXT_OBJ_DIR)funcs.obj

##############################################################################

include $(MAKE_DIR)unaceexe.mk
