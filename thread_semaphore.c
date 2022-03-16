#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>

int var = 5;
sem_t my_sem;

void thread_inc(void)
{
sem_wait(&my_sem);
var++;
sem_post(&my_sem);
//printf("After inc: %d\n", var);
}

void thread_dec(void)
{
sem_wait(&my_sem);
var--;
sem_post(&my_sem);
//printf("After dec: %d\n", var);
}

int main()
{
pthread_t thread1, thread2;
sem_init(&my_sem, 0, 1);

pthread_create(&thread1, NULL, thread_inc, NULL);
pthread_create(&thread2, NULL, thread_dec, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

printf("Var= %d\n", var);
return 0;
}
