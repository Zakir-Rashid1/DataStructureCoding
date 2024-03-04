

#include <stdio.h>
#include <stdlib.h>

typedef enum bool{
  false, true
}boolean;

struct node{
  int data;
  struct node *link;
}*head = NULL;


//Create a node
struct node* create_node(){
  return malloc(sizeof(struct node));
}

//Add some more nodes
void add_some_nodes(int num){
  struct node *ptr = head;
  struct node *temp = NULL;
  int data;

  while(num != 0){
    temp = create_node();
    printf("Enter Data: ");
    scanf("%d", &data);
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    ptr = ptr->link;

    num--;
  }
}


//Traversing the list
void traverse_list(){
  struct node *temp = head;

  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->link;
  }
}


//Reverse The List
void reverse(){
  struct node *temp1 = head;
  struct node *temp2 = temp1->link;
  struct node *temp3 = temp2->link;

  while(temp3 != NULL){
    temp2->link = temp1;
    temp1 = temp2;
    temp2 = temp3;
    temp3 = temp3->link;
  }
  temp2->link = temp1;
  head->link = temp3;
  head = temp2;
  temp1 = temp2 = NULL;

}




//Testing
int main(){
  //Root Node
  head = malloc(sizeof(struct node));
  head->data = 1;
  head->link = NULL;
  printf("Root Node Already Added\n");

  //Adding Some More Nodes
  int num;
  printf("Enter How Many More Nodes You Wanna Add: ");
  scanf("%d", &num);

  add_some_nodes(num);
  printf("\nList Before Reverse\n");
  traverse_list();

  printf("\n\nList After Reverse\n");
  reverse();
  traverse_list();


  return 0;
}
