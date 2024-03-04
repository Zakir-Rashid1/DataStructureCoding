}


//del first node
struct Node* del_first_node(struct Node *tail){
    struct Node *head = NULL;

    if(tail == NULL){
        printf("list is empty");
        return tail;
    }else if(tail == tail->next){
        printf("Node %d is deleted\n\n", tail->data);
        free(tail);
        tail = NULL;
        return tail;
    }else{
        head = tail->next;
        tail->next = head->next;
        head->next->prev = tail;

        printf("Node %d is deleted\n\n", head->data);
        free(head);
        head = NULL;

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
        printf("list on data is\n");
        head = tail->next;
        
        do{
            printf("%d\t", head->data);
            head = head->next;
        }while(head != tail->next);
    }
    printf("\n");
}



//testing