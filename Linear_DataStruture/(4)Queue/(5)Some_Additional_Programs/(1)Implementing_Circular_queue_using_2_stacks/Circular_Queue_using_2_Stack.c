
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 5
int stack2[MAXSIZE];
int stack1[MAXSIZE];
int top2 = -1;
int top1 = -1;

typedef enum bool{
    false, true
}boolean;



//Check Whether The Stack is empty or not
boolean isEmpty(){
    if(top1 == -1 && top2 == -1)
        return true;
    else
        return false;
}


//Check Whether the stack is full or not
boolean isFull(){
    if(top1 == MAXSIZE - 1 && top2 == -1)
        return true;
    else if(top2 == MAXSIZE - 1 && top1 == -1)
        return true;
    else if(top1 + top2 + 2 >= MAXSIZE)
        return true;
    else
        return false;
}


//Push Operation
void push(int data){
    if(!isFull()){
        if(top2 != -1)
            stack1[MAXSIZE - top2 - 1];
        else
            stack1[MAXSIZE];
        stack1[++top1] = data;
    }else{
        printf("\tQueue Is Full\n");
        exit(1);
    }
}

//enQueue Fucntion
void enQueue(int data){
    push(data);
}


//Pop Operation
int pop(){
    if(!isEmpty()){
        if(top2 == -1){
            while(top1 != -1){
                stack2[++top2] = stack1[top1];
                top1--;
            }
            return stack2[top2--];
        }else{
            return stack2[top2--];
        }
    }else{
        printf("\tQueue is empty\n");
        exit(1);
    }
}


//DeQueue Function
int deQueue(){
    return pop();
}



//Display
void display(){
    if(!isEmpty()){
        printf("Queue Elements Are\n");
        if(top2 == -1){
            for(int i = 0; i <= top1; i++)
                printf("%d ", stack1[i]);
        }else{
            for(int i = top2; i >= 0; i--)
                printf("%d ", stack2[i]);
            for(int i = 0; i <= top1; i++)
                printf("%d ", stack1[i]);
        }
    }else{
        printf("\tQueue Is Empty\n");
        exit(1);
    }
    printf("\n");
}


//Return Peek
int peek(){
    if(!isEmpty()){
        if(top2 == -1)
            return stack1[0];
        else
            return stack2[top2];
    }
    else{
        printf("\tQueue Is Empty\n");
        exit(1);
    }
}



//Testing
int main(){
    system("CLS");
    int choice, data;
    do{
        system("CLS");
        printf("\t==============================\n");
        printf("\t<1>. Insert An Element\n");
        printf("\t<2>. Delete An Element\n");
        printf("\t<3>. Return Peek\n");
        printf("\t<4>. Check isFull\n");
        printf("\t<5>. Check isEmpty\n");
        printf("\t<6>. Display\n");
        printf("\t<7>. Exit\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);
        printf("\t==============================\n");

        switch(choice){
            case 1:
                printf("\tEnter Data Element: ");
                scanf("%d", &data);
                enQueue(data);
                printf("\t%d Added Sucessfully\n", data);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 2:
                printf("\t%d is deleted Sucessfully \n", deQueue());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                printf("\tPeek element is %d \n", peek());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                if(isFull())
                    printf("\tQueue Is Full\n");
                else
                    printf("\tQueue Is Not Full\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                if(isEmpty())
                    printf("\tQueue Is Empty\n");
                else
                    printf("\tQueue is Not Empty\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 6:
                display();
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 7:
                exit(1);
            default:
                printf("\tInvalid Choice\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
        }
    }while(true);

    return 0;
}


