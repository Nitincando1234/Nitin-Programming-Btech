#include<stdio.h>
#include<math.h>
void main(){
  int i=0;int j;int k=0;int n;
  int sum=0;
  printf("Enter the length of the series.");
  scanf("%d",&n);
  printf("%d",sum);  j=k+1;
  while(k<=n){
    printf("%d",j);
    sum=i+j;
    i=j;
    j=sum;
    k++;
  }
}
