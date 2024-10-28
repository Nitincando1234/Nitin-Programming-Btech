#include<stdio.h>
int main(){
int a[100],size;int i;
    printf("Enter the Size of the array:");
    scanf("%d",&size);
    printf("Enter the elements:\n");
    for(i=0;i<size;i++){
        printf("Enter the %dth element:",i+1);
        scanf("%d",&a[i]);
    
    }
    for(i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
               a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    printf("After sorting elements are:\n");
    for(i=0;i<size;i++){printf("%d",a[i]);}
return 0 ;
}