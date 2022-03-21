#include<stdio.h>
#include<string.h>

int main()
{
 const char str[] = "linuxkernel.com";
 const char ch = '#';

 printf("String before set: %s \n",str);
 
 memset(str, ch, 5);
 printf("After set: %s \n",str);

 return 0;
}
