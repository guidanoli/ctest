/*
 * lwct_sll.h, v.0.1.1
 *
 * SLL - Single Linked List
 */

#ifndef LWCT_SLL_H
#define LWCT_SLL_H

#include "lwct.h"

typedef enum {

	LWCTL_SLL_OK,
	/* Ok */

	LWCTL_SLL_PARAM,
	/* Parameter is invalid */

	LWCTL_SLL_MEM,
	/* Not enough memory */

	LWCTL_SLL_EMPTY,
	/* List is empty */

	LWCTL_SLL_NOTEMPTY,
	/* List is not empty */

	LWCTL_SLL_EOL,
	/* End of list */

} lwct_sll_ret;

/*
 * Single Linked List
 */
typedef struct lwct_sll_head lwct_sll;

/*
 * Functions for SLL node lifecycle
 */
LWCTL_API lwct_sll_ret lwct_sll_create(lwct_sll **sll);

LWCTL_API lwct_sll_ret lwct_sll_destroy(lwct_sll *sll);

/*
 * Functions for internal state manipulation
 */
LWCTL_API lwct_sll_ret lwct_sll_insert(lwct_sll *sll, void *info,
						void (*delete_f)(void *self));

LWCTL_API lwct_sll_ret lwct_sll_remove(lwct_sll *sll, void **pinfo);

LWCTL_API lwct_sll_ret lwct_sll_get(lwct_sll *sll, void **pinfo);

LWCTL_API lwct_sll_ret lwct_sll_next(lwct_sll *sll);

LWCTL_API lwct_sll_ret lwct_sll_beginning(lwct_sll *sll);

LWCTL_API lwct_sll_ret lwct_sll_isempty(lwct_sll *sll);

LWCTL_API lwct_sll_ret lwct_sll_clean(lwct_sll *sll);

#endif
