
  // Lightweight C test module interface
  // This file is under the GPL-3.0 licence
  // Read the LICENSE file for the full text
  // Guilherme Dantas

  #ifndef LWCT_H
  #define LWCT_H

  ///////////////////////
  // MACRO DEFINITIONS //
  ///////////////////////

  /**
  * Fatal assert - similar to assert but halts if statement is false
  *   statement - boolean value to be asserted
  * > (to stdout) error message + test log, nothing
  * [!] if statement is false, the program is terminated.
  */
  #define fatal_assert(statement) \
                                  \
          LWCTL_FatalAssert(      \
            statement,            \
            #statement,           \
            __FILE__,             \
            __func__,             \
            __LINE__              \
          )                       \

  /**
  * Assert - logs to screen whether statement is true of false
  *   statement - boolean value to be asserted
  * > (to stdout) error message, nothing
  */
  #define assert(statement)       \
                                  \
          LWCTL_Assert(           \
            statement,            \
            #statement,           \
            __FILE__,             \
            __func__,             \
            __LINE__              \
          )                       \

  /**
  * Show Log - prints to screen all tests run (total/errors)
  * > (to stdout) test log
  */
  #define show_log() LWCTL_ShowLog()

  /////////////////////////
  // FUNCTION SIGNATURES //
  /////////////////////////

  /**
  * Asserts if a given boolean value is false and if
  * so, terminates the program. Useful when an unexpected
  * error occurrs (e.g. error in dynamic memory allocation)
  *   boolean - if false, error is thrown
  *   label - statement string
  *   func - calling function name
  *   line - statement line in code
  * > (to stdout) error message + test log, nothing
  * [!] if boolean is false, the program is terminated.
  */
  void LWCTL_FatalAssert (
                        \
    const char boolean, \
    const char * label, \
    const char * file,  \
    const char * func,  \
    const line          \
                        \
  );

  /**
  * Asserts statement, displaying it and the line it's at if false
  *   boolean - if false, error is thrown
  *   label - statement string
  *   func - calling function name
  *   line - statement line in code
  * > (to stdout) error message, nothing
  */
  void LWCTL_Assert (
                        \
    const char boolean, \
    const char * label, \
    const char * file,  \
    const char * func,  \
    const line          \
                        \
  );

  /**
  * Ouputs information stored in counters at a given time
  * > (to stdout) test log
  */
  void LWCTL_ShowLog ();

  #endif
