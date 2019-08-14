
  // Lightweight C test module interface
  // This file is under the GPL-3.0 licence
  // Read the LICENSE file for the full text
  // Guilherme Dantas

  #ifndef LWCT_H
  #define LWCT_H

  // Fatal assert macro
  // statement - boolean value to be evaluated
  #define fatal_assert(statement) LWCTL_FatalAssert(statement,#statement,__LINE__)

  // Assert macro
  // statement - boolean value to be evaluated
  #define assert(statement) LWCTL_Assert(statement,#statement,__LINE__)

  // Show log macro
  #define show_log() LWCTL_ShowLog()

  // Aborts test, displaying the statement that caused it and line,
  // and, additionally, shows log.
  // boolean - if false, error is thrown
  // label - statement string
  // line - statement line in code
  // > (to stderr) error message + test log, nothing
  // [!] if boolean is false, the program is exited.
  void LWCTL_FatalAssert (const char boolean, const char * label, const line);

  // Asserts statement, displaying it and the line it's at if false
  // boolean - if false, error is thrown
  // label - statement string
  // line - statement line in code
  // > (to stderr) error message, nothing
  void LWCTL_Assert (const char boolean, const char * label, const line);

  // Ouputs information stored in counters at a given time
  // > (to stdout) test log
  void LWCTL_ShowLog ();

  #endif
