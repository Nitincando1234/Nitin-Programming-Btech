#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
void main(){
DIR *directory;
directory=opendir("dir-api");
if(directory==NULL)
	perror("opendir");
printf("Opened the directory succesfully ! ");

}
