#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


// add to empty
struct Node* add_to_empty(struct Node *head, int data){
    struct Node *ptr = NULL;
    ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    head = ptr;
    return head;
}

//add at end
void add_at_end(struct Node *head, int data){
    struct Node *ptr = NULL;
    struct Node *temp = head;

    ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    ptr->prev = temp;
    temp->next = ptr;
}


//delete first node
void del_first_node(struct Node **head){
    struct Node *temp = *head;

    if((*head)->next == NULL && (*head)->prev == NULL){
        printf("\nNode  %d is deleted\n", (*head)->data);
        free(*head);
        *head = NULL;
    }else{
        printf("\nNode  %d is deleted\n", (*head)->data);
        *head = (*head)->next;
        (*head)->prev = NULL;
    
        free(temp);
        temp = NULL;   
    }

}


//traverse the list
void traverse_list_frwd(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("List is already empty\n");
    else{
        printf("\nData on list is: \n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}



int main(){
    struct Node *head = NULL;


    //add to empty
    head = add_to_empty(head, 100);

    //add at end
    add_at_end(head, 200);
    add_at_end(head, 300);
    add_at_end(head, 400);

    //traverse the list (frwd)
    traverse_list_frwd(head);

    //delete first node
    del_first_node(&head);
    traverse_list_frwd(head);

    //delete first node
    del_first_node(&head);
    traverse_list_frwd(head);

    //delete first node
    del_first_node(&head);
    traverse_list_frwd(head);

    return 0;
}