//Q 3) Write a program to Determine the LCS of the two strings S1=ACCGGTCGAGTGCGCGGAAGCCGGCCGAA, S2=GTCGTTCGGAATGCCGTTGCTCTGTAAA
#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find the length of the LCS
int lcs(char *X, char *Y, int m, int n) {
    int dp[MAX][MAX];

    // Build the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: if one of the strings is empty
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;  // If characters match
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];  // Take max
            }
        }
    }

    // Print the LCS length
    return dp[m][n];
}

int main() {
    char S1[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char S2[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    int m = strlen(S1);
    int n = strlen(S2);

    printf("Length of LCS: %d\n", lcs(S1, S2, m, n));

    return 0;
}
