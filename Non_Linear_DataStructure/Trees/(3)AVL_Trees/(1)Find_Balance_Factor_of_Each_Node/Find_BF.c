
#include <stdio.h>
#include <stdlib.h>

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

struct node{
  struct node *left;
  int data;  int BF;
  struct node *right;
}*head = NULL;

typedef enum bool{
  false, true
}boolean;


struct node* create_node(){
  return malloc(sizeof(struct node));
}


//Inorder traversal
void inorder(struct node *ptr){
  if(ptr == NULL)
    return;
  inorder(ptr->left);
  printf("%d(%d)  ", ptr->data, ptr->BF);
  inorder(ptr->right);
}


//Height of a left sub Tree
int height_of_node(struct node *ptr){
  if(ptr == NULL)
    return 0;
  return (height_of_node(ptr->left) >= height_of_node(ptr->right) ? height_of_node(ptr->left) + 1: height_of_node(ptr->right) + 1);
}

//Generate BST Using Insert Method
struct node* insert(struct node *ptr, int data){
  if(ptr == NULL){
    struct node *temp = create_node();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->BF = height_of_node(temp->left) - height_of_node(temp->right);

    return temp;
  }
  if(data > ptr->data){
    ptr->right = insert(ptr->right, data);
    ptr->BF = height_of_node(ptr->left) - height_of_node(ptr->right);
  }
  else{
    ptr->left = insert(ptr->left, data);
    ptr->BF = height_of_node(ptr->left) - height_of_node(ptr->right);
  }

  return ptr;
}







//Testing
int main(){
  head = insert(head, 100);
  insert(head, 90); insert(head, 110); insert(head, 80);
  insert(head, 95); insert(head, 105); insert(head, 150);
  insert(head, 70); insert(head, 85); insert(head, 108);
  insert(head, 106); insert(head, 109);

  printf("\nBinary Tree Data: ");
  inorder(head);



  return 0;
}
