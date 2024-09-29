#include<stdio.h>
#include<stdlib.h>
struct node {
    int data,height;
    struct node *left,*right;
};
int max(int a,int b){
    return (a>b)?a:b;
}
int getheight(struct node*node){
    if(node==NULL)
    return 0;
    else
    return node->height;
}
int getBalanceFactor(struct node *node){
    if(node==NULL)
    return 0;
    else
    return getheight(node->left)-getheight(node->right);
}
struct node* createNode(int key){
    struct node*node =(struct node*)malloc(sizeof(struct node));
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
struct node* rightRotate(struct node*node){
    struct node *x=node->left;
    struct node*T2=x->right;
    x->right=node;
    node->left=T2;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    node->height=max(getheight(node->left),getheight(node->right))+1;
    return x;
}
struct node* leftRotate(struct node*x){
    struct node *y=x->right;
    struct node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    y->height=max(getheight(y->left),getheight(y->right))+1;
    return y;
}
struct node * insert(struct node *node,int key){
    if(node==NULL)
    return createNode(key);
    else if(key<node->data){
    node->left=insert(node->left,key);
    }
    else if(key>node->data) {
    node->right=insert(node->right,key);
    }
    else{
        return node;
    }
    node->height=max(getheight(node->left),getheight(node->right))+1;
    int balanceFactor=getBalanceFactor(node);
    if(balanceFactor>1&&key<node->left->data)
    return rightRotate(node);
    if(balanceFactor<-1&&key>node->right->data)
    return leftRotate(node);
    if(balanceFactor>1&&key>node->right->data){
    node->left=leftRotate(node->left);
    return rightRotate(node);
    }
    if(balanceFactor<-1&&key>node->left->data){
    node->right=rightRotate(node->right);
    return leftRotate(node);
    }
    return node;
}
void preorder(struct node * node){
    if(node!=NULL){
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
    }
}
int main(){
struct node*root;
root=insert(root,4);
root=insert(root,3);
root=insert(root,0);
root=insert(root,8);
root=insert(root,9);
root=insert(root,5);
preorder(root);
return 0 ;
}