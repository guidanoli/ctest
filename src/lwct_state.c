/*
 * lwct_state.c, v.1.0.2
 *
 * Test state
 */

#include <stdlib.h>
#include <string.h>
#include "lwct.h"
#include "lwct_state.h"
#include "lwct_deconstructor.h"

/*
 * Test state data
 *
 * @type		test type (see lwct_state_type)
 * @current_file	name of the last file that called an assertion
 * @assertion_cnt       number of assertions
 * @error_cnt	   	number of failed assertions
 * 
 * -- valid for batch tests only:
 * @curr_repetition	current repetition number
 * @total_repetitions	total number of repetitions
 */
struct lwct_state {
	lwct_state_type type;
	lwct_deconstructor *deconstructor;
	char *current_file;
	unsigned long assertion_cnt;
	unsigned long error_cnt;
	unsigned long curr_repetition;
	unsigned long total_repetitions;
};

struct lwct_state *lwct_create_state(lwct_state_type type)
{
	struct lwct_state *S = malloc(sizeof(struct lwct_state));
	if (!S)
		return NULL;
	if(lwct_deconstructor_init(&(S->deconstructor))
						!= LWCTL_DECONSTRUCTOR_OK) {
		free(S);
		return NULL;
	}
	S->current_file = __FILE__;
	S->assertion_cnt = 0;
	S->error_cnt = 0;
	S->type = type;
	S->curr_repetition = 0;
	S->total_repetitions = 0;
	return S;
}

void lwct_destroy_state(struct lwct_state *S)
{
	if (!S) return;
	lwct_deconstructor_destroy(S->deconstructor);
	free(S);
}

void lwct_update_file(struct lwct_state *S, const char *file)
{
	if (strcmp(S->current_file, file) != 0)
		S->current_file = file;
}

void lwct_inc_assertion_cnt(struct lwct_state *S)
{
	++(S->assertion_cnt);
}

void lwct_inc_error_cnt(struct lwct_state *S)
{
	++(S->error_cnt);
}

lwct_state_type lwct_get_type(lwct_state *S)
{
	return S->type;
}

unsigned long lwct_get_assertion_cnt(struct lwct_state *S)
{
	return S->assertion_cnt;
}

unsigned long lwct_get_error_cnt(struct lwct_state *S)
{
	return S->error_cnt;
}

char *lwct_get_current_file(lwct_state *S)
{
	return S->current_file;
}

void lwct_inc_repetition_cnt(lwct_state *S)
{
	++(S->curr_repetition);
}

void lwct_set_repetition_total_cnt(lwct_state *S, unsigned long cnt)
{
	S->total_repetitions = cnt;
}

unsigned long lwct_get_repetition_cnt(lwct_state *S)
{
	return S->curr_repetition;
}

unsigned long lwct_get_repetition_total_cnt(lwct_state *S)
{
	return S->total_repetitions;
}

void lwct_submit_desconstructor(lwct_state *S,
				void (*deconstructor)(void *p), void *pdata)
{
	if (!S || !deconstructor || !pdata) return;
	lwct_deconstructor_insert(S->deconstructor, deconstructor, pdata);
}