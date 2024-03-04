#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 50

typedef enum bool{
    false, true
}boolen;



//Enter elements into the array
void enter_elements(int *array, int size){
    printf("\tEnter Elements Of An Array: \n");
    for(int i = 0; i < size; i++){
        printf("\t\tarray[%d] = ", i);
        scanf("%d", &array[i]);

    }
}



//Validate size
boolen validate_size(int size){
    if(size > 0 && size <= MAXSIZE)
        return true;
    else{
        printf("\tInvlaid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }
}


void insert_at_end(int *array, int *size, int key){
    (*size)++;
    if(validate_size(*size)){
        int j = (*size) - 1;
        array[j] = key;
    }
}


//Display array elements
void display(int *array, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
}



//Testing
int main(){
    system("Cls");
    int size;
    int array[MAXSIZE];
    int key = 0;

    printf("\t\tINSERT AT THE END\n");
    printf("Enter Size of an array: ");
    scanf("%d", &size);

    if(validate_size(size))
        enter_elements(array, size);

    do{
        printf("\nElements Before inserting any key element: \n");
        display(array, size);
        printf("\n===============================\n");

        printf("\n\tEnter your key element: ");
        scanf("%d", &key);
        insert_at_end(array, &size, key); // O(1)

        printf("\nElements After inserting key element: \n");
        display(array, size);
        printf("\n===============================\n");

        printf("\t\tHit enter to continue adding elements ");
        getch();
        printf("\n");
    }while(1);


    return 0;
}