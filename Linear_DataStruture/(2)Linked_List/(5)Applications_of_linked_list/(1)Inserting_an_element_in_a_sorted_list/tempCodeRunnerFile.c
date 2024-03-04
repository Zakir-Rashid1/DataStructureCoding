
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        return head;
    }
}

//data must be in increasing order
//find your pos
struct Node* find_your_pos(struct Node *head, int key){
    struct Node *ptr = NULL;
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;

    ptr = malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->next = NULL;

    if(head == NULL || key < head->data)
        ptr->next = head;
    else{
        temp1 = head;
        while(temp1 != NULL){
            if(key > temp1->data)
                temp2 = temp1;
            temp1 = temp1->next;
        }
        ptr->next = temp2->next;
        temp2->next = ptr;
        return head;
    }
}





//traverse list
void traverse_list(struct Node *head){
    struct Node *temp = NULL;

    if(head == NULL){
        printf("list is already empty\n");
        return;
    }else{
        printf("Data on list is\n");
        temp = head;
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


//testing
int main(){
    struct Node *head = NULL;

    //add to empty
    head = add_to_empty(head, 5);