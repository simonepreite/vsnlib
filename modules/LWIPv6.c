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

LWIPv6_addradddel(){

}

LWIPv6_getaddr(){

}

LWIPv6_adddellink(){

}

LWIPv6_getsetlink(){

}

LWIPv6_adddelroute(){

}

LWIPv6_getroute(){

}
