//Implement fractional knapsack problem 
#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio; // Value per weight
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    return ((struct Item *)b)->ratio - ((struct Item *)a)->ratio;
}

float fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float result = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", result);

    return 0;
}
