//stack using linked list
#include<stdio.h>
#include<stdlib.h>
int len,count=1;
typedef struct node
{ int data;
  struct node *next;
}Node;
Node *head=NULL;
void push(int e)
{ //insert at first.
Node *temp=malloc(sizeof(Node));
temp->data=e;
temp->next=NULL;

  temp->next=head;
  head=temp;
}
int pop()
{  
   if(head==NULL)
   { printf("Stack underflow\n");
     return -99;
   }
   else if(head->next==NULL)
   {  Node *temp = head;
   		head=head->next;
   		return temp->data;
   }
   else{
   Node *temp = head;
   int e=temp->data;
   head=head->next;
   free(temp);
   return e;
  }
  
}
void display()
{ Node *temp=head; 
  while(temp != NULL)
  { printf("%d \t",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
int main()
{ 
  int ch,e;
  while(1)
  { 
    printf("Enter \n	1 to push element in stack\n	2 to pop element from stack\n	3 to display stack elements\n	4 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    { 
      case 1:
      	printf("Enter element\n");
      	scanf("%d",&e);
      	push(e);
      	break;
      case 2:
      	printf("Deleted element = %d\n",pop());
      	break;
     case 3:
     	display();
     	break;
    case 4:
    	exit(0);
     default:
     	printf("Wrong choice, try again\n");
     	
	}
  }
  return 0;
}
