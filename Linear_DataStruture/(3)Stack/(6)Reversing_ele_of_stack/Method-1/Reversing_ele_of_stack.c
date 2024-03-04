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


//Check weather the stack is empty or not
boolean isEmpty(struct node *top){
    if(top == NULL)
        return true;
    else
        return false;
}


//Check weather the stack is full
boolean isFull(struct node *top){
    if(top == NULL)
        return true;
    else
        return false;
}


//Push an element into the stack
void push(struct node **top, struct node *newNode, int data){
    if(!isFull(newNode)){
        newNode->data = data;
        newNode->next = *top;

        *top = newNode;
    }else
        printf("Stack OverFlow\n");
}


//Pop an element form the stack
int pop(struct node **top){
    struct node *temp = NULL;
    int reValue = 0;
    if(!isEmpty(*top)){
        temp = *top;
        *top = (*top)->next;
        reValue = temp->data;

        free(temp);
        temp = NULL;
        return reValue;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}



//Display stack elements
void display(struct node *top){
    struct node *head = NULL;
    if(top == NULL){
        printf("Stack is empty\n");
        exit(1);
    }else{
        printf("Elements inside the stack are\n");
        head = top;
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n\n");
}




//Testing
int main(){
    struct node *top = NULL;
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    printf("Orginal Stack\n");
    push(&top, malloc(sizeof(struct node)), 100);
    push(&top, malloc(sizeof(struct node)), 200);
    push(&top, malloc(sizeof(struct node)), 300);
    push(&top, malloc(sizeof(struct node)), 400);
    push(&top, malloc(sizeof(struct node)), 500);
    display(top);
    

    printf("Temp Stack One\n");
    push(&top1, malloc(sizeof(struct node)), pop(&top));
    push(&top1, malloc(sizeof(struct node)), pop(&top));
    push(&top1, malloc(sizeof(struct node)), pop(&top));
    push(&top1, malloc(sizeof(struct node)), pop(&top));
    push(&top1, malloc(sizeof(struct node)), pop(&top));
    display(top1);


    printf("Temp Stack Two\n");
    push(&top2, malloc(sizeof(struct node)), pop(&top1));
    push(&top2, malloc(sizeof(struct node)), pop(&top1));
    push(&top2, malloc(sizeof(struct node)), pop(&top1));
    push(&top2, malloc(sizeof(struct node)), pop(&top1));
    push(&top2, malloc(sizeof(struct node)), pop(&top1));
    display(top2);

    
    printf("Orginal Stack\n");
    push(&top, malloc(sizeof(struct node)), pop(&top2));
    push(&top, malloc(sizeof(struct node)), pop(&top2));
    push(&top, malloc(sizeof(struct node)), pop(&top2));
    push(&top, malloc(sizeof(struct node)), pop(&top2));
    push(&top, malloc(sizeof(struct node)), pop(&top2));
    display(top);





    return 0;
}