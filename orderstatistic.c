#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k)
            return arr[pi];
        else if (pi < k)
            return quickSelect(arr, pi + 1, high, k);
        else
            return quickSelect(arr, low, pi - 1, k);
    }
    return -1; // k is out of bounds
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Find the 3rd smallest element (0-based index)
    printf("The %d-th smallest element is %d\n", k + 1, quickSelect(arr, 0, n - 1, k));
    return 0;
}
