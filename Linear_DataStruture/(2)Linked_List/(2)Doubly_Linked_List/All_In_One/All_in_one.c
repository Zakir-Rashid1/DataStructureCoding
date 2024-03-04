
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
        return head;
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
        printf("List is empty there should be"
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
        printf("List is  empty there should be"
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
    }else if(pos >= (no_of_nodes(*head) + 1)){
        printf("\nInvalid Position\n");
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

    if(ptr == NULL){
        printf("\nList is already empty\n");
        return;
    }else{
        printf("Data on list is \n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}



//del first Node
void del_first_node(myNode **head){
    myNode *ptr = *head;

    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }else if(ptr->next == NULL && ptr->prev == NULL){
        free(*head);
        *head = NULL;
    }else{
        *head = (*head)->next;
        (*head)->prev = NULL;

        free(ptr);
        ptr = NULL;
    }
}



//del the last node
void del_last_node(myNode **head){
    myNode *ptr = *head;

    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }else if(ptr->prev == NULL && ptr->next == NULL){
        del_first_node(head);
        return;
    }else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
}


//del at any position
void del_at_any_pos(myNode **head, int pos){
    myNode *ptr = *head;

    if(pos == 1){
        del_first_node(head);
        return;
    }else if(pos == no_of_nodes(*head)){
        del_last_node(head);
        return;
    }else{
        while(--pos){
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        ptr = NULL;
    }
}



//reverse the list
void reverse_list(myNode **head){
    myNode *ptr = NULL;
    myNode *temp = *head;

    if(temp == NULL){
        printf("List is already empty nothing to reverse\n");
        return;
    }else{
        while(temp->next != NULL){
            ptr = temp->next;
            temp->next = temp->prev;
            temp->prev = ptr;

            temp = temp->prev;
        }
        temp->next = temp->prev;
        temp->prev = NULL;
        *head = temp;
        temp = ptr = NULL;
    }

}


//testing
int main(){
    myNode *head = NULL;
    int yourChoice = 0;
    int pos = 0, nod = 0;

    do{
        system("CLS");
        printf("\t<Insertion Section>\n");
        printf("<1> Add node to an empty list\n");
        printf("<2> Add new node to the end of list\n");
        printf("<3> Add new node at the begining\n");
        printf("<4> Count number of nodes\n");
        printf("<5> Add new node at any position\n");
        printf("\t<Deletion Section>\n");
        printf("<6> Delete last node\n");
        printf("<7> Delete first node\n");
        printf("<8> Delete node at any position\n");
        printf("<9> Reverse the list\n");
        printf("<10> Exit\n");
        printf("\n\tEnter Your Choice:  ");
        scanf("%d", &yourChoice);

        switch(yourChoice){
            case 1:
                head = add_to_empty(head, 100);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 2:
                add_at_end(head, 200);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 3:
                add_at_beg(&head, 1);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 4:
                nod = no_of_nodes(head);
                printf("\nNo Of Nodes Are: %d \n",nod);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 5:
                printf("Enter Position: ");
                scanf("%d", &pos);
                add_at_any_pos(&head, 500, pos);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 6:
                del_last_node(&head);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 7:
                del_first_node(&head);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 8:
                printf("Enter Position: ");
                scanf("%d", &pos);
                del_at_any_pos(&head, pos);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
                break;
            case 9:
                printf("Data Before Reverse\n");
                traverse_list(head);
                printf("\nData After Reverse\n");
                reverse_list(&head);
                traverse_list(head);
                printf("\n\tHit Enter To Continue ");
                getch();
            case 10:
                exit(1);
            default:
                printf("Invalid Choice");
            }

        }while(1);



    return 0;
}
