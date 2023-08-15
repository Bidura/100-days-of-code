#include<stdlib.h>
#include<stdio.h>
int **adj,*queue,*visited,rear=-1,front=-1,n,top=-1,*stack;
void create_graph()
{ int ne,ch,i,s,d;
  printf("Enter the number of edges \n");
  scanf("%d",&ne);
  printf("Enter 1 if undirected graph and 0 if directed\n");
  scanf("%d",&ch);
  for(i=0;i<ne;i++)
  {
  	printf("Edge number %d\n",i+1);
  	printf("Enter source = ");
  	scanf("%d",&s);
  	printf("Enter destination = ");
  	scanf("%d",&d);
  	adj[s][d]=1;
  	if(ch==1)
  	adj[d][s]=1;
  	
  }
  
}
int isemptys()
{ 
  if(top==-1)
    return 1;
   else 
     return 0;
}
void push(int e)
{
  if(top < n)
  { stack[++top] =e ;
	  }	
}
int peek()
{ return stack[top];
}
int pop()
{ int e;
  if(top!=-1)
   { e=stack[top];
     top--;
      return e;
   }
}
void DFS()
{ int v,flag,start;
  printf("Performing Depth First Search of a graph\n");
  visited=(int*)calloc(sizeof(int),n);
  printf("Enter the root node\n");
  scanf("%d",&start);
   visited[start]=1;
    push(start);
    printf("%d\t",start);
	while(!isemptys())
	{  int i;
		v = peek();
	
		flag=0;
		for(i=0;i<n;i++)
		  { 
		    if(visited[i]==0 && adj[v][i]==1)
		        { push(i);
		          visited[i]=1;
		          printf("%d\t",i); //whenever we visit a node, we print its value 
		          flag=1; //indicates that this node has got unvisited edges.
		          break;
				}
				
		  }
		    if(flag==0)
		     v=pop(); //indicates that the node has no unvisited edges hence we remove it from the stack.
	}
	printf("\n");
}

int isempty()
{ if(front==-1 && rear==-1)
  return 1;
  return 0;
}
int dequeue()
{ int e;
	if(!(front==-1 && rear==-1))
	{  
	  if(front==rear)
	    { e = queue[front];
	      
	      front=rear=-1;
		}
	  else
	   {  e=queue[front];
	      
	      front++;
		} 
		return e;
	}
	return -1;
}

void enqueue(int e)
{ if(rear==-1 && front==-1)
   front++;
  if(rear<n)
  {
  	 queue[++rear]=e;
  }
}

void BFS()
{   int root,i,v;
    printf("Performing BFS\n");
    visited=(int*)calloc(sizeof(int),n);
    printf("enter the root node \n");
    scanf("%d",&root);
    visited[root]=1;
    enqueue(root);
    printf("%d\t",root);
    while(!isempty()){
	 v = dequeue();
     for(i=0;i<n;i++) 
	 	{
		 if(adj[v][i]==1 && visited[i]==0)
		    { visited[i]=1;
		      enqueue(i);
		      printf("%d\t",i);
			}
		}
		
	}
	printf("\n");
}
	 	
int main()
{ int i,j,ch;
  printf("Enter no of nodes \n");
  scanf("%d",&n);
  adj=(int**)malloc(sizeof(int*)*n);
  queue=(int*)malloc(sizeof(int)*n);
  stack=(int*)malloc(sizeof(int)*n);
  visited = (int*)calloc(sizeof(int),n);
  for(i=0;i<n;i++)
  { adj[i]=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++)
      {adj[i][j]=-99;
      if(i==j)
      adj[i][j]=0;
	  }
  }
  while(1)
  {
  	printf("Enter 1 to create graph, 2 to perform DFS, 3 to perform BFS, 4 to print the adjacency matrix, 5 to exit\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  		case 1:
  			create_graph();
  			break;
  		case 2:
  			DFS();
  			break;
  		case 3:
  			BFS();
  			break;
  		case 4:
  			for(i=0;i<n;i++)
  			{ 
   				 for(j=0;j<n;j++)
      		      printf("%d\t",adj[i][j]);
      		    printf("\n");
  			}
  			break;
  		case 5:
  			exit(0);
  		default:
  			printf("Wrong choice\n");
  			
	  }
  }
  return 0;
}

