#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};


//Add some more nodes
struct Node* add_some_nodes(struct Node *head, int data){
    struct Node *ptr = NULL;
    ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    head->link = ptr;
    head = ptr;
    return head;
}

//Traverse the list
void traverse_list(struct Node *head){
    struct Node *ptr = head;

    if(ptr == NULL){
        printf("\nList is already empty\n");
        exit(1);
    }else{
        printf("\nData on list is\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
}


//Delete at beg
struct Node* delete_at_beg(struct Node **head){
    struct Node *ptr = *head;

    if(ptr == NULL){
        printf("\nList is already empty\n");
        exit(1);
    }else{
        *head = (*head)->link;
        free(ptr);
        ptr = NULL;

        return *head;
    }
}


//del at some position
struct Node* del_at_pos(struct Node *head, int pos){
    struct Node *temp = NULL;
    struct Node *temp1 = NULL, *ptr = head;
    struct Node *temp2 = NULL;
    if(pos <= 0){
        printf("Invalid Position\n");
        exit(1);
    }else if(pos == 1){
        temp = delete_at_beg(&head);
        return temp;
    }else{
        pos--;
        while(pos != 0){
            temp1 = ptr;
            temp2 = temp1->link;
            ptr = ptr->link;
            pos--;
        }
        temp1->link = temp2->link;

        free(temp2);
        temp2 = ptr = NULL;

        return head;
    }
}




int main(){
    struct Node *head = NULL, *ptr = NULL;
    struct Node *newHead = NULL;
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;
    ptr = head;

    //add some nodes
    head = add_some_nodes(head, 200);
    head = add_some_nodes(head, 300);
    head = add_some_nodes(head, 400);

    //traverse list
    traverse_list(ptr);

    //del at pos
    newHead = del_at_pos(ptr, 3);
    traverse_list(newHead);

    newHead = del_at_pos(ptr, 1);
    traverse_list(newHead);

    
    

    return 0;
}
