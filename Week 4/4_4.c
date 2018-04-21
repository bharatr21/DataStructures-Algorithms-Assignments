#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* a, const void* b)
{
	return (*(int*) a - *(int*) b);
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int arr[n], exit[n];
	f(i,0,n) scanf("%d", &arr[i]);
	f(i,0,n) scanf("%d", &exit[i]);
	qsort(arr,n,sizeof(arr[0]),cmp);
	qsort(exit,n,sizeof(exit[0]),cmp);
	int ans=1,st=1, time=arr[0];
	i=1;j=0;
	while(i<n&&j<n)
	{
		if(arr[i]<=exit[j])
		{
			st++;
			i++;
			if(st>ans)
			{
				ans=st;
				time=arr[i];
			}
		}
		else
		{
			st--;
			j++;
		}
	}
	printf("There are maximum %d students at time %d\n",ans,time);
	return 0;
}