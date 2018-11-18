#include<stdlib.h>
#include<stdio.h>

int found = 0,energy,start,target;
void findPath(int start, int step)
{
	int num1 = 2*start;
	int num2 = 10*start +1;
	step+=1;
	if(step>energy||start>target)
		return;

	if(num1==target||num2==target||start==target)
	{
		found = 1;
		return;
	}

	findPath(num1,step);
	findPath(num2,step);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d\n%d\n%d", &start, &target, &energy);
		findPath(start,0);
		if(found)
			printf("Yes");
		else
			printf("No");
	}

}
