#include<stdio.h>

void selection(int arr[], int n){
    int min_index, temp;

    for(int i = 0; i < n; i++){
        min_index = i;
        for(int j = i + 1; j < n; j++){
            if( arr[min_index] > arr[j]) min_index = j;

        }
        if ( min_index != i ){
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

}
int main(){
    int arr[] = { 5, 4, 6, 1, 2};

    selection(arr, 5);

    printf("Sorted array:\n");


    for (int i = 0; i < 5; i++ ){
        printf("%d ", arr[i]);

    }

    return 0;
}
