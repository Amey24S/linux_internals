#include<stdio.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
 printf("Init function\n");
}

void *mythread(void *i)
{
 printf("Thread: %d\n", (int *)i);
 pthread_once(&once, (void *)myinit);
 printf("Exit from thread: %d\n", (int *)i);
}

int main()
{
 pthread_t thread, thread1;

 pthread_create(&thread, NULL, mythread, (void *)1);
 pthread_create(&thread1, NULL, mythread, (void *)2);

printf("EXIT\n"); 
pthread_exit(NULL);
}
