#include<stdio.h>
#include<stdlib.h>

// comparator for qsort
int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a-*(int*)b);
}

int main()
{
	int n,p=0,q=0,arr[100],dep[100];
	scanf("%d",&n);
	int cp =n;
	while(n--)
	{
		int a,d;
		scanf("%d %d",&a,&d);
		arr[p++]=a;
		dep[q++]=d;
	}
	qsort(arr,cp,sizeof(int),cmpfunc);
	qsort(dep,cp,sizeof(int),cmpfunc);

	// for(int i=0;i<cp;i++)
	// 	printf("%d ",arr[i]);
	// printf("\n");
	// for(int i=0;i<cp;i++)
	// 	printf("%d ",dep[i]);
	// printf("\n");

	int need=0,res=0;
	int i=0,j=0;

	while(i<cp&&j<cp)
	{
		if(arr[i]<=dep[j]) 
		{
			need++;
			i++;

			if(need>res)
				res=need;
		}
		else
		{
			need--;
			j++;
		}
	}

	printf("%d", res);


}