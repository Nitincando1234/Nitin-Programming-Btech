#include<stdio.h>
#include<math.h>
void main(){
  //WAP TO CHECK A NUMBER IS ARMSTRONG OR NOT.
  int i , j, k, count=0;int a=0;
  printf("Enter the number:");
  scanf("%d",&i);k=i;
  while(i>0){
    i=i/10;
  count++;
  }
  i=k;
  while(i>0){
j=i%10;
a=a+pow(j,count);
i=i/10;
  }

  if(a==k){
    printf("The no. is An Amrstrong NO.");
  }else{
    printf("No. is non-Armstrong no.");
  }
}