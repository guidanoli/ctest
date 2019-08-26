/*
 * lwct_assert.c, v.2.0.1
 *
 * Assertion and log utilities
 */

#include <stdio.h>
#include "lwct_assert.h"
#include "lwct_state.h"
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

void _lwct_fatal_assert(struct lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line)
{
        _lwct_assert(S, bool, label, file, func, line);
        if (bool) return;

        CTPRINT(ERROR_TAG, "The program will be aborted due to a fatal error.");

        lwct_show_log(S);
        lwct_destroy_state(S);
        exit(1);
}

void _lwct_assert(struct lwct_state *S, const char bool,
                        const char *label, const char *file,
                        const char *func, const line)
{
        lwct_update_file(S, file);

        if (bool) {
                CTPRINT(SUCCESS_TAG, "\"%s\"", label);
        } else {
                CTPRINT(ERROR_TAG, "\"%s\" failed in %s:%d (%s%s%s)",
                        label, func, line, UNDERLINE, file, RESET);

                lwct_inc_error_cnt(S);
        }
        lwct_inc_assertion_cnt(S);
}

void lwct_show_log(struct lwct_state *S)
{
        unsigned long assertion_cnt = lwct_get_assertion_cnt(S);
        unsigned long error_cnt = lwct_get_error_cnt(S);

        CTPRINT(LOG_TAG, "%lu asserts.", assertion_cnt);

        if (error_cnt == 0)
                CTPRINT(LOG_TAG, "No errors found.");
        else
                CTPRINT(LOG_TAG, "%llu error%s found.",
                        error_cnt, PLURAL(error_cnt));
}
