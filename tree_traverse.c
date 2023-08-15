
#include<stdlib.h>
#include<stdio.h>
typedef struct node_tree
{
	int val;
	struct node_tree *left;
	struct node_tree *right;
	
	
 } node;
 
 node *root = NULL;
 
 
  node* create_tree(node *Root,int data)
 {  node *temp = malloc(sizeof(node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    int ch;
 	if(Root==NULL)
 	{
 		Root = temp;
 	    return Root;	
 	
	 }
	 else{
	 	printf("Enter 1 if %d is to left of %d\nEnter 2 if %d is to right of %d\n",data, Root->val,data,Root->val);
	 	scanf("%d",&ch);
	 if(ch==1)
	{
	 Root->left= create_tree(Root->left,data);
	}
	else if(ch==2)
	{
	 Root->right= create_tree(Root->right,data);	
	}
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
 
      if(Root != NULL)
 	{ if(Root->val == data)
 	     printf("Value found\n");
 	     else{
 	     	search(Root->left,data);
 	  		search(Root->right,data);
		  }
 	  
 	
	  } 
	  
    
 }  
 
 
 int main()
 {
 	int ch,ch2,data;
 	while(1)
 	{
 		printf("\nEnter 1 to create tree, 2 to traverse inorder, 3 to traverse preorder, 4 to traverse postorder, 5 to exit,  6 to search\n");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:
 				while(1){
 					
 					printf("enter data\n");
 				    scanf("%d",&data);
 				    root=create_tree(root,data);
 					printf("Enter 0 to stop taking data and 1 to continue \n");
 					scanf("%D",&ch2);
 					if(!ch2)
 					break;
 					
				 }
 				
 				
 				break;
 			case 2:
 				inorder(root);
 				break;
 			case 3:
 				preorder(root);
 				break;
 			case 4:
 				postorder(root);
 				break;
 			case 5:
 				exit(0);
 			case 6:
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

