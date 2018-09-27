#include<stdio.h>
#include<stdlib.h>

char letters[26],scanStore[26];
int k=0,l=0;
int isPresent(char x,int size)
{
  for(int i=0;i<size;i++)
  {
    if(letters[i]==x)
      return 1;
  }
  return 0;
}

int cmpfunc(const void* a, const void* b)
{
  return (*(char*)a-*(char*)b);
}

int getIndex(char c)
{
  int index;
  for(int i=0;i<k;i++)
  {
    if((int)letters[i]==(int)c){
      index=i;
      break;
    }


  }
  return index;
}

int main()
{
  int n=0,edges,am[26][26]={{0}},y[26],z[26],c=0;
  char results[26];
  scanf("%d",&edges);
  // convert chars relation to adj matrix
  while(edges--)
  {
    char x,y;
    scanf(" %c %c",&x,&y);
    int X=(int)x-97;
    int Y=(int)y-97;
    if(!isPresent(x,k))
      letters[k++]=x;
    if(!isPresent(y,k))
      letters[k++]=y;
    scanStore[l++]=x;
    scanStore[l++]=y;
  }

  qsort(letters,k,sizeof(char),cmpfunc);

  for(int i=0;i<l-1;i+=2)
  {
    am[getIndex(scanStore[i])][getIndex(scanStore[i+1])]=1;
  }

  n=k;
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d",am[i][j]);
    }
    printf("\n");
  }

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
  int cycle=0;
  for(int i=0;i<k;i++)
  {
    if(y[i]>0)
      cycle++;
  }
  if(cycle==k)
  {
    printf("-1");
    return 0;
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
