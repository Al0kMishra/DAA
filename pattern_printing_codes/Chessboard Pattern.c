#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0)
                printf("X");
            else
                printf("O");
        }
        printf("\n");
    }
    return 0;
}
