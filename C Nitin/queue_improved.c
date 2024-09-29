#include<stdio.h>
#define size 5
int rear=-1,front=-1;
int a[size];
void insert() {
    int num;
    if (front == 0 && rear == size - 1) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
     else {
        rear++;
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    a[rear] = num;
}

void delete(){
    if(front==rear+1)
    {
        printf("Queue is completely empty !\n");
        front=0;
    }
    else{
        printf("Removed %d\n",a[front++]);
    }
}
void print(){
    int tempfront=front;
    while(tempfront<=rear){
        printf("%d\t",a[tempfront]);
        tempfront++;
    }
}
int main(){
printf("Size of the Queue is: %d",size);
while(1){
printf("\nWhich Operation to Perform: \n1.Insertion\n2.Deletion\n3.Print\n:");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
print();
break;
default:
printf("Invalid Choice !");
}
}
return 0 ;
}