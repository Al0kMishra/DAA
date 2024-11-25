#include <stdio.h>
void subsetSum(int set[], int n, int target, int index, int subset[], int subsetSize) {
    if (target == 0) {
        printf("Subset: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (index == n || target < 0)
        return;
    subset[subsetSize] = set[index];
    subsetSum(set, n, target - set[index], index + 1, subset, subsetSize + 1);
    subsetSum(set, n, target, index + 1, subset, subsetSize);
}
int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 9;
    int subset[n];
    subsetSum(set, n, target, 0, subset, 0);
    return 0;
}

