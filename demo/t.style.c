/*
 * t.style.c, v.0.1.0
 *
 * Styles test
 */

#include "lwct.h"
#include "lwct_style.h"

#define NULL (void *) 0

void StyleTest(lwct_state *S)
{
	lwct_style *style;
	lwct_style_ret ret;

	lwct_assert(S, lwct_style_create(NULL) == LWCT_STYLE_PARAM);
	lwct_fatal_assert(S, (ret = lwct_style_create(&style)) != LWCT_STYLE_MEM);
	lwct_assert(S, ret == LWCT_STYLE_OK);
	lwct_assert(S, lwct_style_destroy(style) == LWCT_STYLE_OK);
}

int main(void)
{
	lwct_submit_test(StyleTest);
	return 0;
}
