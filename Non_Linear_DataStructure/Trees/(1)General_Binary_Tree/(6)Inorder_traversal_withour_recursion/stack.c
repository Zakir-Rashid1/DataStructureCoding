


struct stack{
  struct stack *next;
  struct node *data;
}*stk = NULL;


typedef enum bool{
  false, true
}boolean;



//Check weather the stack is empty or not
boolean isEmpty(){
  if(stk == NULL)
    return true;
  else
    return false;
}

//Create node
struct stack* create_stack_node(){
  return malloc(sizeof(struct stack));
}


//Add at beg
void push(struct node *data){
  struct stack *temp = create_stack_node();
  temp->next = NULL;
  temp->data = data;

  if(stk == NULL)
    stk = temp;
  else{
    temp->next = stk;
    stk = temp;
  }
}



//Delete at beg
struct node* pop(){
  struct stack *ptr = stk;
  struct node *temp;

  if(ptr == NULL){
    printf("\nStack is Empty");
    exit(1);
  }
  temp = ptr->data;
  stk = stk->next;
  free(ptr);

  ptr = NULL;
  return temp;
}



//Display
void display(){
  struct stack *ptr = stk;

  while(ptr != NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
