#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>

int vis[100000]={0},adj[1000][1000]={{0}},nodes;

void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<nodes;i++)
		if(adj[x][i]==1&&vis[i]!=1)
			dfs(i);
}

bool dfs_util(int test_node)
{
	int components=0;
	for(int i=0;i<nodes;i++)
	{
		if(vis[i]==0)
		{
			dfs(i);
			components++;	
			printf("break points: %d\n",i );		
		}
	}

	for(int i=0;i<nodes;i++)
		vis[i]=0;
	if(test_node==0)
		components-=1;
	if(components > 1){
		printf("#components: %d\n",components);
		return true;
	}
	return false;
}

int main()
{
	int edges,x,y;
	scanf("%d %d",&nodes,&edges);
	int mem[nodes];
	// form adj mat || non directed graph
	while(edges--)
	{
		scanf("%d %d",&x,&y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	// for(int i=0;i<nodes;i++){
	// 	for(int j=0;j<nodes;j++)
	// 		printf("%d ",adj[i][j]);
	// 	printf("\n");
	// }

	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj[i][j]==1)
			{
				mem[j]=1;
				adj[i][j]=0;
			}
		}

		// printf("\n");
		// for(int i=0;i<nodes;i++)
		// {
		// 	for(int j=0;j<nodes;j++)
		// 		printf("%d ",adj[i][j]);
		// 	printf("\n");
		// }

		if(dfs_util(i))
			printf("answer: %d\n",i);

		for(int k=0;k<nodes;k++)
		{
			if(mem[k]==1)
			{
				adj[i][k]=1;
				mem[k]=0;
			}
		}

	}

	return 0;

}