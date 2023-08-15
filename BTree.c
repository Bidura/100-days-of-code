
//creation of a B Tree
// if order of B Tree is m
// max no of keys = m-1
//max no  of children = m
//min no of keys = m/2 -1
//min no of children  = m/2
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int m;
typedef struct node
{
	int data;
	struct treenode *left;
	struct treenode *right;
}node;

typedef struct treenode
{
	node *keys[4];
	int count;
	
}treenode;

treenode *root = NULL;

treenode* createBTree(treenode *Root,int e)
{  int i,val;
	node* temp = (node*)malloc(sizeof(node));
	temp->data =e;
	temp->left = temp->right = NULL;
	if(Root == NULL)
	{
		Root = (treenode*)malloc(sizeof(treenode));
		Root->keys[0] = temp;
		Root->count=0;
		return Root;
	}
	else
	{
		if(Root->count < 4)
		{
		  for(i=Root->count; i >=0 && e < Root->keys[i]->data ; i--)
		  {
		  	  Root->keys[i+1] = Root->keys[i];
			 
		  }
		  Root->keys[i+1] = temp;
		  Root->count += 1;
		  //inserting the new element in the correct position to maintain ascending order
		}
		else if(Root->count == 4)
		{   val = Root->keys[2]->data;
			for(i=0;i<2;i++)
			{
				Root->keys[2]->left = createBTree(Root->keys[2]->left,Root->keys[i]->data); 
			}
			Root->keys[2]->right = createBTree(Root->keys[2]->right,Root->keys[3]->data); 
			Root = (treenode*)malloc(sizeof(treenode));
			Root->keys[0]->data = val;
			Root->keys[0]->left = Root->keys[0]->right = NULL;
			Root->count=0;
			
		}
		
	}
	return Root;
}




int main()
{   int e;
	while(1)
	{
		printf("To discontinue entering data press 0 else enter 1\n");
		scanf("%d",&e);
		if(e==0)
		break;
		printf("enter data\n");
		scanf("%d",&e);
		root = createBTree(root,e);
		
	}
	
	return 0;
}

