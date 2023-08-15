//Q2, Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
//The task is to check whether a2[] is a subset of a1[] or not. Both arrays can be sorted or unsorted.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int *a1,*a2,n,m,i,j,flag;
	while(1){
	printf("Enter size of first array\n");
	scanf("%d",&n);
	printf("Enter size of 2nd(subset)array\n");
	scanf("%d",&m);
	if(m<=n)
	break;
	else if(m>n)
	printf("Subset is smaller or equal in size as superset, invalid input try again !");
	
	}

	a1=(int*)malloc(sizeof(int)*n);
	a2=(int*)malloc(sizeof(int)*m);
	printf("Enter elements of first array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&i[a1]);
	}
	
	printf("Enter elements of 2nd array\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&i[a2]);
	}
	flag=0;
	for(i=0;i<m;i++)
	{ 
	   
		for(j=0;j<n;j++)
		{  if(a2[i]==a1[j])
		      { 
			  flag++;
		      break;
			  }
		} 
		
	}
	
	if(flag==m)
	printf("Yes");
	else
	printf("No");
	return 0;
}
