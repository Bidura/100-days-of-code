//DFS
//both DFS and BFS have the time complexity of O(v+e)
//v->vertices
//e->edges

#include<stdlib.h>
#include<stdio.h>

int **adj,n,*visited,*stack,top=-1;

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

int isempty()
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
{ int v,flag;
  printf("Performing Depth First Search of a graph\n");
   visited[0]=1;
    push(0);
    printf("%d\t",0);
	while(!isempty())
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
}
int main()
{   printf("Enter the number of nodes\n");
    scanf("%d",&n);
    int i,j;
	adj=(int**)malloc(sizeof(int*)*n);
	visited=(int*)calloc(sizeof(int),n);
	stack=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	  { adj[i] = (int*)malloc(sizeof(int)*n);
	    for(j=0;j<n;j++)
	    { adj[i][j]= -99;
		}
	  }
	  create_graph();
	  getche();
	  for(i=0;i<n;i++)
	  { 
	    for(j=0;j<n;j++)
	    { printf("%d\t",adj[i][j]);
		}
		printf("\n");
	  }
	  printf("\n");
	  getche();
	  DFS();
	return 0;
}
