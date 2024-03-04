#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node{
    int data;
    struct Node* next;
}myNode;



//add to empty
void add_to_empty(myNode **head, int data){
    myNode *ptr = NULL;

    if(*head == NULL){
        ptr = malloc(sizeof(myNode));
        ptr->data = data;
        ptr->next = NULL;

        *head = ptr;
    }else
        printf("list is not empty\n");
}




//add at beg
void add_at_beg(myNode **head, int data){
    myNode *ptr = NULL;
    if(*head == NULL)
        add_to_empty(head, data);
    else{
        ptr = malloc(sizeof(myNode));
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = *head;
        *head = ptr;
    }
}



//add at end
void add_at_end(myNode **head, int data){
    myNode *ptr = NULL;
    myNode *temp = NULL;

    if(*head == NULL)
        add_to_empty(head, data);
    else{
        ptr = malloc(sizeof(myNode));
        ptr->data = data;
        ptr->next = NULL;

        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }
}



//count no of nodes
int no_of_nodes(myNode *head){
    myNode *temp = NULL;
    int count = 0;
    
    if(head == NULL)
        return count;
    else{
        temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
}




//add at any pos
void add_at_any_pos(myNode **head, int data, int pos){
    myNode *ptr = NULL;
    myNode *temp = NULL;

    if(*head == NULL)
        add_to_empty(head, data);
    else if(pos == 1)
        add_at_beg(head, data);
    else if(pos == (no_of_nodes(*head) + 1))
        add_at_end(head, data);
    else{
        ptr = malloc(sizeof(myNode));
        ptr->data = data;
        ptr->next = NULL;
        temp = *head;
        pos--;
        while(--pos){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}



//del first node
void del_at_beg(myNode **head){
    myNode *temp = NULL;

    if(*head == NULL)
        printf("list is empty\n");
    else{
        temp = *head;
        *head = (*head)->next;
        printf("\nNode %d is deleted \n", temp->data);
        free(temp);
        temp = NULL;
    }
}


//del last node
void del_at_end(myNode **head){
    myNode *temp = NULL;
    myNode *temp1 = NULL;

    if(*head == NULL)
        printf("Can't delete list is empty\n");
    else if((*head)->next == NULL){
        printf("\nNode %d is deleted \n", (*head)->data);
        free(*head);
        *head = NULL;
    }else{
        temp = *head;
        temp1 = *head;
        while(temp->next != NULL){
            temp1 = temp;
            temp = temp->next;
        }
        printf("\nNode %d is deleted \n", temp->data);
        free(temp);
        temp = NULL;
        temp1->next = NULL;
    }
}


//del at any pos
void del_at_any_pos(myNode **head, int pos){
    myNode *temp = NULL;
    myNode *temp1 = NULL;
    if(*head == NULL)
        printf("Can't delete list is empty\n");
    else if(pos == 1)
        del_at_beg(head);
    else if(pos == no_of_nodes(*head))
        del_at_end(head);
    else{
        temp = *head;
        temp1 = *head;
        while(--pos){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        printf("\nNode %d is deleted \n", temp->data);
        free(temp);
        temp = NULL;

    }
}





//traverse the list
void traverse_list(myNode *head){
    myNode *temp = NULL;
    if(head == NULL)
        printf("list is empty\n");
    else{
        printf("Data on list is\n");
        temp = head;
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != NULL);
    }
    printf("\n");
}


//testing
int main(){
    myNode *head = NULL;
    int nod = 0, pos = 0;
    int yourChoice = 0;

    do{
        system("cls");
        printf("  Insertion Section\n");
        printf("<1>. Add to empty\n");
        printf("<2>. Add at beg\n");
        printf("<3>. Add at end\n");
        printf("<4>. Add at any pos\n");
        printf("<5>. Count no of nodes\n");
        printf("  Deletion Section\n");
        printf("<6>. Del at beg\n");
        printf("<7>. Del at end\n");
        printf("<8>. Del at any position\n\n");

        printf("Enter Your Choice: ");
        scanf("%d", &yourChoice);

        switch (yourChoice)
        {
        case 1:
            add_to_empty(&head, 100);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 2:
            add_at_beg(&head, 12);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 3:
            add_at_end(&head, 200);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 4:
            printf("Enter Position: ");
            scanf("%d", &pos);
            add_at_any_pos(&head, 99, pos);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 5:
            traverse_list(head);
            printf("Number of nodes are: %d\n", no_of_nodes(head));
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 6:
            del_at_beg(&head);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 7:
            del_at_end(&head);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        case 8:
            printf("Enter Position: ");
            scanf("%d", &pos);
            del_at_any_pos(&head, pos);
            traverse_list(head);
            printf("Hit Enter To Continue ");
            getch();
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }


    }while(1);
}