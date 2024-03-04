#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};



struct node* create_node(){
    struct node *new_node = malloc(sizeof(struct node));
    return new_node;
}


struct node* create_tree(){
    int input, data;
    printf("Do you wanna add a node? 1/0: ");
    scanf("%d", &input);

    if(!input)
        return NULL;
    else{
        struct node *new_node = create_node();
        printf("Enter the data: ");
        scanf("%d", &(new_node->data));

        printf("You are about to add left child to this node %d\n", new_node->data);
        new_node->left = create_tree();
        printf("You are about to add right child to this node %d\n", new_node->data);
        new_node->right = create_tree();

        return new_node;
    }
    
}



//Testing

int main(){
    system("cls");
    struct node *new_node = create_tree();

    printf("%d ", new_node->data);
    printf("%d ", new_node->left->data);
    printf("%d ", new_node->right->data);





    return 0;
}