
//Array Representation of Trees
#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

/*
             100
            /   \
          200    300
         /  \      \
        400  500    800



*/



//Create a node
struct node* create_node(){
  return malloc(sizeof(struct node));
}


//Create a root node
void create_root_node(int data){
  root = create_node();
  root->left = root->right = NULL;
  root->data = data;
  enQueue(root);
}



//Add left child
void add_left_child(struct node *ptr){
  struct node *temp = create_node();
  int data;
  printf("Add Data: ");
  scanf("%d", &data);
  temp->left = temp->right = NULL;
  temp->data = data;
  enQueue(temp);

  ptr->left = temp;
}


//Add right child
void add_right_child(struct node *ptr){
  struct node *temp = create_node();
  int data;
  printf("Add Data: ");
  scanf("%d", &data);
  temp->left = temp->right = NULL;
  temp->data = data;
  enQueue(temp);

  ptr->right = temp;
}


//Construct a Tree
void create(){
  struct node *ptr = NULL;
  int your_choice;

  while(!isEmpty()){
    ptr = deQueue();
    printf("Do you wanna create a left child of %d (1/0): ", ptr->data);
    scanf("%d", &your_choice);
    if(your_choice)
      add_left_child(ptr);

    printf("Do you wanna create a right child of %d (1/0): ", ptr->data);
    scanf("%d", &your_choice);
    if(your_choice)
      add_right_child(ptr);
  }

}



//Preoder
void preorder(struct node *ptr){
  if(ptr == NULL)
    return;
  printf("%d ", ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
}



//Testing
int main(){
  create_root_node(100);
  create();

  preorder(root);

  return 0;
}
