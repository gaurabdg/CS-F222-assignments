#include<stdio.h>

int n=0,y[100],am[100][100]={{0}},q=0,c=0;

void permTopSort(int res[],int vis[])
{
	int flag=0;

	while(c<n){
		int u=0;
	for(int k=u;k<n;k++)
	{
		if(y[k]==0&&vis[k]==0)
		{
			for(int i=0;i<n;i++)
	        {
	          if(am[k][i]==1)
	            am[k][i]=0;
	        }
	        vis[k]=1;
	        res[q++]=k;
	        permTopSort(res,vis);

	        vis[k]=0;
	        res[--q]=0;
	        for(int i=0;i<n;i++)
	        {
	          if(am[k][i]==0)
	            am[k][i]=1;
	        }

	        flag=1;
		}
		
	}
	c++;
	}


	if(!flag)
	{
		for (int i = 0; i < q; ++i)
		{
			printf("%d ", res[q]);
		}
		printf("\n");
	}
}

int main()
{
  int i,j,k,m,y[26],z[26],c=0;
  int edges,total=0;
  scanf("%d",&n);
  scanf("%d",&edges);
  
  while(edges--)
  {
  	int x,y;
  	scanf("%d %d",&x,&y);
    am[x][y]=1;
  }
  
  // for(i=0;i<n;i++)
  // {
  //   for(j=0;j<n;j++)
  //   {
  //     printf("%d",am[i][j]);
  //   }
  //   printf("\n");
  // }
  int visited[100];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

      for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      y[i]=y[i]+am[j][i];
    } 
  }
 
    int res[100]={0};
    permTopSort(res, visited);


  return 0;
}
