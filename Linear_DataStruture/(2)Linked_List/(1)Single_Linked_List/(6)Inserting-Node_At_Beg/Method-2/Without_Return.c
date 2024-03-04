#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *link;
};

void insert_at_beg(struct Node**, int);
void traverse_list(struct Node*);


//Add New Node At The beg
void  insert_at_beg(struct Node **head, int data){
    struct Node *newHead = NULL;
    newHead = malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->link = *head;

    *head = newHead;
    
}

//Traverse The Whole List
void traverse_list(struct Node *head){
    struct Node *ptr = head;

    if(head == NULL){
        printf("List Is Empty");
        exit(1);
    }

    printf("Data of Linked List is: \n");
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n");
}



int main(){
    struct Node *head = NULL;
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;

    struct Node *current = NULL;
    current = malloc(sizeof(struct Node));
    current->data = 200;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct Node));
    current->data = 300;
    current->link = NULL;
    head->link->link = current;

    insert_at_beg(&head, 50);
    traverse_list(head);
    insert_at_beg(&head, 30);
    traverse_list(head);




    return 0;
}





