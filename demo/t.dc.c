/*
 * t.dc.c
 * 
 * Deconstructor demo
 */

#include "lwct.h"

#define MAGIC 12345

void callback(void *p)
{
	puts("Callback called.");
	lwct_assert((lwct_state *) p, 1);
}

void deconstruct(lwct_state *S)
{
	lwct_submit_desconstructor(S, callback, S);
	lwct_fatal_assert(S, 0); // fails
}

int main(void)
{
	lwct_submit_test(deconstruct);
}
