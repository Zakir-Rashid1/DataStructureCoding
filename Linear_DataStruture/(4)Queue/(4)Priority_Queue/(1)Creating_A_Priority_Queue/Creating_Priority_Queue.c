#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// Following : Lowest Number Highest Priority
typedef enum bool{
    false, true
}boolean;

struct node{
    int prority;
    int data;
    struct node *next;
} *front = NULL;

//Check isFull
boolean isFull(struct node *newNode){
    if(newNode == NULL)
        return true;
    else
        return false;
}


//Check IsEmpty
boolean isEmpty(){
    if(front == NULL)
        return true;
    else 
        return false;
}



//EnQueue Function
void enQueue(int data, int priority){
    struct node *newNode = malloc(sizeof(struct node));
    if(!isFull(newNode)){
        if(isEmpty()){
            newNode->prority = priority;
            newNode->data = data;
            newNode->next = NULL;

            front = newNode;
        }else{
            newNode->prority = priority;
            newNode->data = data;
            newNode->next = NULL;

            struct node *temp = front;
            if(priority <= front->prority){
                if(priority < front->prority){ 
                    newNode->next = front;
                    front = newNode;
                }else
                    front->next = newNode; //FCFS
            }else{
                struct node *temp2 = temp;
                while(temp->next != NULL && priority >= temp->prority){
                    temp2 = temp;
                    temp = temp->next;
                }
                if(temp->next == NULL || temp->next != NULL){
                    if(priority < temp->prority){
                        temp2->next = newNode;
                        newNode->next = temp;
                    }else
                        temp->next = newNode;
                }
            }
        }
    }else{
        printf("\tQueue OverFlow\n");
        exit(1);
    }
}


//DeQueue Function
int deQueue(){
    if(!isEmpty()){
        int data;
        struct node *temp = front;
        data = front->data;
        front = front->next;

        free(temp);
        temp = NULL;
        return data;
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
}



//Display
void display(){
    if(!isEmpty()){
        struct node *temp = front;
        printf("\tQueue Elements Are \n");
        while(temp != NULL){
            printf("%d -> P(%d)\t", temp->data, temp->prority); //P(x) : menas priority of x
            temp = temp->next;
        }
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
    printf("\n");
}


//Return Peek
int peek(){
    if(!isEmpty()){
        return front->data;
    }else{
        printf("\tQueue UnderFlow\n");
        exit(1);
    }
    printf("\n");
}






//Testing
int main(){
    int priority, choice;
    int data;
   system("CLS");

    do{
       system("CLS");
        printf("\t=============================\n");
        printf("\t<1>. EnQueue Elements\n");
        printf("\t<2>. DeQueue Elements\n");
        printf("\t<3>. Check IsEmpty\n");
        printf("\t<4>. Display\n");
        printf("\t<5>. Return Peek\n");
        printf("\t<6>. Exit\n");
        printf("\t\tEnter your Choice: ");

        fflush(stdin);
        scanf("%d", &choice);
        printf("\t=============================\n");
        switch(choice){
            case 1:
                printf("\tEnter Data    : ");
                scanf("%d", &data);
                printf("\tEnter Priority: ");
                scanf("%d", &priority);
                enQueue(data, priority);

                printf("\t%d Added Successfully \n", data);
                printf("\t\tHit Enter To Continue ");
                getch();
                break;
            case 2:
                printf("\t%d is deleted Sucessfully \n", deQueue());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                if(isEmpty())
                    printf("\tQueue Is Empty\n");
                else
                    printf("\tQueue is Not Empty\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                display();
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                printf("\tPeek Element Is: %d ", peek());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 6:
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
                                             PRIORITY QUEUE
    Functions Of Prioriry Queue
            -EnQueue(): This function is used to insert an element in the queue.
            The element has to be added according to its priority where the front element of the list 
            must have highest priority and the last element must have lowest priority.

            -DeQueue(): This funciton is used to remove an element fron the queue the element with
            highest prioriy will be deleted.

            -Peek(): This function is used to get the element with the highest priority
            in the list without removing it from the queue.


NOTE: If the priorities are same then use FCFS

*/