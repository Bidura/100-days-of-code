#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int *a,len,pass=0;
void quick_sort(int *a,int l,int u)
{  int first,second,pivot,temp,i;
	if(l<u)
	{  first = l+1;
	    pivot=a[l];
	   for(second=l+1;second<=u;second++)
	   {
			if(a[second]<pivot) 
			{
				 temp = a[second];
				a[second]=a[first];
				a[first]=temp;
				first++;
			}  	
	   	
	   }
	   a[l]=a[first-1];
	   a[first-1]=pivot;
	    printf("After pass %d \n",++pass);
	    getche();
	  for(i=0;i<len;i++)
	    printf("%d\t",a[i]);
	    printf("\nThe pivot has reached the correct index \n");
	  printf(" Dividing \n");
	  printf("First part: ");
	   for(i=l;i<=first-2;i++)
	    printf("%d\t",a[i]);
	    printf("\t\t");
	     printf("\n\nSecond part: ");
	   for(i=first;i<=u;i++)
	    printf("%d\t",a[i]);
	    printf("\n------------------------------------------\n\n");
	  quick_sort(a,l,first-2);
	  quick_sort(a,first,u);
		  
	}
	
}

int main()
{
	int ch,upper,lower,i;
	printf("_______________QUICK SORT________________________________\n");
	while(1)
	{
		printf("Enter 1 to generate the array, 2 to sort the array , 3 to exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter array length = ");
				scanf("%d",&len);
				a=(int *)malloc(sizeof(int)*len);
				printf("Enter upper limit of range \n");
				scanf("%d",&upper);
				printf("Enter lower limit of range \n");
				scanf("%d",&lower);
				srand(time(0));
				for(i=0;i<len;i++)
				 a[i]=rand()%(upper-lower+1) + lower;
				printf("The actual array \n");
				for(i=0;i<len;i++)
				  printf("%d\t",a[i]);
				printf("\n");
				break;
			case 2:
				pass=0;
				quick_sort(a,0,len-1);
				printf("The sorted array \n");
				for(i=0;i<len;i++)
				  printf("%d\t",a[i]);
				printf("\n");
				break;
			case 3:
				exit(0);
			default:
				printf("Wrong choice try again\n");
				
							
		}
	}
	return 0;
}
