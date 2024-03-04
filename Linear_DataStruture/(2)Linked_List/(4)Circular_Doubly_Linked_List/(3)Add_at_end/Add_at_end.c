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
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = tail->next;
        tail->next->prev = ptr;
        tail->next = ptr;
        ptr->prev = tail;

        return tail;
    }
}

//add at end
struct Node* add_at_end(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        tail = add_to_empty(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = tail->next;
        tail->next->prev = ptr;
        tail->next= ptr;
        ptr->prev = tail;

        tail = ptr;
        return tail;
    }
}


//traverse list
void traverse_list(struct Node *tail){
    struct Node *head = NULL;
    if(tail == NULL){
        printf("list is empty\n");
        return;
    }else{
        printf("list on data is\n");
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

    //add at beg
    tail = add_at_beg(tail, 20);
    tail = add_at_beg(tail, 10);

    //add at end
    tail = add_at_end(tail, 200);
    tail = add_at_end(tail, 300);
    traverse_list(tail);


    return 0;
}




























