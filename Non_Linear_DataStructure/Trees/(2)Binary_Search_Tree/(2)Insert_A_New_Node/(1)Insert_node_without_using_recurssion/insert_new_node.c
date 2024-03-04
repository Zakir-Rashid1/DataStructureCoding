


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

#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *left;
  int data;
  struct node *right;
}*head = NULL;


struct node* create_node(){
  return malloc(sizeof(struct node));
}


//Add left child
void add_left_child(struct node *ptr, int data){
  struct node *temp = create_node();
  temp->left = temp->right = NULL;

  temp->data = data;
  ptr->left = temp;
}


//Add right child
void add_right_child(struct node *ptr, int data){
  struct node *temp = create_node();
  temp->left = temp->right = NULL;

  temp->data = data;
  ptr->right = temp;
}



//Create tree
void create_tree(struct node *ptr){
  add_left_child(ptr, 90);
  add_left_child(ptr->left, 80);
  add_right_child(ptr->left, 95);
  add_left_child(ptr->left->left, 70);
  add_right_child(ptr->left->left, 85);

  add_right_child(ptr, 110);
  add_left_child(ptr->right, 105);
  add_right_child(ptr->right, 150);
  add_right_child(ptr->right->left, 108);
  add_left_child(ptr->right->left->right, 106);
}



//Inorder traversal
void inorder(struct node *ptr){
  if(ptr == NULL)
    return;
  inorder(ptr->left);
  printf("%d ", ptr->data);
  inorder(ptr->right);
}


//Add new node
void insert(struct node *ptr, int data){
  struct node *temp = NULL;
  struct node *newNode = create_node();
  newNode->left = newNode->right = NULL;
  newNode->data = data;

    while(ptr != NULL){
      if(data >= ptr->data){
        temp = ptr;
        ptr = ptr->right;
      }
      else{
        temp = ptr;
        ptr = ptr->left;
      }
    }

    if(data >= temp->data)
      temp->right = newNode;
    else
      temp->left = newNode;
}


//Testing
int main(){
  head = create_node();
  head->data = 100;
  create_tree(head);

  printf("Before Addition of New Node: ");
  inorder(head);

  insert(head, 109);
  printf("\nAfter Addition of New Node: ");
  inorder(head);

  return 0;
}
