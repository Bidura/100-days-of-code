#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{ int TC,count,len,*a,i,minc,k,sum,c;
  double pc;
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
	   pc=0.0;
	   for(i=0;i<len;i++)
	   { if(a[i]==0)
	     {printf("enter rank of chef %d    ",i);
    	 scanf("%d",&a[i]);
		 }
	   	pc = pc +  (-1 + (int)(sqrt(1+4*2*minc/a[i])))/2 ;
	   	
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
