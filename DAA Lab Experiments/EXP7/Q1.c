//Q1) 0/1 Knapsack Problem
#include <stdio.h>

#define MAX 100

// Function to solve the 0/1 knapsack problem
int knapsack(int profit[], int weight[], int n, int W) {
    int dp[MAX][MAX];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or zero capacity
            } else if (weight[i-1] <= w) {
                dp[i][w] = (profit[i-1] + dp[i-1][w - weight[i-1]] > dp[i-1][w]) ? 
                            profit[i-1] + dp[i-1][w - weight[i-1]] : dp[i-1][w];
            } else {
                dp[i][w] = dp[i-1][w];  // If the weight is greater than the capacity, we exclude the item
            }
        }
    }

    return dp[n][W];  // The maximum profit will be in the bottom-right corner
}

int main() {
    int profit1[] = {2, 3, 1, 4}, weight1[] = {3, 4, 6, 5};
    int profit2[] = {60, 100, 120}, weight2[] = {10, 20, 30};
    int profit3[] = {2, 5, 8, 1}, weight3[] = {10, 15, 6, 9};
    
    int W1 = 8, N1 = 4;
    int W2 = 50, N2 = 3;
    int W3 = 50, N3 = 4;

    printf("1. Maximum profit (0/1 Knapsack) for input 1: %d\n", knapsack(profit1, weight1, N1, W1));
    printf("2. Maximum profit (0/1 Knapsack) for input 2: %d\n", knapsack(profit2, weight2, N2, W2));
    printf("3. Maximum profit (0/1 Knapsack) for input 3: %d\n", knapsack(profit3, weight3, N3, W3));

    return 0;
}
