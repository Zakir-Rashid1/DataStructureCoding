


#include <stdio.h>
#include <stdlib.h>



//Swap Function
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}



//Time Complexity Is O(n), but i didn't understand the proof :(
void heapify(int arr[], int i, int size){
  int j = 2 * i;

  while(j < size){
    if(j + 1 <= size){
      if(arr[j + 1] > arr[j])
        j = j + 1;
    }
    if(arr[j] > arr[i]){
      swap(&arr[i], &arr[j]);
      i = j;
      j = 2 * i;
    }else
      break;
  }
}




//Print Function
void print(int *arr, int size){
  for(int i = 1; i <= size; i++)
    printf("%d ", arr[i]);
}


int main(){
  int arr[] = {0, 3, 4, 9, 20, 1, 6, 10, 180, -11, 11, 80};
  int size = sizeof(arr)/sizeof(arr[1]) - 1;

  printf("\nData Before Heap Creation: ");
  print(arr, size);
  for(int i = size / 2; i >= 1; i--)
    heapify(arr, i, size);

  printf("\nData After Heapify: ");
  print(arr, size);


  return 0;
}
