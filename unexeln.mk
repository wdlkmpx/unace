APPS_UNACEEXE_NT_OBJS               =                                       \
  $(BASE_NT_OBJS)                                                           \
  $(EXEEXT_NT_OBJS)                                                         \
  $(EXE_OBJ32_DIR)inputnt.obj                                               \
  $(UNACEEXE_EXT_OBJ_DIR)inpnt.obj        $(UNACEEXE_OBJ_DIR)exent.obj


#=============================================================================
$(EXECS_DIR)UNACE32.EXE : 						    \
  $(BASE_ALL_OBJS)                        $(BASE_UNACE_OBJS)                \
  $(APPS_UNACEEXE_OBJS)                   $(APPS_UNACEEXE_NT_OBJS)          \
  $(RTL_NT_FILES)                         $(UNACEEXE_SRCS)version.rc        .AUTODEPEND
	set LINKCMD = $(LINKFLAGS) SYS nt_nolib name $@ $(RTL_NT_EXE_CMD)
#        set LINKCMD = $(LINKFLAGS) SYS nt name $@ #op m=h:/unace32.map
	set OBJS1 = file {$(BASE_ALL_OBJS)}
	set OBJS2 = file {$(BASE_UNACE_EXT_OBJS)}
	set OBJS3 = file {$(APPS_UNACEEXE_OBJS)}
	set OBJS4 = file {$(APPS_UNACEEXE_NT_OBJS)}
	$(PROGMING_DIR)wlink110 @LINKCMD @OBJS1 @OBJS2 @OBJS3 @OBJS4
	$(PROGMING_DIR)wrc $(UNACEEXE_SRCS)version.rc -bt=nt -fo=$(UNACEEXE_OBJ_DIR)version  $@
	$(PROGMING_DIR)upx -9 $@
	set LINKCMD =
	set OBJS1 =
	set OBJS2 =
	set OBJS3 =
	set OBJS4 =

$(EXECS_SFXFILES_DIR)WIN32CL.SFX :                                          \
  $(SFXDDIR)WIN32CL.SFD                   $(EXECS_DIR)UNACE32.EXE           .AUTODEPEND
	$(PROGMING_DIR)sfxwrite $(SFXDDIR)WIN32CL.SFD $(EXECS_DIR)UNACE32.EXE $@

$(EXECS_SFXFILES_DIR)WIN32GUI.SFX :                                         \
  $(SFXDDIR)WIN32GUI.SFD                  $(SFXDDIR)WIN32GUI.EXE            .AUTODEPEND
	$(PROGMING_DIR)sfxwrite $(SFXDDIR)WIN32GUI.SFD $(SFXDDIR)WIN32GUI.EXE $@
