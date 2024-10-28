#include<stdio.h>
#include<sys/stat.h>
void main(){
struct stat buffer;
if((stat("new.txt",&buffer))==-1){
	perror("stat");
	return;
}
printf("File Size: %ld\n",buffer.st_size);
printf("File Permissions: %o\n",buffer.st_mode);
}
