/*
 * lwct_state.c, v.1.0.0
 *
 * Test state
 */

#include <stdlib.h>
#include "lwct.h"
#include "lwct_state.h"

struct lwct_state *lwct_init()
{
        struct lwct_state *S = malloc(sizeof(struct lwct_state));
        if (!S)
                return NULL;
        S->current_file = __FILE__;
        S->assertion_cnt = 0;
        S->error_cnt = 0;
        return S;
}

void lwct_destroy(struct lwct_state *S)
{
        free(S);
}
