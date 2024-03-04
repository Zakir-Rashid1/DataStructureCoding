
/*
A tree is not a complete binary tree, if index of a particular node >= number of nodes

                  10(0)
               /      \
           (1)20      30(2)
             /  \     /
         (3)40 (4)60 8(5)
               CBT  


                 10(0)
               /      \
           (1)20      30(2)
             /  \       \
         (3)40 (4)60    8(6)
              NOT A  CBT 
        Clearly, the index of 8 is 6 which is >= number of nodes

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}Node;


typedef enum bool{
    false, true
}boolean;



//Create a BT
Node* createBinaryTree(){
    int input;
    printf("Do you wanna add a node (1/0)? ");
    scanf("%d", &input);

    if(!input)
        return NULL;

    Node *tree = malloc(sizeof(Node));
    printf("Add data: ");
    scanf("%d", &(tree->data));

    printf("You are about to add left child of %d \n", tree->data);
    tree->left = createBinaryTree();
    printf("You are about to add right child of %d \n", tree->data);
    tree->right = createBinaryTree();

    return tree;
}


//Count number of nodes
int countNodes(Node *tree){
    int left, right;
    if(tree == NULL)
        return 0;
    if(tree->left  == NULL && tree->right == NULL)
        return 1;
    else{
        left = countNodes(tree->left);
        right = countNodes(tree->right);
        return(1 + left + right);
    }
}


//Check weather the BT is a complete BT or Not
boolean isCompleteBinaryTree(Node *tree, int i, int nod){
    boolean left, right;
    if(tree == NULL)
        return true;
    if(i >= nod)
        return false;
    else{
        left = isCompleteBinaryTree(tree->left, (2 * i + 1), nod);
        right = isCompleteBinaryTree(tree->right, (2 * i + 2), nod);
        return(left && right);
    }
}


//Testing

int main(){

    system("cls");
    Node *tree = createBinaryTree();
    printf("Number of nodes are: %d", countNodes(tree));

    if(isCompleteBinaryTree(tree, 0, countNodes(tree)))
        printf("Given BT is a complete BT\n");
    else
        printf("Given BT is not a complete BT\n");

    return 0;
}