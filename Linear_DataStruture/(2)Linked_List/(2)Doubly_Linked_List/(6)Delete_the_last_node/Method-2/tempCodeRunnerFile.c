    return head;
}


//delete last node
myNode* del_last_node(myNode *head){
    myNode *temp = head;
    if(head->next == NULL && head->prev == NULL){
        printf("\nNode %d is deleted \n", head->data);
        free(head);
        head = NULL;
        return head;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("\nNode %d is deleted \n", temp->data);
        free(temp);
        temp = NULL;
    }
    return head;
}


//traverse the list (frwd)
void traverse_list_frwd(myNode *head){
    myNode *ptr = head;
    if(head == NULL){
        printf("List is already empty\n");
        return;
    }else{
        printf("\nData on list is:\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}




//testing
int main(){
    myNode *head = NULL;
    myNode *ptr = NULL;

    //add to empty
    head = add_to_emtpy(head, 100);

    //add at end
    add_at_end(head, 200);
    add_at_end(head, 300);

    //add at beg
    head = add_at_beg(head, 2);
    head = add_at_beg(head, 1);