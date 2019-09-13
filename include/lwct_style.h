/*
 * lwct_style.h, v.0.1.0
 *
 * Output style
 */

#ifndef LWCT_STYLE_H
#define LWCT_STYLE_H

#include "lwct_conf.h"

typedef enum {

	LWCT_STYLE_PRINT_NONE = 0,
	/* Prints nothing */

	LWCT_STYLE_PRINT_SUCCESS = 1,
	/* Prints success messages */

	LWCT_STYLE_PRINT_ERROR = 2,
	/* Prints error messages */

	LWCT_STYLE_PRINT_LOG = 4,
	/* Prints log messages */

} lwct_style_print_flags;

typedef enum {

	LWCT_STYLE_OK,
	/* Ok */

	LWCT_STYLE_PARAM,
	/* Parameter is invalid */

	LWCT_STYLE_MEM,
	/* Not enough memory */

} lwct_style_ret;

typedef struct lwct_style lwct_style;

LWCTL_API lwct_style_ret lwct_style_create(lwct_style **pstyle);

LWCTL_API lwct_style_ret lwct_style_destroy(lwct_style *style);

/*
 * Tip: Combine flags with the bitwise | operator
 * e.g. flag1 | flag2 | flag3 ===> flags 1, 2 and 3
 */
LWCTL_API lwct_style_ret lwct_style_config_print(lwct_style *style,
						lwct_style_print_flags flags);

#endif
