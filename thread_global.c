#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

int var = 5;

void thread_inc(void)
{
var++;
printf("After inc: %d\n", var);
}

void thread_dec(void)
{
var--;
printf("After dec: %d\n", var);
}

int main()
{
pthread_t thread1, thread2;

pthread_create(&thread1, NULL, thread_inc, NULL);
pthread_create(&thread2, NULL, thread_dec, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

printf("Var= %d\n", var);
return 0;
}
