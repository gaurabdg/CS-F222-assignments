#include<stdio.h>

int main()
{
	int n,p=0,q=0;
	int arr[100],dep[100];
	scanf("%d",&n);
	int cp =n;
	while(n--)
	{
		int a,d;
		scanf("%d %d",&a,&d);
		arr[p++]=a;
		dep[q++]=d;
	}
		for(int i=0;i<cp;i++)
		printf("%d ",arr[i]);
	printf("\n");
	for(int i=0;i<cp;i++)
		printf("%d ",dep[i]);

	int need=0,res=0;
	int i=0,j=0;

	while(i<cp&&j<cp)
	{
		if(arr[i]<dep[j]) //<= acording to sample 1, but not matching
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