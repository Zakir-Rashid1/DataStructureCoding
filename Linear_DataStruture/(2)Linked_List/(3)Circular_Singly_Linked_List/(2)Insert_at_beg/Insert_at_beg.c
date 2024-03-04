#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


//add to empty
struct Node* add_to_empty(struct Node *tail, int data){
    struct Node *ptr = tail;

    if(tail == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = ptr;

        tail = ptr;
        return tail;
    }else{
        printf("list is not empty\n");
    }
}



//add at beg
struct Node* add_at_beg(struct Node *tail, int data){
    struct Node *ptr = NULL;
    
    if(tail == NULL){
        tail = add_to_empty(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        // wow : time complexity is O(1)
        ptr->next = tail->next;
        tail->next = ptr;

        tail = ptr;
        return tail;
    }
}


//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = head;

    if(temp == NULL){
        printf("list is already empty\n");
        return;
    }else{
        printf("Data on list is\n");
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}



//testing
int main(){
    struct Node *tail = NULL;
    struct Node *head = NULL;

    head = add_to_empty(tail, 100);
    tail = head;

    //add at beg
    head = add_at_beg(tail, 9);
    head = add_at_beg(tail, 8);
    traverse_list(head);


    return 0;
}