#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,t;
	int pow[N],k=0;
	scanf("%d %d",&t,&N);
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		pow[k++]=tmp;
	}

	int sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=pow[i];
	}
	int av=sum/t;

	int curr=0,next=0,res[t],l=0;
	printf("%d\n",t);
	int T=t;
	for(int i=0;i<N;i++)
	{
		curr += pow[i];
		if(i<N-1)
			next=curr+pow[i+1];

		if(abs(av-curr)<abs(av-next))
		{
			res[l++]=curr;
			t--;
			curr=0;
		}

		if(t==1)
		{
			int remSum=0;
			for(int j=i+1;j<N;j++)
			{
				remSum+=pow[j];
			}
			res[l++]=remSum;
		}
	}


	int m=0;
	// for(int i=0;i<T;i++)
	// {
	// 	// if(res[i]>m)
	// 	// 	m=res[i];
	// 	printf("%d\n",res[i] );
	// }
	// printf("%d\n",m);
	return 0;
}