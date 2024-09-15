#include <stdio.h>
void main(){
    int i=1;int n,j,k;
    printf("Enter the number of lines:-");scanf("%d",&n);
    while(i<=n){
        k=1;
    while(k<=n-1){
        printf(" ");k++;
    }    j=1;
    while(j<=i){
        printf("*");j++;
    }printf("\n");i++;
    }
}