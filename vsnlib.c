#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <dlfcn.h>

#include <vsnlib.h>
#include <vsnshared.h>


struct ret_val{
  struct nlmsghdr* res;
  struct ret_val* next;
};

char* combine_stack_handler(char* fun_name, char* stack){
    //rimuove il .so
    char* combo;
    int len_stack = strlen(stack)-1;
    combo = malloc(sizeof(char)*(strlen(fun_name)+(len_stack-1)));
    strcpy(combo, stack);
    combo[len_stack-2] = '_';
    combo[len_stack-1] = '\0';
    strcat(combo, fun_name);
    return combo;
}


int init_vsnlib(char* stack){ // stack al momento sarà la stringa .so della libreria, in seguito vedremo di far digitare all'utente solo il nome dello stack
  const char *error;
  char* f;
  void *stack_module;
  char* default_path = "/usr/local/lib/vsn/modules/";
  char* app = malloc(strlen(default_path)+strlen(stack)+1);
  printf("init vsnlib\n" );
  strcpy(app, default_path);
  strcat(app, stack);
  stack_module = dlopen(stack,RTLD_LAZY);
  if(!stack_module){
    fprintf(stderr, "Cannot open stack library: %s\n",
    dlerror());
    return -1;
  }
  for(int i=0; i < API_TABLE_SIZE; i++){
    api_table[i].real_fun = dlsym(stack_module, /*combine_stack_handler(*/api_table[i].fun_name/*, stack)*/);
    if ((error = dlerror())) {
      fprintf(stderr, "Couldn't find %s: %s\n", api_table[i].fun_name, error);
      exit(1);
    }
  }
  return 0; //if success
}

void handle_vsnlib(void* buf, size_t len, void* nif, void* stack){
  struct nlmsghdr* header = (struct nlmsghdr*) buf;
  struct nlmsghdr* ret_pkg;
  while (NLMSG_OK(header, len)) {
    /*int err;*/
    int type;

    if (header->nlmsg_type == NLMSG_DONE)
      break;
    type=header->nlmsg_type - RTM_BASE;
    header->nlmsg_pid=getpid();
    printf("type %d :: vsncli_fun_table[type] %p\n", type, vsncli_fun_table[type]);
    if (type >= 0 && vsncli_fun_table[type] != NULL) {
        printf("call fun client vsnlib\n");
        struct ret_val* app = malloc(sizeof(struct ret_val));
        (vsncli_fun_table[type](header, nif, stack));
    }
    header = NLMSG_NEXT(header, len);
  }
  /* da decidere:
    1 - ci occupiamo in questa funzione di fare le send per ogni pacchetto di risposta, ma significa scandire una lista.
    2 - si occupano le relative funzioni di fare la send, risparmiamo sulla scansione della lista e questa funzione può
        restituire un intero di ack o nulla.
  */
}

struct nlmsghdr* rtm_newlink_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config generic_conf;
  struct response* generic_resp;
  generic_conf.interface = nif;
  generic_conf.operation = ifi->ifi_flags;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  printf("newlink vsnlib\n");
  generic_resp = api_table[0].real_fun(&generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_dellink_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = api_table[0].real_fun(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_getlink_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = api_table[1].real_fun(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_setlink_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = api_table[1].real_fun(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_newaddr_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));//(NLMSG_DATA(header));
  struct config generic_conf;
  struct response* generic_resp;
  char str[INET6_ADDRSTRLEN];
  generic_conf.operation=header->nlmsg_type;
  generic_conf.interface=nif;
  generic_conf.mask=ifa->ifa_prefixlen;
  generic_conf.family=ifa->ifa_family;
  struct rtattr* attr = (struct rtattr*)((void*)(((char*)ifa)+ sizeof(struct ifaddrmsg)));
  if(ifa->ifa_family == AF_INET6){
    struct in6_addr* ip6_a = (struct in6_addr*)RTA_DATA(attr);
    inet_ntop(ifa->ifa_family, ip6_a, str, INET6_ADDRSTRLEN);
    inet_pton(ifa->ifa_family, str, ip6_a);
  }
  generic_conf.addr=str;
  generic_conf.stack=stack;
  generic_resp = api_table[2].real_fun(&generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_deladdr_c(struct nlmsghdr* header, void* nif, void* stack){
  rtm_newaddr_c(header, nif, stack);
}

struct nlmsghdr* rtm_getaddr_c(struct nlmsghdr* header, void* nif, void* stack){
  struct ifaddrmsg* ifa = (struct ifaddrmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = api_table[3].real_fun(generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_newroute_c(struct nlmsghdr* header, void* nif, void* stack){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct config generic_conf;
  struct response* generic_resp;
  char str[INET6_ADDRSTRLEN];

  generic_conf.operation=header->nlmsg_type;
  generic_conf.interface=nif;
  generic_conf.family=rtm->rtm_family;
  generic_conf.stack=stack;
  struct rtattr* attr = (struct rtattr*)((void*)(((char*)rtm)+ sizeof(struct rtmsg)));
  if(rtm->rtm_family == AF_INET6){
    struct in6_addr* ip6_a = (struct in6_addr*)RTA_DATA(attr);
    inet_ntop(rtm->rtm_family, ip6_a, str, INET6_ADDRSTRLEN);
    printf("IPv6 address route: %s\n",str);
  }
  generic_conf.addr=str;
  generic_resp = api_table[4].real_fun(&generic_conf);
  /*
  3-aspettare la risposta con la struttura
  4-costruire il pacchetto di risposta
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct nlmsghdr* rtm_delroute_c(struct nlmsghdr* header, void* nif, void* stack){
  rtm_newroute_c(header, nif, stack);
}

struct nlmsghdr* rtm_getroute_c(struct nlmsghdr* header, void* nif, void* stack){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  struct config* generic_conf;
  struct response* generic_resp;
  /*
  1-parsare il payload del pacchetto
  2-chiamare la gemella del server passando la struttura generica
  */
  generic_resp = api_table[5].real_fun(generic_conf);
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
