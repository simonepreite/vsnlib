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

#define BUFSIZE 1024
char buf[BUFSIZE];

void fill_buf_link(struct link_payload* buffer, int mode){

  // nlmsghdr init
  buffer->header.nlmsg_len=32;
  buffer->header.nlmsg_type=RTM_NEWLINK;
  buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK;

  buffer->ifi.ifi_flags=mode;
  buffer->header.nlmsg_seq=102;
  buffer->header.nlmsg_pid=0;
  // ifaddr init
  buffer->ifi.ifi_family=AF_UNSPEC;
  buffer->ifi.ifi_type=AF_NETROM; //maschera
  buffer->ifi.ifi_index=0;
  buffer->ifi.ifi_change=0x1;// dovrei creare l'interfaccia all'interno del test if_nametoindex("vde0");
}



void fill_buf_route(struct route_payload* buffer, char* IPv6, int mode){
  inet_pton(AF_INET6, IPv6, buffer->attribute.ip6_address);

  // rtattr init
  buffer->attribute.attr.rta_len=20;
  buffer->attribute.attr.rta_type=RTA_GATEWAY;
  // nlmsghdr init
  buffer->header.nlmsg_len=64;
  buffer->header.nlmsg_type=mode;

  if(mode==RTM_NEWROUTE){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK|NLM_F_EXCL|NLM_F_CREATE;
  }
  else if(mode==RTM_DELROUTE){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK;
  }
  buffer->header.nlmsg_seq=101;
  buffer->header.nlmsg_pid=0;
  // rtmsg init
  buffer->rtm.rtm_family=AF_INET6;
  buffer->rtm.rtm_dst_len=0; //maschera
  buffer->rtm.rtm_src_len=0;
  buffer->rtm.rtm_tos=0;
  buffer->rtm.rtm_table=RT_TABLE_MAIN;// dovrei creare l'interfaccia all'interno del test if_nametoindex("vde0");
  buffer->rtm.rtm_protocol=RTPROT_UNSPEC;
  buffer->rtm.rtm_scope=RT_SCOPE_NOWHERE;
  buffer->rtm.rtm_type=RTN_UNSPEC;
  buffer->rtm.rtm_flags=0;
}


// generea lo stesso pacchetto netlink generato da ip addr add <IPv6/mask> dev <device_name>

void fill_buf_addr(struct addr_payload* buffer, char* IPv6, int mask, int mode){
  inet_pton(AF_INET6, IPv6, buffer->attribute[0].ip6_address);
  inet_pton(AF_INET6, IPv6, buffer->attribute[1].ip6_address);

  // rtattr init
  buffer->attribute[0].attr.rta_len=20;
  buffer->attribute[0].attr.rta_type=IFA_LOCAL;
  buffer->attribute[1].attr.rta_len=20;
  buffer->attribute[1].attr.rta_type=IFA_ADDRESS;
  // nlmsghdr init
  buffer->header.nlmsg_len=64;
  buffer->header.nlmsg_type=mode;

  if(mode==RTM_NEWADDR){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK|NLM_F_EXCL|NLM_F_CREATE;
  }
  else{
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK;
  }
  buffer->header.nlmsg_seq=100;
  buffer->header.nlmsg_pid=0;
  // ifaddr init
  buffer->ifa.ifa_family=AF_INET6;
  buffer->ifa.ifa_prefixlen=mask; //maschera
  buffer->ifa.ifa_flags=0;
  buffer->ifa.ifa_scope=RT_SCOPE_UNIVERSE;
  buffer->ifa.ifa_index = 0;// dovrei creare l'interfaccia all'interno del test if_nametoindex("vde0");
}

int main(int argc, char** argv){


  struct sockaddr_in6 serv_addr;
  int fd;

  struct stack *stack;
  struct netif *nif;
  void* buf;
  void* buf_r;
  void* buf_l;
  struct response* ret;
  struct ip_addr addr_6;

  struct addr_payload buf_addr;
  struct route_payload buf_route;
  struct link_payload buf_link;

  buf=&buf_addr.header;
  buf_r=&buf_route.header;

  // call vsnlib
  if(init_vsnlib("LWIPv6.so")==-1){
    perror("Cannot init vsnlib");
  }

  #ifdef LWIPV6DL
  /* Run-time load the library (if requested) */
  if ((handle=loadlwipv6dl()) == NULL) {
    perror("LWIP lib not loaded");
    exit(-1);
  }
  #endif
  /* define a new stack */
  if((stack=lwip_stack_new())==NULL){
    perror("Lwipstack not created");
    exit(-1);
  }

  /* add an interface */
  if((nif=lwip_vdeif_add(stack,"/tmp/switch1"))==NULL){
    perror("Interface not loaded");
    exit(-1);
  }

  fill_buf_link(&buf_link, 1);
  handle_vsnlib(&buf_link, buf_link.header.nlmsg_len, (void*)nif, (void*)stack);

  fill_buf_addr(&buf_addr, "2001:db8:0:f101::3", 64, RTM_NEWADDR);
  handle_vsnlib(buf, buf_addr.header.nlmsg_len, (void*)nif, (void*)stack);

  //fill_buf_route(&buf_route, "2001:db8:0:f101::2", RTM_NEWROUTE);
  //handle_vsnlib(buf_r, buf_route.header.nlmsg_len, (void*)nif, (void*)stack);

  memset((char *) &serv_addr,0,sizeof(serv_addr));
    serv_addr.sin6_family = PF_INET6;
    char str[INET6_ADDRSTRLEN];
    //IP6_ADDR(&addr_6,0x2001,0x0db8,0x0000,0xf101,0x0000,0x0000,0x0000,0x2);
    //serv_addr.sin6_addr = (struct in6_addr)addr_6;//
    int reto = inet_pton(PF_INET6, "2001:db8:0:f101::1", serv_addr.sin6_addr.s6_addr);
    printf("ret: %d,    %d,%d,%d,%d\n", reto, serv_addr.sin6_addr.s6_addr[0], serv_addr.sin6_addr.s6_addr[1], serv_addr.sin6_addr.s6_addr[2],serv_addr.sin6_addr.s6_addr[3]);
    inet_ntop(PF_INET6, serv_addr.sin6_addr.s6_addr, str, INET6_ADDRSTRLEN);
    printf("ipv test print:  %s\n", str);
    serv_addr.sin6_port = htons(atoi("9999"));

    /* create a TCP lwipv6 socket */
    if((fd=lwip_msocket(stack,PF_INET6,SOCK_STREAM,0))<0) {
      perror("Socket opening error");
      exit(-1);
    }
    /* connect it to the address specified as argv[1] port argv[2] */
    if (lwip_connect(fd,(struct sockaddr *)(&serv_addr),sizeof(serv_addr)) < 0) {
      perror("Socket connecting error");
      exit(-1);
    }

    while(1) {
      fd_set rfds;
      int n;
      FD_ZERO(&rfds);
      FD_SET(STDIN_FILENO,&rfds);
      FD_SET(fd,&rfds);
      /* wait for input both from stdin and from the socket */
      lwip_select(fd+1,&rfds,NULL,NULL,NULL);
      /* copy data from the socket to stdout */
      if(FD_ISSET(fd,&rfds)) {
        if((n=lwip_read(fd,buf,BUFSIZE)) == 0)
          exit(0);
        write(STDOUT_FILENO,buf,n);
      }
      /* copy data from stdin to the socket */
      if(FD_ISSET(STDIN_FILENO,&rfds)) {
        if((n=read(STDIN_FILENO,buf,BUFSIZE)) == 0)
          exit(0);
        lwip_write(fd,buf,n);
      }
    }
#if 0
    fill_buf_route(&buf_route, "2001:db8:0:f101::2", RTM_DELROUTE);
    handle_vsnlib(buf_r, buf_route.header.nlmsg_len, (void*)nif, (void*)stack);

    fill_buf_addr(&buf_addr, "2001:db8:0:f101::2", 64, RTM_DELADDR);
    handle_vsnlib(buf, buf_addr.header.nlmsg_len, (void*)nif, (void*)stack);

    fill_buf_link(&buf_link, 0);
    handle_vsnlib(&buf_link, buf_link.header.nlmsg_len, (void*)nif, (void*)stack);
#endif
}
