/*
 * Assertion and log utilities
 */

#include <stdio.h>
#include <string.h>
#include "lwct.h"
#include "lwct_colours.h"
#include "lwct_macros.h"

/* Predefined tags */
#define ERROR_TAG   "ERROR",    RED
#define LOG_TAG     "LOG",      YELLOW
#define SUCCESS_TAG "SUCCESS",  GREEN

static char *current_file = __FILE__;
static unsigned long n_tests = 0;
static unsigned long n_failed = 0;

static inline void print_tag(const char * tag, const char * colour)
{
        printf("%s[%s%s%s]%s ", WHITE, colour, tag, WHITE, DEFCOLOUR);
}

void LWCT_FatalAssert(const char boolean, const char * label,
                      const char * file, const char * func, const line)
{
        LWCT_Assert(boolean, label, file, func, line);
        if (boolean) return;

        print_tag(ERROR_TAG);
        puts("The program will be aborted due to a fatal error.");

        LWCT_ShowLog();
        exit(1);
}

void LWCT_Assert(const char boolean, const char * label,
                 const char * file, const char * func, const line)
{
        if (strcmp(current_file, file) != 0) {
                current_file = file;
                printf("On file %s%s%s\n",
                       ULINED_DEFCOLOUR, file, DEFCOLOUR);
        }

        if (boolean) {
                print_tag(SUCCESS_TAG);
                printf("\"%s\"\n", label);
        } else {
                print_tag(ERROR_TAG);
                printf("\"%s\" failed in %s:%d\n", label, func, line);
                
                ++n_failed;
        }
        ++n_tests;
}

void LWCT_ShowLog ()
{
        print_tag(LOG_TAG);
        printf("%lu asserts.\n", n_tests);

        print_tag(LOG_TAG);
        if (n_failed == 0)
                puts("No errors found.");
        else
                printf("%lu error%s found.\n", n_failed, PLURAL(n_failed));
}
