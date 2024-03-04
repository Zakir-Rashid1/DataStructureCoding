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



//Delete First Element
int del_at_beg(int *array, int *size){
    if( size != 0){
        int del = array[0];
        for(int i = 0; i < (*size); i++)
            array[i] = array[i + 1];
        (*size)--;
        return del;
    }else
        return 0;
    printf("\n");
}


//display
void display(int *array, int size){
    if(size == 0){
        printf("Array is now empty\n");
        exit(1);
    }else{
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
    int size = 0;
    int array[MAXSIZE];
    int del = 0;

    printf("\t\tDELETE FIRST ELEMENT\n");
    printf("Enter Size of an array: ");
    scanf("%d", &size);
    validate(size);

    printf("\t\tEnter Elements Respectivelly: \n");
    enter_elements(array, size);

    printf("Elements Before Deletion\n");
    display(array, size);
    printf("=============================\n");

    //del first element
    do{
        del = del_at_beg(array, &size);
        if(del)
            printf("\tElement %d is sucessfully deleted \n", del);
        else{
            printf("\tInvalid Size (Deletion Failed)");
            exit(1);
        }

        printf("\nElements After Deletion\n");
        display(array, size);
        printf("=============================\n");

        printf("\t\nHit Enter To Delete One More Element: ");
        getch();
        printf("\n");
       
    }while(size != 0);


    return 0;
}
