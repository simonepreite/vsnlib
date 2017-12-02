#ifndef _LWIPv6_H
#define _LWIPv6_H


struct response* adddeladdr(struct config* cfg);
struct response* getaddr(struct config* cfg);
struct response* adddellink(struct config* cfg);
struct response* getsetlink(struct config* cfg);
struct response* adddelroute(struct config* cfg);
struct response* getroute(struct config* cfg);

#endif
