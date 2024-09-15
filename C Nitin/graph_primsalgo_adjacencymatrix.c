#include<stdlib.h>
#include<stdio.h>
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
void primsGraph(int adjMatrix[no_vertices][no_vertices]){
    int arbitrary,i,j,u,v,min=999,minCost=0,no_edge=0,*visited;
    visited = (int *)malloc(no_vertices * sizeof(int));
    for(int i=0;i<no_vertices;i++)visited[i]=0;
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
        if(adjMatrix[i][j]==0)
        adjMatrix[i][j]=999;
        }
    }
    printf("Enter the arbitrary value from where to start: ");
    scanf("%d",&arbitrary);
    visited[arbitrary]=1;
    while(no_edge<no_vertices-1){
        min=999;u=-1;v=-1;
        for(int i=0;i<no_vertices;i++){
            if(visited[i]){
                for(int j=0;j<no_vertices;j++){
                    if(!visited[j] && min>adjMatrix[i][j]){
                        min=adjMatrix[i][j];
                        u=i;v=j;
                    }
                }   
            }
        }
        if(u!=-1 && v!=-1){
            printf("\n%d edge (%d to %d) with cost = %d",no_edge++,u,v,min);
            minCost=min+minCost;
            visited[v]=1;
            }adjMatrix[u][v]=adjMatrix[v][u]=999;
    }printf("\nMinimum Cost to build the mst: %d",minCost);
}
void main(){
    printf("Enter the number of vertices of the graph : ");
    scanf("%d",&no_vertices);
    int adjMatrix[no_vertices][no_vertices],True=1,source,destination;
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++)
        adjMatrix[i][j]=0;
    }
    int cost;
    while(True){
        printf("Enter the edge b/w %d to %d (-1 for termination): ",0,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(source==-1 || destination== -1)break;

        printf("Enter the cost: ");
        scanf("%d",&cost);
        if(no_vertices<source || no_vertices<destination){
            printf("Wrong edge input !");
            break;
        }
        adjMatrix[source][destination]=cost;
        adjMatrix[destination][source]=cost;
    }
    printGraph(adjMatrix);
    printf("Prim\'s Algorithm implementation:\n");
    primsGraph(adjMatrix);
}