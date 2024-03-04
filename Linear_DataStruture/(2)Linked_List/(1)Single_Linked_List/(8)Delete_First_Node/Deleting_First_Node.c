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
        printf("List Is Empty");
        exit(1);
    }
    printf("\nData On List Is:\n");
    while(head != NULL){
        printf("%d\t", head->data);
        head = head->link;
    }
}

//Delete First Node
void dlt_first_node(struct Node **head){
    if(*head == NULL){
        printf("List Is Empty");
        exit(1);
    }else{
        struct Node *temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}



int main(){
    struct Node *head = NULL, *temp = NULL;
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;
    temp = head;


    //Add Some Nodes
    head = add_new_nodes(head, 200);
    head = add_new_nodes(head, 300);
    head = add_new_nodes(head, 400);
    traverse_list(temp);

    //delete first node
    dlt_first_node(&temp);
    traverse_list(temp);

    //delete second node
    dlt_first_node(&temp);
    traverse_list(temp);

    return 0;
}

