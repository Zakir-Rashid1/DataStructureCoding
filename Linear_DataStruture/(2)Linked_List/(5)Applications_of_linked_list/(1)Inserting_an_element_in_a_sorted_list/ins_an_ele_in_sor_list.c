#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


//add to empty
struct Node* add_to_empty(struct Node *head, int data){
    struct Node *ptr = NULL;

    if(head == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        head = ptr;
        return head;
    }else{
        printf("list is not empty\n");
    }
}


//add at end
struct Node* add_at_end(struct Node *head, int data){
    struct Node *ptr = NULL;
    struct Node *temp = NULL;

    if(head == NULL){
        head = add_to_empty(head, data);
        return head;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        return head;
    }
}

//data must be in increasing order
//find your pos
struct Node* find_your_pos(struct Node *head, int key){
    struct Node *ptr = NULL;
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;

    ptr = malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->next = NULL;

    if(head == NULL || key < head->data)
        ptr->next = head;
    else{
        temp1 = head;
        while(temp1 != NULL){
            if(key > temp1->data)
                temp2 = temp1;
            temp1 = temp1->next;
        }
        ptr->next = temp2->next;
        temp2->next = ptr;
        return head;
    }
}





//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = NULL;

    if(head == NULL){
        printf("list is already empty\n");
        return;
    }else{
        printf("Data on list is\n");
        temp = head;
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


//testing
int main(){
    struct Node *head = NULL;

    //add to empty
    head = add_to_empty(head, 5);

    //add at end;
    head = add_at_end(head, 20);
    head = add_at_end(head, 24);
    head = add_at_end(head, 30);

    head = find_your_pos(head, 22);
    traverse_list(head);

    return 0;
}