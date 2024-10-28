#include<stdio.h>
void main(){
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    int ml=size/2+1,nspace=size/2,nstar=1;
    for(int i=1;i<=size;i++){
        for(int j=1;j<=nspace;j++)
        printf(" ");
        for(int j=1;j<=nstar;j++)
        printf("*");
        if(i<ml){
        nspace--;
        nstar+=2;}
        else{
        nspace++;
        nstar-=2;
        }
        printf("\n");
    }
}