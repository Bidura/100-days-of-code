//Lab3
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

Node *head = NULL;
Node *last = NULL;

void enqueue(int data)
{
	Node *temp = malloc(sizeof(Node));
	temp -> data = data;
	temp -> next = NULL;
	if(head == NULL && last == NULL)
	{
		temp -> next = head;
		head=temp;
		last = temp;
	}
	else
	{ last->next=temp;
	  last=temp;
	}
}


int dequeue()
{  
   if(head==NULL && last==NULL)
	{ free(head);
	  free(last);
	  printf("Queue is empty !\n");
	  return -99;
	}
   else if(head==last)
   { Node*temp=head;
     head=NULL;
     last=NULL;
     return temp->data;
   }
   
   else 
	{   Node *temp = head;
		head = head -> next;
		int e = temp->data;
		free(temp);
		return e;
	}
	
}
void display()
{
	Node *temp = head;
	while(temp!=NULL)
	{ printf("%d\t",temp->data);
	  temp = temp ->next;
	}
	printf("\n");
}
int main()
{  int ch,e;
   while(1)
   {
   	 printf("Bidura Sarkar 2247244 Enter\n	1 to enqueue\n	2 to dequeue\n	3 to display\n	4 to exit\n");
   	 scanf("%d",&ch);
   	 switch(ch)
   	 { case 1:
   	 	printf("Enter element to enqueue \n");
   	 	scanf("%d",&e);
   	 	enqueue(e);
   	 	break;
   	   case 2:
   	   	printf("Element deleted = %d\n",dequeue());
   	   	break;
   	  case 3:
   	  	display();
   	  	break;
   	 case 4:
   	 	exit(0);
   	   default:
   	   	printf("Wrong choice\n");
   	   	
		}
   }
	
	return 0;
}


