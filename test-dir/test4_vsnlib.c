#include "minlibnetlink.h"

#define BUFSIZE 1024
char buf[BUFSIZE];

int main(int argc, char** argv){

  struct sockaddr_in serv_addr;
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

  struct ip_addr addr, mask;

  buf=&buf_addr.header;
  buf_r=&buf_route.header;

  // call vsnlib
  if(init_vsnlib(argv[1])==-1){
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
  if((nif=lwip_vdeif_add(stack,argv[2]))==NULL){
    perror("Interface not loaded");
    exit(-1);
  }

  fill_buf_link(&buf_link, 1);
  handle_vsnlib(&buf_link, buf_link.header.nlmsg_len, (void*)nif, (void*)stack);

  fill_buf_addr(&buf_addr, "192.168.250.20", 24, RTM_NEWADDR, AF_INET);
  handle_vsnlib(buf, buf_addr.header.nlmsg_len, (void*)nif, (void*)stack);


  fill_buf_route(&buf_route, "192.168.250.2", RTM_NEWROUTE, AF_INET);
  handle_vsnlib(buf_r, buf_route.header.nlmsg_len, (void*)nif, (void*)stack);

  memset((char *) &serv_addr,0,sizeof(serv_addr));
  serv_addr.sin_family      = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("192.168.250.1");
  serv_addr.sin_port        = htons(atoi("9999"));

    /* create a TCP lwipv6 socket */
    if((fd=lwip_msocket(stack,PF_INET,SOCK_STREAM,0))<0) {
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
    fill_buf_route(&buf_route, "192.168.250.1", RTM_DELROUTE, AF_INET);
    handle_vsnlib(buf_r, buf_route.header.nlmsg_len, (void*)nif, (void*)stack);

    fill_buf_addr(&buf_addr, "192.168.250.20", 64, RTM_DELADDR, AF_INET);
    handle_vsnlib(buf, buf_addr.header.nlmsg_len, (void*)nif, (void*)stack);

    fill_buf_link(&buf_link, 0);
    handle_vsnlib(&buf_link, buf_link.header.nlmsg_len, (void*)nif, (void*)stack);
}
