

#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


void bubble_sort(int arr[], int n){
  int flag = 0;
  for(int i = 0; i < n-1; i++){
    flag = 0;
    for(int j = 0; j < n-1-i; j++){
      if(arr[j] > arr[j + 1]){
        swap(&arr[j], &arr[j + 1]);
        flag = 1;
      }
    }
    if(flag == 0)
        break;
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
  int arr[] = {9, 8, 3, 10, -12, 89};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\nData Before Sorting: ");
  print(arr, size);

  bubble_sort(arr, size);
  printf("\nData After Sorting: ");
  print(arr, size);

  /*
  Bubble Sort Is Adaptive As Well As Stable
  Max Time Cxplty: O(n^2)
  Min Time Cxplty: O(n)

  */



  return 0;
}
