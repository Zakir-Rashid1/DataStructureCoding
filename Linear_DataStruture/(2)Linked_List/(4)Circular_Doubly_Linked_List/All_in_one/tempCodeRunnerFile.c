
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
        temp = (*tail)->next;
        temp->prev = (*tail)->prev;
        (*tail)->prev->next = temp;
        printf("\nNode %d is deleted\n", (*tail)->data);
        free(*tail);
        *tail = (*tail)->prev;
    }
}





//testing
int main(){
    struct Node *tail = NULL;
    int yourChoice = 0, pos = 0;
