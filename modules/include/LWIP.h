#ifndef _LWIP_H
#define _LWIP_H

struct response* adddeladdr(struct config* cfg);
struct response* getaddr(struct config* cfg);
struct response* adddellink(struct config* cfg);
struct response* getsetlink(struct config* cfg);
struct response* adddelroute(struct config* cfg);
struct response* getroute(struct config* cfg);

#endif
