#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main(){
int fd;
ssize_t	bytes_written;
char *buffer="Hi This is Nitin Sharma";
if((fd=open("new.txt",O_WRONLY,S_IRWXU))==-1)
	perror("open");
if((bytes_written=write(fd,buffer,strlen(buffer)))==-1)
	perror("write");
if(close(fd)==-1)
	perror("close");
printf("Successfully written %zd bytes !",bytes_written);
}
