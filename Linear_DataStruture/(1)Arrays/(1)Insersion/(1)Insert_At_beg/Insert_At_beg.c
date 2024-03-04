#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 80

typedef enum bool{
    false, true
}boolean;

//Enter elements into the array
void enter_elements(int *array, int size){
    printf("\tEnter Elements Of An Array: \n");
    for(int i = 0; i < size; i++){
        printf("\tarray[%d] = ", i);
        scanf("%d", &array[i]);

    }
}

boolean validate_size(int size){
    if(size > 0 && size <= MAXSIZE)
        return true;
    else{
        printf("\tInvalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }
}

//Insert key element at beg
void insert_at_beg(int *array, int *size, int key){
    (*size)++;
    //Check Whether the new size is valid or not
    if(validate_size(*size)){ 
        int j = *size - 1;
        while(j != 0){
            array[j] = array[j - 1];
            j--;
        }
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

    printf("\t\tINSERT AT BEG\n");
    printf("Enter Size of an array: "); // Size must be <= MAXSIZE
    scanf("%d", &size);

    if(validate_size(size))
        enter_elements(array, size);

    //enter elements
    printf("\nElements Before inserting any key value\n");
    display(array, size);
    printf("\n==================================\n");

    do{
        printf("\n\tEnter your key element: ");
        scanf("%d", &key);

        insert_at_beg(array, &size, key); 

        printf("\nElements After inserting key element\n");
        display(array, size);
        printf("\n==================================\n");
        printf("\t\tHit enter to continue entering elements ");
        getch();
        printf("\n");
    }while(1);


    return 0;
}