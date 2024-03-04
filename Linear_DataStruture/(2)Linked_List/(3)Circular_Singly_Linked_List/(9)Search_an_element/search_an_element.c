#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef enum boolean{
    false, true
}boolean;

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
        printf("List is not empty\n");
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

//add at end
struct Node* add_at_end(struct Node *tail, int data){
    struct Node *ptr = NULL;
    struct Node *temp = tail;

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



//search an element
boolean search_an_ele(struct Node *tail, int sele){
    struct Node *head = NULL;

    if(tail == NULL)
        printf("list is empty\n");
    else if(tail->next == tail){
        if(tail->data == sele || tail->next->data == sele)
            return true;
        else
            return false;
    }else{
        head = tail->next;
        while(head->next != tail->next){
            if(head->data == sele)
                return true;
            head = head->next;
        }
        return false;
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
        printf("\n");
    }
}




//testing
int main(){
    int nod = 0;
    struct Node *tail = NULL;

    //add to empty
    tail = add_to_empty(tail, 100);
    traverse_list(tail);

    // add at beg
    tail = add_at_beg(tail, 2);
    tail = add_at_beg(tail, 1);
    traverse_list(tail);

    //add at end
    tail = add_at_end(tail, 200);
    tail = add_at_end(tail, 300);
    traverse_list(tail);

    if(search_an_ele(tail, 3001))
        printf("Element Found\n");
    else
        printf("Element Not Found\n");


    return 0;
}





