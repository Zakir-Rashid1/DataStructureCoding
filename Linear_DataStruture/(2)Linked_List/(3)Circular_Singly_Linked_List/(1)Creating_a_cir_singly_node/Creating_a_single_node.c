#include <stdio.h>
#include <stdlib.h>

struct Node {
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
        printf("List is not empty\n");
    }
}


//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = head;

    if(temp == NULL){
        printf("List is already empty\n");
        return;
    }else{
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

    //add to empty
    tail = add_to_empty(head, 100);
    head = tail;

    //printf / traverse list
    traverse_list(head);

    return 0;
}