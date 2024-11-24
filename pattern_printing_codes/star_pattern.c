#include <stdio.h>

int main()
{
    int n, space;

    printf("Enter an integer: \n");
    scanf("%d", &n);

    // Upper half of the diamond
    for (int i = 1; i <= n; i++)
    {
        // Spaces before stars
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        // Stars
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    // Lower half of the diamond
    for (int i = n - 1; i >= 1; i--)
    {
        // Spaces before stars
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        // Stars
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
