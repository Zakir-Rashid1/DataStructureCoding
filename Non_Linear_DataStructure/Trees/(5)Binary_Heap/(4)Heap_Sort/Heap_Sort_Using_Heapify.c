


#include <stdio.h>
#include <stdlib.h>



//Swap Function
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}



//Time Complexity 4 Creating A Heap Using Heapify O(n)
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


void fun(int arr[], int size){
  for(int i = size / 2; i >= 1; i--)
    heapify(arr, i, size);
}

//Heap Sort Function
void heap_sort(int *arr, int size){
  int i = 1;
  int j = 2 * i;
  swap(&arr[1], &arr[size]);
  while(j <= size - 1){
    if(2 * i + 1 <= size - 1){
      if(arr[j + 1] > arr[j])
        j = j + 1;
    }
    if(arr[i] < arr[j]){
      swap(&arr[i], &arr[j]);
      i = j;
      j = 2 * j;
    }else
      break;
  }
}


//Print Function
void print(int *arr, int size){
  for(int i = 1; i <= size; i++)
    printf("%d ", arr[i]);
  printf("\n==============================================================\n");
}


int main(){
  int arr[] = {0, 3, 4, 9, 20, 1, 6, 10, 180, -11, 11, 80};
  int size = sizeof(arr)/sizeof(arr[1]) - 1;

  printf("\nData Before Heap Creation: ");
  print(arr, size);

  fun(arr, size);
  printf("\nData After Heap Creation: ");
  print(arr, size);

  printf("\nHeap Data After Sorting: ");
  for(int i = size; i >= 1; i--)
    heap_sort(arr, i);
  print(arr, size);



  /*
  Time Complexity 4 Heap Sorting Using Heapify = O(n)  +  O(nlog(n)) = O(nlog(n))
                                              4 Heapify   4 Deleation

  */


  return 0;
}
