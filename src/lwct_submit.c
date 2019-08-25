/*
 * lwct_submit.c, v.2.0.0
 *
 * Test submission
 */

#include <stdlib.h>
#include "lwct.h"
#include "lwct_submit.h"
#include "lwct_state.h"

void lwct_submit_test(void (*func)(struct lwct_state *S))
{
        if (!func) return;
        struct lwct_state *S = lwct_init();
        if (!S) return;
        (*func)(S);
        lwct_show_log(S);
        lwct_destroy(S);
}

void lwct_submit_batch(void (*func)(lwct_state *S, unsigned long rep),
                        unsigned long repetition_cnt)
{
        if (!func || repetition_cnt <= 0) return;
        struct lwct_state *S = lwct_init();
        if (!S) return;
        for (unsigned long i = 0; i < repetition_cnt; ++i)
                (*func)(S, i);
        lwct_show_log(S);
        lwct_destroy(S);
}
