#include<stdio.h>
void push(int a[],int top,int size){
    while(top!=size-1){
        top++;
        printf("Enter %dth element:",top+1);
        scanf("%d",&a[top]);
    }
    printf("Insertion Successful !\n");
}
void pop(int a[],int top){
    int temp=a[top];
    while(top!=-1){
        printf("Deleted %d",temp);
        top--;
    }
    printf("Deletion Successful !\n");
}
void main(){
int a[100],top=-1,choice,size,terminator;
printf("Enter the size of the stack: ");
scanf("%d",&size);
while(1){
printf("Enter the operation to perform\n1. Insertion\n2.Deletion\t:");
scanf("%d",&choice);
switch(choice){
    case 1:
    push(a,top,size);
    break;
    case 2:
    pop(a,top);
    break;
    default:
    printf("Bad choice !\n");
}
printf("Want to continue:\n1. Yes\n2. NO\t:");
scanf("%d",&terminator);
if(terminator==1)
continue;
else if(terminator==2)
break;
else
break;}
}