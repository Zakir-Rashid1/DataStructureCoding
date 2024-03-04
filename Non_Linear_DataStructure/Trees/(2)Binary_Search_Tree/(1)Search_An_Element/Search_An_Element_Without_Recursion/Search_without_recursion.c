

#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

typedef enum bool{
  false, true
}boolean;



//Time compxty: O(log(n))
boolean isFound = false;
void isPresent(struct node *ptr, int ele){

  while(ptr != NULL){
    if(ele == ptr->data){
      isFound = true;
      break;
    }
    if(ele > ptr->data)
      ptr = ptr->right;
    else
      ptr = ptr->left;
  }
}




//Testing
int main(){
  head = create_node();
  head->left = head->right = NULL;
  head->data = 100;
  printf("Data of root ele is: %d\n", head->data);

  create_tree(head);
  printf("\nPreorder Traversal: ");
  preorder(head);

  isPresent(head, 51);
  if(isFound)
    printf("\nElement Found");
  else
    printf("\nElement Not Found");



  return 0;
}
