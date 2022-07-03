#include <stdio.h>
#include <pthread.h>
void *thread_summation(void *arg);

int sum = 0;

int main(int argc, char **argv)
{
	pthread_t id_t1, id_t2;
	int range1[]={1,50000,1};
	int range2[]={6,200000,0};

	pthread_create(&id_t1, NULL, thread_summation, (void *)range1);
	pthread_create(&id_t2, NULL, thread_summation, (void *)range2);

	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);

	printf("result: %d \n", sum);
	return 0;
}

void *thread_summation(void *arg)
{
	int start=((int*)arg)[0];
	int end=((int*)arg)[1];
	int thr=((int*)arg)[2];
	while(start<=end)
	{
		sum+=start;
		start++;
		printf("%d",thr);
	}
	printf("%d\n",start);
	return NULL;
}
