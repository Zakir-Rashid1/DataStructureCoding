

#include <stdio.h>
#include <stdlib.h>



/*
             10
            /  \
           20  30
               / \
              5   9
          Binary Tree

*/
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}Node;




//Create a BT
Node* create_tree(){
    int data, input;

    printf("Do you wanna create a node 1/0? ");
    scanf("%d", &input);

    if(!input)
        return NULL;
    else{
        Node *new_node = malloc(sizeof(Node));
        printf("Enter data: ");
        scanf("%d", &(new_node->data));

        printf("Your are about to add left child of %d\n", new_node->data);
        new_node->left = create_tree();
        printf("Your are about to add right child of %d\n", new_node->data);
        new_node->right = create_tree();

        return new_node;

    }
}




//Print data
void preorder(struct node *head){
  if(head == NULL)
    return;
  printf("%d ", head->data);
  preorder(head->left);
  preorder(head->right);
}


//Count number of nodes
//Start counting form leaf nodes
int count_no_nodes(Node *root){
    int left, right;
    if(root == NULL)
        return 0;
    left = count_no_nodes(root->left);
    right = count_no_nodes(root->right);
    return (1 + left + right);
}





int main(){
    system("cls");

    Node *node = create_tree();

    preorder(node);
    printf("\nNumber of nodes are: %d ",count_no_nodes(node));


    return 0;
}
