
  // Lightweight C test module implementation
  // This file is under the GPL-3.0 licence
  // Read the LICENSE file for the full text
  // Guilherme Dantas

  #include <stdio.h>
  #include <string.h>
  #include "lwct.h"
  #include "lwct_colours.h"

  #define ERROR_TAG "ERROR",RED
  #define LOG_TAG "LOG",YELLOW
  #define SUCCESS_TAG "SUCCESS",GREEN

  /********************/
  /* Global variables */
  /********************/

  static unsigned long n_tests = 0;   // Number of asserts
  static unsigned long n_failed = 0;  // Number of failed asserts

  /*********************/
  /* Private functions */
  /*********************/

  static inline void print_tag (const char * tag, const char * color);

  /**********************/
  /* Exported functions */
  /**********************/

  void LWCTL_FatalAssert (const char boolean, const char * label, const line)
  {
    LWCTL_Assert(boolean, label, line);
    if (boolean) return;
    print_tag(ERROR_TAG);
    printf("The program will be aborted due to a fatal error.\n");
    LWCTL_ShowLog();
    exit(1);
  }

  void LWCTL_ShowLog ()
  {
    print_tag(LOG_TAG);
    printf("%lu asserts.\n", n_tests);
    print_tag(LOG_TAG);
    if ( n_failed == 0 ) printf("No errors found.\n");
    else printf("%lu error%s found.\n", n_failed, n_failed==1 ? "" : "s");
  }

  void LWCTL_Assert (const char boolean, const char * label, const line)
  {
    if (boolean)
    {
      print_tag(SUCCESS_TAG);
      printf("\"%s\"\n", label);
    }
    else
    {
      print_tag(ERROR_TAG);
      printf("\"%s\" failed at line %d.\n", label, line);
      ++n_failed;
    }
    ++n_tests;
  }

  /************************************/
  /* Private functions implementation */
  /************************************/

  static inline void print_tag (const char * tag, const char * color)
  {
    printf("%s[%s%s%s] ", DEFAULT_COLOUR, \
                          color, \
                          tag, \
                          DEFAULT_COLOUR);
  }
