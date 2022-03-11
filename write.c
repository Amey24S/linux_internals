#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd, len;
char write_buf[50] = "hi, how are you?";
char read_buf[50];

fd = open("kernel.txt", O_CREAT |O_RDWR, 777);
printf("fd is %d\n",fd);

len = write(fd,write_buf,50);
printf("value= %d\n",len);

lseek(fd, 4, SEEK_SET);
read(fd, read_buf, len);
printf("%s",read_buf);

close(fd);
return 0;
}
