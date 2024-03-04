#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define SIZE 100
int first = -1;
int stackArray[SIZE];

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


//push an element
void push(int data){
    if(!isFull()){
        for(int i = first; i >= 0; i--)
            stackArray[i + 1] = stackArray[i];
        stackArray[0] = data;
        first++;
    }else
        printf("Stack OverFlow\n");
}


//pop an element
int pop(){
    int value = 0;
    if(!isEmpty()){
        value = stackArray[0];
        for(int i = 0; i < first; i++)
            stackArray[i] = stackArray[i + 1];
        first--;
        return value;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//display data
void display(){
    if(first == -1)
        printf("Stack is empty\n");
    else{
        printf("Data inside the stack is\n");
        for(int i = 0; i <= first; i++)
            printf("%d ", stackArray[i]);
    }
    printf("\n");
}


//Binary equivalent
void binaryEquivalent(int num){
    int rem = 0;
    for(int i = 2; num > 0; ){
        if(num % 2 == 0 || num % 2 == 1){
            rem = num % 2;
            push(rem);
            num = num / 2;
        }
    }
}





//Testing
int main(){
    short yourChoice = 0;
    int ele = 0, peekEle = 0;
    do{
        system("cls");
        printf("=========================================\n");
        printf("\t 1. Enter An Element\n");
        printf("\t 2. Pop an element\n");
        printf("\t 3. Display all the elements\n");
        printf("\t 4. Is empty\n");
        printf("\t 5. Is full\n");
        printf("\t 6. Exit\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &yourChoice);
        printf("=========================================\n");

        switch(yourChoice){
            case 1:
                printf("Enter An Element: ");
                scanf("%d", &ele);
                binaryEquivalent(ele);
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
                if(isEmpty())
                    printf("Stack Is Empty\n");
                else
                    printf("Stack Is Not Empty\n");
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 5:
                if(isFull())
                    printf("Stack Is Full\n");
                else
                    printf("Stack Is Not Full\n");
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid Choice\n");
                printf("Hit Enter To Continue: ");
                getch();
        }

    }while(true);
}
