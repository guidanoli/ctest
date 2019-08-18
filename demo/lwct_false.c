
  /*
  ** Lightweight C test Library demo
  ** This file is under the GPL-3.0 licence
  ** Read the LICENSE file for the full text
  ** Guilherme Dantas
  */

  int main (void) {
    #ifdef LWCT_RENAME
      lwct_assert(0);
      lwct_show_log();
    #else
      assert(0);
      show_log();
    #endif
  }
