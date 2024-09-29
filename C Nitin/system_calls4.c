#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
int fd=open("new.txt",O_RDONLY);
if(fd==-1)
	perror("open");
off_t offset;
if((offset=lseek(fd,5,0))==-1)
	perror("offset");
printf("Successfully gained\noffset:%zd\n",offset);
if((close(fd))==-1)
	perror("close");
printf("Closed file !");

}
