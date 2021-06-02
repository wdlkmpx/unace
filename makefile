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

INCLSYSDIR 	= //usr/include/sys
INCLDIR 	= //usr/include

DEFINES		= -D__LINUX__ -D__unix__ -D__GCC__ -D__HAS_IO_H__

ifdef DEBUG
LSWITCHES	=
else
LSWITCHES	= -Wl,-s
endif

##############################################################################
all: unace

clean:
	rm unace
	rm linunace25.tgz
	
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
	gcc $(LSWITCHES) -Wl,-lncurses -static -I$(INCLDIR) -I$(INCLSYSDIR) -I$(SRCSsl) $(DEFINES) $(UNACEEXELIN_CFILES) -ggdb -o$(EXECS_DIR)unace
ifndef DEBUG
	tar cfvz linunace25.tgz unace file_id.diz licence
	#sh linpack.sh
endif

