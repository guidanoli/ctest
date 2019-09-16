/*
 * lwct_sll.h, v.0.2.1
 *
 * SLL - Single Linked List
 */

#ifndef LWCT_SLL_H
#define LWCT_SLL_H

#include "lwct_conf.h"

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

	LWCTL_SLL_CONTAINS,
	/* List contains element */

	LWCTL_SLL_DOES_NOT_CONTAIN,
	/* List does not contain element */

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

LWCTL_API lwct_sll_ret lwct_sll_debug(lwct_sll *sll);

/*
 * Searches for node with information info
 * If found, returns LWCTL_SLL_CONTAINS
 * If not, returns LWCTL_SLL_DOES_NOT_CONTAIN
 * If one of the parameters is null, returns LWCTL_SLL_PARAM
 */
LWCTL_API lwct_sll_ret lwct_sll_contains(lwct_sll *sll, void *info);

/*
 * Searches for node with information info
 * If found, makes it the current node an returns LWCTL_SLL_CONTAINS
 * If not, returns LWCTL_SLL_DOES_NOT_CONTAIN
 * If one of the parameters is null, returns LWCTL_SLL_PARAM
 */
LWCTL_API lwct_sll_ret lwct_sll_search(lwct_sll *sll, void *info);

#endif
