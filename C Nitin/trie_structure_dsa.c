#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 26
typedef struct Trie Trie;
struct Trie{
    int is_Terminal;
    char data;
    Trie* children[N];
};
Trie * createNode(char data){
    Trie* node= (Trie*) malloc(sizeof(struct Trie));
    for(int i=0;i<N;i++)node->children[i]=NULL;
    node->data=data;
    node->is_Terminal=0;
    return node;
}
Trie *insertTrie(Trie* root,char * word){
    Trie* temp=root;
    for(int i=0;word[i]!='\0';i++){
        int position=(int)word[i]-'a';
        if(temp->children[position]==NULL)
        temp->children[position]=createNode(word[i]);
        temp=temp->children[position];
    }
    temp->is_Terminal=1;
    return root;
}
void printTrie(Trie* root){
    Trie* temp=root;
    if(!temp)return;
    printf("%c->",temp->data);
    for(int i=0;i<N;i++){
    printTrie(temp->children[i]);
    }
}
int searchTrie(Trie* root, char* word){
    Trie* temp= root;
    for(int i=0;word[i]!='\0';i++){
        int index=(int)word[i]-'a';
        if(temp->children[index]==NULL)return 0;
        temp=temp->children[index];
    }
    if(temp!=NULL && temp->is_Terminal==1)
    return 1;
    return 0;
}
int checkDivergence(Trie *root, char* word){
    Trie* temp=root;
    if(strlen(word)==0)return 0;
    int last_index=0;
    for(int i=0;word[i]!='\0';i++){
    int position=(int)word[i]-'a';
    if(temp->children[position]){
        for(int j=0;j<N;j++){
            if(j!=position && temp->children[j]){
            last_index++;
            break;
            }
        }
        temp=temp->children[position];
    }
}
return last_index;
}
char * findLongest_Prefix(Trie* root, char *word){
    Trie *temp=root;
    if(!word && word[0]=='\0')
    return NULL;
    char *Longest_Prefix=(char *)malloc(sizeof(char)*strlen(word));
    strcpy(Longest_Prefix,word);
    int branch_index=checkDivergence(temp,word)-1;
    if(branch_index>=0){
        Longest_Prefix[branch_index]='\0';
        Longest_Prefix=(char *)realloc(Longest_Prefix,(branch_index+1)*sizeof(char));
    }
    return Longest_Prefix;
}
void freeTrie(Trie *root){
    Trie *temp =root;
    for(int i=0;i<N;i++){
        if(temp->children[i]!=NULL)
        freeTrie(temp->children[i]);
    }free(temp);
}
int isTerminal(Trie* root,char * word){
    Trie* temp=root;
    for(int i=0;word[i]!='\0';i++){
        int position=(int)word[i]-'a';
        if(temp->children[position])
        temp=temp->children[position];
    }
    return temp->is_Terminal;
}
Trie* delete_Trie(Trie* root, char* word){
    int i=0;
    if(!word || word[0]=='\0')return NULL;
    if(!root)return root;
    if(!isTerminal(root,word))return root;
    char * longest_prefix=findLongest_Prefix(root,word);
    Trie * temp=root;
    for(;longest_prefix[i]!='\0';i++){
        int position=(int )longest_prefix[i]-'a';
        if(temp->children[position])
        temp=temp->children[position];
        else{
        free(longest_prefix);
        return root;
        }
    }
    for(;i<strlen(word);i++){
        int position=(int)word[i]-'a';
        if(temp->children[position]){
        Trie * remover=temp->children[position];
        freeTrie(remover);
        temp->children[position]=NULL;
        }
    }
    return root;
}
void main(){
    Trie * root =createNode('\0');
    insertTrie(root,"arm");
    if(searchTrie(root,"arm"))
    printf("Found !\n");
    else
    printf("Not Found !\n");
    insertTrie(root,"nitin");
    if(searchTrie(root,"nitin"))
    printf("Found !\n");
    else
    printf("Not Found !\n");
    insertTrie(root,"sharma");
    if(searchTrie(root,"sharma"))
    printf("Found !\n");
    else
    printf("Not Found !\n");
    insertTrie(root,"you");
    if(searchTrie(root,"you"))
    printf("Found !\n");
    else
    printf("Not Found !\n");
    printf("\n");
    printTrie(root);
    delete_Trie(root,"arm");
    printf("\n\nDeleting string: \"arm\"\n");
    printTrie(root);
}