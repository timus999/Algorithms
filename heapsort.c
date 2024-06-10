#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void heapify(int arr[], int n, int i){
	int largest = i;
	int left_child = ( 2 * i )+ 1;
	int right_child = ( 2 * i ) + 2;

	while( left_child <= n && arr[left_child] > arr[largest])
	{
		largest = left_child;
	}
	while ( right_child <= n && arr[right_child] > arr[largest]){
		largest = right_child;
	}

	if ( largest != i ){
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
}

void heap_sort(int arr[],int n){
	for(int i = (n/2)-1; i >=0; i--){
		heapify(arr, n, i);
	}

	for(int i = n - 1; i >= 0; i--){
    swap(&arr[i], &arr[0]);
    heapify(arr, i - 1, 0);

 	}
}

int main(){
	int arr[] = { 7, 3, 5, 1, 2};
	heap_sort(arr, 5);

	for(int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}
