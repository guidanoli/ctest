/*
 * lwct_state.h, v.1.0.2
 *
 * Test state header
 */

#ifndef LWCT_STATE_H
#define LWCT_STATE_H

#include "lwct.h"

/*
 * Test type enumeration
 */
typedef enum {

        LWCTL_STATE_TYPE_TEST,
        /* Single instance test */

        LWCTL_STATE_TYPE_BATCH,
        /* Multiple instances batch */

} lwct_state_type;

/*
* Functions for test state lifecycle
*/
LWCTL_API lwct_state *lwct_create_state(lwct_state_type type);

LWCTL_API void lwct_destroy_state(lwct_state *S);

/*
 * Functions for internal state manipulation
 */
LWCTL_FUNC void lwct_update_file(lwct_state *S, const char *file);

LWCTL_FUNC void lwct_inc_assertion_cnt(lwct_state *S);

LWCTL_FUNC void lwct_inc_error_cnt(lwct_state *S);

LWCTL_FUNC void lwct_inc_repetition_cnt(lwct_state *S);

LWCTL_FUNC void lwct_set_repetition_total_cnt(lwct_state *S, unsigned long cnt);

/*
 * Functions for access of state fields
 */
LWCTL_FUNC lwct_state_type lwct_get_type(lwct_state *S);

LWCTL_FUNC unsigned long lwct_get_assertion_cnt(lwct_state *S);

LWCTL_FUNC unsigned long lwct_get_error_cnt(lwct_state *S);

LWCTL_FUNC char *lwct_get_current_file(lwct_state *S);

LWCTL_FUNC unsigned long lwct_get_repetition_cnt(lwct_state *S);

LWCTL_FUNC unsigned long lwct_get_repetition_total_cnt(lwct_state *S);

#endif
