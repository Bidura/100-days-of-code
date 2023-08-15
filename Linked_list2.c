#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{ 
   int data;
   struct node *next;
   struct node *prev;
 } node;
 node *head=NULL;
 node *last = NULL;
 void insert(int data)
 { node *temp = (node*)malloc(sizeof(node));
   temp->data = data;
   temp->next=NULL;
   temp->prev=NULL;
   if(head==NULL)
   { temp->next=head;
     head=temp;
     last=head;
     return;
   }
   temp->prev=last;
   last->next=temp;
   last=temp;
 }
 void insert_first(int data)
 { node *temp = (node*)malloc(sizeof(node));
   temp->data = data;
   temp->next=NULL;
   temp->prev=NULL;
   if(head==NULL)
   { temp->next=head;
     head=temp;
     last=head;
     return;
   }
   temp->prev=NULL;
   temp->next=head;
   head->prev= temp;
   head=temp;
 }
 void disp()
 { node *temp=head;
   while(temp!=NULL)
   { printf("%d \t",temp->data);
     temp=temp->next;
   }
   printf("\n");
 	
 }
 void insertion_sort()
 {
 	node *temp=head->next;
 	node *temp2;
 	int e,pass=0;
 	while(temp!=NULL)
 	{   temp2=temp->prev;
 	     e= temp->data;
 		while(temp2!=NULL && temp2->data > e )
 		{
 			temp2->next->data = temp2->data;
 			temp2=temp2->prev;
		 }
		 if(temp2==NULL)
		 {
		 	head->data = e;
		 }
		 else
		 temp2->next->data =e;
		 printf("Pass %d   = \t ",++pass);
		 disp();
	 	temp=temp->next;
	 }
 	
 } 
 void display_odd_even()
 { 
 	node *temp=head;
 	int c=1;
 	printf("Odd position elements \n");
 	while(temp!=NULL)
 	{ if(c%2 !=0)
 	   printf("%d \t",temp->data);
 	   temp=temp->next;
 	   c++;
	 } 
	 printf("\n");
	 printf("Even position elements \n");
	 temp=head;
	 c=1;
	 while(temp!=NULL)
 	{ if(c%2 ==0)
 	   printf("%d \t",temp->data);
 	   temp=temp->next;
 	   c++;
	 }
	  printf("\n-------------------------------------------------------------\n");
 } 
 void delete_last()
 {
 	if(head==NULL && last==NULL)
 	{ printf("List empty\n");
 	  return;
	 }
 	else if(head==last)
 	{  printf("deleted element = %d\n",head->data);
 		head=last=NULL;
 		return ;
	 }
	 node * temp=last;
 	int e =temp->data;
 	last->prev->next=NULL;
 	last=last->prev;
 	free(temp);
 	printf("deleted element = %d\n",e);
 	
 }
 void delete_first()
 {
 	if(head==NULL && last==NULL)
 	{ printf("List empty\n");
 	  return;
	 }
 	else if(head==last)
 	{  printf("deleted element = %d\n",head->data);
 		head=last=NULL;
 		return ;
	 }
	 node * temp = head;
	 int e = temp->data;
	 head = head->next;
	 head->prev = NULL;
	 free(temp);
	 printf("Element deleted = %d\n",e);
 }
 int main()
 {  printf("-------------------------------------LINKED LIST 2247244 Bidura Sarkar -------------------------------------\n");
 	 int ch2;
 	 char ch;
 	 while(1)
 	 {  printf("Enter A to enter elements in linked list\nEnter B to enter elements from the first of the list\nEnter C to sort list\nEnter D to delete element from last\nEnter E to delete element from first\nEnter F to display list\nEnter G to display elements at odd and even position in the list\nEnter H to exit\n ");
 	   	   printf("\n--------------------------------------------------\n");
 	   
		 fflush(stdin);
		 scanf("%c",&ch);
 	    while(!(ch>='A' && ch<='Z'))
 	    { printf("Enter A to enter elements in linked list\nEnter B to enter elements from the first of the list\nEnter C to sort list\nEnter D to delete element from last\nEnter E to delete element from first\nEnter F to display list\nEnter G to display elements at odd and even position in the list\nEnter H to exit\n ");
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
			 	insertion_sort();
			 	break;
			 case 'D':
			 	delete_last();
			 	break;
			 case 'E':
			 	delete_first();
			 	break;
			 case 'F':
			 	disp();
			 	break;
			 case 'G':
			 	display_odd_even();
			 	break;
			 case 'H':
			 	exit(0);
			 default:
			 	printf("Wrong choice\n");
			 
		}
	  }
	  return 0;
 }

