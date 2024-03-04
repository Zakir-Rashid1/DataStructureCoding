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


//del first node
struct Node* del_first_node(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is empty\n");
        return tail;
    }else if(tail->next == tail){
        printf("Node %d is deleted\n", tail->data);
        free(tail);
        tail = NULL;
        return tail;
    }else{
        temp = tail->next;
        tail->next = temp->next;
        printf("Node %d is deleted\n", temp->data);
        free(temp);
        temp = NULL;

        return tail; 
    }
}




//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = NULL;

    if(head == NULL){
        printf("list is already emtpy\n");
        return;
    }else{
        temp = head->next;
        printf("\nData on list is\n");
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
    printf("\n");
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
    traverse_list(tail);

    //del first node
    tail = del_first_node(tail);
    traverse_list(tail);

    //del second first node
    tail = del_first_node(tail);
    traverse_list(tail);
   

}