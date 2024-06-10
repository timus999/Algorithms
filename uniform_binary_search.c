#include <stdio.h>
#include <math.h>

void uniform_binary_search(int *arr, int k, int size) {
    int rate_of_change = size / 2;
    int position = size / 2;

    while (rate_of_change >= 1) {
        if (arr[position] == k) {
            printf("Key found successfully at index %d\n", position);
            return;
        } else if (arr[position] < k) {
            position = position + (int)ceil(rate_of_change / 2.0);
        } else {
            position = position - (int)ceil(rate_of_change / 2.0);
        }
        rate_of_change /= 2;

        // Boundary check
        if (position < 0 || position >= size) {
            printf("Key not found\n");
            return;
        }
    }
    printf("Key not found\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size_of_array = sizeof(array) / sizeof(array[0]);

    int key = 2;
    uniform_binary_search(array, key, size_of_array);

    return 0;
}

