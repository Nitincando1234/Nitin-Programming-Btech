#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
    char identifier[1000];
    char *token = (char*) malloc (1000 * sizeof(char));
    char *buffer = (char*) malloc (1000 * sizeof(char));
    int test = 1;
    printf("Enter the identifier to check: ");
    fgets(identifier,1000,stdin);
    if(identifier[strlen(identifier)-1]=='\n') identifier[strlen(identifier)-1]=='\0';
    if(identifier[0]=='_') test = 1;
    FILE *special_chars = fopen("specialchar.txt","r");
    FILE *keyword_file = fopen("keywordinc.txt","r");
    fgets(buffer, 1000, keyword_file);
    token = strtok(buffer, ",");
    if (strcmp(token, identifier) == 0)
        test = 1;
    while(token != NULL){
        if (strcmp(token, identifier) == 0)
        test = 1;
        token = strtok(NULL, ",");
    }
    free(token);
    free(buffer);
    token = (char*) malloc (1000 * sizeof(char));
    buffer = (char*) malloc (1000 * sizeof(char));
    fgets(buffer, 1000, special_chars);
    token = strtok(buffer, ",");
    printf("%s", token);
    for (int i = 0; identifier[i] != '\0'; i++){
        if(token[0] == identifier[i]) test = 1;
    }
    while(token != NULL){
    for (int i = 0; identifier[i] != '\0'; i++){
        if(token[0] == identifier[i]) test = 1;
    }
    token = strtok(NULL, ",");
    }
    for (int i = 0; identifier[i] != '\0'; i++){
        if(identifier[i] == '_') test = 0;
        else if(identifier[i] == ' ') test = 1;
        else test = 0;
    }

    if(test == 0) printf("\nCorrect Identifier for C !");
    else printf("\nWrong Identifier !!!");
}