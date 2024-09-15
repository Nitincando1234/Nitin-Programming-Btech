#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;int coeff;
};
struct node *start1,*start2,*start3;
void create(struct node *start, int size) {
    int i = 0;
    struct node *current =NULL;  // Use a single pointer
    while (i < size) {
        int num, coeffl;
        printf("Data and Coeff %d: ", i + 1);
        scanf("%d%d", &num, &coeffl);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->coeff = coeffl;
        newNode->next = NULL;
        if (start == NULL) {  // Handle empty list case
            start = newNode;
            current = start;
        } else {
            current->next = newNode;
            current = newNode;
        }
        i++;
    }}

void add(struct node* starta,struct node*startb,struct node *startc){
    struct node*p=starta,*q,*t;
    p=starta;q=startb;
    while(p!=NULL&&q!=NULL){
    struct node *nodePrime=(struct node *)malloc (sizeof(struct node));
    if(p->coeff>q->coeff){
    nodePrime->data=p->data;
    nodePrime->coeff=p->coeff;
    nodePrime->next=NULL;
    if(startc==NULL){
    startc=nodePrime;
    t=nodePrime;
    }
    else{
    t->next=nodePrime;
    t=nodePrime;
    p=p->next;}
    }
    if(q->coeff>p->coeff){
    nodePrime->data=q->data;
    nodePrime->coeff=q->coeff;
    nodePrime->next=NULL;
    if(startc==NULL){
    startc=nodePrime;
    t=startc;
    }
    else{
    t->next=nodePrime;
    t=nodePrime;
    q=q->next;
    }
    }
    else{
    nodePrime->data=p->data+q->data;;
    nodePrime->coeff=q->coeff;
    if(startc==NULL){
    t=nodePrime;
    q=q->next;
    p=p->next;
    startc=nodePrime;
    t=startc;
    }else{
    t->next=nodePrime;
    q=q->next;
    p=p->next;
    t=nodePrime;
    }
    }
    }
    while(p!=NULL){
    struct node *nodePrime=(struct node *)malloc(sizeof(struct node));
    if(startc==NULL){
    t=nodePrime;
    q=q->next;
    p=p->next;
    startc=nodePrime;
    t=startc;
    }else{
    t->data=p->data;
    t->coeff=p->coeff;
    t->next=nodePrime;
    t=nodePrime;
    p=p->next; }
    }
    while(q!=NULL){
    struct node *nodePrime=(struct node *)malloc(sizeof(struct node));
    if(startc==NULL){
    t=nodePrime;
    q=q->next;
    p=p->next;
    startc=nodePrime;
    t=startc;
    }else{
    t->data=q->data;
    t->coeff=q->coeff;
    t->next=nodePrime;
    t=nodePrime;
    q=q->next; }
    }
}
void print(struct node *start){
    if(start==NULL)
    printf("List is empty");
    struct node* qp=start;
    while(qp!=NULL){
        printf("%d%d",qp->data,qp->coeff);
        printf("+");
        qp=qp->next;
    }
}
void main(){
int size1,size2,size;
printf("Enter the size of the linkedlist 1: ");
scanf("%d",&size1);
printf("Enter the size of the linkedlist 2:");
scanf("%d",&size2);
printf("First node:\n");
create(start1,size1);
printf("Second node:\n");
create(start2,size2);
add(start1,start2,start3);
printf("After Addition:\n");
print(start3);
}