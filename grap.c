#include<stdio.h>
#include<stdlib.h>
int que[100],visited[100],reach[100];
int a[100][100],n;
int front=-1,rear=-1;
void bfs(int v)
{int i,u;
  visited[v]=1;
  que[++rear]=v;
  while(front<=rear)
  {
    u=que[++front];
    for(i=1;i<=n;++i)
    {
    if(a[u][i]&&!visited[i])
    {
      que[++rear]=i;
      visited[i]=1;
      printf("%d->>",i );
    }
  }
}
}
void dfs(int v)
{
  int i;
  reach[v]=1;
  for(i=1;i<=n;++i)
  {
    if(a[v][i]&&!reach[i])
    {
      printf("%d-->",i);
      dfs(i);
    }
  }
}
void main()
{
  int v,i,j;
  printf("enter the number of vertices\n");
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  for(j=1;j<=n;++j)
  scanf("%d",&a[i][j]);
  printf("enter the vertices you want to strt from\n");
  scanf("%d",&v);
  for(i=1;i<=n;++i)
  {
    que[i]=0;
    visited[i]=0;
    reach[i]=-0;
  }
  printf("the order of bfs: \t");
  bfs(v);
  printf("the order of dfs:\t");
  dfs(v);
}
