#ifndef _PICOTCP_H
#define _PICOTCP_H


struct response* picoTCP_adddeladdr(struct config* cfg);
struct response* picoTCP_getaddr(struct config* cfg);
struct response* picoTCP_adddellink(struct config* cfg);
struct response* picoTCP_getsetlink(struct config* cfg);
struct response* picoTCP_adddelroute(struct config* cfg);
struct response* picoTCP_getroute(struct config* cfg);

#endif
