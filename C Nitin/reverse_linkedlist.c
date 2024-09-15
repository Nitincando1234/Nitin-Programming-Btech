#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;};
	struct node *start;
void print(struct node *start){
	struct node *q;int i=0;
	q=start;
	while(q!=NULL){
	printf("\n%dth element: %d",i+1,q->data);
	i++;
	q=q->next;	
	}
	}
void reverseprint(struct node*start){
	struct node * prevnode, * currnode, *nextnode;
	currnode=start;nextnode=start;
	while(nextnode!=NULL){
		nextnode=nextnode->next;
		currnode->next=prevnode;
		prevnode=currnode;
		currnode=nextnode;
		}
		start=prevnode;
		print(start);
	}
void main(){
	int size,i=0;
	printf("Enter the size of the list: ");
	scanf("%d",&size);
	while(i<size){
		struct node*q;
		struct node*t=(struct node *)malloc(sizeof(struct node));
		printf("Enter %dth element: ",i+1);
		scanf("%d",&t->data);
		t->next=NULL;
		if(start ==NULL){
		start=t;q=t;
		}
		else{
		q->next=t;
		q=t;}
	i++;	}
		print(start);
		printf("\nDo you want to reverse the list:\n1.Yes\n2.No\t:");
		int option;
		scanf("%d",&option);
		if(option==1)
		reverseprint(start); 
		else
		printf("Bad Choice.");}