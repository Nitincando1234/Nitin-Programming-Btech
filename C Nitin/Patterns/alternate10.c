#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int a=0;
    for(int i=1 ;i<=size;i++){
    if(i%2==0)a=0;
    else a=1;
    for(int j=1;j<=i;j++){
    printf("%d",a);
    if (a==0)a=1;
    else a=0;
    }printf("\n");
    }
}