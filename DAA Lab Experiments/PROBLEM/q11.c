//11) Print All Distinct Elements
#include <stdio.h>

void printDistinct(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j])
                break;
        }
        if (i == j)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Distinct elements: ");
    printDistinct(arr, n);
    return 0;
}
