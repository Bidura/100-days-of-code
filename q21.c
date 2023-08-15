#include<stdio.h>
#include<stdlib.h>
int main()
{ int TC,count,len,*a,i,minc,pc,k,sum,c;
  printf("Enter number of test cases \n");
  scanf("%d",&TC);
  while(TC--)
  { printf("enter no of paratas needed\n");
    scanf("%d",&count);
    printf("enter no  of chefs available\n");
    scanf("%d",&len);
    a = (int*)calloc(sizeof(int),len);
   
	minc =1 ;
	while(1)
	{
	   pc=0;
	   for(i=0;i<len;i++)
	   { if(a[i]==0)
	     {printf("enter rank of chef %d    ",i);
    	 scanf("%d",&a[i]);
		 }
	   	 k=a[i];sum = k; c=1;
	   	  while(sum<=minc)
	   	   {
	   	   	 if(k % a[i]==0)
	   	   	   pc++;
	   	   	 if(pc >= count)
	    {
	    	
	    	break;	
		}
	   	   	   c++;
	   	   	   k = a[i]*c; //generating the next geometric progression term 
	   	   	  sum=sum+k;
			  }
	   	
	   }

	  
	   if(pc >= count)
	    {
	    	printf("min time  =  %d\n",minc);
	    	break;	
		}
		else
		minc++;
	
	}
  	
  }
	
	
	
	
	
	
	
	return 0;
	
}
