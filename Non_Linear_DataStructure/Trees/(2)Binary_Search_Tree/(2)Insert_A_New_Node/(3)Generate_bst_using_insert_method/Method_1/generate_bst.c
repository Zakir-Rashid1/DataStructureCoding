
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


//Inorder traversal
void inorder(struct node *ptr){
  if(ptr == NULL)
    return;
  inorder(ptr->left);
  printf("%d ", ptr->data);
  inorder(ptr->right);
}


//Insert at right
void add_at_right(struct node *ptr, int data){
  struct node *temp = create_node();
  temp->left = temp->right = NULL;
  temp->data = data;
  ptr->right = temp;
}


//Insert at left
void add_at_left(struct node *ptr, int data){
  struct node *temp = create_node();
  temp->left = temp->right = NULL;
  temp->data = data;
  ptr->left = temp;
}


//Generate BST
void insert(struct node *ptr, int data){
  if(ptr == NULL)
    return;
  if(data >= ptr->data){
    insert(ptr->right, data);
    if(ptr->right == NULL)
      add_at_right(ptr, data);
  }else{
    insert(ptr->left, data);
    if(ptr->left == NULL)
      add_at_left(ptr, data);
  }
}


//Testing
int main(){
  head = create_node();
  head->data = 100;
  head->left = head->right = NULL;

  insert(head, 90); insert(head, 110); insert(head, 80);
  insert(head, 95); insert(head, 105); insert(head, 150);
  insert(head, 70); insert(head, 85); insert(head, 108);
  insert(head, 106); insert(head, 109);

  printf("BST Data: ");
  inorder(head);


  return 0;
}
