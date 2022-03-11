#include<stdio.h>
#include<fcntl.h>

int main()
{
int fd1, fd2;

fd2 = open("copy.txt", O_RDONLY, 777);
printf("num is %d",fd2);
close(fd2);
return 0;
}    
