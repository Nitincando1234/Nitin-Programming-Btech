#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    if(size%2==0)size+=1;
    for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
    if((i==size/2+1)||(j==size/2+1))
    printf("*");
    else
    printf(" ");
    }
    printf("\n");
    }
}