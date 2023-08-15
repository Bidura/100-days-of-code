#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int n,**adj,*visited,*parent;
void create_graph()
{ int i,j,ch,num,ch2;
  for(i=0;i<n;i++)
  { adj[i]=(int*)malloc(sizeof(int)*n);
  	for(j=0;j<n;j++)
  	{  
  	   adj[i][j]=-99;	
	}
  }
  ch=0;
  printf("Enter the total number of edges \n");
  scanf("%d",&num);
   printf("Enter 0 if the graph is directed and 1 if undirected \n");
    scanf("%d",&ch2);
  while(ch != num)
  { printf("Edge no = %d\n",ch+1);
  	printf("enter source = ");
  	scanf("%d",&i);
  	printf("Enter destination = ");
  	scanf("%d",&j);
  	printf("Enter the cost = ");
  
  	scanf("%d",&adj[i][j]);
  		if(ch2)
  		adj[j][i]=adj[i][j];
  	ch++;
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{ if(adj[i][j]!=-99)
	  printf("%d\t",adj[i][j]);
	  else
	  printf("o\t");
	  }
  	printf("\n");
  }
  
  
}
int minedge(int *a)
{   int min =-99,j;
	for(j=0;j<n;j++)
	{  if(a[j]!=-99 && visited[j]!=1)
	        { min =a[j];
	          break;
			}
	}
	for(j=0;j<n;j++)
	{
		if(a[j]!=-99 && visited[j]!=1 && a[j]<min)
		{min =a[j];
		}
	}
	return min;
}
void MST()
{   int count=1;
	visited[0]=1;
	parent[0]=-1;
	int i,j,k,m;
	m = minedge(adj[0]);
	i=0;
	printf("finding out minimal spanning tree\n");
	while(count < n)
	{  for(j=0;j<n;j++)
	    {
	    	 if(adj[i][j]==m && visited[j]==0)
	    	 {
	    	 	visited[j]=1;
	    	 	printf("%d --- %d ----> %d \n",i,adj[i][j],j);
	    	 	adj[i][j]=-99;
	    	 	//parent[j]=i;
	    	 	count++;
	    	 	break;
			 }
		}
	
		if(count==n)
		break;
		
		//finding out the minimum edge from the visited nodes
		m=-99;
		getche();		
		for(k=0;k<n;k++)
		{ if(visited[k]==1)
		   {  m = minedge(adj[k]);
		      if(m!=-99)
		      break;//at first we consider any edge (which doesnt form a loop) as the minimum edge to traverse next
		   }
		}
		i=k;
		
		for(k=0;k<n;k++)
		{  
		    if(visited[k]==1)
		    { while(minedge(adj[k])!=-99 && minedge(adj[k])<m)
		      { m = minedge(adj[k]); //then we check in the visited nodes for an edge which has lesser cost than the previous edge
		        i=k;
			  }
			}
		} 
		
		getche();
		
		
	}
	
	
}
int main()
{
  printf("Enter the number of nodes\n");
  scanf("%d",&n);
  visited = (int*)calloc(sizeof(int),n);
  //parent = (int*)malloc(sizeof(int)*n);
  adj=(int**)malloc(sizeof(int*)*n);

  create_graph();
  MST();
  return 0;
}
