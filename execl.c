#include<stdio.h>
#include<unistd.h>

int main()
{
printf("please stop\n");

execl("/home/ameysystem/static_main", "./static_main", 0);

printf("I said stop\n");
printf("I said stop\n");

return 0;
}
