#include<stdlib.h>
#include<stdio.h>
int *stack,top=-1,n;
int isemptys()
{ 
  if(top==-1)
    return 1;
   else 
     return 0;
}
void push(int e)
{
  
  if(top == n-1)
   printf("Stack overflow\n");
   else
   stack[++top] =e ;
}
int peek()
{ return stack[top];
}
int pop()
{ int e=-1;
  if(top!=-1)
   { e=stack[top--];
   }
   else
   printf("Stack underflow\n");
   return e;
}
void display()
{  int i;
	for(i=0;i<=top;i++)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n");
}
int main()
{   char ch,e;
    printf("_____________STACK______________________\n");
    printf("enter maximum size of stack\n");
    scanf("%d",&n);
    stack=(int*)malloc(sizeof(int)*n);//dynamic memory allocation
    while(1)
    {
    	printf("enter a to push element into stack,\nenter b to pop element into stack,\nenter c to peek at stack top\nenter d to check if stack is empty\nenter e to check if display stack contents\nenter f to exit\n ");
    	fflush(stdin);
		scanf("%c",&ch);
		while(!(ch>='a' && ch<='z'))
    	{ 
    	   printf("enter a to push element into stack,\nenter b to pop element into stack,\nenter c to peek at stack top\nenter d to check if stack is empty\nenter e to check if display stack contents\nenter f to exit\n ");
    	   fflush(stdin);
	       scanf("%c",&ch);
		}
		switch(ch)
		{
			case 'a':
				printf("Enter element to enter into stack or enter -1 to quit entering element\n");
				scanf("%d",&e);
				
				while(e!=-1)
				{ push(e);
				printf("Enter element to enter into stack or enter -1 to quit entering element\n");
				scanf("%d",&e);
				
				}
				break;
			case 'b':
				printf("Popped element = %d\n",pop());
				break;
			case 'c':
				printf("Element at stack top = %d\n",peek());
				break;
			case 'd':
				if(isemptys())
				printf("Stack is empty!\n");
				else
				printf("Stack is not empty\n");
				break;
			case 'e':
				display();
				break;
			case 'f':
				exit(0);
			default:
				printf("wrong choice try again\n");
				
		}
	}
	return 0;
}
