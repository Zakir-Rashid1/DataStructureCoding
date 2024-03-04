
#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *link;
  int data;
};


int findMax(int arr[], int size){
  int max = 0;
  for(int i = 0; i < size; i++)
    if(arr[i] > max)
      max = arr[i];

  return max;
}


int numberOfDigits(int max){
  if(max == 0)
    return 0;
  else
    return 1 + numberOfDigits(max/10);
}


struct node* createNode(){
  return malloc(sizeof(struct node));
}


void Insert(struct node **ptr, int num){
  struct node *temp = *ptr;
  if(temp == NULL){
    temp = createNode();
    temp->data = num;
    temp->link = NULL;
    *ptr = temp;
  }else{
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = createNode();
    temp = temp->link;
    temp->data = num;
    temp->link = NULL;
  }
}


int Delete(struct node **ptr){
  struct node *temp = *ptr;  int x;
  x = temp->data;
  *ptr = temp->link;
  free(temp);
  temp = NULL;

  return x;
}


//Radix Sort Function
void radixSort(int arr[], int size){
  struct node *Bins[10];  int x = 1;
  int i, j, nods;
  nods = numberOfDigits(findMax(arr, size));

  //Initilize All Bins with NULL
  for(int i = 0; i < 10; i++)
    Bins[i] = NULL;

  while(nods != 0){
    for(int i = 0; i < size; i++)
      Insert(&Bins[(arr[i]/x) % 10], arr[i]);

    i = j = 0;
    while(j < 10){
      if(Bins[j] != NULL)
        arr[i++] = Delete(&Bins[j]);
      else
        j++;
    }

    x *= 10;
    nods--;
  }

}


void print(int arr[], int n){
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}



int main(){
  int arr[] = {237, 146, 259, 3428, 152, 163, 235, 48, 30006, 62};
  int n = sizeof(arr)/sizeof(arr[0]);
  radixSort(arr, n);
  print(arr, n);


  return 0;
}
