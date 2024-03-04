

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
    head->link = malloc(sizeof(struct Node));
    head->link->data = 200;
    head->link->link = malloc(sizeof(struct Node));
    head->link->link->data = 300;
    head->link->link->link = NULL;

    printf("Data in First Node : %d\n", head->data);
    printf("Data in Second Node: %d\n", head->link->data);
    printf("Data in Third Node : %d\n", head->link->link->data);

    return 0;
}
