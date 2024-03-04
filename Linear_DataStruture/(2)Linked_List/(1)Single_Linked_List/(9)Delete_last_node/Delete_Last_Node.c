#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};


//Add Some New Nodes
struct Node* add_new_nodes(struct Node *head, int data){
    struct Node *ptr = NULL;
    ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    head->link = ptr;
    head = ptr;

    return head;
}

//Traverse The List
void traverse_list(struct Node *head){
    if(head == NULL){
        printf("\nList Is Empty");
        exit(1);
    }else{
        printf("Data On List Is: \n");
        while(head != NULL){
            printf("%d\t", head->data);
            head = head->link;
        }
    }
}


//Delete The Last Node
struct Node* del_at_last(struct Node *head){
    struct Node *ptr = head;
    struct Node *temp = NULL;
    
    if(head == NULL){
        printf("\nList Is Empty");
        exit(1);
    }else if(head->link == NULL){
        printf("\nNode: %d is deleted", head->data);
        free(head);
        head = NULL;
        return head;
    }else{
        while(ptr->link != NULL){
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        printf("\nNode: %d is deleted \n", ptr->data);
        free(ptr);
        ptr = NULL;
        
        return head;
    }
}


int main(){
    struct Node *head = NULL, *temp = NULL;
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;
    temp = head;

    head = add_new_nodes(head, 200);
    head = add_new_nodes(head, 300);
    head = add_new_nodes(head, 400);
    traverse_list(temp);

    //delete at end
    temp = del_at_last(temp);
    traverse_list(temp);

    temp = del_at_last(temp);
    traverse_list(temp);

    temp = del_at_last(temp);
    traverse_list(temp);

    temp = del_at_last(temp);
    traverse_list(temp);




    return 0;
}