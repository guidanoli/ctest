/*
 * t.batch.c, v.1.0.0
 *
 * Batch demo
 */

#include "lwct.h"

int is_prime(unsigned long p)
{
        if (p < 2) return 0;
        for (int i = 2; i <= p/2; i++)
                if (p % i == 0)
                        return 0;
        return 1;
}

void tester(lwct_state *S, unsigned long n)
{
        lwct_assert(S, is_prime(n));
}

int main(void)
{
        lwct_submit_batch(tester, 10);
}
