#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef enum bool{
    false, true
}boolean;

#define SIZE 100
char infix[SIZE];
char stackArray[SIZE];
char postfix[SIZE];
int top = -1;

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
void push(char ele){
    if(!isFull())
        stackArray[++top] = ele;
    else
        printf("Stack OverFlow\n");
}



//Pop an elemnet from the stack
char pop(){
    if(!isEmpty())
        return stackArray[top--];
    else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}



//Define priority
int precedence(char cha){
    switch(cha){
        case '^':
            return 3;
            break;
        case '/':
        case '*':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '(':
            return 0;
            break;
        default:
            return -1;  
    }
}


//InToPost
void inToPos(){
    char symbol;
    char popele;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        switch (symbol){
        case '(':
            push(symbol);
            break;
        case ')':
            while((popele =pop()) != '(')
                postfix[j++] = popele;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && precedence(stackArray[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;        
        default:
            postfix[j++] = symbol;
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}


void print(){
    printf("Equivalent PostFix Expression Is: %s ", postfix);
}

//Testing
int main(){
    system("cls");
    printf("Enter Infix Expression: "); 
    gets(infix);

    inToPos();
    print();

    return 0;
}