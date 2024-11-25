//Q2) Matrix Chain Multiplication (Optimal Parenthesization)
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(int p[], int n, int s[MAX][MAX]) {
    int m[MAX][MAX];

    // m[i, j] is the minimum number of scalar multiplications required to multiply matrices A[i] through A[j]
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;  // Base case: only one matrix
    }

    // Chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n-1];  // Minimum number of multiplications
}

// Function to print the parenthesization of matrices
void printParenthesis(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);  // If only one matrix, print its index
    } else {
        printf("(");
        printParenthesis(s, i, s[i][j]);  // Recur for the left half
        printParenthesis(s, s[i][j] + 1, j);  // Recur for the right half
        printf(")");
    }
}

int main() {
    int arr1[] = {40, 20, 30, 10, 30};
    int arr2[] = {10, 30, 5, 60};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int s1[MAX][MAX] = {0};  // Table to store the split points
    int s2[MAX][MAX] = {0};

    printf("1. Minimum number of multiplications for arr1: %d\n", matrixChainOrder(arr1, n1, s1));
    printf("Optimal parenthesization for arr1: ");
    printParenthesis(s1, 1, n1-1);
    printf("\n");

    printf("2. Minimum number of multiplications for arr2: %d\n", matrixChainOrder(arr2, n2, s2));
    printf("Optimal parenthesization for arr2: ");
    printParenthesis(s2, 1, n2-1);
    printf("\n");

    return 0;
}
