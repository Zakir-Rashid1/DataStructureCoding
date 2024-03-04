#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

//add to empty
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
    temp->next = ptr;
    ptr->prev = temp;
}

//add at beg
void add_at_beg(struct Node **head, int data){
    struct Node *ptr = NULL;
    ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = *head;
    (*head)->prev = ptr;

    *head = ptr;

}

//count no of nodes
int no_of_nodes(struct Node *head){
    struct Node *ptr = head;
    int count = 0;

    if(ptr == NULL)
        return count;
    else{
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}


//add at any position
void add_at_any_pos(struct Node **head, int data, int pos){
    struct Node *ptr = NULL;
    struct Node *temp = NULL;
    struct Node *temp1 = *head;

    if(pos == 1)
        add_at_beg(head, data);
    else if(pos == (no_of_nodes(*head) + 1))
        add_at_end(*head, data);
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        while(--pos){
            temp = temp1;
            temp1 = temp1->next;
        }
        temp1 = NULL;
        temp->next->prev = ptr;
        ptr->next = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
}


//traverse the list (frwd)
void traverse_list_frwd(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("Data on list is: \n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}



int main(){
    struct Node *head = NULL;
    struct Node *ptr = NULL;

    // add to empty
    head = add_to_empty(head, 100);

    //add at end
    add_at_end(head, 200);
    add_at_end(head, 300);
    add_at_end(head, 400);

    //add at beg
    add_at_beg(&head, 2);
    add_at_beg(&head, 3);

    //add at any position
    add_at_any_pos(&head, 190, 1);
    add_at_any_pos(&head, 180, 2);
    add_at_any_pos(&head, 15000, 9);


    //traverse
    traverse_list_frwd(head);



    return 0;
}