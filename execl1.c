#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int pid;

pid = fork();

if(pid==0)
{
 execl("/bin/ls", "ls", "-lh", 0);
}
else
{
printf("Parent\n");
}
return 0;
}
