#include<stdio.h>
int main(){
int a[100],size,front=-1,rear=-1;
int elem;
printf("Enter the size of the queue: ");
scanf("%d",&size);
if(front ==-1 )
{printf("Underflow Occured\n Enter the elements\n");
front=rear=0;}
while(rear<size){
    printf("Enter the %dth element: ",rear+1);
    scanf("%d",&a[rear]);
    rear++;
}
printf("Now perfroming Deletion\n");
while(front!=rear){
    elem=a[front];
    printf("Deleted: %d\n",elem);
    front++;
}
return 0 ;
}