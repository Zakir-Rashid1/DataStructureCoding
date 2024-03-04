#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum bool{
    false,true
}boolean;

struct Node{
    int data;
    struct Node *link;
}*front = NULL, *rear = NULL;


//Check Whether the list is full or not
boolean isFull(struct Node *newNode){
    if(newNode == NULL)
        return true;
    else if(front == NULL){
        front = newNode;
        return false;
    }else
        return false;
}


//Check Whether the queue is emtpy of not
boolean isEmpty(){
    if(front == NULL)
        return true;
    else
        return false;
}


//EnQueue Function
void enQueue(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    if(!isFull(newNode)){
        newNode->data = data;
        newNode->link = NULL;
        if(rear == NULL)
            rear = newNode;
        else{
            rear->link = newNode;
            rear = newNode;
        }
    }else{
        printf("\tQueue Is Full\n");
        exit(1);
    }
}



//DeQueue Function
int deQueue(){
    if(!isEmpty()){
        int data;
        struct Node *temp = NULL;
        data = front->data;
        temp = front;
        front = front->link;
        if(front == NULL)
            rear = NULL;
        free(temp);
        return data;
    }else{
        printf("\tQueue Is Empty\n");
        exit(1);
    }
}



//Return Peek Element
int peek(){
    if(!isEmpty())
        return front->data;
    else{
        printf("\tQueue is Empty\n");
        exit(1);
    }
}


//Display Queue Elements
void display(){
    if(isEmpty()){
        printf("\tQueue is empty\n");
        exit(1);
    }else{
        struct Node *temp = front;
        printf("\tElements Insdie The Queue Are\n");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}




//Tesing
int main(){
    system("cls");
    int choice, data;
    struct Node *newNode = NULL;

    do{
        system("cls");
        printf("============================================\n");
        printf("\t<1>. Enqueue An Element\n");
        printf("\t<2>. Dequeue An Element\n");
        printf("\t<3>. Display All The Elements\n");
        printf("\t<4>. is Empty\n");
        printf("\t<5>. Peek Element\n");
        printf("\t<6>. Exit\n\n");

        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);
        printf("==============================================\n");

        switch(choice){
            case 1:
                printf("\tEnter an element to enqueue: ");
                scanf("%d", &data);
                enQueue(data);
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 2:
                printf("%d is dequeued Sucessfully \n", deQueue());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                display();
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                if(isEmpty())
                    printf("Queue Is Empty\n");
                else
                    printf("Queue Is Not Empty\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                printf("Peek Element insside the queue is %d \n", peek());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }while(true);

    return 0;
}