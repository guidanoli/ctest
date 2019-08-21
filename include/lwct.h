/*
 * Assertion and log utilities
 */

#ifndef LWCT_H
#define LWCT_H

#define lwct_fatal_assert(statement) \
        LWCT_FatalAssert(statement, #statement, __FILE__, __func__, __LINE__)

#define lwct_assert(statement) \
        LWCT_Assert(statement, #statement, __FILE__, __func__, __LINE__)

#define lwct_show_log() LWCT_ShowLog()

void LWCT_FatalAssert(const char boolean, const char * label,
                      const char * file, const char * func, const line);

void LWCT_Assert(const char boolean, const char * label,
                 const char * file, const char * func, const line);

void LWCT_ShowLog();

#endif
