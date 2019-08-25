/*
 * lwct.h, v.3.0.0
 *
 * Lightweight C Test Library
 */

#ifndef LWCT_H
#define LWCT_H

#include "lwct_conf.h"

/*
 * Macros for assertion and log display
 */
#define lwct_fatal_assert(state, bool) \
        _lwct_fatal_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

#define lwct_assert(state, bool) \
        _lwct_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

/*
 * Testing enviroment state
 */
typedef struct lwct_state lwct_state;

/*
 * Functions for test submission work much like observers,
 * and receive the following informations:
 * @S           test enviroment state
 * @repetition  index of repetition
 */
LWCTL_API void lwct_submit_test(void (*func)(lwct_state *S));

LWCTL_API void lwct_submit_batch(void (*func)(lwct_state *S,
                                unsigned long repetition),
                                unsigned long repetition_cnt);

/*
 * Functions for assertion and log display
 */
LWCTL_API void _lwct_fatal_assert(lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

LWCTL_API void _lwct_assert(lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

#endif
