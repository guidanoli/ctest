/*
 * Test state
 */

#include <stdlib.h>
#include "lwct.h"

struct lwct_state *lwct_init()
{
        struct lwct_state *state = malloc(sizeof(struct lwct_state));
        if (!state) return NULL;
        state->current_file = __FILE__;
        state->n_tests = 0;
        state->n_failed = 0;
        return state;
}

void lwct_destroy(struct lwct_state *state)
{
        free(state);
}
