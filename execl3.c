#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
printf("hII");
execl("/home/ameysystem/execl2", "./execl2", "kernel", "program", 0);

return 0;
}
