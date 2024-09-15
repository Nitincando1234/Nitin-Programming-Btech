#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int a=1;
    for(int i=1;i<=size;i++){
    for(int j=1;j<=i;j++,a++){
    printf("%d ",a);
    }
    printf("\n");
    }
}