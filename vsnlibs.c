#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "vsnlib.h"



struct response* rtm_newroute_s(struct config* header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_delroute_s(struct config* header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_getroute_s(struct config* header){
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct response* rtm_newaddr_s(struct config* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_deladdr_s(struct config* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_getaddr_s(struct config* header){
  struct rtmsg* rtm = (struct rtmsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}



struct response* rtm_newlink_s(struct config* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_dellink_s(struct config* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_getlink_s(struct config* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso(dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore di questo al chiamante.
  */
}

struct response* rtm_setlink_s(struct config* header){
  struct ifinfomsg* ifi = (struct ifinfomsg*)(NLMSG_DATA(header));
  /*
  1-controllare lo stack in uso (dilemma delle funzioni! come implementiamo questa parte?)
  2-chiamare le funzioni particolari dello stack e salvare i valori di ritorno
  3-analizzare i valori di ritorno e costruire la struttura di risposta
  4-return del puntatore alla struttura
  5-ritornare il puntatore del pacchetto al chiamante.
  */
}
