#include<stdio.h>
void main(){
    int a[100],option,size,i,num,pos;
    printf("Enter the size:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++){
        printf("Enter the %dth element:",i+1);
        scanf("%d",&a[i]);
    }
    printf("What you want to perform on this array\n");
    printf("1.Insertion\n2.Deletion\n");
    scanf("%d",&option);
    i=0;
    switch(option){
    case 1:
    printf("Enter the number to insert:");
    scanf("%d",&num);
    printf("Enter the position for insertion:");
    scanf("%d",&pos);
    if(pos>size||pos<0){
        printf("Invalid Position!");
    }
    else{
    for(i=size;i>=pos;i--){
    a[i]=a[i-1];
    }size+=1;
    a[pos-1]=num;
    }
    printf("After insertion Array elements are as follows:\n");
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    break;
    case 2:
    printf("Enter the position for deletion:");
    scanf("%d",&pos);
    for(i=pos-1;i<size;i++){
        a[i]=a[i+1];
    }size--;
    printf("After deletion Array elements are as follows:\n");
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    break;
    default:
    printf("Wrong option input\nPlease choose in b/w 1 and 2 !");
    }
}