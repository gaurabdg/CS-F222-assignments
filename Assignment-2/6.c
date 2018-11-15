#include<stdlib.h>
#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x, y, z, f=0;
		scanf("%d\n%d\n%d", &x, &y, &z);
		// printf("%d\n%d\n%d", x, y, z);
		while(y>0&&z--)
		{
			if(y%2==0)
				y/=2;
			else{
				y=(y-1)/10;
				if(y%10!=0)
					break;
			}
			printf("%d\n",y );
			if(y==x)
			{
				printf("Yes\n");
				f=1;
				break;
			}
		}
			if(!f)
			printf("No\n");
	}

}