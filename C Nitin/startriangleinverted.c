#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int j=0;
    for(int i=0;i<size;i++){
    for( j=size-i;j>0;j--){
    printf("*");
    }printf("\n");
    }

}