#include <stdio.h>
#include <stdlib.h>



struct Node{
    int data;
    struct Node *link;
};


int main(){
    struct Node *head = NULL;
    head = malloc(sizeof(struct Node*));
    head->data = 100;
    head->link = NULL;

    head->link = malloc(sizeof(struct Node));
    head->link->data = 200;
    head->link->link = NULL;

    head->link->link = malloc(sizeof(struct Node));
    head->link->link->data = 300;
    head->link->link->link = NULL;

    head->link->link->link = malloc(sizeof(struct Node));
    head->link->link->link->data = 400;
    head->link->link->link->link = NULL;

    //Now printing the data
    printf("Data of Single Linked List Is: ");
    printf("%d\t", head->data);
    printf("%d\t", head->link->data);
    printf("%d\t", head->link->link->data);
    printf("%d\t", head->link->link->link->data);


    return 0;
}