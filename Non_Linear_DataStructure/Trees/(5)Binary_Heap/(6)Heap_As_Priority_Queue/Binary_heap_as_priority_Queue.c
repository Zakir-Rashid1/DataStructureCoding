


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


int delete_higher_priority(int arr[], int *size){
  if(*size == 0){
    printf("\nQueue is empty\n");
    exit(1);
  }
  int x = arr[1];
  arr[1] = arr[*size];
  *size = *size - 1;
  fun(arr, *size);

  return x;
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


  fun(arr, size);
  printf("\nData After Heap Creation: ");
  print(arr, size);

  printf("\n==========================================================");

  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));
  printf("\nDelted Element is: %d ", delete_higher_priority(arr, &size));



  /*
  Inserting An Element in a Queue = O(log(n))
  Deleating An Elemnet in a Queue = O(log(n))
  */

  return 0;
}
