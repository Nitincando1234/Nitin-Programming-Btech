#include<stdio.h>
#include<math.h>
#include<conio.h>
void main (){
  /*WAP to swap any two numbers without using any third variable.*/
  float n,n1;
  printf("Input any 2 number: ");
  scanf("%f%f",&n,&n1);
  n=n+n1;
  n1=n-n1;
  n=n-n1;
  printf("\nFirst is:%f\nSeocnd is:%f",n,n1);

}