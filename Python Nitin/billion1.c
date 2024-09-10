#include<stdio.h>
int main(){
    int n=0;
    int i=0;
    while(n<1000000000000){
        printf("%d\n",n);
        n=n+1;
        i++;
        printf("\t%d\n",i);
    }
    printf("%d",n);
    return 0;
}