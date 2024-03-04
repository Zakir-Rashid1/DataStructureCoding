#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *next;
}*top = NULL;


typedef enum bool{
    false, true
}boolean;


//check weather the heap memory can be allocated or not
boolean isFull(struct node *check){
    if(check == NULL)
        return true;
    else
        return false;
}


//Check weather the stack is empty or not
boolean isEmpty(){
    if(top == NULL)
        return true;
    else
        return false;
}



//push an element into the stack
void push(int data, struct node *newNode){
    if(!isFull(newNode)){
        newNode->next = top;
        newNode->data = data;
        top = newNode;
    }else{
        printf("Stack OverFlow\n");
        exit(1);
    }
}


//pop an element from the stack
int pop(){
    struct node *temp = NULL;
    int ele = 0;
    if(!isEmpty()){
        temp = top;
        top = top->next;
        ele = temp->data;

        free(temp);
        temp = NULL;
        return ele;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//display elements inside the stack
void display(){
    struct node *head = NULL;
    if(top == NULL)
        printf("Stack is empty\n");
    else{
        head = top;
        printf("Elements inside the stack are\n");
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}




//peek element
int peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        exit(1);
    }
    else
        return top->data;
}





//Testing
int main(){
    short yourChoice = 0;
    int ele = 0;
    struct node *newNode = NULL;
    do{
        system("cls");
        printf("=========================================\n");
        printf("\t 1. Push an element\n");
        printf("\t 2. Pop an element\n");
        printf("\t 3. Peek element\n");
        printf("\t 4. Display all the elements\n");
        printf("\t 5. Is empty\n");
        printf("\t 6. Is full\n");
        printf("\t 7. Exit\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &yourChoice);
        printf("=========================================\n");

        switch(yourChoice){
            case 1:
                newNode = malloc(sizeof(struct node));
                printf("Enter An Element To Push: ");
                scanf("%d", &ele);
                push(ele, newNode);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 2:
                ele = pop();
                printf("Element %d is popped from the stack\n", ele);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 3:
                ele = peek();
                printf("Peek element is: %d \n", ele);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 4:
                display();
                printf("Hit Enter To Continue: ");
                getch();
                display();
                break;
            case 5:
                if(isEmpty())
                    printf("Stack Is Empty\n");
                else
                    printf("Stack Is Not Empty\n");
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 6:
                if(isFull(newNode))
                    printf("Stack Is Full\n");
                else
                    printf("Stack Is Not Full\n");
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 7:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }while(true);
}
