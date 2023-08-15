#include<stdio.h>
#include<stdlib.h>
int *table,size;
int delete1(int element)
{  int e;
   if(table[element % size]==element)
     { e = table[element % size];
       table[element % size] = -1;
       return e;
	 }
   else
    { printf("Element absent in hash table !\n");
      return -1;
	}
	 
} 
void init()
{ int i;
	for(i=0;i<size;i++)
	table[i]=-1;
}
void insert(int element)
{   int temp;
    if(table[element % size]== -1)
     table[element % size] = element;
     
    else
    { printf("Collision ! \n Applying linear probing \n");
	 temp = element % size + 1;
	  while(table[temp % size] != -1 && temp % size != element % size )
	   temp++;
	 if(temp % size == element % size)
	 printf("No more elements can be inserted \n");
	 else
	 table[temp%size]=element;  
       
	}
   

}
void search(int element)
{   int temp;
	if(table[element % size]==element )
	printf("Element found at position %d\n",element%size);
	else //since linear probing is used we search at later positions.
	{  temp = element % size + 1;
	  while(table[temp % size] != element && temp % size != element % size )
	   temp++;
	 if(temp % size == element % size )
	 printf("Element is absent\n");
	 else
	 printf("element found at position %d\n",temp%size);
		
	}
}

void print()
{
	 int i;
	 for(i=0;i<size;i++)
	 printf("%d\t",table[i]);
	 printf("\n");
	 
}
int main()
{ int ch,e;
 printf("Enter size of hash table \n");
 scanf("%d",&size);
 table = (int*)malloc(sizeof(int)*size);
 init();
   while(1)
   { 
      printf("Enter 1 to insert , 2 to delete , 3 to search , 4 to print and 5 to exit\n");
      scanf("%d", &ch);
      switch(ch)
      {
      	case 1:
      		printf("enter element to insert \n");
      		scanf("%d",&e);
      		insert(e);
      		break;
      	case 2:
      		printf("enter the element to be deleted from the table\n");
      		scanf("%d",&e);
      		printf("element deleted  = %d\n",delete1(e));
      		break;
      	case 3:
      		printf("enter the element to be searched in the table\n");
      		scanf("%d",&e);
      		search(e);
      		break;
      	case 4:
      		print();
      		break;
      	default :
      		printf("Wrong choice \n");
      		break;
      	case 5:
      		exit(0);
      	
      		
	  }
   }
return 0;
}

