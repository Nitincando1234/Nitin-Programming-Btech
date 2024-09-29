#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
    char a='A';
    for(int j=0;j<size-i-1;j++)
    printf(" ");
    for(int j=0;j<i;j++,a++)
    printf("%c",a);
    for(int j=0;j<=i;j++,a--)
    printf("%c",a);
    printf("\n");
    }
}