
#include "create_avl_tree.c"

/*
              100
            /     \
          90      110
        /   \     /   \
      80    95  105     150
    /   \         \
  70     85       108
                /    \
              106     109



*/


//Return immediate inorder Predecessor
struct node* predecessor(struct node *ptr){
  if(ptr->right == NULL)
    return ptr;
  predecessor(ptr->right);
}

//Return immediate inorder Successor
struct node* successor(struct node *ptr){
  if(ptr->left == NULL)
    return ptr;
  predecessor(ptr->left);
}



//Deleating a node in an AVL Tree
struct node* delete(struct node *ptr, int data){
  struct node *temp = NULL;
  if(ptr->left == NULL && ptr->right == NULL){
    free(ptr);
    ptr = NULL;

    if(root == ptr)
      root = NULL;
    return ptr;
  }
  if(data < ptr->data)
    ptr->left = delete(ptr->left, data);
  else if(data > ptr->data)
    ptr->right = delete(ptr->right, data);
  else{
    if(height(ptr->left) > height(ptr->right)){
      temp = predecessor(ptr->left);
      ptr->data = temp->data;
      ptr->left = delete(ptr->left, temp->data);

    }else{
      temp = successor(ptr->right);
      ptr->data = temp->data;
      ptr->right = delete(ptr->right, temp->data);
    }
  }

  return ptr;
}






int main(){
  root = create_avl_tree(root, 30);
  create_avl_tree(root, 20);
  create_avl_tree(root, 10);
  create_avl_tree(root, 5);
  create_avl_tree(root, 4);

  // create_avl_tree(root, 90);  create_avl_tree(root, 110);
  // create_avl_tree(root, 80);  create_avl_tree(root, 95);
  // create_avl_tree(root, 105); create_avl_tree(root, 150);
  // create_avl_tree(root, 70); create_avl_tree(root, 85);
  // create_avl_tree(root, 108);


  printf("Inorder Traversal Before Deletion: ");
  inorder(root);
  printf("\nHeight of AVL Tree is: %d", height(root));

  printf("\n=====================================\n");
  printf("Inorder Traversal After Deletion: ");
  delete(root, 20);
  update_bf(root);
  inorder(root);



  return 0;
}
