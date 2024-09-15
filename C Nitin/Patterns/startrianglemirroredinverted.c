#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int nstar=size,nspace=0;
    for(int i=1;i<=size;i++){
    for(int j=1;j<=nspace;j++)
    printf(" ");
    for(int j=1;j<=nstar;j++)
    printf("*");
    printf("\n");
    nstar--;
    nspace++;
    }
}