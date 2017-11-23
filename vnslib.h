#ifndef _VNSLIB_H
#define _VNSLIB_H

#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <arpa/inet.h>

/* struct definition */
struct config{

};

struct response{

};


/* client side */

extern void* handle_vnslib(void* buf);
struct nlmsghdr* rtm_newroute_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_delroute_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_getroute_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_newaddr_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_deladdr_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_getaddr_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_newlink_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_dellink_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_getlink_c(struct nlmsghdr* header);
struct nlmsghdr* rtm_setlink_c(struct nlmsghdr* header);

/* server side */

struct response* rtm_newroute_s(struct config* header);
struct response* rtm_delroute_s(struct config* header);
struct response* rtm_getroute_s(struct config* header);
struct response* rtm_newaddr_s(struct config* header);
struct response* rtm_deladdr_s(struct config* header);
struct response* rtm_getaddr_s(struct config* header);
struct response* rtm_newlink_s(struct config* header);
struct response* rtm_dellink_s(struct config* header);
struct response* rtm_getlink_s(struct config* header);
struct response* rtm_setlink_s(struct config* header);


extern int print_address(const void *buf);




#endif
