#include<stdio.h>
int main(){
    int a[100],size,num,i;
    printf("Enter the Size:");scanf("%d",&size);
    for( i=0;i<size;i++){
        printf("Enter the %dth value:",i+1);scanf("%d",&a[i]);
    }printf("Enter the value to search:");scanf("%d",&num);
    for ( i=0;i<size;i++){
        if(num==a[i]){ break;}

    }if(i==size){
        printf("Not found.");
    }else{printf("Element is at %dth position.",i+1);}
    return 0;
}