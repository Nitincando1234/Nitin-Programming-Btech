#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int nspace=1,nstar=size;
    for(int i=1;i<=(size*2)+1;i++)printf("*");
    printf("\n");
    for(int i=1;i<=size;i++){
        for(int j=1;j<=nstar;j++)printf("*");
        for(int j=1;j<=nspace;j++)printf(" ");
        for(int j=1;j<=nstar;j++)printf("*");
        printf("\n");
        nspace+=2;
        nstar--;
    }
}