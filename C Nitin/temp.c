#include<stdio.h>
int main(){
int a[10];
for(int i=0;i<10;i++){
printf("Enter the %dth Element: ",i+1);
scanf("%d",&a[i]);
}int loc,min,temp,j;
for(int i=1;i<10;i++){
    temp=a[i];
    j=i-1;
    while(a[j]>temp&&j>=0){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
    }
for (int i = 0; i <10; i++)
{
    printf("%d\t",a[i]);
}


return 0 ;
}