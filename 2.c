#include<stdio.h>

int main()
{
  int i,j,k,m,n=0,am[26][26]={{0}},y[26],z[26],c=0;
  char letters[26]={'z'};
  int edges,total=0;
  scanf("%d",&edges);
  char results[26];
  // printf("%d",edges);
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

  for(int i=0;i<26;i++)
  {
    if(letters[i]>=97&&letters[i]<=122)
      n++;
  }
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d",am[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<n;i++)
  {
    y[i]=0;
    z[i]=0;
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      y[i]=y[i]+am[j][i];
    } 
  }

  // cycle detection
  // int cycles=0;
  // for(int i=0;i<n;i++)
  // {
  //   if(y[i]!=0)
  //     cycles++;
  // }

  // if(cycles==n){
  //   printf("-1");
  //   return 0;
  // }

  int f=0;
  while(c<n)
  {
      int u=0;
      for(k=u;k<n;k++)
    {

      if((y[k]==0)&&(z[k]==0))
      {
        results[f++]=letters[k];
        z[k]=1;
        for(i=0;i<n;i++)
        {
          if(am[k][i]==1)
            am[k][i]=0;
        }

        for(i=0;i<n;i++)
        {
          y[i]=0;
        }

        for(m=0;m<n;m++)
        {
          for(j=0;j<n;j++)
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
