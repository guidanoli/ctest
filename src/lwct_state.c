/*
 * lwct_state.c, v.1.0.0
 *
 * Test state
 */

#include <stdlib.h>
#include <string.h>
#include "lwct.h"
#include "lwct_state.h"

/*
 * Test state data
 *
 * @current_file        name of the last file that called an assertion
 * @assertion_cnt       number of assertions
 * @error_cnt           number of failed assertions
 */
struct lwct_state {
        char *current_file;
        unsigned long assertion_cnt;
        unsigned long error_cnt;
};

struct lwct_state *lwct_create_state()
{
        struct lwct_state *S = malloc(sizeof(struct lwct_state));
        if (!S)
                return NULL;
        S->current_file = __FILE__;
        S->assertion_cnt = 0;
        S->error_cnt = 0;
        return S;
}

void lwct_destroy_state(struct lwct_state *S)
{
        free(S);
}

void lwct_update_file(struct lwct_state *S, const char *file)
{
        if (strcmp(S->current_file, file) != 0)
                S->current_file = file;
}

void lwct_inc_assertion_cnt(struct lwct_state *S)
{
        ++(S->assertion_cnt);
}

void lwct_inc_error_cnt(struct lwct_state *S)
{
        ++(S->error_cnt);
}

unsigned long lwct_get_assertion_cnt(struct lwct_state *S)
{
        return S->assertion_cnt;
}

unsigned long lwct_get_error_cnt(struct lwct_state *S)
{
        return S->error_cnt;
}

char * lwct_get_current_file(lwct_state *S)
{
        return S->current_file;
}
