#ifndef _LWIP_H
#define _LWIP_H


struct response* LWIP_adddeladdr(struct config* cfg);
struct response* LWIP_getaddr(struct config* cfg);
struct response* LWIP_adddellink(struct config* cfg);
struct response* LWIP_getsetlink(struct config* cfg);
struct response* LWIP_adddelroute(struct config* cfg);
struct response* LWIP_getroute(struct config* cfg);

#endif
