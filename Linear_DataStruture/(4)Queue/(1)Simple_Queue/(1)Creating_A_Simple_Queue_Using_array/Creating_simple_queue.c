#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1;
int rear = -1;

typedef enum bool{
    false, true
}boolean;


//Check Whether the queue is empty of not
boolean isEmpty(){
    if(front == rear + 1 || front == -1)
        return true;
    else
        return false;
}


//Check Whether the queue is full or not
boolean isFull(){
    if(rear == MAXSIZE -1)
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



//Return Peek
int peek(){
    if(!isEmpty())
        return queue[front];
    else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}


//Return Number Of Elemnets Present In The Queue
int numberOfElements(){
    if(!isEmpty())
        return (rear - front + 1);
    else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}

//Dipslay Queue Elements
void display(){
    if(isEmpty()){
        printf("\tQueue UnderFlow\n");
        exit(1);
    }else{
        printf("Elements Inside Queue Are\n");
        for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
        printf("\n");
    }
}


//Testing
int main(){
    system("CLS");
    int choice, data;
    do{
        system("CLS");
        printf("\t==============================\n");
        printf("\t<1>. EnQueue An Element\n");
        printf("\t<2>. DeQueue An Element\n");
        printf("\t<3>. Return Peek\n");
        printf("\t<4>. Check isFull\n");
        printf("\t<5>. Check isEmpty\n");
        printf("\t<6>. Number of Elemnets\n");
        printf("\t<7>. Display\n");
        printf("\t<8>. Exit\n");

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
                printf("\tNumber of elements inside the queue are %d :\n", numberOfElements());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 7:
                display();
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 8:
                exit(1);
            default:
                printf("\tInvalid Choice\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
        }
    }while(true);

    return 0;
}






/*
    Some Observations
    1) Queue is full when rear == MAX + 1
    2) Queue is empty when front == -1 and rear == -1 and front == rear + 1
    3)Queue contains only one elements when rear==front (considering only valid indexes)

                    DrawBack of Simple Queue
    when front != 0 and rear = max -1, then the empty slots can't be filled, which leads to the wastage of memory

            0___1_____2_____3_______4_______5_____6______
            ____ ______ ______ ________ ________ _______ __
                          |                       |
                       front                     rear
        blocks having indexes 0, 1 and 2 are wasted




*/
