#include<stdlib.h>
#include<stdio.h>
#define INF 9999
int no_vertices;
void printGraph(int adjMatrix[no_vertices][no_vertices]){
    printf("The representation of the graph is as the following: \n\n");
    printf("  ");
    for(int i=0;i<no_vertices;i++)
    printf("%d ",i);
    printf("\n");
    for(int i=0;i<no_vertices;i++){
        printf("%d ",i);
        for(int j=0;j<no_vertices;j++){
            printf("%d ",adjMatrix[i][j]);
        }printf("\n");
    }
}
void dijkstraGraph(int adjMatrix[no_vertices][no_vertices],int source, int *dist){
    int visited[no_vertices],count=1,v,min=0;
    for(int i=0;i<no_vertices;i++){
        visited[i]=0;
        dist[i]=INF;
    }
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            if(adjMatrix[i][j]==0)adjMatrix[i][j]=INF;
        }
    }
    visited[source]=1;
    dist[source]=0;
    while(count<no_vertices){
        min=INF;
        for(int i=0;i<no_vertices;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            v=i;
        }
        }
        visited[v]=1;
        count++;
        //relaxation condition
        for(int i=0;i<no_vertices;i++){
            if(dist[i]>dist[v]+adjMatrix[v][i])
            dist[i]=dist[v]+adjMatrix[v][i];
        }
    }

}
void main(){
    printf("Enter the number of vertices of the graph : ");
    scanf("%d",&no_vertices);
    int *dist,adjMatrix[no_vertices][no_vertices],True=1,source,destination,cost;
    dist=(int *)malloc(sizeof(int)*no_vertices);
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++)
        adjMatrix[i][j]=0;
    }

    while(True){
        printf("Enter the edge b/w %d to %d (-1 for termination): ",0,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(source==-1 && destination==-1)break;
        printf("Enter the cost of the graph: ");
        scanf("%d",&cost);
        if(no_vertices<source || no_vertices<destination){
            printf("Wrong edge input !");
            break;
        }
        if(source==-1 || destination== -1)break;
        adjMatrix[source][destination]=cost;//can add cost here taken from input of the edge
        adjMatrix[destination][source]=cost;//can add cost here taken from input of the edge
    }
    printGraph(adjMatrix);
    printf("Enter the source from where to start: ");
    scanf("%d",&source);
    printf("\nCosts b/w source and destination are as follows: \n");
    dijkstraGraph(adjMatrix,source,dist);
    for(int i=0;i<no_vertices;i++){
        if(i!=source)
        printf("\n%d -> %d = %d",source,i,dist[i]);
    }   
}