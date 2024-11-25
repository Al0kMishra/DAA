//2) Insert and Delete an Element in an Array
#include <stdio.h>

void insertElement(int arr[], int *n, int pos, int value) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1]; // Shift elements to the right
    arr[pos] = value; // Insert new element
    (*n)++; // Increase array size
}

void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1]; // Shift elements to the left
    (*n)--; // Decrease array size
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Original array: ");
    printArray(arr, n);

    // Insert 10 at position 2
    insertElement(arr, &n, 2, 10);
    printf("After insertion: ");
    printArray(arr, n);

    // Delete element at position 3
    deleteElement(arr, &n, 3);
    printf("After deletion: ");
    printArray(arr, n);

    return 0;
}
