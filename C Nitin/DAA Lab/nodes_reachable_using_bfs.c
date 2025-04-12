#include <stdio.h>
#include <stdlib.h>

int adj_matrix[20][20], queue[20], n, st_vertex, *visited, f = 0, r = -1;

void bfs(int v) {
    for(int i = 1; i <= n; i++){
        if(adj_matrix[v][i] && !visited[i]) queue[++r] = i;
    }
    if(f <= r) {
        visited[queue[f]] = 1;
        bfs(queue[f++]);
    }
}

void main() {
    printf("Enter the number of vertices in the graph: "); scanf("%d", &n);
    visited = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i <= n; i++) visited[i] = 0;
    printf("Enter the adjacency matrix: \n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) 
            scanf("%d", &adj_matrix[i][j]);
    }
    printf("Enter the starting vertex in the graph: "); scanf("%d", &st_vertex);
    printf("Nodes that can be visited from %d: \n", st_vertex);
    bfs(st_vertex);
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 1) printf("%d ", i);
    }
}