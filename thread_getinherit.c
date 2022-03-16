#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/mman.h>

void * Proc(void* para)
{
 sleep(3);
 return 0;
}

int main()
{
 pthread_attr_t Attr;
 pthread_t id;
 int err, info;
 
 pthread_attr_init(&Attr);
 pthread_attr_getinheritsched(&Attr, &info);

 switch(info)
	{
	 case PTHREAD_INHERIT_SCHED:
	 	printf("Sched\n");
		break;
	 case PTHREAD_EXPLICIT_SCHED:
		printf("Explicit\n");
		break;	
	}

 pthread_attr_setinheritsched(&Attr, PTHREAD_EXPLICIT_SCHED);
 pthread_attr_getinheritsched(&Attr, &info);

 switch(info)
	{
	 case PTHREAD_INHERIT_SCHED:
	 	printf("Sched\n");
		break;
	 case PTHREAD_EXPLICIT_SCHED:
		printf("Explicit\n");
		break;	
	}

 pthread_create(&id, &Attr, Proc, NULL);

 return 0;
}
