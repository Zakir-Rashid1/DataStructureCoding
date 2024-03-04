#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool{
    false, true
}boolean;

struct node {
    char data;
    struct node *next;
}*top = NULL;


//Check weather the stack is empty or not
boolean isEmpty(){
    if(top == NULL)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isFull(struct node *newNode){
    if(newNode == NULL)
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
    }else{
        printf("Stack OverFlow\n");
        exit(1);
    }
}


//Pop an element from the stack
int pop(){
    struct node *temp = NULL;
    int rvalue = 0;
    if(!isEmpty(top)){
        temp = top;
        top = top->next;
        rvalue = temp->data;

        free(temp);
        temp = NULL;
        return rvalue;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//Display stack elements
void display(){
    struct node *temp = NULL;
    if(top == NULL){
        printf("Stack is empty\n");
        exit(1);
    }else{
        printf("Data inside the stack is\n");
        temp = top;
        do{
            printf("%c ", temp->data);
            temp = temp->next;
        }while(temp != NULL);
    }
    printf("\n");
}



//Check matching pari
boolean checkMatchingPair(char a, char b){
    if(a == '(' && b == ')')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else
        return false;
}


//Check Validity of a function
boolean check_validty(char exp[]){
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')'){
           if(isEmpty())
               return false;
           else
               if(!checkMatchingPair(pop(), exp[i]))
                    return false;
       } 
    }
    if(isEmpty())
        return true;
    else
        return false;
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
            
                if(check_validty(exp))
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