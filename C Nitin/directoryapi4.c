#include<sys/stat.h>
#include<stdio.h>
void main(){
mode_t modenew=777;
mode_t modeold=umask(modenew);
printf("%o",modeold);
printf(" Mode Updated to %o Successfully !",modenew);
}
