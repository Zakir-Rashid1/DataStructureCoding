

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};


int main(){
    //Creating A Triple Node Linked List
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 100; // (*head).data = 100;
    head->link = NULL;

    struct Node *current = malloc(sizeof(struct Node));
    current->data = 200;
    current->link = NULL;
    head->link = current; // update

    //Now i can reuse the current pointer 
    current = malloc(sizeof(struct Node));
    current->data = 300;
    current->link = NULL;
    head->link->link = current;


    printf("Data in First Node : %d\n", head->data);
    printf("Data in Second Node: %d\n", head->link->data);
    printf("Data in Third Node : %d\n", head->link->link->data);

    return 0;
}
