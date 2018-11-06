#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a-*(int*)b);
}

int main()
{
	int num;
	scanf("%d",&num);
	int arr[100],k=0,dep[100],l=0;
	for(int i=0;i<num;i++)
	{
		int ar,de;
		scanf("%d %d",&ar,&de);
		arr[k++]=ar;
		dep[l++]=de;
	}

	qsort(arr,num,sizeof(int),cmpfunc);
	qsort(dep,num,sizeof(int),cmpfunc);

	int need=0,res=0;
	int i=0,j=0;

	while(i<num&&j<num)
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

	printf("%d\n", res);

}