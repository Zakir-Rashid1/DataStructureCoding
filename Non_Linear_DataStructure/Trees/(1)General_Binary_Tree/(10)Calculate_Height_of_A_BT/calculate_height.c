


#include <stdio.h>
#include <stdlib.h>
struct node{
  struct node *left;
  int data;
  struct node *right;
}*head = NULL;


//Create node
struct node* create_node(){
  return malloc(sizeof(struct node));
}


//Create root node
struct node* create_root_node(int data){
  head = create_node();
  head->left = head->right = NULL;
  head->data = data;

  return head;
}


//Add left nod
void add_left_node(struct node *ptr){
  int data;
  struct node *temp = create_node();
  printf("Enter Data: ");
  scanf("%d", &data);

  ptr->left = temp;
  temp->data = data;
  temp->left = temp->right = NULL;
}



//Add right node
void add_right_node(struct node *ptr){
  int data;
  struct node *temp = create_node();
  printf("Enter Data: ");
  scanf("%d", &data);

  ptr->right = temp;
  temp->data = data;
  temp->left = temp->right = NULL;
}


//Create tree
void create_tree(struct node *ptr){
  if(ptr == NULL)
    return;
  int your_choice, data;
  printf("Do you wanna add the left child of %d (1/0): ", ptr->data);
  scanf("%d", &your_choice);
  if(your_choice)
    add_left_node(ptr);

  printf("Do you wanna add the right child of %d (1/0): ", ptr->data);
  scanf("%d", &your_choice);
  if(your_choice)
    add_right_node(ptr);

  create_tree(ptr->left);
  create_tree(ptr->right);

}


//preorder
void preorder(struct node *ptr){
  if(ptr == NULL)
    return;
  printf("%d ", ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
}



//Find height of a BT
int height(struct node *head){
  int left = 0;
  int right = 0;
  if(head == NULL)
    return 0;
  left = height(head->left);
  right = height(head->right);
  return ((left >= right) ? (left + 1) : (right + 1));
}


int main(){
  create_root_node(100);
  create_tree(head);

  preorder(head);
  printf("\nheight is %d ", height(head) - 1);



    return 0;
}
