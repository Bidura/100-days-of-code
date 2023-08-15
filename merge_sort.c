#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *temp,*a,len, var=0;

void merge(int l1,int u1,int l2,int u2)
{ int k=0;
  int i=l1;
  temp=(int*)malloc(sizeof(int)*(u2-l1+1));
  while(l1 <= u1 && l2<=u2)
  { 
     if(a[l1]<a[l2])
      temp[k++]=a[l1++];
     else if(a[l1]>a[l2])
      temp[k++]=a[l2++];
     else
     	{
     		temp[k++]=a[l1++];
     		temp[k++]=a[l2++];
		 }
	 
  }
   while(l1 <= u1 )
   	 temp[k++]=a[l1++];
   while(l2 <= u2)
   	 temp[k++]=a[l2++];
   	 
      
     k=0;
   for(;i<=u2;i++)
   {   
      a[i]=temp[k++];
       printf("%d\t",a[i]);
   }
   printf("\n");
  
  
}

void merge_sort(int l,int u)
{ int mid,i;
   if(l<u)
   { mid=(l+u)/2;
      printf("Dividing ..........\n");
      for(i=l;i<=mid;i++)
      { printf("%d\t",a[i]);
	  }
	  printf("         ");
	  for(i=mid+1;i<=u;i++)
      { printf("%d\t",a[i]);
	  }
	  printf("\n\n");
	 
	 
      merge_sort(l,mid);
      merge_sort(mid+1,u);
      merge(l,mid,mid+1,u);
      printf(" Pass %d done\n",++var); 
   }
   if(l==u)
    printf("%d\n",a[l]);
   
}


   int main()
   { 
      int ch,i;
      printf("-----------------SORT------O(nlogn)----------------\n");
      while(1){
      	var =0;
      	printf("Enter 1 to enter an array , 2 to sort the array, 3 to exit \n");
        scanf("%D",&ch);
        while(!(ch>=0 && ch<=10))
        {    printf("Enter 1 to enter an array , 2 to sort the array, 3 to exit \n");
             fflush(stdin);
        	 scanf("%d",&ch);
		}
		switch(ch)
		{  
		   case 1:
		   	printf("Enter the array length\n");
		   	scanf("%d",&len);
		   	srand(time(0));
		   	a=(int*)malloc(sizeof(int)*len);
		   	for(i=0;i<len;i++)
		   	  a[i]=rand() % 100;
		   	printf("The array is  = \n");
		   	for(i=0;i<len;i++)
		   	 printf("%d\t",*(i+a));
		   	printf("\n");
			break;
			
		   case 2:
		   	merge_sort(0,len-1);
		   	printf("The sorted array is  = \n");
		   	for(i=0;i<len;i++)
		   	 printf("%d\t",*(i+a));
		   	printf("\n");
		   	break;
		  
		  case 3:
		  	exit(0);
		  	
		   default:
		   	printf("Wrong choice,try again\n");			 
		   	  
		  }      	
	  }
   }

