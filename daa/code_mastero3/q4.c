#include <stdio.h>
#include <stdlib.h>
#define  MAX_Q_SIZE 500


struct node
{
  int data;
  struct node* left;
  struct node* right;
};

int search(int arr[], int strt, int end, int value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 
 
  *front = *rear = 0;
  return queue;
}
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}    
 
struct node *deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}     



struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  
  struct node *tNode = newNode(pre[preIndex++]);
 
  
  if(inStrt == inEnd)
    return tNode;
 
  
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}




void printLevelOrder(struct node* root)
{
  int rear, front;
  struct node **queue = createQueue(&front, &rear); 
  struct node *temp_node = root;
 
  while(temp_node)
  {
    printf("%d ", temp_node->data);
 
    
    if(temp_node->left)
      enQueue(queue, &rear, temp_node->left);
 
    
    if(temp_node->right)
      enQueue(queue, &rear, temp_node->right);
 
    if(front<=rear)
    temp_node = deQueue(queue, &front);
  }
}


void main()
{
	int t,n,i;
	int in[100000],pre[100000];
	struct node *root= (struct node *) malloc (sizeof(struct node));
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&pre[i]);
		
		for(i=0;i<n;i++)
			scanf("%d",&in[i]);
		
		root=buildTree(in,pre,0,n-1);
		
		printLevelOrder(root);

		t--;
	}
}




















