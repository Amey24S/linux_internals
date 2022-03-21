#include<stdio.h>
#include<string.h>

int main()
{
 const char str[] = "linux.kernel.com";
 const char ch = '.';
 char *ret;

 printf("String before scan: %s \n",str);
 
 ret = memchr(str, ch, strlen(str));
 //printf("Address is %c\n", *ret);
 printf("After scan **%c** is - **%s**\n",ch,ret+5);

 return 0;
}
