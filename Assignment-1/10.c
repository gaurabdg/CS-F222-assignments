#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char op;

	int mass[100];
	for(int i=0;i<100;i++)
	{
		mass[i]=0;
	}

	int max=0;

	for(int i=0;i<n;i++)
	{	
		int k;
		scanf("%d",&k);
		int a[100],b[100];

		for(int j=0;j<k;j++)
		{
			scanf("%d",&a[j]);
			if(a[j] > max) max=a[j];
		}

		for(int j=0;j<k;j++)
		{
			scanf("%d",&b[j]);
			if(b[j]>max) max=b[j];
		}

		scanf(" %c",&op);

		if(op == '>')
		{
			for(int j=0;j<k;j++)
			{	
				if(mass[a[j]]== -1) mass[a[j]] = 1;
				else if(mass[a[j]]== 0) mass[a[j]] = 2;
				if(mass[b[j]]== 2) mass[b[j]] = 1;
				else if(mass[b[j]]== 0) mass[b[j]] = -1;
			}
		}

		if(op == '<')
		{
			for(int j=0;j<k;j++)
			{
				if(mass[b[j]]==-1) mass[b[j]] = 1;
				else if(mass[b[j]]== 0) mass[b[j]] = 2;
				if(mass[a[j]]== 2) mass[a[j]] = 1;
				else if(mass[a[j]]== 0) mass[a[j]] = -1;
			}
		}

		if (op == '<' || op== '>')
		{
			for (int l=0;l<100;l++)
			{	
				int f1=0;
				for(int j=0;j<k;j++)
				{	
					if(l == a[j]) f1=1;
				}

				if(f1!=1)
				{	
					for(int j=0;j<k;j++)
					{	
						if(l== b[j]) f1=1;
					}
				}

				if(f1==0) 
					mass[l]=1;
			}
		}	

		if(op == '=')
		{
			for(int j=0;j<k;j++)
			{
				mass[a[j]] = 1;
				mass[b[j]] = 1;
			}
		}

	}

	int fake=0;
	int flag=0;

	for(int i=1;i<=max;i++)
	{
		if((mass[i]==2 || mass[i]==-1) && flag==1)
		{
			printf("-1\n");
			return 0;
		}
		if(mass[i]==-1 || mass[i]==2) 
			{
				fake=i;
				flag=1;
			} 

	}

	if(flag == 0) printf("-1\n");

	else printf("%d\n",fake);

	return 0;

}
