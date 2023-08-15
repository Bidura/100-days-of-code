#include<stdio.h>
#include<stdlib.h>
int len,prod;
int *a,*b;
int main()
{   int i,j,n;
    printf("Enter array length\n");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    b =(int*)malloc(sizeof(int)*n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
     { printf("Enter element at index = %d   \n",i);
	   scanf("%d",(i+a));
	  } 
	  
	for(i=0;i<n;i++)
	{  prod=1;
	  for(j=0;j<n;j++)
	   { if(i!=j)
	       prod *= a[j];
	   }
	   b[i]=prod;
	}
	printf("Output \n");
     for(i=0;i<n;i++)
     { 
	   printf("%d\t",*(i+b));
	  } 
	  return 0;
}
