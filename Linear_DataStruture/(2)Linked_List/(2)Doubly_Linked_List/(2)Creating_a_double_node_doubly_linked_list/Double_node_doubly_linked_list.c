#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

//Add some new nodes
struct Node* add_some_nodes(struct Node *head){
    struct Node *newNode = NULL;

    newNode = malloc(sizeof(struct Node));
    head->next = newNode;
    newNode->prev = head;
    newNode->data = 200;
    newNode->next = NULL;

    head = newNode;
    return head;
}

//Traverse the list (Forward Traversing)
void traverse_list_frwd(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("Data from forward traverse\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


//Traversing the list(Backward Traversing)
void traverse_list_bkwd(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL){
        printf("List is already empty\n");
        return;
    }else{
        //Moving ptr pointer to point the last node
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        //Now traversing the list Backward
        printf("Data from backward traverse\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}



int main(){
    struct Node *head = NULL;
    struct Node *ptr = NULL;
    head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 100;
    head->next = NULL;

    ptr = head;

    //add new node
    ptr = add_some_nodes(ptr);

    //forward traversing
    traverse_list_frwd(head);

    //backward traversing
    traverse_list_bkwd(head);



    

    return 0;
}