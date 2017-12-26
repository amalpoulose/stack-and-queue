#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct queue
{
	struct node *stack1; //head pointer value of stcak number 1
	struct node *stack2; //head pointer value of stack number 2
}Queue;

int size=0;
void enqueue(Queue *,int); 
void dequeue(Queue *);
void push(node **,int);
int  pop(node **);

int main()
{
	Queue *queue = malloc(sizeof(Queue*));
	int ch,data;
	char choice;
	do
	{
		system("clear");
		printf("------------Queue--------------\n\n1.Enqueue\n2.Dequeue\n\nChoice : ");
		scanf("%d",&ch);
		if(ch==1)
		{

			system("clear");
			printf("Data : ");
			scanf("%d",&data); 
			enqueue(queue,data);
		}
		else if(ch==2)
		{ system("clear");
			dequeue(queue);
		}
		else
			printf("\nInvalid choice\n");
		printf("\nDo you want to continue?(Y/N) : ");
		scanf(" %c",&choice);
	}while(choice=='Y'||choice=='y');
	return 0;

}


void enqueue(Queue *ptr,int n)
{
	if(size>=MAX)
	{
		printf("Queue Full\n");
		return;
	}
	push(&ptr->stack1,n);
	printf("%d is enqueued\n",n);
	size++;
}

void dequeue(Queue *ptr)
{
	int x,y;
	if(!(ptr->stack1))
	{
		printf("queue is empty");
		return;
	}
	if(ptr->stack2==0)
		while(ptr->stack1!=0)
		{
			x=pop(&ptr->stack1);
			push(&ptr->stack2,x);
		}
	printf("%d is dequeued \n",pop(&ptr->stack2));
	while(ptr->stack2!=0)
	{
		x=pop(&ptr->stack2);
		push(&ptr->stack1,x);
	}
	size--;
}

void push(node **ptr,int n)
{
	node *new=malloc(sizeof(node*)); 
	new->data=n;
	new->next=*ptr;
	*ptr=new;
}

int pop(node **ptr)
{
	node *temp;
	int x;
	temp=*ptr;
	x=temp->data;
	*ptr=(*ptr)->next;
	free(temp);
	return x;
}

