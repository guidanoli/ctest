/*
 * lwct_deconstructor.h, v.1.0.0
 * 
 * Deconstructor
 */

#ifndef LWCT_DECONSTRUCTOR_H
#define LWCT_DECONSTRUCTOR_H

#include "lwct_conf.h"

typedef enum {
	
	LWCT_DECONSTRUCTOR_OK,
	/* Ok */
	
	LWCT_DECONSTRUCTOR_PARAM,
	/* Parameter is invalid */
	
	LWCT_DECONSTRUCTOR_MEM,
	/* Not enough memory */
	
	LWCT_DECONSTRUCTOR_DUPLICATE,
	/* Duplicate node */
	
	LWCT_DECONSTRUCTOR_UNEXPECTED,
	/* Unexpected error */
	
} lwct_deconstructor_ret;

typedef struct lwct_deconstructor lwct_deconstructor;

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_init(
						lwct_deconstructor **pdc);

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_destroy(
						lwct_deconstructor *dc);

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_insert(
	lwct_deconstructor *dc, void (*deconstructor)(void *p), void *pdata);

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_debug(
						lwct_deconstructor *dc);

#endif
