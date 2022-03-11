#include<stdio.h>

int main(int argc, char *argv[])
{
int i;
printf("File name: %s\n", argv[0]);
printf("No of arg: %d\n", argc);
printf("Arg passed: ");
for(i=0;i<argc;i++)
	printf("%s",argv[i]);
printf("\n");
return 0;
}
