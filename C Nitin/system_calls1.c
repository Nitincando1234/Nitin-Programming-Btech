#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
int fd=open("new.txt",S_IRWXU,O_RDONLY);
if(fd==-1){
perror("open");
return ;
}
else{
printf("File opening success !");
}
}
