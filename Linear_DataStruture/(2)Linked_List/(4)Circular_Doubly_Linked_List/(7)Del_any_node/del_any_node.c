#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//add to empty
struct Node* add_to_empty(struct Node* tail, int data){
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
        ptr->prev = tail;
        tail->next = ptr;

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
        tail->next = ptr;
        ptr->prev = tail;

        tail = ptr;
        return tail;
    }
}


//del at beg
struct Node* del_at_beg(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is already empty\n");
        return tail;
    }else if(tail == tail->next){
        printf("Node %d is deleted\n", tail->data);
        free(tail);
        tail = NULL;
        return tail;
    }else{
        temp = tail->next;
        tail->next = temp->next;
        temp->next->prev = tail;

        printf("Node %d is deleted\n", temp->data);
        free(temp);
        temp = NULL;

        return tail;
    }
}



//del at end
struct Node* del_at_end(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is already empty\n");
        return tail;
    }else if(tail == tail->next){
        tail = del_at_beg(tail);
        return tail;
    }else{
        temp = tail;
        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;

        printf("Node %d is deleted\n", temp->data);
        tail = temp->prev;
        free(temp);
        temp = NULL;
        return tail;
    }
}


//count no of nodes
int no_of_nodes(struct Node *tail){
    struct Node *head = NULL;
    int count = 0;
    if(tail == NULL)
        return count;
    else{
        head = tail->next;
        do{
            count++;
            head = head->next;
        }while(head != tail->next);

        return count;
    }
}



//del at any pos
struct Node* del_at_any_pos(struct Node *tail, int pos){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is already empty\n");
        return tail;
    }else if(pos == 1){
        tail = del_at_beg(tail);
        return tail;
    }else if(pos == (no_of_nodes(tail) + 1)){
        tail = del_at_end(tail);
        return tail;
    }else{
        temp = tail->next;
        while(--pos){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        printf("Node %d is deleted\n", temp->data);
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
        printf("\nData on list is\n");
        head = tail->next;
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
    printf("\n\n");
}






//testing
int main(){
    struct Node *tail = NULL;

    //add to empty
    tail = add_to_empty(tail, 100);

    //add at beg
    tail = add_at_beg(tail, 40);
    tail = add_at_beg(tail, 20);

    //add at end
    tail = add_at_end(tail, 200);
    tail = add_at_end(tail, 300);
    traverse_list(tail);


    //del first node
    tail = del_at_beg(tail);
    traverse_list(tail);

    
    //del at end
    tail = del_at_end(tail);
    traverse_list(tail);

    //del at pos
    tail = del_at_any_pos(tail, 3);
    traverse_list(tail);
    return 0;
}


