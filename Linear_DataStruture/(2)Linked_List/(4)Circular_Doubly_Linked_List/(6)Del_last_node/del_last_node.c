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


//del first node
struct Node* del_first_node(struct Node *tail){
    struct Node *head = NULL;

    if(tail == NULL){
        printf("list is empty");
        return tail;
    }else if(tail == tail->next){
        printf("Node %d is deleted\n\n", tail->data);
        free(tail);
        tail = NULL;
        return tail;
    }else{
        head = tail->next;
        tail->next = head->next;
        head->next->prev = tail;

        printf("Node %d is deleted\n\n", head->data);
        free(head);
        head = NULL;

        return tail;
    }
}



//del last node
struct Node* del_last_node(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is empty\n");
        return tail;
    }else if(tail == tail->next){
        tail = del_first_node(tail);
        return tail;
    }else{
        temp = tail;
        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;

        printf("Node %d is deleted\n\n", tail->data);
        tail = tail->prev;

        free(temp);
        temp = NULL;
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
        printf("Data on list is\n");
        head = tail->next;
        
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
    printf("\n");
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

    tail = del_first_node(tail);
    traverse_list(tail);

    tail = del_last_node(tail);
    tail = del_last_node(tail);
    traverse_list(tail);

    return 0;
}










