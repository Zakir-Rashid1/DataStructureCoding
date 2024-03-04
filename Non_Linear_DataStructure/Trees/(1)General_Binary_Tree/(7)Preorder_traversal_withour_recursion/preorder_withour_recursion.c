
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "tree.c"


int main(){
  head = create_root_node(100);
  create_tree(head);

  struct node *ptr = head;
  while(ptr != NULL || !isEmpty()){
    if(ptr != NULL){
      printf("%d ", ptr->data);
      push(ptr);
      ptr = ptr->left;
    }else{
      ptr = pop();
      ptr = ptr->right;
    }
  }
  return 0;
}
