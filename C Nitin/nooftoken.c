#include<stdio.h>
#include<string.h>
#include<time.h>
#define size 1000
void main(){
    double start=time(NULL);
    printf("Enter the statement (Please use spaces to seperate each field of statement): ");
    char statement[size];
    fgets(statement,size,stdin);
    char *token=strtok(statement," ");
    int count=0;
    while(token !=NULL){
        count ++;
        token=strtok(NULL," ");
    }
    printf("No. of tokens are: %d",count);
    double end=time(NULL);
    printf("\nExecution time was: %.4f",difftime(end,start));
}