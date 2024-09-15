#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void print(struct node* head){
struct node *temp=head;
int i=0;
if(head==NULL){
    printf("LinkedList is Empty.");
}
while(temp!=NULL){
printf("\n%d Element: %d",i+1,temp->data);
temp=temp->next;i++;
}
}
void insert(struct node*head)
{   int option,num;
    printf("Please Enter the value to Insert: ");
    scanf("%d",&num);
    printf("\nType of Insertion (1.At Beginnig, 2.At specified Index, 3.At End: ): ");
    scanf("%d",&option);
    if(option==1){
    struct node*temp;
    temp=head;
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=temp;
    head=new;
    print(head);
    }
    if(option==2){
     struct node* temp=head;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    printf("Enter the position:");
    int pos;
    scanf("%d",&pos);
    while (--pos)
    {
        temp=temp->next;}
        new->next=temp;
        temp->next=new;
    
    print(head);
    
    }
}
void search(){}
void delete(){}

void main(){
struct node *head,*temp;struct node *new;
head=0;int size;
printf ("Enter the size of the LinkedList:");
scanf("%d",&size);
int i=0;
while(i!=size){
new=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the %d Element: ",i+1);
scanf("%d",&new->data);
new->next=NULL;
if(head==NULL){
    head=temp=new;
}
else{
    temp->next=new;
    temp=new;
}i++;}

print(head);
printf("\nWhat Operation do you want to perform on this linked list: ");
int option;
printf("\n1.Insertion\n2.Deletion\n3.Search\t: ");
scanf("%d",&option);
if(option==1)
insert(head);
else if(option==2)
delete();
else if(option==3)
search();
else{
    printf("Bad Input!");
}
}