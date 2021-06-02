EXE_SRCS                          = $(APPS_SRCS)exe/
EXE_OBJ_DIR                       = $(APPS_OBJ_DIR)exe/
EXE_OBJ16_DIR                     = $(EXE_OBJ_DIR)16/
EXE_OBJ32_DIRsl                   = $(EXE_OBJ_DIR)32
EXE_OBJ32_DIR                     = $(EXE_OBJ_DIR)32/
EXEEXT_OBJ16_DIR                  = $(EXE_OBJ16_DIR)ext/
EXEEXT_OBJ32_DIR                  = $(EXE_OBJ32_DIR)ext/

dosEXE_SRCS                       = $(dosAPPS_SRCS)exe\  #

##############################################################################
EXE_EXT_SRCS                      = $(EXE_SRCS)extern/########################
$(EXEEXT_OBJ32_DIR)arcblk.obj     : $(EXE_EXT_SRCS)arcblk/arcblk.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)comments.obj   : $(EXE_EXT_SRCS)comments/comments.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)crypt.obj      : $(EXE_EXT_SRCS)crypt/crypt.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
EXE_EXT_ERROR_SRCS                = $(EXE_EXT_SRCS)error/#####################
$(EXEEXT_OBJ32_DIR)error.obj      : $(EXE_EXT_ERROR_SRCS)error.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(EXEEXT_OBJ32_DIR)erros2.obj     : $(EXE_EXT_ERROR_SRCS)os2.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)
$(EXEEXT_OBJ32_DIR)errnt.obj      : $(EXE_EXT_ERROR_SRCS)ntlin.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(EXEEXT_OBJ32_DIR)errdos32.obj   : $(EXE_EXT_ERROR_SRCS)dos32.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)errorout.obj   : $(EXE_EXT_SRCS)errorout/errorout.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)filelist.obj   : $(EXE_EXT_SRCS)filelist/filelist.c     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)funcs.obj      : $(EXE_EXT_SRCS)funcs/funcs.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)msgout.obj     : $(EXE_EXT_SRCS)msgout/msgout.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)state.obj      : $(EXE_EXT_SRCS)state/state.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXEEXT_OBJ32_DIR)volume.obj     : $(EXE_EXT_SRCS)volume/volume.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
##############################################################################
##############################################################################
$(EXE_OBJ32_DIR)acefuncs.obj      : $(EXE_SRCS)acefuncs/acefuncs.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXE_OBJ32_DIR)commline.obj      : $(EXE_SRCS)commline/commline.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXE_OBJ32_DIR)convert.obj       : $(EXE_SRCS)convert/convert.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
EXE_INPUT_DIR                     = $(EXE_SRCS)input/#########################

$(EXE_OBJ32_DIR)input.obj         : $(EXE_INPUT_DIR)input.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(EXE_OBJ32_DIR)inputdos.obj      : $(EXE_INPUT_DIR)dos32.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(EXE_OBJ32_DIR)inputnt.obj       : $(EXE_INPUT_DIR)nt.c                   .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(EXE_OBJ32_DIR)inputos2.obj      : $(EXE_INPUT_DIR)os2.c                  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)

##############################################################################
MESSAGEDIR                        = $(EXE_SRCS)messages/######################
MSGFILESDIR                       = $(MESSAGEDIR)msgfiles/####################
MSGFILESDIRsl                     = $(MESSAGEDIR)msgfiles#####################
dosMESSAGEDIR                     = $(dosEXE_SRCS)messages\###################
dosMSGFILESDIR                    = $(dosMESSAGEDIR)msgfiles\#################

$(EXECS_MSGFILES_DIR)unacebru.msg     : $(MSGFILESDIR)bru.msd                  \
                                        $(MSGFILESDIR)bru.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)bru.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)bru.msd $(MSGFILESDIR)bru.msg $@

$(EXECS_MSGFILES_DIR)unaceczc.msg     : $(MSGFILESDIR)czc.msd                  \
                                        $(MSGFILESDIR)czc.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)czc.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)czc.msd $(MSGFILESDIR)czc.msg $@

$(EXECS_MSGFILES_DIR)unacedut.msg     : $(MSGFILESDIR)dut.msd                  \
                                        $(MSGFILESDIR)dut.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)dut.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)dut.msd $(MSGFILESDIR)dut.msg $@

$(EXECS_MSGFILES_DIR)unacefin.msg     : $(MSGFILESDIR)fin.msd                  \
                                        $(MSGFILESDIR)fin.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)fin.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)fin.msd $(MSGFILESDIR)fin.msg $@

$(EXECS_MSGFILES_DIR)unaceger.msg     : $(MSGFILESDIR)ger.msd                  \
                                        $(MSGFILESDIR)ger.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)ger.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)ger.msd $(MSGFILESDIR)ger.msg $@

$(EXECS_MSGFILES_DIR)unacegrk.msg     : $(MSGFILESDIR)grk.msd                  \
                                        $(MSGFILESDIR)grk.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)grk.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)grk.msd $(MSGFILESDIR)grk.msg $@

$(EXECS_MSGFILES_DIR)unacehun.msg     : $(MSGFILESDIR)hun.msd                  \
                                        $(MSGFILESDIR)hun.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)hun.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)hun.msd $(MSGFILESDIR)hun.msg $@

$(EXECS_MSGFILES_DIR)unacenwg.msg     : $(MSGFILESDIR)nwg.msd                  \
                                        $(MSGFILESDIR)nwg.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)nwg.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)nwg.msd $(MSGFILESDIR)nwg.msg $@

$(EXECS_MSGFILES_DIR)unacepol.msg     : $(MSGFILESDIR)pol.msd                  \
                                        $(MSGFILESDIR)pol.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)pol.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)pol.msd $(MSGFILESDIR)pol.msg $@

$(EXECS_MSGFILES_DIR)unacepor.msg     : $(MSGFILESDIR)por.msd                  \
                                        $(MSGFILESDIR)por.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)por.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)por.msd $(MSGFILESDIR)por.msg $@

$(EXECS_MSGFILES_DIR)unacerom.msg     : $(MSGFILESDIR)rom.msd                  \
                                        $(MSGFILESDIR)rom.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)rom.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)rom.msd $(MSGFILESDIR)rom.msg $@

$(EXECS_MSGFILES_DIR)unacerus.msg     : $(MSGFILESDIR)rus.msd                  \
                                        $(MSGFILESDIR)rus.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)rus.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)rus.msd $(MSGFILESDIR)rus.msg $@

$(EXECS_MSGFILES_DIR)unacespa.msg     : $(MSGFILESDIR)spa.msd                  \
                                        $(MSGFILESDIR)spa.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)spa.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)spa.msd $(MSGFILESDIR)spa.msg $@

$(EXECS_MSGFILES_DIR)unaceswe.msg     : $(MSGFILESDIR)swe.msd                  \
                                        $(MSGFILESDIR)swe.msg                  .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)swe.msg
	$(PROGMING_DIR)msgwrite 0 $(MSGFILESDIR)swe.msd $(MSGFILESDIR)swe.msg $@

$(EXE_OBJ_DIR)eng.msg             : $(MSGFILESDIR)eng.msd                      \
                                    $(MSGFILESDIR)eng.msg                      .AUTODEPEND
	$(PROGMING_DIR)del_cr $(MSGFILESDIR)eng.msg
	cd $(MSGFILESDIR)
	$(PROGMING_DIR)msgwrite 0 eng.msd eng.msg $@
	cd $(OBJ_DIRsl)

$(EXE_OBJ32_DIR)eng.obj           :     $(EXE_OBJ_DIR)eng.msg                  .AUTODEPEND
	cd $(EXE_OBJ32_DIRsl)
	$(PROGMING_DIR)binobj $(EXE_OBJ_DIR)eng.msg eng.obj APPS_EXE_MESSAGES_EXTERN_ENGLISH_
	$(PROGMING_DIR)msgtoc $(MSGFILESDIR)eng.c $(EXE_OBJ_DIR)eng.msg
	cd $(OBJ_DIRsl)

$(EXE_OBJ32_DIR)messages.obj      : $(MESSAGEDIR)messages.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXE_OBJ32_DIR)outpterr.obj      : $(EXE_SRCS)outpterr/outpterr.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(EXE_OBJ32_DIR)output.obj        : $(EXE_SRCS)output/output.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(EXE_OBJ32_DIR)outdos32.obj      : $(EXE_SRCS)output/dos32.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)
$(EXE_OBJ32_DIR)outdosas.obj      : $(EXE_SRCS)output/dos32.asm            .AUTODEPEND
	$(COMPILE_A)
$(EXE_OBJ32_DIR)outnt.obj         : $(EXE_SRCS)output/nt.c                 .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)
$(EXE_OBJ32_DIR)outos2.obj        : $(EXE_SRCS)output/os2.c                .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)

##############################################################################
EXE_STATE_SRCS                    = $(EXE_SRCS)state/#########################
$(EXE_OBJ32_DIR)state.obj         : $(EXE_STATE_SRCS)state.c               .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(EXE_OBJ32_DIR)statewat.obj      : $(EXE_STATE_SRCS)watcom.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
APPS_EXE_CFILES =								\
  $(EXE_EXT_SRCS)arcblk/arcblk.c	$(EXE_EXT_SRCS)comments/comments.c	\
  $(EXE_EXT_SRCS)crypt/crypt.c		$(EXE_EXT_ERROR_SRCS)error.c            \
  $(EXE_EXT_ERROR_SRCS)ntlin.c							\
  $(EXE_EXT_SRCS)errorout/errorout.c	$(EXE_EXT_SRCS)filelist/filelist.c	\
  $(EXE_EXT_SRCS)funcs/funcs.c		$(EXE_EXT_SRCS)msgout/msgout.c		\
  $(EXE_EXT_SRCS)state/state.c		$(EXE_EXT_SRCS)volume/volume.c		\
  $(EXE_SRCS)acefuncs/acefuncs.c	$(EXE_SRCS)commline/commline.c		\
  $(EXE_SRCS)convert/convert.c		$(EXE_INPUT_DIR)input.c			\
  $(EXE_INPUT_DIR)lin.c								\
  $(MSGFILESDIR)eng.c			$(MESSAGEDIR)messages.c			\
  $(EXE_SRCS)outpterr/outpterr.c	$(EXE_SRCS)output/output.c		\
  $(EXE_SRCS)output/lin.c							\
  $(EXE_STATE_SRCS)state.c		$(EXE_STATE_SRCS)gcc.c

##############################################################################
EXEEXT_DOS_OBJS                 =                                         \
  $(EXEEXT_OBJ32_DIR)errdos32.obj      $(EXE_OBJ32_DIR)outdos32.obj

EXEEXT_NT_OBJS                    =                                       \
  $(EXEEXT_OBJ32_DIR)errnt.obj         $(EXE_OBJ32_DIR)outnt.obj

EXEEXT_OS2_OBJS                   =                                       \
  $(EXEEXT_OBJ32_DIR)erros2.obj        $(EXE_OBJ32_DIR)outos2.obj

##############################################################################
##############################################################################
APPS_EXEEXT_OBJS                  =                                       \
  $(EXEEXT_OBJ32_DIR)arcblk.obj        $(EXEEXT_OBJ32_DIR)comments.obj    \
  $(EXEEXT_OBJ32_DIR)crypt.obj         $(EXEEXT_OBJ32_DIR)errorout.obj    \
  $(EXEEXT_OBJ32_DIR)error.obj         $(EXEEXT_OBJ32_DIR)filelist.obj    \
  $(EXEEXT_OBJ32_DIR)funcs.obj         $(EXEEXT_OBJ32_DIR)msgout.obj      \
  $(EXEEXT_OBJ32_DIR)state.obj         $(EXEEXT_OBJ32_DIR)volume.obj

APPS_EXE_OBJS                     =                                       \
  $(APPS_EXEEXT_OBJS)                                                     \
  $(EXE_OBJ32_DIR)acefuncs.obj                                            \
  $(EXE_OBJ32_DIR)commline.obj                                            \
  $(EXE_OBJ32_DIR)convert.obj          $(EXE_OBJ32_DIR)input.obj          \
  $(EXE_OBJ32_DIR)messages.obj         $(EXE_OBJ32_DIR)outpterr.obj       \
  $(EXE_OBJ32_DIR)output.obj           $(EXE_OBJ32_DIR)state.obj          \
  $(EXE_OBJ32_DIR)statewat.obj
