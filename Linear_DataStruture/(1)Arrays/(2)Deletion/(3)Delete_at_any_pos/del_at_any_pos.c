#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 40

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



//Validate Key
boolean validateKey(int key, int size){
    if(key >= 0 && key <= size - 1)
        return true;
    else{
        printf("\tInvalid Key\n");
        exit(1);
    }
}

//Validate size
void validateSize(int size){
    if(!(size > 0 && size <= MAXSIZE)){
        printf("\tInvalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }
}



//Delete at any position
int del_at_any_pos(int *array, int *size, int key){
    if(validateKey(key, *size)){
        int del = array[key];
        for(int i = key; i < *size; i++)
            array[i] = array[i + 1];
        (*size)--;
        return del;
    }else{
        printf("\tDeletion Failed (Invalid Size)\n");
        exit(1);
    }
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






//Tesing
int main(){
    system("CLS");
    int size = 0, key = 0;
    int array[MAXSIZE];

    printf("\t\tDELETE AT ANY VALID POSITION\n");
    printf("Enter Size of an array: ");
    scanf("%d", &size);
    
    validateSize(size);
    printf("\t\tEnter Elements Respectivelly\n");
    enter_elements(array, size);

    printf("Elements Before Deletion\n");
    display(array, size);
    printf("=============================\n");

    //Del ele at any valid position
   
    do{
         printf("\tEnter Key (index): ");
         scanf("%d", &key);

        printf("\tElemetn %d is deleted sucessfully ", del_at_any_pos(array, &size, key));

        printf("\nElements After Deletion\n");
        display(array, size);
        printf("=============================\n");
        printf("\t\tHit enter to delete one more element ");
        getch();
        printf("\n");
    }while(1);

    return 0;
}
