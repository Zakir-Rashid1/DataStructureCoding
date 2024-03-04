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


//count no of nodes
int no_of_nodes(struct Node *head){
    int count = 0;
    if(head == NULL)
        return count;
    else{
        while(head != NULL){
            count++;
            head = head->next;
        }
    }
    return count;
}


//reverse the list
void reverse_list(struct Node **head){
    struct Node *temp = *head;
    struct Node *ptr = NULL;

    while(temp != NULL){
        ptr = temp->prev;
        temp->prev = temp->next;
        temp->next = ptr;

        temp = temp->prev;
    }
    *head = ptr->prev;
}

//traverse the list
void traverse_list_frwd(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("List is already empty\n");
    else{
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
    printf("Data Before Reversing\n");
    traverse_list_frwd(head);

    //reverse the list
    printf("\nData After Reversing\n");
    reverse_list(&head);
    traverse_list_frwd(head);


    return 0;
}
