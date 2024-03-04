#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node* add_nodes(struct Node*, int);
void traverse_list(struct Node*);
void add_at_beg(struct Node**, struct Node*);
void add_at_any_pos(struct Node**, struct Node*, int);

//Add Some More Nodes
struct Node* add_nodes(struct Node *head, int data){
    struct Node *ptr = head;

    struct Node *current = malloc(sizeof(struct Node));
    current->data = data;
    current->link = NULL;
    ptr->link = current;

    ptr = current;

    return ptr;
}

//Traverse List
void traverse_list(struct Node *head){
    struct Node *ptr = head;
    if(ptr == NULL){
        printf("List Is Empty");
        exit(1);
    }
    printf("\nData Of List IS: \n");
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
}


//Add At beg
void add_at_beg(struct Node **head, struct Node *newHead){

    newHead->link = *head;
    *head = newHead;
}

//Add At Any Position
void add_at_any_pos(struct Node **head, struct Node *newNode, int pos){
    struct Node *temp = *head;
    struct Node *ptr1 = NULL;
    if(pos == 1)
        add_at_beg(head, newNode);
    else{
        while(--pos){
            ptr1 = temp;
            temp = temp->link;
        }
        newNode->link = temp;
        ptr1->link = newNode;
    }

}



int main(){
    int num = 0, data = 0;
    struct Node *head = NULL;
    struct Node *tempHead = NULL;

    //Single Node
    head = malloc(sizeof(struct Node));
    head->data = 100;
    head->link = NULL;
    printf("Enter No Of Nodes To Add: ");
    scanf("%d", &num);

    //Add Nodes
    tempHead = head;
    for(int i = 1; i <= num; i++){
        printf("Enter Data: ");
        scanf("%d", &data);
        tempHead = add_nodes(tempHead, data);
    }
    traverse_list(head);

    //Add At Beg
    struct Node *newHead = NULL;
    newHead = malloc(sizeof(struct Node));
    newHead->data = 1;
    newHead->link = NULL;
    add_at_beg(&head, newHead);
    traverse_list(head);

    //Add At Any Position (Say Pos = 1)
    struct Node *newNode = NULL;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 307;
    newNode->link = NULL;
    add_at_any_pos(&head, newNode, 1);
    traverse_list(head);

      //Add At Any Position (Say Pos = 3)
    newNode = malloc(sizeof(struct Node));
    newNode->data = 304;
    newNode->link = NULL;
    add_at_any_pos(&head, newNode, 3);
    traverse_list(head);


    return 0;
}



