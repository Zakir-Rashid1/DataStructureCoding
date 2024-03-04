#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//add to empty
void add_to_empty(struct Node **tail, int data){
    struct Node *ptr = NULL;
    if(*tail == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->prev = ptr;
        ptr->data = data;
        ptr->next = ptr;

        *tail = ptr;
    }else
        printf("list is not empty\n");
}


//add at beg
void add_at_beg(struct Node **tail, int data){
    struct Node *ptr = NULL;
    if(*tail == NULL)
        add_to_empty(tail, data);
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = (*tail)->next;
        (*tail)->next->prev = ptr;
        ptr->prev = *tail;
        (*tail)->next = ptr;
    }
}

//add at end
void add_at_end(struct Node **tail, int data){
    struct Node *ptr = NULL;
    if(*tail == NULL)
        add_to_empty(tail, data);
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = (*tail)->next;
        ptr->prev = *tail;
        (*tail)->next = ptr;

        *tail = ptr;
    }
}


//count no of nodes
int no_of_nodes(struct Node *tail){
    struct Node *head = NULL;
    int count = 0;
    if(tail == NULL)
        return count;
    else{
        head = tail->next;
        do{
            count++;
            head = head->next;
        }while(head != tail->next);
        return count;
    }
}


//add at any position
void add_at_any_pos(struct Node **tail, int data,int pos){
    struct Node *ptr = NULL;
    struct Node *temp = NULL;
    
    if(pos == 1)
        add_at_beg(tail, data);
    else if(pos == (no_of_nodes(*tail) + 1))
        add_at_end(tail, data);
    else{
        temp = (*tail)->next;
        ptr = malloc(sizeof(struct Node));
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = NULL;
        while(--pos){
            temp = temp->next;
        }
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
        ptr->next = temp;
        temp->prev = ptr;
    }
}



//del at beg
void del_at_beg(struct Node **tail){
    struct Node *temp = NULL;

    if(*tail == NULL)
        printf("Can't delete becoz list is empty\n");
    else if(*tail == (*tail)->next){
        printf("\nNode %d is deleted\n", (*tail)->data);
        free(*tail);
        *tail = NULL;
    }else{
        temp = (*tail)->next;
        (*tail)->next = temp->next;
        temp->next->prev = *tail;
        printf("\nNode %d is deleted\n", temp->data);
        free(temp);
        temp = NULL;
    }
}


//del at end
void del_at_end(struct Node **tail){
    struct Node *temp = NULL;

    if(*tail == NULL)
        printf("list is already empty\n");
    else if(*tail == (*tail)->next)
        del_at_beg(tail);
    else{
        temp = *tail;
        (*tail)->next->prev = temp->prev;
        (*tail)->prev->next = temp->next;
        printf("\nNode %d is deleted\n", temp->data);
        *tail = (*tail)->prev;
        free(temp);
        temp = NULL;
    }
}



//traverse list
void traverse_list(struct Node *tail){
    struct Node *head = NULL;
    if(tail == NULL)
        printf("list is already empty\n");
    else{
        printf("\ndata on list is\n");
        head = tail->next;
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
    printf("\n");
}




//del at any pos
void del_at_any_pos(struct Node **tail, int pos){
    struct Node *temp = NULL;
    if(*tail == NULL)
        printf("list is already empty\n");
    else if(pos == 1)
        del_at_beg(tail);
    else if(pos == (no_of_nodes(*tail)))
        del_at_end(tail);
    else{
        temp = (*tail)->next;
        while(--pos){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("\nNode %d is deleted\n", temp->data);
        free(temp);
        temp = NULL;
    }
}


//testing
int main(){
    struct Node *tail = NULL;
    int yourChoice = 0, pos = 0;

    do{
        system("cls");
        printf(" Insertion Section\n");
        printf("<1>. Add to empty\n");
        printf("<2>. Add at beg\n");
        printf("<3>. Add at end\n");
        printf("<4>. Add at any position\n");
        printf("<5>. Count no of nodes\n");
        printf(" Deletion Section\n");
        printf("<6>. Del at beg\n");
        printf("<7>. Del at end\n");
        printf("<8>. Del at any position\n");
        printf("Enter Your Choice: ");
        scanf("%d", &yourChoice);

        switch (yourChoice)
        {
        case 1:
            add_to_empty(&tail, 100);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 2:
            add_at_beg(&tail, 21);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 3:
            add_at_end(&tail, 200);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 4:
            printf("Enter Position: ");
            scanf("%d", &pos);
            add_at_any_pos(&tail, 99, pos);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 5:
            printf("\nNo Of Nodes Are: %d\n", no_of_nodes(tail));
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 6:
            del_at_beg(&tail);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 7:
            del_at_end(&tail);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        case 8:
            printf("Enter Position: ");
            scanf("%d", &pos);
            del_at_any_pos(&tail, pos);
            traverse_list(tail);
            printf("Hit Enter To Continue: ");
            getch();
            break;
        default:
            printf("Invalid Position");
            break;
        }
    }while(1);

    return 0;
}