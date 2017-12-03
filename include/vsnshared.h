#ifndef _VSNSHARED_H
#define _VSNSHARED_H

#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <arpa/inet.h>

struct response{
	int error; //0 for success
};

extern void handle_vsnlib(void* buf, size_t len, void* nif, void* stack);
extern int init_vsnlib(char* stack);

#endif
