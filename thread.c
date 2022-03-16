#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
	sleep(2);	
	printf("New thread\n");
	return NULL;
}

int main(void)
{
	int ret = pthread_create(&tid, NULL, thread1, NULL);
	if(ret)
		printf("Thread is no created\n");
	else
		printf("Thread created\n");
		//sleep(2);
		pthread_join(tid, NULL);
return 0;
}
