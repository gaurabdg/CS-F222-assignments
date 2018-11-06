#include <stdio.h>
#include <stdlib.h>

int vis[100000]={0},adj[1000][1000]={{0}},nodes;

void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<nodes;i++)
		if(adj[x][i]==1&&vis[i]!=1)
		{
			dfs(i);
			printf("%d ",i);
		}
}

int main()
{
	int edges,x,y,components=0;
	scanf("%d %d",&nodes,&edges);

	// form adj matrix of directed graph
	while(edges--)
	{
		scanf("%d %d",&x,&y);
		adj[x][y] = 1;
		// adj[y][x] = 1;
	}
	printf("0 ");
	// print all nodes reachable from 0th place
	dfs(0);

	return 0;
}