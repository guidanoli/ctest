
  /*
  ** Lightweight C test module implementation
  ** This file is under the GPL-3.0 licence
  ** Read the LICENSE file for the full text
  ** Guilherme Dantas
  */

  #include <stdio.h>
  #include <string.h>
  #include "lwct.h"
  #include "lwct_colours.h"

  //      MACRO       LABEL       COLOR
  #define ERROR_TAG   "ERROR",    RED
  #define LOG_TAG     "LOG",      YELLOW
  #define SUCCESS_TAG "SUCCESS",  GREEN

  #define PLURAL(q) q==1 ? "" : "s"

  //////////////////////
  // GLOBAL VARIABLES //
  //////////////////////

  static char * current_file = __FILE__;
  static unsigned long n_tests = 0;   // Number of asserts
  static unsigned long n_failed = 0;  // Number of failed asserts

  ///////////////////////
  // PRIVATE FUNCTIONS //
  ///////////////////////

  static inline void print_tag (
                        \
    const char * tag,   \
    const char * color  \
                        \
  );

  ////////////////////////
  // EXPORTED FUNCTIONS //
  ////////////////////////

  void LWCT_FatalAssert (
                        \
    const char boolean, \
    const char * label, \
    const char * file,  \
    const char * func,  \
    const line          \
                        \
  )
  {
    LWCT_Assert(boolean, label, file, func, line);
    if ( boolean ) return;
    print_tag(ERROR_TAG);
    printf("The program will be aborted due to a fatal error.\n");
    LWCT_ShowLog();
    exit(1);
  }

  void LWCT_Assert (
                        \
    const char boolean, \
    const char * label, \
    const char * file,  \
    const char * func,  \
    const line          \
                        \
  )
  {
    if ( strcmp(current_file, file) != 0 )
    {
      current_file = file;
      printf(
        "%sOn file %s%s%s\n",   \
        WHITE,                  \
        ULINED_WHITE,           \
        file,                   \
        WHITE                   \
      );
    }
    if ( boolean )
    {
      print_tag(SUCCESS_TAG);
      printf("\"%s\"\n", label);
    }
    else
    {
      print_tag(ERROR_TAG);
      printf("\"%s\" failed in %s:%d\n", label, func, line);
      ++n_failed;
    }
    ++n_tests;
  }

  void LWCT_ShowLog ()
  {
    print_tag(LOG_TAG);
    printf("%lu asserts.\n", n_tests);
    print_tag(LOG_TAG);
    if ( n_failed == 0 ) printf("No errors found.\n");
    else printf("%lu error%s found.\n", n_failed, PLURAL(n_failed));
  }

  //////////////////////////////////////
  // PRIVATE FUNCTIONS IMPLEMENTATION //
  //////////////////////////////////////

  static inline void print_tag (
                        \
    const char * tag,   \
    const char * color  \
                        \
  )
  {
    printf(
      "%s[%s%s%s] ",  \
      WHITE,          \
      color,          \
      tag,            \
      WHITE           \
    );
  }
