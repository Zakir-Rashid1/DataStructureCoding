void add_at_end(struct Node *head, struct Node *last){
    struct Node *ptr = head;

    if(ptr == NULL){
        printf("List is already empty\n");
        return;
    }else{
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = last;
    }
}


//Add new node at beg
void add_new_at_beg(struct Node **head, struct Node *first){
    struct Node *ptr = *head;

    first->link = *head;
    *head = first;
}


//Count number of nodes
int count_no_of_nodes(struct Node *head){
    struct Node *ptr = head;
    int count = 0;
    
    if(ptr == NULL){
        return count;
    }else{
        while(ptr != NULL){
            count++;
            ptr = ptr->link;
        }
        return count;
    }
}


//Add new node at any pos
void add_at_pos(struct Node **head, struct Node *new, int pos){
    struct Node *ptr = *head;
    
    if(pos == 1){
        add_new_at_beg(head, new);
        return;
    }else{
        pos--;
        while(--pos){
            ptr = ptr->link;
        }
        new->link = ptr->link;
        ptr->link = new;
    }
}


/************************************** Deletion *****************************************/

//Delete first node
void del_first_node(struct Node **head){
    struct Node *ptr = *head;

    if(ptr == NULL){
        printf("List is already empty\n");
        return;
    }else{
        *head = (*head)->link;
        free(ptr);
    }
}

//Delete last node
void del_last_node(struct Node *head){
    struct Node *temp1 = head;
    struct Node *temp2 = head;

    if(head == NULL){
        printf("List is already empty\n");
        return;
    }else if(head->link == NULL){
        free(head);