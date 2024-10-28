#include<stdio.h>
#include<math.h>
void main (){
    float p, r,t;float ci;
    printf("Enter The Principle Amount, Rate & Tenure: ");
    scanf("%f%f%f",&p,&r,&t);
    
    ci=p*pow((1+r/100),t);
    printf("The value of Compound Interest is:%.2f",ci); 
}