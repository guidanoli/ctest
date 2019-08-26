/*
 * lwct_state.h, v.1.0.1
 *
 * Test state header
 */

#ifndef LWCT_STATE_H
#define LWCT_STATE_H

#include "lwct.h"

/*
* Functions for test state lifecycle
*/
LWCTL_API lwct_state *lwct_create_state();

LWCTL_API void lwct_destroy_state(lwct_state *S);

/*
 * Functions for internal state manipulation
 */
LWCTL_FUNC void lwct_update_file(lwct_state *S, const char *file);

LWCTL_FUNC void lwct_inc_assertion_cnt(lwct_state *S);

LWCTL_FUNC void lwct_inc_error_cnt(lwct_state *S);

/*
 * Functions for access of state fields
 */
LWCTL_FUNC unsigned long lwct_get_assertion_cnt(lwct_state *S);

LWCTL_FUNC unsigned long lwct_get_error_cnt(lwct_state *S);

LWCTL_FUNC char * lwct_get_current_file(lwct_state *S);

#endif
