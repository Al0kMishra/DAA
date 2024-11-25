//1) Find Sum of All Array Elements Using Recursion
#include <stdio.h>

int sumArray(int arr[], int size) {
    if (size <= 0) {
        return 0;
    }
        return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = sumArray(arr, n);
    printf("The sum of all array elements is: %d\n", sum);

    return 0;
}
