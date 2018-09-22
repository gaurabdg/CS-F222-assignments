#include <stdio.h>
#include <stdlib.h>

int checkDivBreadth(long int x, long int p[], long int l)
{
	long int i;
	for(i=0;i<l;i++){
		if(x%p[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	long int num,j,i,l=0,edges=0;
	scanf("%ld",&num);
	long int *factors;
	factors = (long int *)malloc(0*sizeof(long int));

	// calculate all factors
	for(i=1;i<=num;i++)
		if(num%i==0)
		{
			l++;
			factors = (long int *)realloc(factors,l*sizeof(long int));
			factors[l-1] = i;
		}

	// form edges for prime multiples / ~(form edges for reflexive/transitive vertices)
	for(i=0;i<l-1;i++)
	{
		long int q=0;
		long int *neighbours;
		neighbours = (long int *)malloc(q*sizeof(long int));
		for(j=i+1;j<l;j++)
		{
			if(factors[j]%factors[i]==0)
			{
				if(checkDivBreadth(factors[j],neighbours,q))
				{
					q++;
					neighbours = (long int *)realloc(neighbours,q*sizeof(long int));
					neighbours[q-1] = factors[j];
				}
			}
		}
		free(neighbours);
		edges+=q;
	}

	free(factors);
	printf("%ld\n",edges);
	return 0;
}