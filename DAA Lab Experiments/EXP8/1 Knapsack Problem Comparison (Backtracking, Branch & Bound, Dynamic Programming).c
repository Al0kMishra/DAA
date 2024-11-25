#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming Approach
int knapsackDP(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

// Backtracking Approach
int knapsackBacktrack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsackBacktrack(W, wt, val, n - 1);
    return max(val[n - 1] + knapsackBacktrack(W - wt[n - 1], wt, val, n - 1),
               knapsackBacktrack(W, wt, val, n - 1));
}

// Branch & Bound Approach
typedef struct Node {
    int level, profit, weight;
    float bound;
} Node;
float bound(Node u, int n, int W, int val[], int wt[]) {
    if (u.weight >= W)
        return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while (j < n && totweight + wt[j] <= W) {
        totweight += wt[j];
        profit_bound += val[j];
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * val[j] / wt[j];
    return profit_bound;
}
int knapsackBB(int W, int wt[], int val[], int n) {
    Node Q[100];
    int front = -1, rear = -1;
    Node u, v;
    Q[++rear] = (Node){-1, 0, 0, 0.0};
    int maxProfit = 0;
    while (front != rear) {
        u = Q[++front];
        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + wt[v.level];
        v.profit = u.profit + val[v.level];
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, val, wt);
        if (v.bound > maxProfit)
            Q[++rear] = v;
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, val, wt);
        if (v.bound > maxProfit)
            Q[++rear] = v;
    }
    return maxProfit;
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Dynamic Programming: %d\n", knapsackDP(W, wt, val, n));
    printf("Backtracking: %d\n", knapsackBacktrack(W, wt, val, n));
    printf("Branch & Bound: %d\n", knapsackBB(W, wt, val, n));
    return 0;
}
