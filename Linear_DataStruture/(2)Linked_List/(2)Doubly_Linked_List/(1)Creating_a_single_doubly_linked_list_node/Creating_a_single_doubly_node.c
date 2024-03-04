#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *pre;
    int data;
    struct Node *next;
};


int main(){
    struct Node *head = NULL;
    head = malloc(sizeof(struct Node));
    head->pre = NULL;
    head->data = 100;
    head->next = NULL;

    return 0;

}
