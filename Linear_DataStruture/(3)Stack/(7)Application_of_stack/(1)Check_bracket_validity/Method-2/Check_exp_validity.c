#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
int top = -1;
char stackArray[SIZE];

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


//Push an element into the stack
void push(int cha){
    if(!isFull())
        stackArray[++top] = cha;
    else
        printf("Stack OverFlow\n");
}


//Pop an element from the stack
int pop(){
    if(!isEmpty())
        return stackArray[top--];
    else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//Check pair
boolean checkMatch(char a, char b){
    if(a == '(' && b == ')')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else
        return false;
}



//Check the validity of an expression
boolean check_validity(char exp[]){
    
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp [i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty())
                return false;
            else{
                if(checkMatch(pop(), exp[i]))
                    continue;
                else
                    return false;
            }
        }
    }
    if(isEmpty())
        return true;
    else
        return false;
}




//Display stack elements
void display(){
    if(top == -1)
        printf("Stack is empty\n");
    else{
        printf("Elements inside the stack are\n");
        for(int i = 0; i <= top; i++)
            printf("%c ", stackArray[i]);
    }
    printf("\n");
}


//testing
int main(){
    char exp[100];
    short yourChoice = 0;

    do{
        system("cls");
        printf("\t================================\n");
        printf("\t1. Enter an expression\n");
        printf("\t2. Display stack elements\n");
        printf("\t3. Exit\n");
        printf("\t\tEnter Your Choice: ");
        scanf("%d", &yourChoice);
        printf("\t================================\n");

        switch(yourChoice){
            case 1:
                printf("Enter your expression: ");
                fflush(stdin);
                gets(exp);

                if(check_validity(exp))
                    printf("Brackets are well blanced\n"
                        "\tExpression is valid\n");
                else
                    printf("Brackets are not well blanced\n"
                        "\tExpression is invalid\n");
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 2:
                display();
                printf("Hit Enter To Continue: ");
                getch();
                break;
            case 3:
                exit(1);
            default:
                printf("Invalid Choice\n");
                printf("Hit Enter To Continue: ");
                getch();
        }
    }while(true);

    return 0;
}