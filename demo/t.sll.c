/*
 * t.sll.c, v.0.1.1
 *
 * Single Linked List test
 */

#include "lwct.h"
#include "lwct_sll.h"

#define NULL (void *) 0
#define MAGIC (void *) 12345

/* Last information deleted */
unsigned int deleted_cnt = 0;
void *last_deleted = NULL;
void delfunc(void *p)
{
	last_deleted = p;
	++deleted_cnt;
}

/*
 * Provide NULL parameters
 */
void nullTest(lwct_state *S)
{
	void *p = MAGIC;
	lwct_sll *l = MAGIC;
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
	lwct_assert(S, p == MAGIC);
	lwct_assert(S, lwct_sll_get(NULL, NULL) == LWCTL_SLL_PARAM);
	lwct_assert(S, lwct_sll_get(l, NULL) == LWCTL_SLL_PARAM);
	lwct_assert(S, lwct_sll_get(NULL, &p) == LWCTL_SLL_PARAM);
	lwct_assert(S, p == MAGIC);
	lwct_assert(S, lwct_sll_next(NULL) == LWCTL_SLL_PARAM);
	lwct_assert(S, lwct_sll_beginning(NULL) == LWCTL_SLL_PARAM);
	lwct_assert(S, lwct_sll_isempty(NULL) == LWCTL_SLL_PARAM);
	lwct_assert(S, lwct_sll_clean(NULL) == LWCTL_SLL_PARAM);
}

/*
* Provides empty lists
*/
void EmptyTest(lwct_state *S)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_assert(S, ret == LWCTL_SLL_OK);
	void *p = MAGIC;
	lwct_assert(S, lwct_sll_remove(l, &p) == LWCTL_SLL_EMPTY);
	lwct_assert(S, p == MAGIC);
	lwct_assert(S, lwct_sll_get(l, &p) == LWCTL_SLL_EMPTY);
	lwct_assert(S, p == MAGIC);
	lwct_assert(S, lwct_sll_next(l) == LWCTL_SLL_EOL);
	lwct_assert(S, lwct_sll_beginning(l) == LWCTL_SLL_OK);
	lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_EMPTY);
	lwct_assert(S, lwct_sll_clean(l) == LWCTL_SLL_OK);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

/*
 * Creates and destroys list
 */
void simpleTest(lwct_state *S)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
	lwct_sll_debug(l);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

/*
 * Auxiliary function to pyramidTest
 */
void _pyramidTest(lwct_state *S, unsigned long n, lwct_sll *l)
{
	lwct_sll_ret ret;
	lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_EMPTY);
	for (int i = 1; i <= n; i++) {
		ret = lwct_sll_insert(l, (void *) i, delfunc);
		lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
		void *p = NULL;
		lwct_assert(S, lwct_sll_get(l, &p) == LWCTL_SLL_OK);
		lwct_assert(S, p == (void *) i);
		lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_NOTEMPTY);
	}
	lwct_sll_debug(l);
	for (int i = 1; i <= n; i++) {
		void *p = NULL;
		lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_NOTEMPTY);
		ret = lwct_sll_remove(l, &p);
		lwct_assert(S, p == n - i + 1); // backwards
		lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
	}
	lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_EMPTY);
}

/*
 * Inserts n nodes and removes all of them
 */
void pyramidTest(lwct_state *S, unsigned long n)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_assert(S, ret == LWCTL_SLL_OK);
	_pyramidTest(S, n, l);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

/*
 * Insert 3 nodes and remove all of the from the beginning
 */
void removeFromBeginning(lwct_state *S)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_assert(S, ret == LWCTL_SLL_OK);
	for (int i = 1; i <= 3; i++) {
		ret = lwct_sll_insert(l, (void *) i, delfunc);
		lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	}
	lwct_assert(S, lwct_sll_beginning(l) == LWCTL_SLL_OK);
	for (int i = 1; i <= 3; i++) {
		void *p = NULL;
		lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_NOTEMPTY);
		ret = lwct_sll_remove(l, &p);
		lwct_assert(S, p == i); // backwards
		lwct_fatal_assert(S, ret == LWCTL_SLL_OK);
	}
	lwct_assert(S, lwct_sll_isempty(l) == LWCTL_SLL_EMPTY);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

/*
 * Cleans list and then runs the pyramid test
 */
void cleanTest(lwct_state *S)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_assert(S, ret == LWCTL_SLL_OK);
	for (int i = 1; i <= 3; i++) {
		ret = lwct_sll_insert(l, (void *) i, delfunc);
		lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	}
	deleted_cnt = 0;
	lwct_assert(S, lwct_sll_clean(l) == LWCTL_SLL_OK);
	lwct_assert(S, deleted_cnt == 3);
	_pyramidTest(S, 3, l);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

void deleteFuncTest(lwct_state *S)
{
	lwct_sll_ret ret;
	lwct_sll *l = NULL;
	ret = lwct_sll_create(&l);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	lwct_assert(S, ret == LWCTL_SLL_OK);
	ret = lwct_sll_insert(l, MAGIC, delfunc);
	lwct_fatal_assert(S, ret != LWCTL_SLL_MEM);
	last_deleted = NULL;
	lwct_assert(S, lwct_sll_clean(l) == LWCTL_SLL_OK);
	lwct_assert(S, last_deleted == MAGIC);
	lwct_assert(S, lwct_sll_destroy(l) == LWCTL_SLL_OK);
}

int main(void)
{
	lwct_submit_test(nullTest);
	lwct_submit_test(simpleTest);
	lwct_submit_batch(pyramidTest, 3);
	lwct_submit_test(removeFromBeginning);
	lwct_submit_test(cleanTest);
	lwct_submit_test(deleteFuncTest);
}
