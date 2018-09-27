
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int N,K,L;
int S[1000],U[1000],T[1000];

int cmpfunc(const void* a, const void* b)
{
  return(*(int*)a - *(int*)b);
}

void findUnion(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0,k=0;
  int sub[1000]={0};
  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
       sub[k++]=arr1[i++];
     
    else if (arr2[j] < arr1[i])
       sub[k++]=arr2[j++];
     
    else
    {
       sub[k++]=arr2[j++];
       i++;
    }
  }

  while(i < m)
       sub[k++]=arr1[i++];
 
  while(j < n)
       sub[k++]=arr2[j++];

    // check if set matches
   int present = 0;
   for(int i=0;i<k;i++)
   {
      if(sub[i]==T[i]&&k==L){
        present++;
      }
   }

   if(present==L)
   {
    for(int i=0;i<m;i++)
    {
      printf("%d ",arr1[i]);
    }
    printf("\n");
   }

}

void genPowerSet(int set[], int set_size) 
{ 

    unsigned int pow_set_size = pow(2.0, (double)set_size); 
    int counter, j; 
    int cmp[1000]={0};

    for(counter = 0; counter < pow_set_size; counter++) 
    { 
      int k=0;
      for(j = 0; j < set_size; j++) 
       { 
          if(counter & (1<<j))
          {
            cmp[k++]=set[j];
          }
       }
       
       findUnion(cmp,U,k,K);
    } 
} 
 
int main()
{

  int i=0,j=0,x=0;

  scanf("%d",&N);
  int n=N;
  while(n--)
  {
    int t;
    scanf("%d",&t);
    S[i++]=t;
  }

  scanf("%d",&K);
  int k=K;
  while(k--)
  {
    int t;
    scanf("%d",&t);
    U[j++]=t;
  }

  scanf("%d",&L);
  int l=L;
  while(l--)
  {
    int t;
    scanf("%d",&t);
    T[x++]=t;
  }
  qsort(S,N,sizeof(int),cmpfunc);
  qsort(U,K,sizeof(int),cmpfunc);
  qsort(T,L,sizeof(int),cmpfunc);
  genPowerSet(S,N);

  return 0;
}