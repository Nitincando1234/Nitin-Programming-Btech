#include<stdio.h>
#define SIZE 5
int TOP=-1;
int a[SIZE];
void push(){
if(TOP==SIZE-1){
printf("Stack Overflow !\n");
return;}
else{
TOP++;
printf("Enter the Number: ");
scanf("%d",&a[TOP]);}
}
void pop(){
    if(TOP==-1)
    {printf("Stack Underflow !\n");}
    printf("Popped %d\n",a[TOP]);
    TOP--;
}
void print(){
    int newsize=0;
    while(newsize<=TOP){
        printf("%d\t",a[newsize]);
        newsize++;
    }
}
int main(){
printf("Size of the stack is : %d\n",SIZE);
while(1){
printf("Which Operation to perform: \n1.Push\n2.Pop\n3.Print\n:");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
push();break;
case 2:
pop();break;
case 3:
print();
break;
default:
printf("Invalid Choice !\n");}}
return 0 ;
}