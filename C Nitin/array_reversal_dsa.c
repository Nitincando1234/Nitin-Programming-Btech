#include<stdio.h>
#include<string.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(char c);
char pop();
void main(){
char str[20];
printf("Enter the String:");gets(str);
for(int i=0;i<strlen(str);i++){
	push(str[i]);}
for(int i=0;i<strlen(str);i++){
	str[i]=pop();}
	puts(str);	
	}
void push(char c){
	if(top==MAX-1)
	printf("Stack is Full.");
	else{
		top++;
		stack[top]=c;}
	}
char pop(){
	if(top==-1)
	printf("Stack is Empty.");
	else{
	top--;
	return stack[top]; }
	}