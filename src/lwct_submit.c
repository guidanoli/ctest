/*
 * lwct_submit.c, v.2.1.0
 *
 * Test submission
 */

#include <stdlib.h>
#include "lwct.h"
#include "lwct_assert.h"
#include "lwct_submit.h"
#include "lwct_state.h"

void lwct_submit_test(void (*func)(lwct_state *S))
{
	if (!func) return;
	lwct_state *S = lwct_create_state(LWCTL_STATE_TYPE_TEST);
	if (!S) return;
	(*func)(S);
	lwct_show_log(S);
	lwct_destroy_state(S);
}

void lwct_submit_batch(void (*func)(lwct_state *S, unsigned long rep),
			unsigned long repetition_cnt)
{
	if (!func || repetition_cnt <= 0) return;
	lwct_state *S = lwct_create_state(LWCTL_STATE_TYPE_BATCH);
	if (!S) return;
	lwct_set_repetition_total_cnt(S, repetition_cnt);
	for (unsigned long i = 1; i <= repetition_cnt; ++i) {
		lwct_inc_repetition_cnt(S);
		(*func)(S, i);
	}
	lwct_show_log(S);
	lwct_destroy_state(S);
}
