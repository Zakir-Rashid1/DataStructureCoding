

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[] = {5, 30, 35, 40, 90, 3, 9, 2, 80, 100000};
int size = sizeof(arr)/sizeof(arr[0]);

//swap
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


//print
void print(){
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("%\n");
}


//Do partioning
int partition(int i, int j){
  int pivot = i;
  while(i < j){
      do{
        i++;
      }while(arr[i] <= arr[pivot]);
      do{
        j--;
      }while(arr[j] > arr[pivot]);
      if(i < j)
        swap(&arr[i], &arr[j]);
  }

  swap(&arr[pivot], &arr[j]);
  return j;
}


void Quick_Sort(int low, int high){
  int j;
  if(low < high){
    j = partition(low, high);
    Quick_Sort(low, j);
    Quick_Sort(j + 1, high);
  }
}


int main(){

  int i = 0; int j = size - 1;
  print();
  Quick_Sort(i, j);
  print();


    return 0;
}
