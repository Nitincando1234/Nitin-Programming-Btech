
#include <stdio.h>
#include <math.h>
void main(){
    int j,a=0,n;
    printf("Enter the number:");
    scanf("%d",&n);
    int count=0;
    int k=n;
    while(n>0){
       
        count++; n=n/10;
    }
    n=k;
    while(n>0){
        j=n%10;
        a= a+pow(j,count);n=n/10;
    }
    if(a==k){
        printf("No. is an Armstrong No.");
    }
    else{
        printf("No. is not an Armstrong No.");
    }
}