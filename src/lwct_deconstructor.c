/*
 * lwct_deconstructor.c, v.0.2.0
 * 
 * Deconstructor
 */

#include <stdlib.h>
#include "lwct_deconstructor.h"
#include "lwct_sll.h"

/*
 * Deconstructor
 * @sll	- single linked list
 */
struct lwct_deconstructor {
	lwct_sll *sll;
};

lwct_deconstructor_ret lwct_deconstructor_init(struct lwct_deconstructor **pdc)
{
	if (!pdc)
		return LWCTL_DECONSTRUCTOR_PARAM;
	struct lwct_deconstructor *dc = 
				malloc(sizeof(struct lwct_deconstructor));
	if (!dc)
		return LWCTL_DECONSTRUCTOR_MEM;
	lwct_sll_ret sll_ret;
	if ((sll_ret = lwct_sll_create(&(dc->sll))) == LWCTL_SLL_MEM)
		return LWCTL_DECONSTRUCTOR_MEM;
	else if(sll_ret != LWCTL_SLL_OK)
		return LWCTL_DECONSTRUCTOR_UNEXPECTED;
	*pdc = dc;
	return LWCTL_DECONSTRUCTOR_OK;
}

lwct_deconstructor_ret lwct_deconstructor_destroy(struct lwct_deconstructor *dc)
{
	if (!dc)
		return LWCTL_DECONSTRUCTOR_PARAM;
	if (lwct_sll_destroy(dc->sll) != LWCTL_SLL_OK)
		return LWCTL_DECONSTRUCTOR_UNEXPECTED;
	free(dc);
	return LWCTL_DECONSTRUCTOR_OK;
}

lwct_deconstructor_ret lwct_deconstructor_insert(struct lwct_deconstructor *dc,
				void (*deconstructor)(void *p), void *pdata)
{
	if (!dc)
		return LWCTL_DECONSTRUCTOR_PARAM;
	if (lwct_sll_insert(dc->sll, pdata, deconstructor) != LWCTL_SLL_OK)
		return LWCTL_DECONSTRUCTOR_UNEXPECTED;
	return LWCTL_DECONSTRUCTOR_OK;
}

lwct_deconstructor_ret lwct_deconstructor_debug(lwct_deconstructor *dc)
{
	if (!dc)
		return LWCTL_DECONSTRUCTOR_PARAM;
	if (lwct_sll_debug(dc->sll) != LWCTL_SLL_OK)
		return LWCTL_DECONSTRUCTOR_UNEXPECTED;
	return LWCTL_DECONSTRUCTOR_OK;
}