#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum boolen{
    false, true
}bool;

struct Node{
    int data;
    struct Node *next;
};


//add to empty
void add_to_empty(struct Node **tail, int data){
    struct Node *ptr = NULL;

    if(*tail == NULL){
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = ptr;

        *tail = ptr;
    }else{
        printf("list is not empty\n");
    }
}


//add at beg
void add_at_beg(struct Node *tail, int data){
    struct Node *ptr = NULL;

    if(tail == NULL)
        add_to_empty(&tail, data);
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = tail->next;
        tail->next = ptr;
    }
}


//add at end
void add_at_end(struct Node **tail, int data){
    struct Node *ptr = NULL;

    if(*tail == NULL){
        printf("He");
        add_to_empty(tail, data);

    }
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = (*tail)->next;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}


//count no of nodes
int no_of_nodes(struct Node *tail){
    struct Node *temp = NULL;
    int count = 0;

    if(tail == NULL)
        return count;
    else{
        temp = tail->next;
        do{
            count++;
            temp = temp->next;
        }while(temp != tail->next);
        return count;
    }
}


//insert at any pos
void insert_at_any_pos(struct Node **tail, int data, int pos){
    struct Node *ptr = NULL;
    struct Node *temp = NULL;

    if(*tail == NULL)
        add_to_empty(tail, data);
    else if(pos == 1)
        add_at_beg(*tail, data);
    else if(pos == (no_of_nodes(*tail) + 1))
        add_at_end(tail, data);
    else{
        ptr = malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;

        temp = (*tail)->next;
        pos--;
        while(--pos){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}


//del at beg
void del_at_beg(struct Node **tail){
    struct Node *head = NULL;
    
    if(*tail == NULL)
        printf("list is empty\n");
    else if(*tail == (*tail)->next){
        printf("\nNode %d is deleted", (*tail)->data);
        free(*tail);
        *tail = NULL;
    }
    else{
        head = (*tail)->next;
        (*tail)->next = head->next;
        printf("\nNode %d is deleted ", head->data);
        free(head);
        head = NULL;
    }
}



//del at end
void del_at_end(struct Node **tail){
    struct Node *temp = NULL;

    if(*tail == NULL)
        printf("list is empty\n");
    else if(*tail == (*tail)->next)
        del_at_beg(tail);
    else{
        temp = (*tail)->next;
        do{
            temp = temp->next;
        }while(temp->next != *tail);
        temp->next = (*tail)->next;
        printf("\nNode %d is deleted", (*tail)->data);
        free(*tail);
        *tail = temp;
    }
}


//del at any pos
void del_at_any_pos(struct Node **tail, int pos){
    struct Node *temp1 = NULL;
    struct Node *temp = NULL;

    if(*tail == NULL)
        printf("list is already empty\n");
    else if(pos == 1)
        del_at_beg(tail);
    else if(pos == no_of_nodes(*tail))
        del_at_end(tail);
    else{
        temp1 = (*tail)->next;
        while(--pos){
            temp = temp1;
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        printf("\nNode %d is deleted", temp1->data);

        free(temp1);
        temp1 = NULL;
    }
}


//search an element
bool search_an_ele(struct Node *tail, int key){
    struct Node *head = NULL;

    if(tail == NULL)
        return false;
    else{
        head = tail->next;
        do{
            if(head->data == key)
                return true;
            else
                head = head->next;
        }while(head != tail->next);
        return false;
    }
}


//traverse the list
void traverse_list(struct Node *tail){
    struct Node *head = NULL;

    if(tail == NULL)
        printf("\nlist is empty\n");
    else{
        printf("\nData on list is\n");
        head = tail->next;
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
    printf("\n");
}





//int main
int main(){
    struct Node *tail = NULL;
    int yourChoice = 0, pos = 0;
    int key = 0;
    do{
        system("cls");
        printf("\t-Insertion Section-\t\n");
        printf("<1>. Add to empty\n");
        printf("<2>. Add at beg\n");
        printf("<3>. Add at end\n");
        printf("<4>. Count no of nodes\n");
        printf("<5>. Insert at any position\n");
        printf("\t-Deletion Section-\t\n");
        printf("<6>. Del from beg\n");
        printf("<7>. Del from end\n");
        printf("<8>. Del at any pos\n");
        printf("<9>. Search an element\n");
        printf("Enter Your Choice: ");
        scanf("%d", &yourChoice);

        switch (yourChoice){
        case 1:
            add_to_empty(&tail, 100);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 2:
            add_at_beg(tail, 1);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 3:
            add_at_end(&tail, 200);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 4:
            traverse_list(tail);
            printf("No Of Nodes Are: %d\n", no_of_nodes(tail));
            printf("Hit enter to continue: ");
            getch();
            break;
        case 5:
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert_at_any_pos(&tail, 4, pos);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 6:
            del_at_beg(&tail);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 7:
            del_at_end(&tail);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
            break;
        case 8:
            printf("Enter Position: ");
            scanf("%d", &pos);
            del_at_any_pos(&tail, pos);
            traverse_list(tail);
            printf("Hit enter to continue: ");
            getch();
        case 9:
            printf("Enter Key Element: ");
            scanf("%d", &key);
            if(search_an_ele(tail, key))
                printf("Key Element Found\n");
            else
                printf("Key Element Not Found\n");
            printf("Hit enter to continue: ");
            getch();
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(1);

    return 0;
}
