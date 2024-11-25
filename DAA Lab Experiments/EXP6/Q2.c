//Implement activity selection problem. 
#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

void activitySelection(struct Activity arr[], int n) {
    printf("Selected Activities:\n");
    int i = 0;
    printf("Activity 1 (Start: %d, Finish: %d)\n", arr[i].start, arr[i].finish);
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish times for activity %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    // Sort activities based on finish time (greedy approach)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].finish > arr[j].finish) {
                struct Activity temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    activitySelection(arr, n);

    return 0;
}
