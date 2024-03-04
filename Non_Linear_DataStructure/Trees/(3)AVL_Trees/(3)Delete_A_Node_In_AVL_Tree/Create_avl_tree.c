
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
  int data; int bf;
  struct node *right;
}*root = NULL;

typedef enum bool{
  false, true
}boolean;


//Create a node
struct node* create_node(){
  return malloc(sizeof(struct node));
}

//Calculate height
int height(struct node *ptr){
  int left = 0;
  int right = 0;
  if(ptr == NULL)
    return 0;
  left = height(ptr->left);
  right = height(ptr->right);
  return left > right ? left + 1 : right + 1;
}

//Inorder traversal
void inorder(struct node *ptr){
  if(ptr == NULL)
    return;
  inorder(ptr->left);
  printf("%d(%d)  ", ptr->data, ptr->bf);
  inorder(ptr->right);
}

//Update BF
void update_bf(struct node *ptr){
  if(ptr == NULL)
    return;
  update_bf(ptr->left);
  update_bf(ptr->right);
  ptr->bf = height(ptr->left) - height(ptr->right);
}


//LL-Rotation on BST
struct node* LLRotation(struct node *ptr){
  struct node *ptrL = ptr->left;
  struct node *ptrLR = ptrL->right;

  ptrL->right = ptr;
  ptr->left = ptrLR;

  if(ptr == root)
    root = ptrL;
  update_bf(ptrL); //updates bf of only 3 nodes
  return ptrL;
}


//RR-Rotation on BST
struct node* RRRotation(struct node *ptr){
  struct node *ptrR = ptr->right;
  struct node *ptrRL = ptrR->left;

  ptrR->left = ptr;
  ptr->right = ptrRL;

  if(ptr == root)
    root = ptrR;
  update_bf(ptrR);
  return ptrR;
}


//LR-Rotation on BST
struct node* LRRotation(struct node *ptr){
  struct node *ptrL = ptr->left;
  struct node *ptrLR = ptrL->right;

  ptr->left = ptrLR->right;
  ptrL->right = ptrLR->left;

  ptrLR->left = ptrL;
  ptrLR->right = ptr;
  if(root == ptr)
    root = ptrLR;
  update_bf(ptrLR);
  return ptrLR;
}


//RL-Rotation on BST
struct node* RLRotation(struct node *ptr){
  struct node *ptrR = ptr->right;
  struct node *ptrRL = ptrR->left;

  ptr->right = ptrRL->left;
  ptrR->left = ptrRL->right;

  ptrRL->left = ptr;
  ptrRL->right = ptrR;

  if(root == ptr)
    root = ptrRL;
  update_bf(ptrRL);
  return ptrRL;
}


//Create an AVL tree
struct node* create_avl_tree(struct node *root, int data){
  if(root == NULL){
    root = create_node();
    root->left = root->right = NULL;
    root->data = data;
    root->bf = 0;

    return root;
  }
  if(data < root->data){
    root->left = create_avl_tree(root->left, data);
    root->bf = height(root->left) - height(root->right);
  }else{
    root->right = create_avl_tree(root->right, data);
    root->bf = height(root->left) - height(root->right);
  }

  //Perform Rotations
  if(root->bf == 2 && root->left->bf == 1)
    root = LLRotation(root);
  else if(root->bf == -2 && root->right->bf == -1)
    root = RRRotation(root);
  else if(root->bf == 2 && root->left->bf == -1)
    root = LRRotation(root);
  else if(root->bf == -2 && root->right->bf == 1)
    root = RLRotation(root);

  return root;
}
