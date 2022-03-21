#include<stdio.h>
#include<string.h>

int main()
{
 char dest[] = "oldstring";
 const char src[] = "newstring";

 printf("Before move dest = %s, src = %s\n",dest, src);
 memmove(dest, src, 11);
 printf("After move dest = %s, src = %s\n",dest, src);

 return 0;
}
