#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
pid_t pid1;
int op, stat;

while(1)
{
printf("Enter 1 to execl and 0 to exit\n");
scanf("%d",&op);
if(!op)
{
	exit(0);
	printf("/n");
}
if(fork()==0)
	{
	execl("/bin/ls", "ls", "-lh", 0);
	exit(0);
	}
}
return 0;
}
