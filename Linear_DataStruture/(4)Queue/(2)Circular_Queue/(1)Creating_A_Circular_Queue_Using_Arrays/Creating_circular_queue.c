#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 5
int cQueue[MAXSIZE];
int front = -1;
int rear = -1;

typedef enum bool{
    false, true
}boolean;



//Check Whether the queue is empty or not
boolean isEmpty(){
    if(front == -1)
        return true;
    else
        return false;
}



//Check Whether the queue is full or not
boolean isFull(){
    if(rear == MAXSIZE - 1 && front == 0)
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
        if(rear == MAXSIZE - 1)
            rear = 0;
        else
            rear++;
        cQueue[rear] = data;
    }else{
        printf("\tQueue OverFlow\n");
        exit(1);
    }
}


//DeQueue Function
int deQueue(){
    int data = 0;
    if(!isEmpty()){
        data = cQueue[front];
         if(front == rear)
            front = rear = -1; //reSize Queue
        else if(front == MAXSIZE - 1)
            front = 0;
        else
            front++;
        return data;
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
 
}



//Return Peek
int peek(){
    if(isEmpty()){
        printf("\tQueue UnderFlow\n");
        exit(1);
    }else
        return cQueue[front];
}




//Display Queue Data
void display(){
    if(!isEmpty()){
        if(front <= rear)
             for(int i = front; i <= rear; i++)
                printf("%d ", cQueue[i]);
        else{
                int j = front;
                while(j != MAXSIZE){
                    printf("%d ", cQueue[j]);
                    j++;
                }
                j = 0;
                while(j <= rear){
                    printf("%d ", cQueue[j]);
                    j++;
                }
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
