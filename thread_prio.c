#include<stdio.h>
#include<pthread.h>

void *my(void *i)
{
printf("Thread: %d\n", (int *)i);
}

main()
{
 pthread_t tid;
 struct sched_param param;
 int priority, policy, ret;
 
 ret = pthread_getschedparam (pthread_self(), &policy, &param);
 
 printf("Main Thread----\n Policy: %d \tPriority: %d\n", policy, param.sched_priority);

 policy = SCHED_RR;
 param.sched_priority = 3;
 pthread_setschedparam (pthread_self(), policy, &param);

 pthread_getschedparam (pthread_self(), &policy, &param);

 printf("\n----Main thread----\n Policy : %d \tPriority: %d\n", policy, param.sched_priority);
}
