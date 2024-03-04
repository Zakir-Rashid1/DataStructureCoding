#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 8
int array[MAXSIZE];
int size;

typedef enum bool{
    false, true
}boolean;


//Validate Size
boolean validate_size(){
    if(size > 0 && size <= MAXSIZE)
        return true;
    else{
        printf("\tInvalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }
}


//Validate Key
boolean validate_pos(int pos){
    if(pos >= 0 && pos <= size)
        return true;
    else{
        printf("\tInvalid Pos (0 <= Pos <= size)\n");
        exit(1);
    }
}


//Enter elements into the array
void enter_elements(){
    printf("\tEnter Elements Of An Array: \n");
    for(int i = 0; i < size; i++){
        printf("\t\tarray[%d] = ", i);
        scanf("%d", &array[i]);

    }
}



//Insert key elements at any position
void insert_at_any_pos(int pos, int key){
    int i = pos - 1;
    size++;
    if(validate_size()){
        for(int i = size - 1; i > pos; i--)
            array[i] = array[i - 1];
        array[pos] = key;
    }
}


//Display array elements
void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
}



//Testing
int main(){
    system("Cls");
    int key = 0;
    int pos = 0;

    printf("\t\tINSERT AT ANY VALID POSITION\n");
    printf("Enter Size of an array: ");
    scanf("%d", &size);

    if(validate_size(size))
        enter_elements();
