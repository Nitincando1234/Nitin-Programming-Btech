#include<stdio.h>
#include<string.h>
#define MAX 50
int top=-1;
char stack[MAX];
void push(char);
char pop();
void main(){
    char str[MAX];
    printf("Enter the string: ");
    gets(str);
    for(int i=0;i<strlen(str);i++){
        push(str[i]);
    }
    for(int i=0;i<strlen(str);i++){
        str[i]=pop();
    }
    printf("\nReversed String using stack is: %s",str);
}
void push(char c){
    if(top==MAX-1)
    printf("\nOverflow");
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    if(top==-1)
    printf("\nUnderflow");
    else{
        return stack[top--];
    }
}