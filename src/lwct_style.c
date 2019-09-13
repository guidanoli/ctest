/*
 * lwct_style.c, v.0.1.0
 *
 * Output style
 */

#include <stdlib.h>
#include "lwct_style.h"

/* Boolean values */
#define TRUE 1
#define FALSE 0

/*
 * Style configuration data
 * @print_success - print success messages?
 * @print_error - print error messages?
 * @print_log - print log?
 */
struct lwct_style {
	unsigned char print_success : 1;
	unsigned char print_error : 1;
	unsigned char print_log : 1;
};

lwct_style_ret lwct_style_create(struct lwct_style **pstyle)
{
	if (!pstyle)
		return LWCT_STYLE_PARAM;

	struct lwct_style *style = malloc(sizeof(struct lwct_style));
	if (!style)
		return LWCT_STYLE_MEM;

	/* Default style */
	style->print_success = TRUE;
	style->print_error = TRUE;
	style->print_log = TRUE;

	*pstyle = style;
	return LWCT_STYLE_OK;
}

lwct_style_ret lwct_style_destroy(struct lwct_style *style)
{
	if (!style)
		return LWCT_STYLE_PARAM;

	free(style);
	return LWCT_STYLE_OK;
}

lwct_style_ret lwct_style_config_print(lwct_style *style,
						lwct_style_print_flags flags)
{
	if (!style)
		return LWCT_STYLE_PARAM;

	style->print_success = (flags & LWCT_STYLE_PRINT_SUCCESS) != FALSE;
	style->print_error = (flags & LWCT_STYLE_PRINT_ERROR) != FALSE;
	style->print_log = (flags & LWCT_STYLE_PRINT_LOG) != FALSE;

	return LWCT_STYLE_OK;
}
