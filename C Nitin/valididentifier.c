#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define size 50
void main(){
    clock_t start;
    double elapsed_time=0;
    start=clock();
    char str[size];
    printf("Enter the identifier to check: ");
    fflush(stdin);
    fgets(str,size,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    FILE *f1=fopen("keywordinc.txt","r");
    FILE *f2=fopen("specialchar.txt","r");
    if(f1==NULL && f2==NULL){
    printf("Unable to open Necessary File !");
    return;
    }
    int test=0;
    if((str[0]>=65&&str[0]<=90)||(str[0]>=97&&str[0]<=122)){
    test=0;
    }
    else{
    printf("Not A Valid Identifier !");
    return;
    }
    char* token=(char *)malloc(sizeof(char)*size);
    char* line=(char *)malloc(sizeof(char)*1000);
    fgets(line,1000,f1);
    if(line!=NULL){
    token=strtok(line,",");
    while(token!=NULL){
    if(strcmp(str,token)==0){
        test=1;
        break;
    }
    token=strtok(NULL,",");
    }
    }
    free(token);
    free(line);
    token=(char *)malloc(sizeof(char)*size);
    line=(char *)malloc(sizeof(char)*1000);
    fgets(line,1000,f2);
    if(line!=NULL){
    token=strtok(line,",");
    while(token!=NULL){
    for(int i=0;str[i]!='\0';i++){
    if(str[i]==token[0]){
    test=1;
    break;
    }
    }
    token=strtok(NULL,",");
    }
    }
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            test=1;
            break;
        }
        if(str[i]=='_')
        test=0;
    }
if(test==0){
printf("\nA Valid Identifier !");
}
else{
printf("\nNot A Valid Identifier !");
}
start=clock()-start;
printf("\t(time taken: %f seconds)",((double)start)/CLOCKS_PER_SEC);
}



