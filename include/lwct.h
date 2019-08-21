/*
 * LWCT main header file
 */

#ifndef LWCT_H
#define LWCT_H

#define lwct_fatal_assert(state, bool) \
        _lwct_fatal_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

#define lwct_assert(state, bool) \
        _lwct_assert(state, bool, #bool, __FILE__, __func__, __LINE__)

#define lwct_show_log(state) _lwct_show_log(state)

struct lwct_state {
        char *current_file;
        unsigned long n_tests;
        unsigned long n_failed;
};

struct lwct_state *lwct_init();

void lwct_destroy(struct lwct_state *state);

void _lwct_fatal_assert(struct lwct_state *state, const char bool,
                        const char *label, const char *file,
                        const char *func, const line);

void _lwct_assert(struct lwct_state *state, const char bool,
                  const char *label, const char *file,
                  const char *func, const line);

void _lwct_show_log(struct lwct_state *state);

#endif
