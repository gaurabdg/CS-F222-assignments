#include<stdio.h>

int main()
{
  int n=0,edges,am[26][26]={{0}},y[26],z[26],c=0;
  char letters[26]={'z'},results[26];
  scanf("%d",&edges);
  
  // convert chars relation to adj matrix
  while(edges--)
  {
    char x,y;
    scanf(" %c %c",&x,&y);
    int X=(int)x-97;
    int Y=(int)y-97;
    letters[X]=x;
    letters[Y]=y;
    am[X][Y]=1;
  }

  // calculating number of nodes/distinct letters present in 
  for(int i=0;i<26;i++)
  {
    if(letters[i]>=97&&letters[i]<=122)
        n++;
  }
  
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     printf("%d",am[i][j]);
  //   }
  //   printf("\n");
  // }

  // initializing column sum and visited array
  for(int i=0;i<n;i++)
  {
    y[i]=0;
    z[i]=0;
  }

  // computing column sum
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      y[i]=y[i]+am[j][i];
    } 
  }

  // TOPOLOGICAL SORT
  int f=0;
  while(c<n)
  {
    int u=0;
    for(int k=u;k<n;k++)
    {
      //check if visited and has edge
      if((y[k]==0)&&(z[k]==0))
      {
        // appending nodes to result
        results[f++]=letters[k];
        // set visited
        z[k]=1;
        // removing all edges from the corresponding row
        for(int i=0;i<n;i++)
        {
          if(am[k][i]==1)
            am[k][i]=0;
        }
        // init column array for recomputation
        for(int i=0;i<n;i++)
        {
          y[i]=0;
        }
        // recompute col sum
        for(int m=0;m<n;m++)
        {
          for(int j=0;j<n;j++)
          {
            y[m]=y[m]+am[j][m];
          }
        }
        
        break;
      }
    }  
    c++;
  }

  // take care of cycles in subgraphs/overall cyclic graph
  int out=0;
  for(int i=0;i<n;i++)
  {
    if(results[i]>=97&&results[i]<=122)
      out++;
  }

  if(out!=n)
  {
    printf("-1");
    return 0;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      printf("%c ",results[i]);
    }
  }

  return 0;
}
