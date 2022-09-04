#define INCL_BASE_ACESTRUC
#define INCL_BASE_ALL

#include "base/includes.h"

// all.h
PCHAR const ARCHIVEEXTENSIONS[5] = {"ACE", "RAR", "ZIP", "ARJ", "EXE"};

// acestruc.h
PCHAR const BASE_ACESTRUC_ACESIGN
  #ifdef USELIMITED
        = "USELTD";
  #else
        = "**ACE**";
  #endif

PCHAR const BASE_ACESTRUC_EXTENSION
  #ifdef USELIMITED
        = ".acl";
  #else
        = ".ace";
  #endif

INT const BASE_ACESTRUC_IsACL
  #ifdef USELIMITED
        = 1;
  #else
        = 0;
  #endif
