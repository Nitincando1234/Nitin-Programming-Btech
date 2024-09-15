#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
int fd=creat("new.txt",S_IRWXU);
if(fd==-1)
	perror("creat");
else
	printf("File creation success !\n");
if(close(fd)==0)
	printf("File successfully closed !\n");
}
