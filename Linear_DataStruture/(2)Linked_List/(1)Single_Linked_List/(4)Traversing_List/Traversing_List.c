#include <stdio.h>
#include <stdlib.h>

struct Node* singlyLinkedList();
void traversingList();
struct Node{
    int data;
    struct Node* link;
};


int main(){
    //Create A Singly Linked List
    struct Node *head;
    head = singlyLinkedList();
    traversingList(head);

    return 0;
}

//Creating A Singly Linked List
struct Node* singlyLinkedList(){
    struct Node *head = NULL, *current = NULL;
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;

    current = malloc(sizeof(struct Node));
    current->data = 200;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct Node));
    current->data = 300;
    current->link = NULL;
    head->link->link = current;

    current = malloc(sizeof(struct Node));
    current->data = 400;
    current->link = NULL;
    head->link->link->link = current;

    return head;
}


// Traversing A Singly Linked List
void traversingList(struct Node *head){
    struct Node *ptr = NULL;
    ptr = head;

    if(ptr == NULL){
        printf("List is emplyt");
        exit(1);
    }
    printf("Data of Singly Linked List Is:\n");
    while(ptr !=NULL){
        printf("%d\t\t", ptr->data);
        ptr = ptr->link;
    }
}











