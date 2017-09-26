#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
typedef struct node
{
 int data;
 struct node *next;
}QUE;

void enqueue(QUE **,int);
void dequeue(QUE **);
int size=0;
 
int main(void)
{   
	QUE *queue=0;
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
			enqueue(&queue,data);
		}
		else if(ch==2)
                    { system("clear");
		     dequeue(&queue);
                    }
		else
			printf("\nInvalid choice\n");
		printf("\nDo you want to continue?(Y/N) : ");
		scanf(" %c",&choice);
	}while(choice=='Y'||choice=='y');
	return 0;
}

void enqueue(QUE **ptr,int n)
{
static QUE *last,*new;
if(size==MAX)
{
  printf("\nQueue is Full\n");
  return;
}
new=malloc(sizeof(QUE));
new->data=n;
if(*ptr==0)
{
 new->next=*ptr;
 *ptr=new;
}
else
{
 new->next=last->next;
 last->next=new;
}
last=new;
size+=1;
printf("\n%d is enqueued\n",n);
} 

void dequeue(QUE **ptr)
{
 if(size==0)
{
 printf("\nQueue is Full\n");
 return;
}
 QUE *temp=*ptr;
 int value=(*ptr)->data;
 (*ptr)=(*ptr)->next;
 free(temp);
 printf("\n %d is Dequeued\n",value);
 size-=1;
} 
