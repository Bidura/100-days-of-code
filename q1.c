//1, Write a program to reverse an array or string
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void reverse_arr(int *a,int size)
{ int i,temp;
 for(i=0;i< size/2;i++)
 {
 	temp = i[a];
 	i[a]=a[size-1-i];
 	a[size-1-i]=temp;
 }
}
void display(int *a,int size)
{ int i;
  for(i=0;i< size;i++)
 {
 	printf("%d\t",*(a+i));
 }	
 printf("\n");
}
int main()
{
	int *a;
	int size,i;
	printf("Enter size of the array\n");
	scanf("%d",&size);
	a=(int*)malloc(sizeof(int)*size);
	printf("Enter array elements one by one");
	for(i=0;i<size;i++)
	{
		scanf("%d",&i[a]);
	}
	printf("Actual array\n");
	display(a,size);
	reverse_arr(&0[a],size);
	printf("Reversed array\n");
	display(a,size);
	return 0;
}
