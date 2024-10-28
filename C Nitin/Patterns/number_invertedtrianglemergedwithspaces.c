#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int nspace=1,nstar=size,a=1;
    for(int i=1;i<=(size*2)+1;i++,a++)printf("%d",a);
    printf("\n");
    for(int i=1;i<=size;i++){
        int a=1;
        for(int j=1;j<=nstar;j++,a++)printf("%d",a);
        for(int j=1;j<=nspace;j++,a++)printf(" ");
        for(int j=1;j<=nstar;j++,a++)printf("%d",a);
        printf("\n");
        nspace+=2;
        nstar--;
    }
}