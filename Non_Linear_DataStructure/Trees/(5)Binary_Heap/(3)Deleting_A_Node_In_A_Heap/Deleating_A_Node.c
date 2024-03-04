

#include <stdio.h>
#include <stdlib.h>


//Swap Two Integers
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


//Creating A Heap
void creating_heap(int *arr, int i){

  while(i > 1 && arr[i] > arr[i/2]){
    swap(&arr[i], &arr[i/2]);
    i = i/2;
  }
}


//Deleating A Heap Node
//Time Complexity For Deleating One Node: O(log(n))
//Time Complexity For Deleating All The Nodes: O(nlog(n))
int delete(int *arr, int n){
  int i, j, x;
  i = 1; j = 2 * i;
  x = arr[1];
  arr[1] = arr[n];


  while (j <= n - 1){
    if(j + 1 <= n - 1)
      if(arr[j + 1] > arr[j])
        j++;
    if(arr[j] > arr[i]){
      swap(&arr[i], &arr[j]);
      i = j;
      j = 2 * i;
    }
  }

  return x;

}


//Print Heap Data
void print(int *arr, int size){
  for(int i = 1; i <= size; i++)
    printf("%d ", arr[i]);
}

//Testing
int main(){
  //Ignoreing first element
  int arr[] = {0, 30, 20, 10, 25, 5, 40};
  int size = sizeof(arr) / sizeof(arr[1]) - 1;
  printf("\nBinary Heap Data Before Heap Creation: ");
  print(arr, size);

  //Assuming the first element is already in heap
  for(int i = 2; i <= size; i++)
    creating_heap(arr, i);
  printf("\nBinary Heap Data After Heap Creation: ");
  print(arr, size);

  printf("\nDeleted Element is: %d ", delete(arr, size));
  printf("\nBinary Heap Data After Heap Deleation: ");
  print(arr, size-1);
  printf("\nDeleted Element is: %d ", delete(arr, 5));
  printf("\nBinary Heap Data After Heap Deleation: ");
  print(arr, size-2);
  printf("\nDeleted Element is: %d ", delete(arr, 4));
  printf("\nBinary Heap Data After Heap Deleation: ");
  print(arr, size-3);

  return 0;
}
