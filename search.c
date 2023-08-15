#include<stdio.h>
#include<stdlib.h>
#include"merge.h"
int len,*a;
int linear_search(int *a,int e)
{
	int i;
	for(i=0;i<len;i++)
	{ if(e==*(i+a))
	   return (i);
	}
	return -1;
}
int binary_search(int *a,int l, int u,int e)
{
	int mid = (l+u)/2;
	if(l>u)
	{ return -1;
	}
	else if(mid[a] == e)
	{ 
	  return (mid);
	}
    else if(mid[a]<e)
    {
    	return binary_search(&a[0],mid+1,u,e);
	}
	else if(mid[a]>e)
	{
			return binary_search(a,l,mid-1,e);
	}
	
}
int main()
{  char ch;
   int e,temp=0,i,j,lower,upper;
   printf("-------------------Searching elements in array ---------------------\n");
   printf("Enter length of the array\n");
   scanf("%d",&len);
   a=(int*)malloc(sizeof(int)*len);
   	
	while(1)
	{ printf("Enter \n	'a' to generate array\n	'b' to implement linear search for the generated number\n	'c' to perform binary search to find the random number\n	'd' to exit\n");
	  fflush(stdin);
	  scanf("%c",&ch);
	switch(ch){
		case 'a':
			
		printf("Enter the upper limit for generating random number\n");
		scanf("%d",&upper);
		printf("Enter the lower limit for generating random number\n");
		scanf("%d",&lower);
	  	i=upper-lower+1;
	  	srand(time(0));
	  	for(j=0;j<len;j++)
	  	{  temp=rand() % i + lower;
	  	    a[j]=temp;
		    
		  } 
		 merge_sort(a,0,len-1);
		  for(j=0;j<len;j++)
	  	  printf("%d \t",a[j]);
	  	  printf("\n");
	  	break;
	 case 'b':
	 	printf("Enter a number within the given range to search within an array \n");
	 	scanf("%d",&e);
	 	while(e<lower || e>upper)
	 	{ printf("Enter a number within the given range !\n");
	 	  	scanf("%d",&e);	
		 }
	 	if(i=linear_search(a,e)+1)
	 	  printf("Element found at position = %d\n",i-1);
	 	else
	 		 printf("Element not found\n");
	 	break;
	 case 'c':
	 	printf("Enter a number within the given range to search within an array \n");
	 	scanf("%d",&e);
	 	while(e<lower || e>upper)
	 	{ printf("Enter a number within the given range !\n");
	 	  	scanf("%d",&e);	
		 }
	 	if(i=binary_search(a,0,len-1,e)+1)
	 	  printf("Element found at position = %d\n",i-1);
	 	else
	 		 printf("Element not found\n");
	 	break;
	 case 'd':
	 	exit(0);
	}
	}
	return 0;
}

	  
	 
	 
	  
	  	
		
	

