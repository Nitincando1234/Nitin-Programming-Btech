#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 1000
void main(){
    printf("Enter the Email Address: ");
    char email[size],*tempemail,coredomain[50];
    fgets(email,size,stdin);
    tempemail=(char*)malloc(sizeof(char)*size);
    strcpy(tempemail,email);
    if(email[strlen(email)=='\n']){
        email[strlen(email)]='\0';
    }
    int test=1;
    for(int i=0;email[i]!='\0';i++){
        if(email[i]=='.'){test=0;break;}
    }
    int count=0;
    for(int i=0;email[i]!='\0';i++){
        if(email[i]=='@'){test=0;count++;break;}
    }
    if(count!=1){printf("\n%s : Not A valid email !",email);
    return;}
    char *domain=(char*)malloc(sizeof(char)*size);
    domain=strchr(email,'@');
    char *dot=(char*)malloc(sizeof(char)*size);
    dot=strchr(domain,'\0');
    strncpy(coredomain,domain,dot-++domain);
    coredomain[strlen(coredomain)-1]='\0';
    char *token=(char*)malloc(sizeof(char)*size);
    token= strtok(email,".");
    for(int i=0;token[i]!='\0';i++){
        if(token[i]=='.')test=1;
    }
    FILE *f1=fopen("validemail.txt","r");
    if(f1==NULL){
    printf("Unable to Open Necessary files! ");
    return;
    }
    char* line=(char*)malloc((sizeof(char))*size);
    fgets(line,size,f1);
    free(token);
    token=(char*)malloc(sizeof(char)*size);
    token=strtok(line,",");
    while (token!=NULL)
    {
        if(strcmp(token,coredomain)==0)
        {test=0;
        break;}
        token=strtok(NULL,",");
    }
    if(test==0)
    printf("\n%s : A valid email !",tempemail);
    else
    printf("\n%s : Not a valid email !",tempemail);
}