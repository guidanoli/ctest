/*
 * lwct_deconstructor.h, v.0.1.0
 * 
 * Deconstructor
 */

#ifndef LWCT_DECONSTRUCTOR_H
#define LWCT_DECONSTRUCTOR_H

#include "lwct_conf.h"

typedef enum {
	
	LWCTL_DECONSTRUCTOR_OK,
	/* Ok */
	
	LWCTL_DECONSTRUCTOR_PARAM,
	/* Parameter is invalid */
	
	LWCTL_DECONSTRUCTOR_MEM,
	/* Not enough memory */
	
	LWCTL_DECONSTRUCTOR_DUPLICATE,
	/* Duplicate node */
	
} lwct_deconstructor_ret;

typedef struct lwct_deconstructor lwct_deconstructor;

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_init(
						lwct_deconstructor **pdc);

LWCTL_FUNC void lwct_deconstructor_destroy(lwct_deconstructor *dc);

LWCTL_FUNC lwct_deconstructor_ret lwct_deconstructor_insert(
	lwct_deconstructor *dc, void (*deconstructor)(void *p), void *pdata);

#endif