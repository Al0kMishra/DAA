#include <stdio.h>

int main()
{
    int n, space;

    printf("Enter an integer:\n");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--)
    {
        space = i - 1;

        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
