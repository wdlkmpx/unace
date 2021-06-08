/**************************************************************************/
/*                                                                        */
/* packprag.h: declares pragmas for alignment settings                    */
/*                                                                        */
/**************************************************************************/

#ifdef SETALIGNMENT
  #undef SETALIGNMENT

  #if ( defined(__MACOSX__) || defined(__sun__) )
    #define RESTOREALIGNMENTOFF
    #pragma pack(4)
  #elif defined(__WATCOMC__) || defined(__GCC__) || defined(__MWERKS__) && (__dest_os == __win32_os)
    #pragma pack(push, 4)
  #endif

  #if defined(__MWERKS__) && (__dest_os == __mac_os)
    #if !(__option(align_array_members))
      #define RESTOREALIGNMENTOFF
      #pragma align_array_members on
    #endif
  #endif

#endif

#ifdef SETNOALIGNMENT
  #undef SETNOALIGNMENT

  #if defined( __MACOSX__ ) || defined( __sun__ )
    #define RESTOREALIGNMENTON
    #pragma pack(1)
  #elif defined(__WATCOMC__) || defined(__GCC__) || defined(__MWERKS__) && (__dest_os == __win32_os)
    #pragma pack(push, 1)
  #endif

  #if defined(__MWERKS__) && (__dest_os == __mac_os)
    #if (__option(align_array_members))
      #define RESTOREALIGNMENTON
      #pragma align_array_members off
    #endif
  #endif

#endif

#ifdef RESTOREALIGNMENT
  #undef RESTOREALIGNMENT
  #if defined(__MACOSX__) || defined(__sun__)
    #ifdef RESTOREALIGNMENTOFF
      #undef RESTOREALIGNMENTOFF
      #pragma pack(1)
    #endif
    #ifdef RESTOREALIGNMENTON
      #undef RESTOREALIGNMENTON
      #pragma pack(4)
    #endif
  #elif defined(__WATCOMC__) || defined(__GCC__) || defined(__MWERKS__) && (__dest_os == __win32_os)
    #pragma pack(pop)
  #endif

  #if defined(__MWERKS__) && (__dest_os == __mac_os)
    #ifdef RESTOREALIGNMENTOFF
      #undef RESTOREALIGNMENTOFF
      #pragma align_array_members off
    #endif
    #ifdef RESTOREALIGNMENTON
      #undef RESTOREALIGNMENTON
      #pragma align_array_members on
    #endif
  #endif

#endif
