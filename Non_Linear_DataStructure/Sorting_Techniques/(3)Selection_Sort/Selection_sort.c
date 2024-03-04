


#include <stdio.h>
#include <stdlib.h>



//Swap Function
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


void selection_sort(int arr[], int n){
  int j, k;
  for(int i = 0; i < n - 1; i++){
    j = k = i;
    j = i + 1;
    while(j < n){
      if(arr[j] < arr[k])
        k = j;
       j++;
    }
    swap(&arr[i], &arr[k]);
  }
}


//Print Function
void print(int *arr, int size){
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n===================================================");

}


int main(){
  int arr[] = {3, 4, 9, 20, 1, 6, 10, 180, -99, 100, -105};
  int size = sizeof(arr)/sizeof(arr[1]);
  printf("Data Before Sorting: ");
  print(arr, size);

  selection_sort(arr, size);
  printf("\n\nData After Sorting: ");
  print(arr, size);

  /*
  Selection: Here selection means select the index, and the minimum value for that particular index.
    -Max Time Complexity : O(n^2)
    -Min Time Complexity : O(n^2)
    -It is neither Adaptive nor Stable

  */



  return 0;
}
