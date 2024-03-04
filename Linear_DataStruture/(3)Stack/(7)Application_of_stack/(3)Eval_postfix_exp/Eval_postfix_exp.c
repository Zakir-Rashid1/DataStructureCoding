#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef enum bool{
    false, true
}boolean;

struct node{
    int data;
    struct node *next;
}*top= NULL;

#define SIZE 100
char postfix[SIZE];
char infix[SIZE];


//Check weather the stack is empty or not
boolean isFull(struct node *newNode){
    if(newNode == NULL)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isEmpty(){
    if(top == NULL)
        return true;
    else
        return false;
}


//Push an element into the stack
void push(char data){
    struct node *newNode = malloc(sizeof(struct node));
    if(!isFull(newNode)){
        newNode->data = data;
        newNode->next = top;

        top = newNode;
    }else
        printf("Stack OverFlow\n");
}


//Pop an element from the stack
char pop(){
    char rvalue;
    struct node *temp = NULL;
    if(!isEmpty()){
        temp = top;
        rvalue = temp->data;
        top = top->next;
        free(temp);

        temp = NULL;
        return rvalue;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}

//Assing precedence
int precedence(char ch){
    switch(ch){
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}


//InToPos
void inToPos(){
    char symbol;
    char rvalue;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        switch (symbol) {
        case '(':
            push(symbol);
            break;
        case ')':
            while((rvalue = pop()) != '(')
                postfix[j++] = rvalue;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && precedence(top->data) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}



//Evalvate PostFix Expression
int eval_postfix(){
    int symbol;
    int a, b;
    for(int i = 0; i < strlen(postfix); i++){
        symbol = postfix[i];
        if(symbol >= '0' && symbol <= '9')
            push(symbol - '0');
        else{
            a = pop();
            b = pop();
            switch (symbol){
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '/':
                push(b / a);
                break;
            case '*':
                push(b * a);
                break;
            case '^':
                pow(b, a);
                break;
            }
        }
    }
    return pop();
}

//Testing

int main(){
    printf("Enter Your Infix Exp: ");
    gets(infix);

    inToPos();
    printf("Equivalent Post Fix Expression is: %s\n", postfix);
    printf("Result: %d ",eval_postfix());

    return 0;
}