#define _XOPEN_SOURCE 600\

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockth(void *i)
{
int rc;
int count = 0;

printf("Thread %d, getting spinlock\n",(int *)i);
rc = pthread_spin_lock(&spinlock);

printf("%d thread unlock the spinlock\n", (int *)i);
rc = pthread_spin_unlock(&spinlock);

printf("%d thread complete\n", (int *)i);
return NULL;
}

int main()
{
int rc=0;
pthread_t thread,thread1;

if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
	perror("init");
printf("Main, get lock\n");
rc = pthread_spin_lock(&spinlock);

printf("Main, create lock thread\n");
rc = pthread_create(&thread, NULL, spinlockth, (int *)1);

printf("Main, wait\n");
sleep(6);

printf("Main, unlock now\n");
rc = pthread_spin_unlock(&spinlock);
if(rc==0)
	printf("Successfully unlocked\n");
else
	printf("Unsuccessfull\n");

printf("Main, wait till thread ends\n");
rc = pthread_join(thread, NULL);

printf("Complete\n");
return 0;
}
