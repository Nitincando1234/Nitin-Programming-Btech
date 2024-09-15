#include <stdio.h>
#include <stdlib.h>
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
void inOrder(struct tree* root){
if(root!=NULL){
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}
}
struct tree *inpredecessor(struct tree * root){
    root =root ->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct tree* del(struct tree* root,int value){
    struct tree *inpre;
    if(root == NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);return NULL;
    }
    if(value<root->data){
        root->left=del(root->left,value);
    }
    else if(value>root->data){
        root->right=del(root->right,value);
    }
    else{
        inpre=inpredecessor(root);
        root->data=inpre->data;
        root->left=del(root->left,inpre->data);
    }
    return root;
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
inOrder(p1);
printf("\nWhich one to delete.");
int value;scanf("%d",&value);
del(p1,value);
inOrder(p1);
}