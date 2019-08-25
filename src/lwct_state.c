/*
 * lwct_state.c
 *
 * Test state
 */

#include <stdlib.h>
#include "lwct.h"
#include "lwct_state.h"

struct lwct_state *lwct_init()
{
        struct lwct_state *state = malloc(sizeof(struct lwct_state));
        if (!state)
                return NULL;
        state->current_file = __FILE__;
        state->assertion_cnt = 0;
        state->error_cnt = 0;
        return state;
}

void lwct_destroy(struct lwct_state *state)
{
        free(state);
}
