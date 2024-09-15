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
void main(){
    printf("Enter the number of vertices of the graph : ");
    scanf("%d",&no_vertices);
    int adjMatrix[no_vertices][no_vertices],True=1,source,destination;
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++)
        adjMatrix[i][j]=0;
    }

    while(True){
        printf("Enter the edge b/w %d to %d (-1 for termination): ",0,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(no_vertices<source || no_vertices<destination){
            printf("Wrong edge input !");
            break;
        }
        if(source==-1 || destination== -1)break;
        adjMatrix[source][destination]=1;//can add cost here taken from input of the edge
        adjMatrix[destination][source]=1;//can add cost here taken from input of the edge
    }
    printGraph(adjMatrix);
}