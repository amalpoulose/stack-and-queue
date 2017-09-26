#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
typedef struct node
{
 int data;
 struct node *next;
}STACK;

void push(STACK **,int);
void pop(STACK **);
int size=0;

int main(void)
{
	STACK *stack=0;
	int ch,data;
	char choice;
	do
	{
		printf("------------Stack--------------\n\n1.Push\n2.pop\n\nChoice : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Data : ");
			scanf("%d",&data); 
			push(&stack,data);
		}
		else if(ch==2)
		     pop(&stack);
		else
			printf("\nInvalid choice\n");
		printf("\nDo you want to continue?(Y/N) : ");
		scanf(" %c",&choice);
	}while(choice=='Y'||choice=='y');
	return 0;
}

void  push(STACK **ptr,int n)
{
  STACK *new;
  if(size==MAX)
  {
    printf("\nStack Full\n");
    return;
  }
  new=malloc(sizeof(STACK));
  new->data=n;
  new->next=*ptr;
  *ptr=new;
  printf("\n %d is pushed in to Stack\n",n);
  size+=1;
}

void pop(STACK **ptr)
{
  STACK *temp;
  if(size == 0)
  {
    printf("\nStack Empty\n");
    return;
  }
  temp=*ptr;   
  printf("\n %d is popped out from stack\n",temp->data);
  *ptr=(*ptr)->next;
  free(temp);
  size-=1;
} 
