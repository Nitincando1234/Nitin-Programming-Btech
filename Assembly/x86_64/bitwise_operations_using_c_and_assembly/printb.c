#include<stdio.h>
void printb(long long n){
    long long s,c;
    for (c=63;c>=0;c--){
        s=n>>c;
        if((c+1)%8==0)//to print spaces for every 8 bit group
        printf(" ");
        if(s&1)
        printf("1");
        else
        printf("0");
    }
    printf("\n");
}