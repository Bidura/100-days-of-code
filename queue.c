//queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void enqueue(int e)
{
	if(front==-1 && rear==-1)
	{
		queue[++rear]=e;
		front=0;
	}
	else if(rear == MAX-1)
	printf("Queue Full\n");
	else
	queue[++rear]=e;
	
}
int dequeue()
{
	int e=-1;
	if(front==-1 && rear==-1)
	printf("Queue empty\n");
	else if(front==rear)
	{
		e = queue[front++];
		front=rear=-1;
	}
	else
	 	e = queue[front++];
	return e;
	
}
void print()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
	printf("\n");
}
int main()
{   
   char ch;
   int e;
   while(1)
   {
   	printf("enter a to enqueue, b to dequeue and c to print elements of queue and d to exit\n");
   	fflush(stdin);
   	scanf("%c",&ch);
   	switch(ch)
   	{ case 'a':
   		printf("enter an element into the queue\n");
   		scanf("%d",&e);
   		enqueue(e);
   		break;
   	 case 'b':
   	 	printf("Deleted element = %d\n",dequeue());
   	 	break;
   	 case 'c':
   	 	print();
   	 	break;
   	 case 'd':
   	 	exit(0);
	   }
   	
   }
	return 0;
}
