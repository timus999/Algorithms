#include <stdio.h>

typedef struct Job {
    int id;
    int deadline;
    int profit;
} Job;

void merge(Job arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Job L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].profit >= R[j].profit) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Job arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobSequencing(Job jobs[], int n) {
    mergeSort(jobs, 0, n - 1);

    int result[n];
    int slot[n];
    for (int i = 0; i < n; i++) slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Job Sequence:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i])
            printf("Job %d\n", jobs[result[i]].id);
    }
}

int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
