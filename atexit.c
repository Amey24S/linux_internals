#include<stdio.h>

void call1(void) {printf("call 1\n");}
void call2(void) {printf("call 2\n");}
void call3(void) {printf("call 3\n");}

int main()
{
printf("1\n");
atexit(call1);

printf("2\n");
atexit(call2);

printf("3\n");
atexit(call3);

exit(0);
}

