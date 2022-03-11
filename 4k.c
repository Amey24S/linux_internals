#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd1, fd2;
char buf[4000];

fd1 = open("4k.txt", O_CREAT | O_RDWR, 777);
printf("value is %d\n", fd1);

fd2 = write(fd1, buf, 4000);

int close(int fd1);
return 0;
}
