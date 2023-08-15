#include<stdio.h>
#include<stdlib.h>
int *a,*b,len,i,j,temp,key;
int a1[10] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
void bubble()
{ int flag=1;
 for(i=0;i<=len-2 ;i++)
 { 
   for(j=0;j<len-1-i;j++)
   {  
      if(a[j]>a[j+1])
      { temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       
	  }
   }
   printf("Pass %d ",i+1);
   for(j=0;j<len;j++)
   	printf("%d\t",a[j]);
   printf("\n");
 }
 
 
}
void selection()
{  
  for(i=0;i<=len-2;i++)
 { 
    for(j=i+1;j<=len-1;j++)
    { 
       if(a[i]>a[j])
       { temp=a[i];
         a[i]=a[j];
         a[j]=temp;
	   }
	}
	 printf("Pass %d ",i+1);
   for(j=0;j<len;j++)
   	printf("%d\t",a[j]);
   printf("\n");
}
}
void insertion()
{ 
   for(i=1;i<=len-1;i++)
   {   key=a[i];
      for(j=i-1;j>=0 && a[j]>key;j--)
      { a[j+1]=a[j];
	  }
	  a[j+1]=key;
	    printf("Pass %d ",i);
   		for(j=0;j<len;j++)
   			printf("%d\t",a[j]);
   		printf("\n");
   }
}

int main()
{
	 int ch,upper,lower;

	 while(1)
	 { printf("Enter 0 to enter array elements manually\nEnter 1 to enter array elements\nEnter 2 to perform bubble sort\nEnter 3 to perform Selection sort\nEnter 4 to perform Insertion Sort\nEnter 5 to reset array\n ");
	   scanf("%d",&ch);
	   switch(ch)
	   { case 0:
	   	   printf("Enter array length\n");
	   	   scanf("%d",&len);
	   	   a=(int*)malloc(sizeof(int)*len);
	   	   for(j=0;j<len;j++)
	   	   {
	   	   	 printf("enter element %d  ",j+1);
	   	   	 scanf("%d",&a[j]);
			  }
			break;
	     case 1:
	     		 printf("Enter upper limit of range\n");
				 scanf("%d",&upper);
	 			 printf("Enter lower limit of range\n");
				 scanf("%d",&lower);
				 i=upper-lower+1;
	   	   printf("Enter array length\n");
	   	   scanf("%d",&len);
	   	   a=(int*)malloc(sizeof(int)*len);
	   	   for(j=0;j<len;j++)
	   	   { a[j]=rand()%i+lower;
			  }
			printf("Actual array\n");
			 for(j=0;j<len;j++)
	   	   { printf("%d\t",a[j]);
			  }	
			printf("\n");
			break;
		 case 2:
		 	bubble();
		 	break;
		 case 3:
		 	selection();
		 	break;
		 case 4:
		 	insertion();
		 	break;
		 case 5:
		 	for(i=0;i<len;i++)
		 	a[i]=a1[i];
			 break;
		 default:
		 	exit(0);
	}
}
return 0;
}
	   	 
	
