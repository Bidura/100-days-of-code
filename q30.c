#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "merge.h"
int median(int **matrix, int R, int C) {
        // code here    
        int *a = (int*)malloc(sizeof(int)*R*C);
        int i,j,k=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                a[k++]=matrix[i][j];
            }
        }
        merge_sort(a,0,R*C-1);
        if((R*C)%2!=0)
        return a[(R*C)/2];
         
        
    
}
int main()
{
	int i,j,R,C;
	int **matrix;
	printf("enter no of rows\n");
	
	scanf("%d",&R);
	printf("Enter no of columns\n");
	scanf("%d",&C);
	matrix=(int**)malloc(sizeof(int*)*R);
	for(i=0;i<R;i++)
        {  	*(matrix+i) = (int*)malloc(sizeof(int)*C);
            for(j=0;j<C;j++)
            {   printf("Enter element at %d %d\n",i,j);
                scanf("%d",&matrix[i][j]);
            }
        }
    printf("Median element %d\n",median(matrix,R,C));
    return 0;
}
