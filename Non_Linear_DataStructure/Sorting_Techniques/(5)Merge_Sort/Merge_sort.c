




#include <stdio.h>

int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
int col = 4;

void print(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }

  printf("\n\n\n");
}


void print_col_wise(){
  for(int j = 0; j < 4; j++){
    for(int i = 0; i < 4; i++){
      if(j % 2 == 0){
        printf("%d ", arr[j][i]);
        printf("\n");
      }
    }
  }
}

int main(){

  print();
  print_col_wise();


  return 0;
}
