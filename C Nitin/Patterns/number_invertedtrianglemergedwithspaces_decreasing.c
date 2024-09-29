#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int nspace=1,nstar=size-1;
    for(int i=1;i<=size;i++)
    printf("%d",i);
    for(int i=size-1;i>=1;i--)
    printf("%d",i);
    printf("\n");
    for(int i=1;i<=size-1;i++){
        int a=1;
        for(int j=1;j<=nstar;j++,a++)printf("%d",a);
        for(int j=1;j<=nspace;j++)printf(" ");
        a-=1;
        for(int j=1;j<=nstar;j++,a--)printf("%d",a);
        printf("\n");
        nspace+=2;
        nstar--;
    }
}