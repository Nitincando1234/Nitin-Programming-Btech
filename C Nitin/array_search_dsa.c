#include<stdio.h>
void main(){
    int a[100],size,num;int i;
    printf("Enter the Size of the array:\n");
    scanf("%d",&size);
    printf("Enter the elements:");
    for(i=0;i<size;i++){
        printf("Enter the %dth element:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to search:");
    scanf("%d",&num);
    for(i=0;i<size;i++){
        if(num==a[i]){
            break;
        }
    }
    printf("%d found at %dth position.",num,i+1);
}