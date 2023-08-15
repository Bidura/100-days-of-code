//matrix multiplication
//the number of columns of the first matrix should match the number of columns of the second matrix

#include<stdio.h>
#include<stdlib.h>

int **mat1, **mat2, **mat3;
int r1,c1,r2,c2,r3,c3;

void assign(int **mat,int r,int c)
{  int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter element at row %d and col %d\n",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
}

void display(int **mat,int r,int c)
{  int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

void multiply()
{ 	int i,j,k;
	if(c1!=r2)
	{ printf("Multiplication not possible\n");
	  return;
	 } 
	mat3 =(int**)malloc(sizeof(int*)*r1);

	for(i=0;i<r1;i++)
	{ *(mat3+i) = (int*)calloc(sizeof(int),c2);
	}
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<c1;k++)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
		
	}
	 
}
int main()
{   int i,j;
	printf("enter number of rows of matrix 1\n");
	scanf("%d",&r1);
	printf("enter number of columns of matrix 1\n");
	scanf("%d",&c1);
	printf("entering elements into matrix1\n");
	mat1=(int**)malloc(sizeof(int*)*r1);
	for(i=0;i<r1;i++)
	*(mat1+i) = (int*)malloc(sizeof(int)*c1);
	assign(mat1,r1,c1);
	printf("Matrix 1 \n");
	display(mat1,r1,c1);
	printf("enter number of rows of matrix 2\n");
	scanf("%d",&r2);
	printf("enter number of columns of matrix 2\n");
	scanf("%d",&c2);
	printf("entering elements into matrix 2\n");
	mat2=(int**)malloc(sizeof(int*)*r2);
	for(i=0;i<r2;i++)
	*(mat2+i) = (int*)malloc(sizeof(int)*c2);
	assign(mat2,r2,c2);
	printf("Matrix 2 \n");
	display(mat2,r2,c2);
	
	multiply();
	printf("Resultant matrix after multiplication\n");
	display(mat3,r1,c2);
	
	return 0;
}

