#ifndef _VSNSHARED_H
#define _VSNSHARED_H

#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <arpa/inet.h>

extern void* handle_vsnlib(void* buf, size_t len);
extern int init_vsnlib(char* stack);
extern int print_address(const void *buf);

#endif
