#include<stdio.h>
#include<stdlib.h>
struct node{
    int data,expo;
    struct node * next;
};
struct node *start1,*start2,*start;
struct node * createPoly(){
    struct node* q,*startLocal=NULL;
    int value,exponent;
    while(1){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    fflush(stdin);
    printf("Enter the value of the node: (Enter -1 to terminate here) ");
    scanf("%d",&value);
    if(value==-1)break;
    if(value==0){
    printf("value can't be zero it is simple calculator please don't spoil it\1 :)");
    return 0;}
    printf("Enter the exponent for the value: ");
    fflush(stdin);
    scanf("%d",&exponent);
    newNode->data=value;
    newNode->expo=exponent;
    newNode->next=NULL;
    if(startLocal==NULL){
    startLocal=newNode;
    q=startLocal;
    }
    else{
    while(q->next!=NULL){
    q=q->next;
    }
    q->next=newNode;
    }}
    return startLocal;
}
void addPoly(){
    struct node*q,*newNode;
    struct node*poly1=start1;
    struct node*poly2=start2;
    while(poly1!=NULL && poly2!=NULL){
    newNode=(struct node*)malloc(sizeof(struct node));
    if((poly1->expo) > (poly2->expo)){
    newNode->data=poly1->data;
    newNode->expo=poly1->expo;
    poly1=poly1->next;
    }
    else if(poly2->expo > poly1->expo){
    newNode->data=poly2->data;
    newNode->expo=poly2->expo;
    poly2=poly2->next;
    }
    else{
    newNode->data=poly1->data+poly2->data;
    newNode->expo=poly1->expo;
    poly1=poly1->next;
    poly2=poly2->next;
    }
    newNode->next=NULL;
    if(start==NULL)
    {start=newNode;
    q=start;}
    else{
    q->next=newNode;
    q=q->next;
    }}
    while(poly1!=NULL){
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=poly1->data;
    newNode->expo=poly1->expo;
    newNode->next=NULL;
    q->next=newNode;
    q=q->next;
    poly1=poly1->next;
    }
    while(poly2!=NULL){
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=poly2->data;
    newNode->expo=poly2->expo;
    newNode->next=NULL;
    q->next=newNode;
    q=q->next;
    poly2=poly2->next;
    }
}
void printPoly(struct node*startLocal){
    struct node*q=startLocal;
    if(startLocal==NULL)
    printf("Empty list !");
    else{
    while(q!=NULL){
    printf("%d^%d",q->data,q->expo);
    if(q->next!=NULL)
    printf("+");
    q=q->next;
    }
    }
    printf("=0\n");
}
void main(){
    printf("Enter the values of the polynomial 1:\n");
    start1=createPoly();
    printf("Enter the values of the polynomial 2:\n");
    start2=createPoly();
    printPoly(start1);
    printPoly(start2);
    addPoly();
    printPoly(start);
}