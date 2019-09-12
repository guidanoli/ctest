/*
 * lwct_deconstructor.c, v.0.1.0
 * 
 * Deconstructor
 */

#include <stdlib.h>
#include "lwct_deconstructor.h"
#include "lwct_sll.h"

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
	if (lwct_sll_create(&(dc->sll)) != LWCTL_SLL_OK)
		return LWCTL_DECONSTRUCTOR_MEM;
	*pdc = dc;
	return LWCTL_DECONSTRUCTOR_OK;
}

void lwct_deconstructor_destroy(struct lwct_deconstructor *dc)
{
	if (!dc) return;
	lwct_sll_destroy(dc->sll);
	free(dc);
}

lwct_deconstructor_ret lwct_deconstructor_insert(struct lwct_deconstructor *dc,
				void (*deconstructor)(void *p), void *pdata)
{
	lwct_sll_insert(dc->sll, pdata, deconstructor);
	lwct_sll_debug(dc);
}