/*
 * lwct_format.h, v.1.0.0
 *
 * ANSI text formatting codes
 *
 * Beware: formats do not reset on their own. Thus, be
 * sure to print RESET before the call of another function
 * or the end of the current function. This will avoid contamination.
 */

#ifndef LWCT_FORMAT_H
#define LWCT_FORMAT_H

/*
 * Colourful tag printing
 *
 * Every message output by the LWCT library is formatted with
 * a leading tag, which is printed in a specific colour.
 * 
 * Tags are often defined in macros as a pair of two arguments
 * #define MY_TAG COLOR, LABEL
 */
#define CTPRINT(tag, message, ...) \
	printf("%s[%s%s%s]%s " message "\n", \
	WHITE, tag, WHITE, RESET, ##__VA_ARGS__)

#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"

#define RED "\x1b[91m"
#define GREEN "\x1b[92m"
#define YELLOW "\x1b[93m"
#define BLUE "\x1b[94m"
#define MAGENTA "\x1b[95m"
#define CYAN "\x1b[96m"
#define WHITE "\x1b[97m"

#endif
