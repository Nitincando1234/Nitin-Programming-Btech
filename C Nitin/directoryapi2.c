#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
void main(){
DIR *directory;
struct dirent *dirdetails;
if((directory=opendir("dir-api"))==NULL)
	perror("opendir");
printf("Directory Details/Enteries:\n");
while((dirdetails=readdir(directory))!=NULL)
	printf("\n%s",dirdetails->d_name);
if(closedir(directory)!=0)	
	perror("closedir");
printf("Exited Successfully !");
}
