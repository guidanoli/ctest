/*
 * t.sll.c, v.0.1.0
 *
 * Single Linked List test
 */

#include "lwct.h"
#include "lwct_sll.h"

#define NULL (void *) 0

void delfunc(void *p)
{
        printf("called delfunc(%d)\n", (int) p);
}

void nullTest(lwct_state *S)
{
        void *p = 1;
        lwct_sll *l = 1;
        lwct_assert(S, lwct_sll_create(NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_destroy(NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(NULL, NULL, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(p, NULL, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(NULL, p, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(NULL, NULL, delfunc) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(p, NULL, delfunc) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_insert(NULL, p, delfunc) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_remove(NULL, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_remove(l, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_remove(NULL, &p) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_get(NULL, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_get(l, NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_get(NULL, &p) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_next(NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_beginning(NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_isempty(NULL) == LWCTL_SLL_PARAM);
        lwct_assert(S, lwct_sll_clean(NULL) == LWCTL_SLL_PARAM);
}

void simpleTest(lwct_state *S)
{
        lwct_sll_ret ret;
        lwct_sll *l = NULL;
        ret = lwct_sll_create(&l);
        lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
        lwct_assert(S, ret == LWCTL_SLL_OK);
        lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

void insertTest(lwct_state *S, unsigned long n)
{
        lwct_sll_ret ret;
        lwct_sll *l = NULL;
        ret = lwct_sll_create(&l);
        lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
        for (int i = 1; i <= n; i++) {
                ret = lwct_sll_insert(l, (void *) i, delfunc);
                lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
        }
        for (int i = 1; i <= n; i++) {
                void *p = NULL;
                lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_NOTEMPTY);
                ret = lwct_sll_remove(l, &p);
                lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
        }
        lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_EMPTY);
        lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

int main(void)
{
        lwct_submit_test(nullTest);
        lwct_submit_test(simpleTest);
        lwct_submit_batch(insertTest, 3);
}
