#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 5
int queue[MAXSIZE];
int stack[MAXSIZE];
int front = -1;
int rear = -1;
int top = -1;

typedef enum bool{
    false, true
}boolean;



//Check Whether the stack is full or not
boolean isStackFull(){
    if(top == MAXSIZE - 1)
        return true;
    else
        return false;
}

//Check Whether the stack is empty or not
boolean isStackEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}


//Push Operation
void push(int data){
    if(!isStackFull())
        stack[++top] = data;
    else{
        printf("\tStack Is Full\n");
        exit(1);
    }
}



//Pop Operation
int pop(){
    if(!isStackEmpty())
        return stack[top--];
    else{
        printf("\tStack Is Empty\n");
        exit(1);
    }
}


//Display Function
void display(){
    if(!isStackEmpty()){
        printf("\tStack Elements Are\n");
        for(int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }else{
        printf("\tStack Is Empty\n");
        exit(1);
    }
    printf("\n");
}



//Check Whether the Queue is full or not
boolean isFull(){
    if(rear == MAXSIZE -1 && front == 0)
        return true;
    else
        return false;
}


//Check Whether the Queue is empty or not
boolean isEmpty(){
    if(front == -1)
        return true;
    else if(front == rear + 1)
        return true;
    else
        return false;
}


//EnQueue Function
void enQueue(int data){
    if(!isFull()){
        if(rear == -1)
            front = 0;
        queue[++rear] = data;
    }else{
        printf("\tQueue OverFlow\n");
        exit(1);
    }
}


//DeQueue Function
int deQueue(){
    if(!isEmpty())
        return queue[front++];
    else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}



//Reverse
void reverse(){
    if(!isStackEmpty()){
        while(!isStackEmpty())
            enQueue(pop());
        while(!isEmpty())
            stack[++top] = deQueue();
    }else{
        printf("\tStack Is Empty\n");
        exit(1);
    }
}





//Testing
int main(){
    short yourChoice = 0;
    int ele = 0;
    do{
        system("cls");
        printf("=========================================\n");
        printf("\t 1. Push An Element\n");
        printf("\t 2. Pop An Element\n");
        printf("\t 3. Reverse Element\n");
        printf("\t 4. Display All The Elements\n");
        printf("\t 5. IsEmpty\n");
        printf("\t 6. IsFull\n");
        printf("\t 7. Exit\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &yourChoice);
        printf("=========================================\n");

        switch(yourChoice){
            case 1:
                printf("\tEnter Your Element: ");
                scanf("%d", &ele);
                push(ele);
                printf("\tElement %d is Pushed Sucessfully \n", ele);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 2:
                ele = pop();
                printf("\tPopped Element Is %d\n", ele);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                reverse();
                printf("\tStack Elements Are Reversed Sucessfully\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                display();
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                if(isStackEmpty())
                    printf("Stack Is Empty\n");
                else
                    printf("Stack Is Not Empty\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 6:
                if(isStackFull())
                    printf("Stack Is Full\n");
                else
                    printf("Stack Is Not Full\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 7:
                exit(1);
            default:
                printf("\t\tInvalid Choice\n");

        }

    }while(true);
}