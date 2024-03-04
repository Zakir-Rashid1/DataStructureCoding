
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
  int data;
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


//Return immediate Inorder Predecessor
struct node* inorder_predecessor(struct node *ptr){
  struct node *temp = NULL;
  if(ptr->right == NULL)
    return ptr;
  temp = inorder_predecessor(ptr->right);
  return temp;
}


//Return immediate Inorder Successor
struct node* inorder_Successor(struct node *ptr){
  struct node *temp = NULL;
  if(ptr->left == NULL)
    return ptr;
  temp = inorder_Successor(ptr->left);
  return temp;
}


//Height of a left sub Tree
int height(struct node *ptr){
  if(ptr == NULL)
    return 0;
  return (height(ptr->left) >= height(ptr->right) ? height(ptr->left) + 1: height(ptr->right) + 1);
}



//delete node
//Avg Time Cxpty: O(log(h) * log(h))
//Best Time Cxpty: O(log(h))
//Worst Time Cxpty: O(log(n))  n-->number of nodes
struct node* delete(struct node *ptr, int key){
  struct node *temp = NULL;

  if(ptr->left == NULL && ptr->right == NULL){
    if(ptr == head)
      head = NULL;
    free(ptr);
    ptr = NULL;
    return ptr;
  }
  if(key < ptr->data)
    ptr->left = delete(ptr->left, key);
  else if(key > ptr->data)
    ptr->right = delete(ptr->right, key);
  else{
    //Its not imp to find the height, so it will not contribute while calculating Time Cxplty
    if(height(ptr->left) > height(ptr->right)){
      temp = inorder_predecessor(ptr->left);
      ptr->data = temp->data;
      ptr->left = delete(ptr->left, temp->data);
    }
    else{
      temp = inorder_Successor(ptr->right);
      ptr->data = temp->data;
      ptr->right = delete(ptr->right, temp->data);
    }
  }

  return ptr;
}

/*
if we remove height then below piece of code should be inserted
if(ptr->left == NULL)
  successor(ptr->right);
else if(ptr->right == NULL)
  predecessor(ptr->left);
else
  successor(ptr->right); // or predecessor(ptr->left);
*/





//Testing
int main(){
  head = insert(head, 100);
  insert(head, 90); insert(head, 110); insert(head, 80);
  insert(head, 95); insert(head, 105); insert(head, 150);
  insert(head, 70); insert(head, 85); insert(head, 108);
  insert(head, 106); insert(head, 109);

  printf("\nBinary Tree Data Before Deletion: ");
  inorder(head);
  delete(head, 110);

  printf("\nBinary Tree Data After Deletion: ");
  inorder(head);


  return 0;
}
