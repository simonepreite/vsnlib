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
