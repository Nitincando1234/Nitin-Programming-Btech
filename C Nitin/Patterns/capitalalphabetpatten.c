#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
    int a=65;
    for(int j=1;j<=size;j++,a++){
    printf("%c",(char)a);
    }printf("\n");
    }
}