#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
    for(int j=0;j<size-i-1;j++)
    printf(" ");
    for(int j=0;j<size;j++)
    printf("*");
    printf("\n");
    }
}