/*
 * lwct_conf.h, v.1.0.0
 *
 * Library configuration
 */

#ifndef LWCT_CONF_H
#define LWCT_CONF_H

/*
 * Library function visibility
 *
 * @LWCTL_FUNC  internal use
 * @LWCTL_API   exported to the API
 */
#define LWCTL_FUNC	__attribute__((visibility("hidden"))) extern
#define LWCTL_API	 extern

#endif
