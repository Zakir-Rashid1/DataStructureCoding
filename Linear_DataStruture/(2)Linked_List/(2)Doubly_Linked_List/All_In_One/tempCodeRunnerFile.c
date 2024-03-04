#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}myNode;

//add nodes to empty list
myNode* add_to_empty(myNode *head, int data){
    if(head == NULL){
        myNode *ptr = NULL;
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        head = ptr;
        return head;
    }else{
        printf("List is not empty\n");
    }
}

//add at end
void add_at_end(myNode *head, int data){
    myNode *ptr = NULL;
    myNode *temp = head;

    ptr = malloc(sizeof(myNode));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    
    if(head == NULL){
        printf("List is already empty there should be"
        "at least one node\n");
        return;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}


//add at beg
void add_at_beg(myNode **head, int data){
    myNode *ptr = NULL;

    ptr = malloc(sizeof(myNode));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    if(*head == NULL){
        printf("List is already empty there should be"
        "at least one node\n");
        return;
    }else{
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}



//Count no of nodes
int no_of_nodes(myNode *head){
    int count = 0;
    if(head == NULL)
        return count;
    else{
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
}



//add at any position
void add_at_any_pos(myNode **head, int data, int pos){
    myNode *ptr = NULL;
    myNode *temp = *head;

    ptr = malloc(sizeof(myNode));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    if(pos == 1){
        add_at_beg(head, data);
        return;
    }else if(pos == (no_of_nodes(*head) + 1)){
        add_at_end(*head, data);
        return;
    }else{
        while(--pos){
            temp = temp->next;
        }
        temp->prev->next = ptr;
        ptr->prev = temp->prev;
        ptr->next = temp;
        temp->prev = ptr;
    }
}


//traverse the list
void traverse_list(myNode *head){
    myNode *ptr = head;

    if(ptr = NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("Data on list is: \n");
        while(ptr != NULL){
            printf("EH");
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}




//testing
int main(){
    myNode *head = NULL;
    int yourChoice = 0;
    int pos = 0, nod = 0;

    do{
        system("CLS");
        printf("<1> Add node to an empty list\n");
        printf("<2> Add new node to the end of list\n");
        printf("<3> Add new node at the begining\n");
        printf("<4> Count number of nodes\n");
        printf("<5> Add new node at any position\n");
        printf("\n\tEnter Your Choiice:  ");
        
        scanf("%d", &yourChoice);
