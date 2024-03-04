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
        printf("list is not empty\n");
        return tail;
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

        ptr->next = tail->next;
        tail->next = ptr;

        return tail;
    }
}


// add at end
struct Node* add_at_end(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL){
        tail = add_to_empty(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = tail->next;
        tail->next = ptr;

        tail = ptr;
        return tail;
    }
}


//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = head;

    if(head == NULL){
        printf("list is already emtpy\n");
        return;
    }else{
        printf("Data on list is\n");
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}


//count no of nodes
int no_of_nodes(struct Node *head){
    struct Node *temp = head;
    int count = 0;

    if(head == NULL)
        return count;
    else{
        do{
            temp = temp->next;
            count++;
        }while(temp != head);

        return count;
    }
}


//add at any pos
struct Node* add_at_any_pos(struct Node *tail, int data, int pos){
    struct Node *head = tail;
    struct Node *ptr = NULL;

    if(pos == 1){
        tail = add_at_beg(tail, data);
        return tail;
    }else if(pos == (no_of_nodes(tail->next) + 1)){
        tail = add_at_end(tail, data);
        return tail;
    }else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        pos--;
        head = head->next;
        while(--pos){
            head = head->next;
        }
        ptr->next = head->next;
        head->next = ptr;

        return tail;
    }
}



//testing
int main(){
    struct Node *tail = NULL;
    int nod = 0;

    //add to empty
    tail = add_to_empty(tail, 100);

    //add at beg
    tail = add_at_beg(tail, 9);
    tail = add_at_beg(tail, 7);

    //add at end
    tail = add_at_end(tail, 200);
    tail = add_at_end(tail, 300);
    traverse_list(tail->next);

    //count no of nodes
    nod = no_of_nodes(tail->next);
    printf("\nNo of nodes are: %d ", nod);

    //add at any pos
    tail = add_at_any_pos(tail, 33, 2);
    traverse_list(tail->next);

    return 0;
}