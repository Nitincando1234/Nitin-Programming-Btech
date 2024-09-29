#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
    char c=65;
    for(int j=1;j<=i;j++,c++){
    printf("%c",c);
    }printf("\n");
    }
}