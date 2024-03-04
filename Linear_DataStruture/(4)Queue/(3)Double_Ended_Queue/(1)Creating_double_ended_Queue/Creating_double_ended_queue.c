#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 5

int dQueue[MAXSIZE];
int front = -1;
int rear = -1;

typedef enum bool{
    false, true
}boolean;



//Check Whether The dQueue Is Full or Not
boolean isFull(){
    if(front == 0 && front == MAXSIZE - 1)
        return true;
    else if(front == rear + 1)
        return true;
    else
        return false;
}


//Check Whether The dQueue Is Empty or Not
boolean isEmpty(){
    if(front == -1)
        return true;
    else
        return false;
}


//enQueueRear Function
void enQueueRear(int data){
    if(!isFull()){
        if(rear == -1)
            front = 0;
        else if(rear == MAXSIZE -1)
            rear = 0; 
        else 
            rear++;
        dQueue[rear] = data;
    }else{
        printf("\tQueue OverFlow\n");
        exit(1);
    }
}


//enQueueFront Function
void enQueueFront(int data){
    if(!isFull()){
        if(front == -1)
            front = rear = 0;
        else if(front == 0)
            front = MAXSIZE - 1;
        else
            front--;
        dQueue[front] = data;
    }else{
        printf("\tQueue OverFlow\n");
        exit(1);
    }
}



//deQueueFront Function
int deQueueFront(){
    int data;
    if(!isEmpty()){
        data = dQueue[front];
        if(front == rear)
            rear = front = -1;
        else if(front == MAXSIZE -1)
            front = 0;
        else
            front++;
        return data;
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}


//deQueueRear Function
int deQueueRear(){
    int data;
    if(!isEmpty()){
        data = dQueue[rear];
        if(rear == front)
            front = rear = -1;
        else if(rear == 0)
            rear = MAXSIZE -1;
        else
            rear--;
        return data;
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}



//Display 
void display(){
    if(!isEmpty()){
        printf("\tElements Inside Queue Are\n");
        if(front <= rear)
            for(int i = front; i <= rear; i++)
                printf("%d ", dQueue[i]);
        else{
            int i = 0;
            for(i = front; i <= MAXSIZE - 1; i++)
                printf("%d ", dQueue[i]);
            
            for(i = 0; i <= rear; i++)
                printf("%d ", dQueue[i]);
        }
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
    printf("\n");
}







//Testing
int main(){
    system("CLS");
    int choice, data;
    do{
        system("CLS");
        printf("\t==============================\n");
        printf("\t<1>. EnQueue Front\n");
        printf("\t<2>. DeQueue Front\n");
        printf("\t<3>. EnQueue Rear\n");
        printf("\t<4>. DeQueue Rear\n");
        printf("\t<5>. Check IsFull\n");
        printf("\t<6>. Check IsEmpty\n");
        printf("\t<7>. Display\n");
        printf("\t<8>. Exit\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);
        printf("\t==============================\n");

        switch(choice){
            case 1:
                printf("\tEnter Data Element: ");
                scanf("%d", &data);
                enQueueFront(data);
                printf("\t%d Added Sucessfully\n", data);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 2:
                printf("\t%d is deleted Sucessfully \n", deQueueFront());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                printf("\tEnter Data Element: ");
                scanf("%d", &data);
                enQueueRear(data);
                printf("\t%d Added Sucessfully\n", data);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                printf("\t%d is deleted Sucessfully \n", deQueueRear());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                if(isFull())
                    printf("\tQueue Is Full\n");
                else
                    printf("\tQueue Is Not Full\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 6:
                if(isEmpty())
                    printf("\tQueue Is Empty\n");
                else
                    printf("\tQueue is Not Empty\n");
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
                    Some important Points                                 
    1) There are two enqueue and dequeue operations in double ended queue one can insert
       or delete an element at either end of the queue
    
    2) Front variable should be decremented whenever a new element has to be inserted at the front end
    
    3) Rear variable should be decremented whenever a new elemnet is deleted from the rear end

    4) if(rear == 0)
        do rear = MAX - 1

    5) if(front == 0)
        do front = MAX -1

*/