
  /*
  ** Lightweight C test Library demo
  ** This file is under the GPL-3.0 licence
  ** Read the LICENSE file for the full text
  ** Guilherme Dantas
  */

  int main (void) {
    #ifdef LWCT_RENAME
      lwct_fatal_assert(1);
      lwct_show_log();
    #else
      fatal_assert(1);
      show_log();
    #endif
  }
