


/*
              100
            /     \
          90      110
        /   \     /   \
      80    95  105     150
    /   \         \
  70     85       108
                /    \
              106     109



*/


struct node{
  struct node *left;
  int data;
  struct node *right;
}*head = NULL;


//Create a node
struct node* create_node(){
  return malloc(sizeof(struct node));
}


//Add left child
void add_left_child(struct node *ptr){
  int data;
  struct node *temp = create_node();
  temp->left = temp->right = NULL;

  printf("Enter data: ");
  scanf("%d", &data);
  temp->data = data;
  ptr->left = temp;
}


//Add right child
void add_right_child(struct node *ptr){
  int data;
  struct node *temp = create_node();
  temp->left = temp->right = NULL;

  printf("Enter data: ");
  scanf("%d", &data);
  temp->data = data;
  ptr->right = temp;
}



//Create a BT
void create_tree(struct node *ptr){
  if(ptr == NULL)
    return;
  int your_choice;
  printf("Do you wanna add the left child of %d (1/0)?: ", ptr->data);
  scanf("%d", &your_choice);

  if(your_choice)
    add_left_child(ptr);

  printf("Do you wanna add the right child of %d (1/0)?: ", ptr->data);
  scanf("%d", &your_choice);
  if(your_choice)
    add_right_child(ptr);

  create_tree(ptr->left);
  create_tree(ptr->right);
}


//Preorder traversal
void preorder(struct node *ptr){
  if(ptr == NULL)
    return;
  printf("%d ", ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
}
