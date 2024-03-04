

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50


//Swap Two Integers
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


//Insert new node
void insert(int *arr, int i){
  while(i > 1){
    if(arr[i] > arr[i/2]){
      swap(&arr[i], &arr[i/2]);
      i = i/2;
    }else
      break;
  }
}

//Print Heap Data
void print(int *arr, int size){
  for(int i = 1; i <= size; i++)
    printf("%d ", arr[i]);
}

//Testing
int main(){
  int arr[] = {0, 10, 20, 30, 25, 5, 40, 110};
  int size = sizeof(arr)/sizeof(arr[1]) - 1;
  printf("\nBinary Heap Data Before Heap Creation: ");
  print(arr, size);

  //Assuming the first element is already in heap
  for(int i = 2; i <= size; i++)
    insert(arr, i);
  printf("\nBinary Heap Data After Heap Creation: ");
  print(arr, size);

  /*
    Time Complexity 4 Inserting One Node: O(log(h))
    Time Complexity 4 Inserting n Nodes: O(nlog(h))
  */


  return 0;
}
