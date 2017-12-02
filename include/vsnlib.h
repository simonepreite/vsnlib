#ifndef _VSNLIB_H
#define _VSNLIB_H

#include "vsnshared.h"

#define  API_TABLE_SIZE 6

/* struct definition */
struct config{
	char* addr;
	int mask;
	int family;
	void* interface;
	void* stack; // stack file descriptor
	int operation;

};

typedef struct response* (*generic_api)(struct config* cfg);
struct gen_api{
  char* fun_name;
  generic_api real_fun;
};

static struct gen_api api_table[]={
  {"adddellink", NULL},
  {"getsetlink",NULL},
  {"adddeladdr", NULL},
  {"getaddr", NULL},
  {"adddelroute", NULL},
  {"getroute", NULL}
};

/* client side */

struct nlmsghdr* rtm_newroute_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_delroute_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_getroute_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_newaddr_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_deladdr_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_getaddr_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_newlink_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_dellink_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_getlink_c(struct nlmsghdr* header, void* nif, void* stack);
struct nlmsghdr* rtm_setlink_c(struct nlmsghdr* header, void* nif, void* stack);

typedef struct nlmsghdr* vns_cli(struct nlmsghdr* header, void* nif, void* stack);
static vns_cli *vsncli_fun_table[]={
	/* NEW/DEL/GET/SET link */
  rtm_newlink_c,
  rtm_dellink_c,
  rtm_getlink_c,
  rtm_setlink_c,
	/* NEW/DEL/GET addr */
  rtm_newaddr_c,
  rtm_deladdr_c,
  rtm_getaddr_c,
  NULL,
	/* NEW/DEL/GET route */
	rtm_newroute_c,
	rtm_delroute_c,
	rtm_getroute_c,
  NULL
};

#endif
