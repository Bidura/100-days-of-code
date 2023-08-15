//linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{ int data;
  struct node *next;
}Node;
Node *head=NULL;
void insert_first(int d)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = d;
	temp->next=NULL;
	
	temp->next=head;
	head=temp;
}
void insert_last(int d)
{ 	Node *temp = malloc(sizeof(Node));
	temp->data = d;
	temp->next=NULL;
	if(!head)
	 {  head = temp;
	    return;
	 }
	Node *temp2 = head;
	while( temp2->next != NULL)
	{
		temp2 = temp2 -> next;
	}
	temp2->next=temp;
	
}
void delete_last()
{
  Node *temp = head;
	while( temp->next->next != NULL)
	{
		temp = temp -> next;
	}
	Node *temp2 = temp->next;
	temp->next=NULL;
	printf("Element to be deleted  = %d \n",temp2->data);
	free(temp2);	
} 

void delete_first()
{
  Node *temp = head;
	head=head->next;
	printf("Element to be deleted  = %d \n",temp->data);
	free(temp);	
}
void reverse()
{
	Node *next2 = NULL;
	Node *prev2 = NULL;
	Node *current = head;
	while(current)
	{
		next2 = current->next;
		current->next=prev2;
		prev2=current;
		current = next2;
	}
	head=prev2;
}
void display()
{   printf("displaying linked list\n");
	Node *temp = head;
	while( temp != NULL)
	{  printf("%d \t",temp->data);
		temp = temp -> next;
	}
	printf("\n");
}
int main()
{   int ch,e;
	while(1)
	{	printf("Enter\n	1 to insert node at last \n	2 to insert at first \n	3 to delete from last \n	4 to delete node from first\n	5 to reverse list\n        6 to display list\n        7 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{ case 1:
			printf("Enter element to insert \n");
			scanf("%d",&e);
			insert_last(e);
			break;
		 case 2:
		 	printf("Enter element to insert \n");
			scanf("%d",&e);
			insert_first(e);
			break;
		 case 3:
		 	delete_last();
		 	break;
		 case 4:
		 	delete_first();
		 	break;
		 case 5:
		 	reverse();
		 	break;
		 case 6:
		 	display();
		 	break;
		case 7:
			exit(0);
		 default:
		 	printf("Wrong choice, try again\n");
		} 
	}
	return 0;
}
