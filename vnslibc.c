#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include <arpa/inet.h>

#include <string.h>

void* handle_vnslib(void* buf){
  struct nlmsghdr* header = (struct nlmsghdr*) buf;
  struct nlmsghdr* response;
  switch(header->nlmsg_type){
    case RTM_NEWROUTE:
          response = rtm_newroute_c(header);
          break;
    case RTM_DELROUTE:
          response = rtm_delroute_c(header);
          break;
    case RTM_GETROUTE:
          response = rtm_getroute_c(header);
          break;
    case RTM_NEWADDR:
          response = rtm_newaddr_c(header);
          break;
    case RTM_DELADDR:
          response = rtm_deladdr_c(header);
          break;
    case RTM_GETADDR:
          response = rtm_getaddr_c(header);
          break;
    case RTM_NEWLINK:
          response = rtm_newlink_c(header);
          break;
    case RTM_DELLINK:
          response = rtm_dellink_c(header);
          break;
    case RTM_GETLINK:
          response = rtm_getlink_c(header);
          break;
    case RTM_SETLINK:
          response = rtm_setlink_c(header);
          break;
    default:
          /* create standard error package */
          break;
  }
  return (void*)response;
}

struct nlmsghdr* rtm_newroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_newroute_c();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_delroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_delroute_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getroute_c(struct nlmsghdr* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_getroute_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct nlmsghdr* rtm_newaddr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_newaddr_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_deladdr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_deladdr_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getaddr_c(struct nlmsghdr* header){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_getaddr_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct nlmsghdr* rtm_newlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_newlink_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_dellink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_dellink_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_getlink_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_setlink_c(struct nlmsghdr* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct /*da definire*/ generic_conf;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  struct /*da definire*/ rtm_setlink_s();
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}












int print_address(void *buf){

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
