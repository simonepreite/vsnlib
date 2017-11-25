/*
la libreria che contiene le funzioni di configurazione dello stack non
dovrebbe essere caricata dinamicamente.
Il fatto che venga caricato questo modulo piuttosto che un altro è fattibile
solo se esiste la dipendenza quindi invece di usare dlopen si potrebbero usare
direttamente le funzioni di libreria dello stack previsto.
per questa in particolare il lavoro dovrebbe essere facilitato dall'implementazione esistente.
le funzioni preesisteni di LWIPv6 richiedono come argomenti:
struct stack *stack, struct nlmsghdr *msg,void * buf,int *offset
*/

struct response* LWIPv6_addradddel(struct config* cfg){

}

struct response* LWIPv6_getaddr(struct config* cfg){

}

struct response* LWIPv6_adddellink(struct config* cfg){

}

struct response* LWIPv6_getsetlink(struct config* cfg){

}

struct response* LWIPv6_adddelroute(struct config* cfg){

}

struct response* LWIPv6_getroute(struct config* cfg){

}
