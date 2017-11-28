#ifndef _LWIPv6_H
#define _LWIPv6_H


struct response* LWIPv6_adddeladdr(struct config* cfg);
struct response* LWIPv6_getaddr(struct config* cfg);
struct response* LWIPv6_adddellink(struct config* cfg);
struct response* LWIPv6_getsetlink(struct config* cfg);
struct response* LWIPv6_adddelroute(struct config* cfg);
struct response* LWIPv6_getroute(struct config* cfg);

#endif
