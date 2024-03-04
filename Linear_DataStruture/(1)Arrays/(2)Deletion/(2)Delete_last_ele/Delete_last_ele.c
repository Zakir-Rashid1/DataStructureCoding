#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 50

typedef enum bool {
    false,true
}boolean;


//Enter elements into the array
void enter_elements(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("\t\tarray[%d] = ", i);
        scanf("%d", &array[i]);
    }
}



//Delete last element
int del_at_end(int *array, int *size){
    if( *size != 0)
        return array[--(*size)];
    else{
        printf("\tDeletion failed (invalid size)\n");
    }
}


//display
void display(int *array, int size){
    if(size == 0)
        printf("Array is empty\n");
    else{
        for(int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

void validate(int size){
    if(size <= 0 || size > MAXSIZE ){
        printf("Invalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }else
        return;
}



//Tesing
int main(){
    system("CLS");
    int size = 0, del = 0;
    int array[MAXSIZE];

    printf("\t\tDELETE LAST ELEMENT\n");
    printf("Enter Size of an array: ");
    scanf("%d", &size);
    validate(size);

    printf("\t\tEnter Elements Respectivelly: \n");
    enter_elements(array, size);

    printf("Elements Before Deletion\n");
    display(array, size);
    printf("=============================\n");

    do{
        
        printf("\tElement %d is deleted sucessfully\n", del_at_end(array, &size));

        printf("Elements After Deletion\n");
        display(array, size);
        printf("=============================\n");
        printf("\t\tHit enter to delete one more element ");
        getch();
        printf("\n");
    }while(1);

    return 0;
}
