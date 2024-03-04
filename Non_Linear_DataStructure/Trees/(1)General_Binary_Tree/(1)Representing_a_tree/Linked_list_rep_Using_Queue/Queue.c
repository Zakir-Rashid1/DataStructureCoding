

#define MAXSIZE 5
struct node{
  struct node *left;
  int data;
  struct node *right;
}*root = NULL;


typedef enum bool{
  false, true
}boolean;

int front = -1;
int rear = -1;
struct node *cQueue[MAXSIZE];

//Check weather the queue is full or not
boolean isFull(){
  if(front == 0 && rear == MAXSIZE -1)
    return true;
  else if(front == rear + 1)
    return true;
  else
    return false;
}


//Check weather the queue if empty or not
boolean isEmpty(){
  if(front == -1 && rear == -1)
    return true;
  else
    return false;
}



//enQueue Method
void enQueue(struct node* data){
  if(!isFull()){
    if(front == -1)
      front = 0;
    if(rear == MAXSIZE -1){
      rear = 0;
      cQueue[rear] = data;
    }
    else
      cQueue[++rear] = data;
  }else{
    printf("Queue OverFlow\n");
    exit(1);
  }
}



//deQueue Method
struct node* deQueue(){
  struct node* rvalue = NULL;
  if(!isEmpty()){
    if(front == rear){
      rvalue = cQueue[front];
      front = rear = -1;
    }
    else if(front == MAXSIZE -1){
      rvalue = cQueue[front];
      front = 0;
    }else
      rvalue = cQueue[front++];
    return rvalue;
  }else{
    printf("Queue UnderFlow\n");
    exit(1);
  }
}


//Display Function
void display(){
  if(!isEmpty()){
    if(front <= rear)
    for(int i = front; i <= rear; i++)
    printf("%d ", cQueue[i]);
    else{
      for(int i = front; i < MAXSIZE; i++)
      printf("%d ", cQueue[i]);
      for(int i = 0; i <= rear; i++)
      printf("%d ", cQueue[i]);
    }
  }else
    printf("Queue If Emtpy\n");
}
