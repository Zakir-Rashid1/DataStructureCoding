
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int stk1[MAXSIZE];
int stk2[MAXSIZE];
int stk3[MAXSIZE];

int stk1_top = -1;
int stk2_top = -1;
int stk3_top = -1;
int stk4_top = -1;

typedef enum bool{
  false, true
}boolean;



//Check weather the stack is empty or not
boolean isEmpty(){
  if(stk1_top == -1)
    return true;
  else
    return false;
}


//Cheeck weather the stack is full or not
boolean isFull(){
  if(stk1_top == MAXSIZE - 1)
    return true;
  else
    return false;
}



//Push elements
void push(int ele){
  if(!isFull())
    stk1[++stk1_top] = ele;
  else{
    printf("Stack OverFlow\n");
    exit(1);
  }
}


//Pop elements
int pop(int stk[]){
  if(!isEmpty())
    return stk[stk1_top--];
  else{
    printf("Stack UnderFlow\n");
    exit(1);
  }
}


//Display ele of stacks
void display(int top, int stk[]){
  for(int i = 0; i <= top; i++)
    printf("%d ", stk[i]);
}






//Testing
int main(){
  int top = -1;
  push(100);
  push(200);
  push(300);
  push(400);
  push(500);

  top = stk1_top;
  printf("Data of orginal stack (stk1): ");
  display(top, stk1);
  printf("\n=========================================================\n");

  printf("Data of temporary1 stack (stk2): ");
  while(stk1_top != -1)
    stk2[++stk2_top] = pop(stk1);
  top = stk2_top;
  display(top, stk2);
  printf("\n=========================================================\n");

  stk1_top = stk2_top;
  printf("Data of temporary2 stack (stk3): ");
  while(stk1_top != -1)
    stk3[++stk3_top] = pop(stk2);
  top = stk3_top;
  display(top, stk3);
  printf("\n=========================================================\n");



  //Moving data of stack three to orginal stack
  printf("Elements of orginal Stack Are: ");
  stk1_top = stk3_top;
  while(stk1_top != -1)
    stk1[++stk4_top] = pop(stk3);
  top = stk4_top;
  display(top, stk1);

  return 0;
}
