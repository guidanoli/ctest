/*
 * lwct_assert.h, v.1.0.1
 *
 * Assertion and log utilities
 */

#ifndef LWCT_ASSERT_H
#define LWCT_ASSERT_H

#include "lwct.h"

LWCTL_API void _lwct_fatal_assert(lwct_state *S, const char bool,
			const char *label, const char *file,
			const char *func, const unsigned int line);

LWCTL_API void _lwct_assert(lwct_state *S, const char bool,
			const char *label, const char *file,
			const char *func, const unsigned int line);

LWCTL_FUNC void lwct_show_log(lwct_state *S);

#endif
