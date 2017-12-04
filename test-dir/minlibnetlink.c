#include "minlibnetlink.h"

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



void fill_buf_route(struct route_payload* buffer, char* IPv6, int mode, int modeIP){
  inet_pton(modeIP, IPv6, buffer->attribute.ip6_address);

  // rtattr init
  buffer->attribute.attr.rta_len=20;
  buffer->attribute.attr.rta_type=RTA_GATEWAY;
  // nlmsghdr init
  buffer->header.nlmsg_len=64;
  buffer->header.nlmsg_type=mode;

  buffer->header.nlmsg_seq=101;
  buffer->header.nlmsg_pid=0;
  // rtmsg init
  if(modeIP==AF_INET6){
      buffer->rtm.rtm_family=AF_INET6;
  }
  else{
    buffer->rtm.rtm_family=AF_INET;
  }
  buffer->rtm.rtm_dst_len=0; //maschera
  buffer->rtm.rtm_src_len=0;
  buffer->rtm.rtm_tos=0;
  buffer->rtm.rtm_table=RT_TABLE_MAIN;// dovrei creare l'interfaccia all'interno del test if_nametoindex("vde0");
  buffer->rtm.rtm_protocol=RTPROT_UNSPEC;
  buffer->rtm.rtm_scope=RT_SCOPE_NOWHERE;
  buffer->rtm.rtm_type=RTN_UNSPEC;
  buffer->rtm.rtm_flags=0;
  if(mode==RTM_NEWROUTE){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK|NLM_F_EXCL|NLM_F_CREATE;
  }
  else if(mode==RTM_DELROUTE){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK;
  }
}


// generea lo stesso pacchetto netlink generato da ip addr add <IPv6/mask> dev <device_name>

void fill_buf_addr(struct addr_payload* buffer, char* IP, int mask, int mode, int modeIP){
  inet_pton(modeIP, IP, buffer->attribute[0].ip6_address);
  inet_pton(modeIP, IP, buffer->attribute[1].ip6_address);
  if(modeIP == AF_INET6){
    // rtattr init
    buffer->attribute[0].attr.rta_len=20;
    buffer->attribute[1].attr.rta_len=20;
    buffer->header.nlmsg_len=64;
  }
  else{
    buffer->attribute[0].attr.rta_len=8;
    buffer->attribute[1].attr.rta_len=8;
    buffer->header.nlmsg_len=40;
  }
  buffer->attribute[0].attr.rta_type=IFA_LOCAL;
  buffer->attribute[1].attr.rta_type=IFA_ADDRESS;
  buffer->ifa.ifa_family=modeIP;
  buffer->header.nlmsg_seq=100;
  buffer->header.nlmsg_pid=0;
  // ifaddr init
  buffer->ifa.ifa_prefixlen=mask; //maschera
  buffer->ifa.ifa_flags=0;
  buffer->ifa.ifa_scope=RT_SCOPE_UNIVERSE;
  buffer->ifa.ifa_index = 0;// dovrei creare l'interfaccia all'interno del test if_nametoindex("vde0");
  buffer->header.nlmsg_type=mode;
  if(mode==RTM_NEWADDR){
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK|NLM_F_EXCL|NLM_F_CREATE;
  }
  else{
    buffer->header.nlmsg_flags=NLM_F_REQUEST|NLM_F_ACK;
  }
}
