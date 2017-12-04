#ifndef _MINLIBNETLINK_H
#define _MINLIBNETLINK_H
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <lwipv6.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include <vsnshared.h>

struct info{
  struct rtattr attr;
  unsigned char ip6_address[sizeof(struct in6_addr)];
};

struct addr_payload{
  struct nlmsghdr header;
  struct ifaddrmsg ifa;
  struct info attribute[2];
};

struct route_payload{
  struct nlmsghdr header;
  struct rtmsg rtm;
  struct info attribute;
};

struct link_payload{
  struct nlmsghdr header;
  struct ifinfomsg ifi;
};

void fill_buf_link(struct link_payload* buffer, int mode);
void fill_buf_route(struct route_payload* buffer, char* IPv6, int mode, int modeIP);
void fill_buf_addr(struct addr_payload* buffer, char* IP, int mask, int mode, int modeIP);

#endif
