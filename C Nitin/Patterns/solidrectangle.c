#include<stdio.h>
void main(){
    int breadth,length;
    printf("Enter the size of the pattern breadth: ");
    scanf("%d",&breadth);
    printf("Enter the size of the pattern length: ");
    scanf("%d",&length);
    for(int i=0;i<length;i++){
    for(int j=0;j<breadth;j++){
        printf("*");
    }printf("\n");
    }
}