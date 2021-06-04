DEBUG = 1

BASIC_DIRsl     = 
BASIC_DIR       = 


MAKE_DIRsl      = 
MAKE_DIR        = 

EXECS_DIR       = 
EXECS_DIRsl     = 
PACKAGES_DIR    = 
PACKAGES_DIRsl  = 
SRCSsl          = $(BASIC_DIR)source
SRCS            = $(SRCSsl)/
INCLS           =

DEFINES		= -D__LINUX__ -D__unix__ -D__GCC__ -U__HAS_IO_H__
#DEFINES	= -D__MACOSX__ -D__unix__ -D__GCC__
#DEFINES	= -D__unix__ -D__GCC__ -D__BIG_ENDIAN__ -D__EMULATE_UNALIGNED__

##############################################################################
all: unace

clean:
	rm -f unace
	rm -f linunace25.tgz
	
include $(MAKE_DIR)base.mk
include $(MAKE_DIR)apps.mk

##############################################################################
UNACEEXELIN_CFILES =					\
  $(BASE_ALL_LIN_CFILES) 	$(BASE_UNACE_CFILES)	\
  $(APPS_EXE_CFILES) 		$(APPS_UNACE_CFILES)	\
  $(APPS_UNACEEXE_CFILES)

UNACEEXENT_CFILES =					\
  $(BASE_ALL_NT_CFILES) 	$(BASE_UNACE_CFILES)	\
  $(APPS_EXE_CFILES) 		$(APPS_UNACE_CFILES)	\
  $(APPS_UNACEEXE_CFILES)

unace: $(UNACEEXELIN_CFILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(INCLS) -I$(SRCSsl) $(DEFINES) $(UNACEEXELIN_CFILES) -o$(EXECS_DIR)unace
