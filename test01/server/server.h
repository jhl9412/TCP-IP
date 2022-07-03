#ifndef __SERVER_H__
#define __SERVER_H__
#include <stdlib.h>
#include <pthread.h>
#define BUF_SIZE 100
#define MAX_CLNT 256

extern void *handle_clnt(void *arg);
extern void send_msg(char *msg, int len);
extern void error_handling(char *msg);

static int clnt_cnt=0;
static int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

#endif
