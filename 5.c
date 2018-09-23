#include <stdio.h>
#include <math.h>

void print(int *a, int n)
{
   int i;
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

int main()
{
  int N,m,n,arr[100][100],na[100];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&na[i]);
    for(int j=0;j<na[i];j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }

  for(int i=0;i<N;i++)
  {
    int pow_set_size = pow(2, na[i]-1); 
    int counter; 

    for(counter = 1; counter < pow_set_size; counter++) 
    { 
      for(int j = 0; j < na[i]; j++) 
      { 
        if(counter & (1<<j)) 
          printf("%d ", arr[i][na[i]-1-j]); 
      }
      printf("\n");

      for(int j = 0; j < na[i]; j++) 
      { 
        if(~counter & (1<<j)) 
          printf("%d ", arr[i][na[i]-1-j]); 
      }
      printf("\n");

      for(int k=0;k<N;k++)
      {
        if(i!=k)
          print(arr[k],na[k]);
      }
        
      printf("*************\n"); 
    } 
  }
  return 0;
}