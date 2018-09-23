#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n)
{
   int i;
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

void combos(int n, int *na, int m[][100], int k, int *a, int *data, int start, int end, int index, int r)
{
  int i;
  if(index==r)
  {
    for(i=0;i<n;i++)
    {
      if(i!=k)
        print(m[i],na[i]);
    }
    print(data,r);
    printf("************************\n");
    
  }
  for(i=start; i<=end && end-i+1>=r-index; i++)
  {
    data[index] = a[i];
    
    combos(n,na,m,k,a,data,i+1,end,index+1,r);
  }
}

void printCombs(int n, int *na, int m[][100], int k, int *a, int p, int r)
{
  int *data = (int*)malloc(r*sizeof( int));
  combos(n,na,m,k,a,data,0,n-1,0,r);
}

int main()
{
   int n,na[100], i, j,a[100][100];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&na[i]);
    for(j=0;j<na[i];j++)
      scanf("%d",&a[i][j]);
  }
  for(i=0;i<n;i++)
    for(j=0;j<(na[i]/2);j++)
      printCombs(n,na,a,i,a[i],na[i],j);
  return 0;
}