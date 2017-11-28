#ifndef _VSNLIB_H
#define _VSNLIB_H

#include "vsnshared.h"

#define  API_TABLE_SIZE 6

/* struct definition */
struct config{

};

struct response{

};

/* questa forse è megli definirla nell'header della libreria */
const char mask4_len[] = {
	"255.255.255.255",
	"255.255.255.0",
	"255.255.0.0",
	"255.0.0.0"
};

typedef struct response* (*generic_api)(struct config* cfg);
struct gen_api{
  char* fun_name;
  generic_api real_fun;
};

static struct gen_api api_table[]={
  {"adddellink", NULL},
  {"getsetlink",NULL},
  {"addradddel", NULL},
  {"getaddr", NULL},
  {"adddelroute",NULL},
  {"getroute", NULL}
};

/* client side */


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

typedef struct nlmsghdr* vns_cli(struct nlmsghdr* header);
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

#if 0
con il mapping delle funzioni si potrebbe evitare il server side
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


#endif



#endif
