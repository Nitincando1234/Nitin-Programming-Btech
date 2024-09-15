#include<stdio.h>
#include<stdlib.h>
#define size 5
int r=-1,f=-1;
struct pq{int data,priority;}pq[size];
void enqueue(int data,int priority){
    if(f==0&&r==size-1){printf("Queue Overflow !");return;}
    else if(f==-1){r=f=0;
    pq[r].data=data;
    pq[r].priority=priority;
    }
    else{
    r++;
    pq[r].data=data;
    pq[r].priority=priority;
    }
}
int gethighestpriority(){
    int HeighestPriority=pq[0].priority;
    int index=0;
    for(int i=f;i<=r;i++){
        if(pq[i].priority>HeighestPriority){HeighestPriority=pq[i].priority;
        index=i;}
    }
    printf("Heighest Priority Element is: %d with Priority: %d",pq[index].data,HeighestPriority);
    return index;
}
void Dequeue(){
    int tempFront=f;
    int high=gethighestpriority();
    printf("\nRemoved %d with priority %d",pq[high].data,pq[high].priority);
    if(r==-1)printf("Queue Underflow !");
    else{
    pq[high].data=pq[high+1].data;
    pq[high].priority=pq[high+1].priority;
    r--;
    }

}
void print(){
        printf("|Data|\t|Priority|\n");
    for(int i=f;i<=r;i++){
        printf("%d\t%d\n",pq[i].data,pq[i].priority);
    }
}
int main(){
while(1){
printf("\nEnter the operation\n1.Enqueue\n2.Dequeue\n3.Print\n4.Find the Heighest Priority Element\n5 or o/w. Exit\n:");
int choice;
scanf("%d",&choice);
switch (choice)
{
case 1:
    printf("Enter the value and priority to Insert in the Queue: ");
    int data,priority;
    scanf("%d",&data);
    scanf("%d",&priority);
    enqueue(data,priority);
    break;
case 2:
    Dequeue();
    break;
case 3:
    print();
    break;
case 4:
    gethighestpriority();
    break;
default:
    printf("You have exited implicitly !");
    break;
    }}
return 0 ;
}