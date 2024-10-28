#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
};
struct tree* createNode(){
struct tree *node=(struct tree*)malloc(sizeof(struct tree));
scanf("%d",&node->data);
node->left=node->right=NULL;
return node;
}
void preOrder(struct tree* root){
if(root!=NULL){
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
}
void postOrder(struct tree* root){
if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}
}
void inOrder(struct tree* root){
if(root!=NULL){
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}
}
void main(){
struct tree *p1,*p2,*p3,*p4,*p5,*p6;
p1=createNode();
p2=createNode();
p3=createNode();
p4=createNode();
p5=createNode();
p6=createNode();
p1->left=p2;
p1->right=p3;
p2->left=p4;
p2->right=p5;
p3->left=p6;
preOrder(p1);
printf("\n");
postOrder(p1);
printf("\n");
inOrder(p1);
printf("\n");
}