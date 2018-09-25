#include <stdio.h>
#include <stdlib.h>

int checkDivBreadth(int x, int p[], int l)
{
	for(int i=0;i<l;i++)
	{
		if(x%p[i]==0)
			return 0;
	}

	return 1;
}

int main()
{
	int num,l=0,edges=0,factors[1000];
	scanf("%d",&num);

	// calculate all factors
	for(int i=1;i<=num;i++)
		if(num%i==0)
		{
			factors[l++] = i;
		}

	// form edges for prime multiples / ~(form edges for reflexive/transitive vertices)
	for(int i=0;i<l-1;i++)
	{
		int q=0, neighbours[1000];
		
		for(int j=i+1;j<l;j++)
		{
			if(factors[j]%factors[i]==0)
			{
				if(checkDivBreadth(factors[j],neighbours,q))
				{
					neighbours[q++] = factors[j];
				}
			}
		}
		
		edges+=q;
	}

	printf("%d\n",edges);

	return 0;
}