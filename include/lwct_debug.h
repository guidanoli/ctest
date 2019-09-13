/*
 * lwct_debug.h, v.0.1.0
 * 
 * Debug
 */

#ifndef LWCT_DEBUG_H
#define LWCT_DEBUG_H

#include "lwct.h"

typedef enum {
	
	LWCT_DEBUG_OK,
	/* Ok */
	
	LWCT_DEBUG_PARAM,
	/* Parameter is invalid */
	
	LWCT_DEBUG_CORRUPTED,
	/* Corrupted data structure */
	
} lwct_debug_ret;

LWCTL_API lwct_debug_ret lwct_debug_counters(lwct_state *S);

LWCTL_API lwct_debug_ret lwct_debug_destructors(lwct_state *S);

#endif