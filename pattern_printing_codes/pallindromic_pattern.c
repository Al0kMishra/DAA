#include <stdio.h>

int main()
{
    int n, space;

    printf("Enter an integer: \n");
    scanf("%d", &n);

    for (int i = n, k = 1; i >= 1 && k <= n; i--, k++)
    {
        space = i - 1;

        // Print spaces
        for (int j = 1; j <= space; j++)
        {
            printf("  ");
        }

        // Print decreasing sequence
        for (int j = k; j >= 1; j--)
        {
            printf("%d ", j);
        }

        // Print increasing sequence
        for (int j = 2; j <= k; j++)
        {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}
