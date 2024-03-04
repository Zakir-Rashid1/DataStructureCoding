
#include <stdio.h>
#include <stdlib.h>


/*                    
                  10
                /   \
               1    20
              / \    \
            9    8   55
            Not a Full BT

                  10
                /   \                    
               1    20                 
              / \   / \                        
            9    8 5  55                        
                Full BT                           

*/


typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}Node;


typedef enum bool{
    false, true
}boolean;




Node* create_node(){
    Node *new_node = malloc(sizeof(Node));
    return new_node;
}


Node* create_tree(){
    int data, input;
    printf("Do you wanna add a node 1/0? ");
    scanf("%d", &input);

    if(!input)
        return NULL;
    
    Node *new_node = create_node();
    printf("Enter the data: ");
    scanf("%d", &(new_node->data));

    printf("You are about to add left child of %d\n", new_node->data);
    new_node->left = create_tree();

    printf("You are about to add right child of %d\n", new_node->data);
    new_node->right = create_tree(10);

    return new_node;

}


void print(Node *new_node){
    printf("%d ", new_node->data);
    printf("%d ", new_node->left->data);
    printf("%d ", new_node->left->left->data);
    printf("%d ", new_node->left->right->data);
    printf("%d ", new_node->right->data);
    printf("%d ", new_node->right->left->data);
    printf("%d\n", new_node->right->right->data);

}



boolean is_full_bt(Node *tree){
    boolean left, right;
    if (tree == NULL);
        return true;
    if (tree->left == NULL && tree->right == NULL)
        return true;
    if(tree->left != NULL && tree->right != NULL){
        left = is_full_bt(tree->left);
        right = is_full_bt(tree->right);
        return (left && right);
    }
    return false;
    
}



int main(){
   system("CLS");
    Node *tree = create_tree();

    print(tree);


    if(is_full_bt(tree))
        printf("Given tree is a full binary tree\n");
    else
        printf("Given tree is not a full binary tree\n");


    return 0;
}