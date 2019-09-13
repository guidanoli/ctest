/*
 * t.dbg.c, v.0.1.0
 *
 * Debug test
 */

#include "lwct.h"
#include "lwct_debug.h"

#define NULL (void *) 0

void deconstructor(void *p) {
	// nothing
}

void CounterTest(lwct_state *S)
{
	lwct_assert(S, 1);
	lwct_assert(S, 0);
	lwct_assert(S, lwct_debug_counters(NULL) == LWCT_DEBUG_PARAM);
	lwct_assert(S, lwct_debug_counters(S) == LWCT_DEBUG_OK);
}

void CounterBatch(lwct_state *S, unsigned long n)
{
	lwct_assert(S, 1);
	lwct_assert(S, 0);
	lwct_assert(S, lwct_debug_counters(NULL) == LWCT_DEBUG_PARAM);
	lwct_assert(S, lwct_debug_counters(S) == LWCT_DEBUG_OK);
}

void DeconstructorTest(lwct_state *S)
{
	lwct_submit_desconstructor(S, deconstructor, S);
	lwct_assert(S, lwct_debug_deconstructors(NULL) == LWCT_DEBUG_PARAM);
	lwct_assert(S, lwct_debug_deconstructors(S) == LWCT_DEBUG_OK);
}

int main(void)
{
	lwct_submit_test(CounterTest);
	lwct_submit_batch(CounterBatch, 3);
	lwct_submit_test(DeconstructorTest);
	return 0;
}
