#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include "server.h"

void send_msg(char *msg, int len)
{
	int i;
	pthread_mutex_lock(&mutx);
	for(i=0; i<clnt_cnt; i++)
		write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mutx);
}
