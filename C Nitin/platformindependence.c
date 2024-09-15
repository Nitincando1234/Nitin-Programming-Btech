#include<stdio.h>
void main(){
    int *a1[5];
    int (* a2[5]);
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(a1));
    printf("%d",sizeof(a2));
}