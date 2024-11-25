//10) Rearrange Array in Maximum Minimum Form
#include <stdio.h>

void rearrangeArray(int arr[], int n) {
    int result[n];
    int left = 0, right = n - 1;
    int i = 0;

    while (left <= right) {
        if (i % 2 == 0)
            result[i++] = arr[right--];
        else
            result[i++] = arr[left++];
    }

    for (int j = 0; j < n; j++)
        arr[j] = result[j];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);
    printf("Rearranged array: ");
    printArray(arr, n);
    return 0;
}
