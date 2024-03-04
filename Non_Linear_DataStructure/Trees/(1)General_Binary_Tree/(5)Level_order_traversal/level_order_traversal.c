
//Level order Traversal
#include <stdio.h>
#include <stdlib.h>
#include "Tree.c"


void level_order_traversal(struct node *ptr){
  enQueue(ptr);
  while(!isEmpty()){
    ptr = deQueue();
    if(ptr != NULL){
      printf("%d ", ptr->data);
      enQueue(ptr->left);
      enQueue(ptr->right);
    }
  }
}






//Testing
int main(){
  create_root_node(100);
  create();

  printf("Level Order Traversal\n");
  level_order_traversal(root);

  return 0;
}
