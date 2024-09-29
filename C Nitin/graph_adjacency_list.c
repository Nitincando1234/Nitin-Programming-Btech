#include<stdio.h>
#include<stdlib.h>
int n_vertices;
struct node {
    int data;
    struct node* next;
};
int *visited;//for bfs or dfs
void createGraph(struct node* vertices[]){
    struct node* newNode,*q, *start;
    int n_adjVertice;
    for(int i=0;i<n_vertices;i++){
        printf("\nHow many vertices are adjacent to %d: ",i);
        scanf("%d",&n_adjVertice);
        if(n_adjVertice==0){    //in case of isolated vertex
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->next=NULL;
            newNode->data=-1;
            vertices[i]=newNode;
        }
        for(int j=0;j<n_adjVertice;j++){
            newNode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the %d vertice adjacent to %d: ",j+1,i);
            scanf("%d",&newNode->data);
            newNode->next=NULL;
            if(vertices[i]==NULL){
                start=newNode;
                vertices[i]=start;
            }
            else
            q->next=newNode;
            q=newNode;
        }
    }

}
void printGraph(struct node* vertice[]){
    struct node *q;
    for(int i=0;i<n_vertices;i++){
        q=vertice[i];
        int j=0;
        printf("\n");
        while(q!=NULL){
            if(q->data==-1) printf("\n%d vertice adjacent to ||%d||: %s",j+1,i,"isolated");
            else printf("\n%d vertice adjacent to ||%d||: %d",j+1,i,q->data);
            q=q->next;
            j++;
        }
    }
}
void bfsPrint(struct node *vertice[],int start){
    struct node *ptr;
    int visited[n_vertices],queue[n_vertices],front=-1,rear=-1;
    queue[++rear]=start;
    ++front;
    visited[start]=1;
    while(front<=rear){
        ptr=vertice[queue[front]];
        printf("%d\t",queue[front++]);
        while(ptr!=NULL){
            if(visited[ptr->data]!=1){
            queue[++rear]=ptr->data;
            visited[queue[rear]]=1;
            }
            ptr=ptr->next;
        }
    }
}
void dfsPrint(struct node *vertice[],int start){
    printf("%d\t",start);
    visited[start]=1;
    struct node* ptr=vertice[start];
    while(ptr!=NULL){
        if(visited[ptr->data]!=1){
            dfsPrint(vertice,ptr->data);
        }
        ptr=ptr->next;
    }
}
void main(){
    int start;
    fflush(stdout);
    printf("Enter the number of the vertices: ");
    scanf("%d",&n_vertices);
    struct node *vertice[n_vertices];
    for(int i=0;i<n_vertices;i++)
    vertice[i]=NULL;
    printf("Graph creation Started:\n");
    createGraph(vertice);
    printf("Graph printing Started:\n");
    printGraph(vertice);
    printf("\n\nfor BFS & DFS \nEnter the start point to start the bfs traversal: ");
    scanf("%d",&start);
    visited=(int *)malloc(n_vertices*sizeof(int));
    printf("BFS traversal of the given graph: \n");
    bfsPrint(vertice,start);
    free(visited);
    visited=(int *)malloc(n_vertices*sizeof(int));
    printf("DFS traversal of the given graph: \n");
    dfsPrint(vertice,start);
    free(visited);
}