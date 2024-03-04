#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 50
int array[MAXSIZE];
int size = 0;

typedef enum bool{
    false,true
}boolean;


//Insert ele into the array
void insert(){
    printf("\t\tEnter Elements Respectivelly\n");
    for(int i = 0; i < size; i++){
        printf("\t\tarray[%d] = ", i);
        scanf("%d", &array[i]);
    }
}


//Validate Size
boolean isValidSize(){
    if(size > 0 && size <= MAXSIZE)
        return true;
    else
        return false;
}


//Validate key
boolean isValidKey(int key){
    if(key >= 0 && key < size)
        return true;
    else
        return false;
}


//display
void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}


//del at beg
int del_at_beg(){
    int delete;
    if(isValidSize()){
        delete = array[0];
        for(int i = 0; i < size ; i++)
            array[i] = array[i + 1];
        size--;
        return delete;
    }else{
        printf("Array is now empty\n");
        exit(1);
    }
}


//del at end
int del_at_end(){
    if(isValidSize())
        return array[--size];
    else{
        printf("Array is now empty\n");
        exit(1);
    }
}



//del at any position
int del_at_any_pos(int key){
    int delete;
    if(isValidKey(key)){
        delete = array[key];
        for(int i = key; i < size ; i++)
            array[i] = array[i + 1];
        size--;
        return delete;
    }else
        printf("Invlaid key\n");
}



//Testing
int main(){
    system("CLS");
    int choice = 0, key = 0;
    printf("Enter Size of an array: ");
    scanf("%d", &size);

    //validateSize
    if(isValidSize(size)){
        insert();
        printf("\tHit Enter To Continue: ");
        getch();
    }
    else{
        printf("Invalid Size (0 < size <= MAXSIZE)\n");
        exit(1);
    }

    do{
        system("CLS");
        printf("\t============================\n");
        printf("\t  <1>. Delete From Beg\n");
        printf("\t  <2>. Delete From End\n");
        printf("\t  <3>. Delete From Any Valid Index\n");
        printf("\t  <4>. Display\n");
        printf("\t  <5>. Exit\n");

        printf("\t    Enter your choice: ");
        scanf("%d", &choice);
        printf("\t============================\n");
        switch(choice){
            case 1:
                printf("\tElement %d is deleted \n", del_at_beg());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 2:
                printf("\tElement %d is deleted \n", del_at_end());
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 3:
                printf("Enter key(index): ");
                scanf("%d", &key);
                if(isValidKey(key))
                    printf("\tElement %d is deleted \n", del_at_any_pos(key));
                else{
                    printf("Invalid Key Or Array is empty\n");
                    exit(1);
                }
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 4:
                if(isValidSize()){
                    printf("Elements Inside The Array Are\n");
                    display();
                }else{
                    printf("Invlaid Size\n");
                    exit(1);
                }
                printf("\t\tHit Enter To Continue: ");
                getch();
                break;
            case 5:
                exit(1);
            default:
                printf("Invlaid Choice\n");
                printf("\t\tHit Enter To Continue: ");
                getch();
        }

    }while(true);


}