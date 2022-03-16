#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

struct arg{
int i;
char c;
}

void* structure_print(void *parameters)
{
 struct arg *p = (struct arg*)parameters;
 printf("Struct data=%c & count=%i\n", p->c, p->i);
 return NULL;
}

int main()
{
 pthread_t thread1;
 pthread_t thraed2;

 struct arg thread1_args;
 struct arg thread2_args;

 pthread_create(&thread1, NULL, structure_print, NULL);
 pthread_create(&thread2, NULL, structure_print, NULL);

 thread1_args.i = 20;
 thread1_args.c = "amey";
 thread2_args.i = 40;
 thread2_args.c = "sone";

 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);

 return 0;
}
