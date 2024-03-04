#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5
int top = -1; 
int stackArray[SIZE];

typedef enum bool{
    false, true
}boolean;

//Check weather the stack is empty or not
boolean isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isFull(){
    if(top == (SIZE - 1))
        return true;
    else
        return false;
}


//Push function
void push(int data){
    if(!isFull())
        stackArray[++top] = data;
    else
        printf("Stack Overflow\n");
}

//Pop function
int pop(){
    if(!isEmpty())
        return stackArray[top--];
    else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//Peek element
int peek(){
    if(top == -1){
        printf("Stack is Empty\n");
        exit(1);
    }else
        return stackArray[top];
}


//Display Method
void display(){
    if(top == -1)
        printf("Stack is empty\n");
    else{
        printf("Elements Inside The Stack Are\n");

        for(int i = 0; i <= top; i++)
            printf("%d ", stackArray[i]);
    }
    printf("\n");
}



//Testing
int main(){
    short yourChoice = 0;
    int ele = 0;
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
                printf("Enter An Element To Push: ");
                scanf("%d", &ele);
                push(ele);
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
            case 4:
                display();
                printf("Hit Enter To Continue: ");
                getch();
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
                if(isFull())
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