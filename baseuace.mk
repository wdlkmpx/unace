BASE_UNACE_SRCS	                      = $(BASE_SRCS)unace/
BASE_UNACE_OBJ_DIR                    = $(BASE_OBJ_DIR)unace/
BASE_UNACE_EXT_OBJ_DIR                = $(BASE_UNACE_OBJ_DIR)ext/

##############################################################################
BASE_UNACE_EXT_SRCS                   = $(BASE_UNACE_SRCS)extern/#############
$(BASE_UNACE_EXT_OBJ_DIR)arcace.obj   : $(BASE_UNACE_EXT_SRCS)arcace/arcace.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)arcblk.obj   : $(BASE_UNACE_EXT_SRCS)arcblk/arcblk.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)arcinfo.obj  : $(BASE_UNACE_EXT_SRCS)arcinfo/arcinfo.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)dcpr.obj     : $(BASE_UNACE_EXT_SRCS)dcpr/dcpr.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)extract.obj  : $(BASE_UNACE_EXT_SRCS)extract/extract.c   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)filelist.obj : $(BASE_UNACE_EXT_SRCS)filelist/filelist.c .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(BASE_UNACE_EXT_OBJ_DIR)memory.obj   : $(BASE_UNACE_EXT_SRCS)memory/memory.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
BASE_UNACE_CFILES =									  \
  $(BASE_UNACE_EXT_SRCS)arcace/arcace.c		$(BASE_UNACE_EXT_SRCS)arcblk/arcblk.c     \
  $(BASE_UNACE_EXT_SRCS)arcinfo/arcinfo.c	$(BASE_UNACE_EXT_SRCS)dcpr/dcpr.c         \
  $(BASE_UNACE_EXT_SRCS)extract/extract.c	$(BASE_UNACE_EXT_SRCS)filelist/filelist.c \
  $(BASE_UNACE_EXT_SRCS)memory/memory.c


##############################################################################
##############################################################################
BASE_UNACE_EXT_OBJS                   =                                       \
  $(BASE_UNACE_EXT_OBJ_DIR)arcace.obj   $(BASE_UNACE_EXT_OBJ_DIR)arcblk.obj   \
  $(BASE_UNACE_EXT_OBJ_DIR)arcinfo.obj                                        \
  $(BASE_UNACE_EXT_OBJ_DIR)dcpr.obj     $(BASE_UNACE_EXT_OBJ_DIR)extract.obj  \
  $(BASE_UNACE_EXT_OBJ_DIR)filelist.obj $(BASE_UNACE_EXT_OBJ_DIR)memory.obj

BASE_UNACE_OBJS                       =                                       \
  $(BASE_UNACE_EXT_OBJS)
##############################################################################
