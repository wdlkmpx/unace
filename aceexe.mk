ACEEXE_SRCS                       = $(APPS_SRCS)ACE/EXE/
ACEEXE_EXT_SRCS                   = $(ACEEXE_SRCS)EXTERN/
ACEEXE_OBJ_DIR                    = $(APPS_OBJ_DIR)ACEEXE/
ACEEXE_OBJ_DIRsl                  = $(APPS_OBJ_DIR)ACEEXE
ACEEXE_EXT_OBJ_DIR                = $(ACEEXE_OBJ_DIR)EXT/

ACEMESSAGEDIR                     = $(ACEEXE_SRCS)MESSAGES/
ACEMSGFILESDIR                    = $(ACEMESSAGEDIR)MSGFILES/
ACEMSGFILESDIRsl                  = $(ACEMESSAGEDIR)MSGFILES

dosACEEXE_SRCS                    = $(dosAPPS_SRCS)ACE\EXE\	 #
dosACEEXE_OBJ_DIR                 = $(dosAPPS_OBJ_DIR)ACEEXE\    #
dosACEMESSAGEDIR                  = $(dosACEEXE_SRCS)MESSAGES\   #
dosACEMSGFILESDIR                 = $(dosACEMESSAGEDIR)MSGFILES\ #
dosACEMSGFILESDIRsl               = $(dosACEMESSAGEDIR)MSGFILES  #

##############################################################################
ACEEXE_EXT_SRCS         = $(ACEEXE_SRCS)EXTERN/###############################
$(ACEEXE_EXT_OBJ_DIR)acarcblk.obj : $(ACEEXE_EXT_SRCS)acarcblk/acarcblk.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acecomm.obj  : $(ACEEXE_EXT_SRCS)acecomm/acecomm.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acefuncs.obj : $(ACEEXE_EXT_SRCS)acefuncs/acefuncs.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acerrout.obj : $(ACEEXE_EXT_SRCS)acerrout/acerrout.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)volume.obj   : $(ACEEXE_EXT_SRCS)volume/volume.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acestate.obj : $(ACEEXE_EXT_SRCS)acestate/acestate.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acfuncs.obj  : $(ACEEXE_EXT_SRCS)acfuncs/acfuncs.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acmsgout.obj : $(ACEEXE_EXT_SRCS)acmsgout/acmsgout.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acoptns.obj  : $(ACEEXE_EXT_SRCS)acoptns/acoptns.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)acvolume.obj : $(ACEEXE_EXT_SRCS)acvolume/acvolume.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)add.obj      : $(ACEEXE_EXT_SRCS)add/add.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)arcblk.obj   : $(ACEEXE_EXT_SRCS)arcblk/arcblk.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)arcread.obj  : $(ACEEXE_EXT_SRCS)arcread/arcread.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)arctest.obj  : $(ACEEXE_EXT_SRCS)arctest/arctest.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)av.obj       : $(ACEEXE_EXT_SRCS)av/av.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)comments.obj : $(ACEEXE_EXT_SRCS)comments/comments.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)error.obj    : $(ACEEXE_EXT_SRCS)error/error.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)filelist.obj : $(ACEEXE_EXT_SRCS)filelist/filelist.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)filesort.obj : $(ACEEXE_EXT_SRCS)filesort/filesort.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)funcs.obj    : $(ACEEXE_EXT_SRCS)funcs/funcs.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)input.obj    : $(ACEEXE_EXT_SRCS)input/input.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)inpnt.obj    : $(ACEEXE_EXT_SRCS)input/nt.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)memory.obj   : $(ACEEXE_EXT_SRCS)memory/memory.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)messages.obj : $(ACEEXE_EXT_SRCS)messages/messages.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)msgout.obj   : $(ACEEXE_EXT_SRCS)msgout/msgout.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)options.obj  : $(ACEEXE_EXT_SRCS)options/options.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)output.obj   : $(ACEEXE_EXT_SRCS)output/output.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)repair.obj   : $(ACEEXE_EXT_SRCS)repair/repair.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)state.obj    : $(ACEEXE_EXT_SRCS)state/state.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_EXT_OBJ_DIR)temp.obj     : $(ACEEXE_EXT_SRCS)temp/temp.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
##############################################################################
##############################################################################
$(ACEEXE_OBJ_DIR)acefuncs.obj     : $(ACEEXE_SRCS)acefuncs/acefuncs.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
ACEEXE_ARCS_SRCS                  = $(ACEEXE_SRCS)ARCHIVES/###################

$(ACEEXE_OBJ_DIR)acarctst.obj     : $(ACEEXE_ARCS_SRCS)test/test.c         .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)arcarj.obj       : $(ACEEXE_ARCS_SRCS)arj/arj.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)arccall.obj      : $(ACEEXE_ARCS_SRCS)callprog/callprog.c .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)arcrar.obj       : $(ACEEXE_ARCS_SRCS)rar/rar.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)arczip.obj       : $(ACEEXE_ARCS_SRCS)zip/zip.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
CLDIR                             = $(ACEEXE_SRCS)COMMLINE/###################
$(ACEEXE_OBJ_DIR)commline.obj     : $(CLDIR)commline.c                     .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)clhelp.obj       : $(CLDIR)help/help.c                    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)comments.obj     : $(ACEEXE_SRCS)comments/comments.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)convert.obj      : $(ACEEXE_SRCS)convert/convert.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)filelist.obj     : $(ACEEXE_SRCS)filelist/filelist.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)filesort.obj     : $(ACEEXE_SRCS)filesort/filesort.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)funcs.obj        : $(ACEEXE_SRCS)funcs/funcs.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
ACE_EXE_INPUT_DIR                  = $(ACEEXE_SRCS)INPUT/#####################

$(ACEEXE_OBJ_DIR)input.obj         : $(ACE_EXE_INPUT_DIR)input.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)inputdos.obj      : $(ACE_EXE_INPUT_DIR)dos32.c           .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)inputnt.obj       : $(ACE_EXE_INPUT_DIR)nt.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_WIN32)

$(ACEEXE_OBJ_DIR)inputos2.obj      : $(ACE_EXE_INPUT_DIR)os2.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_OS2)


##############################################################################
ACEENGMSGFILE                     = $(ACEEXE_OBJ_DIR)aceeng.msg###############

$(ACEEXE_OBJ_DIR)ACEBRU.CPD           : $(MSGFILESDIR)BRU.MSG                  \
	                              $(ACEMSGFILESDIR)ACEBRU.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)BRU.MSG+$(dosACEMSGFILESDIR)ACEBRU.MSG ACEBRU.CPD
	$(PROGMING_DIR)del_cr ACEBRU.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEBRU.MSG       : $(MSGFILESDIR)BRU.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEBRU.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)BRU.MSD ACEBRU.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACECZC.CPD           : $(MSGFILESDIR)CZC.MSG                  \
	                              $(ACEMSGFILESDIR)ACECZC.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)CZC.MSG+$(dosACEMSGFILESDIR)ACECZC.MSG ACECZC.CPD
	$(PROGMING_DIR)del_cr ACECZC.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACECZC.MSG       : $(MSGFILESDIR)CZC.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACECZC.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)CZC.MSD ACECZC.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEDUT.CPD           : $(MSGFILESDIR)DUT.MSG                  \
                                        $(ACEMSGFILESDIR)ACEDUT.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)DUT.MSG+$(dosACEMSGFILESDIR)ACEDUT.MSG ACEDUT.CPD
	$(PROGMING_DIR)del_cr ACEDUT.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEDUT.MSG       : $(MSGFILESDIR)DUT.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEDUT.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)DUT.MSD ACEDUT.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEFIN.CPD           : $(MSGFILESDIR)FIN.MSG                  \
                                        $(ACEMSGFILESDIR)ACEFIN.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)FIN.MSG+$(dosACEMSGFILESDIR)ACEFIN.MSG ACEFIN.CPD
	$(PROGMING_DIR)del_cr ACEFIN.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEFIN.MSG       : $(MSGFILESDIR)FIN.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEFIN.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)FIN.MSD ACEFIN.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEFRE.CPD           : $(MSGFILESDIR)FRE.MSG                  \
                                        $(ACEMSGFILESDIR)ACEFRE.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)FRE.MSG+$(dosACEMSGFILESDIR)ACEFRE.MSG ACEFRE.CPD
	$(PROGMING_DIR)del_cr ACEFRE.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEFRE.MSG       : $(MSGFILESDIR)FRE.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEFRE.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)FRE.MSD ACEFRE.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEGER.CPD           : $(MSGFILESDIR)GER.MSG                  \
                                        $(ACEMSGFILESDIR)ACEGER.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)GER.MSG+$(dosACEMSGFILESDIR)ACEGER.MSG ACEGER.CPD
	$(PROGMING_DIR)del_cr ACEGER.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEGER.MSG       : $(MSGFILESDIR)GER.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEGER.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)GER.MSD ACEGER.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEGRK.CPD           : $(MSGFILESDIR)GRK.MSG                  \
                                        $(ACEMSGFILESDIR)ACEGRK.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)GRK.MSG+$(dosACEMSGFILESDIR)ACEGRK.MSG ACEGRK.CPD
	$(PROGMING_DIR)del_cr ACEGRK.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEGRK.MSG       : $(MSGFILESDIR)GRK.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEGRK.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)GRK.MSD ACEGRK.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEHUN.CPD           : $(MSGFILESDIR)HUN.MSG                  \
                                        $(ACEMSGFILESDIR)ACEHUN.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)HUN.MSG+$(dosACEMSGFILESDIR)ACEHUN.MSG ACEHUN.CPD
	$(PROGMING_DIR)del_cr ACEHUN.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEHUN.MSG       : $(MSGFILESDIR)HUN.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEHUN.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)HUN.MSD ACEHUN.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACENWG.CPD           : $(MSGFILESDIR)NWG.MSG                  \
                                        $(ACEMSGFILESDIR)ACENWG.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)NWG.MSG+$(dosACEMSGFILESDIR)ACENWG.MSG ACENWG.CPD
	$(PROGMING_DIR)del_cr ACENWG.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACENWG.MSG       : $(MSGFILESDIR)NWG.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACENWG.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)NWG.MSD ACENWG.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEPOL.CPD           : $(MSGFILESDIR)POL.MSG                  \
                                        $(ACEMSGFILESDIR)ACEPOL.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)POL.MSG+$(dosACEMSGFILESDIR)ACEPOL.MSG ACEPOL.CPD
	$(PROGMING_DIR)del_cr ACEPOL.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEPOL.MSG       : $(MSGFILESDIR)POL.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEPOL.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)POL.MSD ACEPOL.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEPOR.CPD           : $(MSGFILESDIR)POR.MSG                  \
                                        $(ACEMSGFILESDIR)ACEPOR.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)POR.MSG+$(dosACEMSGFILESDIR)ACEPOR.MSG ACEPOR.CPD
	$(PROGMING_DIR)del_cr ACEPOR.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEPOR.MSG       : $(MSGFILESDIR)POR.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEPOR.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)POR.MSD ACEPOR.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEROM.CPD           : $(MSGFILESDIR)ROM.MSG                  \
                                        $(ACEMSGFILESDIR)ACEROM.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)ROM.MSG+$(dosACEMSGFILESDIR)ACEROM.MSG ACEROM.CPD
	$(PROGMING_DIR)del_cr ACEROM.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACEROM.MSG       : $(MSGFILESDIR)ROM.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEROM.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)ROM.MSD ACEROM.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACERUS.CPD           : $(MSGFILESDIR)RUS.MSG                  \
                                        $(ACEMSGFILESDIR)ACERUS.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)RUS.MSG+$(dosACEMSGFILESDIR)ACERUS.MSG ACERUS.CPD
	$(PROGMING_DIR)del_cr ACERUS.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACERUS.MSG       : $(MSGFILESDIR)RUS.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACERUS.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)RUS.MSD ACERUS.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACESPA.CPD           : $(MSGFILESDIR)SPA.MSG                  \
                                        $(ACEMSGFILESDIR)ACESPA.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)SPA.MSG+$(dosACEMSGFILESDIR)ACESPA.MSG ACESPA.CPD
	$(PROGMING_DIR)del_cr ACESPA.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACESPA.MSG       : $(MSGFILESDIR)SPA.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACESPA.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)SPA.MSD ACESPA.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACESWE.CPD           : $(MSGFILESDIR)SWE.MSG                  \
                                        $(ACEMSGFILESDIR)ACESWE.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)SWE.MSG+$(dosACEMSGFILESDIR)ACESWE.MSG ACESWE.CPD
	$(PROGMING_DIR)del_cr ACESWE.CPD
	cd $(OBJ_DIRsl)

$(EXECS_MSGFILES_DIR)ACESWE.MSG       : $(MSGFILESDIR)SWE.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACESWE.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)SWE.MSD ACESWE.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)ACEENG.CPD           : $(MSGFILESDIR)ENG.MSG                  \
                                        $(ACEMSGFILESDIR)ACEENG.MSG            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	copy /b $(dosMSGFILESDIR)ENG.MSG+$(dosACEMSGFILESDIR)ACEENG.MSG ACEENG.CPD
	$(PROGMING_DIR)del_cr ACEENG.CPD
	cd $(OBJ_DIRsl)

$(ACEENGMSGFILE)                      : $(MSGFILESDIR)ENG.MSD                  \
                                        $(ACEEXE_OBJ_DIR)ACEENG.CPD            .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)msgwrite 1 $(MSGFILESDIR)ENG.MSD ACEENG.CPD $@
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)aceeng.obj       : $(ACEENGMSGFILE)                       .AUTODEPEND
	cd $(ACEEXE_OBJ_DIRsl)
	$(PROGMING_DIR)binobj $(ACEENGMSGFILE) aceeng.obj APPS_EXE_MESSAGES_EXTERN_ENGLISH_
	cd $(ACEMSGFILESDIR)
	$(PROGMING_DIR)msgtoc ACEENG.C $(ACEENGMSGFILE)
	cd $(OBJ_DIRsl)

$(ACEEXE_OBJ_DIR)messages.obj     : $(ACEMESSAGEDIR)messages.c             .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)output.obj       : $(ACEEXE_SRCS)output/output.c          .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)setup.obj        : $(ACEEXE_SRCS)setup/setup.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
ACEEXE_SHELL_SRCS                          = $(ACEEXE_SRCS)SHELL/#############
$(ACEEXE_OBJ_DIR)shell.obj        : $(ACEEXE_SHELL_SRCS)shell.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)sherror.obj      : $(ACEEXE_SHELL_SRCS)error/error.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)shfuncs.obj      : $(ACEEXE_SHELL_SRCS)funcs/funcs.c      .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)shhelp.obj       : $(ACEEXE_SHELL_SRCS)help/help.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)list.obj         : $(ACEEXE_SHELL_SRCS)list/list.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)options.obj      : $(ACEEXE_SHELL_SRCS)options/options.c  .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)screen.obj       : $(ACEEXE_SHELL_SRCS)screen/screen.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)select.obj       : $(ACEEXE_SHELL_SRCS)select/select.c    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

$(ACEEXE_OBJ_DIR)view.obj         : $(ACEEXE_SHELL_SRCS)view/view.c        .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)


##############################################################################
$(ACEEXE_OBJ_DIR)temp.obj         : $(ACEEXE_SRCS)temp/temp.c              .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)state.obj        : $(ACEEXE_SRCS)state/state.c            .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
$(ACEEXE_OBJ_DIR)exe.obj          : $(ACEEXE_SRCS)exe.c                    .AUTODEPEND
	SET WCC386 = $(CFLAGS)
	$(CC_DOS32)

##############################################################################
##############################################################################
APPS_ACEEXE_ARCS_OBJS             =                                       \
  $(ACEEXE_OBJ_DIR)arcarj.obj          $(ACEEXE_OBJ_DIR)arccall.obj       \
  $(ACEEXE_OBJ_DIR)arcrar.obj          $(ACEEXE_OBJ_DIR)arczip.obj


APPS_ACEEXE_COMMLINE_OBJS         =                                       \
  $(ACEEXE_OBJ_DIR)clhelp.obj          $(ACEEXE_OBJ_DIR)commline.obj

APPS_ACEEXE_SHELL_OBJS            =                                       \
  $(ACEEXE_OBJ_DIR)list.obj            $(ACEEXE_OBJ_DIR)options.obj       \
  $(ACEEXE_OBJ_DIR)screen.obj          $(ACEEXE_OBJ_DIR)select.obj        \
  $(ACEEXE_OBJ_DIR)shell.obj           $(ACEEXE_OBJ_DIR)sherror.obj       \
  $(ACEEXE_OBJ_DIR)shfuncs.obj         $(ACEEXE_OBJ_DIR)shhelp.obj        \
  $(ACEEXE_OBJ_DIR)view.obj

APPS_ACEEXE_EXT_OBJS              =                                       \
  $(ACEEXE_EXT_OBJ_DIR)acarcblk.obj    $(ACEEXE_EXT_OBJ_DIR)acecomm.obj   \
  $(ACEEXE_EXT_OBJ_DIR)acefuncs.obj    $(ACEEXE_EXT_OBJ_DIR)acerrout.obj  \
  $(ACEEXE_EXT_OBJ_DIR)acestate.obj    $(ACEEXE_EXT_OBJ_DIR)volume.obj    \
  $(ACEEXE_EXT_OBJ_DIR)acfuncs.obj     $(ACEEXE_EXT_OBJ_DIR)acmsgout.obj  \
  $(ACEEXE_EXT_OBJ_DIR)acoptns.obj     $(ACEEXE_EXT_OBJ_DIR)acvolume.obj  \
  $(ACEEXE_EXT_OBJ_DIR)add.obj         $(ACEEXE_EXT_OBJ_DIR)arcblk.obj    \
  $(ACEEXE_EXT_OBJ_DIR)arcread.obj     $(ACEEXE_EXT_OBJ_DIR)arctest.obj   \
  $(ACEEXE_EXT_OBJ_DIR)av.obj          $(ACEEXE_EXT_OBJ_DIR)comments.obj  \
  $(ACEEXE_EXT_OBJ_DIR)error.obj       $(ACEEXE_EXT_OBJ_DIR)filelist.obj  \
  $(ACEEXE_EXT_OBJ_DIR)filesort.obj    $(ACEEXE_EXT_OBJ_DIR)funcs.obj     \
  $(ACEEXE_EXT_OBJ_DIR)input.obj       $(ACEEXE_EXT_OBJ_DIR)memory.obj    \
  $(ACEEXE_EXT_OBJ_DIR)messages.obj    $(ACEEXE_EXT_OBJ_DIR)msgout.obj    \
  $(ACEEXE_EXT_OBJ_DIR)options.obj     $(ACEEXE_EXT_OBJ_DIR)output.obj    \
  $(ACEEXE_EXT_OBJ_DIR)repair.obj      $(ACEEXE_EXT_OBJ_DIR)state.obj     \
  $(ACEEXE_EXT_OBJ_DIR)temp.obj

APPS_ACEEXE_OBJS                  =                                       \
  $(APPS_ACEEXE_EXT_OBJS)                                                 \
  $(APPS_EXE_OBJS)                                                        \
  $(APPS_ACEEXE_ARCS_OBJS)             $(APPS_ACEEXE_COMMLINE_OBJS)       \
  $(APPS_ACEEXE_SHELL_OBJS)                                               \
  $(ACEEXE_OBJ_DIR)acarctst.obj        $(ACEEXE_OBJ_DIR)acefuncs.obj      \
  $(ACEEXE_OBJ_DIR)comments.obj        $(ACEEXE_OBJ_DIR)convert.obj       \
  $(ACEEXE_OBJ_DIR)filelist.obj                                           \
  $(ACEEXE_OBJ_DIR)filesort.obj        $(ACEEXE_OBJ_DIR)funcs.obj         \
  $(ACEEXE_OBJ_DIR)input.obj                                              \
  $(ACEEXE_OBJ_DIR)aceeng.obj          $(ACEEXE_OBJ_DIR)messages.obj      \
  $(ACEEXE_OBJ_DIR)options.obj                                            \
  $(ACEEXE_OBJ_DIR)output.obj          $(ACEEXE_OBJ_DIR)setup.obj         \
  $(ACEEXE_OBJ_DIR)state.obj           $(ACEEXE_OBJ_DIR)temp.obj          \
  $(ACEEXE_OBJ_DIR)exe.obj
 
APPS_ACEEXENOACL_OBJS				=										\
	$(APPS_ACEEXE_OBJS)					$(BASE_ACE_OBJ_DIR)sfxdos32.obj

APPS_ACEEXEACL_OBJS					=										\
	$(APPS_ACEEXE_OBJS)					$(BASE_ACE_OBJ_DIR)sfxacl.obj

##############################################################################
APPS_ACEEXE_DOS_OBJS              =                                       \
  $(EXE_OBJ32_DIR)inputdos.obj                                            \
  $(EXE_OBJ32_DIR)outdos32.obj                                            \
  $(EXE_OBJ32_DIR)outdosas.obj                                            \
  $(ACEEXE_OBJ_DIR)inputdos.obj

APPS_ACEEXE_NT_OBJS               =                                       \
  $(EXE_OBJ32_DIR)inputnt.obj                                             \
  $(ACEEXE_EXT_OBJ_DIR)inpnt.obj                                          \
  $(ACEEXE_OBJ_DIR)inputnt.obj

APPS_ACEEXE_OS2_OBJS              =                                       \
  $(EXE_OBJ32_DIR)inputos2.obj                                            \
  $(ACEEXE_OBJ_DIR)inputos2.obj
##############################################################################

ifndef ISWMAKE
include $(MAKE_DIR)aceexeln.mk
else
!include $(MAKE_DIR)aceexe2.mk
!include $(MAKE_DIR)aceexe32.mk
!include $(MAKE_DIR)aceexe86.mk
endif

#-----------------------------------------------------------------------------
PACKAGES_DOSACE_DIRsl               = $(PACKAGES_DIR)DOSACE
PACKAGES_DOSACE_DIR                 = $(PACKAGES_DIR)DOSACE\ #
$(PACKAGES_DIR)ACE25.EXE:    $(EXECS_DIR)ACE.EXE                         \
	                     	 $(EXECS_DIR)ACE32.EXE                        \
                             $(EXECS_DIR)ACE2.EXE                         \
                             $(EXECS_DIR)UNACE.EXE                        \
                             $(EXECS_DIR)UNACE32.EXE                      \
                             $(EXECS_DIR)UNACE2.EXE                       \
                             $(EXECS_SFXFILES_DIR)DOS32.SFX               \
                             $(EXECS_SFXFILES_DIR)WIN32CL.SFX             \
                             $(EXECS_SFXFILES_DIR)WIN32GUI.SFX            \
                             $(EXECS_SFXFILES_DIR)OS2CL.SFX               \
                             $(EXECS_MSGFILES_DIR)UNACECZC.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEDUT.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEFIN.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEGER.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEHUN.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACENWG.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEPOL.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEPOR.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACEROM.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACERUS.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACESPA.MSG            \
                             $(EXECS_MSGFILES_DIR)UNACESWE.MSG            \
                             $(EXECS_MSGFILES_DIR)ACECZC.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEDUT.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEFIN.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEGER.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEHUN.MSG              \
                             $(EXECS_MSGFILES_DIR)ACENWG.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEPOL.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEPOR.MSG              \
                             $(EXECS_MSGFILES_DIR)ACEROM.MSG              \
                             $(EXECS_MSGFILES_DIR)ACERUS.MSG              \
                             $(EXECS_MSGFILES_DIR)ACESPA.MSG              \
                             $(EXECS_MSGFILES_DIR)ACESWE.MSG              \
                             $(DOCS_DOSACE_DIR)MSGFILES.TXT               \
                             $(DOCS_DOSACE_DIR)ACE.TXT                    \
                             $(DOCS_DOSACE_DIR)WHATSNEW.TXT               \
                             $(DOCS_DOSACE_DIR)FILE_ID.DIZ                .AUTODEPEND
	del  $(PACKAGES_DOSACE_DIR)*.e*
	del  $(PACKAGES_DOSACE_DIR)SFXFILES\*.s*
	del  $(PACKAGES_DOSACE_DIR)MSGFILES\*.m*
	del  $(PACKAGES_DOSACE_DIR)MSGFILES\*.t*
	del  $(PACKAGES_DOSACE_DIR)MANUAL\*.t*
	copy $(EXECS_DIR)ACE.EXE     $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_DIR)ACE32.EXE   $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_DIR)ACE2.EXE    $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_DIR)UNACE.EXE   $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_DIR)UNACE32.EXE $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_DIR)UNACE2.EXE  $(PACKAGES_DOSACE_DIRsl)
	copy $(EXECS_SFXFILES_DIR)DOS32.SFX   $(PACKAGES_DOSACE_DIR)SFXFILES
	copy $(EXECS_SFXFILES_DIR)WIN32CL.SFX $(PACKAGES_DOSACE_DIR)SFXFILES
	copy $(EXECS_SFXFILES_DIR)WIN32GUI.SFX $(PACKAGES_DOSACE_DIR)SFXFILES
	copy $(EXECS_SFXFILES_DIR)OS2CL.SFX    $(PACKAGES_DOSACE_DIR)SFXFILES
	copy $(EXECS_MSGFILES_DIR)UNACECZC.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEDUT.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEFIN.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEGER.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEHUN.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACENWG.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEPOL.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEPOR.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEPOR.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACEROM.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACERUS.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACESPA.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)UNACESWE.MSG $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACECZC.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEDUT.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEFIN.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEGER.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEHUN.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACENWG.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEPOR.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEPOL.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEPOR.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACEROM.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACERUS.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACESPA.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACESWE.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(EXECS_MSGFILES_DIR)ACESWE.MSG   $(PACKAGES_DOSACE_DIR)MSGFILES
	copy $(DOCS_DOSACE_DIR)MSGFILES.TXT    $(PACKAGES_DOSACE_DIR)MSGFILES\readme.txt
	copy $(DOCS_DOSACE_DIR)ACE.TXT         $(PACKAGES_DOSACE_DIR)MANUAL
	copy $(DOCS_DOSACE_DIR)WHATSNEW.TXT    $(PACKAGES_DOSACE_DIRsl)
	copy $(DOCS_DOSACE_DIR)LICENCE.*       $(PACKAGES_DOSACE_DIR)LICENCE
	copy $(DOCS_DOSACE_DIR)ORDER.*         $(PACKAGES_DOSACE_DIR)ORDER
	copy $(DOCS_DOSACE_DIR)FILE_ID.DIZ $(PACKAGES_DOSACE_DIRsl)
	del  $(PACKAGES_DIR)ACE25.EXE
	cd   $(PACKAGES_DOSACE_DIRsl)
	$(PROGMING_DIR)setftime $(PACKAGES_DOSACE_DIRsl)
	$(PROGMING_DIR)ace32.exe -std a -av -c2 -c2e- -sfx -d1024 -m5 -r ..\ACE25
	cd   $(OBJ_DIRsl)

#-----------------------------------------------------------------------------
PACKAGES_MSGFILES_DIRsl               = $(PACKAGES_DIR)MSGFILES
PACKAGES_MSGFILES_DIR                 = $(PACKAGES_DIR)MSGFILES\ #
SFXDDIR = $(BASE_SRCS)ACE/SFX/				 	 #
dosSFXDDIR = $(dosBASE_SRCS)ACE\SFX\				 #
$(PACKAGES_DIR)MSGFILES.EXE: $(PACKAGES_DIR)ACE25.EXE                     \
                             $(PROGMING_DIR)MSGWRITE.EXE                  \
                             $(PROGMING_DIR)DEL_CR.EXE                    \
                             $(ACEEXE_OBJ_DIR)ACEBRU.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACECZC.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEDUT.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEENG.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEFIN.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEFRE.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEGER.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEGRK.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEHUN.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACENWG.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEPOL.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEPOR.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACEROM.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACERUS.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACESPA.CPD                  \
                             $(ACEEXE_OBJ_DIR)ACESWE.CPD                  \
                             $(MSGFILESDIR)BRU.MSD                        \
                             $(MSGFILESDIR)CZC.MSD                        \
                             $(MSGFILESDIR)DUT.MSD                        \
                             $(MSGFILESDIR)ENG.MSD                        \
                             $(MSGFILESDIR)FIN.MSD                        \
                             $(MSGFILESDIR)FRE.MSD                        \
                             $(MSGFILESDIR)GER.MSD                        \
                             $(MSGFILESDIR)GRK.MSD                        \
                             $(MSGFILESDIR)HUN.MSD                        \
                             $(MSGFILESDIR)NWG.MSD                        \
                             $(MSGFILESDIR)POL.MSD                        \
                             $(MSGFILESDIR)POR.MSD                        \
                             $(MSGFILESDIR)ROM.MSD                        \
                             $(MSGFILESDIR)RUS.MSD                        \
                             $(MSGFILESDIR)SPA.MSD                        \
                             $(MSGFILESDIR)SWE.MSD                        \
                             $(ACEMSGFILESDIR)BRU.BAT                     \
                             $(ACEMSGFILESDIR)CZC.BAT                     \
                             $(ACEMSGFILESDIR)DUT.BAT                     \
                             $(ACEMSGFILESDIR)ENG.BAT                     \
                             $(ACEMSGFILESDIR)FIN.BAT                     \
                             $(ACEMSGFILESDIR)FRE.BAT                     \
                             $(ACEMSGFILESDIR)GER.BAT                     \
                             $(ACEMSGFILESDIR)GRK.BAT                     \
                             $(ACEMSGFILESDIR)HUN.BAT                     \
                             $(ACEMSGFILESDIR)NWG.BAT                     \
                             $(ACEMSGFILESDIR)POL.BAT                     \
                             $(ACEMSGFILESDIR)POR.BAT                     \
                             $(ACEMSGFILESDIR)ROM.BAT                     \
                             $(ACEMSGFILESDIR)RUS.BAT                     \
                             $(ACEMSGFILESDIR)SPA.BAT                     \
                             $(ACEMSGFILESDIR)SWE.BAT                     \
                             $(DOCS_DOSACE_DIR)ACE.TXT                    \
                             $(DOCS_DOSACE_DIR)MSGEDIT.TXT                \
                             $(SFXDDIR)DOS32.SFD                          \
                             $(SFXDDIR)OS2CL.SFD                          \
                             $(SFXDDIR)WIN32CL.SFD                        \
                             $(SFXDDIR)WIN32GUI.SFD                       .AUTODEPEND
	del  $(PACKAGES_MSGFILES_DIR)*.e*
	del  $(PACKAGES_MSGFILES_DIR)*.m*
	del  $(PACKAGES_MSGFILES_DIR)*.d*
	del  $(PACKAGES_MSGFILES_DIR)SFXFILES\*.s*
	del  $(PACKAGES_MSGFILES_DIR)MSGFILES\*.m*
	del  $(PACKAGES_MSGFILES_DIR)MSGFILES\*.t*
	del  $(PACKAGES_MSGFILES_DIR)MANUAL\*.t*
	del  $(PACKAGES_MSGFILES_DIR)MSGEDIT\*.e*
	del  $(PACKAGES_MSGFILES_DIR)MSGEDIT\*.m*
	del  $(PACKAGES_MSGFILES_DIR)MSGEDIT\*.b*
	del  $(PACKAGES_MSGFILES_DIR)MSGEDIT\*.s*
	$(PROGMING_DIR)ace32 x -o $(PACKAGES_DIR)ACE25.EXE $(PACKAGES_MSGFILES_DIR)
	copy $(PROGMING_DIR)MSGWRITE.EXE    $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(PROGMING_DIR)DEL_CR.EXE      $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(dosACEEXE_OBJ_DIR)*.CPD      $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(dosMSGFILESDIR)*.MSD            $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(dosACEMSGFILESDIR)*.BAT      $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(dosSFXDDIR)*.SFD             $(PACKAGES_MSGFILES_DIR)MSGEDIT
	copy $(DOCS_DOSACE_DIR)MSGEDIT.TXT  $(PACKAGES_MSGFILES_DIR)MSGEDIT\readme.txt
	copy $(DOCS_DOSACE_DIR)ACE.TXT      $(PACKAGES_DOSACE_DIR)MANUAL
	del  $(PACKAGES_DIR)MSGFILES.EXE
	cd   $(PACKAGES_MSGFILES_DIRsl)
	$(PROGMING_DIR)setftime $(dosPACKAGES_MSGFILES_DIRsl)
	$(PROGMING_DIR)ace32.exe a -av -c2 -c2e- -sfx -d1024 -m5 -r ..\MSGFILES
	cd   $(OBJ_DIRsl)
