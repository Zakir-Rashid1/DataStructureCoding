#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//add node to empty list
struct Node* add_to_empty(struct Node *head, int data){
    struct Node *ptr = NULL;
    ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    head = ptr;
    return head;
}

//add new node at the end
struct Node* add_at_end(struct Node *head, int data){
    struct Node *ptr = NULL;
    if(head == NULL){
        printf("List is already empty\n");
        //return;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->prev = head;
        head->next = ptr;
        ptr->data = data;
        ptr->next = NULL;

        head = ptr;
        return head;
    }
}


//add new node at the beg
void add_at_beg(struct Node **head, int data){
    struct Node *ptr = NULL;
    if(*head == NULL){
        printf("List is already empty\n");
        return;
    }else{

        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = *head;

        (*head)->prev = ptr;
        *head = ptr;
    }
}


//traverse the list (frwd)
void traverse_list_frwd(struct Node *head){
    struct Node *ptr = head;
    if(head == NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("Data on list is:\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}



int main(){
    struct Node *head = NULL;
    struct Node *ptr = head;

    //add node to empty list
    head = add_to_empty(ptr, 100);
    ptr = head;

    //add node at the end
    ptr = add_at_end(ptr, 200);
    ptr = add_at_end(ptr, 300);

    //add node at the beg
    add_at_beg(&head, 400);
    add_at_beg(&head, 500);

    //add node at end
    ptr = add_at_end(ptr, 600);
    //traverse the list
    traverse_list_frwd(head);


    return 0;
}