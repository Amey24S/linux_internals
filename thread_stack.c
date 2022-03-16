#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void fn( void* para)
{
sleep(2);
return 0;
}

int main()
{
pthread_attr_t Attr;
pthread_t t1;
void *stk;
size_t size;
int err;

size_t my_stksize = 3000000;
void *my_stk;

pthread_attr_init(&Attr);

pthread_attr_getstacksize(&Attr, &size);
pthread_attr_getstackaddr(&Attr, &stk);

printf("Default: Addr=%08x & size:%d\n", stk, size);

my_stk=(void *)malloc(my_stksize);

pthread_attr_setstack(&Attr, my_stk, my_stksize);
pthread_create(&t1, &Attr, fn, NULL);

pthread_attr_getstack(&Attr, &stk, &size);
printf("New stack: addr=%08x and size=%d\n", stk, size);
sleep(3);

return 0;
}
