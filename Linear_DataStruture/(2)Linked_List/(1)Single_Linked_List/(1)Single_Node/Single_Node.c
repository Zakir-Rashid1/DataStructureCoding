

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};


int main(){
    //Creating A Single Node Linked List
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 100; // (*head).data = 100;
    head->link = NULL;

    printf("Data is: %d\n", head->data);

    char ch = 45;
    printf("%c", ch);

    return 0;
}
