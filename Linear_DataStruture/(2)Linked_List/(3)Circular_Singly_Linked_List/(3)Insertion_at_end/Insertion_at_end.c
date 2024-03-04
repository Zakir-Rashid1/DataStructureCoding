#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//add to empty
struct Node* add_to_empty(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = ptr;

        tail = ptr;
        return tail;
    }else{
        printf("List is empty\n");
        return tail;
    }
}



//insert at beg
struct Node* add_at_beg(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        tail = add_to_empty(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        //time coplexicity is O(1)
        ptr->next = tail->next;
        tail->next = ptr;

        return tail;

    }
}


//insert at end
struct Node* add_at_end(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        tail = add_to_empty(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        // time complexicity is O(1)
        ptr->next = tail->next;
        tail->next = ptr;

        tail = ptr;
        return tail;
    }
}


//traverse the list
void traverse_lis(struct Node *head){
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

    //add to empty
    tail = add_to_empty(tail, 100);

    //add at beg
    tail = add_at_beg(tail, 7);
    tail = add_at_beg(tail, 3);

    //add at end
    tail = add_at_end(tail, 200);
    tail = add_at_end(tail, 300);
    traverse_lis(tail->next);



    return 0;
}