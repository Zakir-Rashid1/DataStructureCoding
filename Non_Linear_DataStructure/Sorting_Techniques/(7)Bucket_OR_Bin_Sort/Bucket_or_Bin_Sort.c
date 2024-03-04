

#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *link;
  int data;
};


int findMax(int arr[], int n){
  int max = 0;
  for(int i = 0; i < n ; i++)
    if(max < arr[i])
      max = arr[i];

  return max;
}

struct node* createNode(){
  return malloc(sizeof(struct node));
}

void insert(struct node **ptr, int num){
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


void bucketSort(int arr[], int n){
  int max = findMax(arr, n) + 1;
  int i = 0; int j = 0;
  struct node *bins[max];

  //Initilize all pointers with NULL
  for(int i = 0; i < max; i++)
    bins[i] = NULL;

  while(j < n){
    insert(&bins[arr[j]], arr[j]);
    j++;
  }

  i = j = 0;
  while(i < max){
    if(bins[i] != NULL){
      arr[j++] = Delete(&bins[i]);
    }else
      i++;
  }

}


void print(int arr[], int n){
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}


int main(){
  int arr[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Data Before Sorting: ");
  print(arr, size);

  bucketSort(arr, size);
  printf("\nData After Sorting : ");
  print(arr, size);

  return 0;
}
