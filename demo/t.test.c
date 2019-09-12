/*
 * t.batch.c, v.1.0.0
 *
 * Test demo
 */

#include "lwct.h"

void err(lwct_state *S)
{
	lwct_assert(S, 1);
	lwct_assert(S, 0);
}

void ok(lwct_state *S)
{
	lwct_assert(S, 1);
	lwct_assert(S, 2);
}

int main(void)
{
	lwct_submit_test(err);
	lwct_submit_test(ok);
}
