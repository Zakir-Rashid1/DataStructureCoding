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

        // wow : time complexity is O(1)
        ptr->next = tail->next;
        tail->next = ptr;

        return ptr;
    }
}


//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = head;

    if(temp == NULL){
        printf("list is already empty\n");
        return;
    }else{
        printf("Data on list is\n");