

/*
        Algorithm of Preorder traversal
    1. Visit the root node
    2. Traverse the left subtree 
    3. Traversse the right subtree


            10
           /  \
         20   30
        / \    \
       40  50   55

       Preorder Traversal: 10 20 40 50 30 55

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}Node;



//Create a BT
Node* binaryTree(){
    int input;
    printf("Do you wanna add node (1/0)? ");
    scanf("%d", &input);

    if(!input)
        return NULL;

    Node *tree = malloc(sizeof(Node));
    printf("Add Data: ");
    scanf("%d", &(tree->data));

    printf("You are about to add left child of %d \n", tree->data);
    tree->left = binaryTree();
    printf("You are about to add right child of %d \n", tree->data);
    tree->right = binaryTree();

    return tree;
}




void preorder(Node *tree){
    if(tree == NULL)
        return;
    printf("%d ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}


int main(){
    system("cls");

    Node *tree = binaryTree();
    
    if(tree == NULL)
        printf("Tree is empty\n");
    else{
        printf("Preorder Traversal is: ");
        preorder(tree);
    }

    return 0;
}