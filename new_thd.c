#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * process(void *arg)
{
pthread_detach(pthread_self());

printf("Sleepin 2 sec\n");

sleep(2);
printf("Done\n");
}

int main(void)
{
pthread_t tid;

pthread_create(&tid, NULL, process, NULL);

pthread_exit(NULL);
}
