/*
 * LWCT main header file
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

#define lwct_show_log(state) _lwct_show_log(state)

/*
 * Test state data
 */
struct lwct_state {
        char *current_file;
        unsigned long n_tests;
        unsigned long n_failed;
};

/*
* Functions for test state lifecycle
*/
struct lwct_state *lwct_init();

void lwct_destroy(struct lwct_state *state);

/*
 * Test submission data
 */
struct lwct_submission {
        unsigned long n_current;
        unsigned long n_total;
};

/*
 * Functions for test submission
 */
void lwct_submit_test(void (*func)(struct lwct_state *state));

void lwct_submit_batch(void (*func)(struct lwct_state *state,
                 struct lwct_submission *subinfo), unsigned long n_total);

/*
 * Functions for assertion and log display
 */
void _lwct_fatal_assert(struct lwct_state *state, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

void _lwct_assert(struct lwct_state *state, const char bool,
                  const char *label, const char *file,
                  const char *func, const line);

void _lwct_show_log(struct lwct_state *state);

#endif
