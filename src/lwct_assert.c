/*
 * lwct_assert.c
 *
 * Assertion and log utilities
 */

#include <stdio.h>
#include <string.h>
#include "lwct.h"
#include "lwct_format.h"

#define PLURAL(q) q==1 ? "" : "s"

/*
 * Predefined tags
 *
 * Every tag is defined as a pair (color, label)
 * Colours are escape codes as defined in lwct_format.h
 * Labels are merely strings that will be printed out.
 */
#define ERROR_TAG       RED,        "ERROR"
#define LOG_TAG         YELLOW,     "LOG"
#define SUCCESS_TAG     GREEN,      "SUCCESS"

/*
 * Colourful tag printing
 *
 * Every message output by the LWCT library is formatted with
 * a leading tag, which is printed in a specific colour.
 */
#define CTPRINT(tag, message, ...) \
        printf("%s[%s%s%s]%s " message "\n", \
        WHITE, tag, WHITE, RESET, ##__VA_ARGS__)

void _lwct_fatal_assert(struct lwct_state *state, const char bool,
                        const char *label, const char *file,
                        const char *func, const line)
{
        _lwct_assert(state, bool, label, file, func, line);
        if (bool) return;

        CTPRINT(ERROR_TAG, "The program will be aborted due to a fatal error.");

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
                CTPRINT(SUCCESS_TAG, "\"%s\"", label);
        } else {
                CTPRINT(ERROR_TAG, "\"%s\" failed in %s:%d (%s%s%s)",
                        label, func, line, UNDERLINE, file, RESET);

                ++(state->n_failed);
        }
        ++(state->n_tests);
}

void _lwct_show_log(struct lwct_state *state)
{
        CTPRINT(LOG_TAG, "%lu asserts.", state->n_tests);

        if (state->n_failed == 0)
                CTPRINT(LOG_TAG, "No errors found.");
        else
                CTPRINT(LOG_TAG, "%lu error%s found.",
                        state->n_failed, PLURAL(state->n_failed));
}
