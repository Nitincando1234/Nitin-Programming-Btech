#include <stdio.h>
void main(){
    long int n,fact=1;
    printf("Enter the number:");
    scanf("%ls",&n);
   for(int i=n;i!=0;i--){
    fact=fact*i;
   } printf("Factorial is: %ls",(long)fact);
    
}