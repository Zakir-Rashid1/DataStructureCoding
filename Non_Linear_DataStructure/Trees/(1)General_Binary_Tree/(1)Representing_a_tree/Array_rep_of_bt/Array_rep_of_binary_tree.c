
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 10

char tree[MAXSIZE]; //By default contains '\0'

/*
Requirments:
R1: It must not allow us to insert more than one root elements.
R2: It must check whether the parent node of the node we want to insert exists or not

/*
                          A
                       /    \
                      B      C
                    /  \    / \
                   D    E  F

*/



//Add root element
void add_root_ele(char ele){
  if(tree[0] != '\0')
    printf("Root elemnet already exists\n");
  else
    tree[0] = ele;
}

//Add left child
void left(char c, int parent){
  if(tree[parent] == '\0')
    printf("Can't insert %c parent of %c does not exist ", c, c);
  else
    tree[(2 * parent) + 1] = c;
}


//Add right child
void right(char c, int parent){
  if(tree[parent] == '\0')
    printf("Can't insert %c parent of %c does not exist\n", c, c);
  else
    tree[(2 * parent) + 2] = c;
}


//Print
void print(){
  for(int i = 0; i < MAXSIZE; i++){
    if(tree[i] == '\0')
      printf("* ");
    printf("%c ", tree[i]);
  }
}



int main(){
  add_root_ele('A');
  left('B', 0);
  right('C',0);
  left('D', 1);
  right('E', 1);
  right('F', 2);

  print();

  return 0;
}
