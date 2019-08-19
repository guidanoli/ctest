
  /*
  ** Lightweight C test Library demo config check
  ** This file is under the GPL-3.0 licence
  ** Read the LICENSE file for the full text
  ** Guilherme Dantas
  */

  #include "lwct_colours.h"

  /*
  ** Macros for checking if sth is defined
  */

  #define DEFSTR "defined"
  #define UNDEFSTR "undefined"

  #define CKDEF__(item) "" #item

  #define CKDEF_(sx, x, colour)             \
  puts(MAGENTA sx ": " colour x DEFCOLOUR)  \

  #define CKDEF(x)                          \
  do {                                      \
    if(strcmp("" #x, CKDEF__(x)))           \
      CKDEF_(#x, DEFSTR, GREEN);            \
    else                                    \
      CKDEF_(#x, UNDEFSTR, RED);            \
  } while(0)                                \

  int main (void) {
    CKDEF(LWCT_RENAME);
  }
