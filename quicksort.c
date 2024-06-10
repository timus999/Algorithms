#include<stdio.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int l, int h){
    int pivot = arr[l];
    
    int i = l;

    int last = h;
    for(int j = i + 1; j <= h; j++){
        if( arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i], &arr[l]);

    return i;

}


int main(){
    int arr[] = { 7, 2, 13, 1, 8};
    partition(arr, 0, 4);
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    return 0;

}



