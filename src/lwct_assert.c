/*
 * Assertion and log utilities
 */

#include <stdio.h>
#include <string.h>
#include "lwct.h"
#include "lwct_format.h"
#include "lwct_macros.h"

/* Predefined tags */
#define ERROR_TAG   "ERROR",    RED
#define LOG_TAG     "LOG",      YELLOW
#define SUCCESS_TAG "SUCCESS",  GREEN

static inline void print_tag(const char *tag, const char *colour)
{
        printf("%s[%s%s%s]%s ", WHITE, colour, tag, WHITE, RESET);
}

void _lwct_fatal_assert(struct lwct_state *state, const char bool,
                        const char *label, const char *file,
                        const char *func, const line)
{
        _lwct_assert(state, bool, label, file, func, line);
        if (bool) return;

        print_tag(ERROR_TAG);
        puts("The program will be aborted due to a fatal error.");

        _lwct_show_log(state);
        lwct_destroy(state);
        exit(1);
}

void _lwct_assert(struct lwct_state *state, const char bool,
                  const char *label, const char *file,
                  const char *func, const line)
{
        if (strcmp(state->current_file, file) != 0)
                state->current_file = file;

        if (bool) {
                print_tag(SUCCESS_TAG);
                printf("\"%s\"\n", label);
        } else {
                print_tag(ERROR_TAG);
                printf("\"%s\" failed in %s:%d (%s%s%s)\n",
                       label, func, line, UNDERLINE, file, RESET);

                ++(state->n_failed);
        }
        ++(state->n_tests);
}

void _lwct_show_log(struct lwct_state *state)
{
        print_tag(LOG_TAG);
        printf("%lu asserts.\n", state->n_tests);

        print_tag(LOG_TAG);
        if (state->n_failed == 0)
                puts("No errors found.");
        else
                printf("%lu error%s found.\n",
                       state->n_failed, PLURAL(state->n_failed));
}
