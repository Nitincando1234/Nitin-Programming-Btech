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
int insert(struct tree *root,int key){
struct tree * prev;
while(root!=NULL){
    prev=root;
    if(key==root->data){
        printf("Can't Insert");
        return 0;
    }
    else if(key>prev->data){
        root=root->right;
    }
    
    else {
        root=prev->left;
    }
}
struct tree * new=(struct tree *)malloc(sizeof(struct tree));
new->data=key;
new->left=new->right=NULL;
if(key>prev->data){
    prev->left=new;
}
else{
    prev->right=new;
}
return 1;
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
printf("Which value to insert:");
int value;
scanf("%d",&value);
if(insert(p1,value)){
    printf("Inserted %d",value);
}
}