/*
 * lwct.h, v.2.0.0
 *
 * Lightweight C Test Library
 */

#ifndef LWCT_H
#define LWCT_H

/*
 * Macros for assertion and log display
 */
#define lwct_fatal_assert(state, bool) \
        _lwct_fatal_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

#define lwct_assert(state, bool) \
        _lwct_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

/* @deprecated */
#define lwct_show_log(state) _lwct_show_log(state)

/*
 * Testing enviroment state
 */
typedef struct lwct_state lwct_state;

/*
 * Functions for testing enviroment state life cycle
 * @deprecated
 */
lwct_state *lwct_init();

void lwct_destroy(lwct_state *S);

/*
 * Functions for test submission work much like observers,
 * and receive the following informations:
 * @S           test enviroment state
 * @repetition  index of repetition
 */
void lwct_submit_test(void (*func)(lwct_state *S));

void lwct_submit_batch(void (*func)(lwct_state *S, unsigned long repetition),
                        unsigned long repetition_cnt);

/*
 * Functions for assertion and log display
 */
void _lwct_fatal_assert(lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

void _lwct_assert(lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

/* @deprecated */
void _lwct_show_log(lwct_state *S);

#endif
