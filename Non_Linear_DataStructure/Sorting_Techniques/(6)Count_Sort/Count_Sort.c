

#include <stdio.h>
#include <stdlib.h>


int findMax(int arr[], int n){
  int max = 0;
  for(int i = 0; i < n; i++)
    if(max < arr[i])
      max = arr[i];

  return max;
}



/*
  Time complexity for Count Sort = O(n)
  Space Complexity for Count Sort = O(max(a[i])) = O(n)
*/
void countSort(int arr[], int n){
  int max = findMax(arr, n) + 1;
  int *bins = (int*)malloc(sizeof(int) * max);
  int i = 0; int j = 0;

  for(int i = 0; i < max; i++)
    bins[i] = 0;

  //Fill bin array
  while(j < n){
    bins[arr[j]]++;
    j++;
  }

  //Copy the index of bins to orginal array
  i = j = 0;
  while(i < max){
    if(bins[i] > 0){
      arr[j++] = i;
      bins[i]--;
    }else
      i++;
  }
}


void print(int *arr, int n){
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}



int main(){
  int arr[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Array Elements Before Sorting: ");
  print(arr, n);
  countSort(arr, 10);
  printf("\n\nArray Elements After Sorting:  ");
  print(arr, n);


  return 0;
}
