/*
 * lwct_sll.c, v.0.1.1
 *
 * Single linked list
 */

#include <stdlib.h>
#include "lwct_sll.h"

/*
 * Single linked list node
 * @info	- information stored in node
 * @next	- next node
 * @delete_f	- callback to delete info
 */
struct lwct_sll_node {
	void *info;
	struct lwct_sll_node *next;
	void (*delete_f)(void *self);
};

/*
 * Single linked list head
 * @first	- first node
 * @current	- current node
 */
struct lwct_sll_head {
	struct lwct_sll_node *first;
	struct lwct_sll_node *current;
};

lwct_sll_ret lwct_sll_create(struct lwct_sll_head **sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_head *head = malloc(sizeof(struct lwct_sll_head));
	if (!head)
		return LWCTL_SLL_MEM;
	head->first = NULL;
	head->current = NULL;
	*sll = head;
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_destroy(struct lwct_sll_head *sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	lwct_sll_ret ret;
	if ((ret = lwct_sll_clean(sll)) != LWCTL_SLL_OK)
		return ret;
	free(sll);
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_insert(lwct_sll *sll, void *info,
                                            void (*delete_f)(void *self))
{
	if (!sll || !info)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_node *node = malloc(sizeof(struct lwct_sll_node));
	if (!node)
		return LWCTL_SLL_MEM;
	node->info = info;
	if (sll->current == NULL) {
                /* Empty list */
		node->next = NULL;
		sll->first = node;
	} else {
                /* Not empty */
		node->next = sll->current->next;
                sll->current->next = node;
	}
        sll->current = node;
	node->delete_f = delete_f;
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_remove(lwct_sll *sll, void **pinfo)
{
	if (!sll || !pinfo)
		return LWCTL_SLL_PARAM;
	if (sll->current == NULL)
		return LWCTL_SLL_EMPTY;
	*pinfo = sll->current->info;
	struct lwct_sll_node *p = sll->first, *ant = NULL;
	while (p != sll->current) {
		ant = p;
		p = p->next;
	}
	if (ant == NULL) {
		/* Current is the first */
		sll->current = p->next;
		sll->first = p->next;
	} else {
		/* Current is not the first */
		ant->next = p->next;
		sll->current = ant;
	}
        free(p);
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_get(lwct_sll *sll, void **pinfo)
{
	if (!sll || !pinfo)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_node *curr;
	if ((curr = sll->current) == NULL)
		return LWCTL_SLL_EMPTY;
	*pinfo = curr->info;
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_next(lwct_sll *sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_node *curr, *next;
	if ((curr = sll->current) == NULL)
		return LWCTL_SLL_EMPTY;
	if ((next = curr->next) == NULL)
		return LWCTL_SLL_EOL;
	sll->current = next;
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_beginning(lwct_sll *sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_node *first;
	if ((first = sll->first) == NULL)
		return LWCTL_SLL_EMPTY;
	sll->current = first;
	return LWCTL_SLL_OK;
}

lwct_sll_ret lwct_sll_isempty(lwct_sll *sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	return sll->first == NULL ? LWCTL_SLL_EMPTY : LWCTL_SLL_NOTEMPTY;
}

lwct_sll_ret lwct_sll_clean(lwct_sll *sll)
{
	if (!sll)
		return LWCTL_SLL_PARAM;
	struct lwct_sll_node *p = sll->first, *next = NULL;
	while (p) {
		next = p->next;
		if (p->delete_f)
			p->delete_f(p->info);
		free(p);
		p = next;
	}
	sll->current = NULL;
	sll->first = NULL;
	return LWCTL_SLL_OK;
}
