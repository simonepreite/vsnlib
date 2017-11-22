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



struct /*da definire*/ rtm_newroute_s(struct /*da definire*/ header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_delroute_s(struct /*da definire*/ header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_getroute_s(struct /*da definire*/ header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct /*da definire*/ rtm_newaddr_s(struct /*da definire*/ header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_deladdr_s(struct /*da definire*/ header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_getaddr_s(struct /*da definire*/ header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct /*da definire*/ rtm_newlink_s(struct /*da definire*/ header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_dellink_s(struct /*da definire*/ header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_getlink_s(struct /*da definire*/ header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct /*da definire*/ rtm_setlink_s(struct /*da definire*/ header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore del pacchetto al chiamante.
  */
}
