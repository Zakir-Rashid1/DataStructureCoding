#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} myNode;


//add to empty
myNode* add_to_empty(myNode *head, int data){
    myNode *ptr = NULL;

    ptr = malloc(sizeof(myNode));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    head = ptr;
    return head;
}


// add at end
myNode* add_at_end(myNode *head, int data){
    myNode *ptr = NULL;

    ptr = malloc(sizeof(myNode));
    ptr->prev = head;
    ptr->data = data;
    head->next = ptr;
    ptr->next = NULL;

    head = ptr;
    return head;
}


// add at beg
void add_at_beg(myNode **head, int data){
    myNode *ptr = NULL;

    ptr = malloc(sizeof(myNode));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = *head;
    (*head)->prev = ptr;

    *head = ptr;
}


//count no of nodes
int no_of_nodes(myNode *head){
    myNode *ptr = head;
    int count = 0;

    if(ptr == NULL)
        return count;
    else{
        while(ptr != NULL){
            count++;
            ptr= ptr->next;
        }
        return count;
    }
}


//insert at any position except last
myNode* add_at_any_pos(myNode *head, int data, int pos){
    myNode *ptr = NULL;
    myNode *temp = head;

    if(pos == 1)
        add_at_beg(&head, data);
    else if(pos == (no_of_nodes(head) + 1))
        printf("Invalid Position\n");
    else{
        ptr = malloc(sizeof(myNode));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;
         
        pos--;
        // change temp if pos > 2 else below
        while(--pos){
            temp = temp->next;
        }
        temp->next->prev = ptr;
        ptr->next = temp->next;

        temp->next = ptr;
        ptr->prev = temp;
    }
    return head;
}


//traverse the list (frwd)
void traverse_list_frwd(myNode *head){
    myNode *ptr = head;
    if(head == NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("Data inside the list is: \n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}





int main(){
    myNode *head = NULL;
    myNode *ptr = NULL;

    //add at empty
    head = add_to_empty(head, 100);
    ptr = head;

    //add at end
    ptr = add_at_end(ptr, 200);
    ptr = add_at_end(ptr, 300);

    //add at beg
    add_at_beg(&head, 5);
    traverse_list_frwd(head);

    //count no of nodes
    int nod = no_of_nodes(head);

    //insert at any pos
    head = add_at_any_pos(head, 150, 4);
    traverse_list_frwd(head);
    head = add_at_any_pos(head, 10, 3);
    traverse_list_frwd(head);


    return 0;
}
