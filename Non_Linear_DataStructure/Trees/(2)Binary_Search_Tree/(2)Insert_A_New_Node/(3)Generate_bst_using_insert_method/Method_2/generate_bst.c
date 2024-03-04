

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


//Generate BST Using Insert Method
struct node* insert(struct node *ptr, int data){
  if(ptr == NULL){
    struct node *temp = create_node();
    temp->left = temp->right = NULL;
    temp->data = data;

    return temp;
  }
  if(data > ptr->data)
    ptr->right = insert(ptr->right, data);
  else
    ptr->left = insert(ptr->left, data);

  return ptr;
}


//Testing
int main(){
  head = insert(head, 100);
  insert(head, 90); insert(head, 110); insert(head, 80);
  insert(head, 95); insert(head, 105); insert(head, 150);
  insert(head, 70); insert(head, 85); insert(head, 108);
  insert(head, 106); insert(head, 109);

  printf("BST Data: ");
  inorder(head);


  return 0;
}
