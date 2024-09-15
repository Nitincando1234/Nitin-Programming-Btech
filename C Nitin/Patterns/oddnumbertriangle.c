#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
    for(int j=1,a=1;j<=i;j++,a+=2){
    printf("%d",a);
    }printf("\n");
    }
}