

#include <stdio.h>
#include <stdlib.h>



//Insert in a sorted List
void insertion_sort(int arr[], int n){
  int j;  int key;
  for(int i = 1; i < n; i++){
    j = i - 1;
    key = arr[i];
    while(j >= 0 && key < arr[j]){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}


//Print Function
void print(int arr[], int size){
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n===================================================");

}

//Testing
int main(){
  int arr[] = {5, 10, 15, 20, 25, 30, -98, 1180};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\nData Before Sorting: ");
  print(arr, size);

  insertion_sort(arr, size);
  printf("\nData After Sorting: ");
  print(arr, size);

  /*
  Insertion means pick an element and place it in the sorted list.
    -Max Time Complexity: O(n^2)  in Desc Order
    -Min Time Complexity: O(n) in Acs Order
    -It is Adaptive as well as Stable
    -By Nature insertion sort is Adaptive


  */



  return 0;
}
