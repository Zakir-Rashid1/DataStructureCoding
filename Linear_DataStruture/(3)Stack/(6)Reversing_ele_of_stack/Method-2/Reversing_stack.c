#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum bool{
    false, true
}boolean;


struct node{
    int data;
    struct node *next;
};


//Check weather the stack is empty
boolean isEmpty(struct node *top){
    if(top = NULL)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isFull(struct node *top){
    if(top == NULL)
        return true;
    else
        return false;
}


//Push an element into the stack
void push(struct node **top, int data){
    struct node *newNode = malloc(sizeof(struct node));
    if(!isFull(newNode)){
        newNode->data = data;
        newNode->next = NULL;

        newNode->next = *top;
        *top = newNode;
    }else{
        printf("Stack OverFlow\n");
        exit(1);
    }
}


//Pop an element into the stack
int pop(struct node **top){
    struct node *temp = NULL;
    int rvalue = 0;
    if(!isEmpty(*top)){
        temp = *top;
        rvalue = temp->data;
        *top = (*top)->next;
        free(temp);

        temp = NULL;
        return rvalue;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}



//Display stack elements
void display(struct node *top){
    struct node *head = NULL;

    if(top == NULL)
        printf("Stack is empty\n");
    else{
        printf("Data on stack is\n");
        head = top;
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}



//Reverse the stack
void reverseStackElements(struct node **top){
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    if(*top == NULL){
        printf("Stack is empty\n");
        exit(1);
    }else{
        while(*top != NULL){
            push(&top1, pop(top));
        }
        while(top1 != NULL){
            push(&top2, pop(&top1));
        }
        while(top2 != NULL){
            push(top, pop(&top2));
        }
        printf("Stack Reversed Successfully!\n");
    }
}



//Testing
int main(){
    struct node *top = NULL;
    int yourChoice = 0, data = 0;
    int ele = 0;
    do{
        system("cls");
        printf("\t============================\n");
        printf("\t<1>. Push an element\n");
        printf("\t<2>. Pop An Element\n");
        printf("\t<3>. Reverse Stack\n");
        printf("\t<4>. Display\n");
        printf("\t<5>. Exit\n");
        printf("\t\tEnter Your Choice: ");
        scanf("%d", &yourChoice);
        printf("\t============================\n");

        switch(yourChoice){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &ele);
                push(&top, ele);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 2:
                printf("Popped element is %d \n", pop(&top));
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 3:
                reverseStackElements(&top);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 4:
                display(top);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }while(true);

    return 0;
}
