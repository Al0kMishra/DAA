//13) Interchange Second Biggest and Second Smallest
#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeSecond(int arr[], int n) {
    int firstMax = INT_MIN, secondMax = INT_MIN;
    int firstMin = INT_MAX, secondMin = INT_MAX;
    int secondMaxIndex = -1, secondMinIndex = -1;

    // Find first and second largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] != firstMax) {
            secondMax = arr[i];
            secondMaxIndex = i;
        }

        // Find first and second smallest elements
        if (arr[i] < firstMin) {
            secondMin = firstMin;
            firstMin = arr[i];
        } else if (arr[i] < secondMin && arr[i] != firstMin) {
            secondMin = arr[i];
            secondMinIndex = i;
        }
    }

    if (secondMaxIndex != -1 && secondMinIndex != -1) {
        swap(&arr[secondMaxIndex], &arr[secondMinIndex]);
        printf("Swapped second biggest (%d) and second smallest (%d).\n", secondMax, secondMin);
    } else {
        printf("Array does not have distinct second biggest and second smallest elements.\n");
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 5, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    interchangeSecond(arr, n);

    printf("Modified array: ");
    printArray(arr, n);

    return 0;
}
