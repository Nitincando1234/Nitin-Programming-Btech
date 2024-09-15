#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node*start;
void print(struct node* start){
    int count=0;
    struct node*q;
    q=start;
    if(start ==NULL){
    printf("List is Empty");
}
    while(q!=NULL){
        printf("%d th Element: %d\n",count+1,q->data);
        count++;
        q=q->next;
    }
}
void insertion(struct node* start){
    int option,num;
    printf("What type of insertion\n1.At Begining\n2.At specified Position\n3.At the end\n\t: ");
    scanf("%d",&option);
    struct node *t=(struct node*) malloc(sizeof(struct node));
    switch (option)
    {
    case 1:
        printf("Enter the value to insert: ");
        num;
        scanf("%d",&num);
        t->data=num;
        t->next=start;
        start=t;
        print(start);
        break;
    case 2:
        printf("Enter the position to insert: ");
        int pos;
        scanf("%d",&pos);
        printf("Enter the number to insert: ");
        scanf("%d",&num);
        struct node *q;
        q=start;
        int i=0;
        while(i<pos-2){
        q=q->next;i++;
        }
        t->data=num;
        t->next=q->next;
        q->next=t;
        print(start);
    break;
    case 3:
        printf("Enter the number to insert: ");
        scanf("%d",&num);
        q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        t->data=num;
        q->next=t;
        t->next=NULL;
        print(start);
    break;
    default:
    printf("Bad input.");
        break;
    }
}
void delete(struct node *start){
    struct node*q=start;int num,count=0;int condition=1;
    struct node *p=start;
    printf("Enter the number to delete: ");
    scanf("%d",&num);
    if(start==NULL)
    printf("List is empty.");
    while(q!=NULL){
         if(start->next==NULL){
        printf("Number Deleted at %dth position",count+1);
            free(q);
            start=NULL;
            condition=0;
            break;
        }
       if(q->data==num){
       printf("Number Deleted at %dth position",count+1);
       condition=0;
       p->next=q->next;
       free(q);
       condition=0;
       break;
       }
       p=q;
        q=q->next;count++;
    }
    if(q==NULL && p->data==num){
        free(q);
        p->next=NULL;
        condition=0;
    }
     if(condition==1){
            printf("Number not Found to delete.");
        }
    else{
    print(start);
    }
}
    void search(struct node *start){
        struct node*q;
       q=start;int condition=1;
    int num,count=0;
    printf("Enter the number to search: ");
    scanf("%d",&num);
    if(start ==NULL){
    printf("List is Empty.");
}   
    while(q!=NULL){
       if(q->data==num){
       printf("Number found at %dth position\n",count+1);
       condition=0;}
        q=q->next;count++;
    }
    if(condition==1){
        printf("Number not found.");
    }
    }
void main(){
    
    printf("Creation of linked list: \n");
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d",&size);
    int i=0;
    struct node*q;
    while(i<size){
        struct node*t=(struct node*) malloc(sizeof(struct node));
        printf("Enter the %dth element : ",i+1);
        scanf("%d",&t->data);
        t->next=NULL;
        if(start ==NULL){
            start=t;
            q=t;
        }
        else{
            q->next=t;
            q=t;
        }
        i++;
    }
    print(start);
    insertion(start);
    search(start);
    delete(start);
}