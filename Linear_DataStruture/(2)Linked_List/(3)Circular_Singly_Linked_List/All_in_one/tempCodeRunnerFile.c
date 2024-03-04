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
        printf("Enter Your Choice: ");
        scanf("%d", &yourChoice);

        switch (yourChoice)
        {
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