/*
 * lwct_debug.c, v.0.1.0
 * 
 * Debug
 */

#include "lwct_debug.h"
#include "lwct_format.h"
#include "lwct_state.h"
#include "lwct_deconstructor.h"

/*
 * CTPRINT Tag
 */
#define DEBUG_TAG BLUE, "DEBUG"

lwct_debug_ret lwct_debug_counters(struct lwct_state *S)
{
	if (!S)
		return LWCT_DEBUG_PARAM;
		
	CTPRINT(DEBUG_TAG, "Assertions: %ul\n", lwct_get_assertion_cnt(S));
	CTPRINT(DEBUG_TAG, "Errors: %ul\n", lwct_get_error_cnt(S));
	
	if (lwct_get_type(S) == LWCTL_STATE_TYPE_BATCH)
		CTPRINT(DEBUG_TAG, "Repetition %ul out of %ul\n",
		lwct_get_repetition_cnt(S), lwct_get_repetition_total_cnt(S));
	
	return LWCT_DEBUG_OK;
}

lwct_debug_ret lwct_debug_destructors(lwct_state *S)
{
	if (!S)
		return LWCT_DEBUG_PARAM;
	
	lwct_deconstructor *dc = lwct_get_deconstructor(S);
	if (!dc)
		return LWCT_DEBUG_CORRUPTED;
	
	
}