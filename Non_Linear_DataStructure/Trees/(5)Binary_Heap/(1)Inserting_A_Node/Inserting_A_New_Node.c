

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
//Time Complexity: O(log(h)) h is height of binary heap(Complete Binary Tree)
void insert_new_node(int *arr, int key, int i){
  arr[i] = key;
  while(i > 1 && arr[i] > arr[i/2]){
    swap(&arr[i], &arr[i/2]);
    i = i/2;
  }
}

//Print Heap Data
void print(int *arr, int size){
  for(int i = 1; i <= size; i++)
    printf("%d ", arr[i]);
}

//Testing
int main(){
  int arr[MAXSIZE];
  arr[1] = 30; arr[2] = 20; arr[3] = 15; arr[4] = 5;
  arr[5] = 10; arr[6] = 12; arr[7] = 10;
  printf("Binary Heap Data Before Insertion: ");
  print(arr, 7);

  printf("\nBinary Heap Data After Insertion: ");
  insert_new_node(arr, 40, 8);
  print(arr, 8);

  printf("\nBinary Heap Data After Insertion: ");
  insert_new_node(arr, 25, 9);
  print(arr, 9);


  return 0;
}
