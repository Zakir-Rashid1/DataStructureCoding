#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 50
int array[MAXSIZE];
int size = 0;

typedef enum bool{
    false, true
}boolean;


//validate size
boolean validate_size(){
    if(size > 0 && size <= MAXSIZE)
        return true;
    else{
        printf("\tInvalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }
}



//insert elements into an array
void insert(){
    printf("\tEnter Elements Respectivelly\n");
    for(int i = 0; i < size; i++){
        printf("\t\tarray[%d]= ", i);
        scanf("%d", &array[i]);
    }
}


//add at beg
void add_at_beg(int ele){
    size++;
    if(validate_size()){
        int j = size - 1;
        while(j != 0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = ele;
    }
}


//add at end
void add_at_end(int ele){
    size++;
    if(validate_size()){
        array[size - 1] = ele;
    }
}



//check validity of key
boolean isValidKey(int key){
    if(key >= 0 && key < size)
        return true;
    else{
        printf("\tInvalid Key (0 <= key < size)\n");
        exit(1);
    }   
}



//add at any position
void add_at_any_pos(int key, int ele){
    size++;
    if(isValidKey(key) && validate_size()){
        if(key == 0)
            add_at_beg(ele);
        else if(key == size)
            add_at_end(ele);
        else{
            for(int j = size - 1; j > key; j--)
                array[j] = array[j - 1];
            array[key] = ele;
        }
    }
}


//display array elements
void display(){
    if(validate_size()){
        for(int i = 0; i < size; i++)
            printf("%d ", array[i]);
    }
    printf("\n");
}



//Testing
int main(){
    system("CLS");
    int choice, data, key;
    printf("Enter Size of An Array: ");
    scanf("%d", &size);

    if(validate_size()){
        insert();
        printf("\tHit Enter To Continue ");
        getch();
    }


    do{
        system("CLS");
        printf("\t======================================\n");
        printf("\t<1>. Add at beg\n");
        printf("\t<2>. Add at end\n");
        printf("\t<3>. Add at any position\n");
        printf("\t<4>. Display\n");
        printf("\t<5>. Exit\n");
        printf("\t\tEnter your Choice: ");
        scanf("%d", &choice);
        printf("\n\t====================================\n");

        switch (choice){
        case 1:
            printf("Enter Data Element: ");
            scanf("%d", &data);
            add_at_beg(data);
            printf("\tElement %d is added successfully\n", data);
            printf("\tPress Enter To Continue: ");
            getch();
            break;
        case 2:
            printf("Enter Data Element: ");
            scanf("%d", &data);
            add_at_end(data);
            printf("\tElement %d is added successfully\n", data);
            printf("\tPress Enter To Continue: ");
            getch();
            break;
        case 3:
            printf("Enter Data Element: ");
            scanf("%d", &data);
            printf("Enter Key (index): ");
            scanf("%d", &key);
            add_at_any_pos(key, data);
            printf("\tElement %d is added successfully\n", data);
            printf("\tPress Enter To Continue: ");
            getch();
            break;
        case 4:
            printf("\nElements inside array are\n");
            display();
            printf("\tPress Enter To Continue: ");
            getch();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid Input\n");
        }
    }while(true);

    return 0;
}
