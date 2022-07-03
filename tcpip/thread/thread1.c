#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void* thread_main(void *arg);

int main(int argc, char **argv)
{
	pthread_t t_id;
	int thread_param=5;
	/*
		thread는 동시에 작업하는 것처럼 보이는데 병렬이 아니라 병행해서 작업
		프로세스가 종료되면 해당 프로세스 내에 생성된 쓰레드도 종료.
	 */
	if(pthread_create(&t_id, NULL, thread_main, (void*)&thread_param)!=0)
	{
		puts("pthread_create() error");
		return -1;
	};
	sleep(10);//프로세스의 종료를 막기 위해 main thread를 10초간 쉬게.
	puts("end of main");
	return 0;
}
//thread function
void* thread_main(void *arg)
{	
	int i;
	int cnt=*((int*)arg);
	for(i=0; i<cnt; i++)
	{
		sleep(1);
		puts("ruuning thread");
	}
	return NULL;
}
