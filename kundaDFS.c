#include<stdio.h>

int n,adj[100][100],visited[100];

void DFS(int v)
{
int i;
visited[v]=1;
printf("visited node %d \n",v);
  for(i=0;i<n;i++)
    {
      if(visited[i]==0 && adj[v][i]==1)
        {
          DFS(i);
        }
    }
}

int main()
{
int i,j;
printf("Enter the number of vertices\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
 for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
      {
        scanf("%d",&adj[i][j]);
        
      }
   }
for(i=0;i<n;i++)
{
visited[i]=0;
}
printf("\nEnter starting vertex\n");
scanf("%d",&j);

DFS(j);
}
