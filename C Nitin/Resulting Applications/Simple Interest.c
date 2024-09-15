#include<stdio.h>
#include<math.h>
void main (){
    float p, r,t;float si;
    printf("Enter The Principle Amount, Rate & Tenure: ");
    scanf("%f%f%f",&p,&r,&t);
    
    si=p*r*t/100;
    printf("The value of Simple Interest is:%.2f",si); 
}