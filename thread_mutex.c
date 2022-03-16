#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>

int var = 5;
pthread_mutex_t my_mutex;

void thread_inc(void)
{
pthread_mutex_lock(&my_mutex);
var++;
pthread_mutex_unlock(&my_mutex);
//printf("After inc: %d\n", var);
}

void thread_dec(void)
{
pthread_mutex_lock(&my_mutex);
var--;
pthread_mutex_unlock(&my_mutex);
//printf("After dec: %d\n", var);
}

int main()
{
pthread_t thread1, thread2;
pthread_mutex_init(&my_mutex, NULL);

pthread_create(&thread1, NULL, thread_inc, NULL);
pthread_create(&thread2, NULL, thread_dec, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

printf("Var= %d\n", var);
return 0;
}
