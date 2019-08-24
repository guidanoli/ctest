/*
 * lwct_submit.c
 *
 * Test submission
 */

#include <stdlib.h>
#include "lwct.h"

void lwct_submit_test(void (*func)(struct lwct_state *state))
{
        if (!func) return;
        struct lwct_state *state = lwct_init();
        if (!state) return;
        (*func)(state);
        lwct_show_log(state);
        lwct_destroy(state);
}

void lwct_submit_batch(void (*func)(struct lwct_state *state,
                        struct lwct_submission *subinfo),
                        unsigned long n_total)
{
        if (!func || n_total <= 0) return;
        struct lwct_state *state = lwct_init();
        if (!state) return;
        struct lwct_submission *info = malloc(sizeof(struct lwct_submission));
        if (!info) return;
        info->n_total = n_total;
        info->n_current = 0;
        for (unsigned long i = 0; i < n_total; ++i) {
                (*func)(state, info);
                ++(info->n_current);
        }
        lwct_show_log(state);
        lwct_destroy(state);
        free(info);
}
