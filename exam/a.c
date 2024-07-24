#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int l, int h){

  for(int i = 0; i < h; i++){
      int min_index = i;
      for(int j = i+1; j <= h; j++){
              if ( arr[j] < arr[min_index]){
                    min_index = j;
      }

      }
      if( min_index != i ){
          int temp = arr[i];
          arr[i] = arr[min_index];
          arr[min_index] = temp;
      

      }
  }

}
int main(){

  int nums[] = { 5, 2, 4, 1, 3};


  int size = sizeof nums / sizeof nums[0];
  
  insertion_sort(nums, 0, 4);

  for(int i = 0; i < size; i++){
    printf("%d ", nums[i]);
  }
  return 0;

}
