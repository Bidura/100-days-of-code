//circular queue
#include<stdio.h>
#include<stdlib.h>
int *queue, front=-1, rear=-1,size;
void enqueue(int e)
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=(rear+1)% size;
		queue[rear]=e;
	}
	else if((rear+1)%size == front)
	{
		printf("Queue full\n");
	}
	else
	rear=(rear+1)% size;
	queue[rear]=e;
}
int dequeue()
{  int e;
	if(front==-1 && rear==-1)
	{
		printf("queue empty\n");
		return -1;
	}
	else if(front==rear)
	{
		e = queue[front];
		front=rear=-1;
		return e;
	}
	e = queue[front];
	front = (front+1)%size;
	return e;
}
void display()
{
	int i;
	for(i=front;i!=rear;i=(i+1)%size)
	 printf("%d\t",queue[i]);
	printf("%d\n",queue[i]);
}
int main()
{
	char ch;
	int e;
	printf("enter maximum queue size\n");
	scanf("%d",&size);
	queue=(int*)malloc(sizeof(int)*size);
	while(1)
	{
		printf("enter a for enqueue, b for dequeue, c to display and d to exit\n");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch)
		{
			case 'a':
				printf("enter the element\n");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 'b':
				printf("Deleted element = %d\n",dequeue());
				break;
			case 'c':
				display();
				break;
			case 'd':
				exit(0);
			default:
				printf("wrong choice\n");
				
		}
	}
	return 0;
}
