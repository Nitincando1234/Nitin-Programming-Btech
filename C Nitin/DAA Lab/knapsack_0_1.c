#include <stdio.h>
#include <stdlib.h>

int n_items;

int knapsack(int capacity, int weights[], int profits[]) {
    int dp[n_items + 1][capacity + 1];
    for (int i = 0; i <= n_items; i++) {
        for (int j = 0; j <= capacity; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= n_items; i++) {
        int w = weights[i - 1], p = profits[i - 1];
        for (int sz = 1; sz <= capacity; sz++) {
            dp[i][sz] = dp[i - 1][sz];
            if (sz >= w && dp[i - 1][sz - w] + p > dp[i][sz])
                dp[i][sz] = dp[i - 1][sz - w] + p;
        }
    }
    // for returning the array that represents which items were selected
    int sz = capacity;
    printf("Index of items selected:\n");
    for (int i = n_items; i > 0; i--) {
        if (dp[i][sz] != dp[i - 1][sz]){
            int itemIndex = i - 1;
            printf("%d\t", itemIndex);
            sz -= weights[itemIndex];
        }
    }
    printf("\n");
    return dp[n_items][capacity];

}

void main() {
    int capacity, *weights, *profits;
    printf("Enter the number of items: ");
    scanf("%d", &n_items);
    weights = (int *) malloc(sizeof(int) * n_items);
    profits = (int *) malloc(sizeof(int) * n_items);
    printf("Enter the size of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the weights corresponding to %d :items\n", n_items);
    for (int i = 0; i < n_items; i++) scanf("%d", &weights[i]);
    printf("Enter the profits corresponding to %d :items\n", n_items);
    for (int i = 0; i < n_items; i++) scanf("%d", &profits[i]);
    printf("The maximum profit is: %d", knapsack(capacity, weights, profits));
}