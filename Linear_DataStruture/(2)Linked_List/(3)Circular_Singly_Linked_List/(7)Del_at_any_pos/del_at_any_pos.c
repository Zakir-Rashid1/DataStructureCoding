#include <stdio.h>
#include <stdlib.h>

struct Node {
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



//count no of nodes
int no_of_nodes(struct Node *tail){
    int count = 0;
    struct Node *head = NULL;
    if(tail == NULL)
        printf("List is empty\n");
    else{
        head = tail->next;
        do{
            head = head->next;
            count++;
        }while(head != tail->next);
        return count;
    }
}


//del first node
struct Node* del_first_node(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("List is empty\n");
        return tail;
    }else if(tail == tail->next){
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


//del last node
struct Node* del_last_node(struct Node *tail){
    struct Node *temp = NULL;
    struct Node *ptr = NULL;

    if(tail == NULL){
        printf("List is empty\n");
        return tail;
    }else if(tail == tail->next){
        printf("Node %d is deleted\n", tail->data);
        free(tail);
        tail = NULL;
        return tail;
    }else{
        temp = tail->next;
        do{
            ptr = temp;
            temp = temp->next;
        }while(temp->next != tail->next);
        ptr->next = temp->next;
        printf("Node %d is deleted\n", temp->data);
        free(temp);
        temp = NULL;

        tail = ptr;
        return tail;
    }
}



//del at any pos
struct Node* del_at_any_pos(struct Node *tail, int pos){
    struct Node *temp = NULL;
    struct Node *ptr = NULL;

    if(tail == NULL){
        printf("list is already empty\n");
        return tail;
    }else if(pos == 1){
        tail = del_first_node(tail);
        return tail;
    }else if(pos == (no_of_nodes(tail))){
        tail = del_last_node(tail);
        return tail;
    }else{
        temp = tail->next;
        while(--pos){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
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
        printf("\n");
    }
}








//testing
int main(){
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

    //del first node
    tail = del_first_node(tail);
    traverse_list(tail);

    //del last node
    tail = del_last_node(tail);
    traverse_list(tail);


    //del node at some pos
    tail = del_at_any_pos(tail, 2);
    tail = del_at_any_pos(tail, 1);
    traverse_list(tail);


    return 0;
}





