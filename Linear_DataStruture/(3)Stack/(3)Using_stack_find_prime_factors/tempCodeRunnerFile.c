#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define SIZE 100
int first = -1;
int stackArray[SIZE];

typedef enum bool{
    false, true
}boolean;


//Check weather the stack is empty or not
boolean isEmpty(){
    if(first == -1)
        return true;
    else
        return false;
}


//Check weather the stack is full or not
boolean isFull(){
    if(first == (SIZE - 1))
        return true;
    else
        return false;
}


//push an element
void push(int data){
    if(!isFull()){
        for(int i = first; i >= 0; i--)
            stackArray[i + 1] = stackArray[i];
        stackArray[0] = data;
        first++;
    }else
        printf("Stack OverFlow\n");
}


//pop an element
int pop(){
    int value = 0;
    if(!isEmpty()){
        value = stackArray[0];
        for(int i = 0; i < first; i++)
            stackArray[i] = stackArray[i + 1];
        first--;
        return value;
    }else{
        printf("Stack UnderFlow\n");
        exit(1);
    }
}


//display data
void display(){
    if(first == -1)
        printf("Stack is empty\n");
    else{
        printf("Data inside the stack is\n");
        for(int i = 0; i <= first; i++)
            printf("%d ", stackArray[i]);
    }
    printf("\n");
}


//find prime fact
void primeFact(int num){
    for(int i = 2; i <= num; i++){
        if(num % i == 0){