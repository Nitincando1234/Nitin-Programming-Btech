#include <stdio.h>
int adj_matrix[20][20], n;

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j])
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
            }
        }
    }
}

void main() {
    printf("Enter the number of nodes: "); scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &adj_matrix[i][j]);
    }
    floyd();
    printf("Shortest Distance using Floyd Warshal' s Algo: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) printf("%d ", adj_matrix[i][j]);
        printf("\n");
    }
}
