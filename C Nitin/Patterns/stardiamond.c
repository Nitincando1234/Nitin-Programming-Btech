#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int ml=size/2+1;//middle line
    int i=1;
    for(i=1;i<ml;i++){
    for(int j=1;j<=size-i;j++)
    printf(" ");
    for(int j=1;j<i;j++)
    printf("*");
    for(int j=1;j<=i;j++)
    printf("*");
    printf("\n");
    }

    for(;i<=size;i++){
    for(int j=1;j<i;j++)
    printf(" ");
    for(int j=0;j<=size-i;j++)
    printf("*");
    for(int j=1;j<=size-i;j++)
    printf("*");
    printf("\n");
    }
}