#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
int main(){
int fd=open("new.txt",O_RDONLY);
char buffer[500];
if(fd==-1)
	perror("open");
if(read(fd,buffer,sizeof(buffer))==-1)
	perror("read");
printf("%s",buffer);
close(fd);
}
