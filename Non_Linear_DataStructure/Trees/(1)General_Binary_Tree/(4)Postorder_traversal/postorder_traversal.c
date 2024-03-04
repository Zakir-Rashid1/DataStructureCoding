

/*
        Algorithm of Postorder traversal
    1. Traverse the left subtree 
    2. Traversse the right subtree
    3. Visit the root node of the tree


            10
           /  \
         20   30
        / \    \
       40  50   55

       Postorder Traversal: 40 50 20 55 30 10 

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




void postorder(Node *tree){
    if(tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->data);
}


int main(){
    system("cls");

    Node *tree = binaryTree();
    
    if(tree == NULL)
        printf("Tree is empty\n");
    else{
        printf("Preorder Traversal is: ");
        postorder(tree);
    }

    return 0;
}