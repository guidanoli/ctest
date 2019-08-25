/*
 * lwct_state.h, v.1.0.1
 *
 * Test state header
 */

#ifndef LWCT_STATE_H
#define LWCT_STATE_H

#include "lwct.h"

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

/*
* Functions for test state lifecycle
*/
LWCTL_API lwct_state *lwct_init();

LWCTL_API void lwct_destroy(lwct_state *S);

#endif
