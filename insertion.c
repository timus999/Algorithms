
#include<stdio.h>

void insertion(int *arr, int n){
	
	for(int i = 1; i < n; i++){
		int j = i - 1;
		int key = arr[i];

		while(key < arr[j] && j >= 0){
		       arr[j + 1] = arr[j];
		       j--;
		}

		arr[j+1] = key;
	}
}

int main(){
	int arr[] = { 5, 3, 2, 6, 1};

	insertion(arr, 5);

	for ( int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	return 0;

}

	      		       

