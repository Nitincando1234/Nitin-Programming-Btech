#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node{
    int data;
    struct node* next;
};
struct node *start=NULL;
void creation(){
    struct node *q;
    for(int i=0;i<size;i++){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number: ");
    scanf("%d",&t->data);
    t->next=NULL;
    if(start==NULL){
    start=t;
    q=t;}
    else{
    q->next=t;
    q=t;
    }}
}
void deletion(){
    printf("Where to Delete\n1.At the Beginning\n2.At the specified Position\n3.At the end\n: ");
    int choice;
    scanf("%d",&choice);
    struct node *p;
    struct node *q=start;
    switch(choice){
    case 1:
    q=q->next;
    free(start);
    start=q;
    break;
    case 2:
    printf("Enter the specified position: ");
    int pos;
    scanf("%d", &pos);
    p=q;
    for(int i=0;i<pos-1;i++){
        p=q;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    break;
    case 3:
    p=q;
    while(q->next!=NULL){
    p=q;
    q=q->next;
    }
    free(q);
    p->next=NULL;
    break;
    default:
    printf("Wrong Location\n");
    break;
    }
}
void searching(){
    struct node*q=start;
    int num,i=0;
    printf("Enter the Number to search: ");
    scanf("%d",&num);
    while(q!=NULL){
        if(num==q->data)break;
        printf("%d\t",q->data);
        q=q->next;i++;
    }
    printf("Found at the position: %d",i+1);
}
void insertion(){
    struct node*q=start,*p=q;int choice;
    printf("Enter the position where to insert: \n1.At the Begining\n2.At the specified position\n3.At the End\n: ");
    scanf("%d",&choice);
        struct node *t=(struct node*)malloc(sizeof(struct node));
        int num,pos;
    switch(choice){
        case 1:
        printf("Enter the Number to insert: ");
        scanf("%d",&t->data);
        t->next=NULL;
        start=t;
        start->next=q;
        break;
        case 2:
        printf("Enter the number to insert: ");
        scanf("%d",&num);
        printf("Enter the position to insert: ");
        scanf("%d",&pos);
        t->data=num;
        t->next=NULL;
        for(int i=0;i<pos-1;i++){
            p=q;
            q=q->next;
        }
        p->next=t;
        t->next=q;
        break;
        case 3:
        printf("Enter the number to insert: ");
        scanf("%d",&num);
        p=q;
        while(q->next!=NULL){
            p=q;
            q=q->next;
        }
        t->data=num;
        t->next=NULL;
        q->next=t;
        break;
        default: 
        printf("Invalid Choice !");
        break;
    }
}
void printing();
void Reversed_Print(){
    struct node*prev,*curr,*nextN;
    prev=NULL;
    curr=nextN=start;
    while(curr!=NULL){
        nextN=nextN->next;
        curr->next=prev;
        prev=curr;
        curr=nextN;
    }
    start=prev;
    printing();
}
void printing(){
    struct node*q=start;
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->next;
    }
}
int main(){
int choice;
printf("Size of the LinkedList will be: %d",size);
while(1){
printf("\n1.Creation\n2.Deletion\n3.Searching\n4.Printing\n5.Insertion\n6.Reversed_Print:");
scanf("%d",&choice);
switch(choice){
    case 1:
    creation();
    break;
    case 2:
    deletion();
    break;
    case 3:
    searching();
    break;
    case 4:
    printing();
    break;
    case 5:
    insertion();
    break;
    case 6:
    Reversed_Print();
    break;
    default: 
    printf("Wrong Choice !");
}}
return 0 ;
}