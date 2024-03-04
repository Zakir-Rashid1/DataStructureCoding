#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5
int stackArray[SIZE];
int first = -1;
typedef enum bool{
    false, true
}boolean;


//Check weather the stack is empty or not
boolean isEmpty(){
    if(first == -1)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isFull(){
    if(first == (SIZE - 1))
        return true;
    else
        return false;
}


//Push function
void push(int data){
    if(!isFull()){
        for(int i = first; i >= 0; i--)
            stackArray[i + 1] = stackArray[i];
        stackArray[0] = data;
        first++;        
    }else
        printf("Stack OverFlow\n");
}


//Pop function
int pop(){
    int returnNum = 0;
    if(!isEmpty()){
        returnNum = stackArray[0];
        for(int i = 0; i < first; i++)
            stackArray[i] = stackArray[i + 1];
        first--;
        return returnNum;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


int peek(){
    if(first == -1){
        printf("Stack is Empty\n");
        exit(1);
    }else
        return stackArray[0];
}

//Display function
void display(){
    if(first == -1)
         printf("Stack is empty\n");
    else{
        printf("Elements Inside The Stack Are\n");
        for(int i = 0; i <= first; i++)
            printf("%d ", stackArray[i]);
    }
    printf("\n");
}



//Testing
int main(){
    short yourChoice = 0;
    int ele = 0, peekEle = 0;
    do{
        system("cls");
        printf("=========================================\n");
        printf("\t 1. Push an element\n");
        printf("\t 2. Pop an element\n");
        printf("\t 3. Display all the elements\n");
        printf("\t 4. Peek Element\n");
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
                printf("Element %d is popped out from the stack\n", ele);
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 3:
                display();
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 4:
                peekEle = peek();
                printf("Peek Element is %d \n", peekEle);
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