#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, Item items[], int n) {
    sortItems(items, n);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    int n = sizeof(items) / sizeof(items[0]);

    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(W, items, n));

    return 0;
}
