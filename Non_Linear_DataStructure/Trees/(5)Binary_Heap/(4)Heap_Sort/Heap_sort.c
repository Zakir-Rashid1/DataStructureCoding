

#include <stdio.h>
#include <stdlib.h>

/*
        50
      /   \
     70    60
    /  \
  65     80

        50     70
       /      /  \
      70     50   60
            /
           80






*/

//Swap Function
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


//Insert Function
void insert(int *arr, int i){
  while(i > 1){
    if(arr[i] > arr[i/2]){
      swap(&arr[i], &arr[i/2]);
      i = i/2;
    }else
      break;
  }
}


//Binary Heap Sort Function
void binary_heap_sort(int *arr, int size){
  int i = 1, j;
  j = 2 * i;

  swap(&arr[1], &arr[size]);

  while(j <= size - 1){
    if(j + 1 < size){
      if(arr[j + 1] > arr[j])
        j = j  + 1;
    }
    if(arr[j] > arr[i]){
      swap(&arr[j], &arr[i]);
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
  for(int i = 2; i <= size; i++)
    insert(arr, i);

  printf("\nData After Heap Creation: ");
  print(arr, size);


  for(int i = size; i >= 1; i--)
    binary_heap_sort(arr, i);
  printf("\nData After Sorting: ");
  print(arr, size);

  //Time Complexity 4 Binary Heap Sort O(nlog(n)) + O(nlog(n)) = O(nlog(n))
  //                                   4 Insertion  4 Deleation


  return 0;
}
