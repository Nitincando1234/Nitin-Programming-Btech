#include <stdio.h>
#define INF 999
void dijkstra(int n, int s, int cost[10][10], int dist[10]) {
    int min, v, visited[10], count = 1;
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(cost[i][j] == 0) cost[i][j] = INF;
    //     }
    // }
    visited[s] = 0;
    while(count <= n) {
        min = INF;
        for(int i = 0; i < n; i++) {
            if(min > dist[i] && !visited[i]) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;
        for(int i = 0; i < n; i++) {
            if(dist[i] > dist[v] + cost[v][i]) dist[i] = dist[v] + cost[v][i];
        }
    }
}

void main() {
    int s, cost[10][10], n, dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the contents of the adjacency matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(n, s, cost, dist);
    printf("Shortest Distances are as follows: \n");
    for(int i = 0; i < n; i++) {
        printf("%d -> %d, cost = %d\n", s, i, dist[i]);
    }
}