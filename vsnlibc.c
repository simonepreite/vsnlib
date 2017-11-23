#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "vsnlib.h"

void* handle_vsnlib(void* buf){
  struct nlmsghdr* header = (struct nlmsghdr*) buf;
  struct nlmsghdr* ret_pkg;
  switch(header->nlmsg_type){
    case RTM_NEWROUTE:
          ret_pkg = rtm_newroute_c(header);
          break;
    case RTM_DELROUTE:
          ret_pkg = rtm_delroute_c(header);
          break;
    case RTM_GETROUTE:
          ret_pkg = rtm_getroute_c(header);
          break;
    case RTM_NEWADDR:
          ret_pkg = rtm_newaddr_c(header);
          break;
    case RTM_DELADDR:
          ret_pkg = rtm_deladdr_c(header);
          break;
    case RTM_GETADDR:
          ret_pkg = rtm_getaddr_c(header);
          break;
    case RTM_NEWLINK:
          ret_pkg = rtm_newlink_c(header);
          break;
    case RTM_DELLINK:
          ret_pkg = rtm_dellink_c(header);
          break;
    case RTM_GETLINK:
          ret_pkg = rtm_getlink_c(header);
          break;
    case RTM_SETLINK:
          ret_pkg = rtm_setlink_c(header);
          break;
    default:
          /* create standard error package */
          break;
  }
  return (void*)ret_pkg;
}

struct nlmsghdr* rtm_newroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_newroute_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_delroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_delroute_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_getroute_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct nlmsghdr* rtm_newaddr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_newaddr_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_deladdr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_deladdr_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getaddr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_getaddr_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct nlmsghdr* rtm_newlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_newlink_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_dellink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_dellink_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_getlink_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_setlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = rtm_setlink_s(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}












int print_address(const void *buf){

    struct nlmsghdr* header = (struct nlmsghdr*) buf;
    //unsigned char* ip_string[sizeof(struct in6_addr)];
    char str[INET6_ADDRSTRLEN];
    if(header->nlmsg_type == RTM_NEWROUTE || header->nlmsg_type == RTM_DELROUTE || header->nlmsg_type == RTM_GETROUTE){
      struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
      struct rtattr* attr = (struct rtattr*)((void*)(((char*)rtm)+ sizeof(struct rtmsg)));

      if(rtm->rtm_family == AF_INET6){
        struct in6_addr* ip6_a = (struct in6_addr*)RTA_DATA(attr);
        inet_ntop(rtm->rtm_family, ip6_a, str, INET6_ADDRSTRLEN);
        ("IPv6 address route: %s\n",str);
      }
      else if(rtm->rtm_family == AF_INET){
        struct in_addr* ip4_a = (struct in_addr*)RTA_DATA(attr);
        printf("IPv4 address route: %s\n", inet_ntoa(*ip4_a));
      }

    }
    else if(header->nlmsg_type == RTM_NEWADDR || header->nlmsg_type == RTM_DELADDR || header->nlmsg_type == RTM_GETADDR){
      struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
      struct rtattr* attr = (struct rtattr*)((void*)(((char*)ifa)+ sizeof(struct ifaddrmsg)));
      //struct in_addr* ip_a = (struct in_addr*)RTA_DATA(attr);
      if(ifa->ifa_family == AF_INET6){
        struct in6_addr* ip6_a = (struct in6_addr*)RTA_DATA(attr);
        inet_ntop(ifa->ifa_family, ip6_a, str, INET6_ADDRSTRLEN);
        printf("IPv6 address add: %s\n",str);
        inet_pton(ifa->ifa_family, str, ip6_a);
      }
      else if(ifa->ifa_family == AF_INET){
        struct in_addr* ip4_a = (struct in_addr*)RTA_DATA(attr);
        printf("IPv4 address add: %s\n", inet_ntoa(*ip4_a));
      }
      //printf("prefix: %d\n", ifa->ifa_prefixlen);
      //printf("ip_add: %s\n", inet_ntoa(*ip_a));
    }
    else if(header->nlmsg_type == RTM_NEWLINK || header->nlmsg_type == RTM_DELLINK || header->nlmsg_type == RTM_GETLINK){
      //struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
      //struct rtattr* attr = (struct rtattr*)((void*)(((char*)ifi)+ sizeof(struct ifinfomsg)));
    }
    return 0;
}
