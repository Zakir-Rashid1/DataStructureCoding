#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//add to empty
struct Node* add_to_empty(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->prev = ptr;
        ptr->data = data;
        ptr->next = ptr;

        tail = ptr;
        return ptr;
    }else{
        printf("List is not empty\n");
    }
}


//traverse list
void traverse_list(struct Node *tail){
    struct Node *head = NULL;

    if(tail == NULL){
        printf("list is empty\n");
        return;
    }else{
        printf("Data on list is\n");
        head = tail->next;
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
}












//testing
int main(){
    struct Node *tail = NULL;

    //add to empty
    tail = add_to_empty(tail, 100);

    //traverse list
    traverse_list(tail);

    return 0;
}