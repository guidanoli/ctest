/*
 * lwct_submit.h, v.1.0.1
 *
 * Test submission
 */

#ifndef LWCT_SUBMIT_H
#define LWCT_SUBMIT_H

#include "lwct.h"

/*
 * Functions for test submission
 */
LWCTL_API void lwct_submit_test(void (*func)(lwct_state *S));

LWCTL_API void lwct_submit_batch(void (*func)(lwct_state *S,
                                unsigned long repetition),
                                unsigned long repetition_cnt);

#endif
