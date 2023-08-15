
#include<stdlib.h>
#include<stdio.h>
typedef struct node_tree
{
	int val;
	struct node_tree *left;
	struct node_tree *right;
	
	
 } node;
 
 node *root = NULL;
 
 node* create_BST(node *Root,int data)
 {  node *temp = malloc(sizeof(node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
 	if(Root==NULL)
 	{
 		Root = temp;
 	    return Root;	
 	
	 }
	else if(data < Root->val)
	{
	 Root->left= create_BST(Root->left,data);
	}
	else
	{
	 Root->right= create_BST(Root->right,data);	
	}
	
	return Root;
	
 }

 void preorder(node *Root)
 {
 	if(Root != NULL)
 	{ printf("%d ",Root->val);
 	  preorder(Root->left);
 	  preorder(Root->right);
 	
	  } 
 	
	
 }
 
 void inorder(node* Root)
 {
 	if(Root != NULL)
 	{ inorder(Root->left);
	  printf("%d ",Root->val);
 	  preorder(Root->right);
 	
	  }	
 }
 
 void postorder(node* Root)
 {
 	if(Root!=NULL)
 	{
 		postorder(Root->left);
 		postorder(Root->right);
 		printf("%d ",Root->val);
	 }
 }
 
 void search(node *Root,int data)
 {  
    if(Root== NULL)
     printf("Element not found");
 	else if(Root->val == data)
 	  printf("Value found !\n");
 	else if(Root->val > data)
 	   search(Root->left,data);
 	else if(Root->val < data)
 	   search(Root->right,data);
 }
 
 int main()
 {
 	char ch,ch2;
	 int data;
 	while(1)
 	{
 		printf("\nEnter 1 to create BST, 2 to traverse inorder, 3 to traverse preorder, 4 to traverse postorder, 5 to exit,  6 to search\n");
 		fflush(stdin);
 		scanf("%c",&ch);
 		while(1)
 		{
 			 				
 			if(isdigit(ch)!=0)
 			break;
 			fflush(stdin);
 			scanf("%c",&ch);
		 }
 		switch(ch)
 		{
 			case '1':
 				while(1){
 					
 					printf("enter data\n");
 				    scanf("%d",&data);
 				    root=create_BST(root,data);
 					printf("Enter 0 to stop taking data and 1 to continue \n");
 					fflush(stdin);
 					scanf("%c",&ch2);
 					while(1)
 						{
 			 				
 								if(isdigit(ch2)!=0)
 								break;
 								fflush(stdin);
 								scanf("%c",&ch2);
						 }
 					if(ch2 == '0')
 					break;
 					
				 }
 				
 				
 				break;
 			case '2':
 				inorder(root);
 				break;
 			case '3':
 				preorder(root);
 				break;
 			case '4':
 				postorder(root);
 				break;
 			case '5':
 				exit(0);
 			case '6':
 				printf("Enter element to search \n");
 				scanf("%D",&ch2);
 				search(root,ch2);
 			    break;
 			default:
 				printf("Wrong ch!\n");
 	    }
		 }
return 0;
	 }

