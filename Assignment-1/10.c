#include<stdio.h>

int main()
{
	int num,mass[100];
	for(int i=0;i<100;i++)
		mass[i]=0;
	scanf("%d",&num);

	for(int i=0;i<num;i++)
	{
		int x;
		scanf("%d",&x);
		int a[100],b[100];
		for(int j=0;j<100;j++)
		{
			a[i]=0;
			b[i]=0;
		}

		for(int k=0;k<x;k++)
			scanf("%d",&a[k]);
		for(int k=0;k<x;k++)
			scanf("%d",&b[k]);

		char c;
		scanf(" %c",&c);

		if(c=='>')
		{
			for(int j=0;j<x;j++)
			{
				if(mass[a[j]]==-1)
					mass[a[j]]=1;
				else if(mass[a[j]]==0)
					mass[a[j]]=2;
				
				if(mass[b[j]]==2)
					mass[b[j]]=1;
				else if(mass[b[j]]==0)
					mass[b[j]]=-1;
			}
		}

		if(c=='<')
		{
			for(int j=0;j<x;j++)
			{
				if(mass[b[j]]==-1)
					mass[b[j]]=1;
				else if(mass[b[j]]==0)
					mass[b[j]]=2;
				
				if(mass[a[j]]==2)
					mass[a[j]]=1;
				else if(mass[a[j]]==0)
					mass[a[j]]=-1;
			}
		}

		if (c == '<' || c== '>')
		{
			// int flg=0;
			for(int l=0;l<100;l++)
			{
				int flg=0;
				for(int j=0;j<x;j++)
				{
					if(a[j]==l||b[j]==l)
					{
						flg=1;
						break;
					}
				}
				if(!flg)
				mass[l]=1;
			}
		}	

		if(c=='=')
		{
			for(int j=0;j<x;j++)
			{
				mass[a[j]]=1;
				mass[b[j]]=1;
			}
		}

	}

	for(int i=0;i<10;i++)
		printf("%d\n",mass[i] );
	int f=0,fake;

	for(int i=1;i<=10;i++)
	{
		if((mass[i]==2||mass[i]==-1)&&f==1)
		{
			printf("-1\n");
			return 0;
		}
		
		if(mass[i]==-1||mass[i]==2)
		{
			fake=i;
			f=1;
		}

	}

	if(f==0)
		printf("-1\n");
	else
		printf("%d\n",fake);

	return 0;
}