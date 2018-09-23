#include <stdio.h>
#include <stdlib.h>

void print(long int *a, long int n)
{
	long int i;
	for(i=0;i<n;i++)
		printf("%ld ",a[i]);
	printf("\n");
}

void combos(long int n, long int *na, long int m[][10000], long int k,long int *a,long int *data,long int start,long int end, long int index, long int r)
{
	long int i;
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

void printCombs(long int n, long int *na, long int m[][10000],long int k, long int *a, long int p, long int r)
{
	long int *data = (long int *)malloc(r*sizeof(long int));
	combos(n,na,m,k,a,data,0,n-1,0,r);
}

int main()
{
	long int n,na[1000], i, j, a[1000][10000];
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&na[i]);
		for(j=0;j<na[i];j++)
			scanf("%ld",&a[i][j]);
	}
	for(i=0;i<n;i++)
		for(j=0;j<(na[i]/2);j++)
			printCombs(n,na,a,i,a[i],na[i],j);
	return 0;
}