#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
void main(){
DIR *directory;
if((directory=opendir("dir-api"))==NULL)
	perror("opendir");
if(mkdir("temp_dir",0777)==-1)
	perror("mkdir");
printf("\nDirectory Creation Success !");
if(rmdir("temp_dir")==-1)
	perror("rmdir");
printf("\nDirectory Closed !");
closedir(directory);
fflush(stdout);
printf("\nExiting...");
sleep(2);
}
