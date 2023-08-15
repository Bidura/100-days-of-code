#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
}Node;
Node *head= NULL;
Node *last = NULL;
void insert(int e)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> data = e;
	temp->next = temp->prev = NULL;
	if(head==NULL)
	{
		head=temp;
		last = head;
		head->next = last;
		last->next = head;
		head->prev = last;
		last->prev = head;
		return;
		
	}
	temp->prev = last;
	last->next = temp;
	last = temp;
	last->next = head;
	head->prev = last;
	
}
void insert_first(int e)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> data = e;
	temp->next = temp->prev = NULL;
	if(head==NULL)
	{
		head=temp;
		last = head;
		head->next = last;
		last->next = head;
		head->prev = last;
		last->prev = head;
		return;
		
	}
	temp->next = head;
	temp->prev = head->prev;
	head->prev = temp;
	head = temp;
	last->next = head;
	
}
void delete_last()
{ int e;
	if(head==NULL && last==NULL)
 	{ printf("List empty\n");
 	  return;
	 }
 	else if(head==last)
 	{  printf("deleted element = %d\n",head->data);
 		head=last=NULL;
 		return ;
	 }
	 Node * temp = last;
	 e = temp->data;
	 last->prev->next = head;
	 last->next = NULL;
	 last = last->prev;
	 head->prev = last;
	 temp->prev = NULL;
	 
	 free(temp);
	 printf("deleted element = %d\n",e);
}
void delete_first()
{ int e;
	if(head==NULL && last==NULL)
 	{ printf("List empty\n");
 	  return;
	 }
 	else if(head==last)
 	{  printf("deleted element = %d\n",head->data);
 		head=last=NULL;
 		return ;
	 }
	 Node * temp = head;
	 e = temp->data;
	 head->next->prev = last;
	 head->prev = NULL;
	 head = head->next;
	 last->next = head;
	 temp->next = NULL;
	 free(temp);
	 printf("deleted element = %d\n",e);
}
void insert_pos(int e, int pos)
{
		Node *temp = head;
		int count=1;
	while(count <= pos-2)
	{
		temp = temp->next;
		count++;
	}
	Node *temp2 = (Node*)malloc(sizeof(Node));
	temp2->data = e;
	temp2->prev = temp2 -> next = NULL;
	temp->next->prev = temp2;
	temp2->next = temp->next;
	temp->next = temp2;
	temp2->prev = temp;
}
void display()
{
	Node *temp = head;
	while(temp!= NULL && temp->next != head)
	{
		printf(" %d\t",temp->data);
		temp = temp -> next;
	}
	printf(" %d\n",temp->data);
	
}
void rev_disp()
{
	Node *temp =last;
	while(temp!= NULL && temp->prev != last)
	{
	   printf(" %d\t",temp->data);
		temp = temp->prev;	
	}
	printf(" %d\n",temp->data);
	
}
int main()
 {  printf("-------------------------------------DOUBLY CIRCULAR LINKED LIST  -------------------------------------\n");
 	 int ch2,pos;
 	 char ch;
 	 while(1)
 	 {  printf("Enter A to enter elements in the end of linked list\nEnter B to enter elements from the first of the list\nEnter C to delete element from last\nEnter D to delete element from first\nEnter E to display list\nEnter F to insert element in a given position\nEnter G to display list in reverse order\nEnter H to exit\n ");
 	   	   printf("\n--------------------------------------------------\n");
 	   
		 fflush(stdin);
		 scanf("%c",&ch);
 	    while(!(ch>='A' && ch<='Z'))
 	    { printf("Enter A to enter elements in the end of linked list\nEnter B to enter elements from the first of the list\nEnter C to delete element from last\nEnter D to delete element from first\nEnter E to display list\nEnter F to insert element in a given position\nEnter G to display list in reverse order\nEnter H to exit\n ");
 	   	  printf("\n--------------------------------------------------\n");
			  fflush(stdin);
			 scanf("%c",&ch);	
		 }
 	    
 	    switch(ch)
 	    {
 	    	 case 'A':
 	    	 	printf("Enter a valid element\nOR\nEnter -1 to stop entering elements\n");
 	    	 	scanf("%d",&ch2);
 	    	 	while(ch2!=-1)
 	    	 	{
 	    	 		insert(ch2);
 	    	 		printf("Enter a valid element\nOR\nEnter -1 to stop entering elements\n");
 	    	 		scanf("%d",&ch2);
				  
				}
				break;
			 case 'B':
			 	printf("Enter a valid element\nOR\nEnter -1 to stop entering elements\n");
 	    	 	scanf("%d",&ch2);
 	    	 	while(ch2!=-1)
 	    	 	{
 	    	 		insert_first(ch2);
 	    	 		printf("Enter a valid element\nOR\nEnter -1 to stop entering elements\n");
 	    	 		scanf("%d",&ch2);
				  
				}
				break;
			 case 'C':
			 	delete_last();
			 	break;
			 case 'D':
			 	delete_first();
			 	break;
			 case 'E':
			 	display();
			 	break;
			 case 'F':
			 	printf("Enter position where element is to be inserted\n");
			 	scanf("%d",&pos);
			 	printf("Enter element to be inserted\n");
			 	scanf("%d",&ch2);
			 	insert_pos(ch2,pos);
			 	break;
			 case 'G':
			 	rev_disp();
			 	break;
			 case 'H':
			 	exit(0);
			 default:
			 	printf("Wrong choice\n");
			 
		}
	  }
	  return 0;
 }
