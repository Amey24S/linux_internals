#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void print(void *threadid)
{
printf("HII\n");
while(1);
}

int main()
{
pthread_t thread;
int i, t=0;
printf("Create\n");
i = pthread_create(&thread, NULL, print, NULL);
printf("ID: %d\n", thread);
sleep(5);
t = pthread_cancel(thread);
if (t==0);
	printf("Cancel\n");
printf("tid: %d\n", thread);

return 0;
}
