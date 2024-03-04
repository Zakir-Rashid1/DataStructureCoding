        ptr->next = tail->next;
        tail->next = ptr;

        return tail;
    }
}


// add at end
struct Node* add_at_end(struct Node *tail, int data){
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

        tail = ptr;
        return tail;
    }
}


//del first node
struct Node* del_first_node(struct Node *tail){
    struct Node *temp = NULL;

    if(tail == NULL){
        printf("list is empty\n");
        return tail;
    }else if(tail->next == tail){
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




//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = NULL;
    printf("%d", head);

    if(head == NULL){
        printf("list is already emtpy\n");
        return;
    }else{
        temp = head->next;
        printf("\nData on list is\n");
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
    printf("\n");
}



//testing
int main(){
    struct Node *tail = NULL;
    int nod = 0;

    //add to empty